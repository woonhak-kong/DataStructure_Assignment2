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


	LinkNode<int>* tmp = list.Begin();
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

	tmp = list.Begin();
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

	tmp = list.Begin();
	while (tmp)
	{
		std::cout << tmp->GetData() << "(" << tmp->GetPriority() << ") ";
		tmp = tmp->Next();
	}
	std::cout << "Size = " << list.GetSize() << std::endl;


	std::cout << list.Front()->GetData() << std::endl;

	return 0;
}