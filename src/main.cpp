#include <iostream>

#include "crow.h"

int main() {
    std::cout << "=== LLM Inference Engine ===" << std::endl;
    std::cout << "Engine initialized successfully." << std::endl;

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        return "<h1>Hello World!</h1>";
    });

    app.port(18080).multithreaded().run();

    return 0;
}