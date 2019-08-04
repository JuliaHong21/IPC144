/* -------------------------------------------
Name:           
Student number: 
Email:          
Section:        
Date:           
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void) 
{
	char NL = 'x';
	int Value;

	while (NL != '\n') 
	{
		scanf("%d%c", &Value, &NL);

		if (NL != '\n')
		{
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	}

	return Value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max) 
{		
	int Value = getInt();

	while(Value < min || Value > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		Value = getInt();
	}
	
	return Value;
}

// yes function definition goes here:
int yes(void)
{
	char option, end;
	int x;
	int roof = 0; //flag for while roof	
	
	while (roof != 1)
	{
		scanf("%c%c", &option, &end);

		if (end == '\n')
		{
			if (option == 'y' || option == 'Y')
			{
				x = 1;
				roof = 1;
			}

			else if (option == 'n'|| option == 'N')
			{
				x = 0;
				roof = 1;
			}
		}

		if (roof != 1)
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
	}

	return x;
}

// menu function definition goes here:
int menu(void) 
{
	int num_option; //for return
	
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	
	num_option = getIntInRange(0, 6);
	
	return num_option;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void) 
{
	int z = 1; //flag for while roof

	while (z != -1)
	{		
		z = menu();	

		switch (z)
		{
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 3:
			printf("\n<<< Feature 3 is unavailable >>><\n\n");
			pause();
			printf("\n");
			break;

		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 5:
			printf("<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 0:			

			printf("\nExit the program? (Y)es/(N)o: ");
			
			if (yes() == 1)
			{
				printf("\nContact Management System: terminated");
				z = -1; //terminate the roof
			}
			
			printf("\n");

			break;
		
		}				
	}
}