//PRANEEL MISTHRY
//202515355
//COMPUTER METHODS 3 -- TUT2
//24 FEBRUARY 2016
/**********************************************************************************************************************/

//Program gives proper results however it does seem to trigger a Debug Assertion Error at run time
//Could be an issue with the compiler or some bugs in Visual Studio 2013 on my personal laptop

//MERGED FROM FRACTION SIMPLIFIER BRANCH WITH NO CONFLICTS DETECTED
//Program prompts user to input two fractions to perform math operations

// 1 MARCH 2016
/*Code Modified in Recurring_Values Branch to allow for successive calculations of new fractions*/
/*Changed Mathboy object name to Fract1 -- Added in any Fraction Object as FractNew*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

class Fraction {
private: int *num, *denom, /* *num2, *denom2, */ *result1, *result2, *result3; // private pointer attributes for protection

	     int *ResNum, *ResDen;  

public: Fraction(){              //Default Constructor
			num = new int;       //Allocating dynamic memory for attributes
			denom = new int; 
			*denom = 1; //Initialize denominator to 1 as default value

			//num2 = new int;
			//denom2 = new int;

			result1 = new int;
			result2 = new int;
			result3 = new int;
			ResNum = new int;
			ResDen = new int;
}

		~Fraction(){           //Default Destructor
			delete num;        //deleting dynamic memory for attributes
			delete denom;
			//delete num2;
			//delete denom2;     //Releasing Resources
			delete result1;
			delete result1;
			delete result2;
			delete result3;
			delete ResNum;
			delete ResDen;
		}
		// Defining methods and prototypes
		void add()
		{
			*result1 = *(num1)**(denom2);
			*result2 = *(denom1)**(num2);
			*result3 = *(denom1)**(denom2);
			*ResNum = *(result1)+*(result2);
			*ResDen = *(result3);
			//First attempt to display the result before simplifying the fractions
			cout << *ResNum << " / " << *ResDen << endl;
		};

		void subtract()
		{
			*result1 = *(num1)**(denom2);
			*result2 = *(denom1)**(num2);
			*result3 = *(denom1)**(denom2);
			*ResNum = *(result1)-*(result2);
			*ResDen = *(result3);
			//First attempt to display the result before simplifying the fractions
			cout << *ResNum << " / " << *ResDen << endl;
		};

		void multiply()
		{
			*ResNum = *(num1)**(num2);
			*ResDen = *(denom1)**(denom2);
			//First attempt to display the result before simplifying the fractions
			cout << *ResNum << " / " << *ResDen << endl;

		};

		void divide()
		{
			*ResNum = *(num1)**(denom2);
			*ResDen = *(denom1)**(num2);
			//First attempt to display the result before simplifying the fractions
			cout << *ResNum << " / " << *ResDen << endl;
		};

		void print_lowest_terms()
		{
			//Method is used to finally print out the fraction in lowest terms
			
			int Hval = 0, Lval = 0;   //Initialize temp variables
			if (*ResNum > *ResDen)
			{
				Lval = *ResDen;
				Hval = *ResNum;
			}
			else
			{
				Hval = *ResDen;
				Lval = *ResNum;
			}

			for (int i = Lval; i > 0; i--)     //Start iteration loop to reach lowest terms
			{
				if ((Lval % i == 0) && (Hval % i == 0))  //Check if the number is directly divisible
				{
					*ResNum = *ResNum / i;
					*ResDen = *ResDen / i;
					break;    //Conditional break statement to exit loop after iterating to this point
				}
			}

			cout << *ResNum << " / " << *ResDen << endl;

		};

		void getNumDenom()   //Method to prompt user for input
		{
			//int iNum = 0;
			//int iDenom = 1;   //Safety measure to prevent undefined fractions

			cout << "Please Enter the Numerator and Denominator for the Your First Fraction" << endl;
			cin >> iNum >> iDenom;
			*num1 = iNum;            //Initialize Object private attributes with user input
			*denom1 = iDenom;

			//Attempting to perform additions to the Fraction ended and result obtained previously

			cout << "Please Enter the Numerator and Denominator for the New Fraction" << endl;
			cin >> iNum >> iDenom;
			*num2 = iNum;
			*denom2 = iDenom;

		}; 

};

int main()
{
	char input = 'x'; //User input character initialized

	Fraction *Fract1 = new Fraction(); //OBJECT CREATED and memory allocated and constructor called
	Fraction *FractNew = new Fraction();

	cout << " Welcome to Fraction Mathboy game" << endl;
	cout << "This will diplay the result of math operations on fractions" << endl;

	Fract1->getNumDenom();

	cout << "Please choose the math operation you would like to perform" << endl;
	cout << "Press 1 for ADDITION" << endl;
	cout << "Press 2 for SUBTRACTION" << endl;
	cout << "Press 3 for MULTIPLICATION" << endl;
	cout << "Press 4 for DIVISION" << endl;

	cin >> input;

	switch (input)
	{
	case '1': Fract1->add();
		break;
	case '2': Fract1->subtract();
		break;
	case '3': Fract1->multiply();
		break;
	case '4': Fract1->divide();
		break;
	default: cout << "Please Enter a valid input" << endl;
	}

	cout << "The Fraction in Simplest terms is :" << endl;

	Fract1->print_lowest_terms();
	

	//Enter the print function for simplifying the numbers here
	//We done using the object so we can release it from memory

	delete Fract1;

	system("PAUSE");
	return 0;
}