#include<iostream>
using namespace std;

int main(){

    int arr[100] = {7, 324, 55,9,11,12};
    int arr_size=6;

    int pos=0;

    cout<<"Initial Array:"<<endl;

    for(int y=0; y<arr_size; y++){
        cout<<"Index:["<<y<<"] Value "<<arr[y]<<endl;
    }

    cout<<"Which Index to Delete: ";
    cin>>pos;

    if(pos<0 || pos>=arr_size){
        cout<<"Invalid Index!"<<endl;
        return 0;
    }

    for(int x=pos; x<arr_size-1; x++){
        arr[x] = arr[x+1];
    }

    arr_size--;

    cout<<"After Deletion:"<<endl;
    for(int y=0; y<arr_size; y++){
        cout<<"Index:["<<y<<"] Value "<<arr[y]<<endl;
    }

    return 0;
}
