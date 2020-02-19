// lab_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*В очередь могут быть добавлены элементы, каждому элементу 
	при добавлении присваивается один из трех уровней приоритета (low, normal, high)
	Элементы из очереди извлекаются в соответствии с их приоритетами (сначала извлекаются
	элементы с приоритетом high, потом normal, потом low), элементы с одинаковыми приоритетами 
	извлекаются из очереди в порядки их поступления. 
	В очереди также может происходить операция акселерации – 
	все элементы с приоритетом low находящиеся в момент акселерации 
	в очереди увеличивают свой приоритет до high и «обгоняют» элементы с приоритетом normal.
*/

#include <iostream>
#include "QueueWithPriority.h"
#include <algorithm>
#include <deque>
using namespace std;
bool MyDataSortPredicate(const pair<ElementPriority, QueueElement>& lhs, const pair<ElementPriority, QueueElement>& rhs) {
	bool b = lhs.first > rhs.first;
	return b;
}
int main()
{
	QueueWithPriority hospital ;
	hospital.PutElementToQueue(QueueElement("sick0"), ElementPriority::HIGH);
	hospital.PutElementToQueue(QueueElement("sick1"), ElementPriority::HIGH);
	hospital.PutElementToQueue(QueueElement("korona"), ElementPriority::HIGH);
	hospital.PutElementToQueue(QueueElement("orvi"), ElementPriority::NORMAL);
	hospital.PutElementToQueue(QueueElement("orvi"), ElementPriority::NORMAL);
	hospital.PutElementToQueue(QueueElement("orvi"), ElementPriority::NORMAL);
	hospital.PutElementToQueue(QueueElement("gemorrroy"), ElementPriority::LOW);
	hospital.PutElementToQueue(QueueElement("canser "), ElementPriority::NORMAL);
	hospital.PutElementToQueue(QueueElement("aaaa "), ElementPriority::NORMAL);
	hospital.PutElementToQueue(QueueElement("coronavirus"), ElementPriority::HIGH);
	hospital.PutElementToQueue(QueueElement("AIDS"), ElementPriority::LOW);
	hospital.PutElementToQueue(QueueElement("cold"), ElementPriority::LOW);
	hospital.print();
	QueueElement qe = hospital.GetElementFromQueue();
	hospital.PutElementToQueue(QueueElement("smth"), ElementPriority::LOW);
	hospital.Accelerate();
	qe = hospital.GetElementFromQueue();
	hospital.PutElementToQueue(QueueElement("smth"), ElementPriority::LOW);
	cout << qe.name << endl;
	 qe = hospital.GetElementFromQueue();
	 cout << qe.name << endl;
//	
	 cout << qe.name << endl;
	// qe = hospital.GetElementFromQueue();
	 cout << qe.name << endl;


}


