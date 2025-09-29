#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 10;   // tối đa số sản phẩm trong kho
const int MAX_QUEUE = 20;   // tối đa số khách hàng trong hàng đợi

// ------------------ Cấu trúc dữ liệu -------------------
struct Item {
    string name;
    int quantity;
    double price;
};

struct Customer {
    string itemName;
    int buyQuantity;
};

struct Queue {
    Customer data[MAX_QUEUE];
    int front, rear, size;
};

// ------------------ Hàng đợi -------------------
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
bool isEmpty(Queue *q) { return q->size == 0; }
bool isFull(Queue *q) { return q->size == MAX_QUEUE; }

void enqueue(Queue *q, Customer c) {
    if (isFull(q)) {
        cout << "Queue full!\n";
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE;
    q->data[q->rear] = c;
    q->size++;
    cout << "Added customer wants " << c.buyQuantity << " " << c.itemName << "\n";
}

Customer dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue empty!\n";
        return {"", 0};
    }
    Customer c = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE;
    q->size--;
    return c;
}

// ------------------ Xử lý -------------------
void displayItems(Item *items, int n) {
    cout << "\n--- INVENTORY ---\n";
    for (int i = 0; i < n; i++) {
        cout << items[i].name 
             << " | Quantity: " << items[i].quantity 
             << " | Price: " << items[i].price << "\n";
    }
    cout << "-----------------\n";
}

void processCustomer(Customer c, Item *items, int n) {
    for (int i = 0; i < n; i++) {
        if (items[i].name == c.itemName) {
            if (items[i].quantity >= c.buyQuantity) {
                items[i].quantity -= c.buyQuantity;
                cout << "Customer bought " << c.buyQuantity 
                     << " " << c.itemName << " successfully.\n";
            } else {
                cout << "Not enough stock for " << c.itemName << "!\n";
            }
            return;
        }
    }
    cout << "Item " << c.itemName << " not found!\n";
}

// ------------------ MAIN -------------------
int main() {
    int nItems;
    cout << "Nhap so luong san pham trong kho: ";
    cin >> nItems;

    Item items[MAX_ITEMS];
    for (int i = 0; i < nItems; i++) {
        cout << "Nhap ten san pham thu " << i+1 << ": ";
        cin >> items[i].name;
        cout << "Nhap so luong: ";
        cin >> items[i].quantity;
        cout << "Nhap gia: ";
        cin >> items[i].price;
    }

    Queue q;
    initQueue(&q);

    while (1) {
        int choice;
        cout << "\n===== MENU =====\n";
        cout << "1. Them khach hang vao hang doi\n";
        cout << "2. Phuc vu khach hang (dequeue)\n";
        cout << "3. Xem ton kho\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        if (choice == 1) {
            Customer c;
            cout << "Nhap ten san pham: ";
            cin >> c.itemName;
            cout << "Nhap so luong muon mua: ";
            cin >> c.buyQuantity;
            enqueue(&q, c);
        } 
        else if (choice == 2) {
            if (!isEmpty(&q)) {
                Customer c = dequeue(&q);
                processCustomer(c, items, nItems);
            } else {
                cout << "Hang doi trong!\n";
            }
        } 
        else if (choice == 3) {
            displayItems(items, nItems);
        } 
        else if (choice == 4) {
            cout << "Thoat chuong trinh.\n";
            break;
        } 
        else {
            cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}







------------------------ linked list


#include <iostream>
#include <string>
using namespace std;

// ------------------ Cấu trúc dữ liệu -------------------
struct Item {
    string name;
    int quantity;
    double price;
};

struct Customer {
    string itemName;
    int buyQuantity;
};

// Node của linked list
struct Node {
    Customer data;
    Node* next;
};

// Queue bằng linked list
struct Queue {
    Node* front;
    Node* rear;
    int size;
};

// ------------------ Các hàm xử lý -------------------
void initQueue(Queue &q) {
    q.front = q.rear = nullptr;
    q.size = 0;
}

bool isEmpty(Queue q) {
    return q.size == 0;
}

void enqueue(Queue &q, Customer c) {
    Node* newNode = new Node{c, nullptr};
    if (isEmpty(q)) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
    q.size++;
    cout << "Added customer wants " << c.buyQuantity 
         << " " << c.itemName << "\n";
}

Customer dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue empty!\n";
        return {"", 0};
    }
    Node* temp = q.front;
    Customer c = temp->data;
    q.front = q.front->next;
    if (q.front == nullptr) q.rear = nullptr; 
    delete temp;
    q.size--;
    return c;
}

