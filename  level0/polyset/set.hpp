#pragma once

#include "searchable_bag.hpp"

class set
{
    private:
    searchable_bag& _bag;

    public:
        set() = delete;
        set(const set& copy) = delete;
        set &operator = (const set& src) = delete;
        ~set();

        set(searchable_bag& bag);
        const searchable_bag &get_bag();

        bool has(int) const;
        void insert (int);
	    void insert (int *, int);
	    void print();
	    void clear();
};