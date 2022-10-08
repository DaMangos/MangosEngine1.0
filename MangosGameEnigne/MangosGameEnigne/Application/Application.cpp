#include "Application.hpp"

namespace mge
{
    auto App::window = std::make_unique<sf::RenderWindow>();
    
    void App::Draw(const triangle2& A, const float3& colour)
    {
        sf::VertexArray triangle(sf::Triangles, 3);
        
        for (int i = 0; i < 3; i++)
        {
            triangle[i].position = sf::Vector2f(A[i].x, A[i].y);
            triangle[i].color = sf::Color(static_cast<std::uint8_t>(colour.x), static_cast<std::uint8_t>(colour.y), static_cast<std::uint8_t>(colour.z));
        }

        window->draw(triangle);
    }
    
    App::App()
    :   world(std::make_unique<World>())
    {
        window->create(sf::VideoMode(1200, 1200), "Mangos");
        
        
        Object m4;
        
        m4.SetColour(float3(1.0f, 0.0f, 0.5f));
        
        m4.LoadFromFile("M4.obj");
        
        this->world->objects.emplace_back(m4);
        
        
        
        Light light;
        
        light.SetColour(1.0f);
        
        light.Move(1.0f);
        
        light.Scale(10.f);
        
        this->world->lights.emplace_back(light);
        
        
        Camera camera;
        this->world->cameras.emplace_back(camera);
        
        world->cameras.at(0).location = float3(0.0f, -20.0f, 0.0f);
        world->cameras.at(0).Rotate(0.0f, M_PI_2f, M_PI_2f);
    }
    
    App::~App()
    {}
    
    void App::Run()
    {
        while (window->isOpen())
        {
            sf::Event event;
            
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window->close();

                    return;
                }
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().W))
            {
                world->cameras.at(0).Move(cos(world->cameras.at(0).rotation.z) * 0.01f, sin(world->cameras.at(0).rotation.z) * 0.01f, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().S))
            {
                world->cameras.at(0).Move(-cos(world->cameras.at(0).rotation.z) * 0.01f, -sin(world->cameras.at(0).rotation.z) * 0.01f, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().A))
            {
                world->cameras.at(0).Move(-sin(world->cameras.at(0).rotation.z) * 0.01f, cos(world->cameras.at(0).rotation.z) * 0.01f, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().D))
            {
                world->cameras.at(0).Move(sin(world->cameras.at(0).rotation.z) * 0.01f, -cos(world->cameras.at(0).rotation.z) * 0.01f, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Space))
            {
                world->cameras.at(0).Move(0.0f, 0.0f, 0.005f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().LShift))
            {
                world->cameras.at(0).Move(0.0f, 0.0f, -0.005f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Up))
            {
                world->cameras.at(0).Rotate(0.0f, -0.005f, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Down))
            {
                world->cameras.at(0).Rotate(0.0f, 0.005f, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Left))
            {
                world->cameras.at(0).Rotate(0.0f, 0.0f, 0.005f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Right))
            {
                world->cameras.at(0).Rotate(0.0f, 0.0f, -0.005f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Num0))
            {
                world->cameras.at(0).Rotate(0.01f, 0.0f, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Num1))
            {
                world->cameras.at(0).Rotate(-0.01f, 0.0f, 0.0f);
            }
                                    
            window->clear(sf::Color::White);
            
            world->cameras.at(0).DrawView(world->objects, world->lights, Draw);
            
            window->display();
        }
        
        return;
    }
}
