#include<iostream>
using namespace std;

struct Node{
    int data; 
    Node* next;
};
Node* makenode(int x){               // x là data
    Node*newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;
    return newnode; 
}
bool isempty(Node* x){
    return x == NULL;
}


int main(){
    
}