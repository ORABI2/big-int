#include "Sequence.h"
#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)return a;
	else if (b > a)return b;
}
Sequence::Sequence()
{
	length = 0;
}
Sequence::Sequence(int x)
{

	length = x;

}
Sequence::Sequence(Sequence &rhs)
{
	length = rhs.length;
	seq = new char[length];
	for (int i = 0; i < length; i++)
	{
		seq[i] = rhs.seq[i];
	}
}
void Sequence::set_sequence()
{

	seq = new char[length];
	for (int i = 0; i < length; i++)
	{
		cin >> seq[i];
	}

}
Sequence::~Sequence()
{

}
void Sequence::Print()
{
	for (int i = 0; i < length; i++)
	{
		cout << seq[i] << " ";
	}
	cout << endl;
}

char* Align(Sequence* s1,Sequence* s2)
{
	int m = s1->get_length();
	int n = s2->get_length();
	char* x = new char[m];
	char* y = new char[n];
	x = s1->get_seq();
	y = s2->get_seq();

	int** L = new int *[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		L[i] = new int[n + 1];
	}

		/* Following steps build L[m+1][n+1] in bottom up fashion. Note
		   that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == 0 || j == 0)
					L[i][j] = 0;
				else if (x[i - 1] == y[j - 1])
					L[i][j] = L[i - 1][j - 1] + 1;
				else
					L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
		}

		// Following code is used to print LCS
		int index = L[m][n];

		// Create a character array to store the lcs string
		char* lcs = new char[index + 1];
		lcs[index] =' '; // Set the terminating character
		int c = 0;
		// Start from the right-most-bottom-most corner and
		// one by one store characters in lcs[]
		int i = m, j = n;
		while (i > 0 && j > 0)
		{
			// If current character in X[] and Y are same, then
			// current character is part of LCS
			if (x[i - 1] == y[j - 1])
			{
				lcs[index - 1] = x[i - 1]; // Put current character in result
				c++;
				i--; j--; index--;     // reduce values of i, j and index
			}

			// If not same, then find the larger of two and
			// go in the direction of larger value
			else if (L[i - 1][j] > L[i][j - 1])
				i--;
			else
				j--;
		}

		return lcs;

	}
istream& operator>>(istream&in, Sequence& s)
{
	s.get_sequence(in);
	return in;
}
ostream& operator<<(ostream&out, Sequence&s)
{
	s.print_sequnece(out);
	return out;
}

