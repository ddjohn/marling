#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <libwebsockets.h>

static int destroy_flag = 0;

static void INT_HANDLER(int signo) {
    destroy_flag = 1;
}

/* *
 * websocket_write_back: write the string data to the destination wsi.
 */
int websocket_write_back(struct lws *wsi_in, char *str, int str_size_in) 
{
    if (str == NULL || wsi_in == NULL)
        return -1;

    int n;
    int len;
    unsigned char *out = NULL;

    if (str_size_in < 1) 
        len = strlen(str);
    else
        len = str_size_in;

    out = (unsigned char *)malloc(sizeof(char)*(LWS_SEND_BUFFER_PRE_PADDING + len + LWS_SEND_BUFFER_POST_PADDING));
    //* setup the buffer*/
    memcpy (out + LWS_SEND_BUFFER_PRE_PADDING, str, len );
    //* write out*/
    n = lws_write(wsi_in, out + LWS_SEND_BUFFER_PRE_PADDING, len, LWS_WRITE_TEXT);

    printf("[websocket_write_back] %s\n", str);
    //* free the buffer*/
    free(out);

    return n;
}


static int ws_service_callback(
                         struct lws *wsi,
                         enum lws_callback_reasons reason, void *user,
                         void *in, size_t len)
{

    switch (reason) {

        case LWS_CALLBACK_ESTABLISHED:
            printf("[Main Service] Connection established\n");
            break;

        //* If receive a data from client*/
        case LWS_CALLBACK_RECEIVE:
            printf("[Main Service] Server recvived:%s\n",(char *)in);

            //* echo back to client*/
            websocket_write_back(wsi ,(char *)in, -1);

            break;
    case LWS_CALLBACK_CLOSED:
            printf("[Main Service] Client close.\n");
        break;

    default:
            break;
    }

    return 0;
}

struct per_session_data {
    int fd;
};

int main(int args, char* argv[]) {
    int port = 5000;
    const char *interface = NULL;
    struct lws_context_creation_info info;
    struct lws_protocols protocol;
    struct lws_context *context;
    const char *cert_path = NULL;
    const char *key_path = NULL;
    int opts = 0;

    struct sigaction act;
    act.sa_handler = INT_HANDLER;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction( SIGINT, &act, 0);

    protocol.name = "my-echo-protocol";
    protocol.callback = ws_service_callback;
    protocol.per_session_data_size=sizeof(struct per_session_data);
    protocol.rx_buffer_size = 0;

    memset(&info, 0, sizeof info);
    info.port = port;
    info.iface = interface;
    info.protocols = &protocol;
    info.extensions = lws_get_internal_extensions();
    info.ssl_cert_filepath = cert_path;
    info.ssl_private_key_filepath = key_path;
    info.gid = -1;
    info.uid = -1;
    info.options = opts;

    context = lws_create_context(&info);
    if (context == NULL) {
        printf("[Main] Websocket context create error.\n");
        return -1;
    }

    printf("[Main] Websocket context create success.\n");

    //
    while ( !destroy_flag ) {
        lws_service(context, 50);
    }
    usleep(10);
    lws_context_destroy(context);

    return 0;
}
