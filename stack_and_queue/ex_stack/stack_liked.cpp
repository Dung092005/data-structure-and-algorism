#include<iostream>
using namespace std;
typedef struct website{
    string title;
    string url;
}website;
typedef struct node{
    website data;
    node *next;
} node;
typedef struct stack_site{
    node *top;
} stack;
void init(stack *s){
    s->top = NULL;
}
bool isempty(stack*s){
    return s->top == NULL;
}
void push(stack *s,website w){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = w;
    newnode->next = s->top;
    s->top = newnode;
}
void pop(stack *s){
    node*temp = (node*)malloc(sizeof(node));
    if(isempty(s)){
        cout<< "stack empty";
    }
    temp = s->top;
    s->top = s->top->next;
    delete(temp);
}

void visit_web(stack* backward,stack* forward,website w,website* cur){
      if (cur->url != "") {            // đã có current trước đó
        push(backward, *cur);
    }       
    *cur = w;
    while(!isempty(forward)) pop(forward);
     cout << "Visit: " << cur->title << " (" << cur->url << ")\n";
}


void back(stack* backward,stack* forward,website *cur){
    if (isempty(backward)) {
        cout << "Không có website trước đó.\n";
        return;
    }
    push(forward,*cur);
    *cur = backward->top->data;
    pop(backward);
     cout << "Back to: " << cur->title << " (" << cur->url << ")\n";
}
void goforward(stack*backward,stack*forward,website*cur){
    if(isempty(forward)){
        cout<<"không có website nào để forward";
        return;
    }
    *cur = forward->top->data;
    push(backward,*cur);
    pop(forward);               
    cout << "Forward to: " << cur->title << " (" << cur->url << ")\n";

}
void display(stack s) {
    node* p = s.top;
    cout << "Stack (top -> bottom):\n";
    while (p != nullptr) {
        cout << "  " << p->data.title << " (" << p->data.url << ")\n";
        p = p->next;
    }
    cout << endl;
}

int main(){ 
    stack backward, forward;
    website current = {"", ""};
    init(&backward);
    init(&forward);
    
    visit_web(&backward, &forward, {"https://google.com", "Google"}, &current);
    visit_web(&backward, &forward, {"https://youtube.com", "YouTube"}, &current);
    visit_web(&backward, &forward, {"https://facebook.com", "Facebook"}, &current);
    visit_web(&backward, &forward, {"https://github.com", "GitHub"}, &current);
    back(&backward, &forward, &current);
    back(&backward, &forward, &current);
    goforward(&backward, &forward, &current);
    display(backward);
    display(forward);
    cout<<"current is : "<<current.title<<" and "<<current.url<<"\n";
    

    
    return 0; 
}










// s.top -> 3 -> 2 -> 1 -> NULL