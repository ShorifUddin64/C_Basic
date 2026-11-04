#include<iostream>
using namespace std;

int main(){

    int arr[4] = {11, 119, 10, 1};
    int arr_size = 4;

    for(int x=0; x<arr_size-1; x++){
        int min_index = x;
        for(int y=x+1; y<arr_size; y++){
            if(arr[y]<arr[min_index]){
                min_index = y;
            }
        }
        if(min_index!=x){
            int temp = arr[x];
            arr[x] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    for(int i=0; i<arr_size; i++){
        cout<<arr[i]<<", ";
    }

    return 0;
}
