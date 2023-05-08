#include "task1.h"

#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES 
using namespace std;

int VectorLong::counter = 0;

VectorLong::VectorLong() : VectorLong(1, 0) {}

VectorLong::VectorLong(int size) : VectorLong(size, 0) {}

VectorLong::VectorLong(int size, long value)
{
	this->size = size;
	this->array = new long[size];
	for (int i = 0; i < size; i++)
		this->array[i] = value;
	this->counter++;
}

VectorLong::VectorLong(const VectorLong& p)
{
	this->size = p.size;
	this->state = p.state;
	this->array = new long[p.size];
	if (this->array == nullptr)
		this->state = 1;
	else
		for (int i = 0; i < this->size; i++)
			this->array[i] = p.array[i];
	this->counter++;
}


VectorLong::~VectorLong()
{
	delete[] this->array;
	this->counter--;
}




//----------------Unari----------------
VectorLong& VectorLong::operator++()
{
	for (int i = 0; i < this->size; i++)
		this->array[i]++;
	return *this;
}

VectorLong& VectorLong::operator--()
{
	for (int i = 0; i < this->size; i++)
		this->array[i]--;
	return *this;
}

VectorLong VectorLong::operator++(int)
{
	VectorLong copy{ *this };
	++(*this);
	return copy;
}
VectorLong VectorLong::operator--(int)
{
	VectorLong copy{ *this };
	--(*this);
	return copy;
}

bool VectorLong::operator!()
{
	return size != 0;
}

VectorLong& VectorLong::operator~()
{
	for (int i = 0; i < this->size; i++)
		this->array[i] = ~array[i];
	return *this;
}

VectorLong& VectorLong::operator-()
{
	for (int i = 0; i < size; i++)
		this->array[i] = -this->array[i];
	return *this;
}




VectorLong& VectorLong::operator=(VectorLong p)
{
	this->size = p.size;
	delete[] array;
	 long* array{ new  long[p.size] };
	for (int i = 0; i < p.size; i++)
		this->array[i] = p.array[i];
	return *this;
}


VectorLong& VectorLong::operator+=(VectorLong& p)
{
	if (this->size != p.size)
	{
		this->state = 1;
		return *this;
	}
	for (int i = 0; i < this->size; i++)
		this->array[i] += p.array[i];
	return *this;
}

VectorLong& VectorLong::operator-=(VectorLong& p)
{
	if (this->size != p.size)
	{
		this->state = 1;
		return *this;
	}
	for (int i = 0; i < this->size; i++)
		this->array[i] -= p.array[i];
	return *this;
}

VectorLong& VectorLong::operator*=( long value)
{
	for (int i = 0; i < this->size; i++)
		this->array[i] *= value;
	return *this;
}

VectorLong& VectorLong::operator/=( long value)
{
	if (value == 0)
	{
		this->state = 2;
		return *this;
	}
	for (int i = 0; i < this->size; i++)
		this->array[i] /= value;
	return *this;
}

VectorLong& VectorLong::operator%=( long value)
{
	if (value == 0)
	{
		this->state = 2;
		return *this;
	}
	for (int i = 0; i < this->size; i++)
		this->array[i] %= value;
	return *this;
}

VectorLong& VectorLong::operator|=(VectorLong& p)
{
	if (this->size != p.size)
	{
		this->state = 1;
		return *this;
	}
	for (int i = 0; i < this->size; i++)
		this->array[i] |= p.array[i];
	return *this;
}

VectorLong& VectorLong::operator^=(VectorLong& p)
{
	if (this->size != p.size)
	{
		this->state = 1;
		return *this;
	}
	for (int i = 0; i < this->size; i++)
		this->array[i] ^= p.array[i];
	return *this;
}

VectorLong& VectorLong::operator&=(VectorLong& p)
{
	if (this->size != p.size)
	{
		this->state = 1;
		return *this;
	}
	for (int i = 0; i < this->size; i++)
		this->array[i] &= p.array[i];
	return *this;
}



//----------------Arithmetic binary----------------
VectorLong VectorLong::operator+(VectorLong& p)
{
	VectorLong tmp(this->size);
	if (this->size != p.size)
	{
		tmp.state = 1;
		return tmp;
	}
	for (int i = 0; i < this->size; i++)
		tmp.array[i] = this->array[i] + p.array[i];
	return tmp;
}

