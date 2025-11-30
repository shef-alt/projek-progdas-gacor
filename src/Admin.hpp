#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <string>
#include <iostream>
#include "User.hpp"

using namespace std;

class Admin : public User {
   private:
      string password;

   public:
      Admin(const char* password);

      void adminInput();
      void opsiAdmin();
      void setOpsiAdmin(int opsi);
};
#endif