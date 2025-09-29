#include<bits/stdc++.h>
using namespace std;
struct Node{
    int value;
    Node* next;
};
void printout(Node* n){
    while(n != NULL){
        cout << n->value << "\n";
        n = n->next;
    }
}
int size(Node* x){
    int count = 0 ;
    while (x != NULL){
        count = count + 1;
        x = x->next;
    }
    return count;
}
void insert_front(Node** head, int newvalue){
    //1 prepare a new node
    Node* newnode = new Node;
    newnode->value = newvalue;
    //2 put it in front of current head
    newnode->next = *head;
    //3 move head of the list to poit the newnode;
    *head = newnode; 

}
bool isempty(Node* x){
    return x == NULL;
}
Node* makenode(int x){               // x là data
    Node*newnode = new Node;
    newnode->value = x;
    newnode->next = NULL;
    return newnode; 
}
void insert_at_end(Node** head,int newvalue){
        //prepare a newnode
        Node*newnode=makenode(newvalue);
        //check whether it is empty ?
        if (isempty(*head)) return;
        Node*temp = *head;
        // do while to get the last digit
        while(temp->next != NULL){
            temp = temp->next;
        }
        // connect lastdigit to new 
        temp->next = newnode;
        
}
void insert_mid(Node**head,int newvalue,int pos){
    int n = size(*head);
    if(pos <= 0 || pos > n + 1 ) cout << "vị trí ko hợp lệ";
  	if(pos == 1){
		insert_front(head,newvalue);
        return;
	}
	else if(pos == n +1 ){
		insert_at_end(head, newvalue); 
        return;
	}
    Node*p = *head;
    for(int i = 1 ; i <= pos - 1; i++){
        p = p->next;
    }
    Node*temp = makenode(newvalue);
    temp->next = p->next;
    p->next = temp;
} 
void delete_first(Node** head) {
    if (*head == NULL) return;  // danh sách rỗng thì thoát
    
    Node* temp = *head;         // temp trỏ tới node đầu tiên
    *head = (*head)->next;      // head trỏ sang node kế tiếp
    delete temp;                // xóa node cũ
}
void delete_last(Node*head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp= temp->next;
    }
    delete temp->next;
    temp->next = NULL;

}
void delete_mid(Node**head, int pos){
    int n = size(*head); 
    if(*head == NULL) return;
    if(pos == 1) delete_first(head);
    if(pos == n) delete_last(*head);
    Node* p =  *head; 
    for(int i = 1; i <= pos-1; i++){
        p = p ->next;
    }
    Node*temp = p->next;
    p->next = p->next->next;
    delete(temp);
}

int main(){

    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    head->value = 1;
    head->next = second;
    second ->value = 2;
    second ->next = third;
    third->value = 3;
    third->next = NULL;
    insert_front(&head, -1); 
    insert_at_end(&head,4);
    insert_mid(&head,5,2);   
    // delete_first(&head);
    // // delete_last(head);
    delete_mid(&head,3);
    printout(head);

}




//   lưu ý nha : Node** head, thì phải truyền &head ở hàm main đúng chưa, vì ở main, head là 1 poiter, &head là địa chỉ của poiter đo
//    vậy tức là trong các hàm như insert_front .., thì head chứa địa chỉ của con trỏ head trong main, còn *head thì nó chưa
//   địa chỉ của new node() trong heap, và **head thì là giá trị của cái node trong heap