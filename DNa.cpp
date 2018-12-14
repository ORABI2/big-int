#include "DNa.h"
#include "RNA.h"
#include<iostream>
#include<fstream>
using namespace std;
class RNA;
DNA::DNA()
{
	set_sequence();
}
int DNA::get_length()
{

	return length;

}
char* DNA::get_seq()
{
	return seq;
}
DNA::DNA(char * seq, int l, DNA_Type atype)
{

	length = l;
	this->seq = new char[length];
	for (int i = 0; i < length; i++)
	{
		this->seq[i] = seq[i];
	}
	type = atype;
}
DNA::DNA(const DNA& rhs)
{
	seq = new char[rhs.length];
	length = rhs.length;
	for (int i = 0; i < rhs.length; i++)
	{
		seq[i] = rhs.seq[i];

	}

	type = rhs.type;
}
char DNA::get_seq_fromDNA(int indx)
{
	return seq[indx];
}
void DNA::BuildComplementaryStrand()
{
	complementary_strand = new DNA(seq, length, type);
	for (int i = 0; i < length; i++)
	{
		if (seq[i] == 'A')
			complementary_strand->seq[ i ] = 'T';
		if (seq[i] == 'T')
			complementary_strand->seq[ i ] = 'A';
		if (seq[i] == 'C')
			complementary_strand->seq[ i ] = 'G';
		if (seq[i] == 'G')
			complementary_strand->seq[ i ] = 'C';



	}
}
void DNA::Print()
{
	cout << "Strand: ";
	for (int i = 0; i < length; i++)
	{
		cout << seq[i];
	}
	cout << endl << "Complementary Strand: ";
	for (int i = 0; i < length; i++)
	{
		cout << complementary_strand->seq[i];
	}
	cout << endl;
	cout << "Type: ";
	if (type == promoter)
	{
		cout << "Promoter" << endl;
	}
	else if (type == motif)
	{
		cout << "Motif" << endl;
	}
	else if (type == tail)
	{
		cout << "Tail" << endl;
	}
	else if (type == noncoding)
	{
		cout << "Noncoding" << endl;
	}

}
RNA DNA::ConvertToRNA()
{
	char* temp = new char[length];
	for (int i = 0; i < length; i++)
	{
		if (seq[i] == 'T')
			temp[i] = 'U';
		else
			temp[i] = seq[i];
	}
	RNA object(temp,length, mRNA);
	delete temp;
	return  object;
}
DNA::~DNA()
{

}

void DNA::SaveSequenceToFile(char*filename)
{
	ofstream file;
	file.open(filename);
	DNA obj(seq, length, type);
	for (int i = 0; i < length; i++) {
		file << obj.seq[i];
	}
	file << endl;
	file << "the length of the sequence is :" << obj.length<<endl;
	file << "the type of sequence  :" << obj.type<<endl;
	file.close();
}
void DNA::LoadSequenceFromFile(char*filename)
{
	ifstream file(filename);
	file >> length;
	for (int i = 0; i < length; i++)
	{
		file >> seq[i];
	}
	int x;
	file >> x;
	type = (DNA_Type)x;

}
void DNA::print_sequnece(ostream& out)
{
	out << "Strand: ";
	for (int i = 0; i < length; i++)
	{
		out << seq[i];
	}
	out << endl << "Complementary Strand: ";
	for (int i = 0; i < length; i++)
	{
		out << complementary_strand->seq[i];
	}
	out << endl;
	out << "Type: ";
	if (type == promoter)
	{
		out << "Promoter" << endl;
	}
	else if (type == motif)
	{
		out << "Motif" << endl;
	}
	else if (type == tail)
	{
		out << "Tail" << endl;
	}
	else if (type == noncoding)
	{
		out << "Noncoding" << endl;
	}
}
void DNA::get_sequence(istream& in)
{
	while (true)
	{
		try
		{
			cout << "Enter the length of the sequence: " << endl;
			in >> length;
			int counter = 0;
			char* arr = new char[length];
			if (length % 3 != 0)
			{
				string err = "Error \n'because the length of sequence must be divide on 3'";
				throw err;
			}

			cout << "Enter the sequence: " << endl;
			for (int i = 0; i < length; i++)
			{
				in >> arr[i];
			}
			for (int i = 0; i < length; i++)
			{

				if (arr[i] != 'A'&&arr[i] != 'C'&&arr[i] != 'G'&&arr[i] != 'T')
				{
					string err = "You Should make sure you enter a sequence of just (A,C,G,T) \n OR you enter an invalid size of sequnece ";
					throw err;
				}
			}
			seq = new char[length];
			for (int i = 0; i < length; i++)
			{
				seq[i] = arr[i];
			}
			string x;
			cout << "Enter the type of the DNA: " << endl;
			cin >> x;

			int y;
			if (x == "promoter")
			{
				y = 0;
			}
			else if (x == "motif")
			{
				y = 1;
			}
			else if (x == "tail")
			{
				y = 2;
			}
			else if (x == "noncoding")
			{
				y = 3;
			}
			else
			{
				string err = "please enter a valid type";
				throw err;
			}
			type = (DNA_Type)y;
			break;
		}
		catch (string err)
		{
			cout << "" << err << endl;
		}
	}
}
DNA DNA::operator+ (DNA& rhs)
{
	char* res = new char[length + rhs.length];
	for (int i = 0; i < length; i++)
	{
		res[i] = seq[i];
	}
	for (int i = 0; i < rhs.length; i++)
	{
		res[i + length] = rhs.seq[i];
	}
	return DNA(res, length + rhs.length, type);
}
bool DNA::operator==(DNA rhs)
{
	if (length != rhs.length)
	{
		return false;
	}
	if (type != rhs.type)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (seq[i] != rhs.seq[i])
		{
			return false;
			break;
		}
	}
	return true;
}
bool DNA::operator!=(DNA rhs)
{
	if (length == rhs.length)
	{
		return false;
	}

	return true;
}
