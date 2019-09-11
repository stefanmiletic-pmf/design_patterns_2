#pragma once

class cake;

class interface_cake_iterator {
public:
    virtual bool hasNext() = 0;
    virtual cake* next() = 0;
};