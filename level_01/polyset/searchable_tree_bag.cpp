
#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &copy){
	tree->l = copy.tree->l;
	tree->r = copy.tree->r;
	tree->value = copy.tree->value;
}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &copy){
	tree->l = copy.tree->l;
	tree->r = copy.tree->r;
	tree->value = copy.tree->value;
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag(){};

//SEARCH
bool	searchable_tree_bag::has(int n){
	node	*i = tree;
	
	if (i == nullptr)
		return (false);
	while (i->value != n && i != nullptr){
		if (i->value > n)
			i = i->l;
		else
			i = i->r;
	}
	if (i->value = n)
		return (true);
	return (false);
}
