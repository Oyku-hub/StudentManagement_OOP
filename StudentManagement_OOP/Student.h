#include<iostream>
using namespace std;

class Student
{
private:
	int id;
	string name;
	int examNote;

public:

	Student(int _id, string _name, int _examNote);


	//get
	int getId() { return id; }
	string getName() { return name; }
	int getExamNote() { return examNote; }

	//set

	void setId(int _id);
	void setName(string _name);
	void setExamNote(int _examNote);


	void PrintInfo();






};
