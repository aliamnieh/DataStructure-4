// HEAP TREE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int* x;
int* y;
int Size;
int c;

//min heap

void swap(int& x, int& y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int parent(int i) {
    return floor((i - 1) / 2);
}

void add(int item) {
    if (c == Size)return;
    Size++;
    int i = Size - 1;
    x[i] = item;
    while (i!=0&&x[i]<x[parent(i)])
    {
        swap(x[i], x[parent(i)]);
        i = parent(i);
    }

}

void decreasekey(int i, int q) {
    x[i] = q;
    while (i!=0&&x[i]<x[parent(i)])
    {
        swap(x[i], x[parent(i)]);
        i = parent(i);
    }
}

void minHeapify(int i) {
    if (i < Size&&i>=0) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;
        if (l >= 0 && l < Size) {
            if (x[l] < x[s])s = l;
        }
        if (r >= 0 && r < Size) {
            if (x[r] < x[s])s = r;
        }
        if (s == i) {
            if (l >= 0 && l < Size)  minHeapify(l);
            if (r >= 0 && r < Size)minHeapify(r);
        }
        else {
            swap(x[i], x[s]);
            if(l>=0&&l<Size)minHeapify(l);
            if(r>=0&&r<Size)minHeapify(r);
        }
    }
    else return;
}

void deleteHeap(int i) {
    if (Size == 0)return;
    if (i < Size&&i>=0) {
        x[i] = x[Size - 1];
        Size--;
        minHeapify(i);
    }
    else return;
}

void heapSort(int a[],int n) {
    for (int i = 0; i < n; i++)
        add(a[i]);
    for (int i = 0; i < n; i++) {
        y[i] = x[0];
        deleteHeap(0);
    }
}

int main()
{
    x = new int[30];
    c = 30;
    Size = 0;
    //
    int a[] = { 20,18,25,12,23,24,1,123,14,54,43,47,9,18,29};
    y = new int[15];
    heapSort(a, 15);
    for (int i = 0; i < 15; i++)
        cout << y[i] << "   ";
    _getch();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
