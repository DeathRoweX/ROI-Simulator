/*
	ROI Class Declarations
*/

#ifndef ROI_HPP
#define ROI_HPP

#include <cstdlib>
#include <ctime>
#include <vectror>

class ROI{
private:
	unsigned int years;
	double initialAmount;
	double endingROI;

	std::vector<double> annualROI;
	std::vector<double> mean;
	std::vector<double> sigma;
	std::vector<double> annualBalance;

	unsigned int numOfTrials; // for randomization

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
