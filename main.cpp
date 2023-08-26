// ML-Algos-from-Scratch-in-Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "LinearRegression.h"

using namespace std;

int main(void) {

    LinearRegression model = LinearRegression();

    cout << "Slope: " << model.get_slope() << endl;
    cout << "Intercept: " << model.get_intercept() << endl;

    return(0);
}
