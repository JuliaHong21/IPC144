// Name: Youngeun Hong
// Student Number: 159100171
// Email: yhong38@myseneca.ca
// Section: U
// Workshop: 3

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#define NUMS 4
#include<stdio.h>
int main(void) {

	printf("---=== IPC Temperature Analyzer ===---\n");

	int i;
	int highTem; //high temperature from user
	int lowTem; //low temperature from user
	int totalHigh = 0;
	int totalLow = 0;
	int highstTem = 0;
	int lowestTem = 0;
	int highstDay = 0;
	int lowestDay = 0;
	float average;

	//roof for printing days
	for (i = 0; i < NUMS; i++) {

		//to take the high temperature from user
		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &highTem);
		printf("\n");

		//to take the high temperature from user
		printf("Enter the low value for day %d: ", i + 1);
		scanf("%d", &lowTem);
		printf("\n");

		//to print incorrect message
		while (highTem > 40 || lowTem < -40 || highTem < lowTem) {

			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");

			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &highTem);
			printf("\n");

			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &lowTem);
			printf("\n");

		}

		//sum of all correct inputs of user
		totalHigh += highTem;
		totalLow += lowTem;

		//to find the highst temperature
		if (highTem > highstTem) {

			highstTem = highTem;
			highstDay = i + 1;

		}

		//to find the lowst temperature
		if (lowTem < lowestTem) {

			lowestTem = lowTem;
			lowestDay = i + 1;
		}

		
	}

	//culcuate and print average of all correct inputs of user
	average = (float)(totalHigh + totalLow) / (NUMS * 2);
	printf("The average (mean) temperature was: %.2f\n", average);

	//to print the highst and lowest temperature and the day
	printf("The highest temperature was %d, on day %d\n", highstTem, highstDay);
	printf("The lowest temperature was %d, on day %d\n", lowestTem, lowestDay);

	
	printf("\n");

	return 0;
}