#include "User.hpp"
#include "controller.hpp"

// User //
User::User(const char* u, int pin, int rek, long saldo)
   : username(u), pin(pin), rekening(rek), saldo(saldo) {}

long User::stock = 500000000;
long User::saldo2 = 0;  //Saldo awal untuk tiap rekening kedua adalah nol
string User::log = "";

string User::getName(){
   return this->username;
}

int User::getPin(){
   return this->pin;
}

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
         log += getName() + " Menambah saldo sebesar: Rp" + to_string(saldo) + "\n\n";
         break;
      case 3:
         cout << "===============================\n";
         cout << "Masukkan jumlah saldo anda: ";
         cin >> saldo;
         this->saldo += saldo;
         User::stock += saldo;
         log += getName() + " Menarik uang sebesar: Rp" + to_string(saldo) + "\n\n";
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
   log += getName() + " Melakukan transfer ke Bank " + bank + " dengan nomor rekening " + to_string(norek) + " sebesar " + to_string(nominal) + "\n\n";
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
      log += getName() + " Memindahkan saldo ke rekening " + to_string(pindah) + " sebesar " + to_string(nominal) + "\n\n";
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

