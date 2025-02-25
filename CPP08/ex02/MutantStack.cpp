#include "MutantStack.hpp"

//--------------------------------Constructors--------------------------------//
template <typename T>
MutantStack<T>::MutantStack () : stack_size(0), lst(nullptr) {
	//std::cout << "Default constructor MutantStack called" << std::endl << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & src) : stack_size(src.stack_size) {
	//std::cout << "Copy constructor MutantStack called" << std::endl << std::endl;
	if (src == nullptr)
		throw std::exception();
	for (size_t i = 0; i < stack_size; i++) // can we use foreach?
		this->pop();
	stack_size = src.stack_size;
	this->iterator it = src.begin();
	this->iterator ite = src.end();
	while (it != ite)
	{
		this->push(*it); // will elements be pushed in a correct order?
		++it;
	}
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
	if (rhs.lst == nullptr)
		throw std::exception();
	if (this != &rhs) {
		for (size_t i = 0; i < stack_size; i++) // can we use foreach?
			this->pop();
		stack_size = rhs.stack_size;
		MutantStack<T>::iterator it = rhs.begin();
		MutantStack<T>::iterator ite = rhs.end();
		while (it != ite)
		{
			this->push(*it); // will elements be pushed in a correct order?
			++it;
		}
	}
	return *this;
}

//-------------------------------Member functions------------------------------//
template <typename T>
T & MutantStack<T>::top(void) {
	if (rhs.lst == nullptr)
		throw std::exception();
	return(lst.begin());
}

template <typename T>
bool MutantStack<T>::empty(void) {
	if (stack_size == 0)
		return true;
	else
		return false;
}

template <typename T>
size_t MutantStack<T>::size(void) {
	return stack_size;
}

template <typename T>
void MutantStack<T>::push(const T & new_element) {
	if (rhs.lst == nullptr)
		throw std::exception();
	this->lst.push_front(new_element);
}

template <typename T>
void MutantStack<T>::emplace(const T & new_element) {
	if (rhs.lst == nullptr)
		throw std::exception();
	this->lst.emplace_front(new_element);
}

template <typename T>
void MutantStack<T>::pop(void) {
	if (rhs.lst == nullptr)
		throw std::exception();
	this->lst.pop_front;
}

template <typename T>
void MutantStack<T>::swap (T & other) {
	if (other == nullptr || lst == nullptr)
		throw std::exception();
	this->lst.swap(other);
}

//-----------------------------Iterators------------------------------//
template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::begin() {
    return Iterator(this->lst); // correct?
}

template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::end() {
    return Iterator(this->lst + stack_size); // correct?
}