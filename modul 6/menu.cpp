#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil)
{
    int jumlah = rand()%bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

int sequentialSearching()
{
    clrscr();
    int data [100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++)
    {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++)
    {
        if (data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1)
    {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d", save);
    }
    else
    {
        printf("Data tidak ada!\n");
    }
}


int binarySearching()
{
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukkan jumlah data? ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    cout << "=======================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n=======================================================\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n -1;
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if(key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        } 
    }
    if (ketemu == true)
    {
        cout << "Angka ditemukan! ";
    }
    else
        cout << "Angka tidak ditemukan!";
    return 0;
}

int main(){
    int pilih;
    printf("Pilih menu\n");
    printf("1. Sequential Searching\n");
    printf("2. Binary Searching\n");
    printf("3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n");
    printf("4. Exit\n");
    printf("Pilih : ");
    cin >> pilih;

    if(pilih == 1){
        sequentialSearching();
    } else if (pilih == 2){
        binarySearching();
    } else if (pilih== 3){
        printf("jelaskan");
    } else if (pilih== 4){
        printf("Program Dihentikan\n");
    }
    else{
        printf ("Input menu tidak valid!\n\n");
    }
    return 1;
}