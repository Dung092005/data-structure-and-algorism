#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct item {
    char name[50];
    int quality;
    int price;
} item;

typedef struct customer {
    char product_name[50];
    int amount;
} customer;

typedef struct node {
    customer data;
    struct node *next;
} node;

typedef struct queue {
    node* front;
    node* back;
} queue;

void init(queue *a) {
    a->front = a->back = NULL;
}

int isEmpty(queue *a) {
    return a->front == NULL;
}

void enqueue(queue *a, customer c) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = c;
    newnode->next = NULL;
    if (isEmpty(a)) {
        a->front = a->back = newnode;
    } else {
        a->back->next = newnode;
        a->back = newnode;
    }
}

void dequeue(queue *a, item it[], int nitem) {
    if (a->front == NULL) {
        printf("QUEUE EMPTY\n");
        return;
    }

    node* temp = a->front;
    customer c = a->front->data;
    a->front = a->front->next;
    if (a->front == NULL) a->back = NULL;
    free(temp);

    int found = 0;
    for (int i = 0; i < nitem; i++) {
        if (strcmp(it[i].name, c.product_name) == 0) {
            found = 1;
            if (it[i].quality >= c.amount) {
                it[i].quality -= c.amount; // cập nhật kho
                printf("YOU BOUGHT %s with quantity %d\n",
                       c.product_name, c.amount);
                printf("Total Money: %d\n", c.amount * it[i].price);
            } else {
                printf("NOT ENOUGH %s\n", c.product_name);
            }
            break;
        }
    }
    if (!found) {
        printf("NO ITEM IN STORE\n");
    }
}

void displayStock(item it[], int n) {
    printf("--- Stock ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s | Quality : %d | Price : %d \n",
               it[i].name, it[i].quality, it[i].price);
    }
    printf("--------------\n");
}

int main() {
    item items[3] = {
        {"Laptop", 5, 1500},
        {"Phone", 4, 800},
        {"Chair", 6, 200}
    };
    int n = 3;
    queue q;
    init(&q);

    // Thêm khách hàng
    customer c1 = {"Laptop", 2};
    customer c2 = {"Phone", 3};
    customer c3 = {"Chair", 7};  // vượt quá số lượng
    customer c4 = {"Tablet", 1}; // không có trong stock

    enqueue(&q, c1);
    enqueue(&q, c2);
    enqueue(&q, c3);
    enqueue(&q, c4);

    // Hiển thị ban đầu
    displayStock(items, n);

    // Xử lý từng khách hàng theo FIFO
    while (!isEmpty(&q)) {
        dequeue(&q, items, n);
        displayStock(items, n);
    }

    return 0;
}
