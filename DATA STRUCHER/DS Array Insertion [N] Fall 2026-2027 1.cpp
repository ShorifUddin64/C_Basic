#include<iostream>
using namespace std;

int main(){

    int arr[100] = {7, 324, 55,9,11,12};
    int arr_size=6;

    int pos=0;
    int value=0;

    cout<<"Initial Array:"<<endl;

    for(int y=0; y<arr_size; y++){
        cout<<"Index:["<<y<<"] Value "<<arr[y]<<endl;
    }

    cout<<"In which Index: ";
    cin>>pos;

    cout<<"What Value: ";
    cin>>value;

    for(int x=arr_size; x>pos; x--){
        arr[x] = arr[x-1];
    }

    arr_size++;
    arr[pos]=value;

    cout<<"After Insertion:"<<endl;
    for(int y=0; y<arr_size; y++){
        cout<<"Index:["<<y<<"] Value "<<arr[y]<<endl;
    }

    return 0;
}
