#include <bits/stdc++.h>
using namespace std;
#define capacity 100
typedef struct Stack{
    int data[capacity];
    int top;   // là size, cho bt có bao nhiêu phần tử trong 
} Stack;
int isFull(Stack *st) {
    return st->top >= capacity;  // hoặc >= MAX_SIZE - 1 nếu đếm từ 0
}

// Hàm kiểm tra stack có rỗng không
int isEmpty(Stack *st) {
    return st->top == 0;  // giả sử top = 0 khi rỗng
}
void init1(Stack *st){
    st->top = 0;
}  
Stack *init2(){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    st->top = 0;
    return st;
}
void push(Stack* st,int value){
    if(isFull(st)){
        printf("its full");
    }
    st->top++;
    st->data[st->top] = value;
}
void pop(Stack* st){
    st->top--;
}
void display(Stack* st){
    for(int i = 1; i<=st->top;i++){
        cout<<st->data[i];
    }
}
int main(){
    Stack s1;    // biến tĩnh
    int n;
    cin >> n;
    for(int i =0; i<n; i++){
        int value;
        scanf("%d",&value); 
        push(&s1,value);
    }
    pop(&s1);
    display(&s1);

    Stack *s2 = init2(); // biến động,         bây giờ s2 là con trỏ tới một ô nhớ trong heap
    push(s2, 100);
    push(s2, 200);
    display(s2);
   
    // Giải phóng nếu dùng malloc
    free(s2);

}