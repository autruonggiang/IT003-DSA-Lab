#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;

void Nhap(int[]);
void Xuat(int[]);
void InterchangeSort(int[]);
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

void InterchangeSort(int a[])
{
	int i, j;

	for (i = 0; i < MAX - 1; i++)
	{
		for (j = i + 1; j < MAX; j++)
		{
			if (a[j] < a[i])
				Swap(a[i], a[j]);
		}
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
	Nhap(a);
	cout << "\nMang ban dau:" << endl;
	Xuat(a);

	InterchangeSort(a);
	cout << "\nMang sau khi sap xep:" << endl;
	Xuat(a);
	return 0;
}