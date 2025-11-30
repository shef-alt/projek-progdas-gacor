#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <string>
#include <iostream>
#include "User.hpp"
#include "Admin.hpp"

using namespace std;

extern User user1;
extern User user2;
extern User user3;
extern User user4;
extern User user5;
extern Admin admin;

void start();
void login();
void list(string username, int pin);

#endif