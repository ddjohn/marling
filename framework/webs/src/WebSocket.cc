#include "Trace.h"
#include "WebSocket.h"
#include <string.h>
#include <signal.h>

CLASS("WebSocket");

struct per_session_data {
    int fd;
};

static int destroy_flag = 0;

static void INT_HANDLER(int signo) {
    destroy_flag = 1;
}


WebSocket::WebSocket(int port) {
   METHOD("WebSocket()");

    struct sigaction act;
    act.sa_handler = INT_HANDLER;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction( SIGINT, &act, 0);

   struct lws_protocols protocol;
   protocol.name = "my-echo-protocol";
//   protocol.callback = ws_service_callback;
   protocol.per_session_data_size=sizeof(struct per_session_data);
   protocol.rx_buffer_size = 0;

   struct lws_context_creation_info info;
   //memset(&info, 0, sizeof info);
   info.port = port;
   info.iface = NULL;
   info.protocols = &protocol;
   info.extensions = lws_get_internal_extensions();
   info.ssl_cert_filepath = NULL;
   info.ssl_private_key_filepath = NULL;
   info.gid = -1;
   info.uid = -1;
   info.options = 0;

   context = lws_create_context(&info);
   if(context == NULL)
      EXCEPTION("lws_create_context failed");
}

WebSocket::~WebSocket() {
   METHOD("~WebSocket()");

    lws_context_destroy(context);
}

void WebSocket::run() {
	METHOD("run()");

    while ( !destroy_flag ) {
        lws_service(context, 50);
    }
} 
