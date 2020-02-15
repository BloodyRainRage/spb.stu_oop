#pragma once

#include <string>
enum class ElementPriority
{
    HIGH = 3,
    NORMAL = 2 ,
    LOW = 1 
} ;

typedef struct QueueElement
{
    std::string name;
    QueueElement(string name) {
        this->name = name;
    }
    QueueElement() {}
};



