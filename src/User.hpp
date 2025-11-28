#ifndef __USER
#define __USER

#include <string>
#include <iostream>

using namespace std;
class User {
   protected:
      static long stock;

   private:
      int rekening;
      long saldo;
      static long saldo2; //Untuk rekening kedua

   public:
      int pin;
      string username;
      static string log;
      User(const char* username, int pin, int rek, long saldo);

      // getter
      string getName(){
         return this->username;
      }

      // setter
      // void userInput();
      // void checkIf(string username, string password);
      void chooseOpsi();
      void setOpsi(int opsi);
      void addSaldo(long saldo);
      void setRekening(int rek);
      void display();
      void transfer();
};

class Admin : public User {
   private:
      string password;

   public:
      Admin(const char* password);
      void adminInput();
      void opsiAdmin();
      void setOpsiAdmin(int opsi);
};

void login();
void start();
void list(string username, int pin);
#endif 