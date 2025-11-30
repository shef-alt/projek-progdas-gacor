#include "Admin.hpp"
#include "controller.hpp"

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










