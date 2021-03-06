#include <iostream>
using namespace std;


class Node
{
public:
	Node(int d = NULL, Node* RL = NULL, Node* LL = NULL) :data(d), Rlink(RL), Llink(LL) {}
	int data;
	Node* Rlink;
	Node* Llink;
};

int main()
{
	int Num_Data;

	Node *Header, *Y, *Temp;
	Header = new Node();
	cin >> Num_Data;
	Header->data = Num_Data;
	Header->Llink = NULL;
	Header->Rlink = NULL;

	Temp = Header;

	while (cin >> Num_Data)
	{
		Y = new Node();
		Y->data = Num_Data;
		Y->Llink = Temp;
		Y->Rlink = NULL;
		Temp->Rlink = Y;
		Temp = Temp->Rlink;
	}

	cout << "Scrolling Node From Llink :" << endl;
	while (Temp->Llink != NULL)
	{
		cout << Temp->data << "->";
		Temp = Temp->Llink;
	}
	cout << Temp->data << "->" << endl;

	cout << "Scrolling Node From Llink :" << endl;
	while (Temp->Rlink != NULL)
	{
		cout << Temp->data << "->";
		Temp = Temp->Rlink;
	}
	cout << Temp->data << "->" << endl;
}
