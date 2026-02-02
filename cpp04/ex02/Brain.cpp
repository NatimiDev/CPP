#include "Brain.hpp"

Brain::Brain()
{}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &to_copy)
{
	if(this != &to_copy)
	{
		for(int i = 0; i < 100; i++)
			ideas[i] = to_copy.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{}