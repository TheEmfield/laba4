#include <iostream>
#include <exception>
double sequenceTaylor(double accuracy, int numberMax, double value) {
	double resultCorrect = 0;
	double absError = 0;
	double result = 1;
	double temp = 1;
	if (value <= -1 || value >= 1) {
		throw std::out_of_range("Inputed value out of range");
	}
	for (int j = 1; j <= numberMax;j++) {
		temp *= -1 * value;
		result += (temp * (j + 1) * (j + 2)) / 2;
		absError = temp * (j + 1) * (j + 2) / 2;
		}
		if (std::abs(absError) <= accuracy) {
			return result;
	}
	throw std::invalid_argument("Inaccurate calculations");
}

int main() {
	double accuracy = 0.00001;
	int numberMax = 100000000;
	double start = -0.99;
	double end = 0.99;
	double step = 0.01;
	for (double i = start; i < end; i += step) {
		try {
			double result = 0;
			double divider = (1 + i) * (1 + i) * (1 + i);
			double resultCorrect = 1 / divider;
			result = sequenceTaylor(accuracy, numberMax, i);
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
	std::cout << "End of programme";
	return 0;
}
