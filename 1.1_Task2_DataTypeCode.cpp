#include <iostream>
#include <string>
using namespace std;

int main(){
    int age = 20;
    float Gpa = 3.85;
    double preciseNumber = 3.12345678974563372;
    char grade = 'A';
    bool isPassed = true;
    string Name = "Shorif Uddin";
    short smallNumber = 324;
    /* long bigNumber = 1363474798298734L;// This value fits in signed long long,BUT it is too big for signed long,
                                            so use a long long literal suffix.*/
    long long bigNumber = 1363474798298734LL;

    cout << "Age: " << age << endl;
    cout << "GPA: " << Gpa << endl;
    cout << "PreciseNumber: " << preciseNumber << endl;
    cout << "Grade: " << grade<< endl;
    cout << boolalpha; // to print true or false instead of 1 or 0
    cout << "isPassed: " << isPassed << endl;
    cout << "Name: " << Name << endl;
    cout << " Small Number: " << smallNumber << endl;
    cout << " bigNumber: " << bigNumber << endl;

    return 0;

}