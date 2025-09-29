#include<iostream>
#include<stack>
#include<string>
using namespace std;

void output_stack(stack<int> a){
    while(!a.empty()){
        cout << a.top();
        a.pop();
    }
}
void ex1(stack<int> a){
    int n;
    cin >> n;
    while(n != 0){
        int bina = n % 2;
        a.push(bina);
        n = n/2; 
    }
    output_stack(a);
}
void ex2(stack<int> a){
    string s; 
    getline(cin,s);
    for(int i = 0; i< s.length(); i++){
        a.push(s[i]);
    }
    output_stack(a);
}

int main(){
    stack<int> a;
    // ex1(a);
    ex2(a);

}



// đề bài 1 : covert decimal number to binary
// đề bài 2 : nhập vào 1 chuỗi ký tự và in ra ngược lại