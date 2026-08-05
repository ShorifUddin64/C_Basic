/*
    =============================================================
    C++ COMPLETE BASICS - DAILY REVISION FILE
    =============================================================
    HOW TO USE THIS FILE:
    - Read this file top to bottom every evening.
    - Every line has a comment explaining WHAT it does and WHICH
      basic concept it belongs to.
    - Concepts are NOT repeated unnecessarily. A concept is shown
      only as many times as needed to fully understand its
      behavior (example: bool is shown with cout because its
      output behavior - printing 1/0 instead of true/false - is
      not obvious just from declaring it).
    - This file compiles and runs as ONE complete program in
      CodeBlocks. Only the cin block is commented out on purpose,
      so reading the file doesn't pause waiting for input -
      uncomment it if you want to test user input too.
    =============================================================
*/

#include <iostream>   // Preprocessor directive: includes the Input/Output Stream library
                      // BASIC: Preprocessor directives / Header files
                      // Without this, cin/cout would not exist in this file

using namespace std;  // Tells the compiler to use the "std" namespace directly
                      // BASIC: Namespaces
                      // Without this, you would have to write std::cout, std::cin every time


// ================= FUNCTION DECLARATION (PROTOTYPE) =================
// BASIC: Function declaration / prototype
// This tells the compiler "a function named addNumbers exists, takes two ints, returns an int"
// The actual body is defined LATER (below main). This is why prototypes exist -
// so main() can call a function that is physically written after it in the file.
int addNumbers(int a, int b);

// Function overloading example prototype - same name, different parameter types
// BASIC: Function overloading (same function name, different parameter list)
double addNumbers(double a, double b);


// =============================================================
// CLASS & OBJECT - the most basic OOP building block
// =============================================================
// BASIC: class - a blueprint that bundles DATA (variables) and BEHAVIOR (functions) together
class Student {
public:                          // BASIC: access specifier 'public' - accessible from OUTSIDE the class too
    string studentName;          // BASIC: data member (also called property/attribute) of the class
    int studentAge;

    void introduce() {           // BASIC: member function (also called method) - behavior that belongs to the class
        cout << "Hi, I am " << studentName << ", age " << studentAge << endl;
    }
};
// Student itself is just the BLUEPRINT - no memory used yet, no actual student exists until we make an OBJECT (in main)


// =============================================================
// ENCAPSULATION - hiding data, controlling access through functions
// =============================================================
// BASIC: encapsulation - wrapping data + the functions that operate on it into one unit,
// and RESTRICTING direct outside access to the data (data hiding)
class BankAccount {
private:                          // BASIC: access specifier 'private' - NOT accessible directly from outside the class
    double balance;               // this is HIDDEN - no outside code can write "account.balance = -500;" directly

public:
    BankAccount() {                // BASIC: constructor - special function, runs AUTOMATICALLY when an object is created
        balance = 0;               // sets a safe starting value, same name as the class, no return type
    }

    void deposit(double amount) {  // BASIC: public function acting as a controlled "gateway" to modify private data
        if (amount > 0) {          // validation logic - THIS is the real benefit of encapsulation
            balance += amount;     // (+=  BASIC: compound assignment operator, same as balance = balance + amount)
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {   // won't allow withdrawing more than available - protects data integrity
            balance -= amount;      // BASIC: compound assignment operator
        } else {
            cout << "Withdraw denied - invalid amount" << endl;
        }
    }

    double getBalance() {           // BASIC: "getter" function - controlled READ access to private data
        return balance;
    }
    // Notice: there is NO setBalance(double) here that lets you just overwrite balance directly.
    // That restriction IS the encapsulation - outside code can only change balance through
    // deposit()/withdraw(), which enforce rules. This is the whole point of making it private.
};


// =============================================================
// INHERITANCE - one class reusing/extending another class
// =============================================================
// BASIC: base class (also called parent class) - the class being inherited FROM
class Animal {
public:
    string animalName;

    Animal(string n) {              // BASIC: constructor that takes a parameter
        animalName = n;
        cout << "Animal constructor called for " << animalName << endl;
    }

    void eat() {                    // a general behavior ALL animals share
        cout << animalName << " is eating." << endl;
    }

