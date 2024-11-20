#include <cmath>
#include <complex>

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

// enum class...
enum State {
    CALCULATING
    DISPLAYING
};

class ComplexPlane {
    // Constructor
    ComplexPlane(int pixelWidth, int pixelHeight);

    void draw(RenderTarget& target, RenderStates states) const;

    void updateRender();
    void zoomIn();
    void zoomOut();

    void setCenter(Vector2i mousePixel);
    void setMouseLocation(Vector2i mousePixel);
    
    void loadText(Text& text);
    size_t countIterations(Vector2f coord);
    void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b);
    Vector2f mapPixelToCoords(Vector2i mousePixel);
}