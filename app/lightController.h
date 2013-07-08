// Define our light controller argument structure
struct lightControllerArgs {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    char action[140];
    uint16_t delay;
};

// Define our callback type
typedef void (*Callback)(lightControllerArgs);

// Declare our scope's strip
Adafruit_NeoPixel strip = NULL;

// Define the OMR logo's "m" pixel location as a range
uint8_t m_pixels[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };

// Define the OMR sign's "background" pixel location as a range
uint16_t b_pixels[155] = { 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179 };

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

// Change the color of the sign's background pixels
void changeColorBackgroundPixels(uint8_t R, uint8_t G, uint8_t B) {
    // Create our color from our RGB values
    uint32_t color = strip.Color(R, G, B);

    // Get the length of the b_pixels array
    uint8_t b_pixels_length = sizeof(b_pixels)/sizeof(b_pixels[0]);

    // Loop through each pixel
    for (uint8_t i = 0; i < b_pixels_length; i++) {
        strip.setPixelColor(b_pixels[i], color);
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

// Animate the color of the sign's background pixels
void animateBackgroundPixels(char action[], uint8_t R, uint8_t G, uint8_t B, uint16_t delayTime = 0) {
    // Create our color from our RGB values
    uint32_t color = strip.Color(R, G, B);

    // Create some reusable colors
    uint32_t blackColor = strip.Color(0, 0, 0);

    // Get the length of the b_pixels array
    uint8_t b_pixels_length = sizeof(b_pixels)/sizeof(b_pixels[0]);

    // Turn the action into a String object (lower cased)
    String str_action = String(action);
    str_action.toLowerCase();

    // Holy hell, I hate C. Make sure to ALWAYS append a "\0" character to your "strings" (character arrays)
    if (str_action.equals("line-fill\0")) {
        // Set a sensible default
        if (delayTime == 0) {
            delayTime = 50;
        }

        // Loop through each pixel in the "m"
        for (int16_t i = (b_pixels_length - 1); i >= 0; i--) {
            strip.setPixelColor(b_pixels[i], color);
            strip.show();
            delay(delayTime);
        }
        for (int16_t i = (b_pixels_length - 1); i >= 0; i--) {
            strip.setPixelColor(b_pixels[i], blackColor);
            strip.show();
            delay(delayTime);
        }

        for (uint16_t i = 0; i < b_pixels_length; i++) {
            strip.setPixelColor(b_pixels[i], color);
            strip.show();
            delay(delayTime);
        }
        for (uint16_t i = 0; i < b_pixels_length; i++) {
            strip.setPixelColor(b_pixels[i], blackColor);
            strip.show();
            delay(delayTime);
        }

    } else if (str_action.equals("snake\0")) {
        // Set a sensible default
        if (delayTime == 0) {
            delayTime = 160;
        }

        // Loop through each pixel in the "m"
        for (int16_t i = b_pixels_length; i >= 0; i -= 2) {
            if (i != (b_pixels_length - 1)) {
                strip.setPixelColor(b_pixels[i], blackColor);
            }

            strip.setPixelColor(b_pixels[i - 1], color);
        }

        strip.show();
        delay(delayTime);

        for (int16_t i = (b_pixels_length - 1); i >= 0; i -= 2) {
            strip.setPixelColor(b_pixels[i], blackColor);
            strip.setPixelColor(b_pixels[i - 1], color);
        }

        strip.show();
        delay(delayTime);

    } else {
        // Set a sensible default
        if (delayTime == 0) {
            delayTime = 160;
        }

        // Setup our colors
        uint32_t redColor = strip.Color(255, 0, 0);

        // Loop through each pixel in the "m"
        for (uint8_t j = 0; j < 2; j++) {
            for (int16_t i = (b_pixels_length - 1); i >= 0; i--) {
                strip.setPixelColor(b_pixels[i], redColor);
            }

            strip.show();
            delay(delayTime);

            for (int16_t i = (b_pixels_length - 1); i >= 0; i--) {
                strip.setPixelColor(b_pixels[i], blackColor);
            }

            strip.show();
            delay(delayTime);
        }
    }
}

// Animate the color of the strip's pixels in the M (of the OMR logo)
void animateMPixels(char action[], uint8_t R, uint8_t G, uint8_t B, uint16_t delayTime = 0) {
    // Create our color from our RGB values
    uint32_t color = strip.Color(R, G, B);

    // Create some reusable colors
    uint32_t blackColor = strip.Color(0, 0, 0);

    // Get the length of the m_pixels array
    uint8_t m_pixels_length = sizeof(m_pixels)/sizeof(m_pixels[0]);

    // Turn the action into a String object (lower cased)
    String str_action = String(action);
    str_action.toLowerCase();

    // Holy hell, I hate C. Make sure to ALWAYS append a "\0" character to your "strings" (character arrays)
    if (str_action.equals("line-fill\0")) {
        // Set a sensible default
        if (delayTime == 0) {
            delayTime = 50;
        }

        // Loop through each pixel in the "m"
        for (int8_t i = (m_pixels_length - 1); i >= 0; i--) {
            strip.setPixelColor(i, color);
            strip.show();
            delay(delayTime);
        }
        for (int8_t i = (m_pixels_length - 1); i >= 0; i--) {
            strip.setPixelColor(i, blackColor);
            strip.show();
            delay(delayTime);
        }

        for (int8_t i = 0; i < m_pixels_length; i++) {
            strip.setPixelColor(i, color);
            strip.show();
            delay(delayTime);
        }
        for (int8_t i = 0; i < m_pixels_length; i++) {
            strip.setPixelColor(i, blackColor);
            strip.show();
            delay(delayTime);
        }

    } else if (str_action.equals("snake\0")) {
        // Set a sensible default
        if (delayTime == 0) {
            delayTime = 160;
        }

        // Loop through each pixel in the "m"
        for (int8_t i = m_pixels_length; i >= 0; i -= 2) {
            if (i != (m_pixels_length - 1)) {
                strip.setPixelColor(i, blackColor);
            }

            strip.setPixelColor(i - 1, color);
        }

        strip.show();
        delay(delayTime);

        for (int8_t i = (m_pixels_length - 1); i >= 0; i -= 2) {
            strip.setPixelColor(i, blackColor);
            strip.setPixelColor(i - 1, color);
        }

        strip.show();
        delay(delayTime);

    } else {
        // Set a sensible default
        if (delayTime == 0) {
            delayTime = 160;
        }

        // Setup our colors
        uint32_t redColor = strip.Color(255, 0, 0);

        // Loop through each pixel in the "m"
        for (uint8_t j = 0; j < 2; j++) {
            for (int8_t i = (m_pixels_length - 1); i >= 0; i--) {
                strip.setPixelColor(i, redColor);
            }

            strip.show();
            delay(delayTime);

            for (int8_t i = (m_pixels_length - 1); i >= 0; i--) {
                strip.setPixelColor(i, blackColor);
            }

            strip.show();
            delay(delayTime);
        }
    }
}

// Change the color of ALL of the strip's LEDs
void changeColorAll(uint8_t R, uint8_t G, uint8_t B) {
    // Call our separate functions
    changeColorBackgroundPixels(R, G, B);
    changeColorMPixels(R, G, B);
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
    animateMPixels(args.action, args.red, args.green, args.blue, args.delay);
}

void animateBackgroundPixels(lightControllerArgs args) {
    animateBackgroundPixels(args.action, args.red, args.green, args.blue, args.delay);
}
