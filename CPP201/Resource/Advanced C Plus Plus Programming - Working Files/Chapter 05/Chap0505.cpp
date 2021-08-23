#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    // 100 90 80 70 60
    ifstream gradeFile;
    stringstream grades;
    int grade;
    int total = 0;
    gradeFile.open("c:\\data\\grades.txt");
    string line;
    getline(gradeFile, line);
    grades << line;
    gradeFile.close();
    for(int i = 0; i < 5; ++i) {
        grades >> grade;
        total += grade;
    }
    double average = total / 5;
    cout << "average: " << average << endl;
    return 0;
}
