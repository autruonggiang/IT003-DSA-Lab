#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void print(int *list, int num) {
    for (int i = 0; i < num; ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
}

void create_random(int *&list, int num) {
    srand(time(NULL));
    
    list = new int[num];
    for (int i = 0; i < num; ++i) {
        list[i] = rand() % 201 - 100;
    }
}

void swap(int *list, int n1, int n2) {
    int temp = list[n1];
    list[n1] = list[n2];
    list[n2] = temp;
}

void merge(int *list, int start, int mid, int end) {
    
    int len_lArray = mid - start + 1,
        len_rArray = end - mid;
    
    int leftArray[len_lArray],
        rightArray[len_rArray];
        
    for (int i = 0; i < len_lArray; ++i)
        leftArray[i] = list[start + i];
    
    for (int i = 0; i < len_rArray; ++i)
        rightArray[i] = list[mid + 1 + i];
    
    int iMain = start,
        iLeft = 0,
        iRight = 0;
    
    while (iLeft < len_lArray && iRight < len_rArray) {
        if (leftArray[iLeft] <= rightArray[iRight]) {
            list[iMain] = leftArray[iLeft];
            iLeft++;
        } else {
            list[iMain] = rightArray[iRight];
            iRight++;
        }
        
        iMain++;
    }
    
    while (iLeft < len_lArray) {
        list[iMain] = leftArray[iLeft];
        iLeft++;
        iMain++;
    }
    
    while (iRight < len_rArray) {
        list[iMain] = rightArray[iRight];
        iRight++;
        iMain++;
    }
    
}

void merge_sort(int *list, int start, int end) {
    
    if (start >= end)
        return;
    
    int mid = start + (end - start) / 2;
    
    merge_sort(list, start, mid);
    merge_sort(list, mid + 1, end);
    
    merge(list, start, mid, end);
}

int main () {
    
    int num = 50;
    int *list;
    
    cout << "Mang ban dau\n";
    create_random(list, num);
    print(list, num);
    
    cout << "\nMang sau khi sap xep\n";
    merge_sort(list, 0, num - 1);
    print(list, num);
}
