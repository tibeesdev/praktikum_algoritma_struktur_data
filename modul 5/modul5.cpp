#include <iostream>
#include <string>

using namespace std;


void insertionSort(){
    string nama;
    cout << "Masukkan Nama: ";
    getline (cin, nama);

    int n = nama.length();

    for (int i = 1; i < n;i++){
        char key = nama[i];
        int j = i - 1;

        while (j >= 0 && nama[j] > key){
            nama[j+1] = nama[j];
            j = j - 1;
        }
        nama[j + 1] = key;
    }
    cout << "Hasil Insertion Sort Nama: " << nama << endl;
}



int main(){
    insertionSort();

}

