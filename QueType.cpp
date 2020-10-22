#include "QueType.h"

template<class T>
QueType<T>::QueType() {
    maxQue = 500 + 1;
    items = new T[maxQue];
    makeEmpty();
}

template<class T>
QueType<T>::QueType(int max) {
    maxQue = max + 1;
    items = new T[maxQue];
    makeEmpty();
}

template<class T>
QueType<T>::~QueType() {
    delete[] items;
}

template<class T>
void QueType<T>::makeEmpty() {
    front = maxQue - 1;
    rear = maxQue - 1;
}

template<class T>
bool QueType<T>::isEmpty() const {
    return front == rear;
}

template<class T>
bool QueType<T>::isFull() const {
    return (rear + 1) % maxQue == front;
}

template<class T>
void QueType<T>::enqueue(T newItem) {
    if(isFull()) {
        throw QueueOverflow();
    } 

    rear = (rear + 1) % maxQue;
    items[rear] = newItem;
}

template<class T>
void QueType<T>::dequeue(T& item) {
    if(isEmpty()) {
        throw QueueUnderflow();
    }

    front = (front + 1) % maxQue;
    item = items[front];
}

template<class T>
T QueType<T>::peek() {
    if(isEmpty()) {
        throw QueueUnderflow();
    }

    return items[(front + 1) % maxQue];
}

template<class T>
int QueType<T>::length() {
    if(front <= rear) {
        return rear - front;
    } else {
        return maxQue - front + rear;
    }
}

template<class T>
void QueType<T>::printQueue(ofstream& output) {
    int current = front;
    for(int i = 0; i < length(); i++) {
        current = (current + 1) % maxQue;
        output << items[current] << ' ';
    }

    output << endl;
}
