#include <iostream>
#include <string>
using namespace std;

int main() {
    char huruf;
    string kata;
    int angka;

    cout << "a. Masukkan sebuah huruf = ";
    cin >> huruf;
    cout << "b. Masukkan sebuah kata = ";
    cin >> kata;
    cout << "c. Masukkan sebuah angka = ";
    cin >> angka;

    cout << "\nd. Huruf yang anda masukkan adalah = " << huruf<<endl;
    cout << "e. Kata yang anda masukkan adalah = " << kata<<endl;
    cout << "f. Angka yang anda masukkan adalah = " << angka<<endl;

    return 0;
}