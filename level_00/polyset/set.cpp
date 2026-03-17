
#include "set.hpp"

set::set(searchable_bag &newBag) : bag(newBag) {}

// FUNCTIONS
bool	set::has(int n){
	return (bag.has(n));
}

searchable_bag	&set::get_bag(void)const{
	return (bag);
}

void	set::print(void){
	bag.print();
}

void	set::clear(void){
	bag.clear();
}

void	set::insert(int n){
	if (!this->has(n))
		bag.insert(n);
}

void	set::insert(int *n, int size){
	for (int i = 0; i < size; i++){
		if (!this->has(n[i]))
			bag.insert(n[i]);
	}
}
