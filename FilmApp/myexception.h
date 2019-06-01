#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>

class MyException : public std::exception {
public:
    MyException();

    virtual std::string render() = 0; // Error message
};

#endif // MYEXCEPTION_H
