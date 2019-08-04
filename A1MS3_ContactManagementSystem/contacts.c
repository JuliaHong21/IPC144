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

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"

// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:

#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name* name) 
{
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes() == 1) //ask if the user has a middle name
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
		clearKeyboard();

	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);
	clearKeyboard();
}


// getAddress:
void getAddress(struct Address* address) 
{
	int street_num;
	int apartment_num; 
	
	//get street number
	printf("Please enter the contact's street number: ");
	
	street_num = getInt();
	while (street_num < 0)
	{
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		scanf("%d", &street_num);
	}

	address->streetNumber = street_num;

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearKeyboard();

	// get apartment number
	printf("Do you want to enter an apartment number? (y or n): ");
	
	if(yes() == 1) //ask if the user has an apartment number
	{
		printf("Please enter the contact's apartment number: ");
		apartment_num = getInt();
		while (apartment_num < 0)
		{
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			scanf("%d", &apartment_num);
		}

		address->apartmentNumber = apartment_num;
	}

	//get postal code
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	clearKeyboard();

	//get contact's city
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	clearKeyboard();

}


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers* numbers) 
{
	//get cell phone number
	printf("Please enter the contact's cell phone number: ");  //a cell number is manatory
	scanf(" %10[^\n]", numbers->cell);
	clearKeyboard();
	
	//get home phone number
	printf("Do you want to enter a home phone number? (y or n): "); 
	if (yes() == 1) //ask if the user has a home phone number
	{	
		printf("Please enter the contact's home phone number: ");
		scanf(" %10[^\n]", numbers->home);
		clearKeyboard();
	}
	
	//get business phone number
	printf("Do you want to enter a business phone number? (y or n): "); 
	if (yes() == 1) //ask if the user has a business phone number
	{
		printf("Please enter the contact's business phone number: ");
		scanf(" %10[^\n]", numbers->business);
		clearKeyboard();
	}

}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(struct Contact* contact) 
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}

