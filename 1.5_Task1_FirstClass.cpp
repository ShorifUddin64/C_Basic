#include <iostream>
#include <string>
using namespace std;

class Student {
    public :
    string name;
    int age;
    float gpa;

    void Showinfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gpa: " << gpa << endl;
    }


};

int main() {
    Student s1;
    cout << "Enter Your Name: ";
    getline(cin , s1.name);//getline is used to take input with spaces
    cout << " Enter Your Age: ";
    cin >> s1.age;
    cout<< "Enter Your Gpa: ";
    cin >> s1.gpa;
    s1.Showinfo();
    return 0;
}
