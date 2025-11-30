#include "controller.hpp"

User user1 = User("Nala", 123456, 1, 6500000);
User user2 = User("Nopal", 131381, 1, 5000000);
User user3 = User("Santos", 374320, 1, 3200000);
User user4 = User("Arkana", 567241, 1, 1300000);
User user5 = User("Warsun", 682402, 1, 50000000);
Admin admin = Admin("admin6767");

void start(){
   cout << "========================================\n";
   cout << "||  Selamat datang di ATM Bianglala!  ||\n";
   login();
}

void login(){
   int opsi;
   cout << "========================================\n";
   cout << "Pilih Login sebagai:\n1. User/Nasabah\n2. Admin/Petugas ATM Center";
   cout << "\nMasukkan opsi(1/2): ";
   cin >> opsi;
   if(opsi == 1){
      string username;
      int pin;
      cout << "=======================================\n";
      cout << "Anda login sebagai user\n";
      cout << "Masukkan username: ";
      cin >> username;
      cout << "Masukkan pin(6 digit): ";
      cin >> pin;
      list(username, pin);
      
   }else if(opsi == 2){
      cout << "=======================================\n";
      cout << "Anda login sebagai admin\n";
      admin.adminInput();
   }else{
      cout << "Masukan anda tidak valid!\nSilahkan coba ulang.\n";
   }
}

void list(string username, int pin){
   if (user1.getPin() == pin && user1.getName() == username) {
      user1.chooseOpsi();
   }else if (user2.getPin() == pin && user2.getName() == username) {
      user2.chooseOpsi();
   }else if (user3.getPin() == pin && user3.getName() == username) {
      user3.chooseOpsi();
   }else if (user4.getPin() == pin && user4.getName() == username) {
      user4.chooseOpsi();
   }else if (user5.getPin() == pin && user5.getName() == username) {
      user5.chooseOpsi();
   }else {
      cout << "Username atau pin yang anda masukkan tidak ditemukan!\nSilahkan coba ulang" << endl;
      login();
   }
}