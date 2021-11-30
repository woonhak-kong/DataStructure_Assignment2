#pragma once
#include <cassert>
#include <iostream>

template <class T> class LinkedList;

template <class T>
class LinkNode
{
public:
	friend class LinkedList<T>;

	// basically m_priority is not used
	LinkNode() : m_priority(-1), m_next(nullptr), m_previous(nullptr) {}

	T GetData()
	{
		return m_data;
	}
	int GetPriority()
	{
		return m_priority;
	}
	LinkNode* Next()
	{
		return m_next;
	}
private:
	T m_data;
	int m_priority;
	LinkNode* m_next;	// Self-referencial Pointer
	LinkNode* m_previous;
};



// Linked List doesn't have to know Priority Queue
// So, delete functions related to PriorityQueue

template <class T>
class LinkedList
{
public:
	// Constructor and Destructor
	LinkedList() : m_size(0), m_root(nullptr), m_lastNode(nullptr) {}
	~LinkedList()
	{
		while (m_root)
		{
			Pop_Back();
		}
	}
	// --------------- POSITIONING FUNCTIONS ----------------------
	LinkNode<T>* Begin()
	{
		assert(m_root != nullptr);
		return m_root;
	}
	LinkNode<T>* End()
	{
		return nullptr;
	}
	LinkNode<T>* Last()
	{
		assert(m_lastNode != nullptr);
		return m_lastNode;
	}

	void Push_Front(T newData)
	{
		// Create a new node (new root node)
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != nullptr);
		node->m_data = newData;

		if (m_root != nullptr) // Linked List has at least 1 item
		{
			node->m_next = m_root;
			m_root->m_previous = node;
			m_root = node;
		}
		else // Linked list is empty
		{
			m_root = node;
			m_lastNode = node;
		}

		m_size++;
	}
	void Pop_Front()
	{
		assert(m_root != nullptr);

		// Create a temp that will allow us to delete the content as needed
		LinkNode<T>* temp = m_root;

		// Reroute pointers
		m_root = m_root->m_next;

		if (m_root != nullptr)
		{
			m_root->m_previous = nullptr;
		}
		else
		{
			m_lastNode = nullptr;
		}

		delete temp;
		temp = nullptr;

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}
	void Push_Back(T newData)
	{
		// Create a standalone LinkNode object
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != nullptr);
		node->m_data = newData;

		// Add the new LinkNode to the existing LinkedList
		if (m_lastNode != nullptr) // LinkedList is populated. Push to the end of the list.
		{
			m_lastNode->m_next = node;
			node->m_previous = m_lastNode;
		}
		else // An empty linked list
		{
			m_root = node;
		}

		m_lastNode = node;

		m_size++;
	}
	void Pop_Back()
	{
		assert(m_root != nullptr);

		// Check if there is only 1 node (aka just a root)
		if (m_root->m_next == nullptr)
		{
			delete m_root;
			m_root = nullptr;
			m_lastNode = nullptr;
		}
		else // Linked list has 2 or more items
		{
			LinkNode<T>* prevNode = m_lastNode->m_previous;

			// The previous while loop simply positioned the pointer to the 2nd last node in the list. We don't need traversal here.
			prevNode->m_next = nullptr;
			delete m_lastNode;
			m_lastNode = prevNode;
			prevNode = nullptr;
		}

		m_size = (m_size == 0 ? m_size : m_size - 1);	// Prevent negative sizes
	}


	// lower priority num has higher priority
	void PushByPriority(T newData, int priority)
	{
		LinkNode<T>* node = new LinkNode<T>;
		assert(node != nullptr);
		node->m_data = newData;
		node->m_priority = priority;

		// if list is empty
		if (m_root == nullptr)
		{
			m_root = node;
			m_lastNode = node;
		}
		else
		{
			// get node that has lower priority than parameter
			LinkNode<T>* nodeAfterThisPriority = GetNodeLowerPriority(priority);

			if (nodeAfterThisPriority != nullptr)
			{
				LinkNode<T>* tmp = nodeAfterThisPriority->m_previous;
				nodeAfterThisPriority->m_previous = node;

				// if tmp is null, nodeAfterThisPriority is m_root
				if (tmp != nullptr)
				{
					tmp->m_next = node;
				}
				else
				{
					m_root = node;
				}

				node->m_previous = tmp;
				node->m_next = nodeAfterThisPriority;
			}
			// if nullptr returns, this priority is lower than every things
			else
			{
				// just put at last place
				LinkNode<T>* tmp = m_lastNode;
				m_lastNode = node;
				tmp->m_next = node;

				node->m_previous = tmp;
				node->m_next = nullptr;

			}
		}
		m_size++;
	}



	int GetSize()
	{
		return m_size;
	}

private:
	int m_size;					// Holds the size of the linked list
	LinkNode<T>* m_root;		// Point to the root of the linked list
	LinkNode<T>* m_lastNode;	// Point to the last node of the linked list


private:

	LinkNode<T>* GetNodeLowerPriority(int priority)
	{
		LinkNode<T>* tmp = m_root;
		while (tmp)
		{
			if (tmp->m_priority > priority)
			{
				return tmp;
			}
			tmp = tmp->m_next;
		}

		// if there is no node
		return nullptr;
	}
};
