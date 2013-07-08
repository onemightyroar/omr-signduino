// Define our light controller argument structure
struct lightControllerArgs {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    char action[];
};

// Define our callback type
typedef void (*Callback)(lightControllerArgs);

// Declare our scope's strip
Adafruit_NeoPixel strip = NULL;

// Define the OMR logo's "m" pixel location as a range
uint8_t m_pixels[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };

// Define an animation callback
Callback currentAnimation = NULL;

// Define our callback's args
lightControllerArgs currentAnimationArgs;



// Allow us to set our strip in this controller from another scope
void setLightStrip(Adafruit_NeoPixel &lightStrip) {
    strip = lightStrip;
}

// Set our current animation callback
void setCurrentAnimation(Callback animationLoopCallback) {
    currentAnimation = animationLoopCallback;
}

// Set our current animation callback's arguments
void setCurrentAnimationArgs(lightControllerArgs args) {
    currentAnimationArgs = args;
}

// Initialize our light strip
void initLightStrip(Adafruit_NeoPixel &lightStrip) {
    // Set our scope's light strip
    setLightStrip(lightStrip);

    // Clear the light strip back to "black/blank"
    lightStrip.show();
}


/**
 * Light/Color functions go here
 */

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

    // Get the length of the m_pixels array
    uint8_t m_pixels_length = sizeof(m_pixels)/sizeof(m_pixels[0]);

    // Loop through each pixel in the "m"
    for (uint8_t i = 0; i < m_pixels_length; i++) {
        strip.setPixelColor(i, color);
    }

    // Show the things!
    strip.show();
}

// Change the color of the strip's pixels in the M (of the OMR logo)
void animateMPixels(char action[], uint8_t R, uint8_t G, uint8_t B) {
    // Create our color from our RGB values
    uint32_t color = strip.Color(R, G, B);

    // Get the length of the m_pixels array
    uint8_t m_pixels_length = sizeof(m_pixels)/sizeof(m_pixels[0]);

    // Loop through each pixel in the "m"
    for (int8_t i = (m_pixels_length - 1); i >= 0; i--) {
        strip.setPixelColor(i, color);
        strip.show();
        delay(40);
    }
    for (int8_t i = 0; i < m_pixels_length; i++) {
        strip.setPixelColor(i, 0, 0, 255);
        strip.show();
        delay(40);
    }
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


/**
 * Struct arg versions go here
 */

void animateMPixels(lightControllerArgs args) {
    animateMPixels(args.action, args.red, args.green, args.blue);
}
