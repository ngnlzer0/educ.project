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
	std::cout << root->num << "; ";
	showNode(root->right);
}

bool searchNum(node* root, int number,int* level)
{
	
	if (root->num == number)
	{
		return true;
	}
	(*level)++;
	if (root->num > number && root->left != NULL)
	{
		searchNum(root->left, number, level);
	}
	else if(root->num < number && root->right != NULL)
	{
		searchNum(root->right, number, level);
	}
}

int height(node* root) 
{
	if (root == NULL) 
	{
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

void ShowNumH(node* root, int hight, int level)
{
	if (level > hight)
		return;
	if (level == hight)
	{
		std::cout << root->num << ", ";
	}
	if (root->left != NULL)
	{
		level++;
		ShowNumH(root->left, hight, level);
		level--;
	}
	if (root->right != NULL )
	{
		level++;
		ShowNumH(root->right, hight, level);
		level--;
	}
	level++;
}
int main()
{
	srand(time(NULL));
	node* root = new node;
	root->num = 7;
	root->left = root->right = NULL;

	int arr[] = {7, 13, 4, 18, 2, 11, 9, 5, 16, 3, 0, 10, 20, 8, 1, 14, 6, 17, 12, 19};
	int level = 0;

	for (int i = 0; i < 20; i++)
	{
		addNode(root, arr[i]);
	}
	showNode(root);

	std::cout << endl;

	std::cout << "what number you search ?" << endl;
	int num = 0;
	cin >> num;
	if (searchNum(root, num, &level) == true)
	{
		std::cout << "Tree have you number, and his hignt = " << level << endl;
	}
	else
		std::cout << "Tree dont have this number" << endl;
	level = 0;

	std::cout <<"Hight of this tree is a "<< height(root) << endl;
	
	std::cout << "chois hight tree" << endl;
	int hig = 0;
	cin >> hig;
	std::cout << "number in hights of you want is: ";
	ShowNumH(root, hig, 0);

	return 0;
}
