#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <iostream>

using namespace std;
class User {
   protected:
      static long stock;
      static string log;

   private:
      string username;
      int pin;
      int rekening;
      long saldo;
      static long saldo2; //Untuk rekening kedua

   public:
      
      User(const char* username, int pin, int rek, long saldo);

      // getter
      string getName();
      int getPin();

      // setter
      void chooseOpsi();
      void setOpsi(int opsi);
      void setRekening(int rek);
      void display();
      void transfer();
};
#endif 