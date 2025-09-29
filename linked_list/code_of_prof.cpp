#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *pnext;
} Node;

typedef struct _List {
    int size;
    Node *pHead;
} List;

/* Khởi tạo danh sách */
void initList(List *l){
    l->size = 0;
    l->pHead = NULL;
}

/* Tạo node mới */
Node* createNode(int val){
    Node *node = (Node*) malloc(sizeof(Node));
    if (!node) return NULL;
    node->data = val;
    node->pnext = NULL;
    return node;
}

/* Chèn vào đầu */
void insertFirst(List *l, int val){
    Node *pnew = createNode(val);
    if (!pnew) return;

    pnew->pnext = l->pHead;
    l->pHead = pnew;
    l->size++;
}

/* Chèn vào cuối */
void insertLast(List *l, int val){
    Node *pnew = createNode(val);
    if (!pnew) return;

    if (l->pHead == NULL) {
        l->pHead = pnew;
    } else {
        Node *cur = l->pHead;
        while (cur->pnext != NULL) {
            cur = cur->pnext;
        }
        cur->pnext = pnew;
    }
    l->size++;
}

/* Xóa đầu */
Node* removeFirst(List *l){
    if (l->pHead == NULL) return NULL;

    Node *tmp = l->pHead;
    l->pHead = tmp->pnext;
    tmp->pnext = NULL;
    l->size--;
    return tmp;   // caller sẽ free(tmp)
}

/* In danh sách */
void printList(List *l){
    Node *cur = l->pHead;
    printf("List(size=%d): ", l->size);
    while (cur){
        printf("%d -> ", cur->data);
        cur = cur->pnext;
    }
    printf("NULL\n");
}

/* Main */
int main(void){
    List myList;
    initList(&myList);

    int n;
    printf("Nhap so luong node: ");
    scanf("%d", &n);

    printf("Nhap %d so:\n", n);
    for (int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        insertLast(&myList, val);  // dùng insertLast để giữ đúng thứ tự nhập
    }

    printf("Danh sach vua nhap:\n");
    printList(&myList);

    /* Thử removeFirst */
    Node *rm = removeFirst(&myList);
    if (rm){
        printf("Removed: %d\n", rm->data);
        free(rm);
    }

    printList(&myList);

    /* Giải phóng toàn bộ */
    while (myList.pHead != NULL){
        Node *tmp = removeFirst(&myList);
        free(tmp);
    }

    return 0;
}
