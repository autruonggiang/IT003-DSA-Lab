#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;

void Nhap(int[]);
void Xuat(int[]);
void SelectionSort(int[]);
void Swap(int&, int&);

using namespace std;

void Nhap(int a[])
{
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
		a[i] = rand() % (200 + 1) - 100;
}

void Xuat(int a[])
{
	for (int i = 0; i < MAX; i++)
		cout << setw(8) << a[i];
}

void SelectionSort(int a[])
{
	int i, j;
	int min;

	for (i = 0; i < MAX - 1; i++)
	{
		min = i;
		for (j = i + 1; j < MAX; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
			Swap(a[min], a[i]);
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
	Nhap(a);
	cout << "\nMang ban dau:" << endl;
	Xuat(a);

	SelectionSort(a);
	cout << "\nMang sau khi sap xep:" << endl;
	Xuat(a);
	return 0;
}
