#include <iostream>

// Link statically with GLEW
#define GLEW_STATIC

// Headers
#include <GL/glew.h>
#include <SFML/Window.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    
    sf::Window window( sf::VideoMode( 800, 600, 32 ), "OpenGL", sf::Style::Titlebar | sf::Style::Close, settings );
    
    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if ( GLEW_OK != glewInit( ) )
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }
    
    bool running = true;
    while ( running )
    {
        sf::Event windowEvent;
        while ( window.pollEvent( windowEvent ) )
        {
            switch ( windowEvent.type )
            {
                case sf::Event::Closed:
                    running = false;
                    break;
            }
        }
        
        // Clear the screen to black
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear( GL_COLOR_BUFFER_BIT );
        
        // Draw OpenGL
        
        
        // Swap buffers
        window.display( );
    }
    
    window.close( );
    
    return 0;
}