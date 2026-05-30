#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>

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

bool binarySearch (int arr[], int left, int N, int target){

    int right = N-1;
    
    while (left <= right)
    {
     int mid =  left + (right - left) / 2;

     if (arr[mid] == target)
     {
        return true;
     }
     else if (target < arr[mid])
     {
        right = mid - 1;
     }
     else{
        left = mid + 1;
     }
    }
    return false;
    
}

void selectionSort (int arr[], int n){
    for (int i = 0; i < n-1; i++){
        int minidx = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minidx])
            {
                minidx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = temp;
    }
}

int main()
{
    int N, X;
    int barisInput;
    int temp;

    cout<< "Masukkan N dan X: ";
    cin>> N >> X;

    vector<int> array(N);

    randomize();
    printf("generating %d number . . .\n", N);
    for (int i = 0; i < N; i++)
    {
        array[i] = random(25) + 1;
        printf("%d ", array[i]);
    }

    selectionSort(array.data(), N);

    cout <<endl;

    int totalPasangan = 0;

    for (int i = 0; i < N-1; i++){

        if (i > 0 && array[i] == array[i - 1]){
            continue;
        }
        int angka_pertama = array[i];
        int target = X- angka_pertama;

        if(binarySearch(array.data(), i + 1, N, target)){
            totalPasangan++;
        }

    }
    cout <<totalPasangan;

}
