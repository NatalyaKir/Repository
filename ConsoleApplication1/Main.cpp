#include "Array.h"
#include <iostream>
#include <cstdio>
using namespace std;


void main()
{
	const int n = 10;
	int temp[n] = {6, 7, 8, 10, 1, 5, 90, 38, 66, 0};
	Array B(n, temp);
	const int m = 4;
	int tempa[m] = {1, 2, 3, 4};
	Array A(m, tempa);

	Array C = A & B;
	A.show();
	B.show();
	C.show();

	cout << A << endl;
	Array D;
	cin >> D;
	cout << D << endl;


	int nav=1;
	while (nav != 0)
	{
		cout << "Input number for action: 1 - show, 2 - search, 3 - add, 4 - delete, 5 - change, 6 - sort, 0 - exit" << endl;
		cin >> nav;
		if (nav == 1)
		{
			B.show();
		}
		if (nav == 2)
		{
			cout << "Input parameter for search: ";
			int param;
			cin >> param;
			int ind = B.search(param);
			if (ind!=-1)
				cout << "Find element "<< param << " with index "<< ind <<endl;
			else
				cout << "Non-existent element" <<endl;
		}
		if (nav == 3)
		{
			cout << "Input element for add: ";
			int elem;
			cin >> elem;
			B.add(elem);
		}
		if (nav == 4)
		{
			cout << "Input element for del: ";
			int elem;
			cin >> elem;
			B.del(elem);
		}
		if (nav == 5)
		{
			cout << "Input element for change: ";
			int elem;
			cin >> elem;
			cout << "Input index of change from 0 to "<<B.get_size()-1<<": ";
			int ind;
			cin >> ind;
			B.change(ind, elem);
		}
		if (nav == 6)
		{
			B.sort();
		}
	}
}

/*cout << "Input size of array: ";
int size;
cin >> size;
cout << "Input array: "<<endl;
int *tmp = new int [size];
int j = 0;
for (int i = 0; i < size; i++)
{
cin >> *(tmp+i);
}
Array A(size, tmp);*/
//int temp[3] = {6,7,8};
//Array B(3, temp);
//Array *B=new Array(3, temp);
//Array C();
//delete[] tmp;