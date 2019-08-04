/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

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
	
	int flag = 0;

	while (flag == 0)
	{
		printf("Please enter the contact's street number: ");
		street_num = getInt();

		if (street_num >= 0)
		{
			address->streetNumber = street_num;
			flag = 1;
		}
	}

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearKeyboard();

	// get apartment number
	printf("Do you want to enter an apartment number? (y or n): ");

	if (yes() == 1) //ask if the user has an apartment number
	{		
		int flag = 0;
		while (flag == 0)
		{
			printf("Please enter the contact's apartment number: ");
			apartment_num = getInt();

			if (apartment_num >= 0)
			{
				address->apartmentNumber = apartment_num; 
				flag = 1;
			}
		}
			
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
void getNumbers(struct Numbers* numbers)
{
	//get cell phone number
	printf("Please enter the contact's cell phone number: ");  //a cell number is manatory
	getTenDigitPhone(numbers->cell);
	
	//get home phone number
	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes() == 1) //ask if the user has a home phone number
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);		
	}

	//get business phone number
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes() == 1) //ask if the user has a business phone number
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}

}

// getContact:
void getContact(struct Contact* contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}