#include <iostream>
#include <string>
#include "User.hpp"

// User //
User::User(const char* u, int pin, int rek, long saldo)
   : username(u), pin(pin), rekening(rek), saldo(saldo) 
   {
      
   }
long User::stock = 500000000;
long User::saldo2 = 0;  //Saldo awal untuk tiap rekening kedua adalah nol
string User::log = "";

User user1 = User("Nala", 123456, 1, 999999999);
User user2 = User("Nopal", 123456, 1, 5000000);
User user3 = User("Santos", 123456, 1, 5000000);
User user4 = User("Arkana", 123456, 1, 5000000);
User user5 = User("Warsun", 123456, 1, 5000000);
Admin admin = Admin("admin6767");

void User::chooseOpsi(){
   int opsi;
   cout << "==============================\n";
   cout << "Pilih opsi berikut: \n1. Cek saldo dan akun\n2. Tarik tunai\n3. Setor/tambah saldo\n4. Transfer\n5. Pindah rekening dan saldo\n6. Keluar\nMasukkan opsi: ";
   cin >> opsi;
   setOpsi(opsi);
   if(opsi !=6 )
   display();
}

void User::setOpsi(int opsi){
   long saldo;
   int rek;
   switch (opsi){
      case 1:
         cout << "========================\n";
         cout << "Info saldo dan akun anda: \n";
         break;
      case 2:
         cout << "Masukkan nominal untuk tarik tunai: ";
         cin >> saldo;
         this->saldo -= saldo;
         User::stock -= saldo;
         log += this->username + " Menambah saldo sebesar: Rp" + to_string(saldo) + "\n\n";
         break;
      case 3:
         cout << "===============================\n";
         cout << "Masukkan jumlah saldo anda: ";
         cin >> saldo;
         this->saldo += saldo;
         User::stock += saldo;
         log += this->username + " Menarik uang sebesar: Rp" + to_string(saldo) + "\n\n";
         break;
      case 4:
         cout << "===============================\n";
         transfer();
         break;
      case 5:
         cout << "==================================\n";
         cout << "Silahkan pilih rekening anda(1/2): ";
         cin >> rek;
         setRekening(rek);
         break;
      case 6:
         cout << "Terimakasih sudah menggunakan layanan kami🙏\n";
         login();
         break;
      default:
         cout << "Input salah!";
         chooseOpsi();
         break;
   }
}

void User::transfer(){
   int opsi;
   int norek;
   long nominal;
   int admin = 5000;
   cout << "Pilih bank anda:\n1. Bank Bianglala\n2. Bank Santosa\n3. Bank Arkana\nMasukkan opsi: ";
   cin >> opsi;
   cout << "Masukkan nomor rekening penerima: "; //bebas jika bukan bank gacor
   cin >> norek;
   cout << "Masukkan nominal transfer: ";
   cin >> nominal;
   if(opsi == 1){
      switch(norek){
      case 123456:
         user1.saldo += nominal;
         break;
      case 131381:
         user2.saldo += nominal;
         break;
      case 374320:
         user3.saldo += nominal;
         break;
      case 567241:
         user4.saldo += nominal;
         break;
      case 682402:
         user5.saldo += nominal;
         break;
      default:
         cout << "Nomor rekening tidak ditemukan!";
         chooseOpsi();
         break;
      } this->saldo -= nominal;
   } else if(opsi == 2 || opsi == 3){
      this->saldo -= nominal + admin;
      User::stock -= nominal;
   }
   string bank;
   if(opsi == 1){
      bank = "Bianglala";
   }else if(opsi == 2){
      bank = "Santosa";
   }else if(opsi == 3){
      bank = "arkana";
   }
   log += this->username + " Melakukan transfer ke Bank " + bank + " dengan nomor rekening " + to_string(norek) + " sebesar " + to_string(nominal) + "\n\n";
}

