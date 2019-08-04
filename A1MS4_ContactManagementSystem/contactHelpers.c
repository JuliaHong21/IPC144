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
#include <ctype.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}
// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
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


// getIntInRange:
int getIntInRange(int min, int max)
{
	int Value = getInt();

	while (Value < min || Value > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		Value = getInt();
	}

	return Value;
}

// yes:
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

			else if (option == 'n' || option == 'N')
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

// menu:
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
	printf("\n");

	return num_option;
}

// contactManagerSystem:
void contactManagerSystem(void)
{
	struct Contact contacts[MAXCONTACTS]
	= { { { "Rick", {'\0'}, "Grimes" },
		  { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	      { "4161112222", "4162223333", "4163334444" } },
	    {
		  { "Maggie", "R.", "Greene" },
		  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		  { "9051112222", "9052223333", "9053334444" } },
	   {
		  { "Morgan", "A.", "Jones" },
		  { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
		  { "7051112222", "7052223333", "7053334444" } },
	   {
	 	 { "Sasha", {'\0'}, "Williams" },
		 { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	 	 { "9052223333", "9052223333", "9054445555" } },
	  };
	
	int z = 1; //flag for while roof

	while (z != -1)
	{
		z = menu();

		switch (z)
		{
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 0:

			printf("Exit the program? (Y)es/(N)o: ");

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


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;
	int flag = 0; // 0: did not find a character which is not a digit, 1: found a charagter which is not a digit

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");

		if (!needInput)
		{
			int i;
			for (i = 0; i < 10; i++) {

				if (!flag && !isdigit(telNum[i]))
				{
					needInput = flag = 1;
				}
			}

			if (flag)
				printf("Enter a 10-digit phone number: ");
		
			flag = 0;
		}
	}
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	int find_index = -1;

	for (i = 0; i < size; i++)
	{
		if (find_index == -1)
		{
			if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
			{
				find_index = i;
			}
				
		}
	}
		
	return find_index;
}



// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int dp_footer)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", dp_footer);
}

// displayContact:
void displayContact(const struct Contact* dp_contact)
{
	if (strlen(dp_contact->name.middleInitial) != 0 )
	{
		printf(" %s %s %s\n", dp_contact->name.firstName, dp_contact->name.middleInitial, 
			dp_contact->name.lastName);
	}

	else
	{
		printf(" %s %s\n", dp_contact->name.firstName, dp_contact->name.lastName);
	}

		printf("    C: %-10s   H: %-10s   B: %-10s\n", dp_contact->numbers.cell,
		dp_contact->numbers.home, dp_contact->numbers.business);
	
	if (dp_contact->address.apartmentNumber != 0)
	{
		printf("       %d %s, Apt# %d, %s, %s\n", dp_contact->address.streetNumber, 
			dp_contact->address.street, dp_contact->address.apartmentNumber, 
			dp_contact->address.city, dp_contact->address.postalCode);

	}
	
	else
	{
		printf("       %d %s, %s, %s\n", dp_contact->address.streetNumber,
			dp_contact->address.street, dp_contact->address.city, dp_contact->address.postalCode);
	}
	
}

// displayContacts:
void displayContacts(const struct Contact dp_contacts[], int size_dpContacts)
{
	displayContactHeader();
	int count = 0;
	
	int i;
	for (i = 0; i < size_dpContacts; i++)
	{
		if (strlen(dp_contacts[i].numbers.cell) > 0)
		{
			displayContact(&dp_contacts[i]);
			count++;
			
		}
	}
	
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact search[], int size_search)
{
	char get_cellNumber[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(get_cellNumber);

	int found_index = findContactIndex(search, size_search, get_cellNumber);
	if (found_index != -1)
	{
		printf("\n");
		displayContact(&search[found_index]);	
		printf("\n");
	}

	else
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
}

// addContact:
void addContact(struct Contact add[], int size_add)
{
	int flag = 0;
	int i;
	for (i = 0; i < size_add; i++)	
	{
		if (flag == 0)
		{
			if (strlen(add[i].numbers.cell) == 0)
			{
				getContact(&add[i]);
				printf("--- New contact added! ---\n\n");
				flag = 1;
			}

		}
		
	}

	if (flag == 0)
	{	
		printf("*** ERROR: The contact list is full! ***\n\n");
	}
	
}

// updateContact:
void updateContact(struct Contact update[], int size_update)
{
	char get_cellNumber[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(get_cellNumber);
	
	int found_index = findContactIndex(update, size_update, get_cellNumber);
	if (found_index != -1)
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&update[found_index]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1)
		{
			update[found_index].name.middleInitial[0] = '\0';
			getName(&update[found_index].name);
		}

		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
		{
			update[found_index].address.apartmentNumber = 0;
			getAddress(&update[found_index].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1)
		{
			update[found_index].numbers.home[0] = '\0';
			update[found_index].numbers.business[0] = '\0';
			getNumbers(&update[found_index].numbers);
		}
						
		printf("--- Contact Updated! ---\n\n");	

	}
	

	else
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	


}

// deleteContact:
void deleteContact(struct Contact delete[], int size_del) 
{
	char get_cellNumber[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(get_cellNumber);
	
	int found_index = findContactIndex(delete, size_del, get_cellNumber);

	if (found_index != -1)
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&delete[found_index]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");

		if (yes() == 1)
		{
			delete[found_index].numbers.cell[0] = '\0';
			delete[found_index].numbers.business[0] = '\0';
			delete[found_index].numbers.home[0] = '\0';
			delete[found_index].name.middleInitial[0] = '\0';
			delete[found_index].address.apartmentNumber = 0;

			printf("--- Contact deleted! ---\n\n");
		}
		else
		{
			printf("\n");
		}
	}

	else
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
}

// sortContacts:
void sortContacts(struct Contact sort[], int size_sort) 
{

}