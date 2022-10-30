#include "Spawnables.hpp"

namespace mge
{
    std::size_t World::s_world_count = 0;
    
    World::World()
    :   id(this->s_world_count),
        name("World_" + std::to_string(this->id)),
        objects(),
        lights(),
        cameras()
    {
        s_world_count++;
    }
    
    World::~World()
    {
        s_world_count--;
    }

    std::size_t Spawnable::s_spawnable_count = 0;
    
    Spawnable::Spawnable()
    :   id(this->s_spawnable_count),
        name("Spawnable_" + std::to_string(this->id)),
        location(0.0f),
        rotation(0.0f),
        scale(1.0f)
    {
        this->s_spawnable_count++;
    }

    Spawnable::~Spawnable()
    {
        this->s_spawnable_count--;
    }

    void Spawnable::Move(const float3& A)
    {
        this->location += A;
    }
    
    void Spawnable::Move(float x, float y, float z)
    {
        this->location += float3(x, y, z);
    }
        
    void Spawnable::Rotate(const float3& A)
    {
        this->rotation = std::clamp(this->rotation + A, float3(0.0f), float3(2.0f * M_PIf));
    }
    
    void Spawnable::Rotate(float x, float y, float z)
    {        
        this->rotation = std::clamp(this->rotation + float3(x, y, z), float3(0.0f), float3(2.0f * M_PIf));
    }
        
    void Spawnable::Scale(const float3& A)
    {
        this->scale = fabs(this->scale * A);
    }
    
    void Spawnable::Scale(float x, float y, float z)
    {
        this->scale += fabs(this->scale * float3(x, y, z));
    }
    
    Object::Polygon::Polygon(const float3& normal,
                             const float3& vertex_0,
                             const float3& vertex_1,
                             const float3& vertex_2,
                             const float2& texture_0,
                             const float2& texture_1,
                             const float2& texture_2,
                             const float3& colour)

    :   normal(normal),
        vertices(triangle3(vertex_0, vertex_1, vertex_2)),
        texture(triangle2(texture_0, texture_1, texture_2)),
        colour(colour)
    {}
    
    bool Object::Polygon::operator<(const Polygon& A) const
    {
        return this->vertices.Center().LengthSquared() > A.vertices.Center().LengthSquared();
    }
    
    Object::Polygon Object::GetPolygon(const std::array<std::size_t, 7>& polygon_index) const
    {
        float3x3 rotation(cos(this->rotation.z) * cos(this->rotation.y),
                          cos(this->rotation.z) * sin(this->rotation.y) * sin(this->rotation.x) - sin(this->rotation.z) * cos(this->rotation.x),
                          cos(this->rotation.z) * sin(this->rotation.y) * cos(this->rotation.x) + sin(this->rotation.z) * sin(this->rotation.x),
                          sin(this->rotation.z) * cos(this->rotation.y),
                          sin(this->rotation.z) * sin(this->rotation.y) * sin(this->rotation.x) + cos(this->rotation.z) * cos(this->rotation.x),
                          sin(this->rotation.z) * sin(this->rotation.y) * cos(this->rotation.x) - cos(this->rotation.z) * sin(this->rotation.x),
                                                - sin(this->rotation.y),
                                                  cos(this->rotation.y) * sin(this->rotation.x),
                                                  cos(this->rotation.y) * cos(this->rotation.x));
            
        
        return Object::Polygon(rotation * this->normal_pool.at(polygon_index[0]),
                               rotation * this->vertex_pool.at(polygon_index[1]) * this->scale + this->location,
                               rotation * this->vertex_pool.at(polygon_index[2]) * this->scale + this->location,
                               rotation * this->vertex_pool.at(polygon_index[3]) * this->scale + this->location,
                                          this->texture_pool.at(polygon_index[4]),
                                          this->texture_pool.at(polygon_index[5]),
                                          this->texture_pool.at(polygon_index[6]),
                                          this->object_colour);
    }
    

    Object::Object()
    :   object_colour(1.0f),
        vertex_pool(1, 0.0f),
        normal_pool(1, 0.0f),
        texture_pool(1, 0.0f),
        polygon_indices(0)
    {}
    
    Object::~Object()
    {}
    
