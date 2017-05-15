#include "Array.h"

int Array::arr_cnt = 0;

Array::Array()
{
	max_size = 1;
	p = new int[1];
	p[0] = -1;
	index = 1;
	arr_cnt++;
}

Array::Array(const Array &t)
{
	p = new int[t.max_size];
	for (int i=0; i<t.max_size; i++)
		p[i] = t.p[i];
	max_size = t.max_size;
	index = t.index;
	arr_cnt++;
}

Array::Array(int size, int *tmp)
{
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = *(tmp + i);
	max_size = size;
	index = size;
	arr_cnt++;
}

Array::~Array()
{
	arr_cnt--;
	delete [] p;
}

int Array::get_size()
{
	return index;
}

int Array::search(int elem)
{
	int ind = -1;
	for (int i = 0; i < index; i++)
	{
		if (*(p + i) == elem)
			ind = i;
	}
	return ind;
}

int Array::get_elem(int ind)
{
	return p[ind];
}

void Array::change(int ind, int elem)
{
	p[ind] = elem;
}

void Array::add(int elem)
{
	if (index < max_size)
		p[index++] = elem;
	else
	{
		int *tempA = new int[2 * index];
		for (int i = 0; i <= index; i++)
			*(tempA+i) = *(p+i);
		tempA[index++] = elem;
		max_size *= 2;
		delete [] p;
		p = tempA;
	}
}

void Array::del(int elem)
{
	int pos=search(elem);
	for (int i = pos; i < index - 1; i++)
		p[i] = p[i + 1];
	index--;
	if (index < max_size / 3)
	{
		max_size /= 2;
		int * tempA= new int[max_size];
		for (int i = 0; i < index; i++)
			tempA[i] = p[i];
		delete[] p;
		p = tempA;
	}
}

void Array::show()
{
	for (int i = 0; i < index; i++)
	{
		cout << *(p + i)<<" ";
	}
	cout <<endl;
}

void Array::sort()
{
	for (int i = 0; i < index - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < index; j++)
		{
			if (p[min] > p[j])
				min = j;
		}
		if (i != min)
		{
			int tmp = p[i];
			p[i] = p[min];
			p[min] = tmp;
		}
	}
}

Array Array:: operator & (const Array &rhs) 
{
	Array A;
	int * tempA = new int[index + rhs.index];
	int i = 0;
	for (i; i < index; i++)
	{
		*(tempA+i) = *(p+i);
	}
	for (int j = 0; j < rhs.index; j++, i++)
	{
		tempA[i] = rhs.p[j];
	}
	A.p = tempA;
	A.index = index + rhs.index;
	A.max_size = index + rhs.index;
	arr_cnt++;
	return A;
}

Array Array:: operator + (const Array &rhs)
{
	Array A;
	if (index > rhs.index)
	{
		int * tempA = new int[index];
		int i = 0;
		for (i; i < rhs.index; i++)
		{
			tempA[i] = *(p + i) + *(rhs.p + i);
		}
		for (i; i < index; i++)
		{
			tempA[i] = p[i];
		}
		A.p = tempA;
		A.index = index;
		A.max_size = index;
	}
	else if (index == rhs.index)
	{
		int * tempA = new int[index];
		int i = 0;
		for (i; i < index; i++)
		{
			tempA[i] = p[i] + rhs.p[i];
		}
		A.p = tempA;
		A.index = index;
		A.max_size = index;
	}
	else
	{
		int * tempA = new int[rhs.index];
		int i = 0;
		for (i; i < index; i++)
		{
			tempA[i] = *(p + i) + *(rhs.p + i);
		}
		for (i; i < rhs.index; i++)
		{
			tempA[i] = rhs.p[i];
		}
		A.p = tempA;
		A.index = rhs.index;
		A.max_size = rhs.index;
	}
	arr_cnt++;
	return A;
}

Array Array:: operator - (const Array &rhs)
{
	Array A;
	if (index > rhs.index)
	{
		int * tempA = new int[index];
		int i = 0;
		for (i; i < rhs.index; i++)
		{
			tempA[i] = *(p+i) - *(rhs.p+i);
		}
		for (i; i < index; i++)
		{
			tempA[i] = p[i];
		}
		A.p = tempA;
		A.index = index;
		A.max_size = index;
	}
	else if (index == rhs.index)
	{
		int * tempA = new int[index];
		int i = 0;
		for (i; i < index; i++)
		{
			tempA[i] = p[i] - rhs.p[i];
		}
		A.p = tempA;
		A.index = index;
		A.max_size = index;
	}
	else
	{
		int * tempA = new int[rhs.index];
		int i = 0;
		for (i; i < index; i++)
		{
			tempA[i] = *(p + i) - *(rhs.p + i);
		}
		for (i; i < rhs.index; i++)
		{
			tempA[i] = rhs.p[i];
		}
		A.p = tempA;
		A.index = rhs.index;
		A.max_size = rhs.index;
	}
	arr_cnt++;
	return A;
}

Array & Array:: operator ++ ()
{
	for (int i = 0; i < index; i++)
	{
		p[i]++;
	}
	return *this;
}

Array Array:: operator ++ (int)
{
	Array A(*this);
	for (int i = 0; i < index; i++)
	{
		p[i]++;
	}
	return A;
}

Array & Array:: operator = (const Array & rhs)
{
	int q = 0;
	for (int i = 0; i < index; i++)
		if (p[i] == rhs.p[i])
			q++;
	if (q == rhs.index)
		return *this;
	p = new int[rhs.max_size];
	for (int i = 0; i<rhs.max_size; i++)
		p[i] = rhs.p[i];
	max_size = rhs.max_size;
	index = rhs.index;
	arr_cnt++;
	return *this;
}

Array::operator double()
{
	double sum = 0;
	for (int i = 0; i < index; i++)
		sum += p[i];
	double av = sum / index;
	return av;
}

Array::operator int()
{
	int sum = 0;
	for (int i = 0; i < index; i++)
		sum += p[i];
	return sum;
}

ostream & operator <<(ostream &out, Array & obj)
{
	for (int i = 0; i < obj.index; i++)
	{
		out << *(obj.p + i) << " ";
	}
	return out;
}

istream & operator >> (istream &in, Array & obj)
{
	in >> obj.index;
	obj.max_size=obj.index;
	obj.p = new int[obj.index];
	for (int i = 0; i < obj.index; i++)
	{
		in >> obj.p[i];
	}
	obj.arr_cnt++;
	return in;
}

ofstream & operator << (ofstream &file, Array & obj)
{
	for (int i = 0; i < obj.index; i++)
	{
		file << obj.p[i] << " ";
	}
	return file;
}

ifstream & operator >> (ifstream &file, Array & obj)
{
	int size = 0;
	char smbl;
	while (!file.eof())
	{
		file.get(smbl);
		if (smbl==' ')
			size++;
	}
	file.clear();
	file.seekg(0, ios::beg);
	obj.p = new int[size];
	for (int i = 0; i < size-1; i++)
	{
			file >> obj.p[i];
	}
	obj.index = size-1;
	obj.max_size = size-1;
	obj.arr_cnt++;
	return file;
}
