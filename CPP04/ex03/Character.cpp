/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:39:42 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/02 16:06:36 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>


Character::Character(void) {
	std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}


Character::Character(std::string const &name) : _name(name) {
	std::cout << "Character parametric constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}

Character::Character(Character const &src) {
	std::cout << "Character copy constructor called." << std::endl;
	*this = src;
	return ;
}

Character::~Character(void) {
	std::cout << "Default destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	return ;
}

Character & Character::operator=(Character const &rhs) {
	std::cout << "Character assignation operator called" << std::endl;
	if (this != &rhs)
	{
		*this->_inventory = *rhs._inventory;
		this->_name = rhs.getName();
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break ;
		}
	return ;
}

void Character::unequip(int idx) {
	if (idx > 3 || idx < 0)
	{
		std::cout << this->getName() << " can't unequip inventory slot n°" << idx << std::endl;
		return ;
	}
	_inventory[idx] = NULL;
	return ;
}

void Character::use(int idx, ICharacter &target) {
	if (idx > 3 || idx < 0)
	{
		std::cout << this->getName() << "can't attack, inventory slot n°" << idx << " does not exist" << std::endl;
		return ;
	}
	else if (_inventory[idx] == NULL)
	{
		std::cout << this->getName() << " can't attack, inventory slot n°" << idx << " is empty." << std::endl;
		return ;
	}
	std::cout << this->getName() << " ";
	_inventory[idx]->use(target);
	return ;
}
