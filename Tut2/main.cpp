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
private: int *numerator, *denominator; //Using pointer method to allocate dynamic memory to attributes

	     
public: Fraction()
{              //Default Constructor
			numerator = new int;       //Allocating dynamic memory for attributes
			denominator = new int; 

			*numerator = 1;
			*denominator = 1;         //Initialize denominator to 1 as default value
			                   //Use checking in main programe for division by 0 protection

}
		Fraction(int n, int d)    //Creating an overloading constructor to return a fraction based on user values
		{
			numerator = new int;
			denominator = new int;

			*numerator = n;      //Assign the numerator
			
			//Doing safefty check for denominator values of 0
			if (d == 0)
			{
				cout << "A Zero value denominator is not allowed -- Exiting Program" << endl;
				exit(0);
			}
			else 
			{
				*denominator = d;
			}
		}

		~Fraction(){                  //Default Destructor
			delete numerator;        //deleting dynamic memory for attributes
			delete denominator;
			
		}
		// Defining methods and prototypes

		Fraction add(Fraction nextFraction)   //Creating a method of user defined type fraction with in built fraction object
		{
			int n, d;
			n = *numerator**(nextFraction.denominator) + *denominator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			get_lowest_terms(n, d);

			return Fraction(n, d);
			
		};

		Fraction subtract(Fraction nextFraction)  // NB IN BUILT OBJECTS WITHIN CLASS METHODS ARE ONLY VISIBLE TO METHODS
		{
			int n, d;
			n = *numerator**(nextFraction.denominator) - *denominator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			get_lowest_terms(n, d);

			return Fraction(n, d);
		};

		Fraction multiply(Fraction nextFraction)
		{
			int n, d;
			n = *numerator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			get_lowest_terms(n, d);

			return Fraction(n, d);

		};

		Fraction divide(Fraction nextFraction)
		{
			int n, d;
			n = *numerator**(nextFraction.denominator);
			d = *denominator**(nextFraction.numerator);
			get_lowest_terms(n, d);

			return Fraction(n, d);

		};

		void get_lowest_terms(int n, int d)
		{
			//Method is used to finally print out the fraction in lowest terms
			
			int Hval = 0, Lval = 0;   //Initialize temp variables
			if (n > d)
			{
				Lval = d;
				Hval = n;
			}
			else
			{
				Hval = d;
				Lval = n;
			}

			for (int i = Lval; i > 0; i--)     //Start iteration loop to reach lowest terms
			{
				if ((Lval % i == 0) && (Hval % i == 0))  //Check if the number is directly divisible
				{
					n = n / i;
					d = d / i;
					break;    //Conditional break statement to exit loop after iterating to this point
				}
			}

		};

		void print()
		{
			//Function Simply prints out the values stored the attributes after calculations
			cout << *numerator << " / " << *denominator;
		}

		void getNumDenom(int iNum, int iDenom)   //Method to prompt user for input
		{
			

		}; 

		void setNumDenom()
		{

		
		};

};

int main()
{
	char input = 'x'; //User input character initialized

	//Fraction *Fract1 = new Fraction(); //OBJECT CREATED and memory allocated and constructor called
	//Fraction *FractNew = new Fraction();

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