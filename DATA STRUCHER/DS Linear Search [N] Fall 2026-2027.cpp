#include<iostream>
using namespace std;

int main(){

    int arr[100] = {7, 324, 55,9,11,12};
    int arr_size=6;

    int value=0;
    int pos=-1;

    cout<<"Array:"<<endl;

    for(int y=0; y<arr_size; y++){
        cout<<"Index:["<<y<<"] Value "<<arr[y]<<endl;
    }

    cout<<"What Value to Search: ";
    cin>>value;

    for(int x=0; x<arr_size; x++){
        if(arr[x]==value){
            pos = x;
            break;
        }
    }

    if(pos==-1){
        cout<<"Value Not Found!"<<endl;
    }
    else{
        cout<<"Value Found at Index:["<<pos<<"]"<<endl;
    }

    return 0;
}
