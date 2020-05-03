#include <stdio.h>
#include <stdlib.h>

option1(){     
	// Initialize variables:
        float number = 0;
        char conversion = 'x';
	// Valid input check:
	while ((conversion != 'K') && (conversion != 'M')) {
		printf("\nPlease input 'K' for Kilometer to Mile, and 'M' for Mile to Kilometer conversion:  ");
              	scanf(" %c", &conversion);
        }
	// Input:
	printf("\nPlease input a number to be converted:");
	scanf("\n%f", &number);
	// Calculations:
	float kToM = number*0.621371;
	float mToK = number*1.60934;
	// Output:
	if (conversion == 'K') {
                printf("\nYour result is: %.2f Miles.\n", kToM);
	}
	if (conversion == 'M') {
                printf("\nYour result is: %.2f Kilometers.\n", mToK);
	}
}

option2(){     
	// Initialize Variables
        float number = 0;
        char conversion = 'x';
  	// Valid input check
	while ((conversion != 'M') && (conversion != 'F')) {
        	printf("\n Please input 'M' for Meter to Feet, and 'F' for Feet to Meter conversion:  ");
        	scanf(" %c", &conversion);
       	}
	// Input:
        printf("\n Please input a number to be converted:");
        scanf("%f", &number);
	// Calculations:
        float mToF = number*3.28084;
        float fToM = number*0.3048;
	// Output:
        if (conversion == 'M') {
                printf("\n Your result is: %.2f Feet.\n", mToF);
        }
        if (conversion == 'F') {
                printf("\n Your result is: %.2f Meters.\n", fToM);
        }
}

option3(){
	// Initialize Variables
        float number = 0;
        char conversion = 'x';
	// Valid input check
	while (conversion != 'C' && conversion != 'I') {
              	printf("\n Please input 'C' for Centimere to Inch, and 'I' for Inch to Centimetre conversion:   ");                       
		scanf(" %c", &conversion);
        }
	// Input:
        printf("\n Please input a number to be converted:");
        scanf("%f", &number);
	// Calculations:
        float cToI = number*0.393701;
        float iToC = number*2.54;
	# Output:
        if (conversion == 'C') {
        	printf("\n Your result is: %.2f Inches.\n", cToI);
        }
        if (conversion == 'I') {
                printf("\n Your result is: %.2f Centimetres.\n", iToC);
        }
}
      
option4(){
	// Initialize Variables
        float number = 0;
        char conversion = 'x';

	// Valid input check
 	while ((conversion != 'C') && (conversion != 'F')) {
              printf("\n Please input 'C' for Celsius to Fahrenheit, and 'F' for Fahrenheit to Celsius conversion  :");
              scanf(" %c", &conversion);
        }
	// Input:
        printf("\n Please input a number to be converted:");
        scanf("%f", &number);
	// Calculations:
        float cToF = (number*(9.0/5.0)) + 32.0;
        float fToC = (number - 32.0)*(5.0/9.0);
	// Output:
        if (conversion == 'C') {
        	printf("\n Your result is: %.2f degrees Fahrenheit.\n", cToF);
        }
        if (conversion == 'F') {
        	printf("\n Your result is: %.2f degrees Celsius.\n", fToC);
        }
}

int main()
{
    // Initialize Variable
    int input;

    // Introduction:
    printf("\n Welcome to the converter program. Here are the following command options:  ");

    // Continues till user wants to quit and inputs 5.
    while (input != 5) {

	// Options menu:
        printf("\n");
        printf("   1    for conversion between Kilometers and Miles.\n");
        printf("   2    for conversion between Meters and Feet.\n");
        printf("   3    for conversion between Centimetres and Inches.\n");
        printf("   4    for conversion between Celcius and Fahrenheit.\n");
        printf("   5    to exit the program.\n");
	printf("\n");
        scanf(" %d", &input); 

         if (input == 5) {
              exit(0);
         }
         else if (input == 1) {
		option1();
         }
         else if (input == 2) {
 	 	option2();
         }
         else if (input == 3) {
		option3();
         }
         else if (input == 4) {
		option4();
        }
    }
    return 0;
}