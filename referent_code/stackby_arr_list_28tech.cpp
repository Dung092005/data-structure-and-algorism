 
#include <bits/stdc++.h>

using namespace std;

int n = 0, st[10001];

void push(int x){
	st[n] = x;
	++n;
}

void pop(){
	if(n >= 1)
		--n;
}

int top(){
	return st[n - 1];
}

int size(){
	return n;
}

int main(){
	while(1){
		cout << "-------------------------------\n";
		cout << "1. push\n";
		cout << "2. pop\n";
		cout << "3. top\n";
		cout << "4. size\n";
		cout << "0. Thoat\n";
		cout << "-------------------------------\n";
		int lc; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap x :" ; 1cin >> x;
			push(x);
		}
		else if(lc == 2){
			pop();
		}
		else if(lc == 3){
			if(n == 0) cout << "EMPTY\n";
			cout << top() << endl;
		}
		else if(lc == 4){
			cout << size() << endl;
		}
		else{
			break;
		}
	}
	return 0;
}