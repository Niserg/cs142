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

class StackLL
{
 node * top;
 public:
 void pop();
 void push(int);
 void display();
 StackLL();
};
 
 StackLL :: StackLL()
 {
  top = NULL;
 }

 void StackLL :: pop()
 {
  if(top != NULL)
  {
   node * tmp2 = top;                                     // temporary pointer to top
   top = top->next;                                   
   tmp2->next = NULL;                                     // detach the temporary variable (break all links)
  }
  else cout << "\nNO ELEMENT TO DELETE !!\n";
 }


 void StackLL :: push(int data)
{
  node * tmp = new node(data);
  tmp->next = top;                                           // make the link between existing list and new element
  top = tmp;                                                // this would work even if top = NULL initially
};


 void StackLL :: display()
{
  node * check = top;
  while(check != NULL)                                       // display till you reach the last element
  {
   cout << check->datum << "  ,";
   check = check->next;
  }
  cout << "\tNOthing more to display.\n";
};

 

 int main()
{
 char ch;
 int choice, datum;
 cout << "\nProgram to implement Stacks using Linked List in C++.\n";
 StackLL obj;
 cout << "\nAn empty linked list has been created.";
do{
   cout << "\nChoose among the following:\n\t1.Push an element\n\t2.Pop an element.\n\t3.Display elements.\t\t:";
   cin >> choice;
    switch(choice)
   {
    case 1 :  cout << "\nEnter the data (integer type) to be stored in the new element:   ";
              cin >> datum;
 	      obj.push(datum);
	      break;
    case 2 :  cout << "\nDeleting the top most element.";  
	      obj.pop();
	      break; 
    case 3 :  cout << "\nDisplaying the elements :"; 
	      obj.display();
	      break;
    default:  cout << "\n Wrong Choice !!\n";
              break;
   }
   cout << "\nWanna continue?   (answer y or Y for yes) : ";
   cin >> ch;
   cout << endl;
  }while(ch =='y'||ch == 'Y');
 		 
  return 0;
}
