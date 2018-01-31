
/*
	ROI Class Declarations
*/

#ifndef ROI_CPP
#define ROI_CPP

#include "roi.hpp"
#include <numeric>
#include <algorithm>

ROI::ROI(){

}

double ROI::currentYearROI(){

	// define vector of x trials
	std::vector<double> v(numberOfTrials);

	// fill with random values between -15% and 20%
	std::generate(v.begin(), v.end(), [](){
		return ((rand() % 20) - 15) / 100;
	});

	// calc mean


	// calc sigma

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
}

void ROI::display(){


}


#endif
