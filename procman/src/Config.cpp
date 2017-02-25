#include "Trace.h"
#include "Config.h"
#include "json.h"

CLASS("Config");

void callback(void* data) {
   METHOD("callback");

};

Config::Config(std::string file) {
   METHOD("Config(std::string)");

   void* data = NULL;

   json_parser parser;
   json_parser_init(&parser, NULL, callback, data);


}

Config::~Config() {
   METHOD("~Config()");

}

