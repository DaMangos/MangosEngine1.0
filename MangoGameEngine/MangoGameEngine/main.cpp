#include "MGE_Spawnable.h"
#include "MGE_World.hpp"
#include <iostream>

int main()
{
    float A = 0.0f;
    
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Mangos 3D Enigne");

    mge::World world;
    
    
    mge::sCamera camera(window.getSize().x, window.getSize().y, pi / 3.0f, 25.0f);
    camera.world_location =  mge::Vector3f(0.0f, -4.0f, 1.0f);
    camera.world_rotation =  mge::Vector3f(0.0f, 0.5f * pi, 0.5f * pi);

    world.cameras.emplace_back(camera);

    
    
    mge::sObject cube_0;
    cube_0.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 0.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f}));
    cube_0.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}));
    cube_0.world_location =  mge::Vector3f(-3.0f, -3.0f, 0.0f);
    world.objects.emplace_back(cube_0);
    
    
    
    mge::sObject cube_1;
    cube_1.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 0.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f}));
    cube_1.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}));
    cube_1.world_location =  mge::Vector3f(-3.0f, 3.0f, 0.0f);
    world.objects.emplace_back(cube_1);
    
    
    
    mge::sObject cube_2;
    cube_2.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 0.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f}));
    cube_2.mesh.emplace_back(mge::Plane3f({1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}));
    cube_2.world_location =  mge::Vector3f(3.0f, 3.0f, 0.0f);
    world.objects.emplace_back(cube_2);

    
    
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
            world.cameras[0].Move(mge::Vector3f( cos(world.cameras[0].world_rotation.z) * 0.001f,  sin(world.cameras[0].world_rotation.z) * 0.001f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().S))
        {
            world.cameras[0].Move(mge::Vector3f(-cos(world.cameras[0].world_rotation.z) * 0.001f, -sin(world.cameras[0].world_rotation.z) * 0.001f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().A))
        {
            world.cameras[0].Move(mge::Vector3f(-sin(world.cameras[0].world_rotation.z) * 0.001f,  cos(world.cameras[0].world_rotation.z) * 0.001f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().D))
        {
            world.cameras[0].Move(mge::Vector3f( sin(world.cameras[0].world_rotation.z) * 0.001f, -cos(world.cameras[0].world_rotation.z) * 0.001f, 0.0f));
        }
        
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Space))
        {
            world.cameras[0].Move(mge::Vector3f(0.0f, 0.0f, 0.001f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().LShift))
        {
            world.cameras[0].Move(mge::Vector3f(0.0f, 0.0f, -0.001f));
        }
        
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Up))
        {
            world.cameras[0].Rotate(mge::Vector3f(0.0f, -0.001f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Down))
        {
            world.cameras[0].Rotate(mge::Vector3f(0.0f, 0.001f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Left))
        {
            world.cameras[0].Rotate(mge::Vector3f(0.0f, 0.0f, 0.001f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Right))
        {
            world.cameras[0].Rotate(mge::Vector3f(0.0f, 0.0f, -0.001f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Num0))
        {
            world.cameras[0].Rotate(mge::Vector3f(0.001f, 0.0f, 0.0f));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard().Num1))
        {
            world.cameras[0].Rotate(mge::Vector3f(-0.001f, 0.0f, 0.0f));
        }
        
        window.clear();
        
        A += 0.001;
        
        world.objects[0].world_location = mge::Vector3f(0.0f, 0.0f, sin(A));
        world.objects[1].world_rotation = mge::Vector3f(0.0f, 0.0f, A);
        world.objects[2].world_scale    = mge::Vector3f(1.0f, 2.0 - sin(A) ,2.0 + sin(A));


        for (auto visable_triangle_world: world.cameras[0].GetVisableTrianglesWorld(world.objects))
        {
            if (world.cameras[0].GetVisableTrianglesScreen(visable_triangle_world).size() > 0)
            {
                for (auto visable_screen_triangle : world.cameras[0].GetVisableTrianglesScreen(visable_triangle_world))
                {
                    sf::VertexArray triangle(sf::LineStrip, 4);
                    
                    triangle[0].position = sf::Vector2f(visable_screen_triangle.vertex[0].x, visable_screen_triangle.vertex[0].y);
                    triangle[1].position = sf::Vector2f(visable_screen_triangle.vertex[1].x, visable_screen_triangle.vertex[1].y);
                    triangle[2].position = sf::Vector2f(visable_screen_triangle.vertex[2].x, visable_screen_triangle.vertex[2].y);
                    triangle[3].position = sf::Vector2f(visable_screen_triangle.vertex[0].x, visable_screen_triangle.vertex[0].y);
                        
                    window.draw(triangle);
                    
                }
            }
        }
        
        window.display();
    }
}
