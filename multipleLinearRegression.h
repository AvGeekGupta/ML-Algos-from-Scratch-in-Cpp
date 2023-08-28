#pragma once

#include <random>

/// <summary>
/// A class containing multiple linear regression functions.
/// </summary>
class MultipleLinearRegression {

private:

	// Variables
	std::vector<double> slopes; // The slope of the linear regression model
	double intercept; // The intercept of the linear regression model

	/// <summary>
	/// Calculates the value of y using the equation y = m1X1 +m2X2 + m3X3 + ... + c.
	/// </summary>
	/// <param name="X">The input values for which y needs to be calculated.</param>
	/// <returns>The calculated y value.</returns>
	double fun(std::vector<double> X) {

		// Variables
		double sum_mX = 0.0;

		// Calculating 
		for (int i = 0; i < X.size(); i++) {
			sum_mX += this->get_slope(i) * X[i];
		}

		return (sum_mX + this->get_intercept());
	}

	/// <summary>
	/// Generates a pseudo-random number within the specified range using the Mersenne Twister engine.
	/// </summary>
	/// <param name="lowerLimit">The lower limit of the number generation range.</param>
	/// <param name="higherLimit">The higher limit of the number generation range.</param>
	/// <returns>A double-precision floating-point number.</returns>
	double generate_random_number(double lower_limit, double higher_limit) {
		// Create a Mersenne Twister engine
		std::random_device rd;
		std::mt19937 mt(rd());

		// Define a range for random floating-point numbers
		std::uniform_real_distribution<double> dist(lower_limit, higher_limit);

		return(dist(mt));
	}

	/// <summary>
	/// Sets the values of slopes.
	/// </summary>
	/// <param name="slopes">Vector of slope values.</param>
	void set_slopes(std::vector<double> slopes) {
		this->slopes = slopes;
	}

	/// <summary>
	/// Sets the value of intercept.
	/// </summary>
	/// <param name="intercept">Value of the intercept.</param>
	void set_intercept(double intercept) {
		this->intercept = intercept;
	}

	/// <summary>
	/// Gets the slope value for a specific variable by index.
	/// </summary>
	/// <param name="index">The index of the variable.</param>
	/// <returns>The slope value for the specified variable.</returns>
	double get_slope(int index) {
		return (this->get_slopes()[index]);
	}

public:

	/// <summary>
	/// Initializes a new instance of the MultipleLinearRegression class.
	/// </summary>
	MultipleLinearRegression(void) {

		// Initialising the slope and intercept with random numbers.
		this->set_intercept(this->generate_random_number(-1.0, 1.0));
	}

	/// <summary>
	/// Returns the slopes of the linear regression model for each variable.
	/// </summary>
	/// <returns>A vector containing slope values.</returns>
	std::vector<double> get_slopes(void) {
		return (this->slopes);
	}

	/// <summary>
	/// Returns the intercept of the linear regression model.
	/// </summary>
	/// <returns>The intercept value.</returns>
	double get_intercept(void) {
		return (this->intercept);
	}

	/// <summary>
	/// Predicts the value of y based on the input values X using the multiple linear regression model.
	/// </summary>
	/// <param name="X">The input values for which the prediction is made.</param>
	/// <returns>The predicted y value.</returns>
	double predict(std::vector<double> X) {
		return (this->fun(X));
	}

	/// <summary>
	/// Sets the slope and intercept values of the linear regression model.
	/// </summary>
	/// <param name="slopes">Vector of slope values for each variable.</param>
	/// <param name="intercept">The intercept value.</param>
	void set_params(std::vector<double> m, double c) {
		this->set_slopes(m);
		this->set_intercept(c);
	}

	/// <summary>
	/// Fits the data to the Multiple Linear Regression model.
	/// </summary>
	/// <param name="X">Input data points.</param>
	/// <param name="y">Expected output values.</param>
	void fit(std::vector<double> X, std::vector<double> y) {

		// Invalid input check
		if (X.size() != y.size() || X.empty()) {
			throw "Invalid input data.";
		}
		
		// TODO: Implement fitting algorithm

	}
};

