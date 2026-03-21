#include <iostream>
#include <string>
using namespace std;

struct Kendaraan{
    string plat, jenis_kendaraan, nama_pemilik, alamat, kota;
};

int main(){
    Kendaraan kdn;
    kdn.plat = "DA123MK";
    kdn.jenis_kendaraan = "RUSH";
    kdn.nama_pemilik = "Andika Hartanto";
    kdn.alamat = "Jl. Kayu Tangi 1";
    kdn.kota = "Banjarmasin";

    cout<< "a. Plat Nomor Kendaraan : "<<kdn.plat<<endl;
    cout<< "b. Jenis Kendaraan      : "<<kdn.jenis_kendaraan<<endl;
    cout<< "c. Nama Pemilik         : "<<kdn.nama_pemilik<<endl;
    cout<< "d. Alamat               : "<<kdn.alamat<<endl;
    cout<< "e. Kota                 : "<<kdn.kota<<endl;

    return 0;
}