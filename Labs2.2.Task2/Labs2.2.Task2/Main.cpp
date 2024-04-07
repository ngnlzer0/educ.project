#include<iostream>
using namespace std;

struct list
{
	int num;
	list* left;
	list* right;
};

void Add(list** head, list** teil, int number)
{
	list* temp = new list;
	temp->num = number;
	if ((*head) != NULL)
	{
		(*teil)->left = temp;
		(*head)->right = temp;
		temp->right = (*teil);
		temp->left = (*head);
		(*teil) = temp;
	}
	else
	{
		temp->left = temp;
		temp->right = temp;
		(*head) = temp;
		(*teil) = (*head);
	}
}

void Show(list* head, list* teil)
{
	if (head == NULL)
	{
		cout << "List is empetis" << endl;
		return;
	}
	do
	{
		cout << head->num << ", ";
		head = head->left;
	} while (teil->left != head);
	cout << endl;
}

void breaks(list** headm, list** teilm, list** headd, list** teild)
{
	do
	{
		if ((*headm)->num % 2 != 0)
		{
			if ((*headm)->right != (*teild))
			{
				(*headm)->right->left = (*headm)->left;
				(*headm)->left->right = (*headm)->right;
			}
			else
			{
				(*teilm)->left = (*headm)->left;
				(*headm)->left = (*teilm);
			}
			Add(headd, teild, (*headm)->num);
		}
		(*headm) = (*headm)->left;

	} while ((*teilm)->left != (*headm));
}


int main()
{
	int arr[] = { 4, 16, 8, 37, 22, 45, 11, 5, 0, 30, 12, 29, 50, 9, 3, 18, 26, 41, 2, 7 };

	list* headm = NULL;
	list* teilm = headm;
	list* headd = NULL;
	list* teild = headd;

	for (int i = 0; i < 20; i++)
	{
		Add(&headm, &teilm, arr[i]);
	}
	Show(headm, teilm);

	breaks(&headm, &teilm, &headd, &teild);
	Show(headm, teilm);
	Show(headd, teild);
}