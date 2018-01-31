/*
	ROI Class Declarations
*/

#ifndef ROI_HPP
#define ROI_HPP

#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cmath>

class ROI{
private:
	unsigned int years;
	double initialAmount;

	std::vector<double> annualROI;
	std::vector<double> annualBalance;
	std::vector<double> mean;
	std::vector<double> sigma;
	
	unsigned int numberOfTrials; // for randomization

	double currentYearROI();
	double calcBalance();

public:
	ROI();
	
	void setYears(unsigned int y);
	void setAmount(double a);

	void simulate();
	void display();
};

#endif
