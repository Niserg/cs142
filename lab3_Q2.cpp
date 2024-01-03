#include <iostream>

using namespace std;

class node
{
 public:
 int datum;
 node * next;
 node(int);
 node();
};
 
 node :: node()
 {
	next = NULL;
 }
 node :: node(int newData)
 {
	next = NULL;
  	datum = newData;
 }


class circularLinkedList
{
 node * head;
 public: 
 void insert(int);
 void insertAt(int, int);
 void deleteNode();
 void deleteNodeAt(int);
 void display();
 void countItems();
 circularLinkedList();
};
 
 circularLinkedList :: circularLinkedList()
 {
 	head = NULL;
 }

 void circularLinkedList :: insert( int datum)
 {	
	node * temp = new node(datum);
	node * check1 = head;
  	if(check1 == NULL)
	    {head = temp;   head->next = head;}
	else
	{	
	 while(check1->next != head)
	 	  check1 = check1->next;
	 check1->next = temp;
	 temp->next = head;
	 
	}

 }
 
 void circularLinkedList :: insertAt( int datum, int pos)
 {
	node * temp = new node(datum);
	node * check2 = head;
	int count = 1;
	if(head != NULL)
      {
	while(check2->next != head)
        {
	  check2 = check2->next;
	  count++;
          if(count == pos-1) break;
	}
	if(count < pos-1)
	{
	 cout << "\nThe list has only "<< count << " number of elements. Cannot add at specified position.\n";
	 delete temp;
	}
 	else
	{
	 temp->next = check2->next;
	 check2->next = temp;
	}
	 	
      }
	else
	 insert(datum);
 }


 void circularLinkedList :: deleteNode()
 {
	node * check3 = head;
	if(check3 == NULL) cout << "\nUnderflow!!\n";
	else if(check3->next == head) head = NULL;
	else 
	{ while(check3->next->next != head)
	   check3 = check3->next;
	  check3->next = check3->next->next;
	  check3->next->next = NULL;
	}	
 }


 void circularLinkedList :: deleteNodeAt(int pos)
 {
 	int count = 1;
	node * check4 = head;
	while(check4->next != head)
	{
	 check4 = check4->next;
	 count++;
	 if(count == pos-1) break;
	}
	if(count < pos)	cout << "\nThe list has only "<< count << " number of elements. There is no node at the specified position.\n";
	else
	{
	 check4->next = check4->next->next;
	 check4->next->next = NULL;
	}
	
 }

 void circularLinkedList :: display()
 {
	node * check5 = head;
	cout << "\n";
     if(check5 != NULL)
 	do
	{
	 cout << check5->datum <<" -> ";
	 check5 = check5->next;
	}while(check5 != head);
     else 
	cout << "\nUNDERFLOW !!\n";
 }
 
 void circularLinkedList :: countItems()
 {
	node * check = head;
        int count = 1;
	do
	{
         count++;
	 check = check->next;
        }while(check != head);
	cout << "\nThe doubly linked list has "<< count <<" elements.\n";
 }


int main()
{
 int choice1, choice2, data, pos;
 char ch = 'y';
 circularLinkedList object;
 cout << "\nProgram to implement Circular Linked List using C++.\n";
 cout << "A Circular linked list has been created.";
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
