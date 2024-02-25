#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;

void Nhap(int[], int&);
void Xuat(int[], int);
int Partition(int[], int, int);
void QuickSort(int[], int, int);
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

int Partition(int a[], int low, int high)
{
	int pivot = a[high];    
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && a[left] < pivot) left++;
		while (right >= left && a[right] > pivot) right--;
		if (left >= right) break;
		Swap(a[left], a[right]);
		left++;
		right--;
	}
	Swap(a[left], a[high]);
	return left;
}

void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(a, low, high);

		QuickSort(a, low, pi - 1);
		QuickSort(a, pi + 1, high);
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

	QuickSort(a, 0, n - 1);
	cout << "\nMang sau khi sap xep:" << endl;
	Xuat(a, n);
	return 0;
}