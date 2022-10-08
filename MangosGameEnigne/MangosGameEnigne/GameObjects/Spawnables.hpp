#ifndef Spawnables_hpp
#define Spawnables_hpp

#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

#include "LinearAlgebra.hpp"

namespace mge
{
    class World;
    class Spawnable;
    class Object;
    class Light;
    class Camera;
    
    class World
    {
        static std::size_t s_world_count;
        
    public:
        
        size_t id;

        std::string name;
        
        std::vector<Object> objects;
        
        std::vector<Light> lights;
        
        std::vector<Camera> cameras;
        
        World();
        
        ~World();
    };

    
    class Spawnable
    {
        static std::size_t s_spawnable_count;

    public:
        
        size_t id;

        std::string name;

        float3 location, rotation, scale;
                
        
        Spawnable();
        
        virtual ~Spawnable();
        
        virtual void Move(const float3& A);
        
        virtual void Move(float x, float y, float z);

        virtual void Rotate(const float3& A);
        
        virtual void Rotate(float x, float y, float z);
        
        virtual void Scale(const float3& A);
        
        virtual void Scale(float x, float y, float z);
    };

    class Object: public Spawnable
    {
        friend Camera;
        
    protected:
        
        float3 object_colour;

        std::vector<float3> vertex_pool, normal_pool;
        
        std::vector<float2> texture_pool;

        std::vector<std::array<std::size_t, 7>> polygon_indices;
                
        class Polygon
        {
        public:
                        
            float3 normal;

            triangle3 vertices;
            
            triangle2 texture;
                        
            float3 colour;


            Polygon(const float3& normal,
                    const float3& vertex_0,
                    const float3& vertex_1,
                    const float3& vertex_2,
                    const float2& texture_0,
                    const float2& texture_1,
                    const float2& texture_2,
                    const float3& colour);
            
            bool operator<(const Polygon& A) const;
        };
                        
        Object::Polygon GetPolygon(const std::array<std::size_t, 7>& polygon_index) const;
        
        template <typename DataType>
        void GetDataFromLine(const std::string& line, std::vector<DataType>& out)
        {
            std::istringstream stream(line);
            
            while (!(stream.eof() || stream.bad()))
            {
                DataType value;
                
                stream >> value;
                
                if (stream.fail())
                {
                    stream.clear();
                    stream.ignore();
                } else
                {
                    out.emplace_back(value);
                }
            }
        }

    public:
        
        Object();
        
        ~Object();
        
        bool LoadFromFile(const std::string& file_name);

        void Clear();
        
        void SetColour(const float3& colour);
    };


    class Light: public Spawnable
    {
        friend Camera;
        
    protected:

        float3 colour, normal;
        
    public:
        
        Light();
        
        ~Light();
        
        void Rotate(const float3& A) override;
        
        void Rotate(float x, float y, float z) override;
        
        void SetColour(const float3& colour);
    };


    class Camera: public Spawnable
    {
        float hight, width, fov, render_distance;

        float3 normal, length;

                        
        float3x3 TransitionMatrix() const;
        
        bool IsPoylgonVisable(Object::Polygon& A) const;
        
        triangle2 ProjectVertices(const triangle3& A) const;
        
        bool ClipVerticesAgainstBoundary(const triangle2& A, const line2& B, std::vector<triangle2>& out) const;
      
        bool ClipVertices(const triangle2& A, std::vector<triangle2>& out) const;

        void IlluminatePoygon(Object::Polygon& A, const std::vector<Light>& lights) const;
    
    public:
        
        Camera();
        
        ~Camera();
        
        void Rotate(const float3& A) override;
        
        void Rotate(float x, float y, float z) override;
                
        void SetSetting(float hight, float width, float fov, float render_distance);
        
        float3 Normal() const;

        void DrawView(const std::vector<Object>& objects, const std::vector<Light>& lights, void(* Draw)(const triangle2&, const float3&)) const;
    };
}


#endif
