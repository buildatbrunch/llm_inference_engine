#include <iostream>

#include "crow.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/generate")
      .methods("POST"_method)
      ([](const crow::request& req){
        auto body = crow::json::load(req.body);
        if (!body || !body.has("prompt")) {
            return crow::response(400, crow::json::wvalue({{"error", "Invalid request body"}}));
        }

        CROW_LOG_INFO << "Received prompt: " << body["prompt"].s();

        auto resp = crow::json::wvalue();
        resp["status"] = "received";
        return crow::response(200, resp);
      });

    app.port(18080).multithreaded().run();

    return 0;
}