#include <iostream>

using namespace std;

class QueueAR
{
 int ar[50];
 int * rear, * front;                             // class QueueAR has element list and both frontand rear pointers to act as a Queue
 public:
 void push(int);
 void pop(); 
 void display();
 QueueAR();
};
 
QueueAR :: QueueAR()
{
 for(int i =0; i<50; ++i) ar[i] = 0;                        // initializing array elements with zero 
 rear = front = NULL;
}

void QueueAR :: push(int datum)
{
 if(rear != NULL)
	 rear = rear + 1;                               // if non-empty ---push the rear
 else    
	 front = rear = ar;                             // else front is the rear
 
 *rear = datum;                            // in any case----give new value to shifted rear (because it is a Queue--insertion from back)
}


void QueueAR :: pop()
{
 int * tmp = front;
 if((front != NULL) && (front != rear))    // if list has more than one element -> shift all by one step forward (as happens in queue)
	{
	 while(tmp != rear)	 
	  {
	   *tmp = *(tmp+1);
	   tmp = tmp+1;
          }
	}
 else if((front == rear)&&(front != NULL))                   // else if only one element then delete it (simple)
	{
	 *front = 0;
         front = rear = NULL;
	}
 else cout << "\n NO ELEMENT TO DELETE!!";                      // else display warning
}
 
void QueueAR :: display()
{
 int * tmp = front;
 if(rear == ar) cout << "\t"<< *rear << " is the only element.";
 else
 while(tmp != rear)                                             // display till last element if array has more than one element
	{
	 cout << *tmp << "  ,";
 	 tmp = tmp + 1;
	}
 cout << "\nNO more elements to display!!";                      // default expression ...works with "no-element array" as well 
}

//*****************************************************************************************************************


int main()
{
 int choice, datum;
 char ch;
 cout << "\nProgram to implement queue using an array.\n";
 QueueAR obj;
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
