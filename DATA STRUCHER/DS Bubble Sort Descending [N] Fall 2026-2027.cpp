#include<iostream>
using namespace std;

int main(){

    int arr[4] = {11, 119, 10, 1};
    int arr_size = 4;

    for(int x=0; x<arr_size-1; x++){
        for(int y=0; y<arr_size-x-1; y++){
            if(arr[y]<arr[y+1]){
                int temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }

    for(int i=0; i<arr_size; i++){
        cout<<arr[i]<<", ";
    }

    return 0;
}
