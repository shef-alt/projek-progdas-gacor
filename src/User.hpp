#ifndef __PLAYER
#define __PLAYER

#include <string>

using namespace std;

class User {
   private:
      string username;
      string password;
      int rekening;
      long saldo;

   public:
      User(const char* username, const char* pw, int rek, long saldo);

      // getter
      string getName(){
         return this->username;
      }

      // setter
      void userInput();
      void checkIf(string username, string password);
      void chooseOpsi();
      void setOpsi(int opsi);
      void addSaldo(long saldo);
      void setRekening(int rek);
      void display();
      void exit();
};
#endif 