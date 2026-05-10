#include <iostream>
#include <string>

using namespace std;

// insertion
void insertionSort(){
    string nama;
    cout << "Masukkan Nama: ";
    getline (cin, nama);

    if (!nama.empty()){
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

    } else {
        cout << "Nama Tidak Boleh Kosong!"<< endl;
    }
}

//merge
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

//shell
void shellSort(){
    string nama;
    cout << "Masukkan Nama: ";
    getline (cin, nama);

    if(!nama.empty()){
        int n = nama.length();

        for (int gap = n/2; gap >0 ; gap /= 2){
            for (int i = gap; i < n; i++){
                char temp = nama[i];
                int j;

                for (j = i; j >= gap && nama[j - gap] > temp; j -= gap){
                    nama[j] = nama[j - gap];
                }
                nama[j] = temp;
            }
        }

        cout << "Hasil Shell Sort Nama: " << nama << endl;
    } else {
        cout << "Nama Tidak Boleh Kosong!" << endl;
    }
}

// quicksort
void swap(char &a, char &b){
    char temp = a;
    a= b;
    b = temp;
}

int partition(string &nim, int low, int high){
    char pivot = nim [high];
    int i = (low - 1);

    for (int j = low; j < high; j++){
        if (nim[j] <= pivot){
            i++;
            swap(nim[i], nim[j]);
        }
    }
    swap(nim[i+1], nim[high]);
    return (i+1);
}

void quickSort(string &nim, int low, int high){
    if (low < high){
        int pi = partition(nim, low, high);

        quickSort(nim, low, pi-1);
        quickSort(nim, pi + 1, high);
    }
}

void quickSortCall(){
    string nim;
    cout << "Masukkan NIM: ";
    getline (cin, nim);

    if (!nim.empty()){
        quickSort(nim, 0, nim.length() - 1);
        cout << "Hasl Quick Sort NIM: "<< nim<< endl;
    } else {
        cout << "NIM Tidak Boleh Kosong!" <<endl;
    }
}

// bubble sort
void bubbleSort(){
    string nim;
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    if (!nim.empty()){
        int n = nim.length();

        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1 ;j++){
                if (nim[j] > nim [j+1]){
                    char temp = nim[j];
                    nim[j] = nim[j+1];
                    nim[j+1] = temp;
                }
            }
        }
        cout << "Hasil Bubble Sort NIM: " << nim <<endl;
    }else {
        cout << "NIM Tidak Boleh Kosong!" << endl;
    }
}

int main(){
    //insertionSort();
    //mergeCall();
    //shellSort();
    //quickSortCall();
    bubbleSort();

}

