#include "MutantStack.hpp"

int main(void) {
	const std::string line = "-------------------------";

//---------------------------------Testing with MutantStack-----------------------------//

	std::cout << std::endl << line << "Testing with MutantStack" << line  << std::endl << std::endl;
	
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Stack size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(22);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	//---------------------------------Testing with std::list-----------------------------//

	std::cout << std::endl << line << "Testing with std::list" << line  << std::endl << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Top element: " << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "Stack size: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(22);
	lst.push_back(0);

	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();

	++it2;
	--it2;

	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::stack<int, std::list<int>> s2(lst);

	//-------------------------------Testing the deep copy--------------------------------//

	std::cout << std::endl << line << "Testing the deep copy" << line  << std::endl << std::endl;

	MutantStack<int> copy_stack(mstack);

	copy_stack.pop();
	copy_stack.push(-5656565);

	it = mstack.begin();
	ite = mstack.end();

	while (it != ite)
	{
		std::cout << "Original stack: " << *it << std::endl;
		++it;
	}

	//-----------------------------Testing reverse iterators------------------------------//

	std::cout << std::endl << line << "Testing reverse iterators" << line  << std::endl << std::endl;

	MutantStack<int>::reverse_iterator itr = mstack.rbegin();
	MutantStack<int>::reverse_iterator iter = mstack.rend();

	while (itr != iter)
	{
		std::cout << *itr << std::endl;
		++itr;
	}


	//-----------------------------Testing constant iterators------------------------------//

	std::cout << std::endl << line << "Testing constant iterators" << line  << std::endl << std::endl;

	MutantStack<int>::const_iterator itc = mstack.cbegin();
	MutantStack<int>::const_iterator itec = mstack.cend();

	//*itc = 1; not possible because of const

	while (itc != itec)
	{
		std::cout << *itc << std::endl;
		++itc;
	}

	//-----------------------------Testing constant reverse iterators------------------------------//

	std::cout << std::endl << line << "Testing constant reverse iterators" << line  << std::endl << std::endl;

	MutantStack<int>::const_reverse_iterator itcr = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator itecr = mstack.crend();

	//*itcr = 1; not possible because of const

	while (itcr != itecr)
	{
		std::cout << *itcr << std::endl;
		++itcr;
	}

	return 0;
}