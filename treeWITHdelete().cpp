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
};

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
 node* searchNode(int);
 void displayNode(node*);
 int displayTree(node *);
 int displayTree();
 void deleteNode(int);
};

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
	  check->right = temp;
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
 cout << ((check->left == NULL)? "NO" : "YES");
 cout << "\nRight child :\t";
 cout << ((check->right == NULL)? "NO" : "YES");
 cout << "\nParent :\t";
 cout <<((check->parent == NULL)? "NO" : "YES");
 cout << endl;
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
	displayNode(check);
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
 node * check = searchNode(dt);
 node * largest = NULL;

 if(check == NULL) cout << "\nERROR! The node does not exists.";

 else 
 {
   if(check->right == NULL && check->left == NULL)
   {
      if(check->parent != NULL)
      {
	if(check->parent->left == check)
	check->parent->left = NULL;
	else 
	check->parent->right = NULL;
      } 
      else
	root = NULL;
      
      check->parent = NULL;
   }
  
   else if(check->right == NULL)
   {
      if(check->parent != NULL)
      {
        if(check->parent->left == check)
         check->parent->left = check->left;
	else
         check->parent->right = check->left;
	
        check->left->parent = check->parent;
      }
      else 
	 root = check->left;

      check->left = check->parent = NULL;

   }

   else if(check->left == NULL)
   {
      if(check->parent != NULL)
      {
        if(check->parent->left == check)
         check->parent->left = check->right;
        else
         check->parent->right = check->right;
        
        check->right->parent = check->parent;
      }
      else 
	root = check->right;
 
      check->right = check->parent = NULL;
   }
   else 
     {
	largest = root;

       while(largest->right != NULL)
                 largest = largest->right;
        


       largest->parent->right = largest->left;
       if(largest->left != NULL) largest->left->parent = largest->parent;
                  
       if(check->parent != NULL)
       {
         if(check->parent->left == check)
         {
           check->parent->left = largest;
	   largest->parent = check->parent->left;
         }
         else
         {
           check->parent->right = largest;
           largest->parent = check->parent->right;
	 }
         
       }
       else
         root = largest;
       
       largest->left = check->left;
       largest->right = check->right;   
       
     }
 }  	
}

int binaryTree :: displayTree(node* temp)
{
 int flag = 0;
 if(temp == NULL) return flag;

   flag = displayTree(temp->left);
   cout << "  " << temp->data << "  ";
   flag = displayTree(temp->right);
 	
 return 1; 
}


int binaryTree :: displayTree()
{
  return displayTree(root);
}


int main()
{
 int data, choice;
 char ch ='y';
 node* check;
 binaryTree T;
 cout << "\nProgram to implement tree data structure.\n";
 do{
	cout << "\nChoose among the following tasks :\n\t1.Insert a node\n\t2.Search for a node\n\t3.Delete a node\n\t4.Display Tree\n\t5.Exit\n";
	cin >> choice;
	switch(choice)
	{
 	 case 1 : cout << "\nEnter an integer element to insert with :\t";
	  	  cin >> data;
	   	  T.insertNode(data);
		  break;
 	 case 2 : cout << "\nEnter some integer to search for :\t";
		  cin >> data;
		  check = T.searchNode(data);
		  break;  
	 case 3 : cout << "\nWhich node do you wanna delete? Enter the integer data it has :\t";
		  cin >> data;
		  T.deleteNode(data);
		  break;
	 case 4 : data = T.displayTree();
		  if(data == 0) cout << "NO TREE!!";
		  break;
	 case 5 : break;
	 default: cout << "\nWrong choice.";
	  	  break;
	}
	
	cout << "\nWanna repeat? ('y' for yes)\t:";
	cin >> ch;
 } while(ch == 'y' || ch == 'Y');
 return 0;
}
