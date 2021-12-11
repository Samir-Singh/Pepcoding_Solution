class MyCircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
    int originalSize;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        size = k;
        originalSize = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) 
            return false;
        rear = (rear+1)%size;
        arr[rear] = value;
        originalSize++;
        if(front == -1)
            front = 0;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front+1)%size;
        originalSize--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(originalSize == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(originalSize == size) return true;
        return false;
    }
};