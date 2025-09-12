#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class University_Subject
{
	public:
	string subject_name;
	short int subject_status;
	vector<string> subject_availability;
	string groups;
	int classroom;
	int subject_time[2];
	string location;
	void create_subject()
	{
		cout << "Enter subject name: ";
		cin >> subject_name;
		cout << "Enter subject status (-1 - every weeks, 0 - even weeks, 1 - odd weeks): ";
		cin >> subject_status;
		cout << "Enter subject availability (e.g., MWF for Monday, Wednesday, Friday): ";
		char day;
		vector<char> days;
		subject_availability.clear();
		while(true)
		{
			cin >> day;
			if(day == '\0') break;
			if(day == ' ' || day == ';' || day == '.' || day == ':' || day == '-' || day == '_' || day == ',')
			{
				subject_availability.push_back(string(days.begin(), days.end()));
				days.clear();
				continue;
			} 
			else if(day == '\n')
			{
				break;
			}
			else
			{
				days.push_back(day);
			};

		}

		cout << "Enter groups (comma separated): ";
		cin >> groups;
		cout << "Enter classroom number: ";
		cin >> classroom;
		cout << "Enter subject time (start end in 24-hour format, e.g., 1300 1400): ";
		cin >> subject_time[0] >> subject_time[1];
		cout << "Enter location: ";
		cin >> location;
	}
};



int main()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	char output[50];
	strftime(output, sizeof(output), "%A, %d, %B, %Y", localtime(&now));
	cout << "The current local time is: " << output << endl;
	University_Subject subject;
	subject.create_subject();
	cout << "Subject Created: " << subject.subject_name << endl;

	return 0;
}