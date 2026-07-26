#include <iostream>
#include <string>
using namespace std;

int main() {
    int age = 20;
    float gpa = 3.85;
    double preciseNumber = 3.14159265358979;
    char grade = 'A';
    bool isPassed = true;
    string name = "Shorif";
    short smallNumber = 100;
    long bigNumber = 170000000;

    cout << boolalpha;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Precise Value: " << preciseNumber << endl;
    cout << "Grade: " << grade << endl;
    cout << "Passed: " << isPassed << endl;
    cout << "Small Number: " << smallNumber << endl;
    cout << "Big Number: " << bigNumber << endl;

    return 0;
}