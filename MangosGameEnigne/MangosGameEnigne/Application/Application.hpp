#ifndef Application_hpp
#define Application_hpp

#include <SFML/graphics.hpp>
#include "Spawnables.hpp"

namespace mge
{
    class App
    {
        std::unique_ptr<World> world;
        
        static std::unique_ptr<sf::RenderWindow> window;
                
        static void Draw(const triangle2& A, const float3& colour);
                
    public:
        
        App();
                
        ~App();

        void Run();
        
    };
}
#endif
