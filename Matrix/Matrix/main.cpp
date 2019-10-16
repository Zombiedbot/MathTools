#include "headers.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	RowNode *M1 = Input();
	RowNode *M2 = Input();
	RowNode *resAdd;
	RowNode *resMul;
	resAdd = Add(M1, M2);
	resMul = Mul(M1 ,M2);
	cout << "Addition result:\n";
	Output(resAdd);
	cout << "Multiplication result:\n";
	Output(resMul);
	system("pause");
}