    bool Object::LoadFromFile(const std::string& file_name)
    {
        std::ifstream file(file_name);
        
        std::string line;
        
        std::unordered_map<float3, std::size_t> normals;
        
        std::size_t normal_index = 1;
        
        bool has_normals = false;
        
        bool has_textures = false;
        
        if (!file)
        {
            std::cout << "Failed opening file: " << file_name << std::endl;
            
            return false;
        }
        
        while (std::getline(file, line))
        {
            if (line.starts_with("v "))
            {
                std::vector<float> out;
                
                this->GetDataFromLine(line, out);
                
                this->vertex_pool.emplace_back(out.at(0), out.at(1), out.at(2));
                
                continue;
            }
            
            if (line.starts_with("vt "))
            {
                std::vector<float> out;
                
                this->GetDataFromLine(line, out);
                
                this->texture_pool.emplace_back(out.at(0), out.at(1));
                
                has_textures = true;
                
                continue;
            }
            
            if (line.starts_with("vn "))
            {
                std::vector<float> out;
                
                this->GetDataFromLine(line, out);
                
                this->normal_pool.emplace_back(out.at(0), out.at(1), out.at(2));
                
                has_normals = true;
                
                continue;
            }
            
            if (line.starts_with("f ") && !has_normals && !has_textures)
            {
                std::vector<std::size_t> out;
                
                this->GetDataFromLine(line, out);
                                
                auto normal = normals.emplace(triangle3(this->vertex_pool.at(out.at(0)),
                                                        this->vertex_pool.at(out.at(1)),
                                                        this->vertex_pool.at(out.at(2))).Normal(), normal_index);

                std::array<std::size_t, 7> value = {normal.first->second, out.at(0), out.at(1), out.at(2), 0, 0, 0};

                if (normal.second)
                    normal_index++;
                
                this->polygon_indices.emplace_back(value);
                
                continue;
            }
            
            if (line.starts_with("f ") && !has_normals && has_textures)
            {
                std::vector<std::size_t> out;
                
                this->GetDataFromLine(line, out);
                                
                auto normal = normals.emplace(triangle3(this->vertex_pool.at(out.at(0)),
                                                        this->vertex_pool.at(out.at(2)),
                                                        this->vertex_pool.at(out.at(4))).Normal(), normal_index);
                
                std::array<std::size_t, 7> value = {normal.first->second, out.at(0), out.at(2), out.at(4), out.at(1), out.at(3), out.at(5)};

                if (normal.second)
                    normal_index++;
                
                this->polygon_indices.emplace_back(value);
                
                continue;
            }
            
            if (line.starts_with("f ") && has_normals && !has_textures)
            {
                std::vector<std::size_t> out;
                
                this->GetDataFromLine(line, out);
                                                
                std::array<std::size_t, 7> value = {out.at(1), out.at(0), out.at(2), out.at(4), 0, 0, 0};
                
                this->polygon_indices.emplace_back(value);
                
                continue;
            }
            
            if (line.starts_with("f ") && has_normals && has_textures)
            {
                std::vector<std::size_t> out;
                
                this->GetDataFromLine(line, out);
                                
                std::array<std::size_t, 7> value = {out.at(2), out.at(0), out.at(3), out.at(6), out.at(1), out.at(4), out.at(7)};
                
                this->polygon_indices.emplace_back(value);
            }
        }
        
        if (!normals.empty())
        {
            this->normal_pool.resize(normal_index);

            for (auto normal : normals)
                this->normal_pool[normal.second] = normal.first;
        }
            
        file.close();
    }

    void Object::Clear()
    {
        this->object_colour = 1.0f;
        this->vertex_pool.clear();
        this->normal_pool.clear();
        this->polygon_indices.clear();
    }
        
    void Object::SetColour(const float3&  colour)
    {
        this->object_colour = colour;
    }

    Light::Light()
    :   normal(1.0f, this->rotation.y, this->rotation.z, true),
        colour(1.0f)
    {}
        
    Light::~Light()
    {}
    
    void Light::Rotate(const float3& A)
    {
        this->rotation = std::clamp(this->rotation + A, float3(0.0f), float3(2.0f * M_PIf));
        
        this->normal = float3(1.0f, this->rotation.y, this->rotation.z, true);
    }
    
