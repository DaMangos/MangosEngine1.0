#include "Application.hpp"

namespace mge
{
    auto App::window = std::make_unique<sf::RenderWindow>();
    
    void App::Draw(const triangle2& A, const float3& colour)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard().Q))
        {
            sf::VertexArray wire_triangle(sf::LineStrip, 4);
            
            for (int i = 0; i < 4; i++)
            {
                wire_triangle[i].position = sf::Vector2f(A[i % 3].x, A[i % 3].y);
                wire_triangle[i].color = sf::Color(static_cast<std::uint8_t>(colour.x), static_cast<std::uint8_t>(colour.y), static_cast<std::uint8_t>(colour.z));
            }
            
            window->draw(wire_triangle);
        } else
        {
            sf::VertexArray triangle(sf::Triangles, 3);
            
            for (int i = 0; i < 3; i++)
            {
                triangle[i].position = sf::Vector2f(A[i].x, A[i].y);
                triangle[i].color = sf::Color(static_cast<std::uint8_t>(colour.x), static_cast<std::uint8_t>(colour.y), static_cast<std::uint8_t>(colour.z));
            }
            
            window->draw(triangle);
        }
    }
    
    App::App()
    :   world(std::make_unique<World>())
    {
        window->create(sf::VideoMode(1200, 1200), "Mangos");
        
        
        Object m4;
                
        m4.SetColour(float3(0.5f, 0.0f, 0.8f));
        
        m4.LoadFromFile("M4.obj");
        
        this->world->objects.emplace_back(m4);
        
        
        
        Object mp7;
        
        mp7.Scale(2.0f);
                
        mp7.SetColour(float3(0.0f, 1.0f, 0.5f));
        
        mp7.LoadFromFile("MP7.obj");
        
        this->world->objects.emplace_back(mp7);
        
        
        
        
        
        Camera camera;
        this->world->cameras.emplace_back(camera);
        
        world->cameras.at(0).location = float3(0.0f, -20.0f, 0.0f);
        world->cameras.at(0).Rotate(0.0f, M_PI_2f, M_PI_2f);
    }
    
    App::~App()
    {}
    
    void App::Run()
    {
        float ahlpha;
        
        float speed = 1.0f, look_speed = 0.1f;
        
        world->objects.at(0).Move(float3(0.0f, 10.0f, 0.0f));
        world->objects.at(1).Move(float3(0.0f, 20.0f, 0.0f));

        
        
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
            
            ahlpha += 0.5f;
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().W))
            {
                world->cameras.at(0).Move(cos(world->cameras.at(0).rotation.z) * speed, sin(world->cameras.at(0).rotation.z) * speed, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().S))
            {
                world->cameras.at(0).Move(-cos(world->cameras.at(0).rotation.z) * speed, -sin(world->cameras.at(0).rotation.z) * speed, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().A))
            {
                world->cameras.at(0).Move(-sin(world->cameras.at(0).rotation.z) * speed, cos(world->cameras.at(0).rotation.z) * speed, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().D))
            {
                world->cameras.at(0).Move(sin(world->cameras.at(0).rotation.z) * speed, -cos(world->cameras.at(0).rotation.z) * speed, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Space))
            {
                world->cameras.at(0).Move(0.0f, 0.0f, speed);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().LShift))
            {
                world->cameras.at(0).Move(0.0f, 0.0f, -1.0f * speed);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Up))
            {
                world->cameras.at(0).Rotate(0.0f, -1.0f * look_speed, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Down))
            {
                world->cameras.at(0).Rotate(0.0f, look_speed, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Left))
            {
                world->cameras.at(0).Rotate(0.0f, 0.0f, look_speed);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Right))
            {
                world->cameras.at(0).Rotate(0.0f, 0.0f, -1.0f * look_speed);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Num0))
            {
                world->cameras.at(0).Rotate(look_speed, 0.0f, 0.0f);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard().Num1))
            {
                world->cameras.at(0).Rotate(-1.0f * look_speed, 0.0f, 0.0f);
            }
                                                
            window->clear(sf::Color::White);
            
            world->cameras.at(0).DrawView(world->objects, world->lights, Draw);
            
            window->display();
        }
        
        return;
    }
}
