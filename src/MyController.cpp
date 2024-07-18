// src/MyController.cpp

#include "MyController.h"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void MyController::handle_get(http_request request)
{
    json::value response;
    response[U("message")] = json::value::string(U("Hello, GET request received!"));
    request.reply(status_codes::OK, response);
}

void MyController::handle_post(http_request request)
{
    request.extract_json().then([=](json::value body)
                                {
        json::value response;
        response[U("message")] = json::value::string(U("Hello, POST request received!"));
        response[U("data")] = body;
        request.reply(status_codes::OK, response); })
        .wait();
}
