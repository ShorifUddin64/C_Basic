#include<iostream>
using namespace std;
int factorial (int n)
{
    int sum=1;
    for(int i=1;i<=n;i++){
        sum =sum*i;
    }
    return sum;

}
int main (){
    int n;
cin>>n;
int r=factorial( n);

cout<<r;

    return 0;

}
