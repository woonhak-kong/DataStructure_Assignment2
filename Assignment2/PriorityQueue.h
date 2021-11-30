#pragma once
#include "LinkedList.h"


// Lower priority number has higher priority in this class

template<class T>
class PriorityQueue
{
public:

	PriorityQueue()	{}
	~PriorityQueue()
	{
		// all data will be deleted when m_linkedList is deleted in LinkedList's destructor
	}


	// removing the first element of the linked list
	void Pop()
	{
		m_linkedList.Pop_Front();
	}

	LinkNode<T>* Front()
	{
		return m_linkedList.Begin();
	}

	void Push(T newData, int priority)
	{
		m_linkedList.PushByPriority(newData, priority);
	}

	int GetSize()
	{
		return m_linkedList.GetSize();
	}

private:
	LinkedList<T> m_linkedList;

};
