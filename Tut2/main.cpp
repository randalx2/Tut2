//PRANEEL MISTHRY
//202515355
//COMPUTER METHODS 3 -- TUT2
//24 FEBRUARY 2016
/**********************************************************************************************************************/

//Program gives proper results however it does seem to trigger a Debug Assertion Error at run time

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

class Fraction {
private: int *num1, *denom1, *num2, *denom2, *result1, *result2, *result3; // private pointer attributes for protection
		 int *ResNum, *ResDen;

public: Fraction(){              //Default Constructor
			num1 = new int;       //Allocating dynamic memory for attributes
			denom1 = new int;

			num2 = new int;
			denom2 = new int;

			result1 = new int;
			result2 = new int;
			result3 = new int;
			ResNum = new int;
			ResDen = new int;
}

		~Fraction(){           //Default Destructor
			delete num1;        //deleting dynamic memory for attributes
			delete denom1;
			delete num2;
			delete denom2;     //Releasing Resources
			delete result1;
			delete result1;
			delete result2;
			delete result3;
			delete ResNum;
			delete ResDen;
		}
		// Defining method prototypes
		void add()
		{
			*result1 = *(num1)**(denom2);
			*result2 = *(denom1)**(num2);
			*result3 = *(denom1)**(denom2);
			*ResNum = *(result1)+*(result2);
			*ResDen = *(result3);
			//First attempt to display the result before simplifying the fractions
			cout << *ResNum << " / " << *ResDen;
		};

		void subtract()
		{
			*result1 = *(num1)**(denom2);
			*result2 = *(denom1)**(num2);
			*result3 = *(denom1)**(denom2);
			*ResNum = *(result1)-*(result2);
			*ResDen = *(result3);
			//First attempt to display the result before simplifying the fractions
			cout << *ResNum << " / " << *ResDen;
		};

		void multiply()
		{
			*ResNum = *(num1)**(num2);
			*ResDen = *(denom1)**(denom2);
			//First attempt to display the result before simplifying the fractions
			cout << *ResNum << " / " << *ResDen;
		};

		void divide()
		{
			*ResNum = *(num1)**(denom2);
			*ResDen = *(denom1)**(num2);
			//First attempt to display the result before simplifying the fractions
			cout << *ResNum << " / " << *ResDen;
		};

		void print()
		{
			//Method is used to finally print out the fraction in lowest terms
		};

		void GetNumDenom()   //Method to prompt user for input
		{
			int iNum = 0;
			int iDenom = 1;
			cout << "Please Enter the Numerator and Denominator for the First Fraction separated by spaces" << endl;
			cin >> iNum >> iDenom;
			*num1 = iNum;            //Initialize Object private attributes with user input
			*denom1 = iDenom;
			cout << "Please Enter the Numerator and Denominator for the Second Fraction separated by spaces" << endl;
			cin >> iNum >> iDenom;
			*num2 = iNum;
			*denom2 = iDenom;

		}; 

};

int main()
{
	char input = 'x'; //User input character initialized

	Fraction *Mathboy = new Fraction(); //OBJECT CREATED and memory allocated and constructor called
	cout << " Welcome to Fraction Mathboy game" << endl;
	cout << "This will diplay the result of the addition, subtraction, multiplication or division of two fractions" << endl;

	Mathboy->GetNumDenom();

	cout << "Please choose the corresponding math operation you would like to perform accordingly" << endl;
	cout << "Press 1 for ADDITION" << endl;
	cout << "Press 2 for SUBTRACTION" << endl;
	cout << "Press 3 for MULTIPLICATION" << endl;
	cout << "Press 4 for DIVISION" << endl;

	cin >> input;

	switch (input){
	case '1': Mathboy->add();
		break;
	case '2': Mathboy->subtract();
		break;
	case '3': Mathboy->multiply();
		break;
	case '4': Mathboy->divide();
		break;
	default: cout << "Please Enter a valid input" << endl;
	}

	//Enter the print function for simplifying the numbers here
	//We done using the object so we can release it from memory

	delete Mathboy;

	system("PAUSE");
	return 0;
}