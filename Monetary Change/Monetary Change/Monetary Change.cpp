#include <iostream>
#include <math.h> //Have to round floating-point input by user or else will get an inaccurate integer cast value
using namespace std;

struct change { //This struct will be used to hold the total value as its seperate coins
	int quarters;
	int dimes;
	int nickles;
	int pennies;
};

double GetInput(); //Declaration
change ComputeChange(int totCents);//Declaration
void PrintChange(change totChange); //Declaration

int main() {
	double totCents = 0; //To total amount of money entered by user
	change totChange; //The amount of change broken down by type
	char quit = 'y'; //Lets the user input a value to quit or rerun the program
	
	cout << "\n*************************************************\n"; //put extra space as program launches
	cout << "Welcome to Monetary Change!" << endl << endl;

	while (quit != 'n') {

		//In case the user inputs something other than an 'n' or 'y'
		while (quit != 'y' && quit != 'n') {
			cout << "I'm sorry, I didn't get that" << endl << endl;
			cout << "Would you like to enter another value? (y/n): ";
			cin >> quit;
		}

		//If the user entered an 'n' in the previous loop, this statement breaks the program loop and causes the program to end
		if (quit == 'n') {
			break;
		}

		totCents = GetInput();
		totChange = ComputeChange(totCents); //Computes the total change broken down by type
		PrintChange(totChange); //Print each coin type to screen for user

		cout << endl << "Would you like to enter another value? (y/n): ";
		cin >> quit;
		cout << endl;
	}
}

//Makes sure the user input is a double and not a char
double GetInput() {

	double totCents = 0;

	cout << "Please enter the amount of money you'd like converted to change ($.$$ format, no symbols): ";
	cin >> totCents; //get input from user

	//If the user enters something other than an int or double, this loop catches it and asks for a new input
	while (cin.fail()) {
		cin.clear(); //Clear the input to avoid an infinite loop
		cin.ignore(); //Ignores characters in the input stream
		cout << endl << "I'm sorry, but that is not a valid input" << endl;
		cout << endl << "Please enter the amount of money you'd like converted to change ($.$$ format, no symbols): ";
		cin >> totCents; //get input from user
	}

	totCents = totCents * 100; //Convert value to cents
	totCents = (int)ceil(totCents); //Must round floating point value to nearest whole number or else will get innacurate cast

	return totCents;
}

//Breaks the total amount of money down into seperate coin types
change ComputeChange(int totCents) {
	change totChange;
	int remChange = totCents; //Amount of change remaining after each coin type is deducted

	totChange.quarters = remChange / 25;
	remChange = remChange % 25;
	totChange.dimes = remChange / 10;
	remChange = remChange % 10;
	totChange.nickles = remChange / 5;
	remChange = remChange % 5;
	totChange.pennies = remChange / 1;

	return totChange;
}

//Print each coin type to screen for user
void PrintChange(change totChange) {
	cout << endl << "Quarters: " << totChange.quarters;
	cout << endl << "Dimes: " << totChange.dimes;
	cout << endl << "Nickles: " << totChange.nickles;
	cout << endl << "Pennies: " << totChange.pennies;
	cout << endl;
}