#pragma once
class CircularQueue {
public:
	/*
		Queue Size
		The Maximum size of the queue. Change the number here on implementation.
	*/
	const int QUEUE_SIZE = 5;
	/*
		Constructor
	*/
	CircularQueue();
	/*
		enQueue
		Add information to the back of the queue.
		parameter (int): an integer to add to the queue.
	*/
	void enQueue(int data);
	/*
		deQueue
		Remove the data at the front of the array.
	*/
	int deQueue();
	/*
		Display Queue
		Diaplays the current queue to the console in a friendly format.
	*/
	void displayQueue();
private:
	/*
		Front queue index
		Rear queue index
	*/
	int front, rear;
	/*
		Pointer to the queue array
	*/
	int *queue;
};