#include "ComplexPlane.h"

using namespace std;

int main()
{

    VideoMode vm(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);

    RenderWindow window(vm, "Mandelbrot!", Style::Default);
    ComplexPlane(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);

    sf::Font font;
    sf::Text text;
    text.setFont(font);
    if (!font.loadFromFile("Comic Sans MS.ttf"))
        throw runtime_error("Could not find font");

    text.setString("Test");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(::sf::Text::Bold);



    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    //Zoom Out
                    //setCenter
                }

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    //Zoom In
                    //setCenter
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                //setMouseLocation
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        //Update Scene
            //UpdateRender
            //LoadText

        //Draw
            //Clear RenderWindow
            //ComplexPlane
            //Text
            //Display RenderWindow
    }
    return 0;
}