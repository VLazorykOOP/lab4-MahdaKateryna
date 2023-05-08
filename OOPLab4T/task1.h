#pragma once

class VectorLong
{
private:
	 long* array = nullptr;
	int size = 0;
	int state = 0;
	static int counter;
public:
	VectorLong();
	VectorLong(int size);
	VectorLong(int size,  long value);
	VectorLong(const VectorLong& p);
	~VectorLong();

	//Unari
	VectorLong& operator++();
	VectorLong& operator--();
	VectorLong operator++(int);
	VectorLong operator--(int);
	bool operator!();
	VectorLong& operator~();
	VectorLong& operator-();

	//Appropriation
	VectorLong& operator=(VectorLong p);
	VectorLong& operator+=(VectorLong& p);
	VectorLong& operator-=(VectorLong& p);
	VectorLong& operator*=(long value);
	VectorLong& operator/=(long value);
	VectorLong& operator%=(long value);
	VectorLong& operator|=(VectorLong& p);
	VectorLong& operator^=(VectorLong& p);
	VectorLong& operator&=(VectorLong& p);

	//Arithmetic binary
	VectorLong operator+(VectorLong& p);
	VectorLong operator-(VectorLong& p);
	VectorLong operator*( long value);
	VectorLong operator/( long value);
	VectorLong operator%( long value);

	//Bitwise binary
	VectorLong operator|(VectorLong& p);
	VectorLong operator^(VectorLong& p);
	VectorLong operator&(VectorLong& p);

	//bitwise shift operations
	friend VectorLong& operator>>(VectorLong& p, long value);
	friend VectorLong& operator<<(VectorLong& p,  long value);

	//Indexing
	 long& operator[](const int index);

	//New
	void* operator new(size_t size);

	//Delete
	void operator delete(void* pointer);

	 long operator()();

	//comparison //size
	bool operator==(VectorLong& p);
	bool operator!=(VectorLong& p);
	bool operator>(VectorLong& p);
	bool operator>=(VectorLong& p);
	bool operator<(VectorLong& p);
	bool operator<=(VectorLong& p);

	void Print();
};
