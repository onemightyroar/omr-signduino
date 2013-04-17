/* Default, root command to respond with */
void defaultCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // Check our credentials
    if (protectEndpoint(server)) {
        // 200 "OK" response
        server.httpSuccess();

        // Not a HEAD request
        if (type != WebServer::HEAD) {
            server.print("One Mighty Roar");
        }
    }
}

/* Unknown endpoint/bad match response */
void failureCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // 404 "Not Found" response
    httpNotFound(server);
}

/* Generic response when other commands fail to match/execute */
void urlPathCommand(WebServer &server, WebServer::ConnectionType type, char **url_path, char *url_tail, bool tail_complete)
{
}
