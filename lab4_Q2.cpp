#include <iostream>

using namespace std;

class node
{
 public:
 int datum;
 node * next;
 node(int);
};

 node :: node(int data)
 {
  next = NULL;
  datum = data;
 }

class QueueLL
{
 node * front, * rear;
 public:
 QueueLL();
 void pop();
 void push(int); 
 void display();
};

 QueueLL :: QueueLL()                                 // constructor for class Queue ensures that pointers are initialized
 {
  front = rear = NULL;
 }

 void QueueLL :: push(int datum)
 {
  node * temp = new node(datum);
  if(rear != NULL) rear->next = temp;               // if list is non-empty add from behind
  else front = temp;
  rear = temp;                                      // in any case "rear = temp" is required
 }

 void QueueLL :: pop()
 {
  if(front != NULL)
  {
   node * temp2 = front;
   front = front->next;
   temp2->next = NULL;                                  // breaking every link of the element to be deleted 
  }
  else cout << "\nCannot delete since no element.\n";
 }

 void QueueLL :: display()
 {
  node * check = front;
  while(check != NULL)                               // display till you reach the end of the list
  {
   cout << check->datum << "  ,";
   check = check->next;
  }
  cout << "\nNOthing MORE TO DISPLAY.\n";
}
 

int main()
{
 int choice, datum;
 char ch;
 QueueLL obj;
 cout << "\nProgram to implement Queue using linked list.\n An empty linked list has been created ....";
 do
  {
   cout << "Choose among the following :\n\t1.Push\n\t2.Pop\n\t3.Display from front.\n";
   cin >> choice;
   switch(choice)
   {
    case 1 : cout << "\nEnter an integer value for new element.\t:";
   	     cin >> datum;
 	     obj.push(datum);
  	     break;
    case 2 : cout << "\nDeleting an element from front end ....";
   	     obj.pop();
  	     break;
    case 3 : obj.display();
 	     break;
    default : cout << "\nWrong choice!!";
   }
 
   cout << "\nWanna do more?\tenter 'Y' or 'y' for yes\t:";
   cin >> ch;
  }while(ch == 'y'||ch == 'Y');

 
 return 0;
} 
