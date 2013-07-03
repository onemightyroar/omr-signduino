// Declare our scope's strip
Adafruit_NeoPixel strip = NULL;

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
