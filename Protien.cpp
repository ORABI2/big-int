#include "Protien.h"
#include "RNA.h"
#include<fstream>
Protein::Protein()
{

}
Protein::Protein(char* p, int l, Protein_Type atype)
{
	length = l;
	seq = new char[length];
	for (int i = 0; i < length; i++)
	{
		seq[i] = p[i];
	}
	type = atype;
}
Protein::Protein(const Protein &rhs)
{
	seq = new char[rhs.length];
	length = rhs.length;
	for (int i = 0; i < rhs.length; i++)
	{
		seq[i] = rhs.seq[i];

	}
	type = rhs.type;
}
void Protein::Print()
{
	cout << "The Sequence:" << " ";
	for (int i = 0; i < length; i++)
	{
		cout << seq[i];
	}
	cout << endl;
	cout << "The Type:" << " ";
	switch (type)
	{
	case 0:
		cout << "Hormon" << endl;
		break;
	case 1:
		cout << "Enzyme" << endl;
		break;
	case 2:
		cout << "TF" << endl;
		break;
	case 3:
		cout << "Cellular_Function" << endl;
		break;
	default:
		cout << "unknown" << endl;
	}
}
int Protein::get_length()
{
	return length;
}
char* Protein::get_seq()
{
	return seq;
}

Protein::~Protein()
{
	//delete seq;
}

  Protein Protein::operator+ (Protein& rhs)
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
	 Protein obj(res, length + rhs.length,type);
	 return obj;
  }
  void Protein::SaveSequenceToFile(char*filename)
  {
	  ofstream file;
	  file.open(filename);
	  for (int i = 0; i < length; i++)
	  {
		  file << seq[i];
	  }
	  file << endl;
	  file << length << endl;
	  file << type << endl;
	  file.close();
  }
  void Protein::LoadSequenceFromFile(char*filename)
  {
	  ifstream file(filename);
	  file >> length;
	  for (int i = 0; i < length; i++)
	  {
		  file >> seq[i];
	  }
	  int x;
	  file >> x;
	  type = (Protein_Type)x;

  }
  void Protein::print_sequnece(ostream& out)
  {
	  out << "Strand: ";
	  for (int i = 0; i < length; i++)
	  {
		  out << seq[i];
	  }
	  out << endl;
	  out << "Type: ";
	  if (type == Hormon)
	  {
		  out << "Hormon" << endl;
	  }
	  else if (type == Enzyme)
	  {
		  out << "Enzyme" << endl;
	  }
	  else if (type == TF)
	  {
		  out << "TF" << endl;
	  }
	  else if (type == Cellular_Function)
	  {
		  out << "Cellular_Function" << endl;
	  }
  }
  void Protein::get_sequence(istream& in)
  {
	  while (true)
	  {
		  try
		  {
			  cout << "Enter the length of the sequence: " << endl;
			  in >> length;
			  char* arr = new char[length];
			  cout << "Enter the sequence: " << endl;
			  for (int i = 0; i < length; i++)
			  {
				  in >> arr[i];
			  }
			  CodonsTable table;
			  for (int i = 0; i < length; i++)
			  {
				  bool check = false;
				  for (int j = 0; j < 64; j++)
				  {
					  if (arr[i] == table.getCodon(j).AminoAcid && arr[i] != '*' && arr[i] != '*')
					  {
						  check = true;
					  }
				  }
				  if (check == false)
				  {
					  string err = "You have entered an invalid character.\n";
					  throw err;
				  }
			  }
			  seq = new char[length];
			  for (int i = 0; i < length; i++)
			  {
				  seq[i] = arr[i];
			  }
			  string x;
			  cout << "Enter the type of the Protein: " << endl;
			  cin >> x;
			  int y;
			  if (x == "hormon")
			  {
				  y = 0;
			  }
			  else if (x == "enzyme")
			  {
				  y = 1;
			  }
			  else if (x == "TF")
			  {
				  y = 2;
			  }
			  else if (x == "Cellular_Function")
			  {
				  y = 3;
			  }
			  else
			  {
				  string err = "please enter a valid type";
				  throw err;
			  }
			  type = (Protein_Type)y;
			  break;
		  }
		  catch (string err)
		  {
			  cout << "Error!\n" << err << endl;
		  }
	  }
  }

  DNA* Protein::GetDNAStrandsEncodingMe(DNA & bigDNA,int& DNA_count)
  {
	  string temp = "";
	  DNA* allstrands = new DNA[bigDNA.get_length()];
	  int strand_counter = 0;
	  RNA bigRNA(bigDNA.ConvertToRNA());
	  CodonsTable table;
	  int counter = 0;
	  for (int i = 0; i < (bigDNA.get_length()-2); i += 3)
	  {
		  for (int j = 0; j < 64; j++)
		  {

			  if (bigDNA.get_seq_fromDNA(i) == table.getCodon(j).value[0] && bigDNA.get_seq_fromDNA(i + 1) == table.getCodon(j).value[1] && bigDNA.get_seq_fromDNA(i + 2) == table.getCodon(j).value[2])
			  {
				  temp += table.getCodon(j).AminoAcid;
				  counter++;
				  if (counter == length)
				  {
					  bool is_equal = true;
					  for (int m = 0; m < length; m++)
					  {
						  if (temp[m] != seq[m])
						  {
							  is_equal = false;
							  break;
						  }
					  }
					  if (is_equal)
					  {

						  char* sequence = new char[length * 3];
						  int seq_count = 0;
						  i -= (length - 1) * 3;
						  for (int j = i; j < (i + (length * 3)); j += 3)
						  {
							  sequence[seq_count++] = bigDNA.get_seq_fromDNA(bigDNA.get_length()- j-1);
							  sequence[seq_count++] = bigDNA.get_seq_fromDNA(bigDNA.get_length()- (j+1)-1);
							  sequence[seq_count++] = bigDNA.get_seq_fromDNA(bigDNA.get_length()-(j+2)-1);
						  }
						  DNA one_possibility(sequence, length * 3, tail);
						  allstrands[strand_counter++] = one_possibility;
						  i += ((length - 1) * 3);
					  }
					  else
					  {
						  i -= (length-1)*3+2;
					  }
					  temp = "";
					  counter = 0;
					  break;
				  }
			  }
		  }
	  }
	  DNA_count = strand_counter;
	  return allstrands;
  }
  bool Protein::operator==(Protein rhs)
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
  bool Protein::operator!=(Protein rhs)
  {
	  if (length == rhs.length)
	  {
		  return false;
	  }

	  return true;
  }
