void backgroundColorCommand(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // Check our credentials
    if (!protectEndpoint(server)) {
        return;
    }

    // 200 "OK" response
    server.httpSuccess();

    // Declare our color values
    int red = 255;
    int green = 255;
    int blue = 255;

    switch (type) {
        case WebServer::HEAD:
            return;
            break;
        case WebServer::POST:
            // Declare our param vars
            char paramName[32], paramValue[140];

            // Loop through each param
            while (server.readPOSTparam(paramName, 32, paramValue, 140)) {
                // Red
                if (strcasecmp(paramName, "r") == 0 || strcasecmp(paramName, "red") == 0) {
                    red = strtoul(paramValue, NULL, 10);
                }

                // Green
                if (strcasecmp(paramName, "g") == 0 || strcasecmp(paramName, "green") == 0) {
                    green = strtoul(paramValue, NULL, 10);
                }

                // Blue
                if (strcasecmp(paramName, "b") == 0 || strcasecmp(paramName, "blue") == 0) {
                    blue = strtoul(paramValue, NULL, 10);
                }
            }

            // Change our color!
            changeColorBackgroundPixels(red, green, blue);

            // Print the new color values
            server.print(getColorString(red, green, blue));

            break;
        case WebServer::DELETE:
            // Set the color values to black/off
            red = 0;
            green = 0;
            blue = 0;

            // Change our color!
            changeColorBackgroundPixels(red, green, blue);

            // Print the new color values
            server.print(getColorString(red, green, blue));

            break;
        default:
            // Print the color values
            server.print(getColorString(red, green, blue));

            break;
    }
}

void backgroundAnimateCommand(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // Check our credentials
    if (!protectEndpoint(server)) {
        return;
    }

    // 200 "OK" response
    server.httpSuccess();

    // Create our animation args struct
    lightControllerArgs animationArgs;
    strcpy(animationArgs.action, "line-fill");
    animationArgs.red = 255;
    animationArgs.green = 255;
    animationArgs.blue = 255;
    animationArgs.delay = 0;

    switch (type) {
        case WebServer::HEAD:
            return;
            break;
        case WebServer::POST:
            // Declare our param vars
            char paramName[32], paramValue[140];

            // Loop through each param
            while (server.readPOSTparam(paramName, 32, paramValue, 140)) {
                // Red
                if (strcasecmp(paramName, "r") == 0 || strcasecmp(paramName, "red") == 0) {
                    animationArgs.red = strtoul(paramValue, NULL, 10);
                }

                // Green
                if (strcasecmp(paramName, "g") == 0 || strcasecmp(paramName, "green") == 0) {
                    animationArgs.green = strtoul(paramValue, NULL, 10);
                }

                // Blue
                if (strcasecmp(paramName, "b") == 0 || strcasecmp(paramName, "blue") == 0) {
                    animationArgs.blue = strtoul(paramValue, NULL, 10);
                }

                // Action
                if (strcasecmp(paramName, "a") == 0 || strcasecmp(paramName, "action") == 0) {
                    strcpy(animationArgs.action, paramValue);
                }

                // Delay
                if (strcasecmp(paramName, "d") == 0 || strcasecmp(paramName, "delay") == 0
                    || strcasecmp(paramName, "s") == 0 || strcasecmp(paramName, "speed") == 0) {

                    animationArgs.delay = strtoul(paramValue, NULL, 10);
                }
            }

            // Set our current animation and args
            setCurrentAnimation(&animateBackgroundPixels);
            setCurrentAnimationArgs(animationArgs);

            // Print the new color values
            server.print(getColorString(animationArgs.red, animationArgs.green, animationArgs.blue));

            // Create and print the new action value
            server.print("\nAction: ");
            server.print(animationArgs.action);

            // Create and print the new action value
            server.print("\nDelay: ");
            server.print(animationArgs.delay);

            break;
        case WebServer::DELETE:
            // Kill the animation callback
            setCurrentAnimation(NULL);

            server.print("\nAction: ");

            break;
        default:
            // Print the color values
            server.print(getColorString(animationArgs.red, animationArgs.green, animationArgs.blue));

            // Create and print the action value
            server.print("\nAction: ");
            server.print(animationArgs.action);

            // Create and print the action value
            server.print("\nDelay: ");
            server.print(animationArgs.delay);

            break;
    }
}

