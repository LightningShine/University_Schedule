#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <stdio.h>

using namespace std;

class University_Subject
{
public:
	string subject_name;
	short int subject_status;
	vector<string> subject_availability;
	string groups;
	int classroom;
	vector<string> subject_time;
	string location;
	void create_subject()
	{
		cout << "Enter subject name: ";
		cin >> subject_name;
		cout << "Enter subject status (-1 - every weeks, 0 - even weeks, 1 - odd weeks): ";
		cin >> subject_status;
		cout << "Enter subject availability (e.g., AAA for Monday, Wednesday, Friday): ";
		string day;
		string storage;
		cin.ignore(); // To ignore the newline character left in the input buffer
		getline(cin,day);
		istringstream ss(day);
		while (ss >> storage) {
			subject_availability.push_back(storage);
		}
		cout << "Enter groups (comma separated): ";
		getline(cin, groups);
		cout << "Enter subject time (as 13:00 - 14:30): ";
		string time_input;
		getline(cin,time_input);
		stringstream time_stringstream(time_input);
		while (getline(time_stringstream, time_input, '-'))
		{
			subject_time.push_back(time_input);
		};
		cout << "Enter classroom number: ";
		cin >> classroom;
		
		cout << "Enter location: ";
		cin >> location;
	}
	void class_info()
	{
		cout << "Subject Name: " << subject_name << endl;
		cout << "Subject Status: ";
		if(subject_status == -1) {
			cout << "Every week" << endl;
		}
		else if (subject_status == 0) {
			cout << "Even weeks" << endl;
		}
		else if (subject_status == 1) {
			cout << "Odd weeks" << endl;
		}

			cout << "Subject Availability: ";
		for (const auto& day : subject_availability) {
			cout << day << ", ";
		}
			cout << endl;
		cout << "Groups: " << groups << endl;
			cout << "Classroom: " << classroom << endl;
		cout << "Subject Time: ";
			cout << subject_time[0] << "to" << subject_time[1];
		cout << endl;
			cout << "Location: " << location << endl;
	}
};



int main()
{
	struct tm newtime;
	time_t now = time(0);
	//char* dt = ctime(&now);
	char output[50];
	localtime_s(&newtime, &now);
	strftime(output, sizeof(output), "%A, %d %B %Y", &newtime);
	cout << "The current local time is: " << output << endl;
	University_Subject subject;
	subject.create_subject();
	system("cls");
	cout << "Subject Created: " << subject.subject_name << "\n\n";
	subject.class_info();
	

	return 0;
	
}