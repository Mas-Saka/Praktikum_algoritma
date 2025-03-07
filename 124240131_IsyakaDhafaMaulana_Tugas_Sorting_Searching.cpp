#include <iostream>
using namespace std;
    
    struct judul{
        string judul_lagu, penyanyi, genre;
        int tahun;
    };
    
    const int lagu_maks=10;
    judul daftarlagu[lagu_maks];
    int banyak_lagu =0;

    
    void tambahlagu(){
        string kembali;
        int jumlah;
        do{
        if (banyak_lagu >= lagu_maks){
            cout << "Daftar lagu sudah Maksimal\n";
            return;
        }

        cout << "Berapa Lagu yang akan dimasukkan ? (MAX =10):"; 
        cin >> jumlah;
        cin.ignore();

        if (banyak_lagu+jumlah > lagu_maks) {
            cout << "Inputan Lagu Melebihi Batas MAX\n";
            return;
        }
        for (int i=0;i<jumlah;i++) {
        cout << "Isikan Judul Lagu :";
        getline(cin,daftarlagu[banyak_lagu].judul_lagu);
        cout << "Isikan Penyanyi :";
        getline(cin,daftarlagu[banyak_lagu].penyanyi);
        cout << "Isikan Genre :";
        getline(cin,daftarlagu[banyak_lagu].genre);
        cout << "Isikan Tahun Perilisan :";
        cin >> daftarlagu[banyak_lagu].tahun;
        cin.ignore();
        banyak_lagu ++;
    }

        cout << "\nHoree!! Lagu Berhasil Ditambahkan\n";

        cout << "\nIngin Kembali Ke Menu Utama? (iya/tidak) :"; cin >> kembali;
        
    }while (kembali != "iya");
}

    // Pakai Bubble Sort
    void urutinlagu() {
        for(int i=0;i<banyak_lagu-1; i++){
            for(int j = 0; j < banyak_lagu - i - 1; j++){
                if (daftarlagu[j].judul_lagu > daftarlagu [j + 1].judul_lagu)
                {
                 swap(daftarlagu[j], daftarlagu[j+1]);
                }
            }
        }
    }

    void tampillagu(){
        if (banyak_lagu==0) {
            cout << "Belum ada daftar lagu yang ditambahkan\n";
            return;
        }
        urutinlagu();
        cout << "Daftar Playlist Lagu :\n";
        for (int i=0; i<banyak_lagu;i++){
            cout<< i+1 << "." <<" Judul Lagu : " << (*(daftarlagu+i)).judul_lagu<< " | "
            <<"Nama Penyanyi : "<< daftarlagu[i].penyanyi<< " | "
            <<"Genre : "<< daftarlagu[i].genre<< " | "
            <<"Tahun Rilis :" << daftarlagu[i].tahun << endl;
        }
    }

    // Pakai Sequential Search
    void pencarilagu(){
        string kembali;
        do {
        if(banyak_lagu==0){
            cout << "Belum Ada Lagu yang Ditambahkan\n";
            return;
        }

        string pencari;
        cout << "Masukkan Judul yang ingin anda cari :";
        cin.ignore();
        getline(cin, pencari);
    

    bool ditemui = false;
    for (int i = 0; i < banyak_lagu; i++) {
        if(daftarlagu[i].judul_lagu == pencari){
            cout << "==================================\n";
            cout << "Daftar Lagu Ditemukan:\n ";
            cout << "Judul Lagu : "<< daftarlagu[i].judul_lagu << endl;
            cout << "Nama Penyanyi : "<< daftarlagu[i].penyanyi << endl;
            cout << "Genre : "<< daftarlagu[i].genre << endl;
            cout << "Tahun Rilis : "<< daftarlagu[i].tahun << endl;
            cout << "==================================\n";
            ditemui = true;
            break;
        }
    }
    if (!ditemui){
        cout << "Lagu yang anda cari tidak ditemukan.\n";
    } cout << "\nIngin Kembali Ke Menu Utama? (iya/tidak) :"; cin >> kembali;
}while(kembali != "iya");
    }

int main (){
    system ("cls");
    int pilih;
    string kembali;
    do {
    cout << "\n==================================";
    cout << "\n## Menu Utama Playlist Musik ##";
    cout << "\n==================================\n";
    cout << "List Lagu yang Telah Ditambahkan :\n";
    if(banyak_lagu>0) {
        for (int i=0 ;i<banyak_lagu;i ++) {
                        cout << i+1 << ". " << daftarlagu[i].judul_lagu << " - " << daftarlagu[i].penyanyi << endl;
        }
    }
    cout << "==================================\n";
    cout << "1.) tambah Lagu";
    cout << "\n2.) Cari Lagu";
    cout << "\n3.) Keluar\n"; 
    cout << "Pilih Menu : " ; cin >> pilih;

    switch (pilih)
    {
    case 1 :
        tambahlagu();
        break;
    case 2 :
        pencarilagu();
        break;
    case 3 :
        cout << "\nTerimakasih Telah Menggunakan Layanan Kami\n";
        break;
    default:
        cout << "\nNomor yang Diinputkan Salah";
        break;
    }

    }while (pilih!=3);    
}