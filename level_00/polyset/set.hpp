
#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set
{
	private:
		set();
		set(const searchable_bag &bag);
		set	&operator=(const searchable_bag &bag);

		//VARIABLES
		searchable_bag	&bag;
		
	public:
		set(searchable_bag &newBag);
		~set(){};

		//FUNCTIONS
		bool			has(int n);
		searchable_bag	&get_bag(void)const;
		void			print(void);
		void			clear(void);
		void			insert(int n);
		void			insert(int *n, int size);
};

#endif