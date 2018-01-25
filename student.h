//Student.h Header File for Linked List
#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<iomanip>
using namespace std;

class Student
{
 public:
  Student(char*, char*, int, float); //constructor
  ~Student(); //deconstructor
  //member functions
  char* get_name();
  int get_id();
  float get_gpa();
 private:
  //member variables
  char* name;
  int id;
  float gpa;
};

#endif
  