void clearQueue(Queue &q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    cout << "Queue cleared.\n";
}

// ------------------ Xử lý -------------------
void displayItems(Item items[], int n) {
    cout << "\n--- INVENTORY ---\n";
    for (int i = 0; i < n; i++) {
        cout << items[i].name 
             << " | Quantity: " << items[i].quantity 
             << " | Price: " << items[i].price << "\n";
    }
    cout << "-----------------\n";
}

void processCustomer(Customer c, Item items[], int n) {
    for (int i = 0; i < n; i++) {
        if (items[i].name == c.itemName) {
            if (items[i].quantity >= c.buyQuantity) {
                items[i].quantity -= c.buyQuantity;
                cout << "Customer bought " << c.buyQuantity 
                     << " " << c.itemName << " successfully.\n";
            } else {
                cout << "Not enough stock for " << c.itemName << "!\n";
            }
            return;
        }
    }
    cout << "Item " << c.itemName << " not found!\n";
}

void displayQueue(Queue q) {
    cout << "\n--- CUSTOMERS IN QUEUE ---\n";
    Node* cur = q.front;
    int i = 1;
    while (cur != nullptr) {
        cout << i++ << ". " << cur->data.buyQuantity 
             << " " << cur->data.itemName << "\n";
        cur = cur->next;
    }
    if (i == 1) cout << "Queue is empty.\n";
    cout << "--------------------------\n";
}

// ------------------ MAIN -------------------
int main() {
    int nItems;
    cout << "Nhap so luong san pham trong kho: ";
    cin >> nItems;

    Item items[20];
    for (int i = 0; i < nItems; i++) {
        cout << "Nhap ten san pham thu " << i+1 << ": ";
        cin >> items[i].name;
        cout << "Nhap so luong: ";
        cin >> items[i].quantity;
        cout << "Nhap gia: ";
        cin >> items[i].price;
    }

    Queue q;
    initQueue(q);

    while (1) {
        int choice;
        cout << "\n===== MENU =====\n";
        cout << "1. Them khach hang vao hang doi\n";
        cout << "2. Phuc vu khach hang (dequeue)\n";
        cout << "3. Xem ton kho\n";
        cout << "4. Xem khach hang trong hang doi\n";
        cout << "5. Thoat\n";
        cout << "6. Xem tong so khach hang trong hang doi\n";
        cout << "7. Xoa tat ca khach hang trong hang doi\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        if (choice == 1) {
            Customer c;
            cout << "Nhap ten san pham: ";
            cin >> c.itemName;
            cout << "Nhap so luong muon mua: ";
            cin >> c.buyQuantity;
            enqueue(q, c);
        } 
        else if (choice == 2) {
            if (!isEmpty(q)) {
                Customer c = dequeue(q);
                processCustomer(c, items, nItems);
            } else {
                cout << "Hang doi trong!\n";
            }
        } 
        else if (choice == 3) {
            displayItems(items, nItems);
        } 
        else if (choice == 4) {
            displayQueue(q);
        } 
        else if (choice == 5) {
            cout << "Thoat chuong trinh.\n";
            break;
        }
        else if (choice == 6) {
            cout << "So khach dang cho: " << q.size << "\n";
        }
        else if (choice == 7) {
            clearQueue(q);
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}
