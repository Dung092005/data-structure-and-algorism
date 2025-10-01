#include<iostream>
using namespace std;
void sum_iteration(){
    int n;
    cin >> n;
    int sum = 0;
    while(n!=0){
        sum = sum + n%10;
        n = n/10;
    }
    cout<<sum<<"\n";
}

int recurtion(int n){
    if(n==0) return 0;
    return n%10 + recurtion(n/10);

}


int main(){
    sum_iteration();
    int n; cin >> n;
    cout<< recurtion(n);
    return 0;
}