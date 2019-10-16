#include "headers.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
 
RowNode *insert(RowNode *Matr, int val, int numRow, int numCol)
{
	/*
	Вставка происходит посредством единоразового прохода
	по списку строк до нужной нам строки(если таковой нету -
	создаем её), и вызова функции вставки в строку
	*/
	RowNode *prev = nullptr;
	RowNode *head = Matr;
	while (Matr && Matr -> num < numRow)
	{
		prev = Matr;
		Matr = Matr -> nextRow;
	}
	if (prev == nullptr)
	{
		if (Matr -> num != numRow)
		{
			RowNode *newRow = new RowNode; 
			newRow -> nextRow = Matr;
			newRow -> num = numRow;
			Node *newEl = new Node;
			newEl -> next = nullptr;
			newEl -> num = numCol;
			newEl -> val = val;
			newRow -> nextNode = newEl;
			head = newRow;
		}
		else
		{
			insertInRow(Matr, val, numCol);
		}
	}
	else if (!Matr)
	{
		RowNode *newRow = new RowNode; 
		newRow -> nextRow = nullptr;
		newRow -> num = numRow;
		prev -> nextRow = newRow;
		Node *newEl = new Node;
		newEl -> next = nullptr;
		newEl -> num = numCol;
		newEl -> val = val;
		newRow -> nextNode = newEl;
	}
	else
	{
		if (Matr -> num != numRow)
		{
			RowNode *newRow = new RowNode; 
			newRow -> nextRow = Matr;
			newRow -> num = numRow;
			Node *newEl = new Node;
			newEl -> next = nullptr;
			newEl -> num = numCol;
			newEl -> val = val;
			newRow -> nextNode = newEl;
			prev -> nextRow = newRow;
		}
		else
		{
			insertInRow(Matr, val, numCol);
		}
	}
	return head;
}

void insertInRow(RowNode *row, int val, int numCol)
{
	/*
	Вствка происходит посредством полного прохода
	по списку элементов строки до нужного нам элемента.
	Если нету - добавляем, иначе меняем его значение на новое
	*/
	Node *prev = nullptr;
	Node *cur = row -> nextNode;
	while(cur && cur -> num < numCol)
	{
		prev = cur;
		cur = cur -> next; 
	}
	if (!cur)
	{
		Node *newEl = new Node;
		newEl -> val = val;
		newEl -> num = numCol;
		newEl -> next = nullptr;
		prev -> next = newEl;
	}
	else if (!prev)
	{
		if (cur -> num == numCol) return;
		Node *newEl = new Node;
		newEl -> val = val;
		newEl -> num = numCol;
		newEl -> next = cur;
		row -> nextNode = newEl;
	}
	else
	{
		if (cur -> num == numCol) return;
		Node *newEl = new Node;
		newEl -> val = val;
		newEl -> num = numCol;
		newEl -> next = cur;
		prev -> next = newEl;
	}
}


RowNode *Add(RowNode *Matr1, RowNode *Matr2)
{
	/*
	С помощью операции merge производим слияние срок,
	при совпадении номеров строк - таким же обрахом слияем эти 2 строки.
	При совпадении номеров столбцов элементов в строке - суммируем их значения.
	*/
	RowNode *res = nullptr;
	RowNode *head = nullptr;
	while (Matr1 || Matr2)
	{
		if (Matr1 && Matr2 && Matr2 -> num == Matr1 -> num)
		{
			RowNode *newRow = new RowNode;
			newRow -> num = Matr2 -> num;
			newRow -> nextNode = nullptr;
			newRow -> nextRow = nullptr;
			if (res) res -> nextRow = newRow; 
				else head = newRow;
			res = newRow;
			Node *newHead = nullptr;
			Node *el1 = Matr1 -> nextNode;
			Node *el2 = Matr2 -> nextNode;
			Node *res1 = nullptr;
			while (el1 || el2)
			{
				if (el1 && el2 && el1 -> num == el2 -> num)
				{
					Node *newEl = new Node;
					newEl -> num = el1 -> num;
					newEl -> next = nullptr;
					newEl -> val = el1 -> val + el2 -> val;
					if (res1) res1 -> next = newEl; else newHead = newEl;
					res1 = newEl;
					el1 = el1 -> next;
					el2 = el2 -> next;
				}
				else if (!el1 || (el2 && el1 -> num > el2 -> num) )
				{
					Node *newEl = new Node;
					newEl -> num = el2 -> num;
					newEl -> next = nullptr;
					newEl -> val = el2 -> val;
					if (res1) res1 -> next = newEl; else newHead = newEl;
					res1 = newEl;
					el2 = el2 -> next;
				}
				else
				{
					Node *newEl = new Node;
					newEl -> num = el1 -> num;
					newEl -> next = nullptr;
					newEl -> val = el1 -> val;
					if (res1) res1 -> next = newEl; else newHead = newEl;
					res1 = newEl;
					el1 = el1 -> next;
				}
			}
			res -> nextNode = newHead;
			Matr1 = Matr1 -> nextRow;
			Matr2 = Matr2 -> nextRow;
		}
		else if ( !Matr1 || (Matr2 && Matr1 -> num > Matr2 -> num) )
		{
			RowNode *newRow = new RowNode;
			newRow -> num = Matr2 -> num;
			newRow -> nextNode = Matr2 -> nextNode;
			newRow -> nextRow = nullptr;
			if (res) res -> nextRow = newRow; else head = newRow;
			res = newRow;
			Matr2 = Matr2 -> nextRow;
		}
		else
		{
			RowNode *newRow = new RowNode;
			newRow -> num = Matr1 -> num;
			newRow -> nextNode = Matr1 -> nextNode;
			newRow -> nextRow = nullptr;
			if (res) res -> nextRow = newRow; else head = newRow;
			res = newRow;
			Matr1 = Matr1 -> nextRow;
		}
	}
	return head;
}

