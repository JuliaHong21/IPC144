/* -------------------------------------------
Name: Youngeun Hong
Student number: 159100171
Email: yhong38@myseneca.ca
Section: u
Date: 31 Oct 2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


int main (void)
{
    // Declare variables here:
	struct Name fullName = { "", "", "" };
	struct Address fullAddress = { 0, "", 0, "", "" };
	struct Numbers contact = { "", "", "" };
	char answer;

    // Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");


    // Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", fullName.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &answer);

	if (answer != 'n' || answer != 'N') {   //ask if the user has a middle name
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", fullName.middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", fullName.lastName);


    // Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &fullAddress.streetNumber);

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", fullAddress.street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &answer);

	if (answer != 'n' || answer != 'N') {  //ask if the user has an apartment number
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &fullAddress.apartmentNum);
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", fullAddress.postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", fullAddress.city);


    // Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &answer);

	if (answer != 'n' || answer != 'N') {  //ask if the user has a cell phone number
		printf("Please enter the contact's cell phone number: ");
		scanf(" %10[^\n]", contact.cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &answer);

	if (answer != 'n' || answer != 'N') {  //ask if the user has a home phone number
		printf("Please enter the contact's home phone number: ");
		scanf(" %10[^\n]", contact.home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("  %c", &answer);

	if (answer != 'n' || answer != 'N') {  ////ask if the user has a business phone number
		printf("Please enter the contact's business phone number: ");
		scanf(" %10[^\n]", contact.business);
	}
	
	// Display Contact Summary Details
	printf("\n");
	printf("Contact Details\n"); //Contact Details
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", fullName.firstName);
	printf("Middle initial(s): %s\n", fullName.middleInitial);
	printf("Last name: %s\n", fullName.lastName);
	printf("\n");
	
	printf("Address Details\n"); //Address Details
	printf("Street number: %d\n", fullAddress.streetNumber);
	printf("Street name: %s\n", fullAddress.street);
	printf("Apartment: %d\n", fullAddress.apartmentNum);
	printf("Postal code: %s\n", fullAddress.postalCode);
	printf("City: %s\n", fullAddress.city);
	printf("\n");

	printf("Phone Numbers:\n"); //Phone Numbers
	printf("Cell phone number: %s\n", contact.cell);
	printf("Home phone number: %s\n", contact.home);
	printf("Business phone number: %s\n", contact.business);
	printf("\n");

    // Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!\n");


    return 0;
}

/*  SAMPLE OUTPUT:
    
    Contact Management System
    -------------------------
    Please enter the contact's first name: Tom
    Do you want to enter a middle initial(s)? (y or n): y
    Please enter the contact's middle initial(s): L. A.
    Please enter the contact's last name: Wong Song
    Please enter the contact's street number: 20
    Please enter the contact's street name: Keele Street
    Do you want to enter an apartment number? (y or n): y
    Please enter the contact's apartment number: 40
    Please enter the contact's postal code: A8A 4J4
    Please enter the contact's city: North York
    Do you want to enter a cell phone number? (y or n): Y
    Please enter the contact's cell phone number: 9051116666
    Do you want to enter a home phone number? (y or n): Y
    Please enter the contact's home phone number: 7052227777
    Do you want to enter a business phone number? (y or n): Y
    Please enter the contact's business phone number: 4163338888

    Contact Details
    ---------------
    Name Details
    First name: Tom
    Middle initial(s): L. A.
    Last name: Wong Song

    Address Details
    Street number: 20
    Street name: Keele Street
    Apartment: 40
    Postal code: A8A 4J4
    City: North York

    Phone Numbers:
    Cell phone number: 9051116666
    Home phone number: 7052227777
    Business phone number: 4163338888

    Structure test for Name, Address, and Numbers Done!
*/