void User::setRekening(int rek){
   switch(rek){
      case 1:
         this->rekening = rek;
         this->saldo;
         break;
      case 2:
         this->rekening = rek;
         User::saldo2;
         break;
      default:
         cout << "Rekening tidak ditemukan!" << endl;
         break;
   }
   char opsi;
   int pindah;
   cout << "Pindah uang ke rekening lain? (Y/N): ";
   cin >> opsi;
   if('Y' == opsi){
      long nominal;
      cout << "Masukkan rekening tujuan (1/2): ";
      cin >> pindah;
      cout << "Masukkan nominal: ";
      cin >> nominal;
      if(1 == pindah) {
         this->saldo += nominal;
         User::saldo2 -= nominal;
      }else if(2 == pindah){
         this->saldo -=nominal;
         User::saldo2 += nominal;
      }
      log += this->username + " Memindahkan saldo ke rekening " + to_string(pindah) + " sebesar " + to_string(nominal) + "\n\n";
   }
}

void User::display(){
   cout << "Username\t: " << this->username << endl;
   cout << "Password\t: " << this->pin << endl;
   cout << "Rekening\t: " << this->rekening << endl;
   if(this->rekening == 1) {
      cout << "Saldo\t\t: " << "Rp" << this->saldo << endl;
   } else if(this->rekening == 2) {
      cout << "Saldo\t\t: " << "Rp" << User::saldo2 << endl;
   }
   chooseOpsi();
}

// void User::log(int opsi, int info){
//    switch(opsi){
//       case 1:
//          msg += this->username + " Mengecek saldo dan akun"; break;
//       case 2:
//          msg += this->username + " Menambah saldo sebesar: Rp" + to_string(info);; break;
//       case 3:
//          msg += this->username + " Menarik uang sebesar: Rp" + to_string(info);; break;
//       case 4:
//          msg += this->username + " Melakukan transfer ke Bank " + to_string(info); + " dengan nomor rekening " + to_string(info); + " sebesar " + to_string(info);; break;
//       case 5:
//       break;
//    }
//    cout << endl;
// }

// Admin //
Admin::Admin(const char* password)
         : User("", 0, 0, 0) 
         {
            this->password = password;
         };;

void Admin::adminInput(){
   string password;
   cout << "Masukkan password: ";
   cin >> password;
   if(this->password == password){
      opsiAdmin();
   }else{
      cout << "Password ditolak!\nSilahkan coba lagi";
      login();
   }
}

void Admin::opsiAdmin(){
   int opsi;
   cout << "==============================\n";
   cout << "Pilih opsi berikut: \n1. Lihat stock uang\n2. Restock uang\n3. Ambil stock uang\n4. Lihat log transaksi\n5. Exit\nMasukkan opsi: ";
   cin >> opsi;
   setOpsiAdmin(opsi);
   opsiAdmin();
}

void Admin::setOpsiAdmin(int opsi){
   long stock;
   int rek;
   switch (opsi){
      case 1:
         cout << "===============================\n";
         cout << "Stock uang di ATM: " << this->stock << endl;
         break;
      case 2:
         cout << "Masukkan stock uang: ";
         cin >> stock;
         this->stock += stock;
         break;
      case 3:
         cout << "Ambil stock uang: ";
         cin >> stock;
         this->stock -= stock;
         break;
      case 4:
         cout << "===============================\n";
         cout << "Log Transaksi: \n" << log;
         break;
      case 5: 
         login();
         break;
      default:
         cout << "Input salah!";
         opsiAdmin();
         break;
   }
}

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
   if (user1.pin == pin && user1.username == username) {
      user1.chooseOpsi();
   }else if (user2.pin == pin && user2.username == username) {
      user2.chooseOpsi();
   }else if (user3.pin == pin && user3.username == username) {
      user3.chooseOpsi();
   }else if (user4.pin == pin && user4.username == username) {
      user4.chooseOpsi();
   }else if (user5.pin == pin && user5.username == username) {
      user5.chooseOpsi();
   }else {
      cout << "Username atau pin yang anda masukkan tidak ditemukan!\nSilahkan coba ulang" << endl;
      login();
   }
}











