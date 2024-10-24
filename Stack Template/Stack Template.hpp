#pragma once

template<class T>
class Stack {
	T* arr;
	unsigned int elements;
	unsigned int maximumElements;
public:
	Stack() {
		elements = 0;
		maximumElements = 0;
		arr = nullptr;
	}
	Stack(unsigned int maximumElements) {
		this->maximumElements = maximumElements;
		arr = new T[maximumElements];
		elements = 0;
	}
	Stack(Stack &otherStack) {
		elements = otherStack.Elements();
		arr = new T[elements];
		maximumElements = otherStack.MaximumElements();
		for (int i = 0; i < elements; i++)
			arr[i] = otherStack.Get(i);
	}
	~Stack() {
		delete[] arr;
	}
	bool Empty() {
		return elements == 0;
	}
	unsigned int Elements() {
		return elements;
	}
	unsigned int MaximumElements() {
		return maximumElements;
	}
	unsigned int Size() {
		return sizeof(arr);
	}
	void Resize(unsigned int newMaximum) {
		T* newArr = new T[newMaximum];
		int i = 0;
		while (i < elements && i < newMaximum) {
			newArr[i] = arr[i];
			i++;
		}
		elements = i;
		delete[] arr;
		arr = newArr;
	}
	void Push(T data) {
		if (elements < maximumElements) {
			arr[elements] = data;
			elements++;
		}
		//else {}
	}
	T Pop() {
		if (!Empty()) {
			T temp = arr[elements - 1];
			elements--;
			return temp;
		}
		//else {}
	}
	T Get(unsigned int position) {
		if (!Empty() && position < elements) {
			return arr[position];
		}
		//else{}
	}
	void Print() {}
	void ReversePrint() {}
};