#include<iostream>
#include<cmath>
using namespace std;
int count = 0;
bool isprime(int n){
    if ( n < 2) return false;
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}
bool issperic(int n){
    if(n < 30) return false;
    for(int i = 2; i<=n; i++){
        if(n % i == 0 && isprime(i)){
            count++;
            n = n / i;
            if(n % i == 0 ) return false;
        }
    }
    
    return ( count == 3);
}
int main(){
    int a;
    cin >> a;
    if (issperic(a)) cout << a << " is speric ";
    else{
        cout << " it is not speric";
    }
    cout << count;

    
}
