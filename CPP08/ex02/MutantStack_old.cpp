#include "MutantStack.hpp"

//--------------------------------Constructors--------------------------------//
template <typename T>
MutantStack<T>::MutantStack () : stack_size(0), lst() {
	//std::cout << "Default constructor MutantStack called" << std::endl << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & src) : stack_size(src.stack_size), \
	lst(src.lst) {
	//std::cout << "Copy constructor MutantStack called" << std::endl << std::endl;
}

//---------------------------------Destructor---------------------------------//
template <typename T>
MutantStack<T>::~MutantStack() {
	//std::cout << "Destructor MutantStack called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//
template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & rhs) {
	//std::cout << "Copy assignment operator MutantStack called" << std::endl << std::endl;
	 if (this != &rhs) {
        lst = rhs.lst;
        stack_size = rhs.stack_size;
    }
	return *this;
}

//-------------------------------Member functions------------------------------//
template <typename T>
T & MutantStack<T>::top(void) {
	if (lst.empty())
        throw std::exception();
	return(lst.front());
}

template <typename T>
bool MutantStack<T>::empty(void) {
	return lst.empty();
}

template <typename T>
size_t MutantStack<T>::size(void) {
	return stack_size;
}

template <typename T>
void MutantStack<T>::push(const T & new_element) {
	this->lst.push_front(new_element);
}

template <typename T>
void MutantStack<T>::emplace(const T & new_element) {
	this->lst.emplace_front(new_element);
}

template <typename T>
void MutantStack<T>::pop(void) {
	if (lst.empty())
        throw std::exception();
	this->lst.pop_front();
}

template <typename T>
void MutantStack<T>::swap(MutantStack<T> & other) {
    lst.swap(other.lst);
    std::swap(stack_size, other.stack_size);
}

//-----------------------------iterators------------------------------//
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return iterator(this->lst.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    typename std::list<T>::iterator it = this->lst.begin();
    std::advance(it, stack_size);
    return iterator(it);
}