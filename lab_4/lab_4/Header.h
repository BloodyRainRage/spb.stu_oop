#pragma once
#ifndef  HEADER_H
#define HEADER_H
#include <vector>

using namespace std;


class Deque {

public:
	vector<int>		vect;
	
    Deque() {
        vect.clear();
        for (int i = 0; i <= 10; ++i)
            vect.push_back(i);
    }

    class iterator {

    public:
    public:
        typedef int  value_type;
        typedef int& reference;
        typedef int* pointer;

        typedef std::bidirectional_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;
        typedef std::ptrdiff_t distance_type;

        iterator(const  int* value = pointer()) {
            position_ = const_cast<pointer>(value);
        };

        iterator& operator ++ () {
            ++position_;
            return *this;
        }

        iterator operator ++ (int) {
            return iterator(position_++);
        }


        iterator& operator -- () {
            --position_;
            return *this;
        }

        iterator operator --(int) {
            return(position_--);
        }

        value_type operator*() {
            int num = 1;
            for (int i = 1; i <= *position_; i++)
                num = num * i;
            return num;
        }

        bool operator !=(const iterator& value) {
            return position_ != value.position_;
        }

        bool operator ==(const iterator& value) {
            return position_ == value.position_;
        }


    protected:
        pointer position_;

    };
	
    iterator begin() {
        return iterator(&vect[0]); 
    }
    iterator end() { 
        return iterator(&vect[9] + 1); 
    }


};



#endif // ! HEADER_H

