#include <iostream>

#include "PriorityQueue.h"





int main()
{
	PriorityQueue<int> list;

	list.Push(21, 23);
	list.Push(34, 56);
	list.Push(24, 23);
	list.Push(14, 98);
	list.Push(65, 34);
	list.Push(23, 36);
	list.Push(48, 12);
	list.Push(69, 26);
	list.Push(15, 1);
	list.Push(58, 7);
	list.Push(63, 5);


	std::cout << "\n--------------- After Push ----------------" << std::endl;
	LinkNode<int>* tmp = list.Front();
	while (tmp)
	{
		std::cout << tmp->GetData() << "(" << tmp->GetPriority() << ") ";
		tmp = tmp->Next();
	}
	std::cout << "Size = " << list.GetSize() << std::endl;


	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();

	std::cout << "\n--------------- After Pop 8 times ----------------" << std::endl;
	tmp = list.Front();
	while (tmp)
	{
		std::cout << tmp->GetData() << "(" << tmp->GetPriority() << ") ";
		tmp = tmp->Next();
	}
	std::cout << "Size = " << list.GetSize() << std::endl;


	std::cout << "\n--------------- After Push 50(50) ----------------" << std::endl;
	list.Push(50, 50);

	tmp = list.Front();
	while (tmp)
	{
		std::cout << tmp->GetData() << "(" << tmp->GetPriority() << ") ";
		tmp = tmp->Next();
	}
	std::cout << "Size = " << list.GetSize() << std::endl;

	std::cout << "\n--------------- Call Front() ----------------" << std::endl;
	std::cout << list.Front()->GetData() << "(" << list.Front()->GetPriority() << ") ";
	std::cout << "Size = " << list.GetSize() << std::endl;
	return 0;
}