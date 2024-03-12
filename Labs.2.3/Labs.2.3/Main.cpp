#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

struct indexlist
{
	int num;
	int index;
	indexlist* left;
	indexlist* right;
};

struct matrix
{
	indexlist* line;
	matrix* dawn;
};

void add(indexlist** head, indexlist** teil)
{

	indexlist* temp = new indexlist;
	temp->num = rand() % 2;
	if ((*head) != NULL)
	{
		temp->right = (*teil);
		temp->left = NULL;
		(*teil)->left = temp;
		temp->index = (*teil)->index + 1;
		(*teil) = temp;
	}
	else
	{
		(*head) = temp;
		(*teil) = temp;
		temp->left = NULL;
		temp->right = NULL;
		temp->index = 1;
	}
}

void init(indexlist** head, indexlist** teil, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		add(head, teil);
	}

	indexlist* temp = new indexlist;
	temp->num = 1 + rand() % 1;
	temp->right = (*teil);
	temp->left = NULL;
	(*teil)->left = temp;
	temp->index = (*teil)->index + 1;
	(*teil) = temp;

}

void show(indexlist* head, indexlist* teil)
{
	while (head)
	{
		cout << "[ " << head->index << ", " << head->num << " ]";
		head = head->left;
	}
	cout << endl;
}

void dellist(indexlist** head, indexlist** teil)
{
	while (*head)
	{
		indexlist* temp = (*head);
		(*head) = (*head)->left;
		delete temp;
		temp = NULL;
	}
}

void shortlist(indexlist** head, indexlist** teil)
{
	indexlist* start = (*head);
	while (*head)
	{
		if ((*head)->num == 0)
		{
			indexlist* temp = (*head);
			if ((*head)->right == NULL)
			{
				(*head) = (*head)->left;
				(*head)->right = NULL;
				start = (*head);
			}
			else
			{
				(*head)->left->right = (*head)->right;
				(*head)->right->left = (*head)->left;
				(*head) = (*head)->left;
			}
			delete temp;
			continue;
		}
		(*head) = (*head)->left;
	}
	(*head) = start;
}// from a full list to a short list (saport function for a task 1)

void longlist(indexlist** head, indexlist** teil)
{
	indexlist* start = (*head);
	while (*head)
	{
		if ((*head)->left != NULL and (((*head)->index) + 1) != ((*head)->left->index))
		{
			indexlist* temp = new indexlist;
			temp->num = 0;

			if ((*head)->right == NULL and ((*head)->index) > 1)
			{
				temp->index = 1;
				temp->left = (*head);
				(*head)->right = temp;
				(*head) = temp;
				start = temp;
			}
			else
			{
				temp->index = (*head)->index + 1;

				temp->left = (*head)->left;
				temp->right = (*head);
				(*head)->left->right = temp;
				(*head)->left = temp;
				(*head) = temp;

			}
			continue;
		}
		(*head) = (*head)->left;
	}
	(*head) = start;
}// // from a sparse list to a complete list, (task 1)

void initmat(matrix** headmat, matrix** teilmat, int size)
{
	for (int i = 0; i < size; i++)
	{
		matrix* tempmat = new matrix;
		indexlist* head = NULL;
		indexlist* teil = head;
		init(&head, &teil, size);
		shortlist(&head, &teil);
		tempmat->line = head;
		if ((*headmat) == NULL)
		{
			(*headmat) = tempmat;
			(*teilmat) = (*headmat);
		}
		else
		{
			(*teilmat)->dawn = tempmat;
			(*teilmat) = tempmat;
		}
		(*teilmat)->dawn = NULL;
	}
}// create matrix for a size*size (part of task 2)

void showmat(matrix* headmat)
{
	while (headmat)
	{
		while (headmat->line)
		{
			cout << "[ " << headmat->line->index << ", " << headmat->line->num << " ]";
			headmat->line = headmat->line->left;
		}
		cout << endl;
		headmat = headmat->dawn;
	}
}// showing a your matrix (2 part for a tesk 2)

int main()
{
	srand(time(NULL));

	indexlist* head = NULL;
	indexlist* teil = head;

	cout << "task 1 your fuul list:" << endl;
	cout << "first element of [] is a index, second element is a number of list " << endl;
	init(&head, &teil, 10);
	show(head, teil);
	cout << "from full list to a short:" << endl;
	shortlist(&head, &teil);
	show(head, teil);
	cout << "from a short list to full:" << endl;
	longlist(&head, &teil);
	show(head, teil);

	matrix* headmat = NULL;
	matrix* teilmat = headmat;

	cout << "task 2 your short matrix:" << endl;

	initmat(&headmat, &teilmat, 10);
	showmat(headmat);

	cout << "and in the end I would like to say that there is a small drawback in the sorting," << endl;
	cout << "if the last element is 0, then the code breaks" << endl;
	cout << "I'm writing to you in English because for some reason my compiler doesn't work with Cyrillic" << endl;
	cout << "and longslist function have a litle problem, if the first element has an index other than 1, then adding it works strangely " << endl;

	system("pause");
}