void mColorCommand(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // Check our credentials
    if (!protectEndpoint(server)) {
        return;
    }

    // 200 "OK" response
    server.httpSuccess();

    // Declare our color values
    int red = 255;
    int green = 255;
    int blue = 255;

    switch (type) {
        case WebServer::HEAD:
            return;
            break;
        case WebServer::POST:
            // Declare our param vars
            char paramName[32], paramValue[140];

            // Loop through each param
            while (server.readPOSTparam(paramName, 32, paramValue, 140)) {
                // Red
                if (strcasecmp(paramName, "r") == 0 || strcasecmp(paramName, "red") == 0) {
                    red = strtoul(paramValue, NULL, 10);
                }

                // Green
                if (strcasecmp(paramName, "g") == 0 || strcasecmp(paramName, "green") == 0) {
                    green = strtoul(paramValue, NULL, 10);
                }

                // Blue
                if (strcasecmp(paramName, "b") == 0 || strcasecmp(paramName, "blue") == 0) {
                    blue = strtoul(paramValue, NULL, 10);
                }
            }

            // Change our color!
            changeColorMPixels(red, green, blue);

            // Print the new color values
            server.print(getColorString(red, green, blue));

            break;
        case WebServer::DELETE:
            // Set the color values to black/off
            red = 0;
            green = 0;
            blue = 0;

            // Change our color!
            changeColorMPixels(red, green, blue);

            // Print the new color values
            server.print(getColorString(red, green, blue));

            break;
        default:
            // Print the color values
            server.print(getColorString(red, green, blue));

            break;
    }
}

void mAnimateCommand(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // Check our credentials
    if (!protectEndpoint(server)) {
        return;
    }

    // 200 "OK" response
    server.httpSuccess();

    // Create our animation args struct
    lightControllerArgs animationArgs;
    strcpy(animationArgs.action, "line-fill");
    animationArgs.red = 255;
    animationArgs.green = 255;
    animationArgs.blue = 255;
    animationArgs.delay = 0;

    switch (type) {
        case WebServer::HEAD:
            return;
            break;
        case WebServer::POST:
            // Declare our param vars
            char paramName[32], paramValue[140];

            // Loop through each param
            while (server.readPOSTparam(paramName, 32, paramValue, 140)) {
                // Red
                if (strcasecmp(paramName, "r") == 0 || strcasecmp(paramName, "red") == 0) {
                    animationArgs.red = strtoul(paramValue, NULL, 10);
                }

                // Green
                if (strcasecmp(paramName, "g") == 0 || strcasecmp(paramName, "green") == 0) {
                    animationArgs.green = strtoul(paramValue, NULL, 10);
                }

                // Blue
                if (strcasecmp(paramName, "b") == 0 || strcasecmp(paramName, "blue") == 0) {
                    animationArgs.blue = strtoul(paramValue, NULL, 10);
                }

                // Action
                if (strcasecmp(paramName, "a") == 0 || strcasecmp(paramName, "action") == 0) {
                    strcpy(animationArgs.action, paramValue);
                }

                // Delay
                if (strcasecmp(paramName, "d") == 0 || strcasecmp(paramName, "delay") == 0
                    || strcasecmp(paramName, "s") == 0 || strcasecmp(paramName, "speed") == 0) {

                    animationArgs.delay = strtoul(paramValue, NULL, 10);
                }
            }

            // Set our current animation and args
            setCurrentAnimation(&animateMPixels);
            setCurrentAnimationArgs(animationArgs);

            // Print the new color values
            server.print(getColorString(animationArgs.red, animationArgs.green, animationArgs.blue));

            // Create and print the new action value
            server.print("\nAction: ");
            server.print(animationArgs.action);

            // Create and print the new action value
            server.print("\nDelay: ");
            server.print(animationArgs.delay);

            break;
        case WebServer::DELETE:
            // Kill the animation callback
            setCurrentAnimation(NULL);

            server.print("\nAction: ");

            break;
        default:
            // Print the color values
            server.print(getColorString(animationArgs.red, animationArgs.green, animationArgs.blue));

            // Create and print the action value
            server.print("\nAction: ");
            server.print(animationArgs.action);

            // Create and print the action value
            server.print("\nDelay: ");
            server.print(animationArgs.delay);

            break;
    }
}

