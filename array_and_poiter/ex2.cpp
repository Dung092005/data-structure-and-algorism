#include<iostream>
using namespace std;
void findMax(int *max, int a) {
    if (a > *max) {
        *max = a;  // cập nhật giá trị tại địa chỉ con trỏ
    }
}

int main(){
     int currentMax = 10;

    cout << "Current max = " << currentMax << endl;

    findMax(&currentMax, 5);  
    cout << "After comparing with 5: " << currentMax << endl;

}