#include<iostream>
using namespace std;
void ex1(){
    int num, lastdigit, temp,middle,swap,pow10 = 1;;
    cin>> num;
    lastdigit = num % 10;
    temp = num;
    while(temp>=10){
        temp = temp / 10;
        pow10 *= 10;
    }
    middle = (num % pow10)/ 10;
    swap = lastdigit*pow10 + middle*10 + temp;
    cout << swap;
}

int main(){
    ex1();
}