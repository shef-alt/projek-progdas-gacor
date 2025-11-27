#include <iostream>
#include <string>
#include "User.hpp"

User::User(const char* u, const char* pw, int rek, long saldo)
   : username(u), password(pw), rekening(rek), saldo(saldo) {}

void User::userInput(){
   string username;
   string password;
   cout << "Masukkan username: ";
   cin >> username;
   cout << "Masukkan password: ";
   cin >> password;
   checkIf(username, password);
   chooseOpsi();
}

void User::checkIf(string username, string password){
   if(this->username == username && this->password == password){
      cout << "================================\n";
      cout << "Selamat datang " << this->username << "!" << endl;
   } else {
      cout << "Username or password is invalid!\n" << "Try Again" << endl;
      userInput();
   }
}

void User::chooseOpsi(){
   int opsi;
   cout << "==============================\n";
   cout << "Pilih opsi berikut: \n1. Tambah Saldo\n2. Transfer\n3. Pindah rekening\n4. Exit\nMasukkan opsi: ";
   cin >> opsi;
   setOpsi(opsi);
   if(opsi !=4 )
   display();
}

void User::setOpsi(int opsi){
   long saldo;
   int rek;
   switch (opsi){
      case 1:
         cout << "===============================\n";
         cout << "Masukkan jumlah saldo anda: ";
         cin >> saldo;
         addSaldo(saldo);
         break;
      case 2:
         break;
      case 3:
         cout << "==================================\n";
         cout << "Silahkan ilih rekening anda(1, 2): ";
         cin >> rek;
         setRekening(rek);
         break;
      case 4:
         cout << "Terimakasih sudah menggunakan layanan kami🙏";
         exit();
         break;
      default:
         cout << "Input salah!";
         chooseOpsi();
         break;
   }
}

void User::addSaldo(long saldo){
   this->saldo += saldo;
}

void User::setRekening(int rek){
   switch (rek){
      case 1:
         this->saldo;
         break;
      case 2:
         this->rekening = rek;
         this->saldo = 125000;
         break;
      default:
         cout << "Rekening tidak ditemukan!" << endl;
         break;
   }
}

void User::display(){
   cout << "Username\t: " << this->username << endl;
   cout << "Password\t: " << this->password << endl;
   cout << "Rekening\t: " << this->rekening << endl;
   cout << "Saldo\t\t: " << "Rp" << this->saldo << endl;
   chooseOpsi();
}

void User::exit(){}












