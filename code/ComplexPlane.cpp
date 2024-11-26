#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight) {
    m_pixel_size.x = pixelWidth;
    m_pixel_size.y = pixelHeight;

    m_aspectRatio = 1.0*(pixelHeight/pixelWidth);

    m_plane_center = {0, 0};
    m_plane_size = {BASE_WIDTH, BASE_HEIGHT*m_aspectRatio};
    m_zoomCount = 0;
    m_state = State::CALCULATING;

    m_vArray.setPrimitiveType(Points);
    m_vArray.resize(pixelWidth * pixelHeight);
}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const {
    target.draw(m_vArray);
}

void ComplexPlane::updateRender() {
    if (m_state == State::CALCULATING) {
        for (int i=0; i< VideoMode::getDesktopMode().height; i++) {
            for (int j=0; j< VideoMode::getDesktopMode().width; j++) {
                m_vArray[j+i*m_pixel_size.x].position = {(float)j, (float)i};

                //mapPixelToCoords...
                Vector2i testI = {j, i};
                Vector2f testF;
                testF = mapPixelToCoords(testI);

                //countIterations..
                Uint8 r, g, b;
                ///iterationsToRGB...

                m_vArray[j+i*m_pixel_size.x].color = {r, g, b};
            }
        }
        m_state = State::DISPLAYING;
    }
}

void ComplexPlane::zoomIn() {
    m_zoomCount++;
    int xSize = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
    int ySize = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
    m_plane_size.x = xSize;
    m_plane_size.y = ySize;
    m_state = State::CALCULATING;
}

void ComplexPlane::zoomOut() {
    m_zoomCount--;
    int xSize = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
    int ySize = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
    m_plane_size.x = xSize;
    m_plane_size.y = ySize;
    m_state = State::CALCULATING;
}

void ComplexPlane::setCenter(Vector2i mousePixel) {
    //mapToCoords...
    Vector2f test = mapPixelToCoords(mousePixel);

    m_plane_center = test;
    m_state = State::CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel) {
    //mapToCoords...
    Vector2f test = mapPixelToCoords(mousePixel);

    m_mouseLocation = test;
}

void ComplexPlane::loadText(Text& text) {
    // stringstream
    std::stringstream testss;
    //std::string tests;
    testss << "Mandelbrot Set\n" <<
            "Center: (" << m_plane_center.x << ", " << m_plane_center.y << ")\n" <<
            "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")\n" <<
            "Left click to zoom in\n" <<
            "Right click to zoom out";
    //std::stringstream testss(tests);
}

size_t ComplexPlane::countIterations(Vector2f coord) {
    // uhh
    //z(i+1) = z(i)^2 + c; z(0) = 0
    std::complex<float> c(coord.x, coord.y);
    std::complex<float> z = c;
    int i = 0;
    while (abs(z) < 2.9 && i < MAX_ITER) {
        z = pow(z, 2) + c;
        i++;
    }
    return i;
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) {
    // oough.
    int range = MAX_ITER/5;
    if (count < range) {
        r = 75;
        g = 75;
        b = 165;
    } else if (count < 2*range) {
        r = 154;
        g = 92;
        b = 175;
    } else if (count < 3*range) {
        r = 224;
        g = 118;
        b = 158;
    } else if (count < 4*range) {
        r = 250;
        g = 190;
        b = 140;
    } else {
        r = 252;
        g = 255;
        b = 148;
    }
}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel) {
    // gug
    // okk sooo this maps... mousePixel to a Vector2f.... okkkkkkk
    // i think this is on click?
    // ((n  - a) / (b - a)) * (d - c) + c
    // sooooo
    // ughhhhh
    float debugX, debugY;
    // need to figure out how to get width and height of the screen
    debugX = ((mousePixel.x - 0) / (VideoMode::getDesktopMode().width - 0)) * (m_plane_size.x) +
             (m_plane_center.x - m_plane_size.x / 2.0);
    debugY = ((mousePixel.y - 0) / (VideoMode::getDesktopMode().height - 0)) * (m_plane_size.y) +
             (m_plane_center.y - m_plane_size.y / 2.0);
    Vector2f ret = {debugX, debugY};
    return ret;
}