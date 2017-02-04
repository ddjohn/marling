#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <libwebsockets.h>

class WebSocket {

public:
   WebSocket(int port);
   ~WebSocket();

  void run();

private:
   struct lws_context *context;

};

#endif
