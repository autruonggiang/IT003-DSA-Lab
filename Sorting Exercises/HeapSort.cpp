#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;

void Nhap(int[], int&);
void Xuat(int[], int);
void Heapify(int, int, int);
void HeapSort(int[], int);
void Swap(int&, int&);

using namespace std;

void Nhap(int a[], int &n)
{
	cout << "Nhap so luong phan tu n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % (200 + 1) - 100;
}

void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(8) << a[i];
}

void Heapify(int a[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && a[l] > a[largest])
		largest = l;

	if (r < n && a[r] > a[largest])
		largest = r;

	if (largest != i)
	{
		Swap(a[i], a[largest]);

		Heapify(a, n, largest);
	}
}

void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		Swap(a[0], a[i]);
		Heapify(a, i, 0);
	}
}


void Swap(int& xx, int& yy)
{
	int temp = xx;
	xx = yy;
	yy = temp;
}

int main()
{
	int a[MAX];
	int n;
	Nhap(a, n);
	cout << "\nMang ban dau:" << endl;
	Xuat(a, n);

	HeapSort(a, n);
	cout << "\nMang sau khi sap xep:" << endl;
	Xuat(a, n);
	return 0;
}
