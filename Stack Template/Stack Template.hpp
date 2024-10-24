	#pragma once

//	Stack class template
//	====================
	template<class T>
	class Stack {

//		Private Member Variables
//		========================
		T* arr;
		unsigned int elements;
		unsigned int maximumElements;
//		=============================

//	Public Member Functions
//	=======================
	public:

//		Zero-parameter constructor
//		==========================
		Stack() {
			elements = 0;
			maximumElements = 0;
			arr = nullptr;
		} // Stack()
//		============

//		Maximum size constructor
//		=====================================
		Stack(unsigned int maximumElements) {
			this->maximumElements = maximumElements;
			arr = new T[maximumElements];
			elements = 0;
		} // Stack(unsigned int)
//		========================

//		Copy constructor
//		==========================
		Stack(Stack &otherStack) {
			elements = otherStack.Elements();
			arr = new T[elements];
			maximumElements = otherStack.MaximumElements();
			for (int i = 0; i < elements; i++)
				arr[i] = otherStack.Get(i);
		} // Stack(Stack)
//		=================

//		Destructor
//		==========
		~Stack() {
			delete[] arr;
		} // ~Stack()
//		=============

//		Returns true if the stack is empty
//		==================================
		bool Empty() {
			return elements == 0;
		} // Empty()
//		============

//		Returns the number of elements in the stack
//		===========================================
		unsigned int Elements() {
			return elements;
		} // Elements()
//		===============

//		Returns the maximum number of elements that can be stored in the stack
//		======================================================================
		unsigned int MaximumElements() {
			return maximumElements;
		} // MaximumElements()
//		======================

//		Returns the size occupied by the stack in memory
//		================================================
		unsigned int Size() {
			return sizeof(arr);
		} // Size()
//		===========

//		Changes the maximum elements that can be stored in the stack
//		============================================================
		void Resize(unsigned int newMaximum) {
			T* newArr = new T[newMaximum];
			int i = 0;
//			========================================
			while (i < elements && i < newMaximum) {
				newArr[i] = arr[i];
				i++;
			} // while
//			==========
			elements = i;
			delete[] arr;
			arr = newArr;
		} // Resize(unsigned int)
//		=========================

//		Pushes an element onto the stack
//		================================
		void Push(T data) {
			if (elements < maximumElements) {
				arr[elements] = data;
				elements++;
			}
			//else {}
		} // Push(T)
//		============

//		Removes an element from the top of the stack and returns the popped element
//		===========================================================================
		T Pop() {
			if (!Empty()) {
				T temp = arr[elements - 1];
				elements--;
				return temp;
			}
			//else {}
		} // Pop()
//		==========

//		Returns the element at the top of the stack
//		===========================================
		T GetTop() {
			if (!Empty() && position < elements) {
				return arr[elements - 1];
			}
		} // GetTop()
//		=============

//		Returns the element at a specified position in the stack
//		========================================================
		T Get(unsigned int position) {
			if (!Empty() && position < elements) {
				return arr[position];
			}
			//else{}
		} // Get()
//		==========

//		Undefined Member Functions
//		==========================
		void Print() {}
		void ReversePrint() {}
//		======================

	}; // class Stack<T> {}
//	=======================