#ifndef DNA_H
#define DNA_H
#pragma once
#include "Sequence.h"
class RNA;

enum DNA_Type { promoter, motif, tail, noncoding };

class DNA : public Sequence
{
private:
	DNA_Type type;
	DNA * complementary_strand;
	int startIndex;
	int endIndex;
public:
	// constructors and destructor
	DNA();
	DNA(char * seq, int l, DNA_Type atype);
	DNA(const DNA& rhs);
	~DNA();
	int get_length();
	char get_seq_fromDNA(int indx);
	char* get_seq();
	// function printing DNA sequence information to user
	void Print();
	void LoadSequenceFromFile(char*fileneme);
	void SaveSequenceToFile(char*filename);
	void print_sequnece(ostream& out);
	void get_sequence(istream& in);
	void BuildComplementaryStrand();
	RNA ConvertToRNA();
    DNA operator+(DNA&rhs);
	bool operator==(DNA rhs);
	bool operator!=(DNA rhs);
};

#endif // DNA_H
