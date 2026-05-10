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

void merge(string &nama, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L = nama.substr (left, n1);
    string R = nama.substr (mid + 1, n2);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            nama[k] = L[i];
            i++;
        } else{
            nama[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nama[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        nama[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(string &nama, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(nama, left, mid);
        mergeSort(nama, mid + 1, right);
        merge(nama, left, mid, right);
    }
}

void mergeCall(){
    string nama;
    cout << "Masukkan Nama: ";
    getline(cin, nama);

    if(!nama.empty()){
        mergeSort(nama, 0, nama.length() - 1);
        cout << "Hasil Merge Sort Nama: "<< nama << endl;
    }else {
        cout << "Nama Tidak Boleh Kosong!"<< endl;
    }
}


int main(){
    //insertionSort();
    mergeCall();

}

