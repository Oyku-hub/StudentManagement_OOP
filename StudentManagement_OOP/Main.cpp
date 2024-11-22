#include<iostream>
#include <list>
#include "Student.h "

using namespace std;

void ShowList()
{
	cout << "1 Add new student:" << endl;
	cout << "2 Show All List" << endl;
	cout << "3  Delete Student ID" << endl;
	cout << "4  Seach student with Id" << endl;
	cout << "5  Change student info " << endl;
}

void AddStudent(list<Student>* studentList)
{
	list<Student>::iterator it;

	int id, examNote;
	string name;

	//Input Validation
	while (true)
	{
		cout << "Enter the student id that will add: ";
		cin >> id;

		if (cin.fail()) 
		{
			cin.clear();               
			cin.ignore(1000, '\n');   
			cout << "Invalid input! Please enter a valid numeric ID.\n";
		}
		else
		{
			break; 
		}
	}

	cout << "Enter the student name that will add: ";
	cin >> name;

	
	while (true)
	{
		cout << "Enter the student examNote that will add: ";
		cin >> examNote;

		if (cin.fail()) 
		{
			cin.clear();               
			cin.ignore(1000, '\n');    
			cout << "Invalid input! Please enter a valid numeric exam note.\n";
		}
		else
		{
			break; 
		}
	}

	Student student(id, name, examNote);

	for (it = studentList->begin(); it != studentList->end(); ++it)
	{
		if (it->getId() == id)
		{
			cout << "This ID already exists!\n";
			it->PrintInfo();
			return; 
		}
	}

	studentList->push_back(student); 
	cout << "Student added successfully.\n";
}


void ShowAllList(list<Student>* studentList)
{

	list<Student>::iterator it;

	for (it = studentList->begin(); it != studentList->end(); it++)
	{
		it->PrintInfo();
	}
	
}

void DeleteStudent(list<Student>* studentList)
{
	int id;
	cout << " Enter the student id that will delete :";
	cin >> id;

	list<Student>::iterator it;

	for (it = studentList->begin(); it != studentList->end(); it++)
	{
		if (it->getId() == id)
			break;
	}
	
	if (it==studentList->end())
	{
		cout << " Invalid id !!! ";
	}
	else
	{
		studentList->erase(it);

	}
}

void SearchStudent(list<Student>* studentList)
{
	int id;
	cout << " Enter the student id that will search :";
	cin >> id;

	list<Student>::iterator it;

	for (it = studentList->begin(); it != studentList->end(); it++)
	{
		if (it->getId() == id)
		{
			it->PrintInfo();
			
		}

	}
	

}

void SetStudentInfo(list<Student>* studentList)
{
	int _id, _examNote;
	string _name;

	int choose = 0;
	list<Student>::iterator it;

	cout << " Enter the student id that will set : ";
	cin >> _id;


	cout << endl;
	for (it = studentList->begin(); it != studentList->end(); it++)
	{
		

		if (it->getId() == _id)
		{
			cout << "1 = Change id / 2= Name / 3= ExamNote " << endl;
			cin >> choose;

			switch (choose)
			{
				

			case 1:

				cout << "Enter the new id number :";
				cin >> _id;
				it->setId(_id);
				it->PrintInfo();
				break;


			case 2:

				cout << "Enter the new name :";
				cin >> _name;
				it->setName(_name);
				it->PrintInfo();
				break;

			case 3:

				cout << "Enter the new examNote :";
				cin >> _examNote;
				it->setExamNote(_examNote);
				it->PrintInfo();
				break;

			default:
				cout << "Invalid value !!!"<<endl;
				break;
			}
		}


	}


}

int main()
{
	int choose = 0;

	list<Student>* studentList = new list<Student>();

	do
	{
		ShowList();
		cout << " Enter the choose :";
		cin >> choose;

		switch (choose)
		{
		case 1:
			AddStudent(studentList);
			break;

		case 2:
			ShowAllList(studentList);
			break;
		case 3:
			DeleteStudent(studentList);
			break;
		case 4:
			SearchStudent(studentList);
			break;
		case 5:
			SetStudentInfo(studentList);
			break;

		default:
			cout << " Invalid choose !!! ";
			break;
		}

	} while (choose != 7);


}
