/*
	 Name:      <Youngeun Hong>
	 Student#:  <159100171>
	 Section:   <U>
*/

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include <stdio.h>

int main(void)
{
	double amt = 0; // amount to be paid  
	double gst = 0; 
	double total = 0; // total of amount and gst
	int balance_owing = 0;  
	int loonies = 0; 
	int quarters = 0; 
	int dimes = 0; 
	int nickels = 0; 
	int pennies =0; 
	
	//to get amount to be paid from user
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amt);

	//to find and print the value of GST
	gst = amt * 0.13 + 0.005;
	printf("GST: %.2lf\n", gst);
	total = amt + gst;
	printf("Balance owing: $%.2lf\n", total);

	balance_owing = total * 100; // for integer division
	
	//calculating the number of loonies and balace using modulus
	loonies = balance_owing / 100;
	balance_owing = balance_owing % 100;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, (double)balance_owing / 100);

	//calculating the number of loonies and balace using modulus
	quarters = balance_owing / 25;
	balance_owing = balance_owing % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (double)balance_owing / 100);

	//calculating the number of dimes and balace using modulus
	dimes = balance_owing / 10;
	balance_owing = balance_owing % 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (double)balance_owing / 100);

	//calculating the number of nickels and balace using modulus
	nickels = balance_owing / 5;
	balance_owing = balance_owing % 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, (double)balance_owing / 100);

	//calculating the number of pennies and balace using modulus
	pennies = balance_owing / 1;
	balance_owing = balance_owing % 1;
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (double)balance_owing / 100);

	return 0;
}
