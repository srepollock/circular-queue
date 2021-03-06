#include "stdafx.h"
#include "CircularQueue.h"
#include <iostream>
CircularQueue::CircularQueue() {
	front = rear = -1;
	queue = new int[QUEUE_SIZE];
};
void CircularQueue::enQueue(int data) {
	if ((front == 0 && rear == -1) || (rear == front -1)) {
		std::cout << "\nQueue is full." << std::endl;
	}
	else if (front == -1) {
		front = rear = 0;
		queue[rear] = data;
	}
	else if (rear == QUEUE_SIZE - 1 && front != 0) {
		rear = 0;
		queue[rear] = data;
	}
	else {
		rear++;
		queue[rear] = data;
	}
};
int CircularQueue::deQueue() {
	if (front == -1) {
		std::cout << "\nQueue is emtpy." << std::endl;
		return -1;
	}
	int data = queue[front];
	queue[front] = -1;
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == QUEUE_SIZE - 1) {
		front = 0;
	}
	else {
		front++;
	}
	return data;
};

void CircularQueue::displayQueue()
{
	if (front == -1)
	{
		std::cout << "\nQueue is Empty" << std::endl;
		return;
	}
	std::cout << "\nElements in Circular Queue are: " << std::endl;
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			std::cout << queue[i] << std::endl;
	}
	else
	{
		for (int i = front; i < QUEUE_SIZE; i++)
			std::cout << queue[i] << std::endl;

		for (int i = 0; i <= rear; i++)
			std::cout << queue[i] << std::endl;
	}
};

int main()
{
	CircularQueue *queue = new CircularQueue();
	queue->displayQueue();
	queue->enQueue(1);
	queue->enQueue(2);
	queue->enQueue(3);
	queue->displayQueue();
	std::cout << "\n" << queue->deQueue() << std::endl;
	queue->displayQueue();
	queue->enQueue(15);
	queue->displayQueue();
	std::cout << "\n" << queue->deQueue() << std::endl;
	std::cout << "\n" << queue->deQueue() << std::endl;
	std::cout << "\n" << queue->deQueue() << std::endl;
	queue->displayQueue();
	return 0;
};