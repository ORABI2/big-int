#ifndef SEQUENCE_H
#define SEQUENCE_H

#pragma once
#include<iostream>
using namespace std;
class Sequence
{
protected:
	char * seq;
	int length;
public:
	// constructors and destructor
	Sequence();
	Sequence(int length);
	Sequence(Sequence& rhs);
	virtual ~Sequence();
	virtual int get_length()=0;
	virtual char* get_seq() = 0;
	virtual void LoadSequenceFromFile(char* filename) = 0;
	virtual void SaveSequenceToFile(char* filename) = 0;
	void set_sequence();
	virtual void Print() = 0;
	friend char* Align(Sequence* s1,Sequence* s2);
	friend int max(int a, int b);
	virtual void print_sequnece(ostream& out)=0 ;
	virtual void get_sequence(istream& in)=0 ;
	friend istream& operator>>(istream&in, Sequence& s);
	friend ostream& operator<<(ostream&out, Sequence& s);

};

#endif // SEQUENCE_H
