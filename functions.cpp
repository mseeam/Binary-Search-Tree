/********************************************************************************
 * File  :   functions.cpp                                                      *
 * Author: Mohammad Seeam                                                       *
 * Assignment 8: Binary Search Tree                                             *
 * Fully functional Binary Search Tree                                          *
 * This header structure for all cpp and h files.                               *
 * This file, functions.cpp, includes functions.h                               *
 * Just included <string> and <iostream> to prevent compile error               *
 *******************************************************************************/

#include "functions.h"
#include <string>
#include <iostream>

// do not modify this function
int random_range(int min, int max) {
    //returns a random number between min and max inclusive
    return (std::rand() % (max - min + 1)) +min;
}

// you may add more functions here if you need them
