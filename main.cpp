//Linked Lists 2, By Stone Yang [Using Alex Y.'s Node.h & Node.o files]
#include<iostream>
#include<cstring>
#include<iomanip>
#include"node.h"
#include"student.h"
using namespace std;

//function prototypes
void commands();
void add(Node* &head);
void print(Node* current);
void avg(Node* head);
void del(Node* &head);
Node* add_rec(Node* current, int id);
Node* del_rec(Node* current, int id);

int main()
{
  Node* head = NULL;
  bool repeat = true;
  char choice[10];
  commands();

  while(repeat) //loops - repeat default to true
    {
      cout << endl << "Entry: ";
      cin.getline(choice, 10);

      for(int i = 0; i < strlen(choice); i++) //uppercase "choice"
	{
	  choice[i] = toupper(choice[i]);
	}
      if(strcmp(choice, "ADD") == 0)
	{
	  add(head);
	}
      else if(strcmp(choice, "PRINT") == 0)
	{
	  print(head);
	}
      else if(strcmp(choice, "DELETE") == 0)
	{
	  del(head);
	}
      else if(strcmp(choice, "AVERAGE") == 0)
	{
	  avg(head);
	}
      else if(strcmp(choice, "QUIT") == 0)
	{
	  repeat = false; //ends loop & program
	}
      else if(strcmp(choice, "COMMAND") == 0)
	{
	  commands();
	}
    }
  return 0;
}

void commands() //prints commands
{
  cout << endl << "Commands: " << endl;
  cout << "     ADD: Create a new student entry." << endl;
  cout << "   PRINT: Print student list." << endl;
  cout << "  DELETE: Delete an existing student entry." << endl;
  cout << " AVERAGE: Prints average GPA of all student entries." << endl;
  cout << "    QUIT: Exit student list." << endl;
  cout << " COMMAND: Displays the current command list." << endl;
}

void add(Node* &head) //adds student information to the list
{
  char fname[30];
  char lname[30];
  int id;
  float gpa;

  cout << "Enter first name: ";
  cin >> fname;
  cout << "Enter last name: ";
  cin >> lname;
  cout << "Enter ID: ";
  cin >> id;
  cout << "Enter GPA: ";
  cin >> gpa;
  cin.ignore();
  Student* student = new Student(fname, lname, id, gpa);
  Node* node = new Node(student);

  if(head == NULL) //if there is no previous listing, make head = node
    {
      head = node;
    }
  else if(head->getStudent()->get_id() > id) //if the ID of student is greater, move it up
    {
      node->setNext(head);
      head = node;
    }
  else
    {
      Node* current = add_rec(head, id);
      node->setNext(current->getNext());
      current->setNext(node);
    }
}

void print(Node* current) //prints all students
{
  if(current != NULL) //recursion that continues until the next selection is NULL
    {
      cout << current->getStudent()->get_name() << endl;
      cout << current->getStudent()->get_id() << endl;
      cout << fixed << setprecision(2) << current->getStudent()->get_gpa() << endl << endl;
      print(current->getNext());
    }
}

void del(Node* &head) //deletes a student
{
  int id;
  cout << "Enter the ID of the student you wish to delete: ";
  cin >> id;
  cin.ignore();
  cout << endl;

  if(head->getStudent()->get_id() == id)
    {
      if(head->getNext() == NULL)
	{
	  delete head;
	  head = NULL;
	}
      else
	{
	  Node* node = head->getNext();
	  delete head;
	  head = node;
	}
    }
  else
    {
      Node* current = del_rec(head, id);
      if(current != NULL)
	{
	  Node* node = current->getNext()->getNext();
	  delete current->getNext();
	  current->setNext(node);
	}
    }
}

void avg(Node* head) //averages gpa of all students
{
  float avg = 0;
  float total = 0;
  int studentNum = 0;

  Node* current = head;
  while(current != NULL) //recursion, increases # of students & addition
    {
      total += current->getStudent()->get_gpa();
      studentNum++;
      current = current->getNext();
    }
  avg = total/studentNum; //formula
  cout << "Average GPA of all students: " << setprecision(2) << avg << endl;
}

Node* add_rec(Node* current, int id) //recursion for the add function
{
  if((current->getNext() != NULL) && (current->getNext()->getStudent()->get_id() <= id))
    {
      return add_rec(current->getNext(), id);
    }
    else
      {
	return current;
      }
}

Node* del_rec(Node* current, int id) //recursion for the delete function
{
  if((current->getNext() != NULL) && (current->getNext()->getStudent()->get_id() != id))
    {
      return del_rec(current->getNext(), id);
    }
  else if(current->getNext() == NULL)
    {
      cout << "Student does not exist." << endl;
      return NULL;
    }
  else
    {
      return current;
    }
}
