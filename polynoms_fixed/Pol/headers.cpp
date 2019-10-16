#include "headers.h"
#include <iostream>

using namespace std;

ListNode *insert_in(ListNode *head, double val, double deg)
{
	ListNode *s = new ListNode;
	ListNode *prev = nullptr;
	ListNode *hh = head;
	s -> val = val;
	s -> deg = deg;
	s -> next = nullptr;
	while(head)
	{
		if (s -> deg > head -> deg)
		{
			if(prev)
			{
				prev -> next = s;
				s -> next = head;
				return hh;
			}
			else
			{
				s -> next = head;
				hh = s;
				return hh;
			}
		}
		else
		{
			if (s->deg < head->deg)
			{
				prev = head;
				head = head -> next;
			}
			else
			{
				head -> val = s -> val;
				delete s;
				return hh;
			}
		}
	}
	if(prev)
	{
		prev -> next = s;
		return hh;
	}
	else
	{
		head = s;
		return head;
	}


}

ListNode *Add(ListNode *p1, ListNode *p2)
{
	ListNode *res = nullptr;
	while(p1 || p2)
	{
		if (p1 && p2)
		{
			if (p1->deg == p2->deg)
				{
					if(p1->val != -1 * p2->val) res = insert_in(res, p1->val + p2->val, p1->deg);
					p1 = p1->next;
					p2 = p2->next;
				}
			else
			{
				if (p1->deg < p2->deg)
				{
					res = insert_in(res, p1->val, p1->deg);
					p1 = p1->next;
				}
				else
				{
					res = insert_in(res, p2->val, p2->deg);
					p2 = p2->next;
				}
			}
		}
		else
		{
			if(p1)
			{
				res = insert_in(res, p1->val, p1->deg);
				p1 = p1->next;
			}
			else
			{
				res = insert_in(res, p2->val, p2->deg);
				p2 = p2->next;
			}
		}
	}
	return res;
}

ListNode *reverse(ListNode *p)
{
	ListNode *h = new ListNode;
	h -> val = p -> val;
	h -> deg = p -> deg;
	h -> next = nullptr;
	p = p -> next;
	while(p)
	{
		ListNode *l = new ListNode;
		l -> val = p -> val;
		l -> deg = p -> deg;
		p = p -> next;
		l -> next = h;
		h = l;
	}
	return h;
}

ListNode *Mul(ListNode *p1, ListNode *p2)
{
	ListNode *res = nullptr;
	ListNode *h1 = p1;
	ListNode *h2 = p2;
	while(p1)
	{
		p2 = h2;
		while(p2)
		{
			res = insert_in(res, p1->val * p2->val, p1->deg + p2->deg);
			p2 = p2 -> next;
		}
		p1 = p1 -> next;
	}
	res = reverse(res);
	return res;
}

void prnt(ListNode *p)
{
	while(p)
	{
		if (p -> deg == 1)
		{
			if (p -> val != 1) cout << '('<< p -> val << ") * x "; else cout << "x ";
		}
		else if (p -> deg == 0)
		{
			if (p -> val != 0) cout << '('<< p -> val << ") ";
		}
		else
		{
			if (p -> val != 1) cout << '('<< p -> val << ") * x ^ (" << p -> deg <<") "; else cout << " x ^ (" << p -> deg <<") ";
		}
		if (p->next) cout << "+ "; else cout << '\n';
		p = p->next;
	}
}

ListNode *Der(ListNode *p)
{
	ListNode *res = nullptr;
	if(p -> deg == 0)
	{
		p = p -> next;
	}
	while(p)
	{
		if ( p->deg == 0 ) break;
		res = insert_in(res, p->val * p->deg, p->deg - 1);
		p = p->next;
	}
	return res;
}

ListNode *Copy(ListNode *p1)
{
	ListNode *p2 = new ListNode;
	ListNode *h = p2;
	while(p1)
	{
		//cout << 1;
		p2 -> val = p1 -> val;
		p2 -> deg = p1 -> deg;
		if (p1 -> next)
		{
			ListNode *h = new ListNode;
			p2 -> next = h;
		}
		else
		{
			p2 -> next = nullptr;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return h;
}



ListNode *Sub(ListNode *p1, ListNode *p2)
{
	ListNode *res = nullptr;
	while(p1 || p2)
	{
		if (p1 && p2)
		{
			if (p1->deg == p2->deg)
				{
					if(p1->val != p2->val) res = insert_in(res, p1->val - p2->val, p1->deg);
					p1 = p1->next;
					p2 = p2->next;
				}
			else
			{
				if (p1->deg < p2->deg)
				{
					res = insert_in(res, p1->val, p1->deg);
					p1 = p1->next;
				}
				else
				{
					res = insert_in(res, p2->val, p2->deg);
					p2 = p2->next;
				}
			}
		}
		else
		{
			if(p1)
			{
				res = insert_in(res, p1->val, p1->deg);
				p1 = p1->next;
			}
			else
			{
				res = insert_in(res, p2->val, p2->deg);
				p2 = p2->next;
			}
		}
	}
	return res;
}

void Div(ListNode *p1, ListNode *p2, ListNode *&quo, ListNode *&res)
{
	ListNode *l, *k;
	k = new ListNode;
	l = nullptr;
	res = Copy(p1);
	while(res && res->deg >= p2-> deg)
	{
		k->deg = res->deg - p2->deg;
		k->val = res -> val * 1.0 / p2 ->val * 1.0;
		k->next = nullptr;
		quo = insert_in(quo, k->val, k->deg);
		l = Mul(p2, k);
		//cout << ' ' << k->deg << ' ';
		ListNode *res1 = res;
		res = Sub(res1, l);
		//prnt(l);
	}
}
