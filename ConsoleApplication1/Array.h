#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class Array
{
	int max_size;
	int index;
	int *p;
	static int arr_cnt;
public:
	Array();
	Array(const Array &t);
	Array(int size, int *tmp);
	~Array();
	int get_size();
	void add(int elem);
	int search(int elem);
	int get_elem(int ind);
	void change(int ind, int elem);
	void del(int elem);
	void show();
	void sort();
	Array operator & (const Array &rhs);
	Array operator + (const Array &rhs);
	Array operator - (const Array &rhs);
	Array & operator ++ ();
	Array operator ++ (int);
	Array & operator = (const Array & rhs);
	operator double();
	operator int();
	friend ostream & operator <<(ostream &out, Array & obj);
	friend istream & operator >>(istream &in, Array & obj);
	friend ofstream & operator << (ofstream &file, Array & obj);
	friend ifstream & operator >> (ifstream &file, Array & obj);
};

class Stack : public Array
{
public:
	Stack();
	~Stack();
};

class Queue : public Array
{

public:
	Queue();
	~Queue();
};