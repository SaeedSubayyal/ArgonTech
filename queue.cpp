#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Queue {

public:

int front,rear,capacity;
int* queue;

Queue(int c){
		front = rear = 0;
		capacity = c;
		queue = new int;
	}

	~Queue() {
         delete[] queue; 
        }

void queue_enqueue(int data){

		if (capacity == rear) {
			cout<<"Queue is full\n";
			return;
		}
		else {
			queue[rear] = data;
			rear++;
		}
		return;
}

void queue_dequeue(){

		if (front == rear) {
			cout<<"Queue is empty\n";
		}
		else {
			for (int i = 0; i < rear - 1; i++) {
				queue[i] = queue[i + 1];
			}
			rear--;
		}
}

void queue_display(){
		int i;
		if (front == rear) {
            cout<<"Queue is Full\n";
		}
		for (i = front; i < rear; i++) {
			cout<<queue[i]<<endl;
		}
		return;
}

void queue_front(){

		if (front == rear) {
			cout<<"Queue is Empty\n";
			return;
		}
		cout<<"Front element: "<<queue[front]<<endl;
		return;
	}

};

int main(){

	Queue q(4);

	q.queue_display();


	q.queue_enqueue(210);
	q.queue_enqueue(302);
	q.queue_enqueue(403);
	q.queue_enqueue(501);

	q.queue_display();


	q.queue_enqueue(601);

	q.queue_display();

	q.queue_dequeue();
	q.queue_dequeue();


	q.queue_display();

	q.queue_front();
    return 0;
}