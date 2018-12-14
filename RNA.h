#ifndef RNA_H
#define RNA_H
#pragma once
#include"Sequence.h"
#include"DNa.h"
#include"Protien.h"
#include"CodonsTable.h"
#include<iostream>
class CodonsTable;
class Protein;
using namespace std;
enum RNA_Type { mRNA, pre_mRNA, mRNA_exon, mRNA_intron };

class RNA : public Sequence
{
private:
	RNA_Type type;
public:
	// constructors and destructor
	RNA();
	RNA(char * seq, int l, RNA_Type atype);
	RNA(const RNA &rhs);
	~RNA();
	char get_seq_fromRNA(int indx);
	int get_length();
	char* get_seq();
	// function to be overridden to print all the RNA information
	void Print();
	// function to convert the RNA sequence into protein sequence
	// using the codonsTable object
	Protein ConvertToProtein(CodonsTable& table);
	// function to convert the RNA sequence back to DNA
	DNA ConvertToDNA();
	RNA operator+(RNA& rhs);
	void LoadSequenceFromFile(char*fileneme);
	void SaveSequenceToFile(char*filename);
	void print_sequnece(ostream& out);
	void get_sequence(istream& in);
	bool operator==(RNA rhs);
	bool operator!=(RNA rhs);
};

#endif // RNA_H
