/* Include our web framework extensions */
#include "webFrameworkExtensions.h"

/* Include our generic response functions */
#include "genericResponses.h"

/* Include our web controller/route responders */
#include "webController.h"

// Setup our web server
void setupServerCommands(WebServer &server) {
    // Setup generic route commands
    server.setDefaultCommand(&defaultCmd);
    server.setFailureCommand(&failureCmd);
    server.setUrlPathCommand(&urlPathCommand);

    // Add specific route commands
    server.addCommand("color", &colorCommand);
    server.addCommand("b-color", &backgroundColorCommand);
    server.addCommand("b-animate", &backgroundAnimateCommand);
    server.addCommand("m-color", &mColorCommand);
    server.addCommand("m-animate", &mAnimateCommand);
}
