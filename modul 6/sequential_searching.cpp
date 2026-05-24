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

int main()
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