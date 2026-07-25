#include<iostream>
using namespace std;
class Rectangle{
    double width;
    double height;
public:
    void setDimensions(double w,double h){
        width=w;
        height=h;
    }
    double getArea(){
    double area=0.5*width*height;
    return area;
    }
};
int main(){
    double x,y,s,z;
    Rectangle ob1,ob2;
    cin>>x>>y;
    ob1.setDimensions(x,y);
    cout<<ob1.getArea()<<endl;
    cin>>s>>z;
    ob2.setDimensions(s,z);
    cout<<ob2.getArea()<<endl;
    return 0;

}
