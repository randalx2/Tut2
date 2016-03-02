//PRANEEL MISTHRY
//202515355
//COMPUTER METHODS 3 -- TUT2
//24 FEBRUARY 2016
/**********************************************************************************************************************************/

//Program gives proper results however it does seem to trigger a Debug Assertion Error at run time
//Could be an issue with the compiler or some bugs in Visual Studio 2013 on my personal laptop

//MERGED FROM FRACTION SIMPLIFIER BRANCH WITH NO CONFLICTS DETECTED
//Program prompts user to input two fractions to perform math operations

// 1 MARCH 2016
/*Code Modified in Recurring_Values Branch to allow for successive calculations of new fractions based on values assigned in code*/
/*Changed Mathboy object name to FractA, FractB and FractC**/
/*This branch uses values directly from the code to test the methods using these specs*/
/*No user input is needed from cin function in this branch -- to be added later*/
/*This branch shows how to use built in objects within a class when using methods*/
/*For instance it shows how the user defined datatype called fraction can be used to define methods and their arguments*/

/*2 MARCH 2016 MODIFYING THE MyPC-Recurring_Values Branch to enable user input of the fractions and operations*/

/**********************************************************************************************************************************/
/*3 MARCH 2016 -- Merged User Input Branch back into Master*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

int iNum1 = 1, iNum2 = 1, iDenom1 = 1, iDenom2 = 1;  //Using global variables for input

class Fraction {
private: int *numerator, *denominator; //Using pointer method to allocate dynamic memory to attributes

	     
public: Fraction()
{                                      //Default Constructor
			numerator = new int;       //Allocating dynamic memory for attributes
			denominator = new int; 

			*numerator = 1;
			*denominator = 1;   //Initialize denominator to 1 as default value
			                   //Use checking in main programe for division by 0 protection

}
		Fraction(int n, int d)    //Creating an overloading constructor to return a fraction based on user values when object created using overloading
		{                         //Useful when creating inbuilt class objects to perform operations on
			numerator = new int;  //Must allocate memory in each constructor again
			denominator = new int;

			*numerator = n;      //Assign the numerator
			
			//Doing safefty check for denominator values of 0
			if (d == 0)
			{
				cout << "A Zero value denominator is not allowed -- Exiting Program" << endl;
				exit(0); //Program will exit with error code if 0 is detected as a denominator
			}
			else 
			{
				*denominator = d;
			}
		}

		~Fraction()
		{                  //Default Destructor
			
			
		}

		// Defining methods and prototypes

		Fraction add(Fraction nextFraction)   //Creating a method of user defined datatype argument object
		{
			int n, d;
			n = *numerator**(nextFraction.denominator) + *denominator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			return Fraction(n / gcd(n,d), d / gcd(n,d));
			
		};

		Fraction subtract(Fraction nextFraction)  // NB IN BUILT OBJECTS WITHIN CLASS METHODS ARE ONLY VISIBLE TO METHODS
		{
			int n, d;
			n = *numerator**(nextFraction.denominator) - *denominator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			return Fraction(n / gcd(n,d), d / gcd(n,d));
		};

		Fraction multiply(Fraction nextFraction)
		{
			int n, d;
			n = *numerator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			return Fraction(n / gcd(n,d), d / gcd(n,d));

		};

		Fraction divide(Fraction nextFraction)
		{
			int n, d;
			n = *numerator**(nextFraction.denominator);
			d = *denominator**(nextFraction.numerator);
			
			return Fraction(n / gcd(n,d), d / gcd(n,d));

		};

		// method to get lowest terms for fractions
		//the previous method from other branches has been omitted in favour of this on
		//since this method makes it easier to simply return a fraction in simplest terms
		int gcd(int n, int d)
		{
			int remainder;
			while (d != 0)
			{
				remainder = n % d;
				n = d;
				d = remainder;
			}
			return n;
		}

		void print()
		{
			//Function Simply prints out the values stored the attributes after calculations
			cout << *numerator << " / " << *denominator << endl;  
		}
	
};

void getNumDenom()   //Function to prompt user for input
{
	//Assing values based on user's input
	cout << "Please Enter the Numerator and Demoninator for your First Fraction " << endl;
	cin >> iNum1 >> iDenom1;

	cout << "Please Enter the Numerator and Demoninator for your Second Fraction " << endl;
	cin >> iNum2 >> iDenom2;

};

int main()
{
	cout << " Welcome to Fraction Mathboy game" << endl;
	cout << "This will diplay the result of math operations on fractions" << endl;

	getNumDenom(); //Get user input

	Fraction *FractA = new Fraction(iNum1,iDenom1); // Overloading constuctor called and assigned memory
	Fraction *FractB = new Fraction(iNum2,iDenom2); //using user input variables to assign parameters of overloading constructor

	Fraction *FractC = new Fraction();  // default constructor called -- Store result in this object

	/*Running basic tests to check correctness*/

	cout << "The results of addition, subtraction, multiplication and division are: " << endl;

	*FractC = FractA->add(*FractB);  //Result should be 3/4
	FractC->print();

	*FractC = FractA->subtract(*FractB);  //Result should be 1/4
	FractC->print();

	*FractC = FractA->multiply(*FractB);  //Result should be 1/8
	FractC->print();

	*FractC = FractA->divide(*FractB);  //Result should be 2
	FractC->print();

	//This block may be needed later so I simply commented it out
	/**cout << "Please choose the math operation you would like to perform" << endl;
	cout << "Press 1 for ADDITION" << endl;
	cout << "Press 2 for SUBTRACTION" << endl;
	cout << "Press 3 for MULTIPLICATION" << endl;
	cout << "Press 4 for DIVISION" << endl;**/

	//cin >> input;

	/**switch (input)
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

	Fract1->print_lowest_terms(); **/
	

	//Enter the print function for simplifying the numbers here
	//We done using the objects so we can release them from memory

	delete FractA;
	delete FractB;
	delete FractC;

	system("PAUSE");
	return 0;
}