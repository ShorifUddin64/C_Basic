#include <iostream>
using namespace std;

class cgpa{
public:
    int cradit;
     float result;
     static float total_result;
             static float total_cgpa;
             static int totul_cradit;
             static float vewresult;

     cgpa(int x,float y){
     cradit=x;
     result=y;}

      float calculat_mark(){
          if(90<=result&&100>=result){
            result=4.00;
          return  result;}
          else if(85<=result&&90>result){
            result=3.75;
          return  result;}
          else if(80<=result&&85>result){
            result=3.50;
          return  result;}
          else if(75<=result&&80>result){
            result=3.25;
          return  result;}
          else if(70<=result&&75>result){
            result=3.00;
          return  result;}
          else if(65<=result&&70>result){
            result=2.75;
          return  result;}
          else if(60<=result&&65>result){
            result=2.50;
          return  result;}
          else if(50<=result&&60>result){
            result=2.25;
          return  result;}
          else{
            result =0;
          return result;}}

          float calculate_result(){
              result=cradit*result;
              return result;}

              float TOTALSUM1(){
              total_result+=result;
              return total_result;}

              int TOTALSUM2(){
              totul_cradit +=cradit;
    return totul_cradit; }

void CGPA(){
    total_cgpa=total_result/totul_cradit;
    //vewresult+=total_cgpa;
    cout<<total_cgpa<<endl;}
};
float cgpa::total_result = 0;
int cgpa::totul_cradit = 0;
float cgpa::vewresult=0;
float cgpa::total_cgpa = 0;

int main(){
    cgpa A(1,91);//IC


    A.calculat_mark();
    A.calculate_result();
    A.TOTALSUM1();
    A.TOTALSUM2();
    A.CGPA();

    /*cgpa B(3,42.28);//IP
    B.calculat_mark();
    B.calculate_result();
    B.TOTALSUM1();
    B.TOTALSUM2();
    B.CGPA();*/

    /*cgpa C(1,50);//IPL
    C.calculat_mark();
    C.calculate_result();
    C.TOTALSUM1();
    C.TOTALSUM2();
    C.CGPA();*/

    cgpa D(3,80);//MATH1
    D.calculat_mark();
    D.calculate_result();
    D.TOTALSUM1();
    D.TOTALSUM2();
    D.CGPA();

    cgpa E(3,75);//EN1
    E.calculat_mark();
    E.calculate_result();
    E.TOTALSUM1();
    E.TOTALSUM2();
    E.CGPA();


    cgpa F(3,70);//IPV
    F.calculat_mark();
    F.calculate_result();
    F.TOTALSUM1();
    F.TOTALSUM2();
    F.CGPA();

    cgpa G(1,85);//IPLV
    G.calculat_mark();
    G.calculate_result();
    G.TOTALSUM1();
    G.TOTALSUM2();
    G.CGPA();

    cgpa H(3,80);//MATH 2V
    H.calculat_mark();
    H.calculate_result();
    H.TOTALSUM1();
    H.TOTALSUM2();
    H.CGPA();

    cgpa I(3,75);//ENG-1V
    I.calculat_mark();
    I.calculate_result();
    I.TOTALSUM1();
    I.TOTALSUM2();
    I.CGPA();

    cgpa J(3,85);//PHY-1V
    J.calculat_mark();
    J.calculate_result();
    J.TOTALSUM1();
    J.TOTALSUM2();
    J.CGPA();
    return 0;}
