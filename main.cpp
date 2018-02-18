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
	int totalYears = 0;
	double initialAmount = 0.00;

	std::cout << "\nEnter Initial Amount: ";
	std::cin >> initialAmount;

	std::cout << "\nEnter Number of years: ";
	std::cin >> totalYears;
	
	roi.setYears(totalYears);
	roi.setAmount(initialAmount);
}
