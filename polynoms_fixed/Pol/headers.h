
struct ListNode // структура слогаемого полинома
{
	double val; // значение коэфициента
	int deg; // значение степени
	ListNode *next; // указатель на следующее слогаемое степенью меньше
};

ListNode *insert_in(ListNode *head, double val, double deg); // функция вставки произвольного слогаемого с коэф. val и степенью deg в полином с первым слогаемым head

ListNode *Add(ListNode *p1, ListNode *p2); // функция которая возвращает полином результата сложения полиномов p1 и p2

ListNode *reverse(ListNode *p); // функция, которая возвращает полином, в котором слогаемые расположены в обратном порядке

ListNode *Mul(ListNode *p1, ListNode *p2); //  функция которая возвращает полином результата умножения полиномов p1 и p2

void prnt(ListNode *p); // функция вывода полинома в stdout

ListNode *Der(ListNode *p); // функция, которая возвращает полином производной полинома p

ListNode *Copy(ListNode *p1); // функция, которая создаёт в памяти копию полинома p1

ListNode *Sub(ListNode *p1, ListNode *p2); // функция вычетания полинома p1 и p2

void Div(ListNode *p1, ListNode *p2, ListNode *&quo, ListNode *&res); // функция деления полинома p1 на полином p2
// дополнительно принимает ссылки на аргументы quo - частное и res - остаток от деления, так как не может аернуть 2 полинома сразу

