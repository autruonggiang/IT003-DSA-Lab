#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;

void Nhap(int[]);
void Xuat(int[]);
void InsertionSort(int[]);

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

void InsertionSort(int a[])
{
	int i, j;
	int x;
	for (i = 1; i < MAX; i++)
	{
		x = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = x;
	}
}

int main()
{
	int a[MAX];
	Nhap(a);
	cout << "\nMang ban dau:" << endl;
	Xuat(a);

	InsertionSort(a);
	cout << "\nMang sau khi sap xep:" << endl;
	Xuat(a);
	return 0;
}