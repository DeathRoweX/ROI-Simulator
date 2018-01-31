#include <iostream>
#include "roi.hpp"

// function declarations
void getUserInput(ROI &roi);

// Test client
int main(void){
	std::srand(std::time(nullptr));
	ROI r = ROI();
	getUserInput(r);
	r.simulate();
	r.display();
}

// function definitons
void getUserInput(ROI &roi){
	unsigned int totalYears = 0;
	double initialAmount = 0.00;
	unsigned int numOfTrials = 100;

	try{
	// cin totalYears set
	// cin

	} catch {

	}


}
