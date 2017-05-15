#include "Array.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;


void main()
{

	int main = 1;
	while (main !=0)
	{
		cout << "Input number of laboratory work (0 - exit):" << endl;
		cin >> main;
		if (main == 1)
		{
			const int n = 10;
			int temp[n] = { 6, 7, 8, 10, 1, 5, 90, 38, 66, 0 };
			Array B(n, temp);
			int nav = 1;
			while (nav != 0)
			{
				cout << "Input number for action:" << endl;
				cout << "1 - show" << endl;
				cout << "2 - show array size" << endl;
				cout << "3 - search" << endl;
				cout << "4 - add" << endl;
				cout << "5 - delete" << endl;
				cout << "6 - change" << endl;
				cout << "7 - get value from index" << endl;
				cout << "8 - sort" << endl;
				cout << "0 - exit" << endl;
				cin >> nav;
				if (nav == 1)
				{
					B.show();
				}
				if (nav == 2)
				{
					cout << B.get_size() << endl;
				}
				if (nav == 3)
				{
					cout << "Input parameter for search: ";
					int param;
					cin >> param;
					int ind = B.search(param);
					if (ind != -1)
						cout << "Find element " << param << " with index " << ind << endl;
					else
						cout << "Non-existent element" << endl;
				}
				if (nav == 4)
				{
					cout << "Input element for add: ";
					int elem;
					cin >> elem;
					B.add(elem);
				}
				if (nav == 5)
				{
					cout << "Input element for del: ";
					int elem;
					cin >> elem;
					B.del(elem);
				}
				if (nav == 6)
				{
					cout << "Input element for change: ";
					int elem;
					cin >> elem;
					cout << "Input index of change from 0 to " << B.get_size() - 1 << ": ";
					int ind;
					cin >> ind;
					B.change(ind, elem);
				}
				if (nav == 7)
				{
					cout << "Input index from 0 to " << B.get_size() - 1 << ": ";
					int ind;
					cin >> ind;
					int elem = B.get_elem(ind);
					cout << "Element with index " << ind << " = " << elem << endl;
				}
				if (nav == 8)
				{
					B.sort();
				}
			}
		}
		if (main == 2)
		{
			const int n = 10;
			int temp[n] = { 6, 7, 8, 10, 1, 5, 90, 38, 66, 0 };
			Array B(n, temp);
			const int m = 4;
			int tempa[m] = { 1, 5, 9, 20 };
			Array A(m, tempa);
			cout << "Initial arrays:" << endl;
			A.show();
			B.show();
			int nav = 1;
			while (nav != 0)
			{
				cout << "Input number for action:" << endl;
				cout << "1 - union" << endl;
				cout << "2 - addition" << endl;
				cout << "3 - subtraction" << endl;
				cout << "4 - prefix increment" << endl;
				cout << "5 - postfix increment" << endl;
				cout << "6 - assignment =" << endl;
				cout << "7 - casting to double" << endl;
				cout << "8 - casting to int" << endl;
				cout << "9 - >> input and << output" << endl;
				cout << "10 - FILE >> input and << output" << endl;
				cout << "0 - exit" << endl;
				cin >> nav;
				if (nav == 1)
				{
					cout << "Union of arrays A&B:" << endl;
					Array C = A & B;
					C.show();
				}
				if (nav == 2)
				{
					cout << "Element-by-element addition A+B:" << endl;
					Array C = A + B;
					C.show();
				}
				if (nav == 3)
				{
					cout << "Element-by-element subtraction A-B:" << endl;
					Array C = A - B;
					C.show();
				}
				if (nav == 4)
				{
					cout << "Prefix increment ++A:" << endl;
					Array C = ++A;
					cout << "C: ";
					C.show();
					cout << "A: ";
					A.show();
				}
				if (nav == 5)
				{
					cout << "Postfix increment A++:" << endl;
					Array C = A++;
					cout << "C: ";
					C.show();
					cout << "A: ";
					A.show();
				}
				if (nav == 6)
				{
					cout << "Before assignment:" << endl;
					Array C;
					C.show();
					C = A;
					cout << "After assignment:" << endl;
					C.show();
				}
				if (nav == 7)
				{
					double av=(double)A;
					cout << "Average A = " << av << endl;
				}
				if (nav == 8)
				{
					int sum = (int)A;
					cout << "Sum of A = " << sum << endl; 
				}
				if (nav == 9)
				{
					Array C;
					cout << "Input size and array:" << endl; 
					cin >> C;
					cout << "Output array:" << endl;
					cout << C << endl;
				}
				if (nav == 10)
				{
					ofstream file("array.txt");
					file << B;
					file.close();
					ifstream file1("array.txt");
					Array C;
					file1 >> C;
					file.close();
					cout << C << endl;
				}
			}
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