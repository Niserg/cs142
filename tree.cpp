#include<iostream>

using namespace std;

class node
{
 public :
 int data;
 node * parent;
 node * left;
 node * right;
 node(int);
}

node :: node(int x =0)
{
 data = x;
 parent = left = right = NULL;
}

class binaryTree
{
 node * root;
 public:
 binaryTree();
 void insertNode(int);
 void deleteNode(int);
 node* searchNode(int);
 void displayNode(node*);
}

binaryTree :: binaryTree()
{
 root = NULL;
}

void binaryTree :: insertNode(int dt)
{
 node * temp = new node(dt);
 node * check = root;
 if(check == NULL)
	root = temp;
 else
  while(true)
  {
   if(check->data == dt)
	break;

   else if(check->data > dt)
   {
	if(check->left == NULL)
	{
   	  temp->parent = check;
	  check->left = temp;
	  break;
	}
	else
	  check = check->left;
   }

   else
   {
	if(check->right == NULL)
	{
	  temp->parent = check;
	  ckeck->right = temp;
	  break;
	}
	else
	  check = check->right;
   }
  }
}


void binaryTree :: displayNode(node * check)
{
 cout << "\nDetails :";
 cout << "\nLeft child :\t";
 cout << (check->left == NULL)? "NO" : "YES";
 cout << "\nRight child :\t";
 cout << (check->right == NULL)? "NO" : "YES";
 cout << "\nParent :\t";
 cout << (check->parent == NULL)? "NO" : "YES";
}

node* binaryTree :: searchNode(int dt)
{
 int count =0;
 node * check = root;
 if(check == NULL)
     return NULL;
 else
  while(true)
  {
   if(check->data == dt)
   {
	cout << "\nNode found at depth " << count <<".\n";
	display(check);
	return check;
   }
   else if(check->data > dt)
   {
    if(check->left == NULL)	
	{
	 cout << "\nNOT FOUND.\n";
	 return NULL;
	}
    else
	check = check->left;
   }
   else
   {
    if(check->right == NULL)
	{
 	 cout << "\nNOT FOUND.\n";
	 return NULL;
	}
    else
	check = check->right;
   }
   
   count++;
  }
}


void binaryTree :: deleteNode(int dt)
{
 node * delete_node = searchNode(dt);
 if(delete_node != NULL)
 {
  if(delete_node == NULL && delete_node == NULL)
	{
	  
 } 
 else
 cout << "\nThe specified node is not present in the tree.";
}
}



int main()
{
 int data, choice;
 char ch ='y';
 node* check;
 binaryTree T;
 cout << "\nProgram to implement tree data structure.\n";
 do{
	cout << "\nChoose among the following tasks :\n\t1.Insert a node\n\t2.Search for a node\n\t3.Delete a node\n\t4.Exit\n";
	cin >> choice;
	switch(choice)
	{
 	 case 1 : cout << "Enter an integer element to insert with :";
	  	  cin >> data;
	   	  T.insertNode(data);
		  break;
 	 case 2 : cout << "Enter some integer to search for :";
		  cin >> data;
		  check = T.searchNode(data);
		  break;
	 case 3 : cout << "\nEnter an integer element to be deleted :";
	 	  cin >> data;
	  	  T.deleteNode(data);
	 	  break;
	 case 4 : break;
	 default: cout << "\nWrong choice.";
	  	  break;
	}
	
	cout << "Wanna repeat? ('y' for yes)\t:";
	cin >> ch;
 while(ch == 'y' || ch == 'Y');
 return 0;
}

