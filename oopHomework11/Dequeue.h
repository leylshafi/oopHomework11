#pragma once
template<typename T, int SIZE = 10>
class Deque
{
	T arr[SIZE]{};
	int _front = -1;
	int _rear = -1;

public:
	Deque() = default;

	void push_front(T item) {  
		if (isFull())
			throw "Queue is full";


		if (_rear == -1)
			_rear = 0;

		_front = (_front + 1) % SIZE;

		arr[_front] = item;
		
	}

	void push_rear(T item) {
		if (isFull())
			throw "Queue is full";


		if (isEmpty())
			_front = 0;

		_rear = (_rear + 1) % SIZE;

		arr[_rear] = item;
	}
	void pop_front() {
		if (isEmpty())
			throw "Queue is empty";
		if (_front == _rear)
		{
			_rear = -1;
			_front = -1;
		}
		else
			_rear = (_rear - 1) % SIZE;
	}
	void pop_rear() {
		if (isEmpty())
			throw "Queue is empty";
		if (_front == _rear)
		{
			_rear = -1;
			_front = -1;
		}
		else
			_front = (_front + 1) % SIZE;
	}
	bool isFull() const {
		return (_rear + 1) % SIZE == _front;
	}
	bool isEmpty()const {
		return _front == -1;
	}
	const T& front()const { return arr[_front]; }
	const T& rear()const { return arr[_rear]; }

	int size() const
	{
		if (isEmpty())
			return 0;

		if (_rear >= _front)
			return _rear - _front + 1;

		return SIZE - (_front - _rear - 1);
	};

	void display() const
	{
		if (isEmpty())
			throw "Queue is empty";


		cout << "Front -> " << _front << endl;
		cout << "Rear -> " << _rear << endl;


		cout << "Items -> ";

		int i;
		for (i = _front; i != _rear; i = (i + 1) % SIZE)
			cout << arr[i] << ' ';
		cout << arr[i] << endl;
	}
};