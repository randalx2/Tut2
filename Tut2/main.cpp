//PRANEEL MISTHRY
//202515355
//COMPUTER METHODS 3 -- TUT2
//24 FEBRUARY 2016
/**********************************************************************************************************************************/

//Program gives proper results 
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
/*3 MARCH 2016-- Will Attempt to alter code to use operator overloading in Branch "Operator_Overloading"**************************/
/*Last commit has been pushed for this tut and all final core specs have been successfully met -- Merged into Master Branch*/

/***************Previous Methods have been commented out instead of deleted For future reference*************************************************/
/*6 MARCH 2016 -- Successfully overloaded the iostream operators to make it easier to input and output fractions************/
/**************************************************************************************************************************/
#include <iostream>
#include <exception>
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
			*denominator = d;
		}

		~Fraction()
		{                  //Default Destructor
			
			
		}

		//Accessors
		void getNumDenom(int &outNum, int &outDenom)
		{
			outNum = *numerator;
			outDenom = *denominator;
		}

		//Accessors for the numerator and denominator separately
		int getNum()
		{
			return *numerator;
		}

		int getDenom()
		{
			return *denominator;
		}

		// Defining methods and prototypes

		/*Fraction add(Fraction nextFraction)   //Creating a method of user defined datatype argument object
		{
			int n, d;
			n = *numerator**(nextFraction.denominator) + *denominator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			return Fraction(n / gcd(n,d), d / gcd(n,d));
			
		};*/

		Fraction operator+(Fraction nextFraction)  //Operator overloading method for addition
		{
			int n, d; //Needed temp storage variables for operator overloading methods
			n = *numerator**(nextFraction.denominator) + *denominator**(nextFraction.numerator);

			try{
				d = *denominator**(nextFraction.denominator);
				if (d == 0)
				{
					throw "Possible ZERO Denominator Detected";
				}
				return Fraction(n / gcd(n, d), d / gcd(n, d));
			}
			catch (const char *e)
			{
				cout << e;
			}	
		}


		/*Fraction subtract(Fraction nextFraction)  // NB IN BUILT OBJECTS WITHIN CLASS METHODS ARE ONLY VISIBLE TO METHODS
		{
			int n, d;
			n = *numerator**(nextFraction.denominator) - *denominator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			return Fraction(n / gcd(n,d), d / gcd(n,d));
		};*/

		Fraction operator-(Fraction nextFraction)  //Operator overloading method for subtraction
		{
			int n, d;
			n = *numerator**(nextFraction.denominator) - *denominator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			return Fraction(n / gcd(n, d), d / gcd(n, d));
		}

		/*Fraction multiply(Fraction nextFraction)
		{
			int n, d;
			n = *numerator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			return Fraction(n / gcd(n,d), d / gcd(n,d));

		};*/

		Fraction operator*(Fraction nextFraction)  //Operator overloading method for multiplication
		{
			int n, d;
			n = *numerator**(nextFraction.numerator);
			d = *denominator**(nextFraction.denominator);

			return Fraction(n / gcd(n, d), d / gcd(n, d));
		}

		/*Fraction divide(Fraction nextFraction)
		{
			int n, d;
			n = *numerator**(nextFraction.denominator);
			d = *denominator**(nextFraction.numerator);
			
			return Fraction(n / gcd(n,d), d / gcd(n,d));

		};*/

		Fraction operator/(Fraction nextFraction)  //Operator Overloading method for division
		{
			int n, d;
			n = *numerator**(nextFraction.denominator);
			d = *denominator**(nextFraction.numerator);

			return Fraction(n / gcd(n, d), d / gcd(n, d));
		}

		// method to get lowest terms for fractions
		//the previous method from other branches has been omitted in favour of this one -- Euclid's Algortith gcd
		//since this method makes it easier to simply return a fraction in simplest terms

		//Overloading the stream insertion and extraction operators
		friend ostream &operator << (ostream &output, Fraction &someFraction);  //Function prototypes
		friend istream &operator >> (istream &input, Fraction &someFraction);

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
			cout << *numerator << " / " << *denominator << " From print method" << endl;  
		}  //NB This function is not needed if we have overloaded the << operator for ostream


		friend ostream &operator << (ostream &output, Fraction &someFraction){

			output << *someFraction.numerator << " / " << *someFraction.denominator << " From ostream overloading method" << endl; //Displays result as fraction for cout
			return output;
		}

		friend istream &operator >> (istream &input, Fraction &someFraction){

			input >> *someFraction.numerator >> *someFraction.denominator; //simply uses cin to assign the numerator and denominator
			return input;
		}
	
};