RowNode *Trans(RowNode *Matr)
{
	/*
	Создается новая матрица, и полным проходом по 
	исходной матрице для каждого элемента вызывается фунция вставки 
	в новую матрицу с поменяными местами номерами строки и столбца элемента
	*/
	Node *h = Matr -> nextNode;
	RowNode *res = new RowNode;
	Node *h1 = new Node;
	res -> num = h -> num;
	res -> nextRow = nullptr;
	res -> nextNode = h1;
	h1 -> val = h -> val;
	h1 -> num = Matr -> num;
	h1 -> next = nullptr;
	h = h -> next;
	while (Matr)
	{
		if (!h) h = Matr -> nextNode;
		int Col = Matr -> num;
		while(h)
		{
			res = insert(res, h -> val, h -> num, Col);
			h = h -> next;
		}
		Matr = Matr -> nextRow;
	}
	return res;
}

RowNode *Mul(RowNode *Matr1, RowNode *Matr2)
{
	Matr2 = Trans(Matr2);
	RowNode *Head2 = Matr2;
	RowNode *res = nullptr;
	Node *el1;
	Node *el2;
	while (Matr1)
	{
		while (Matr2)
		{
			el1 = Matr1 -> nextNode;
			el2 = Matr2 -> nextNode;
			int sum = 0;
			while (el1 || el2)
			{
				if (el1 && el2 && el1 -> num == el2 -> num)
				{
					sum += (el1 -> val) * (el2 -> val);
					el1 = el1 -> next;
					el2 = el2 -> next;
				}
				else if (!el1 || (el2 && el1 -> num > el2 -> num) )
				{
					el2 = el2 -> next;
				}
				else
				{
					el1 = el1 -> next;
				}
			}
			if (sum) 
			{
				if (res) res = insert(res, sum, Matr1 -> num, Matr2 -> num); else
				{
					res = new RowNode;
					Node *newEl = new Node;
					res -> num = Matr1 -> num;
					res -> nextNode = newEl;
					res -> nextRow = nullptr;
					newEl -> val = sum;
					newEl -> num = Matr2 -> num;
					newEl -> next = nullptr;
				}
			}
			Matr2 = Matr2 -> nextRow;
		}
		Matr2 = Head2;
		Matr1 = Matr1 -> nextRow;
	}
	return res;
}

RowNode *Input()
{
	/*
	Функция ввода матрицы из файла input.txt
	*/
	RowNode *Matr = new RowNode;
	Node *newEl = new Node;
	int num, val, row, col;
	fin >> num;
	fin >> val >> row >> col;
	Matr -> num = row;
	Matr -> nextRow = nullptr;
	Matr -> nextNode = newEl;
	newEl -> num = col;
	newEl -> val = val;
	newEl -> next = nullptr;
	for (int i = 1; i < num; ++i)
	{
		fin >> val >> row >> col;
		Matr = insert(Matr, val, row, col);
	}
	return Matr;
}


void Output(RowNode *Matr)
{
	/*
	Вывод в консоль списком элементов, где по порядку записаны
	значение, номер строки, номер столбца
	*/
	int rowNum;
	Node *curEl;
	while (Matr)
	{
		rowNum = Matr -> num;
		curEl = Matr -> nextNode;
		while (curEl)
		{
			cout << curEl -> val << ' ' << rowNum << ' ' << curEl -> num << '\n';
			curEl = curEl -> next;
		}
		Matr = Matr -> nextRow;
	}
}

int getSize(RowNode *matrix)
{
	int numRows = 0, numCols = 0, size = 0;
	Node *node;
	while(matrix)
	{
		numRows = matrix->num;
		numCols = 0;
		node = matrix->nextNode;
		while(node)
		{
			numCols = node->num;
			node = node->next;
		}
		size = max(numCols, size);
	    matrix = matrix->nextRow;
	}
	size = max(numRows, size);
	return size;
}