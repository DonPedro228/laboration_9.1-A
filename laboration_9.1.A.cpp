#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;

enum Specialnist { Computer_Science, Philology , Information_Technology };

struct Student
{
	string prizv;
	int course;
	Specialnist specialnist;
	double physics_grade;
	double math_grade;
	double informatics_grade;
};

void Create(Student* S, const int N);
void Print(Student* S, const int N);
int Count5(Student* S, const int N);
int Count4(Student* S, const int N);
int Count3(Student* S, const int N);
void Students_With_Grade_5_In_Physics_And_Math(Student* S, const int N);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Input N: "; cin >> N;

	Student* S = new Student[N];
	int grade3Count;
	int grade4Count;
	int grade5Count;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Choose an extion: " << endl << endl;
		cout << " [1] - entering data from the keyboard" << endl;
		cout << " [2] - print data in display" << endl;
		cout << " [3] - cout count 3 from math" << endl;
		cout << " [4] - cout count 4 from math" << endl;
		cout << " [5] - cout count 5 from math" << endl;
		cout << " [6] - Students who got '5' in Physics and Math" << endl;
		cout << " [0] - Exit" << endl << endl;
		cout << "Input value: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem)
		{
		case 1:
			Create(S, N);
			break;
		case 2:
			Print(S, N);
			break;
		case 3:
			grade3Count = Count3(S, N);
			cout << "Count grades 3 from math: " << grade3Count << endl;
			break;
		case 4:
			grade4Count = Count4(S, N);
			cout << "Count grades 4 from math: " << grade4Count << endl;
			break;
		case 5:
			grade5Count = Count5(S, N);
			cout << "Count grades 5 from math: " << grade5Count << endl;
			break;
		case 6:
			cout << "Students who got '5' in Physics and Math:" << endl;
			Students_With_Grade_5_In_Physics_And_Math(S, N);
			break;
		}
	} while (menuItem != 0);


	delete[] S;

	return 0;
}

void Create(Student* S, const int N) {
	int specialnist_value;
	for (int i = 0; i < N; i++) {
		cout << "Student # " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << " Last Name: ";  getline(cin, S[i].prizv);
		cout << " Course: ";  cin >> S[i].course;
		cout << " Specialnist (0 - Computer_Science, 1 - Philology, 2 -  Information_Technology): ";

		cin >> specialnist_value;
		S[i].specialnist = static_cast<Specialnist>(specialnist_value);
		cout << "Physics Grade: ";
		cin >> S[i].physics_grade;
		cout << "Mathematics Grade: ";
		cin >> S[i].math_grade;
		cout << "Informatics Grade: ";
		cin >> S[i].informatics_grade;
		cout << "-----------------------------\n";
	}
}

void Print(Student* S, const int N)
{
	cout << "=================================================================================================="
		<< endl;
	cout << "| # | Last Name             | Course | Specialnist                | Phisics | Math | Informatics |"
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(24) << left << S[i].prizv << " | " << left << S[i].course
			<< " | ";

		switch (S[i].specialnist) {
		case Computer_Science:
			cout << setw(27) <<"Computer_Science";
			break;
		case Philology:
			cout << setw(27) <<"Philology";
			break;
		case Information_Technology:
			cout << setw(27) << "Information_Technology";
			break;
		}

		cout << " | " << setw(6) << S[i].physics_grade << " | " << setw(10) << S[i].math_grade
			<< " | " << setw(11) << S[i].informatics_grade << " |" << endl;
	}
	cout << "=================================================================================================="
		<< endl;
}

int Count5(Student* S, const int N) {
	int grade5Count = 0;
	for (int i = 0; i < N; i++) {
		if (S[i].math_grade == 5) {
			grade5Count++;
		}
	}

	return grade5Count;
}

int Count4(Student* S, const int N) {
	int grade4Count = 0;
	for (int i = 0; i < N; i++) {
		if (S[i].math_grade == 4) {
			grade4Count++;
		}
	}

	return grade4Count;
}

int Count3(Student* S, const int N) {
	int grade3Count = 0;
	for (int i = 0; i < N; i++) {
		if (S[i].math_grade == 3) {
			grade3Count++;
		}
	}

	return grade3Count;
}

void Students_With_Grade_5_In_Physics_And_Math(Student* S, const int N) {
	for (int i = 0; i < N; i++) {
		if (S[i].physics_grade == 5 && S[i].math_grade == 5) {
			cout << S[i].prizv << endl;
		}
	}
}