#include<bits/stdc++.h>
using namespace std;
void changePointer(int **p) {
    static int y = 200; // dùng static để y không mất khi hàm kết thúc
    *p = &y;           
    cout << "đây là p : "<< p<<"\n";
    cout << "đây là *P ; " << *p<<"\n";
    cout << **p;
}

int main() {
    int x = 10;
    int *ptr = &x;

    changePointer(&ptr); // truyền địa chỉ của con trỏ
   
}

