void colorCommand(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // Check our credentials
    if (protectEndpoint(server)) {
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
                char paramName[16], paramValue[16];

                // Loop through each param
                while (server.readPOSTparam(paramName, 16, paramValue, 16)) {
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

                server.print("OK");
                server.printCRLF();

                server.print("Red: ");
                server.print(red);
                server.printCRLF();

                server.print("Green: ");
                server.print(green);
                server.printCRLF();

                server.print("Blue: ");
                server.print(blue);
                server.printCRLF();

                break;
            case WebServer::DELETE:
                changeColorAll(0, 0, 0);
                server.print("RESET");
                server.printCRLF();
                server.print("OFF");
                break;
            default:
                changeColorAll(255, 0, 255);
                server.print("OMR Signduino");
                break;
        }
    }
}
