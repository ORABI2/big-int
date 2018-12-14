#include <cstring>
#include <fstream>
#include"CodonsTable.h"
using namespace std;

CodonsTable::CodonsTable()
{
	LoadCodonsFromFile("RNA_codon_table.txt");
}
void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
	ifstream cdnFile;
	cdnFile.open(codonsFileName, ios::in);
	char temp[4];
	char AA;
	int counter = 0;
	while (!cdnFile.eof() && counter != 64)
	{
		cdnFile >> temp >> AA;
		codons[counter].value[0] = temp[0];
		codons[counter].value[1] = temp[1];
		codons[counter].value[2] = temp[2];
		codons[counter].value[3] = '\0';
		codons[counter].AminoAcid = AA;
		counter++;
	}
}
Codon CodonsTable::getAminoAcid(char * value)
{
	Codon x;
	x.value[0] = value[0];
	x.value[1] = value[1];
	x.value[2] = value[2];
	for (int i = 0; i < 64; i++)
	{
		if ((x.value[0] == codons[i].value[0]) && (x.value[1] == codons[i].value[1]) && (x.value[2] == codons[i].value[2]))
		{
			x.AminoAcid = codons[i].AminoAcid;
			return x;
		}
	}
}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
	Codon x;
	x.value[0] = value[0];
	x.value[1] = value[1];
	x.value[2] = value[2];
	x.AminoAcid = AminoAcid;
	codons[index] = x;
}
Codon CodonsTable::getCodon(const int index)
{
	Codon res;
	res.value[0] = codons[index].value[0];
	res.value[1] = codons[index].value[1];
	res.value[2] = codons[index].value[2];
	res.AminoAcid = codons[index].AminoAcid;
	return res;
}



CodonsTable::~CodonsTable()
{

}
