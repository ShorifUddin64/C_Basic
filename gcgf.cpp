#include <iostream>
using namespace std;

int main() {
    cout << "STEP 1: Creating dynamic array using a single pointer" << endl;
    int *parr = new int[5];
    cout << "arr holds address: " << parr << endl << endl;

    cout << "STEP 2: Storing values in the array" << endl;
    for (int i = 0; i < 5; i++) {
        parr[i] = (i + 1) * 10;
        cout << "arr[" << i << "] = " << parr[i]
             << " stored at address " << (parr + i) << endl;
    }
    cout << endl;

    cout << "STEP 3: Using double pointer (**)" << endl;
    int **pp = &parr;   // pp stores the address of pointer arr
    cout << "pp holds address of arr pointer: " << pp << endl;
    cout << "*pp gives arr address: " << *pp << endl;
    cout << "**pp gives first value: " << **pp << endl << endl;

    cout << "STEP 4: Accessing array using double pointer" << endl;
    cout << "*(*pp ) = " << *(*pp ) << endl; // same as arr[0]
    cout << "*(*pp + 1) = " << *(*pp + 1) << endl; // arr[1]
    cout << "*(*pp + 2) = " << *(*pp + 2) << endl; // arr[2]
    cout << endl;

    cout << "STEP 5: Deleting dynamic array" << endl;
    delete[] parr;
    cout << "Array deleted!" << endl << endl;
    cout<<*parr<<endl;

    cout << "STEP 6: After deletion" << endl;
    cout << "arr still stores old address, but memory is freed." << endl;
    cout << "pp still points to arr pointer." << endl;

    return 0;
}


