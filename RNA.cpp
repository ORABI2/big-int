#include "RNA.h"
#include<iostream>
#include"CodonsTable.h"
#include<fstream>
using namespace std;
RNA::RNA()
{
	set_sequence();
}

RNA::RNA(char * seq, int l, RNA_Type atype)
{

	length = l;
	this->seq = new char[length];
	for (int i = 0; i < length; i++)
	{
		this->seq[i] = seq[i];
	}
	type = atype;
}
RNA::RNA(const RNA &rhs)
{
	seq = new char[rhs.length];
	length = rhs.length;
	for (int i = 0; i < rhs.length; i++)
	{
		seq[i] = rhs.seq[i];

	}
	type = rhs.type;
}
void RNA::Print()
{
	cout << "The Sequence:" << " ";
	for (int i = 0; i < length; i++)
	{
		cout << seq[i] << " ";
	}
	cout << endl;
	cout << "The Type:" << " ";
	switch (type)
	{
	case 0:
		cout << "mRNA" << endl;
		break;
	case 1:
		cout << "pre_mRNA" << endl;
		break;
	case 2:
		cout << "mRNA_exon" << endl;
		break;
	case 3:
		cout << "mRNA_intron" << endl;
		break;
	default:
		cout << "unknown" << endl;
	}
}
DNA RNA::ConvertToDNA()
{
	char* temp = new char[length];
	for (int i = 0; i < length; i++)
	{
		if (seq[i] == 'U')
			temp[i] = 'T';
		else
			temp[i] = seq[i];
	}
	DNA object(temp, length, tail);
	delete temp;
	return  object;
}
char RNA::get_seq_fromRNA(int index)
{
	return seq[index];
}
int RNA::get_length()
{
	return length;
}
char* RNA::get_seq()
{
	return seq;
}
Protein RNA::ConvertToProtein(  CodonsTable&  table)
{
	int c = 0;
	char* temp = new char[length / 3];
	char* arr=new char[3];

	for (int i = 0; i < length; i +=3)
	{
		arr[0] = seq[i];
		arr[1] = seq[i+1];
		arr[2] = seq[i+2];

		for (int j = 0; j < 64; j++)
		{
			Codon x;
			x= table.getCodon(j);
			if (arr[0] == x.value[0] && arr[1] == x.value[1] && arr[2] == x.value[2])
			{
				if(x.AminoAcid!='*')
				{
					temp[c] = x.AminoAcid;
					c++;
					break;
				}

			}

		}

	}
	Protein object(temp, length / 3, Hormon);
	delete arr;
	delete temp;
	return object;
}

RNA::~RNA()
{

}


RNA RNA::operator+ (RNA& rhs)
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
	return RNA(res, length + rhs.length, type);
}
void RNA::SaveSequenceToFile(char*filename)
{
	ofstream file;
	file.open(filename);
	for (int i = 0; i < length; i++)
	{
		file << seq[i];
	}
	file << endl;
	file << length<<endl;
	file << type<<endl;
	file.close();
}
void RNA::LoadSequenceFromFile(char*filename)
{
	ifstream file(filename);
	file >> length;
	for (int i = 0; i < length; i++)
	{
		file >> seq[i];
	}
	int x;
	file >> x;
	type = (RNA_Type)x;

}
void RNA::print_sequnece(ostream& out)
{
	out << "Strand: ";
	for (int i = 0; i < length; i++)
	{
		out << seq[i];
	}
	out << endl;
	out << "Type: ";
	if (type == mRNA)
	{
		out << "mRNA" << endl;
	}
	else if (type == pre_mRNA)
	{
		out << "pre_mRNA" << endl;
	}
	else if (type == mRNA_exon)
	{
		out << "mRNA_exon" << endl;
	}
	else if (type == mRNA_intron)
	{
		out << "mRNA_intron" << endl;
	}
}
void RNA::get_sequence(istream& in)
{
	while (1)
	{
		try
		{
			cout << "Enter the length of the sequence: " << endl;
			in >> length;
			char* arr = new char[length];
			if (length % 3 != 0)
			{
				string err = "the sequence length must be multiple of 3";
				throw err;
			}
			cout << "Enter the sequence: " << endl;
			for (int i = 0; i < length; i++)
			{
				in >> arr[i];
			}
			for (int i = 0; i < length; i++)
			{
				if (arr[i] != 'A'&&arr[i] != 'C'&&arr[i] != 'G'&&arr[i] != 'U')
				{
					string err = "you can't enter any character exept:(A,C,G,U)";
					throw err;
				}
			}
			seq = new char[length];
			for (int i = 0; i < length; i++)
			{
				seq[i] = arr[i];
			}
			string x;
			cout << "Enter the type of the RNA: " << endl;
			in >> x;
			int y;
			if (x == "mRNA")
			{
				y = 0;
			}
			else if (x == "pre_mRNA")
			{
				y = 1;
			}
			else if (x == "mRNA_exon")
			{
				y = 2;
			}
			else if (x == "mRNA_intron")
			{
				y = 3;
			}
			else
			{
				string err = "please enter a valid type";
				throw err;
			}
			type = (RNA_Type)y;
			break;
		}
		catch (string err)
		{
			cout << "Error!\n" << err << endl;
		}
	}
}
bool RNA::operator==(RNA rhs)
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
bool RNA::operator!=(RNA rhs)
{
	if (length == rhs.length)
	{
		return false;
	}

	return true;
}
