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
