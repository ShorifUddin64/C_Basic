#include<iostream>
using namespace std;

void bubbleSort(int arr[], int arr_size){
    for(int x=0; x<arr_size-1; x++){
        for(int y=0; y<arr_size-x-1; y++){
            if(arr[y]>arr[y+1]){
                int temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }
}

int main(){

    int arr[100] = {7, 324, 55,9,11,12};
    int arr_size=6;

    int value=0;
    int pos=-1;

    cout<<"Initial Array:"<<endl;

    for(int y=0; y<arr_size; y++){
        cout<<"Index:["<<y<<"] Value "<<arr[y]<<endl;
    }

    bubbleSort(arr, arr_size);   // Binary Search needs a sorted array

    cout<<"After Sorting:"<<endl;

    for(int y=0; y<arr_size; y++){
        cout<<"Index:["<<y<<"] Value "<<arr[y]<<endl;
    }

    cout<<"What Value to Search: ";
    cin>>value;

    int low=0;
    int high=arr_size-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]==value){
            pos = mid;
            break;
        }
        else if(arr[mid]<value){
            low = mid+1;
        }
        else{
            high = mid-1;
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
