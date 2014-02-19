#include <lacewing.h>

static void on_get(lw_ws webserver, lw_ws_req req) {
    (void) webserver;
    lw_stream_writef(req,
            "<form method=\"POST\" action=\"/\">"
            "<p>"
            "What's your name?<br />"
            "<input type=\"text\" id=\"name\" name=\"name\"><br />"
            "What do you want to post?<br />"
            "<input type=\"text\" id=\"message\" name=\"message\">"
            "</p>"
            "<input type=\"submit\">"
            "</form>"
            );
}

static void on_post(lw_ws webserver, lw_ws_req req)
{
   (void)webserver;
   lw_stream_writef (req, "post from %s", lw_version ());
   
   lw_ws_req_param param = lw_ws_req_POST_first(req);
   while(param){
       lw_stream_writef (req, "<p>%s : %s</p>",lw_ws_req_param_name(param), lw_ws_req_param_value(param) );
       param = lw_ws_req_param_next(param);
       
   }
   
}


int main (int argc, char * argv[])
{
   (void)argc;
   (void)argv;
    
   lw_pump pump = lw_eventpump_new ();
   lw_ws webserver = lw_ws_new (pump);

   lw_ws_on_get (webserver, on_get);
   
   lw_ws_on_post(webserver, on_post);
   
   lw_ws_host (webserver, 8181);
    
   lw_eventpump_start_eventloop (pump);
    
   lw_ws_delete (webserver);
   lw_pump_delete (pump);

   return 0;
}

