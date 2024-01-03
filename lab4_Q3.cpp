#include <iostream>

using namespace std;

class StackAR
{
 int ar[50];                                       // class StackAR has array both array and pointer to point to starting position 
 int * top;
 public:
 void pop();
 void push(int);
 void display();
 StackAR();
};

 StackAR :: StackAR()
 {
  for(int i=0; i<50; ++i) ar[i] = 0;                // initializing every element with zero 
  top = NULL;
 }


 void StackAR :: push(int data)
 {
   if(top != NULL)
      	 top = top+1;                         // shift top backwards in the array ---it is a stack
   else
 	 top = ar;
   
   *top = data;                            // in any case value is assigned to the shifted (new) top
 }


 void StackAR :: pop()
 {
    if((top != NULL) && (top != ar))
 	{
 	 *top = 0;
	 top = top-1;                         // shift the top to forward while deleting----it is stack
 	}
    else if(top == ar)
           {
	    top = NULL;
	    cout << "\nList is now empty.";
	   }
    else cout << "\nList is already empty!!\n";
 }

 void StackAR :: display()
 {
  int * tmp = ar;
  if(top != NULL)
  while(tmp != (top+1))                         // display till last element
  {
   cout << *ar << " ,";
   tmp = tmp + 1;
  }
  cout << "\nNothing more to display.";
 }

    
 
int main()
{
 int choice, datum;
 char ch;
 cout << "\nProgram to implement stack using arrays.";
 StackAR obj;
 cout << "\nAn empty array has been created.";
do{
   cout << "\nChoose among the following:\n\t1.Push an element\n\t2.Pop an element.\t\t";
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