    void Light::Rotate(float x, float y, float z)
    {
        this->rotation = std::clamp(this->rotation + float3(x, y, z), float3(0.0f), float3(2.0f * M_PIf));

        this->normal = float3(1.0f, this->rotation.y, this->rotation.z, true);
    }
        
    void Light::SetColour(const float3& colour)
    {
        this->colour = colour;
    }
        
    float3 Camera::Normal() const
    {
        return float3(1.0f, this->rotation.y, this->rotation.z, true);
    }
        
    bool Camera::IsPoylgonVisable(Object::Polygon& A) const
    {
        for (int i = 0; i < 3; i++)
        {
            A.vertices[i] -= this->location;
        }
        
        if (A.vertices.Center().Angle(A.normal) <= M_PI_2f)
        {
            return false;
        }
        
        if (this->Normal().Angle(A.vertices[0]) > this->fov &&
            this->Normal().Angle(A.vertices[1]) > this->fov &&
            this->Normal().Angle(A.vertices[2]) > this->fov)
        {
            return false;
        }
        
        if ((A.vertices[0]).Length() > this->render_distance ||
            (A.vertices[1]).Length() > this->render_distance ||
            (A.vertices[2]).Length() > this->render_distance)
        {
            return false;
        }
        
        if (ShortestDistance(this->Normal(), this->location, A.vertices[0]) < 0.0f ||
            ShortestDistance(this->Normal(), this->location, A.vertices[1]) < 0.0f ||
            ShortestDistance(this->Normal(), this->location, A.vertices[2]) < 0.0f)
        {
            return false;
        }
        
        return true;
    }
            
    triangle2 Camera::ProjectVertices(const triangle3& A) const
    {
        float theta = this->normal.SphericalTheta();
        float phi   = this->normal.SphericalPhi();

        float3x3 transistion(cos(theta) * cos(phi), cos(theta) * sin(phi), -sin(theta), -sin(phi), cos(phi), 0.0f, this->normal.x, this->normal.y, this->normal.z);

        triangle2 result;
        
        for (int i = 0; i < 3; i++)
        {
            float2 proj_A(transistion * (A[i] * (this->length / A[i].Dot(this->normal)) - (this->normal * this->length)));
                
            float2 rotated_proj_A(proj_A.Length(), proj_A.PolarPhi() + this->rotation.x + M_PI_2f, true);
            
            result[i] = float2((rotated_proj_A.x * this->width) + 0.5f * (this->width + 1.0f),
                               (rotated_proj_A.y * this->width) + 0.5f * (this->hight + this->hight / this->width));
        }
        
        return result;
    }

        
    bool Camera::ClipVerticesAgainstBoundary(const triangle2& A, const line2& B, std::vector<triangle2>& out) const
    {
        std::array<bool, 3> is_vertex_visable;
        
        int visable_vertices = 0;
        
        
        for (int j = 0; j < 3; j++)
        {
            is_vertex_visable[j] = (ShortestDistance(B, A[j]) < 0.0f) ? true : false;
            
            visable_vertices += (ShortestDistance(B, A[j]) < 0.0f) ? 1 : 0;
        }
        
        switch (visable_vertices)
        {
            case 1:
            {
                for (int j = 0; j < 3; j++)
                {
                    if(is_vertex_visable[j])
                    {
                        out.emplace_back(A[j],
                                         Intersection(line2(A[(j + 1) % 3], A[j]),    B),
                                         Intersection(line2(A[(j + 2) % 3], A[j]),    B));
                    }
                }
            }
                
            case 2:
            {
                for (int j = 0; j < 3; j++)
                {
                    if(is_vertex_visable[j] && is_vertex_visable[(j + 1) % 3])
                    {
                        out.emplace_back(A[j],
                                         Intersection(line2(A[(j + 2) % 3], A[(j + 1) % 3]),    B),
                                         Intersection(line2(A[(j + 2) % 3], A[j]),              B));
                        
                        out.emplace_back(A[j],
                                         A[(j + 1) % 3],
                                         Intersection(line2(A[(j + 2) % 3], A[(j + 1) % 3]),    B));
                    }
                }
            }
                
            case 3:
            {
                out.emplace_back(A);
            }
                
        }
        
        return visable_vertices != 0;
    }
    
