//implement a it using the functions and data (top pointer) of two stacks]

#include <iostream>

using namespace std;

class node                                              // class node
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
//************************************************************************
class StackLL                                               // class Stack
{
 node * top;
 public:
 void pop();
 void push(int);
 void display();
 void reverseStack(StackLL);
 StackLL();
};

 StackLL :: StackLL()
 {
  top = NULL;
  cout << "\nStack constructor called.";
 }


void StackLL :: pop()
 {
  if(top != NULL)
     top = top->next;
  else cout << "\nNO ELEMENT TO DELETE !!\n";
 }


 void StackLL :: push(int d)
{
  node * temp = new node(d);
  temp->next = top;
  top = temp;
}

void StackLL :: reverseStack(StackLL s)
{
 node * tmp = this->top;
 int dt;
 while(tmp != NULL)
 {
  dt = tmp->datum;
  s.push(dt);
  tmp = tmp->next;
 } 
}

 void StackLL :: display()
{
  node * check = top;
  while(check != NULL)
  {
   cout << check->datum << "  ,";
   check = check->next;
  }
  cout << "\n\tNOthing more to display.\n";
};



//*****************************************************************************


class Queue
{
 StackLL s1, s2;
 public:
 void pushQ(int);
 void popQ();
 void displayQ();
};

void Queue :: pushQ(int data)
{
 s1.push(data) ;
}

void Queue :: popQ()
{
 s1.display();
 s1.reverseStack(s2);
 cout << "\ns1 :"; s1.display();
 cout << "\ns2 :"; s2.display();
 s2.pop();
 cout << "\ns2 :";  s2.display();
 s2.reverseStack(s1);
 cout << "\ns1 :";  s1.display();
 cout << "\ns2 :";  s2.display();
}

void Queue :: displayQ()
{
 s1.display();
}

//*****************************************************************************
int main()
{
 int choice, datum;
 char ch;
 cout << "\nProgram to implement a queue using two stacks.\n";
 Queue obj;
 cout << "\nAn empty Queue has been created (it has two empty Stacks ).";
do{
   cout << "\nChoose among the following:\n\t1.Push an element\n\t2.Pop an element.\n\t3.Display elements.\t\t:";
   cin >> choice;
    switch(choice)
   {
    case 1 :  cout << "\nEnter the data (integer type) to be stored in the new element:   ";
              cin >> datum;
              obj.pushQ(datum);
              break;
    case 2 :  cout << "\nDeleting the top most element.";
              obj.popQ();
              break;
    case 3 :  cout << "\nDisplaying the elements :";
              obj.displayQ();
              break;
    default:  cout << "\n Wrong Choice !!\n";
              break;
   }
   cout << "\nWanna continue?   (answer y or Y for yes) : ";
   cin >> ch;
  }while(ch == 'y' || ch == 'Y');


return 0;
}
