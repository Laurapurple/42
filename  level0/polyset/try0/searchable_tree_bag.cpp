#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &copy): tree_bag(copy) {}
searchable_tree_bag  &searchable_tree_bag::operator=(const searchable_tree_bag &src)
{
    if (this != &src)
        tree_bag::operator=(src);
    return (*this);
}
searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::search(node *node, const int i) const
{
    if (node == nullptr)
        return false;
    if (node->value == i)
        return true;
    else if (i < node->value)
        return(search(node->l, i));
    else
        return(search(node->r,i));
}

bool searchable_tree_bag::has(int value) const
{
    return(search(this->tree, value));
}
