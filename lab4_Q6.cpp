#include <iostream>	
#include <string.h>
#include <cstdio>

using namespace std;
 
class node
{
 public:
 char name[20];
 float phno;
 char description[50];
 node * next;
 node(float, char*, char*);
};

 node :: node(float mbno, char * nm, char * dsc)
 {
  next = NULL;
  phno = mbno;
  strcpy(name, nm);
  strcpy(description, dsc);
 }

//***************************************************************************************************

class QueueLL
{
 node * front, * rear;
 public:
 QueueLL();
 void pop();
 void push(float, char*, char*);
 void display();
 void insertAtTop(float, char*, char*);
};

 QueueLL :: QueueLL()                                 // constructor for class Queue ensures that pointers are initialized
 {
  front = rear = NULL;
 }

 void QueueLL :: push(float datum, char * name, char * desc)
 {
  int result =0;
  node * temp = new node(datum, name, desc);
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
   cout << "\nName:\t";
   cout.write(check->name,20);
   cout << "\nPhone number:\t" << check->phno;
   cout << "\nDescription:\t";
   cout.write(check->description,50);
   check = check->next;
  }
  cout << "\nNOthing MORE TO DISPLAY.\n";
}

void QueueLL :: insertAtTop(float datum, char * name, char * desc)
{
  node * temp = new node(datum, name, desc);
  temp->next = front; 
  front = temp;
}



int palindromeCheck(char * name)
{
 int i, j, k, flag =1;
 for(k=0; name[k] != '\0'; ++k) ;
 for(j=k-1, i=0; j>=0, i<k; --j, ++i)
 {
  if(name[i] != name[j])
   {
    flag = 0;
    break;
   }
 }
 return flag;
}



int main()
{
 int choice, result;
 float mobno;
 char ch, Name[20], Desc[50];
 QueueLL obj;
 cout << "\nProgram to implement Queue as a data structure for a customer service company..\n An empty linked list has been created ....";
 do
  {
   cout << "Choose among the following :\n\t1.Push\n\t2.Pop\n\t3.Display from front.\n";
   cin >> choice;
   switch(choice)
   {
    case 1 : cout << "\nEnter phone no. of the customer.\t:";
             cin >> mobno;
	     cout << "\nEnter your name :";
 	     cin >> gets(Name);
	     result = palindromeCheck(Name);
             cout << "\nEnter description :";
	     cin.getline(Desc,50);
	     if(result == 1) obj.insertAtTop(mobno, Name, Desc);
	     else  obj.push(mobno, Name, Desc);
	     obj.display();
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