    bool Camera::ClipVertices(const triangle2& A, std::vector<triangle2>& out) const
    {
        std::array<std::vector<triangle2>, 3> clipped_triangles;
        
        std::array<line2, 4> boundaries;
                
        boundaries[0] = line2(float2(0.0f),                      float2(this->width, 0.0f));
        boundaries[1] = line2(float2(this->width, 0.0f),         float2(this->width, this->hight));
        boundaries[2] = line2(float2(this->width, this->hight),  float2(0.0f,        this->hight));
        boundaries[3] = line2(float2(0.0f,        this->hight),  float2(0.0f));

        if (this->ClipVerticesAgainstBoundary(A, boundaries[0], clipped_triangles[0]))
        {
            for (auto clipped_triangle_0 : clipped_triangles[0])
            {
                if (this->ClipVerticesAgainstBoundary(clipped_triangle_0, boundaries[1], clipped_triangles[1]))
                {
                    for (auto clipped_triangle_1 : clipped_triangles[1])
                    {
                        if (this->ClipVerticesAgainstBoundary(clipped_triangle_1, boundaries[2], clipped_triangles[2]))
                        {
                            for (auto clipped_triangle_2 : clipped_triangles[2])
                            {
                                this->ClipVerticesAgainstBoundary(clipped_triangle_2, boundaries[3], out);
                            }
                        }
                    }
                }
            }
        }
        
        return !out.empty();
    }
      
    void Camera::IlluminatePoygon(Object::Polygon& A, const std::vector<Light>& lights) const
    {        
        for (auto light : lights)
        {
            //A.colour += fmod(fabs(light.normal.Dot(A.normal)) * light.scale.Length() / (light.location - A.vertices.Center()).Length(), 1.0f);
        }
        
        A.colour *= fabs(this->normal.Dot(A.normal)) * 255.0f;
    }
    
    Camera::Camera()
    :   hight(1200.0f),
        width(1200.0f),
        fov(M_PIf / 3.0f),
        render_distance(200.0f),
        normal(1.0f, this->rotation.y, this->rotation.z, true),
        length(tan(this->fov) * sqrt(this->hight * this->hight + this->width * this->width) / (2.0f * this->width))
    {}
        
    Camera::~Camera()
    {}
    
    void Camera::Rotate(const float3& A)
    {
        this->rotation = std::clamp(this->rotation + A, float3(0.0f), float3(2.0f * M_PIf));

        this->normal = float3(1.0f, this->rotation.y, this->rotation.z, true);
    }
    
    void Camera::Rotate(float x, float y, float z)
    {
        this->rotation = std::clamp(this->rotation + float3(x, y, z), float3(0.0f), float3(2.0f * M_PIf));

        this->normal = float3(1.0f, this->rotation.y, this->rotation.z, true);
    }
        
    void Camera::SetSetting(float hight, float width, float fov, float render_distance)
    {
        this->hight = hight;
        this->width = width;
        this->fov = std::clamp(fov, M_PI_4f, M_PI_2f);
        this->render_distance = render_distance;
    }

    void Camera::DrawView(const std::vector<Object>& objects, const std::vector<Light>& lights, void (* Draw)(const triangle2&, const float3&)) const
    {
        std::vector<Object::Polygon> polygons;

        for (auto object : objects)
        {
            for (auto index : object.polygon_indices)
            {
                Object::Polygon polygon = object.GetPolygon(index);
                
                if (this->IsPoylgonVisable(polygon))
                {
                    polygons.emplace_back(polygon);
                }
            }
        }
        
        std::sort(polygons.begin(), polygons.end());
        
        for (auto polygon : polygons)
        {
            std::vector<triangle2> triangles_to_draw;
            
            this->IlluminatePoygon(polygon, lights);
        
            if (this->ClipVertices(this->ProjectVertices(polygon.vertices), triangles_to_draw))
            {
                for (auto triangle : triangles_to_draw)
                {
                    Draw(triangle, polygon.colour);
                }
            }
        }
    }
}
