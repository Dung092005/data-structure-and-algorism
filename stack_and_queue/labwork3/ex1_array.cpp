#include<bits/stdc++.h>
using namespace std;

#define max_number 100 

struct item {
    string name;
    int quality;
    int price;
};

struct customer {
    int amount_pro;
    string product_name;
};

struct queuee {
    customer data[max_number];
    int size;
};

void init(queuee* a) {
    a->size = 0;
}

bool isfull(queuee* a) {
    return a->size == max_number;
}

bool isempty(queuee* a) {
    return a->size == 0;
}

void push(queuee* a, customer c) {
    if (isfull(a)) {
        cout << "Queue full, cannot add customer!\n";
        return;
    }
    a->data[a->size] = c;
    a->size++;
}

void pop(queuee* a, item store[], int n) {
    if (isempty(a)) {
        cout << "Queue rong, khong the pop!\n";
        return;
    }
    customer c = a->data[0];
    for (int i = 0; i < a->size - 1; i++) {
        a->data[i] = a->data[i + 1];
    }
    a->size--;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (c.product_name == store[i].name) {
            found = true;
            if (store[i].quality >= c.amount_pro) {
                store[i].quality -= c.amount_pro;
                cout << " Successfully purchased " 
                     << c.product_name 
                     << " with quantity " << c.amount_pro << endl;
            } else {
                cout << " Not enough product to buy\n";
            }
            break;
        }
    }
    if (!found) cout << " Cannot find this product in store\n";
}

void display_cus(customer c) {
    cout << "Product name: " << c.product_name 
         << " | Quantity: " << c.amount_pro << endl; 
}

void display(queuee* a) {
    if (isempty(a)) {
        cout << "Queue rong!\n";
        return;
    }
    for (int i = 0; i < a->size; i++) {
        display_cus(a->data[i]);
    }
}

void display_item(item store[], int n) {
    cout << "=== Store items ===\n";
    for (int i = 0; i < n; i++) {
        cout << store[i].name << endl;
        cout << "Quantity: " << store[i].quality << endl;
        cout << "Price: " << store[i].price << endl;
    }
}

int main () {
    item store[3] = {
        {"laptop", 5, 400}, 
        {"phone", 4, 4000}, 
        {"chair", 6, 3000}
    };
    int n = 3;

    queuee a; 
    init(&a);

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add customer\n";
        cout << "2. Process one customer (pop)\n";
        cout << "3. Process all customers\n";
        cout << "4. Display queue\n";
        cout << "5. Display store\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 0) break;
        
        if (choice == 1) {
            customer c;
            cout << "Nhap ten san pham va so luong: ";
            cin >> c.product_name >> c.amount_pro;
            push(&a, c);
        }
        else if (choice == 2) {
            pop(&a, store, n);
        }
        else if (choice == 3) {
            while (!isempty(&a)) {
                pop(&a, store, n);
            }
        }
        else if (choice == 4) {
            display(&a);
        }
        else if (choice == 5) {
            display_item(store, n);
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }
    }
}
