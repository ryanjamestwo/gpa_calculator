/*******************************************************************************
 * AUTHORS      : RJ Calabio
 * STUDENT IDs  : 1222714
 * AS 5 		: Selection & Repetition
 * CLASS        : CS1A
 * SECTION      : T-Th 8:00a
 * DUE DATE     : 04/15/2021
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include<cstring>
using namespace std;

/*******************************************************************************
 * Selection & Repetition
 * -----------------------------------------------------------------------------
 * This program prompts user for letter grades of each class that they took.
 * The program will accept inputs until an X is inputed. This will repeat 3
 * times.
 * -----------------------------------------------------------------------------
 * INPUT:
 *     letterGrade - user inputs the letter grade they got in their class
 *
 * OUTPUT:
 *	   totalPoints - the total number of grade points that a person got
 *	   finalGPA	   - the final GPA of the user
 *
 ******************************************************************************/

int main()
{
	/***************************************************************************
	 * OUTPUT - Class Heading
	 *
	 * PROGRAMMER   : Programmers' Names
	 * CLASS        : Student's Course
	 * SECTION      : Class Days and Times
	 * ASSIGNMENT	: Assignment Name
	 *
	 * -------------------------------------------------------------------------
	 * PROCESSING
	 * -------------------------------------------------------------------------
	 *
	 * LOOP_AMNT	: Number of times the program should loop
	 *
	 **************************************************************************/

	const char PROGRAMMER[]  = "RJ Calabio";
	const char CLASS[]       = "CS1A";
	const char SECTION[]     = "T-Th at 8:00a";
	const char ASSIGNMENT[]  = "Selection & Repetition";

	const int  LOOP_AMNT  	 = 3;

	int   counter; 		//CALC & OUT  - counter for for loop

	char  letterGrade;  //IN & CALC   - input for grades
	int   totalPoints;  //CALC & OUT  - sums total grade points
	float finalGPA;	    //CALC & OUT  - calculates final GPA
	int   gradeCount;	//CALC & CALC - counts # of inputed grades
	bool  invalid;		//CALC & CALC - whether or not input is valid

	/***************************************************************************
	 * OUTPUT - Class Heading
	 **************************************************************************/

	cout << left;
	cout << "***************************************************************\n";
	cout << "*  PROGRAMMMED BY: "    << PROGRAMMER  << endl;
	cout << "*  "      << setw(14)   << "CLASS"     << ": " << CLASS    << endl;
	cout << "*  "      << setw(14)   << "SECTION"   << ": " << SECTION  << endl;
	cout << "*  ASSIGNMENT 5  "		 << ": "		<<	ASSIGNMENT		<< endl;
	cout << "*************************************************************\n\n";
	cout << right;


	/***************************************************************************
	 * INPUT - Starts with a for loop which loops the program 3 times.
	 * 		   Goes into a do-while that error checks if the input given is
	 * 		   valid.
	 **************************************************************************/
	for(counter = 1; counter <= LOOP_AMNT; counter = counter + 1)
	{
		totalPoints  = 0;
		gradeCount   = 0;
		cout << "TEST CASE # " << counter << endl;

		do //while(invalid)
		{

			cout << "\tEnter Letter Grade # " << gradeCount + 1 << ": ";
			cin.get(letterGrade);
			cin.ignore(10000,'\n');
			letterGrade = toupper(letterGrade);

			invalid = (letterGrade != 'A' &&
						letterGrade != 'B' &&
						letterGrade != 'C' &&
						letterGrade != 'D' &&
						letterGrade != 'F' &&
						letterGrade != 'X');

		}while(invalid);

		/***********************************************************************
		 * PROCESSING - A while loop checks whether or not the input is X.
		 * 				If it isn't the program adds the appropriate points
		 * 				to the totalPoints variable. The gradeCount is
		 * 				updated and then a do-while loop error checks to see
		 * 				if valid inputs are inputed.
		 **********************************************************************/

		while(letterGrade != 'X')
		{
			switch (letterGrade)
			{
			case'A' : totalPoints = totalPoints + 4;
					  break;
			case'B' : totalPoints = totalPoints + 3;
					  break;
			case'C' : totalPoints = totalPoints + 2;
					  break;
			case'D' : totalPoints = totalPoints + 1;
					  break;
			} //switch(letterGrade)
			gradeCount   = gradeCount + 1;


			do //while(invalid)
			{
				cout << "\tEnter Letter Grade # " << gradeCount + 1 << ": ";
				cin.get(letterGrade);
				cin.ignore(10000,'\n');
				letterGrade = toupper(letterGrade);

				invalid = (letterGrade != 'A' &&
							letterGrade != 'B' &&
							letterGrade != 'C' &&
							letterGrade != 'D' &&
							letterGrade != 'F' &&
							letterGrade != 'X');

			}while(invalid);

		} //while(letterGrade != 'X')


		/***********************************************************************
		 * OUTPUT - When an X is inputed, the program checks if it going to
		 * 			do a calculation in which the calculation would involve
		 * 			dividing by 0. If the gradeCount doesn't equal 0,
		 * 			the program outputs the final GPA and total grade points
		 **********************************************************************/
		if(gradeCount != 0)
		{
			finalGPA = totalPoints / float(gradeCount);
			cout << endl << setprecision(2) << fixed;
			cout << "Total Grade Points: " << totalPoints << endl;
			cout << "GPA: " << finalGPA;
			cout << endl << endl;
		} //if(gradeCount == 0)

	} //for(counter = 1; counter <= 3; counter = counter + 1)

	return 0;
}