void colorCommand(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // Check our credentials
    if (!protectEndpoint(server)) {
        return;
    }

    // 200 "OK" response
    server.httpSuccess();

    // Declare our animate values
    int red = 255;
    int green = 255;
    int blue = 255;

    switch (type) {
        case WebServer::HEAD:
            return;
            break;
        case WebServer::POST:
            // Declare our param vars
            char paramName[32], paramValue[140];

            // Loop through each param
            while (server.readPOSTparam(paramName, 32, paramValue, 140)) {
                // Red
                if (strcasecmp(paramName, "r") == 0 || strcasecmp(paramName, "red") == 0) {
                    red = strtoul(paramValue, NULL, 10);
                }

                // Green
                if (strcasecmp(paramName, "g") == 0 || strcasecmp(paramName, "green") == 0) {
                    green = strtoul(paramValue, NULL, 10);
                }

                // Blue
                if (strcasecmp(paramName, "b") == 0 || strcasecmp(paramName, "blue") == 0) {
                    blue = strtoul(paramValue, NULL, 10);
                }
            }

            // Change our color!
            changeColorAll(red, green, blue);

            // Print the new color values
            server.print(getColorString(red, green, blue));

            break;
        case WebServer::DELETE:
            // Set the color values to black/off
            red = 0;
            green = 0;
            blue = 0;

            // Change our color!
            changeColorAll(red, green, blue);

            // Print the new color values
            server.print(getColorString(red, green, blue));

            break;
        default:
            // Print the color values
            server.print(getColorString(red, green, blue));

            break;
    }
}

void allAnimateCommand(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // Check our credentials
    if (!protectEndpoint(server)) {
        return;
    }

    // 200 "OK" response
    server.httpSuccess();

    // Create our animation args struct
    lightControllerArgs animationArgs;
    strcpy(animationArgs.action, "line-fill");
    animationArgs.red = 255;
    animationArgs.green = 255;
    animationArgs.blue = 255;
    animationArgs.delay = 0;

    switch (type) {
        case WebServer::HEAD:
            return;
            break;
        case WebServer::POST:
            // Declare our param vars
            char paramName[32], paramValue[140];

            // Loop through each param
            while (server.readPOSTparam(paramName, 32, paramValue, 140)) {
                // Red
                if (strcasecmp(paramName, "r") == 0 || strcasecmp(paramName, "red") == 0) {
                    animationArgs.red = strtoul(paramValue, NULL, 10);
                }

                // Green
                if (strcasecmp(paramName, "g") == 0 || strcasecmp(paramName, "green") == 0) {
                    animationArgs.green = strtoul(paramValue, NULL, 10);
                }

                // Blue
                if (strcasecmp(paramName, "b") == 0 || strcasecmp(paramName, "blue") == 0) {
                    animationArgs.blue = strtoul(paramValue, NULL, 10);
                }

                // Action
                if (strcasecmp(paramName, "a") == 0 || strcasecmp(paramName, "action") == 0) {
                    strcpy(animationArgs.action, paramValue);
                }

                // Delay
                if (strcasecmp(paramName, "d") == 0 || strcasecmp(paramName, "delay") == 0
                    || strcasecmp(paramName, "s") == 0 || strcasecmp(paramName, "speed") == 0) {

                    animationArgs.delay = strtoul(paramValue, NULL, 10);
                }
            }

            // Set our current animation and args
            setCurrentAnimation(&animateAll);
            setCurrentAnimationArgs(animationArgs);

            // Print the new color values
            server.print(getColorString(animationArgs.red, animationArgs.green, animationArgs.blue));

            // Create and print the new action value
            server.print("\nAction: ");
            server.print(animationArgs.action);

            // Create and print the new action value
            server.print("\nDelay: ");
            server.print(animationArgs.delay);

            break;
        case WebServer::DELETE:
            // Kill the animation callback
            setCurrentAnimation(NULL);

            server.print("\nAction: ");

            break;
        default:
            // Print the color values
            server.print(getColorString(animationArgs.red, animationArgs.green, animationArgs.blue));

            // Create and print the action value
            server.print("\nAction: ");
            server.print(animationArgs.action);

            // Create and print the action value
            server.print("\nDelay: ");
            server.print(animationArgs.delay);

            break;
    }
}
