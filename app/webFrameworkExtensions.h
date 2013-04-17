/* 404 Not Found error */
void httpNotFound(WebServer &server)
{
    P(notFoundMsg) =
        "HTTP/1.0 404 Not Found" CRLF
        WEBDUINO_SERVER_HEADER
        "Content-Type: text/html" CRLF
        CRLF;

    server.printP(notFoundMsg);
}

/* Protect an endpoint by checking our API credentials */
bool protectEndpoint(WebServer &server)
{
    // Check our credentials
    if (server.checkCredentials(HTTP_BASIC_CREDENTIALS) != true) {
        // 401 Unauthorized (ask for credentials)
        server.httpUnauthorized();

        return false;
    }

    return true;
}
