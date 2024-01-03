#include <iostream>

using namespace std;

class node
{                                                           // list has to be doubly linked
 public:
 int datum;
 node * next, * prev;
 node(int);
 node();
};
 
 node :: node()                                           // constructor overloading to allow initialization in different ways
 {
	next = prev = NULL;
 }
 node :: node(int newData)
 {
	next = prev = NULL;
  	datum = newData;
 }


class doublyLinkedList
{
 node * head, * tail;
 public: 
 void insert(int);
 void insertAt(int, int);
 void deleteNode();
 void deleteNodeAt(int);
 void display();
 void countItems();
 doublyLinkedList();
};
 
 doublyLinkedList :: doublyLinkedList()
 {
 	head = tail = NULL;
 }

 void doublyLinkedList :: insert( int datum)
 {	
	node * temp = new node(datum);
  	if(head == NULL)                                            //if there is no node in list
	    head = tail = temp;
	else
	{	
	tail->next = temp;
  	temp->prev = tail;
	temp->next = NULL;
	tail = temp;
	}

 }
 
 void doublyLinkedList :: insertAt( int datum, int pos)
 {
	node * temp = new node(datum);
	node * check = head;                              // check will help to reach at position specified
	int count = 1;
	while(check != NULL)
        {
	  check = check->next;
	  count++;
          if(count == pos-1) break;                        // stop before the place of node insertion
	}
	if(count < pos-1)
	{
	 cout << "\nThe list has only "<< count << " number of elements. Cannot add at specified position.\n";
	 delete temp;
	}
 	else
	{
	 temp->prev = check;
	 temp->next = check->next;
	 if(temp->next != NULL) temp->next->prev = temp;          // to avoid the case when check is the last node
 	 if(check != NULL) check->next = temp;                   /* to avoid the case when there is only one element head and
		                                                  we want insertion at 2nd position*/
	}	
 }


 void doublyLinkedList :: deleteNode()
 {
	if(head == NULL) cout << "\nUnderflow!!\n";
	else 
	{ 
	 tail = tail->prev;
	 tail->next = NULL;
	}

 }

 void doublyLinkedList :: deleteNodeAt(int pos)
 {
 	int count = 1;
	node * check = head;
	while(check != NULL)                                // to reach one node before the node to be deleted
	{
	 check = check->next;
	 count++;
	 if(count == pos) break;
	}
	if(count < pos)	cout << "\nThe list has only "<< count << " number of elements. There is no node at the specified position.\n";
	else
	{
	 if(check != NULL) check->prev->next = check->next;                           // to avoid the case when check is the only element
		else head = NULL;
	 if(check->next != NULL) check->next->prev = check->prev;         // to avoid the case when it is the last element that is to be deleted
	}
	
 }

 void doublyLinkedList :: display()
 {
	node * check = head;
	cout << "\n";
 	while(check != NULL)
	{
	 cout << check->datum <<" -> ";
	 check = check->next;
	}
 }
 
 void doublyLinkedList :: countItems()
 {
	node * check = head;
        int count = 0;
        while(check != NULL)
        {
         count++;
	 check = check->next;
        }
	cout << "\nThe doubly linked list has "<< count <<" elements.\n";
 }


int main()
{
 int choice1, choice2, data, pos;
 char ch = 'y';
 doublyLinkedList object;
 cout << "\nProgram to implement Doubly Linked List using C++.\n";
 cout << "A doubly linked list has been created.";
while(ch == 'y'||ch == 'Y') 
{
   cout << "Choose a task among these :";
   cout << "\n\t1.\tInsert an element.\n\t2.\tDelete an element.\n\t3.\tDisplay all elements in linked list.\n\t4.\tCount all elements in linked list.\n";
   cin >> choice1;
 
 switch(choice1)
 {
  case 1 : cout << "\nGive a value to be stored in the new element :";
 	   cin >> data;
 	   cout <<"\n1.\tInsert at the end of the linked list.\n2.\tInsert at a specified position."<<"\nEnter your choice :\n";
 	   cin >> choice2;
            switch(choice2)
 		{
 		 case 1 : object.insert(data);            
 			  break;
 		 case 2 : cout << "\nEnter the position at which it is to be inserted :";
 			  cin >> pos;
 			  object.insertAt(data, pos);
               		  break;
 		 default: cout << "\nWrong choice!!";
 		}
            break;
 
  case 2 : cout <<"\n1.\tDelete at the end of the linked list.\n2.\tDelete at a specified position."<<"\nEnter your choice :\n";
           cin >> choice2;
            switch(choice2)
                 {
                  case 1 : object.deleteNode();
                          break;
                  case 2 : cout << "\nEnter the position at which it is to be deleted :";
                          cin >> pos;
                          object.deleteNodeAt(pos);
                          break;
                  default: cout << "\nWrong choice!!";
                 }
 	   break;
  case 3 : cout << "Elements in the linked list have :";
 	   object.display();
 	   break;
  case 4 : object.countItems();
 	   break;
  default: cout << "\nWrong choice !!";
 	   break;
 
 
 }
 cout << "\npress 'Y' to go back, 'N' otherwise.\n";
 cin >> ch;
}
  
return 0;
}
