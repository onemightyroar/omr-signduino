// Declare our scope's strip
Adafruit_NeoPixel strip = NULL;

// Define the OMR logo's "m" pixel location as a range
uint8_t m_pixels[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };


// Allow us to set our strip in this controller from another scope
void setLightStrip(Adafruit_NeoPixel &lightStrip) {
    strip = lightStrip;
}

void initLightStrip(Adafruit_NeoPixel &lightStrip) {
    // Set our scope's light strip
    setLightStrip(lightStrip);

    // Clear the light strip back to "black/blank"
    lightStrip.show();
}

// Change the color of ALL of the strip's LEDs
void changeColorAll(uint8_t R, uint8_t G, uint8_t B) {
    // Create our color from our RGB values
    uint32_t color = strip.Color(R, G, B);

    // Loop through each pixel in our strip
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, color);
    }

    // Show the things!
    strip.show();
}

// Change the color of the strip's pixels in the M (of the OMR logo)
void changeColorMPixels(uint8_t R, uint8_t G, uint8_t B) {
    // Create our color from our RGB values
    uint32_t color = strip.Color(R, G, B);

    uint8_t m_pixels_length = sizeof(m_pixels)/sizeof(m_pixels[0]);
    for (uint8_t i = 0; i < m_pixels_length; i++) {
        strip.setPixelColor(i, color);
    }

    // Show the things!
    strip.show();
}

// Get the color values as a string
char *getColorString(uint8_t R, uint8_t G, uint8_t B) {
    char colorString[100];

    sprintf(
        colorString,
        "Red: %d (%x)\r\nGreen: %d (%x)\r\nBlue: %d (%x)",
        R, R,
        G, G,
        B, B
    );

    return colorString;
}
