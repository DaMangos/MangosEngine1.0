#include <SFML/Graphics.hpp>
#include "MGE_Spawnable.h"
#include "MGE_World.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Mangos 3D Enigne");
    
    mge::World world;
    
    mge::sCamera camera(window.getSize().x, window.getSize().y, pi / 3.0f, 200.0f);
    
    camera.Move(mge::Vector3f(-10.0f, 0.5f, 0.5f));
    camera.Rotate(mge::Vector3f(0.0f, pi / 2.0f, 0.0f));
    
    
    mge::sObject cube;
    
    cube.Scale(mge::Vector3f(1.0f, 1.0f, 1.0f));
    
    cube.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}));
    cube.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}));
    cube.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}));
    cube.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}));
    cube.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}));
    cube.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}));
    cube.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}));
    cube.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}));
    cube.mesh.emplace_back(mge::Plane3f({0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f}));
    cube.mesh.emplace_back(mge::Plane3f({0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 0.0f}));
    cube.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f}));
    cube.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}));

    
    
    world.objects.emplace_back(cube);
    world.camaras.emplace_back(camera);

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();

                return 0;
            }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().W))
        {
            camera.Move(mge::Vector3f(0.001f, 0.0f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().S))
        {
            camera.Move(mge::Vector3f(-0.001f, 0.0f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().A))
        {
            camera.Move(mge::Vector3f(0.0f, 0.001f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().D))
        {
            camera.Move(mge::Vector3f(0.00f, -0.001f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Space))
        {
            camera.Move(mge::Vector3f(0.0f, 0.0f, 0.001f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().LShift))
        {
            camera.Move(mge::Vector3f(0.0f, 0.0f, -0.001f));
        }
        
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Up))
        {
            camera.Rotate(mge::Vector3f(0.0f, 0.0001f, 0.0f));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Down))
        {
            camera.Rotate(mge::Vector3f(0.0f, -0.0001f, 0.0f));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Left))
        {
            camera.Rotate(mge::Vector3f(0.0f, 0.0f, 0.0001f));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Right))
        {
            camera.Rotate(mge::Vector3f(0.0f, 0.0f, -0.0001f));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Num0))
        {
            camera.Rotate(mge::Vector3f(0.0001f, 0.0f, 0.0f));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Num1))
        {
            camera.Rotate(mge::Vector3f(-0.0001f, 0.0f, 0.0f));
        }
        
        window.clear();
                   
        for (auto local_visable_triangles: camera.GetVisableTriangles(world.objects))
        {
            
            if (camera.ClipTriangles(camera.GetTrianglePojection(local_visable_triangles)).size() > 0)
            {
                for (auto screen_triangle : camera.ClipTriangles(camera.GetTrianglePojection(local_visable_triangles)))
                {
                    sf::VertexArray triangle(sf::LineStrip, 4);
                    
                    triangle[0].position = sf::Vector2f(screen_triangle.vertex[0].x, screen_triangle.vertex[0].y);
                    triangle[1].position = sf::Vector2f(screen_triangle.vertex[1].x, screen_triangle.vertex[1].y);
                    triangle[2].position = sf::Vector2f(screen_triangle.vertex[2].x, screen_triangle.vertex[2].y);
                    triangle[3].position = sf::Vector2f(screen_triangle.vertex[0].x, screen_triangle.vertex[0].y);
                        
                    window.draw(triangle);
                }
            }
        }
        
        window.display();
    }
}