int main()
{
	cout << " Welcome to Fraction Mathboy game" << endl;
	cout << "This will diplay the result of math operations on fractions" << endl;

	//Since the input stream operator is overload in the class we can also use cin to set the fractions
	Fraction *FractA = new Fraction();  //No need to use overloaded constructor now as I have overloaded the >> operator....
	Fraction *FractB = new Fraction();  //..to get the user to input the values for the fractions
	Fraction *FractC = new Fraction();  // default constructor called -- Store result in this object

	cout << "Enter the Numerator and Denominator for the First Fraction " << endl;
	cin >> *FractA;  // Store the inputs in the attributes of object *FractA

	//Check invalid denominator input
	try{
		if (FractA->getDenom() == 0)
			throw "Invalid Zero input for Denominator Detected. Please Restart and Try again";
	}
	catch (const char *e)
	{
		cout << "Exception Occurred" << endl;
		cout << e;
	}

	cout << "Enter the Numerator and Denominator for the Second Fraction " << endl;
	cin >> *FractB;

	//Check invalid denominator input
	try{
		if (FractB->getDenom() == 0)
			throw "Invalid Zero input for Denominator Detected, Please Restart and Try again";
	}
	catch (const char *e)
	{
		cout << "Exception Occurred" << endl;
		cout << e << endl;
	}


	/*Running basic tests to check correctness*/

	cout << "The results of addition, subtraction, multiplication and division are: " << endl;

	//Previous method equations have been commented out for future reference

	//*FractC = FractA->add(*FractB);  //Result should be 3/4

	try
	{
		if (FractA->getDenom() == 0 || FractB->getDenom() == 0)
			throw "Possible ZERO DENOMINATOR detected";

		*FractC = *FractA + *FractB;
		FractC->print(); //Print out the attributes stored in FractC object
	}

	catch (const char *e)
	{
		cout << e;
		cout << endl;
	}

	//Next I'll repeat the printout using the overloaded stream insertion operator method
	cout << *FractC << endl;

	//*FractC = FractA->subtract(*FractB);  //Result should be 1/4

	*FractC = *FractA - *FractB;
	FractC->print();

	//Next I'll repeat the printout using the overloaded stream insertion operator method
	cout << *FractC << endl;


	//*FractC = FractA->multiply(*FractB);  //Result should be 1/8

	*FractC = *FractA**FractB;
	FractC->print();

	//Next I'll repeat the printout using the overloaded stream insertion operator method
	cout << *FractC << endl;


	//*FractC = FractA->divide(*FractB);  //Result should be 2

	//Taking into account the possiblility that Fract B could have a value of 0
	//Will need to check the numerator of FractB for 0
	try
	{
		if (FractB->getNum() == 0)
		{
			throw "Fraction B is 0 value. Math Error";
		}

		*FractC = *FractA / *FractB;
		FractC->print();
	}
	catch (string str)
	{
		cout << str;
	}
	

	//Next I'll repeat the printout using the overloaded stream insertion operator method
	cout << *FractC << endl;


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
	//We are done using the objects so we can release them from memory

	delete FractA;
	delete FractB;
	delete FractC;

	system("PAUSE");
	return 0;
}