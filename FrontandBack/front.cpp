//#include "crow.h"
//#include "crow_all.h"
#include "/home/bub/crow/scripts/crow_all.h" 

int main()
{
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([](){
        auto page = crow::mustache::load_text("front.html");
        return page;
    });

    app.port(5000).multithreaded().run();
}