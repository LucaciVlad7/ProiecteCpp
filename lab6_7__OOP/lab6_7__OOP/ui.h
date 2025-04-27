#pragma once
#include "service.h"


class ui {
private:
    service serv;
    repository& repo;
public:
    ui(service servx, repository& repox) : serv{ servx }, repo{ repox } {}
    void runApp();
};