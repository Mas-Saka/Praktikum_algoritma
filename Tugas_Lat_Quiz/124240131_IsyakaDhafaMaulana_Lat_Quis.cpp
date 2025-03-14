#include <iostream>
#include <fstream> // Library untuk membaca dan menulis file
#include <cstring> // Library untuk fungsi string
using namespace std;

struct lagu {
    char jdl_lagu[50], penyanyi[50], genre[40];
    int tahun;
};

const int lagu_maks = 10;
lagu daftar_lagu[lagu_maks]; 
int banyak_lagu = 0;

void simpan_ke_file(){
    FILE *fptr = fopen("lagu.dat", "wb"); 
    if(fptr == NULL){
        cout << "Error membuka file\n";
        return;
    }
    fwrite(daftar_lagu, sizeof(lagu), banyak_lagu, fptr); 
    fclose(fptr);
}

void baca_dari_file() {
    FILE *fptr = fopen("lagu.dat", "rb");
    if (fptr == NULL) {
        return; // Jika file tidak ditemukan, tidak melakukan apa-apa
    }
    banyak_lagu = fread(daftar_lagu, sizeof(lagu), lagu_maks, fptr);
    fclose(fptr);
}




void tambah_lagu () {
    string kembali ;
    int jumlah;
    do{
    if (banyak_lagu >= lagu_maks) {
        cout << "Daftar Lagu Sudah Maksimal\n";
        return;
    }
    cout << "Masukkan Jumlah Lagu yang anda inginkan (max=10): "; 
    cin >> jumlah;
    cin.ignore();

    if(banyak_lagu + jumlah > lagu_maks) {
        cout << "Inputan Lagu Melebihi Batas Maksimal\n";
        return;
    }

    for (int i=0; i<jumlah; i++){
        cout << "==================================\n";
        cout << "Masukkan Judul Lagu \t: ";
        cin.getline(daftar_lagu[banyak_lagu].jdl_lagu, 50);
        cout << "Masukkan Penyanyi \t: ";
        cin.getline(daftar_lagu[banyak_lagu].penyanyi, 50);
        cout << "Masukkan Genre Lagu\t: ";
        cin.getline(daftar_lagu[banyak_lagu].genre, 40);
        cout << "Masukkan Tahun Lagu \t: ";
        cin >> daftar_lagu[banyak_lagu].tahun;
        cout << "==================================\n";
        cin.ignore();
        banyak_lagu++;
    }

    simpan_ke_file();
    cout << "File Lagu Berhasil Ditambahkan\n";
    cout << "Lagu Berhasil Ditambahkan\n";
    cout << "Ingin Kembali Ke Menu Utama? (iya/tidak) :"; cin >> kembali;
    }while (kembali != "iya");
}

    void urutkan_lagu(){
        for(int i=0;i<banyak_lagu-1; i++){
            for(int j=0; j<banyak_lagu-i-1; j++){
                if(daftar_lagu[j].jdl_lagu > daftar_lagu[j+1].jdl_lagu){
                    swap(daftar_lagu[j], daftar_lagu[j+1]);
                }
            }
        }
    }

    void tampilkanlagu(){
        string kembali;
        if(banyak_lagu==0){
            cout <<"\nBelum ada lagu yang anda tambahkan\n";
            return;
        }
        
        urutkan_lagu();
        cout << "\nDaftar Playlist Lagu :\n";
        for (int i=0; i<banyak_lagu; i++){
             cout << i+1 <<"." << "Judul Lagu : " << daftar_lagu[i].jdl_lagu << " | "
             << "Nama Penyanyi : " << daftar_lagu[i].penyanyi << " | "
            << "Genre : " << daftar_lagu[i].genre << " | "
            << "Tahun Rilis : " << daftar_lagu[i].tahun << endl;
        }
    
    }

    void cari_lagu(){
        string kembali ;
        char cari[50];
        
        if(banyak_lagu==0){
            cout << "Belum Ada Lagu yang Ditambahkan\n";
            return;
        }
        do{
        cout << "Masukkan Judul yang dicari (beri spasi diawal agar judul dapat dibaca program) :";
        cin.ignore(); // untuk membersihkan buffer dari cin sebelumnya
        cin.getline(cari, 50);

        bool ditemukan = false;
        for(int i=0; i<banyak_lagu; i++){
            if(strcmp(daftar_lagu[i].jdl_lagu, cari)==0){
                cout << "==================================\n";
                cout << "Daftar Lagu Ditemukan:\n";
                cout << "Judul Lagu :" << daftar_lagu[i].jdl_lagu << endl;
                cout << "Nama Penyanyi :" << daftar_lagu[i].penyanyi << endl;
                cout << "Genre : "<< daftar_lagu[i].genre << endl;
                cout << "Tahun Rilis :" << daftar_lagu[i].tahun << endl;
                cout << "==================================\n";
                ditemukan = true;
                break;
            }
        }
        if (ditemukan == false){
            cout << "Lagu yang anda cari tidak ditemukan\n";
        }
    }while(kembali == "iya");
    }

    void editlagu(){
        if(banyak_lagu==0){
            cout << "Belum Ada Lagu yang Ditambahkan\n";
            return;
        }
        char cari[50];
        cout << "Masukkan Judul Lagu yang ingin diedit (beri spasi diawal agar judul dapat dibaca program) :";
        cin.ignore();
        cin.getline(cari, 50);

        bool ditemukan(false);
        for(int i=0; i<banyak_lagu; i++) {
            if(strcmp(daftar_lagu[i].jdl_lagu, cari)==0){
            cout << "==================================\n";
            cout << "Masukkan Judul Lagu :";
            cin.getline(daftar_lagu[i].jdl_lagu,50);
            cout << "Masukkan Penyanyi :";
            cin.getline(daftar_lagu[i].penyanyi,50);
            cout << "Masukkan Genre :" ;
            cin.getline(daftar_lagu[i].genre,40);
            cout << "Masukkan Tahun Rilis :";
            cin>> daftar_lagu[i].tahun;
            cin.ignore();

            simpan_ke_file();
            cout << "Lagu Berhasil Diperbarui!!\n";
            return;
        }
    
    }
}

int main () {
    baca_dari_file();
    int pilih_menu;
    do {
    cout << "==================================";
    cout << "\nPlaylist Lagu :\n";
    if(banyak_lagu>0) {
        for (int i=0; i<banyak_lagu; i++){
            cout << i+1 << ".) " << daftar_lagu[i].jdl_lagu << "  " << endl;
        }   
    }
    cout << "==================================\n";
    cout << "1. Tambah Lagu\n";
    cout << "2. Edit Lagu\n";
    cout << "3. Tampilkan Lagu\n";
    cout << "4. Cari Lagu\n";
    cout << "5. Keluar\n";
    cout << "Pilih Menu : "; cin >> pilih_menu;
    cin.ignore();

    switch (pilih_menu){
        case 1:
            tambah_lagu();
            break;
        case 2:
            editlagu();
            break;
        case 3:
            tampilkanlagu();
            break;
        case 4:
            cari_lagu();
            break;
        case 5:
            cout << "Terima Kasih Telah Menggunakan Layanan Kami\n";
            break;
        default:
            cout << "Nomor yang Diinputkan Salah\n";
            break;
    } 
}while(pilih_menu != 5);
    
}