VectorLong VectorLong::operator-(VectorLong& p)
{
	VectorLong tmp(this->size);
	if (this->size != p.size)
	{
		tmp.state = 1;
		return tmp;
	}
	for (int i = 0; i < this->size; i++)
		tmp.array[i] = this->array[i] - p.array[i];
	return tmp;
}

VectorLong VectorLong::operator*( long value)
{
	VectorLong tmp(this->size);
	for (int i = 0; i < this->size; i++)
		tmp.array[i] = this->array[i] * value;
	return tmp;
}

VectorLong VectorLong::operator/( long value)
{
	VectorLong tmp(this->size);
	if (value == 0)
	{
		tmp.state = 2;
		return tmp;
	}
	for (int i = 0; i < this->size; i++)
		tmp.array[i] = this->array[i] / value;
	return tmp;
}

VectorLong VectorLong::operator%( long value)
{
	VectorLong tmp(this->size);
	if (value == 0)
	{
		tmp.state = 2;
		return tmp;
	}
	for (int i = 0; i < size; i++)
		tmp.array[i] = this->array[i] % value;
	return tmp;
}



//----------------Bitwise binary----------------
VectorLong VectorLong::operator|(VectorLong& p)
{
	VectorLong tmp(this->size);
	if (this->size != p.size)
	{
		tmp.state = 1;
		return tmp;
	}
	for (int i = 0; i < this->size; i++)
		tmp.array[i] = this->array[i] | p.array[i];
	return tmp;
}

VectorLong VectorLong::operator^(VectorLong& p)
{
	VectorLong tmp(this->size);
	if (this->size != p.size)
	{
		tmp.state = 1;
		return tmp;
	}
	for (int i = 0; i < this->size; i++)
		tmp.array[i] = this->array[i] ^ p.array[i];
	return tmp;
}

VectorLong VectorLong::operator&(VectorLong& p)
{
	VectorLong tmp(this->size);
	if (this->size != p.size)
	{
		tmp.state = 1;
		return tmp;
	}
	for (int i = 0; i < this->size; i++)
		tmp.array[i] = this->array[i] & p.array[i];
	return tmp;
}


//----------------Indexing----------------
 long& VectorLong::operator[](const int index)
{
	if (index < 0 || index > this->size)
	{
		this->state = 3;
		return this->array[this->size - 1];
	}
	return this->array[index];
}

//----------------New----------------
void* VectorLong::operator new(size_t size)
{
	cout << endl << "Operator new worked" << endl;
	VectorLong temp = VectorLong(size);
	return &temp;
	//return new  long[size] {};
}

//----------------Delete----------------
void VectorLong::operator delete(void* pointer)
{
	cout << endl << "Operator delete worked" << endl;
	delete[] pointer;
}

//----------------()----------------
long VectorLong::operator()()
{
	double abs = 0;
	for (int i = 0; i < size; i++)
		abs += (array[i] * array[i]);
	return sqrt(abs);
}

//----------------Comparison size----------------
bool VectorLong::operator==(VectorLong& p)
{
	if (this->size == p.size && this->array == p.array)
		return true;
	else
		return false;

}

bool VectorLong::operator!=(VectorLong& p)
{
	if (this->size != p.size || this->array != p.array)
		return true;
	else
		return false;
}

bool VectorLong::operator>(VectorLong& p)
{
	if (this->size > p.size)
		return true;
	else
		return false;
}

bool VectorLong::operator>=(VectorLong& p)
{
	if (this->size >= p.size)
		return true;
	else
		return false;
}

bool VectorLong::operator<(VectorLong& p)
{
	if (this->size < p.size)
		return true;
	else
		return false;
}

bool VectorLong::operator<=(VectorLong& p)
{
	if (this->size <= p.size)
		return true;
	else
		return false;
}

void VectorLong::Print()
{
	cout << "Size: " << this->size << endl;
	cout << "State: " << this->state << endl;
	cout << "Counter: " << this->counter << endl;
	cout << "Array: " << endl;
	for (int i = 0; i < this->size; i++)
		cout << this->array[i] << '\t';
	cout << endl << endl;
}


//----------------Bitwise shift operations----------------
VectorLong& operator>>(VectorLong& p,  long value)
{
	VectorLong tmp(p.size);
	for (int i = 0; i < p.size; i++)
		tmp.array[i] = p.array[i] >> value;
	return tmp;
}

VectorLong& operator<<(VectorLong& p,  long value)
{
	VectorLong tmp(p.size);
	for (int i = 0; i < p.size; i++)
		tmp.array[i] = p.array[i] << value;
	return tmp;
}
