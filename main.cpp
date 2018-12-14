#include <iostream>
#include "DNa.h"
#include "RNA.h"
#include "Sequence.h"
#include"Protien.h"
#include"CodonsTable.h"
#include <iostream>
#include<string.h>
#include<string>
using namespace std;
int main()
{
	cout << "choose the type of the sequnce !" << endl;
	cout << "1-[ DNA ]" << endl;
	cout << "2-[ RNA ]" << endl;
	cout << "3-[ protein ]" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		DNA object1;
		cin >> object1;
		cout << "Choose the operation you want :" << endl;
		cout << "1- Print the entered DNA & the complementary strand for this DNA ." << endl;
		cout << "2- Convert from DNA to RNA" << endl;
		cout << "3- Align two DNAs" << endl;
		cout << "4- Save the DNA in file" << endl;
		cout << "5- Load another DNA from file" << endl;
		cout << "6- enter another DNA" << endl;
		cout << "7- print DNA " << endl;
		cout << "8- add 2 DNAs " << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			object1.BuildComplementaryStrand();
			object1.Print();
		}
		else if (choice == 2)
		{
			RNA object2(object1.ConvertToRNA());
			object2.Print();
		}
		else if(choice == 3)
		{
			cout << "Entering the 1st DNA....." << endl;
			DNA obj;
			cin >> obj;
			Sequence* s1 = new DNA(obj);
			cout << "Entering the 2nd DNA....." << endl;
			DNA obj2;
			cin >> obj2;
			Sequence* s2= new DNA(obj2);
			char* out = Align(s1, s2);
			int i = 0;
			cout << "The Align result is: ";
			while (out[i] != '\0')
			{
				if (out[i] >= 'A'&&out[i] <= 'Z')
				{
					cout << out[i];
					i++;
				}
				else break;
			}
			}
		else if (choice == 4)
		{
			cout << "Enter file name:" << endl;
			char* filename = new char[28];
			cin >> filename;
			object1.SaveSequenceToFile(filename);
		}
		else if (choice == 5)
		{
			cout << "Enter file name:" << endl;
			char* filename = new char[28];
			cin >> filename;
			object1.LoadSequenceFromFile(filename);
			object1.BuildComplementaryStrand();
		}
		else if (choice == 6)
		{
			DNA obj;
			cin >> obj;
			obj.BuildComplementaryStrand();
		}
		else if (choice == 7)
		{

			cout << object1 << endl;

		}
		else if (choice == 8)
		{
			cout << "Entering the 1st DNA....." << endl;
			DNA obj1;
			cin>>obj1;
			cout << "Entering the 2nd DNA....." << endl;
			DNA obj2 ;
			cin >> obj2;
			DNA obj3(obj1 + obj2);
			obj3.BuildComplementaryStrand();
			cout << obj3 << endl;
		}


	}
	if (choice == 2)
	{

		RNA object1;
		cin >> object1;
		cout << "Choose the operation you would like to do" << endl;
		cout << "1)Print the entered RNA" << endl;
		cout << "2)Convert from RNA to DNA" << endl;
		cout << "3)Convert from RNA to Protein" << endl;
		cout << "4)Align two RNAs" << endl;
		cout << "5)Save the RNA to a file" << endl;
		cout << "6)Load another RNA from file" << endl;
		cout << "7)enter another RNA" << endl;
		cout << "8)print RNA" << endl;
		cout << "9)add 2 RNAs" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			object1.Print();
		}
		else if (choice == 2)
		{
			DNA object2(object1.ConvertToDNA());
			object2.Print();
		}
		else if (choice == 3)
		{
			CodonsTable table;
			Protein obj(object1.ConvertToProtein(table));
			obj.Print();
		}
		else if (choice == 4)
		{
			cout << "Entering the 1st RNA....." << endl;
			RNA obj;
			cin >> obj;
			Sequence* s1 = new RNA(obj);
			cout << "Entering the 2nd RNA....." << endl;
			RNA obj2;
			cin >> obj2;
			Sequence* s2 = new RNA(obj2);
			char* out = Align(s1, s2);
			int i = 0;
			cout << "The Align result is: ";
			while (out[i] != '\0')
			{
				if (out[i] >= 'A'&&out[i] <= 'Z')
				{
					cout << out[i];
					i++;
				}
				else break;
			}

		}
		else if (choice == 5)
		{
			cout << "Enter file name:" << endl;
			char* filename = new char[28];
			cin >> filename;
			object1.SaveSequenceToFile(filename);
		}
		else if (choice == 6)
		{
			cout << "Enter file name:" << endl;
			char* filename = new char[28];
			cin >> filename;
			object1.LoadSequenceFromFile(filename);
			//object1.Print();
		}
		else if (choice == 7)
		{
			DNA obj;
			cin >> obj;
			//obj.Print();
		}
		else if (choice == 8)
		{
		cout << object1 << endl;
		}
		else if (choice == 9)
		{
			cout << "Entering the 1st RNA....." << endl;
			RNA obj1;
			cin >> obj1;
			cout << "Entering the 2nd RNA....." << endl;
			RNA obj2;
			cin >> obj2;
			RNA obj3(obj1 + obj2);
			cout << obj3 << endl;
 }
	}
	if (choice == 3)
	{

		Protein object1;
		cin >> object1;
		cout << "Choose the operation you need to do .." << endl;
		cout << "1)Print the entered Protein" << endl;
		cout << "2)Convert from Protein to DNA" << endl;
		cout << "3) Align two Proteins" << endl;
		cout << "4)Save Protein to a file" << endl;
		cout << "5)Load another Protein from file" << endl;
		cout << "6)cin another Protein" << endl;
		cout << "7)cout Protein" << endl;
		cout << "8)Protein+Protein" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			object1.Print();
		}
		else if (choice == 2)
		{
			cout << "Entering the the big DNA....." << endl;
			DNA obj;
			cin >> obj;
			int l;
			DNA*out = new DNA[obj.get_length()];
			out = object1.GetDNAStrandsEncodingMe(obj, l);
			for (int i = 0; i < l; i++)
			{
				out[i].BuildComplementaryStrand();
				cout << out[i] << endl;
			}
		}
		else if (choice == 3)
		{
			cout << "Entering the 1st Protein....." << endl;
			Protein obj1;
			cin >> obj1;
			Sequence* s1 = new Protein(obj1);
			cout << "Entering the 2nd Protein....." << endl;
			Protein obj2;
			cin >> obj2;
			Sequence* s2 = new Protein(obj2);
			char* out = Align(s1, s2);
			int i = 0;
			cout << "The Align result is: ";
			while (out[i] != '\0')
			{
				if (out[i] >= 'A'&&out[i] <= 'Z')
				{
					cout << out[i];
					i++;
				}
				else break;
			}

		}
		else if (choice == 4)
		{
			cout << "Enter file name:" << endl;
			char* filename = new char[28];
			cin >> filename;
			object1.SaveSequenceToFile(filename);
		}
		else if (choice == 5)
		{
			cout << "Enter file name:" << endl;
			char* filename = new char[28];
			cin >> filename;
			object1.LoadSequenceFromFile(filename);
			//object1.Print();
		}
		else if (choice == 6)
		{
			Protein obj;
			cin >> obj;
			//obj.Print();
		}}}
