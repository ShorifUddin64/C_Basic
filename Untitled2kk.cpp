#include<iostream>
using namespace std;
int caloulateFactorial(int n){
int k=n;
int factoriyal=1;
for(int i=1;i<=k;i++){
    factoriyal *=i;

}
return factoriyal;
}
int main (){
    int s;
    cin>>s;
    cout<<caloulateFactorial(s)<<endl;
    return 0;

}


