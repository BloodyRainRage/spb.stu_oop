#include "QueueWithPriority.h"
#include <algorithm>
#include <iostream>
void QueueWithPriority::PutElementToQueue(const QueueElement& element, ElementPriority priority)
{
		queue.push_back(make_pair(priority, element));
		if (ElementPriority::HIGH == priority ||
			ElementPriority::NORMAL == priority) ++count;
		sorted = false; 
}

QueueElement QueueWithPriority::GetElementFromQueue()
{
	
	pair<ElementPriority, QueueElement>  tmp = queue.front();
	this->sortByPriority();
	if (ElementPriority::HIGH == tmp.first ||
		ElementPriority::NORMAL == tmp.first) --count;
	queue.pop_front();

	return tmp.second;
}

void QueueWithPriority::Accelerate()
{
	auto it = queue.begin();
	advance(it, count);
	for (it; it != queue.end(); ++it) {
		it->first = ElementPriority::HIGH;
		count++;
	}
	this->sortByPriority();
}

QueueWithPriority::QueueWithPriority()
{
}

QueueWithPriority::~QueueWithPriority()
{
}
