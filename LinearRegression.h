#pragma once

#include <random>

/// <summary>
/// A class containing linear regression functions.
/// </summary>
class LinearRegression {

private:

	// Variables
	double m, c;

	/// <summary>
	/// This function calculates the value of y with the equation of y=mx+c.
	/// </summary>
	/// <param name="x"> The value for which, y needs to be calculated </param>
	/// <returns> The calculated y. </returns>
	double fun(double x) {
		return ((this->m * x) + this->c);
	}

	/// <summary>
	/// This function generates a pseudo random number betwwen the provided range, 
	/// using Mersenne Twister engine.
	/// </summary>
	/// <param name="lower_limit"> The lower limit of the number generation range </param>
	/// <param name="higher_limit"> The higher limit of the number generation range </param>
	/// <returns> Double floating point number </returns>
	double generate_random_number(double lower_limit, double higher_limit) {
		// Create a Mersenne Twister engine
		std::random_device rd;
		std::mt19937 mt(rd());

		// Define a range for random floating-point numbers
		std::uniform_real_distribution<double> dist(lower_limit, higher_limit);

		return(dist(mt));
	}

	/// <summary>
	/// Sets the value of slope.
	/// </summary>
	/// <param name="m"> Value of the slope </param>
	void set_slope(double m) {
		this->m = m;
	}

	/// <summary>
	/// Sets the value fo intercept.
	/// </summary>
	/// <param name="c"> Value of the intercept </param>
	void set_intercept(double c) {
		this->c = c;
	}

public:

	/// <summary>
	/// Default Constructor
	/// </summary>
	LinearRegression(void) {

		// Initialising the slope and intercept with random numbers.
		this->m = this->generate_random_number(-1.0, 1.0);
		this->c = this->generate_random_number(-1.0, 1.0);
	}

	/// <summary>
	/// This function returns the slope of the curve.
	/// </summary>
	/// <returns> double point number </returns>
	double get_slope(void) {
		return (m);
	}

	/// <summary>
	/// This function returns the intercept of the curve.
	/// </summary>
	/// <returns> double point number </returns>
	double get_intercept(void) {
		return (c);
	}

	/// <summary>
	/// Predicts the value of y with respect to the x.
	/// </summary>
	/// <param name="x"> The value for which the prediction needs to be made </param>
	/// <returns> The predicted value </returns>
	double predict(double X) {
		return (this->fun(X));
	}

	/// <summary>
	/// Sets the value of the parameters in the model, i.e. intercept and slope.
	/// </summary>
	/// <param name="m"> Value of slope </param>
	/// <param name="c"> Value of intercept </param>
	void set_params(double m, double c) {
		this->set_slope(m);
		this->set_intercept(c);
	}

	/// <summary>
	/// Fit the data to the Linear Regression model.
	/// </summary>
	/// <param name="X"> Input </param>
	/// <param name="y"> Expected output </param>
	void fit(std::vector<double> X, std::vector<double> y) {

		// Invalid input check
		if (X.size() != y.size() || X.empty()) {
			std::cerr << "Invalid input data." << std::endl;
			return;
		}

		// Variables
		double sum_X = 0.0, sum_y = 0.0;
		double sum_X_squared = 0.0, sum_Xy = 0.0;
		double mean_X = 0.0, mean_y = 0.0;
		int n = X.size();

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

