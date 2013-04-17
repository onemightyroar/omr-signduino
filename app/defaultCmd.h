/* Default, root command to respond with */
void defaultCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
    // 200 "OK" response
    server.httpSuccess();

    if (type == WebServer::GET) {
        server.print("One Mighty Roar");
    }
}
