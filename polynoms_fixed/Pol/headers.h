
struct ListNode // ��������� ���������� ��������
{
	double val; // �������� �����������
	int deg; // �������� �������
	ListNode *next; // ��������� �� ��������� ��������� �������� ������
};

ListNode *insert_in(ListNode *head, double val, double deg); // ������� ������� ������������� ���������� � ����. val � �������� deg � ������� � ������ ��������� head

ListNode *Add(ListNode *p1, ListNode *p2); // ������� ������� ���������� ������� ���������� �������� ��������� p1 � p2

ListNode *reverse(ListNode *p); // �������, ������� ���������� �������, � ������� ��������� ����������� � �������� �������

ListNode *Mul(ListNode *p1, ListNode *p2); //  ������� ������� ���������� ������� ���������� ��������� ��������� p1 � p2

void prnt(ListNode *p); // ������� ������ �������� � stdout

ListNode *Der(ListNode *p); // �������, ������� ���������� ������� ����������� �������� p

ListNode *Copy(ListNode *p1); // �������, ������� ������ � ������ ����� �������� p1

ListNode *Sub(ListNode *p1, ListNode *p2); // ������� ��������� �������� p1 � p2

void Div(ListNode *p1, ListNode *p2, ListNode *&quo, ListNode *&res); // ������� ������� �������� p1 �� ������� p2
// ������������� ��������� ������ �� ��������� quo - ������� � res - ������� �� �������, ��� ��� �� ����� ������� 2 �������� �����

