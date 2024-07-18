#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <spdlog/spdlog.h> // Include spdlog header
#include "MyController.h"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

int main()
{
    // Initialize spdlog logger
    // auto console_logger = spdlog::stdout_logger_mt("console");
    // console_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");

    uri_builder uri(U("http://localhost:9090"));
    auto addr = uri.to_uri().to_string();
    http_listener listener(addr);

    MyController controller; // Instantiate your controller or handler

    // Set up listener to handle GET and POST methods
    listener.support(methods::GET, std::bind(&MyController::handle_get, &controller, std::placeholders::_1));
    listener.support(methods::POST, std::bind(&MyController::handle_post, &controller, std::placeholders::_1));

    try
    {
        listener.open().then([&listener]()
                             { spdlog::info("Listening on {}", listener.uri().to_string()); })
            .wait();

        // Wait for user input to stop the listener
        std::string line;
        std::getline(std::cin, line);

        listener.close().wait();
    }
    catch (const std::exception &e)
    {
        spdlog::error("Error: {}", e.what());
    }

    return 0;
}
