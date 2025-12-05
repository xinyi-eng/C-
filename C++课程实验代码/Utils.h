#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>  
#include <string>
#include <cstdlib>  
#include "User.h"   
#include "WordRecord.h"

using namespace std;
inline void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif
}

#endif