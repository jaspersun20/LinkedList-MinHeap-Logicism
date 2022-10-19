#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate

template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
    size_t size_;    
};

// Constructor
template<typename T>
Stack<T>::Stack()
{   
  size_=0;
}

// Deconstructor
template<typename T>
Stack<T>::~Stack(){
	while(!Stack<T>::empty()){
		Stack<T>::pop();
	}
}

template<typename T>
bool Stack<T>::empty() const
{
	if(()==0){
			return true;
	}
	else{
			return false;
	}
}

template<typename T>
size_t Stack<T>::size() const
{
    return size_;
}

template<typename T>
void Stack<T>::push(const T& item)
{ // call inherited push_front()
    std::vector<T>::push_back(item); 
    size_++;
}

template<typename T>
void Stack<T>::pop()
{ 
    if(size_==0){
        throw std::overflow_error("Empty vector");
    }
    else{
        std::vector<T>::pop_back(); 
        size_--;
    }
}

template<typename T>
const T& Stack<T>::top() const
{
    if(size_==0){
        throw std::overflow_error("Empty vector");
    }
    else{
        return (*this)[size_-1];
    }
}








#endif