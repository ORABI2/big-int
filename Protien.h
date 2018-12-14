#ifndef PROTIEN_H
#define PROTIEN_H
#pragma once
#include"Sequence.h"
#include"DNa.h"
#include"RNA.h"
#include<iostream>
#include"CodonsTable.h"
using namespace std;
enum Protein_Type { Hormon, Enzyme, TF, Cellular_Function };

class Protein : public Sequence
{
private:
	Protein_Type type;
public:
	// constructors and destructor
	Protein();
	Protein(char * p,int l, Protein_Type atype);
	Protein(const Protein &rhs);
	~Protein();
	int get_length();
	char* get_seq();

		// return an array of DNA sequences that can possibly
		// generate that protein sequence
		DNA* GetDNAStrandsEncodingMe( DNA & bigDNA,int& length);
	 void Print();
	 void LoadSequenceFromFile(char*fileneme);
	 void SaveSequenceToFile(char*filename);
	 void print_sequnece(ostream& out);
	 void get_sequence(istream& in);
	 Protein operator+(Protein& rhs);
	 bool operator==(Protein rhs);
	 bool operator!=(Protein rhs);
};

#endif // PROTIEN_H
