#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight) {
    m_pixel_size.x = pixelWidth;
    m_pixel_size.y = pixelHeight;

    m_aspectRatio = 1.0*(height/width);

    m_plane_center = {0, 0};
    m_plane_size = {BASE_WIDTH, BASE_HEIGHT*m_aspectRatio};
    m_zoomCount = 0;
    m_State = State::CALCULATING;

    // init vertexarray
    // ...
}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const {
    target.draw(m_vArray);
}

void ComplexPlane::UpdateRender() {
    if (m_State == CALCULATING) {
        for (int =0; i< //yval; i++) {
            for (int j=0; j<//xval; j++) {
                vArray[j+i*pixelWidth].position = {(float)j, (float)i};
                //mapPixelToCoords...
                //countIterations..
                Uint8 r, g, b;
                ///iterationsToRGB...
                vArray[j+i*pixelWidth].color = {r, g, b};
            }
        }
        m_state = DISPLAYING;
    }
}

void ComplexPlane::zoomIn() {
    m_ZoomCount++;
    int xSize = BASE_WIDTH * pow(BASE_ZOOM, m_ZoomCount);
    int ySize = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_ZoomCount);
    m_plane_size = //...,this. somehow
    m_State = CALCULATING;
}

void ComplexPlane::zoomOut() {
    m_ZoomCount--;
    int xSize = BASE_WIDTH * pow(BASE_ZOOM, m_ZoomCount);
    int ySize = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_ZoomCount);
    m_plane_size = //this
    m_State = CALCULATING;
}

void ComplexPlane::setCenter(Vector2i mousePixel) {
    //mapToCoords...
    m_plane_center = //that
    m_State = CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel) {
    //mapToCoords...
    m_mouseLocation = //that
}

void ComplexPlane::loadText(Text& text) {
    // stringstream
}

size_t ComplexPlane::countIterations(Vector2f coord) {
    // uhh
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) {
    // oough.
}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel) {
    // gug
}