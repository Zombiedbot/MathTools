#include <fstream>
#include <cstdlib>
#include <iostream>
#include "headers.h"

using namespace std;


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m, val, deg;
	ListNode *h1 = nullptr, *h2 = nullptr, *ptr;
	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		fin >> val >> deg;
		h1 = insert_in(h1, val, deg);
	}
	fin >> m;
	for (int i = 0; i < m; ++i)
	{
		fin >> val >> deg;
		h2 = insert_in(h2, val, deg);
	}
	ptr = h1;
	cout << "P1: ";
	prnt(h1);
	cout << "P2: ";
	prnt(h2);
	ListNode *res_add = nullptr;
	res_add = Add(h1, h2);
	cout << "Sum: ";
	prnt(res_add);
	res_add = nullptr;
	res_add = Sub(h1, h2);
	cout << "Sub: ";
	prnt(res_add);
	ListNode *res_mul = nullptr;
	res_mul = Mul(h1, h2);
	cout << "Mul: ";
	prnt(res_mul);
	ListNode *quo = nullptr;
	ListNode *res_div = nullptr;
	Div(h1, h2, quo, res_div);
	cout << "Quo: ";
	prnt(quo);
	cout << "Rem: ";
	prnt(res_div);
	ListNode *der_res = nullptr;
	der_res = Der(h1);
	cout << "Der: ";
	prnt(der_res);
	system("pause");
	return 0;
}

