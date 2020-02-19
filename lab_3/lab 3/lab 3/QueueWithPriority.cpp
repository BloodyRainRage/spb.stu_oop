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

void QueueWithPriority::print() {
	cout << endl;
	sortByPriority();
	for (auto it = queue.begin(); it != queue.end(); ++it) {
		pair<ElementPriority, QueueElement>  tmp = *it;
		string priority;
		switch (tmp.first) {
		case ElementPriority::HIGH: 
			priority = "HIGH"; break;
		case ElementPriority::LOW: 
			priority = "LOW"; break;
		case ElementPriority::NORMAL: 
			priority = "NORMAL"; break;
		}
		cout << "element:" << priority << " " << tmp.second.name << endl;
	}
}

QueueWithPriority::QueueWithPriority()
{
}

QueueWithPriority::~QueueWithPriority()
{
}
