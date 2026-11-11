#include<iostream>
using namespace std;

#define MAX 5

class Stack{
private:
    int arr[MAX];
    int top;
public:

    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if(top == MAX-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = value;
        cout<<value<<" Pushed in the stack"<<endl;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<arr[top]<<" Popped out from the stack"<<endl;
        top--;
    }

    bool peek()
    {
        if(top == -1)
        {
            cout<<"Stack is Empty"<<endl;
            return true;
        }
    }

    void display()
    {
        bool isEmpty = peek();
        if(isEmpty == false)
        {
            cout<<"Stack Elements are :"<<endl;
            for(int i=top; i>=0; i--)
            {
                cout<<arr[i]<<endl;
            }
        }

    }

};


int main()
{

    Stack s;

    s.display();


    return 0;
}
