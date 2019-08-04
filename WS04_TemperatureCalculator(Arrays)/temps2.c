//--------------------------------------------------
// Name: Youngeun Hong          
// Student Number: 159100171
// Email: yhong38          
// Section: U        
// Workshop: At - Home       
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include <stdio.h>

int main(void) {

	int days;
	int averDays;
	int i;
	int highTem[10]; //high temperature from user
	int lowTem[10]; //low temperature from user
	int totalHighTem = 0;
	int totalLowTem = 0;
	int highstTem;
	int lowestTem;
	int highstDay = 0;
	int lowestDay = 0;
	float average;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);

	while (days < 3 || days > 10) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
	}

	printf("\n");

	for (i = 0; i < days; i++) {

		//to take the high temperature from user
		printf("Day %d - High: ", i + 1);
		scanf("%d", &highTem[i]);

		//to take the low temperature from user
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lowTem[i]);

	}

	//print high & low temperature with days
	printf("\n");
	printf("Day  Hi  Low\n");

	for (i = 0; i < days; i++) {
		printf("%d%5d%6d\n", i + 1, highTem[i], lowTem[i]);

	}

	// The highst & lowest temperature and average
	highstTem = highTem[0];
	lowestTem = lowTem[0];

	for (i = 0; i < days; i++) {	

		//to find the highst temperature
		if (highTem[i] > highstTem) {

			highstTem = highTem[i];
			highstDay = i + 1;
		}
	
		//to find the lowst temperature
		if (lowTem[i] < lowestTem) {

			lowestTem = lowTem[i];
			lowestDay = i + 1;
		}	
	}


	// print highest and lowest temperature
	printf("\nThe highest temperature was %d, on day %d\n", highstTem, highstDay);

	printf("The lowest temperature was %d, on day %d\n", lowestTem, lowestDay);


	printf("\nEnter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
	scanf("%d", &averDays);

	//to find average temperature
	while (averDays >= 0)
	{
		if (averDays < 1 || averDays > 4) {
			printf("\nInvalid entry, please enter a number between 1 and 4, inclusive: ");
			scanf("%d", &averDays);
		}

		else {
			for (i = 0; i < averDays; i++) {
				//sum of all inputs of user
				totalHighTem += highTem[i];
				totalLowTem += lowTem[i];
			}
			average = (float)(totalHighTem + totalLowTem) / (float)(2*averDays);
			printf("\nThe average temperature up to day %d is: %.2f\n", averDays, average);

			printf("\nEnter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
			scanf("%d", &averDays);

			totalHighTem = 0;
			totalLowTem = 0;

		}

	}

	printf("\nGoodbye!\n");
	
		

return 0;



}