    virtual void makeSound() {      // BASIC: virtual function - allows a DERIVED class to override this behavior
        cout << animalName << " makes a generic animal sound." << endl;
    }
};

// BASIC: derived class (also called child/sub class) - inherits from Animal using ": public Animal"
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {     // BASIC: calling the BASE class constructor from the derived class constructor
        cout << "Dog constructor called for " << animalName << endl;
    }

    void makeSound() override {     // BASIC: function overriding - Dog provides its OWN version of makeSound()
        cout << animalName << " says: Woof woof!" << endl;
    }
    // eat() is NOT re-written here - Dog automatically GETS eat() for free from Animal.
    // This reuse (not having to rewrite eat()) is the core benefit of inheritance.
};


// =============================================================
// STRUCT - similar to class, but members are public by default
// =============================================================
// BASIC: struct - groups related variables together, mainly used for simple data bundles
struct Point {
    int x;      // no access specifier written -> defaults to PUBLIC (opposite of class, which defaults to private)
    int y;
};


// =============================================================
// OPERATOR OVERLOADING - redefining what an operator does for a class
// =============================================================
// BASIC: operator overloading - lets built-in operators like + work on YOUR OWN class types
class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0) {   // BASIC: default parameter values - Complex() with no args still works
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other) {   // BASIC: operator+ overload - defines what '+' means for two Complex objects
        return Complex(real + other.real, imag + other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};


// =============================================================
// ABSTRACTION - hiding implementation details behind a common interface
// =============================================================
// BASIC: abstract class - a class with at least one PURE virtual function, CANNOT be directly instantiated
class Shape {
public:
    virtual double area() = 0;    // BASIC: pure virtual function - "= 0" means NO body here, every derived class MUST implement it

    virtual ~Shape() {}           // BASIC: virtual destructor - REQUIRED whenever you delete a derived object through
                                   // a base class pointer (like shapePtr below); without this, delete causes undefined
                                   // behavior because it wouldn't know to also run Circle's destructor
};

class Circle : public Shape {     // Circle is FORCED to implement area(), or it also becomes abstract
public:
    double radius;
    Circle(double r) { radius = r; }

    double area() override {
        return 3.1416 * radius * radius;
    }
};


// =============================================================
// STATIC (class-level) - a value SHARED across ALL objects of a class
// =============================================================
// BASIC: static data member - only ONE copy exists, shared by every object, not per-object like normal members
class IDGenerator {
public:
    static int count;             // declaration only, inside the class

    IDGenerator() {
        count++;                  // every new object increases the SAME shared counter
    }
};
int IDGenerator::count = 0;       // BASIC: static member must be defined ONCE outside the class, here we set its starting value


// Prototype for the static LOCAL variable demo function (defined after main, like addNumbers)
int counterFunction();


int main() {  // BASIC: main() function - entry point of every C++ program, execution starts here

    // ================= VARIABLES & DATA TYPES =================

    int wholeNumber = 10;         // BASIC: Data type 'int' - stores whole numbers (no decimal)
    float smallDecimal = 3.14f;   // BASIC: Data type 'float' - stores decimal numbers, less precision, needs 'f' suffix
    double bigDecimal = 3.141592653589; // BASIC: Data type 'double' - stores decimal numbers, more precision than float
    char singleLetter = 'A';      // BASIC: Data type 'char' - stores ONE character, written in single quotes
    bool isPassed = true;         // BASIC: Data type 'bool' - stores only true or false
    string name = "Shorif";       // BASIC: Data type 'string' - stores text (needs #include <string>, iostream pulls it in indirectly here)

    // Printing normal variables - shown ONCE, since the concept (cout prints value) is simple and clear
    cout << "Int value: " << wholeNumber << endl;      // BASIC: cout (console output), << insertion operator, endl (newline)
    cout << "Float value: " << smallDecimal << endl;   // Same concept as above, minimal repeat just to confirm float prints normally
    cout << "Double value: " << bigDecimal << endl;    // Same concept, confirming double prints with more precision
    cout << "Char value: " << singleLetter << endl;    // Same concept, char prints as the actual letter
    cout << "String value: " << name << endl;          // Same concept, string prints as text

    // BOOL is a SPECIAL CASE - it needs to be shown, because its printed output is NOT what beginners expect
    cout << "Bool value (isPassed): " << isPassed << endl;
    // BASIC: bool output behavior
    // cout does NOT print "true" or "false" by default.
    // It prints 1 for true and 0 for false. This line's WHOLE PURPOSE
    // is to demonstrate that exact behavior - this is why it's shown, not skipped.

    bool isFailed = false;
    cout << "Bool value (isFailed): " << isFailed << endl;
    // Second bool shown ONLY to prove BOTH sides (true->1 AND false->0), not just one


    // ================= CONSTANTS =================
    const double PI = 3.14159;   // BASIC: 'const' keyword - value CANNOT be changed after this point
    // PI = 3.0;                 // <-- if uncommented, this line would cause a COMPILE ERROR (const protection)
    cout << "Constant PI: " << PI << endl;


    // ================= INPUT (cin) =================
    // BASIC: cin (console input) - reads value typed by the user, >> extraction operator
    // int userAge;
    // cout << "Enter your age: ";
    // cin >> userAge;              // Program pauses here, waits for user to type a number and press Enter
    // cout << "You entered: " << userAge << endl;
    // (kept commented so the file doesn't pause when you just READ it - uncomment to actually run/test)


    // ================= OPERATORS =================

    int x = 10, y = 3;  // BASIC: multiple variable declaration in one line

    cout << "\n--- Arithmetic Operators ---\n";     // BASIC: \n is an escape sequence for newline, alternative to endl
    cout << "x + y = " << (x + y) << endl;   // BASIC: addition operator
    cout << "x - y = " << (x - y) << endl;   // BASIC: subtraction operator
    cout << "x * y = " << (x * y) << endl;   // BASIC: multiplication operator
    cout << "x / y = " << (x / y) << endl;   // BASIC: division operator - integer/integer = integer (result 3, decimal part dropped)
    cout << "x % y = " << (x % y) << endl;   // BASIC: modulus operator - gives REMAINDER of division, only works on integers

    cout << "\n--- Relational Operators ---\n";      // These COMPARE two values and return a bool (1 or 0)
    cout << "x > y  : " << (x > y) << endl;   // BASIC: greater than
    cout << "x < y  : " << (x < y) << endl;   // BASIC: less than
    cout << "x == y : " << (x == y) << endl;  // BASIC: equality check (NOT the same as single '=' which is assignment)
    cout << "x != y : " << (x != y) << endl;  // BASIC: not-equal check

    cout << "\n--- Logical Operators ---\n";          // These combine bool conditions
    bool cond1 = true, cond2 = false;
    cout << "cond1 && cond2 : " << (cond1 && cond2) << endl; // BASIC: AND - true only if BOTH sides true
    cout << "cond1 || cond2 : " << (cond1 || cond2) << endl; // BASIC: OR - true if AT LEAST ONE side true
    cout << "!cond1         : " << (!cond1) << endl;         // BASIC: NOT - flips true to false and vice versa

    cout << "\n--- Increment / Decrement ---\n";
    int counter = 5;
    cout << "counter++ (post-increment, prints OLD value then increases): " << counter++ << endl; // BASIC: post-increment
    cout << "counter is now: " << counter << endl;   // confirming it actually increased after the line above
    cout << "++counter (pre-increment, increases THEN prints NEW value): " << ++counter << endl;  // BASIC: pre-increment
    cout << "counter-- (post-decrement): " << counter-- << endl; // BASIC: post-decrement
    cout << "--counter (pre-decrement): " << --counter << endl; // BASIC: pre-decrement


    // ================= CONTROL FLOW: if-else =================
    cout << "\n--- if-else ---\n";
    int marks = 75;
    if (marks >= 80) {                          // BASIC: if statement - runs block only if condition is true
        cout << "Grade: A" << endl;
    } else if (marks >= 60) {                   // BASIC: else-if - checked only if previous condition was false
        cout << "Grade: B" << endl;
    } else {                                    // BASIC: else - runs if ALL above conditions were false
        cout << "Grade: C or below" << endl;
    }

    // ================= CONTROL FLOW: switch =================
    cout << "\n--- switch ---\n";
    int day = 3;
    switch (day) {                    // BASIC: switch statement - jumps directly to matching case
        case 1:                       // BASIC: case label
            cout << "Sunday" << endl;
            break;                    // BASIC: break - stops execution from "falling through" into next case
        case 2:
            cout << "Monday" << endl;
            break;
        case 3:
            cout << "Tuesday" << endl;
            break;
        default:                      // BASIC: default - runs if no case matched, like a final else
            cout << "Other day" << endl;
    }


    // ================= LOOPS (all 3, with extra logic inside) =================

    cout << "\n--- for loop (with continue + break logic) ---\n";
    // BASIC: for loop structure -> for(initialization; condition; update)
    for (int i = 1; i <= 10; i++) {           // starts at 1, runs while i<=10, increases i by 1 each round
        if (i % 2 == 0) {                     // condition check INSIDE the loop, using modulus operator
            continue;                          // BASIC: continue - skips rest of THIS round, jumps to update (i++), goes to next round
        }
        if (i == 9) {                          // another condition, different purpose than the one above
            cout << "Stopping early at i=9" << endl;
            break;                              // BASIC: break - exits the loop COMPLETELY, ignores remaining rounds
        }
        cout << "for loop i (odd only) = " << i << endl;  // only odd numbers before 9 reach this line
    }

    cout << "\n--- while loop (with nested if + decrement) ---\n";
    // BASIC: while loop structure -> condition checked BEFORE each round, may run 0 times if false from start
    int n = 5;
    while (n > 0) {                            // runs as long as n is greater than 0
        if (n == 3) {                          // BASIC: nested if inside a loop
            cout << "n is exactly 3 - special case" << endl;
        } else {
            cout << "while loop n = " << n << endl;
        }
        n--;                                    // BASIC: decrement used as the loop's own update step (manual, not in the loop header)
    }

    cout << "\n--- do-while loop (runs at least once, with condition trick) ---\n";
    // BASIC: do-while loop structure -> body runs FIRST, condition checked AFTER
    // KEY DIFFERENCE from while: do-while ALWAYS executes at least one time, even if condition is false from the start
    int m = 100;   // deliberately starts already false-ish to prove the "runs at least once" behavior
    do {
        cout << "do-while ran with m = " << m << " (proves it runs even though m > 10 is false)" << endl;
        m++;
    } while (m < 10);  // condition is false immediately, but the body above STILL ran one time


    // ================= ARRAYS =================
    cout << "\n--- Arrays ---\n";
    int numbers[5] = {10, 20, 30, 40, 50};   // BASIC: array declaration - fixed-size collection of same-type values
    // Index starts at 0, NOT 1
    cout << "First element (index 0): " << numbers[0] << endl;   // BASIC: array indexing
    cout << "Last element (index 4): " << numbers[4] << endl;

    cout << "Looping through the array: ";
    for (int i = 0; i < 5; i++) {             // BASIC: using a for loop to traverse an array (very common combined pattern)
        cout << numbers[i] << " ";
    }
    cout << endl;


    // ================= FUNCTIONS =================
    cout << "\n--- Functions ---\n";
    int sumInt = addNumbers(4, 6);             // BASIC: calling a function, passing arguments, storing the return value
    cout << "addNumbers(4, 6) = " << sumInt << endl;

    double sumDouble = addNumbers(2.5, 3.1);   // BASIC: calling the OVERLOADED version - compiler picks this
    cout << "addNumbers(2.5, 3.1) = " << sumDouble << endl;   // because arguments are double, not int
    // This proves function overloading: same name "addNumbers", compiler chooses the
    // correct version based on argument TYPES automatically.


    // ================= POINTERS =================
    cout << "\n--- Pointers ---\n";
    int normalVar = 25;              // a normal variable holding a value
    int* ptr = &normalVar;           // BASIC: pointer declaration - '*' means "this variable stores an address"
                                      // '&' is the ADDRESS-OF operator - gets the memory address of normalVar

    cout << "Value of normalVar        : " << normalVar << endl;
    cout << "Address of normalVar (&)  : " << &normalVar << endl;  // BASIC: printing a memory address directly
    cout << "Value stored in ptr       : " << ptr << endl;         // ptr itself holds an ADDRESS, so this prints the same address
    cout << "Value AT that address (*) : " << *ptr << endl;        // BASIC: dereference operator '*' - "go to the address and get the value there"

    *ptr = 99;                        // BASIC: modifying a value THROUGH a pointer (dereferencing on the left side)
    cout << "normalVar AFTER *ptr = 99: " << normalVar << endl;    // proves ptr and normalVar point to the SAME memory


    // ================= REFERENCES =================
    cout << "\n--- References ---\n";
    int original = 50;
    int& ref = original;             // BASIC: reference declaration - '&' here means "ref is another NAME for original"
                                      // NOT the same '&' as address-of; context (declaration vs expression) decides meaning

    cout << "original      : " << original << endl;
    cout << "ref           : " << ref << endl;   // prints the same value, because ref IS original, not a copy

    ref = 77;                         // changing ref changes original directly - no dereferencing needed (unlike pointers)
    cout << "original AFTER ref = 77: " << original << endl;
    // KEY DIFFERENCE from pointer: a reference cannot be null, cannot be reassigned to
    // refer to a different variable later, and needs no * to access/modify the value.


    // ================= CLASS & OBJECT (using the Student class defined above) =================
    cout << "\n--- Class & Object ---\n";
    Student s1;                      // BASIC: creating an OBJECT - this is where actual memory is allocated from the blueprint
    s1.studentName = "Shorif";       // BASIC: accessing a public data member using the dot '.' operator
    s1.studentAge = 19;
    s1.introduce();                  // BASIC: calling a member function on an object using the dot '.' operator

    Student s2;                      // a SECOND, completely independent object from the SAME class
    s2.studentName = "Rafi";
    s2.studentAge = 20;
    s2.introduce();
    // s1 and s2 each have their OWN copy of studentName/studentAge - proves a class is a
    // blueprint, and each object made from it is a separate, independent instance.


    // ================= ENCAPSULATION (using the BankAccount class defined above) =================
    cout << "\n--- Encapsulation ---\n";
    BankAccount myAccount;           // constructor runs automatically here, balance starts at 0
    // myAccount.balance = 500;      // <-- if uncommented: COMPILE ERROR, because balance is private
    myAccount.deposit(500);          // must go through the public function - this IS encapsulation in action
    myAccount.deposit(-100);         // invalid amount, silently rejected by the validation logic inside deposit()
    myAccount.withdraw(200);
    myAccount.withdraw(10000);       // invalid - more than balance, rejected, prints the denial message
    cout << "Final balance: " << myAccount.getBalance() << endl;   // only way to READ balance from outside


    // ================= INHERITANCE (using Animal -> Dog defined above) =================
    cout << "\n--- Inheritance ---\n";
    Dog myDog("Bruno");              // this line triggers BOTH constructors: Animal's first, then Dog's
    myDog.eat();                     // inherited directly from Animal, Dog never had to define this itself
    myDog.makeSound();               // runs Dog's OVERRIDDEN version, not Animal's generic version

    Animal genericAnimal("Generic"); // a plain Animal object, not a Dog
    genericAnimal.makeSound();       // runs Animal's own version, since it's not a Dog


    // ================= TYPE CASTING =================
    cout << "\n--- Type Casting ---\n";
    double preciseValue = 9.7;
    int implicitCast = preciseValue;                       // BASIC: implicit casting - compiler converts automatically, decimal part silently dropped
    int explicitCast = static_cast<int>(preciseValue);      // BASIC: explicit casting - YOU tell the compiler to convert, preferred in C++ over old (int) style
    cout << "Implicit cast result: " << implicitCast << endl;
    cout << "Explicit cast result: " << explicitCast << endl;


    // ================= TERNARY OPERATOR =================
    cout << "\n--- Ternary Operator ---\n";
    int checkNum = 11;
    string parity = (checkNum % 2 == 0) ? "Even" : "Odd";   // BASIC: ternary operator - shorthand for a simple if-else that returns a value
    cout << checkNum << " is " << parity << endl;


    // ================= STRUCT =================
    cout << "\n--- Struct ---\n";
    Point p1;                        // creating an object of struct - same syntax as a class object
    p1.x = 3;                        // BASIC: accessing struct members directly with '.', no getter needed - PUBLIC by default
    p1.y = 4;
    cout << "Point p1 = (" << p1.x << ", " << p1.y << ")" << endl;


    // ================= 2D ARRAY =================
    cout << "\n--- 2D Array ---\n";
    int grid[2][3] = { {1, 2, 3}, {4, 5, 6} };   // BASIC: 2D array - array of arrays, [rows][columns]
    for (int row = 0; row < 2; row++) {          // BASIC: nested for loop - outer loop for rows
        for (int col = 0; col < 3; col++) {      // BASIC: inner loop for columns
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }


    // ================= STRING FUNCTIONS =================
    cout << "\n--- String Functions ---\n";
    string word = "Programming";
    cout << "Length of word     : " << word.length() << endl;     // BASIC: .length() - number of characters
    cout << "Substring (0 to 4) : " << word.substr(0, 4) << endl; // BASIC: .substr(start, count) - extracts part of a string
    cout << "Position of 'g'    : " << word.find('g') << endl;    // BASIC: .find() - returns INDEX of first match
    cout << "Word + \" Language\" : " << (word + " Language") << endl;  // BASIC: '+' on strings means CONCATENATION, not addition


    // ================= SIZEOF =================
    cout << "\n--- sizeof Operator ---\n";
    cout << "sizeof(int)    : " << sizeof(int) << " bytes" << endl;      // BASIC: sizeof - tells how much memory a type/variable uses
    cout << "sizeof(double) : " << sizeof(double) << " bytes" << endl;
    cout << "sizeof(char)   : " << sizeof(char) << " bytes" << endl;


    // ================= ENUM =================
    cout << "\n--- Enum ---\n";
    enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY };  // BASIC: enum - named constants; SUNDAY=0, MONDAY=1, TUESDAY=2... automatically
    Day today = TUESDAY;
    cout << "today (as a number): " << today << endl;   // prints 2 - enum values are stored as integers internally


    // ================= STATIC =================
    cout << "\n--- Static ---\n";
    cout << "Call 1: " << counterFunction() << endl;   // BASIC: static LOCAL variable - retains its value between function calls
    cout << "Call 2: " << counterFunction() << endl;   // a normal (non-static) local variable would reset to 0 every call
    cout << "Call 3: " << counterFunction() << endl;   // this keeps increasing instead - proves it's not reset

    IDGenerator obj1;   // count becomes 1
    IDGenerator obj2;   // count becomes 2 (SAME shared variable, not obj1's own copy)
    IDGenerator obj3;   // count becomes 3
    cout << "Total IDGenerator objects created (static count): " << IDGenerator::count << endl;  // accessed via ClassName::, not an object


    // ================= ABSTRACTION =================
    cout << "\n--- Abstraction ---\n";
    // Shape myShape;                 // <-- if uncommented: COMPILE ERROR, Shape is abstract, cannot make an object of it directly
    Shape* shapePtr = new Circle(5);  // BASIC: 'new' - dynamic memory allocation; a BASE class pointer can point to a DERIVED object
    cout << "Circle area via Shape pointer: " << shapePtr->area() << endl;   // BASIC: '->' operator - access members through a pointer
    delete shapePtr;                  // BASIC: 'delete' - frees memory that 'new' allocated, prevents memory leaks


    // ================= OPERATOR OVERLOADING =================
    cout << "\n--- Operator Overloading ---\n";
    Complex c1(2, 3), c2(1, 4);
    Complex c3 = c1 + c2;              // this '+' is NOT the built-in one - it calls OUR overloaded operator+ from the Complex class
    cout << "c1 + c2 = ";
    c3.display();


    return 0;   // BASIC: return statement - tells the operating system the program ended successfully (0 = success)

}  // end of main()


// ================= FUNCTION DEFINITIONS =================
// BASIC: Function definition - the ACTUAL body of a function declared earlier as a prototype

int addNumbers(int a, int b) {   // takes two int parameters
    return a + b;                 // BASIC: return statement inside a function - sends the result back to the caller
}

double addNumbers(double a, double b) {  // overloaded version - same name, different parameter types (double)
    return a + b;
}

int counterFunction() {
    static int callCount = 0;   // BASIC: static local variable - initialized ONLY ONCE, ever, no matter how many times this function is called
    callCount++;                // keeps increasing across calls, unlike a normal local variable which would reset to 0 every time
    return callCount;
}
