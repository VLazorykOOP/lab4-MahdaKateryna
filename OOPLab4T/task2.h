#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;
const int SIZE = 100;
class EData
{ 
private:
	pair<string, string>person[SIZE];
	int size = 0;
	int CodeError = 0; // 1 - Overflow 2 - Wrong index
public:
	EData();
	EData(string post, string PIB);
	~EData();

	int getCodeError();
	int getSize();

	void AddPerson( string post, string PIB);
	
	pair<string, string>& operator[](string& post);
	//pair<string, string>& operator[](string& PIB);

	friend ostream& operator<<(ostream& os, const pair<string, string>person);
	friend istream& operator>>(istream& is, pair<string, string>person);
	
	//PrintAll
	friend ostream& operator<<(ostream& os, const EData);
};