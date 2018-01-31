
/*
	ROI Class Declarations
*/

#ifndef ROI_CPP
#define ROI_CPP

#include "roi.hpp"


ROI::ROI(){

}

double ROI::currentYearROI(){

	// define vector of x trials
	std::vector<double> v(numberOfTrials);

	// fill with random values between -15% and 20%
	std::generate(v.begin(), v.end(), [](){
		return ((std::rand() % 20) - 15) / 100;
	});

	// calc mean
	double sum = std::accumulate(v.begin(), v.end(), 0.0);
	double mean = sum / v.size();
	annualMean.push_back(mean);
	

	// create difference vector
	std::vector<double> diff(v.size());
	std::transform(v.begin(), v.end(), diff.begin(), 
		std::bind2nd(std::minus<double>(), mean));

	// get squared sum
	double sq_sum = std::inner_product(diff.begin(), 
		diff.end(), diff.begin(), 0.0);

	// calc sigma
	double sigma = std::sqrt(sq_sum / v.size());
	annualSigma.push_back(sigma);

	// calc ROI
	// inverse cummulative normal distribution
	// double roi = norm.inv(rand(), mean, sigma);
	// double r = ((double)std::rand() / (RAND_MAX)) + 1;
	// return roi;
}

double ROI::calcBalance(){

}

void ROI::setYears(unsigned int y){
	years = y;
}

void ROI::setAmount(double a){
	initialAmount = a;
}

void ROI::simulate(){
	// reset data
	if(!(annualROI.empty() || annualMean.empty() || 
			annualSigma.empty() || annualBalance.empty())){
		annualROI.clear();
		annualBalance.clear();
		annualMean.clear();
		annualSigma.clear();
	}

	for(unsigned int i = 0; i < years; i++){

		annualROI.push_back(currentYearROI());
		annualBalance.push_back(calcBalance());

	}
}

void ROI::display(){


}


#endif
