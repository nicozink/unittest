/*
Copyright © Nico Zink
All rights reserved.
*/

#pragma once

#ifndef UNITTESTEXCEPTION_H
#define UNITTESTEXCEPTION_H

// Local Includes

// Project Includes

// External Includes
#include <exception>

// Stores an exception which is thrown when a unit test
// fails, and the rest of the test is skipped. In this
// case, not much else is supposed to happen.
class UnitTestException : public std::exception
{
  public:
    
    /*
     * Constructors
     */
    
    // Creates a new instance of the UnitTestException class.
    UnitTestException();

    /*
     * Public Virtual Methods
     */
    
    // Returns the exception error message. We're not really
    // interested in it, so a default message is fine.
    virtual const char* what() const throw();
};

#endif

