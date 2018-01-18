#include <iostream>

using namespace std;

class node
{
 public:
 int datum;
 node * next;
 node(int);
};

 node :: node(int i)                                  // constructor of class node
 {
	datum = i;
        next = NULL;
 }



class linkedList     
{
 node * end;
 public :
 void insertNode(int);
 void deleteNode();
 void deleteAt(int);
 void insertAt(int, int);
 void display();
 int countItems();
 linkedList() { end = NULL;}                                       // constructor of class linkedList
};

 void linkedList :: insertNode(int i)
 {
	node * newNode = new node(i);
	newNode->next = end;
	end = newNode;
 }
 
 void linkedList :: insertAt(int i, int pos)
 {	
	int size =this->countItems();                                // "this" pointer gives the memory address of the object which called the function 
	int count =1;
	node * newNode = new node(i);
	node * tmp = end;
     if((size + 1) < pos) 
	{
	 delete newNode;
	 cout << "\nThe linked list has less number of elements than position given by you.\n"; 
	}
     else{
     	while(count != (pos-1))                                          // this loop traverses the linked list to reach at element at position (pos-1) because the list is singly linked
 	 {
 	  tmp = tmp->next;
	  count++;
	 }
	  newNode->next = tmp->next; 	
	  tmp->next = newNode;
 	 }
 }

 void linkedList :: deleteNode()
 {
	if(end!=NULL) end = end->next;                              // deleting elements by breaking the link with next element
 }
 
 void linkedList :: deleteAt(int pos)
 {
	int size =this->countItems();
        int count =1;
        node * tmp = end;
     if(size < pos)
	cout << "\nUNDERFLOW \t!!!";
     else
     {
      while(count != (pos-1))
        { 
         tmp = tmp->next;
         count++;
        }
        tmp->next = tmp->next->next;                                   // deleting element by breaking the links with adjacent elements
     }
 }

 void linkedList :: display()
 {
	node * tmp = end;
        while (tmp != NULL)
	{
 	 cout << tmp->datum << " -> ";                                // display till the last element with "NULL" in "next" pointer is reached
	 tmp = tmp->next;
	}
	cout << " NULL.";
 }

 
 int linkedList :: countItems()
 {
	int cntr =0;                                                   // counter to count number of times the loop is executed
        node * tmp = end;
	while (tmp != NULL)
        {
	 cntr++;
	 tmp = tmp->next;
	}
     return cntr;
 }


int main()
{
 int choice, choice2, data, pos;
 char ch = 'y';
 cout << "\nProgram to implement Singly Linked List using C++.\n";
 linkedList L1;
 cout << "A linked list has been created.";
while(ch == 'y'||ch == 'Y') 
{
   cout  << "Choose a task among these :";
   cout << "\n\t1.\tInsert an element.\n\t2.\tDelete an element.\n\t3.\tDisplay all elements in linked list.\n\t4.\tCount all elements in linked list.\n";
   cin >> choice;
 
 switch(choice)
 {
  case 1 : cout << "\nGive a value to be stored in the new element :";
 	   cin >> data;
 	   cout <<"\n1.\tInsert at the end of the linked list.\n2.\tInsert at a specified position."<<"\nEnter your choice :\n";
 	   cin >> choice2;
            switch(choice2)
 		{
 		 case 1 : L1.insertNode(data);            
 			  break;
 		 case 2 : cout << "\nEnter the position at which it is to be inserted :";
 			  cin >> pos;
 			  L1.insertAt(data, pos);
               		  break;
 		 default: cout << "\nWrong choice!!";
 		}
            break;
 
  case 2 : cout <<"\n1.\tDelete at the end of the linked list.\n2.\tDelete at a specified position."<<"\nEnter your choice :\n";
           cin >> choice2;
            switch(choice2)
                {
                 case 1 : L1.deleteNode();
                          break;
                 case 2 : cout << "\nEnter the position at which it is to be deleted :";
                          cin >> pos;
                          L1.deleteAt(pos);
                          break;
                 default: cout << "\nWrong choice!!";
                }
 	   break;
  case 3 : cout << "Elements in the linked list have :";
 	  L1.display();
 	  break;
  case 4 : cout << "Number of elements in the list is :" << L1.countItems();
 	  break;
  default: cout << "\nWrong choice !!";
 	  break;
 
 
 }
 cout << "\npress 'Y' to go back, 'N' otherwise.\n";
 cin >> ch;
}
return 0;
}
