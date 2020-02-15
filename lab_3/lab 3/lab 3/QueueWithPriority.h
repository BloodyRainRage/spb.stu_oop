#pragma once
using namespace std; 

#include <string>
#include <list>
#include "struct.h"


class QueueWithPriority
{



    list<std::pair<ElementPriority, QueueElement > > queue;
    int count = 0 ; 
    bool sorted = false; 
    void sortByPriority() {
        if (sorted) return; 
        queue.sort( [](const pair<ElementPriority, QueueElement>& lhs, const pair<ElementPriority, QueueElement>& rhs) {
            return lhs.first > rhs.first;
            });
        sorted = true; 
    }
    public: 
        void PutElementToQueue(const QueueElement& element, ElementPriority priority);
        QueueElement GetElementFromQueue();

        void Accelerate();
        // Конструктор, создает пустую очередь
        QueueWithPriority();
        // Деструктор
        ~QueueWithPriority();
};