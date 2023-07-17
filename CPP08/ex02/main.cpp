/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:16:33 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/17 15:39:59 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <vector>

int main()
{
	{
		std::cout << "_____ TESTS WITH MUTANT STACK _____" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack top is : ";
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack size is : ";
		std::cout << mstack.size() << std::endl << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
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
	}
	{
		std::cout << "_____ TESTS WITH LIST _____" << std::endl;
		std::list<int> mslist;
		mslist.push_front(5);
		mslist.push_front(17);
		std::cout << "mstack list is : ";
		std::cout << mslist.front() << std::endl;
		mslist.pop_front();
		std::cout << "mstack size is : ";
		std::cout << mslist.size() << std::endl << std::endl;
		mslist.push_back(3);
		mslist.push_back(5);
		mslist.push_back(737);
		//[...]
		mslist.push_back(0);
		std::list<int>::iterator it = mslist.begin();
		std::list<int>::iterator ite = mslist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(std::list<int>);
	}
	{
		std::cout << "_____ TESTS WITH SUBIELO _____" << std::endl;
		std::vector<std::pair<int, int> > msvector;
		msvector.insert(msvector.begin(), std::pair<int, int>(5, 5));
		msvector.insert(msvector.begin(), std::pair<int, int>(17, 17));
		std::cout << "msvector vector<pair> is : ";
		std::cout << msvector.begin()->first << std::endl;
		msvector.erase(msvector.begin());
		std::cout << "msvector vector<pair> size is : ";
		std::cout << msvector.size() << std::endl << std::endl;
		msvector.push_back(std::pair<int, int>(3, 3));
		msvector.push_back(std::pair<int, int>(5, 5));
		msvector.push_back(std::pair<int, int>(737, 737));
		//[...]
		msvector.push_back(std::pair<int, int>(0, 0));
		std::vector<std::pair<int, int> >::iterator it = msvector.begin();
		std::vector<std::pair<int, int> >::iterator ite = msvector.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << it->first << " | " << it->second <<  std::endl;
			++it;
		}
		std::stack<int> s(std::vector<std::pair<int, int> >);
	}
	{
		std::cout << "_____ TESTS WITH SUBIELO 2 _____" << std::endl;
		MutantStack<std::pair<int, MutantStack<int> > > mstack;
		MutantStack<int> tmp;
		tmp.push(5);
		mstack.push(std::pair<int, MutantStack<int> >(1, tmp));
		tmp.push(17);
		mstack.push(std::pair<int, MutantStack<int> >(2, tmp));
		std::cout << "mstack top is : ";
		std::cout << mstack.begin()->first << " | " << *mstack.begin()->second.begin() << std::endl;
		tmp.pop();
		mstack.pop();
		std::cout << "mstack size is : ";
		std::cout << mstack.size() << std::endl << std::endl;
		tmp.push(3);
		mstack.push(std::pair<int, MutantStack<int> >(3, tmp));
		tmp.push(5);
		mstack.push(std::pair<int, MutantStack<int> >(4, tmp));
		tmp.push(737);
		mstack.push(std::pair<int, MutantStack<int> >(5, tmp));
		//[...]
		mstack.push(std::pair<int, MutantStack<int> >(6, tmp));
		MutantStack<std::pair<int, MutantStack<int> > >::iterator it = mstack.begin();
		MutantStack<std::pair<int, MutantStack<int> > >::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			MutantStack<int>::iterator lol = it->second.begin();
			std::cout << it->first << " | ";
			while (lol != it->second.end())
			{	
				std::cout << *lol << " ";
				lol++;
			}
			std::cout << std::endl;
			++it;
		}
		std::stack<int> s(MutantStack<std::pair<int, MutantStack<int> > >);
	}
}