// src/MyController.h

#pragma once

#include <cpprest/json.h>
#include <cpprest/http_listener.h>

class MyController
{
public:
    void handle_get(web::http::http_request request);
    void handle_post(web::http::http_request request);
};
