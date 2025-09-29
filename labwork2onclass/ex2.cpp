#include<iostream>
using namespace std;

typedef struct Car{
    int capacity;
    int id;
    Car *next;
    int reserved; 
} Car;
typedef struct Train{
    Car*head;
    int size;
} train;

void initTrain(Train* mytrain){
    mytrain->head = NULL;
    mytrain->size = 0;
}
Car* createCar(int id,int capacity,int reserved){
    if(reserved > capacity) return NULL;
    
    Car *newCar = (Car*)malloc(sizeof(Car));
    newCar->id = id;
    newCar->capacity = capacity;
    newCar->reserved = reserved;
    newCar->next = NULL;
    return newCar;
}
void addCar(train *train,int id, int capacity, int reserved){ 
    Car*newcar = createCar(id,capacity,reserved);
    if(train->head == NULL){
        train->head = newcar;
    }
    else{
        Car* temp = train->head;
        while(temp->next != NULL){
            temp = temp->next; 
        }
        temp->next = newcar;
    }
    train->size++;
}
void remove(train *train){
    Car* cur = train->head;
    Car* pre = NULL;
    while(cur != NULL){
        Car* temp = cur;
        if(cur->reserved == 0){
            if(pre == NULL){
                train->head = cur->next;
            }
            else{
                pre->next = cur->next;
            }
            free(temp);
            cur = cur->next;
        }
        else{
            pre = cur;
            cur = cur->next; 
        }
    }

    }

void display(Train* train){ 
    Car*temp = train->head;
    printf("the length of linkest list is : %d \n",train->size);
    while(temp != NULL){
        printf("capacity : %d, id : %d, reserved: %d",temp->capacity,temp->id,temp->reserved);
        printf("\n");
        temp = temp->next;
    }   
}

int main(){ 
    train mytrain;
    initTrain(&mytrain);
    int n;
    cout << "input amount of link list: ";
    cin >>n;
    for(int i = 0; i< n;i++){
        int id, cap,res;
        cin >> id >> cap >>res;
        addCar(&mytrain,id,cap,res);
    }
    remove(&mytrain);
    display(&mytrain);

}