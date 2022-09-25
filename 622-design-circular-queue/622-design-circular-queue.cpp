class MyCircularQueue {
    vector<int>arr;
    int front = 0, rear =-1, sz;
    //front-- position which element is deleted
    //rear--where we just inserted an element 
    //sz-- max size
public:
    MyCircularQueue(int k) {
        arr.resize(k);
        sz=k;
        
    }
    
    bool enQueue(int value) {
        //check if arr is full, we can't insert more
        if(isFull()) return false;
        //otherwise, rear move to next position, we insert there
        rear=(rear +1)% sz;
        //assign value
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        //if array is empty, we can't delete
        if(isEmpty()) return false;
        //front==rear, means array has only 1 element , so we restart both pointers
        if(front == rear){
            front=0,rear=-1;
        } else { //else just increase the front, to point next value
            front = (front +1)% sz;
        }
        return true;
    }
    
    int Front() {
        //if empty, we can't get any element , return -1 else return front
        return isEmpty()? -1: arr[front];
    }
    
    int Rear() {
        //if empty, we can't get any element , return -1 else return rear
        return isEmpty()? -1: arr[rear];
    }
    
    bool isEmpty() {
        //ir rear == -1, we haven't inserted any, so it's empty.
        return rear == -1;
    }
    
    bool isFull() {
        //for full condition,
        //1. array shouldn't be empty
        //2. next value of rear shouldn't be front
        return !isEmpty() and (rear +1 )%sz == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */