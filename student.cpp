#include<iostream>
#include<string.h>
#include"student.h"
using namespace std;

Student::Student(char* fname, char* lname, int newID, float newGPA) //constructor
{
  name = new char[30];
  strcpy(name, fname);
  strcat(name, " ");
  strcat(name, lname);
  id = newID;
  gpa = newGPA;
}

Student::~Student() //deconstructor
{
  delete name;
}

char* Student::get_name()
{
  return name;
}

int Student::get_id()
{
  return id;
}

float Student::get_gpa()
{
  return gpa;
}
