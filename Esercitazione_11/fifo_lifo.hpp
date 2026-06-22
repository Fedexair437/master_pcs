#pragma once
#include <queue>
#include <stack>
using namespace std;

template<typename I>
class fifo
{
    queue<I> q;

public:
    /* Costruttore di default */
    fifo() : q(queue<I>{})
    {}

    /* Altri metodi richiesti */
    void put(I new_element) { q.push(new_element); }

    I get() {
        I first_in=q.front();
        q.pop();
        return first_in;
    }

    bool empty() { return q.empty(); }

};


template<typename I>
class lifo
{
    stack<I> s;

public:
    /* Costruttore di default */
    lifo() : s(stack<I>{})
    {}

    /* Altri metodi richiesti */
    void put(I new_element) { s.push(new_element); }

    I get() {
        I last_in=s.top();
        s.pop();
        return last_in;
    }

    bool empty() { return s.empty(); }

};