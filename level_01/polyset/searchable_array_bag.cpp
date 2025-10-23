
#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(){}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &copy){
	data = copy.data;
	size = copy.size;
}

searchable_array_bag	&searchable_array_bag::operator=(const searchable_array_bag &copy){
	data = copy.data;
	size = copy.size;
	return (*this);
}

searchable_array_bag::~searchable_array_bag(){}

// SEARCH
bool	searchable_array_bag::has(int n){
	if (size <= 0)
		return (false);
	for (int i = 0; i < size; i++){
		if (data[i] == n)
			return (true);
	}
	return (false);
}
