#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n){
    if(n<2) return false;
    if(n == 2 || n == 3) return true;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}
// void issperic1(int n){ 
//     if(n<30){
//         printf("Not speric number");
        
//     }
//     int count = 0;
//     for(int i = 2; i < n; i++){
//         if(n % i == 0 && isprime(i)){
//             if((n / i) % i == 0){
//                 printf("Not speric number");
                
//             }
//             count++;
//         }
//     }
//     if(count == 3 ){
//         printf("this is sepheric number");   
//     }
//     else printf("this is not sepheric");
// }
bool issperic(int n, int i, int *count) {
    if (n == 1) return (*count == 3);   // dừng khi đã chia hết

    if (n % i == 0 && isprime(i)) {
        int times = 0;
        while (n % i == 0) {
            n /= i;
            times++;
        }
        if (times > 1) return false;   // không cho lặp prime
        (*count)++;
        return issperic(n, i+1, count);
    }

    return issperic(n, i+1, count);
}

int main() {
    int n; cin >> n;
    int count = 0;
    if (n < 30) {
        cout << "this is not speric";
        return 0;
    }
    if (issperic(n, 2, &count)) 
        cout << "it is speric";
    else 
        cout << "this is not speric";
    return 0;
}
