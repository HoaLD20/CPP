#include<iostream>

using namespace std;

struct Student {
	string name;
	int age;
	int score;
};

int main() {
	int n;
	cin >> n;
	Student *students = new Student[100];
	for (int i = 0; i < n; i++) {
		cin >> students[i].name >> students[i].age >> students[i].score;
	}

	Student s = students[0];
	for (int i = 1; i < n; i++) {
		if (students[i].score > s.score) {
			s = students[i];
		}
	}

	cout << "Name: " << s.name << endl;
	cout << "Age: " << s.age << endl;
	cout << "Score: " << s.score;
	
	delete[] students;
	return 0;
}