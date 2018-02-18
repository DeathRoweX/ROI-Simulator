
/*
	ROI Class Definition
*/

#ifndef ROI_CPP
#define ROI_CPP

#include "roi.hpp"


ROI::ROI(){
	years = 0;
	initialAmount = 0;
	numberOfTrials = 1000;
}

ROI::ROI(unsigned int y, double x){
	years = y;
	initialAmount = x;
	numberOfTrials = 1000;
}

double ROI::currentYearROI(){

	// define vector of x trials
	std::vector<double> v(numberOfTrials);

	// fill with random values between -15% and 20%
	std::generate(v.begin(), v.end(), [](){
		return (double)((std::rand() % 35) - 15) / 100;
	});

	// calc mean
	double sum = std::accumulate(v.begin(), v.end(), 0.0);
	double currentMean = sum / v.size();
	mean.push_back(currentMean);

	// create difference vector
	std::vector<double> diff(v.size());
	std::transform(v.begin(), v.end(), diff.begin(), 
		std::bind2nd(std::minus<double>(), currentMean));

	// get squared sum
	double sq_sum = std::inner_product(diff.begin(), 
		diff.end(), diff.begin(), 0.0);

	// calc sigma
	double currentSigma = std::sqrt(sq_sum / v.size());
	sigma.push_back(currentSigma);

	// calc ROI
	// inverse cumulative normal distribution
	// double roi = 0.5 * (1 + erfc(((double)std::rand() - currentMean) / (currentSigma * sqrt(2.))));
	// std::cout << "ROI: " << roi << std::endl; // Test

	return currentMean; // ^^^ TODO::Fix inverse gaussian ^^^
}

double ROI::calcBalance(){
	if(annualBalance.empty()){
		return initialAmount + (initialAmount * annualROI.back());
	} else {
		return annualBalance.back() + (annualBalance.back() * annualROI.back());
	}
}

void ROI::setYears(unsigned int y){
	years = y;
}

void ROI::setAmount(double a){
	initialAmount = a;
}

void ROI::simulate(){

	if(!(annualROI.empty() || mean.empty() || 
			sigma.empty() || annualBalance.empty())){
		annualROI.clear();
		annualBalance.clear();
		mean.clear();
		sigma.clear();
	}

	for(unsigned int i = 0; i < years; i++){
		annualROI.push_back(currentYearROI());
		annualBalance.push_back(calcBalance());
	}
	finalROI = (annualBalance.back() - initialAmount) / initialAmount;
}

void ROI::display(){
	std::cout << "\n======= Simulation Details =======";
	for(unsigned int i = 1; i <= years; i++){
		std::cout << "\n\nYear " << i << " of " << years;
		std::cout << "\nMean: " << mean[i-1]; 
		std::cout << "\nSigma: " << sigma[i-1];
		std::cout << "\nROI: " << annualROI[i-1];
		std::cout << "\nAnnual Balance: " << annualBalance[i-1];
	}
	std::cout << "\n\n======= Simulation Summary =======";
	std::cout << "\nStarting Balance: " << initialAmount;
	std::cout << "\nEnding Balance: " << annualBalance.back();
	std::cout << "\nTotal ROI: " << finalROI;
	std::cout << std::endl;
}

#endif
