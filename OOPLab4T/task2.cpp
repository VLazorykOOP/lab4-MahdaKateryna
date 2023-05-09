#include <iostream>
#include <string>
#include <map>
#include "Task2.h"
using namespace std;

EData::EData() {}

EData::EData(string post, string PIB)
{
	this->person[0].first = post;
	this->person[0].second = PIB;
}

EData::~EData() {}


int EData::getCodeError()
{
	return this->CodeError;
}

int EData::getSize()
{
	return this->size;
}

void EData::AddPerson(string post, string PIB)
{
	if (this->size == SIZE)
		CodeError = 1;
	else
	{
		person[this->size].first = post;
		person[this->size].second = PIB;
		this->size++;
	}
}

pair<string, string>& EData::operator[](string& post)
{
	for (int i = 0; i < this->size; i++)
		if (post == this->person[i].first)
			return this->person[i];

	this->CodeError = 2;
	return this->person[0];
}

//pair<string, string>& EData::operator[](string& PIB)
//{
//	for (int i = 0; i < this->size; i++)
//		if (PIB == this->person[i].second)
//			return this->person[i];
//
//	this->CodeError = 2;
//	return this ->person[0];
//}

ostream& operator<<(ostream& os, const pair<string, string> person)
{
	os << person.first << "\t" << person.second << endl;
	return os;
}

istream& operator>>(istream& is, pair<string, string> person)
{
	is >> person.first;
	is >> person.second;
	return is;
}

ostream& operator<<(ostream& os, const EData pers)
{
	for (int i = 0; i < pers.size; i++)
		os << pers.person[i].first << "\t" << pers.person[i].second << endl;
	os << "Code error: " << pers.CodeError << endl;
	return os;
}