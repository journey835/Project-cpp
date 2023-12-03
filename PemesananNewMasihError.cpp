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
    // int menuCount = 0;
    int menuCount = 1;
    menus[0].namaMenu = "Ayam";
    menus[0].harga = 10;
    menus[0].stock = 10;
    
    bool ulang = true;
    bool selesai = true;

    double totalHarga = 0.0;


    cout<<"Selamat datang di cafe sederhana kami!"<<endl;
    cout<<"=================================================="<<endl;

    // MAIN CODE
    while(ulang) {
        cout<<"Pilih menu yang anda ingin gunakan : "<<endl;
        cout<<"1. Input menu"<<endl;
        cout<<"2. Menu dan Pemesanan"<<endl;

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

                // Input menu
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

            //Pemesanan
            cout<<endl;
            cout<<"DISKON"<<endl;
            cout<<"pembelian minimal Rp50 mendapat DISC 5% dari total belanja"<<endl;
            cout<<"============================================================================================"<<endl;
            cout<<"No. | Nama Menu \t| Harga \t| Stock \t "<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;

            for(int i = 0; i < menuCount; i++) {
                cout<< i + 1 << ".  | " << menus[i].namaMenu<< " \t\t| Rp"<< menus[i].harga << " \t\t| "<< menus[i].stock<< endl;
            }

            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<endl;
            cout<<"MASUKKAN 0 JIKA SELESAI MELAKUKAN PEMESANAN"<<endl;
            cout<<"============================================================================================"<<endl<<endl;
            
        
            if (ulang == true) {
                selesai = true;
            }
            while (selesai ) {
                cout<<"Pilih menu : ";
                int nomorMenu;
                cin>>nomorMenu;

                if (nomorMenu < 0 || nomorMenu > menuCount) {
                    cout<<"Nomor menu yang anda masukkan salah. Silahkan memasukkan nomor menu sesuai yang ada di daftar menu"<<endl;
                    cout<<endl;
                    continue;
                }

                if (nomorMenu <= menuCount) {
                    if(nomorMenu == 0){
                        selesai = false;
                    } else {
                        // Pemesanan menu
                        cout << "Masukkan jumlah pesanan : ";
                        int jumlahPesanan;
                        cin >> jumlahPesanan;

                            // Cek ketersediaan stok
                        if (jumlahPesanan <= menus[nomorMenu - 1].stock) {
                            // Mengurangi stok sesuai dengan pesanan
                            menus[nomorMenu - 1].stock -= jumlahPesanan;
                            // Akumulasi totalharga
                            totalHarga += (menus[nomorMenu - 1].harga * jumlahPesanan);

                            cout << "Pesanan Anda untuk " << menus[nomorMenu - 1].namaMenu << " sebanyak " << jumlahPesanan << " telah dipesan." << endl;
                            cout << "Total harga sementara : Rp" << totalHarga << endl;
                            cout<<endl;
                        }
                        // } else {
                        //     cout<<"Maaf, stok menu tidak mencukupi untuk pesanan Anda."<<endl;
                        //     cout<<endl;
                        // }
                    }
                }
                if (menus[nomorMenu - 1].stock == 0) {
                    cout<<"Maaf, stok menu yang anda pilih sedang kosong. Silahkan coba lagi nanti atau pilih menu yang masih tersedia."<<endl;
                    continue;
                }
            }

            // Invoice Pembelian
            cout << endl;
            cout << "INVOICE PEMBELIAN MENU CAFE SEDERHANA" << endl;
            cout<<"------------------------------------------------------------------------"<<endl;
            cout << "No. | Nama Menu \t| Harga \t| Jumlah \t| Subtotal" << endl;
            cout<<"------------------------------------------------------------------------"<<endl;

            double subtotalMenu = 0.0;
            for (int j = 0; j < menuCount; ++j) {
                int jumlahPesan = (menus[j].stock < 0) ? 0 : menus[j].stock;
                subtotalMenu = menus[j].harga * jumlahPesan;

                cout << j + 1 << ".  | " << menus[j].namaMenu << " \t\t| Rp" << menus[j].harga << " \t\t| " << jumlahPesan << " \t\t| Rp" << subtotalMenu << endl;
            }
            cout<<"------------------------------------------------------------------------"<<endl;

            if (totalHarga >= 50) {
                cout<<"Anda mendapat diskon sebesar \t: Rp"<<totalHarga * 5 / 100<<endl;
                totalHarga = diskon(totalHarga, 5);
                cout<<"Total harga \t\t\t: Rp"<<totalHarga<<endl;
            } else {
            cout << "Total harga \t\t: Rp" << totalHarga << endl;
            }
        }

        // Cek program lanjut / End
        cout<<endl;
        cout<<"========================================================================"<<endl;
        cout<<"Apakah anda ingin menggunakan program lagi ? (y/n)"<<endl;
        string ulangi;
        cin>>ulangi;
        if(ulangi == "n") {
            ulang = false;
        }
    }
    system("cls");
    cout<<"Program Selesai"<<endl;
}