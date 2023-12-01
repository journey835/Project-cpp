#include<iostream>
#include<string>
using namespace std;

const string USERNAME = "kasir";
const string PASSWORD = "1";

struct MENU{
    /* data */
    string namaMenu;
    double harga;
    int stock;
};

double diskon(double total, double diskon) {
    return total - (total * diskon / 100);
}

int main() {
    MENU menus[100];
    int menuCount = 0;
    bool selesai = false;
    double totalHarga = 0.0;

    cout<<"Selamat datang di cafe sederhana kami!"<<endl;
    while(true) {
        cout<<"Pilih menu yang anda ingin gunakan (1 / 2): "<<endl;
        cout<<"1. Input menu"<<endl;
        cout<<"2. Daftar menu"<<endl;
        cout<<"3. Pemesanan"<<endl;

        int menu;
        cin>>menu;

        if(menu == 1) {
            cout<<"Masukkan username : ";
            string username;
            cin>>username;

            cout<<"Masukkan password : ";
            string password;
            cin>>password;

            if(username == USERNAME && password == PASSWORD) {
                // input menu
                cout<<"Masukkan nama menu : ";
                string namaMenu;
                cin.ignore();
                getline(cin, namaMenu);

                cout<<"Masukkan harga : ";
                double harga;
                cin>>harga;

                cout<<"Masukkan stock : ";
                int stock;
                cin>>stock;

                menus[menuCount].namaMenu = namaMenu;
                menus[menuCount].harga = harga;
                menus[menuCount].stock = stock;
                menuCount++;
            } else {
                cout<<"Username atau password yang anda masukkan salah. Silahkan coba lagi."<<endl;
            }
        } else if (menu == 2) {
            for(int i = 0; i < menuCount; i++) {
                cout<<i + 1<<". "<<menus[i].namaMenu<<endl;
                cout<<"   harga : Rp"<<menus[i].harga<<endl;
                cout<<"   stock : "<<menus[i].stock<<endl;
            }
        } else if (menu == 3) {
            //pemesanan
            cout<<"DISKON"<<endl;
            cout<<"Dengan total pembelian minimal Rp50.000 anda akan mendapat DISC 5% dari total belanja anda"<<endl;
            cout<<"-----------------------------------------------------------------"<<endl;
            cout<<"Masukkan 0 jika selesai melakukan pemesanan "<<endl<<endl;
            while (selesai == false) {
                cout<<"Pilih menu : ";
                int nomorMenu;
                cin>>nomorMenu;

                if (nomorMenu < 0 || nomorMenu > menuCount) {
                    cout<<"Nomor menu yang anda masukkan salah. Silahkan memasukkan nomor menu sesuai yang ada di daftar menu"<<endl;
                    continue;
                }

                if (nomorMenu <= menuCount) {
                    if(nomorMenu == 0){
                        selesai = true;
                    } else {
                        // Pemesanan menu
                        cout << "Masukkan jumlah pesanan: ";
                        int jumlahPesanan;
                        cin >> jumlahPesanan;

                        if (jumlahPesanan <= menus[nomorMenu - 1].stock) {
                            // Cek ketersediaan stok

                            // Mengurangi stok sesuai dengan pesanan
                            menus[nomorMenu - 1].stock -= jumlahPesanan;

                            // Akumulasi totalharga
                            totalHarga += (menus[nomorMenu - 1].harga * jumlahPesanan);

                            cout << "Pesanan Anda untuk " << menus[nomorMenu - 1].namaMenu << " sebanyak " << jumlahPesanan << " telah dipesan." << endl;
                            cout << "Total harga sementara: Rp" << totalHarga << endl;
                        } else {
                            cout << "Maaf, stok menu tidak mencukupi untuk pesanan Anda." << endl;
                        }
                    }
                }
                if (menus[nomorMenu - 1].stock == 0) {
                    cout<<"Maaf, stok menu yang anda pilih sedang kosong. Silahkan coba lagi nanti atau pilih menu yang masih tersedia."<<endl;
                    continue;
                }
            }
            cout << endl;
            cout << "INVOICE PEMBELIAN MENU CAFE SEDERHANA" << endl;
            cout << "-------------------------------------" << endl;
            cout << "No. | Nama Menu       | Harga | Jumlah | Subtotal" << endl;
            cout << "-------------------------------------" << endl;

            double subtotalMenu;
            for (int i = 0; i < menuCount; ++i) {
                int jumlahPesan = (menus[i].stock < 0) ? 0 : menus[i].stock;
                subtotalMenu = menus[i].harga * jumlahPesan;

                cout << i + 1 << ".  | " << menus[i].namaMenu << "   | Rp" << menus[i].harga << " | " << jumlahPesan << "      | Rp" << subtotalMenu << endl;
            }

            cout << "-------------------------------------" << endl;
            if (totalHarga >= 50.000) {
                cout<<"Anda mendapat diskon sebesar "<<totalHarga * 5 / 100<<endl;
                totalHarga = diskon(totalHarga, 5);
                cout<<"Total harga yang harus dibayar : Rp"<<totalHarga<<endl;
            } else {
            cout << "Total harga: Rp" << totalHarga << endl;
            }
            cout << endl;
        }
    }
}