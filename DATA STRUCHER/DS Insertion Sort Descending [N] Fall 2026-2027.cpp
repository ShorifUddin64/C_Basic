#include<iostream>
using namespace std;

int main(){

    int arr[4] = {11, 119, 10, 1};
    int arr_size = 4;

    for(int x=1; x<arr_size; x++){
        int key = arr[x];
        int y = x-1;
        while(y>=0 && arr[y]<key){
            arr[y+1] = arr[y];
            y--;
        }
        arr[y+1] = key;
    }

    for(int i=0; i<arr_size; i++){
        cout<<arr[i]<<", ";
    }

    return 0;
}
