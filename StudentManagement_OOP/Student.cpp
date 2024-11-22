#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(int _id, string _name, int _examNote)
{
	id = _id;
	name = _name;
	examNote = _examNote;

}

void Student::setId(int _id)
{
	id = _id;
}

void Student::setName(string _name)
{
	name = _name;
}

void Student::setExamNote(int _examNote)
{
	examNote = _examNote;
}

void Student::PrintInfo()
{
	cout << " Student id is :" << id << " Student name is : " << name << " Student examNote is " << examNote<<endl;
}
