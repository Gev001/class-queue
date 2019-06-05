#include<iostream>
using namespace std;
template<typename T>
class Queue {
public:
	Queue() : m_size(0), m_cap(100) { m_q = new T[m_cap]; cout << "defoult ctor \n"; }//defoult ctor
	Queue(T *x1)//par ctor
	{

		cout << "par ctor \n";
		m_q = x1;
	}

	~Queue() { delete[] m_q; m_q = nullptr; }///dtor????

	Queue(const Queue<T>&other)//copy
	{
		cout << "copy cttor \n";
		m_size = other.m_size;
		m_cap = other.m_cap;
		m_q = new T[m_cap];
		for (int i = 0; i < m_size; ++i)
			m_q[i] = other.m_q[i];
	}

	Queue(Queue<T>&&other)//move copy
	{
		cout << "move ctor \n";
		m_size = other.m_size;
		m_cap = other.m_cap;
		m_q = other.m_q;
		other.m_q = nullptr;
	}


	Queue<T>& operator=(Queue<T>&other) //assigment operator
	{
		if (this = &other) { return *this; }
		else {
			cout << "move assigment operator c \n";
			m_size = other.m_size;
			m_cap = other.m_cap;
			m_q = new T[m_cap];
			for (int i = 0; i < m_size; ++i)
				m_q[i] = other.m_q[i];
		}
	}

	Queue<T>& operator=(Queue<T>&&other) //move assigment
	{
		if (this == &other) { return *this; }
		else {
			cout << "assigment operator c \n";
			m_size = other.m_size;
			m_cap = other.m_cap;
			m_q = other.m_q;
			other.m_q = nullptr;
		}
	}


	bool empty() { return size == 0; }
	void reserve(unsigned m_cap1) { m_q = new T[m_cap1]; }
	const int size()const { return m_size; }
	const int capasity()const { return  m_cap; }
	void clear() { m_size = 0; }


	void push_back(T val)
	{
		if (m_cap < m_size) { m_q[m_size++] = val; }
		else
		{
			m_cap *= 2;
			T*current = new T[m_cap];
			for (unsigned i = 0; i < m_size; ++i)
			{
				current[i] = m_q[i];
			}
			delete[] m_q;
			m_q = current;
			m_q[m_size++] = val;
		}
	}

	void pop_front()
	{
		for (unsigned int i = 0; i < m_size; ++i)
		{
			m_q[i] = m_q[i + 1];
		}
		--m_size;
	}
	const int front() { return m_q[0]; }
	const T top() { return m_q[--m_size]; }


	Queue<T>& operator[](unsigned int index) //?
	{
		return m_q[index];
	}
private:
	T* m_q;
	unsigned m_size;
	unsigned m_cap;
};
#pragma once
