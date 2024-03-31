#include<iostream>
#include<time.h>
using namespace std;

struct node
{
	int num;
	node* left;
	node* right;
};
node* createNode(int number)
{
	node* newnode = new node;
	newnode->num = number;
	newnode->left = newnode->right = NULL;
	return newnode;
}

void addNode(node* root, int number)
{
	if (number < root->num)
	{
		if (root->left)
		{
			addNode(root->left, number);
		}
		else
		{
			root->left = createNode(number);
		}
	}
	else
	{
		if (root->right)
		{
			addNode(root->right, number);
		}
		else
		{
			root->right = createNode(number);
		}
	}
}

void showNode(node* root)
{
	if (!root)
	{
		return;
	}
	showNode(root->left);
	cout << root->num << "; ";
	showNode(root->right);
}

bool searchNum(node* root,int number,int* level)
{
	if (!root)
	{
		return false;
	}
	(*level)++;
	bool check = false;

	if (root->num == number)
		return true;
	else
	{
		if (root->num < number)
		{
			check = searchNum(root->right, number, level);
		}
	}

	if (!check)
	{
		(*level)--;
		cout << "deLevel  " << endl;
	}

}

int main()
{
	srand(time(NULL));
	node* root = new node;
	root->num = rand() % 10;
	root->left = root->right = NULL;

	for (int i = 0; i < 20; i++)
	{
		addNode(root, rand() % 10);
	}
	showNode(root);

}
