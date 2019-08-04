/* -------------------------------------------
Name: Youngeun Hong
Student number: 159100171
Email: yhong38@myseneca.ca
Section: u
Date: 30 Oct 2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #1 here...
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNum;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #1 here...
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};
