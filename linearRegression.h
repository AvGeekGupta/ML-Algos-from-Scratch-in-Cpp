#pragma once

#include <random>

/// <summary>
/// Represents a class containing linear regression functions.
/// </summary>
class LinearRegression {

private:

	double slope; // The slope of the linear regression model
	double intercept; // The intercept of the linear regression model

	/// <summary>
	/// Calculates the value of y using the equation y = mX + c.
	/// </summary>
	/// <param name="X">The input value for which y needs to be calculated.</param>
	/// <returns>The calculated y value.</returns>
	double fun(double X) {
		return ((this->get_slope() * X) + this->get_intercept());
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
	/// Sets the slope value of the linear regression model.
	/// </summary>
	/// <param name="slope">The value of the slope.</param>
	void set_slope(double slope) {
		this->slope = slope;
	}

	/// <summary>
	/// Sets the intercept value of the linear regression model.
	/// </summary>
	/// <param name="intercept">The value of the intercept.</param>
	void set_intercept(double intercept) {
		this->intercept = intercept;
	}

public:

	/// <summary>
	/// Initializes a new instance of the LinearRegression class.
	/// </summary>
	LinearRegression(void) {

		// Initialising the slope and intercept with random numbers.
		this->set_slope(this->generate_random_number(-1.0, 1.0));
		this->set_intercept(this->generate_random_number(-1.0, 1.0));
	}

	/// <summary>
	/// Returns the slope of the linear regression model.
	/// </summary>
	/// <returns>The slope value.</returns>
	double get_slope(void) {
		return (slope);
	}

	/// <summary>
	/// Returns the intercept of the linear regression model.
	/// </summary>
	/// <returns>The intercept value.</returns>
	double get_intercept(void) {
		return (intercept);
	}

	/// <summary>
	/// Predicts the value of y based on the input X using the linear regression model.
	/// </summary>
	/// <param name="X">The input value for which the prediction is made.</param>
	/// <returns>The predicted y value.</returns>
	double predict(double X) {
		return (this->fun(X));
	}

	/// <summary>
	/// Sets the slope and intercept values of the linear regression model.
	/// </summary>
	/// <param name="slope">The slope value.</param>
	/// <param name="intercept">The intercept value.</param>
	void set_params(double m, double c) {
		this->set_slope(m);
		this->set_intercept(c);
	}

	/// <summary>
	/// Fits the linear regression model to the provided data.
	/// </summary>
	/// <param name="X">The input data points.</param>
	/// <param name="y">The expected output values.</param>
	void fit(std::vector<double> X, std::vector<double> y) {

		// Invalid input check
		if (X.size() != y.size() || X.empty()) {
			throw "Invalid input data!";
		}

		// Variables
		double sum_X = 0.0, sum_y = 0.0;
		double sum_X_squared = 0.0, sum_Xy = 0.0;
		double mean_X = 0.0, mean_y = 0.0;
		int n;
		
		n = X.size();

		// Calculate sums and means
		for (int i = 0; i < n; ++i) {
			sum_X += X[i];
			sum_y += y[i];
			sum_X_squared += X[i] * X[i];
			sum_Xy += X[i] * y[i];
		}

		mean_X = sum_X / n;
		mean_y = sum_y / n;

		// Calculating slope and intercept
		this->set_slope((sum_Xy - n * mean_X * mean_y) / (sum_X_squared - n * mean_X * mean_X));
		this->set_intercept(mean_y - this->get_slope() * mean_X);
	}
};

