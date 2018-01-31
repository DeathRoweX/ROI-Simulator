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
	// fill with random values between -15% and 20%

	// calc mean	
	// calc sigma
}


double ROI::calcBalance(){

}

void setYears(unsigned int y){
	years = y;
}

void setAmount(double a){
	initialAmount = a;
}


int ROI::simulate(){
	// reset data
	if(!(annualROI.empty() || mean.empty() || 
			sigma.empty() || annualBalance.empty())){
		annualROI.clear();
		annualBalance.clear();
		mean.clear();
		sigma.clear();
	}

	for(int i = 0; i < years; i++){

		annualROI.push_back(currentYearROI());
		annualBalanc(calcBalance();

	}
}


void ROI::display(){


}





#endif
