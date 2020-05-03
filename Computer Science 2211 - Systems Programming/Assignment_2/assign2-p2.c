#include<stdio.h> 

// Function to calculate x raised to the power y 
float power(float base, unsigned int exponent) 
{ 
    // Base case
    if (exponent == 0) 
        return 1; 
    else if (exponent%2 == 0) 
        return power(base, exponent/2)*power(base, exponent/2); 
    else
        return base*power(base, exponent/2)*power(base, exponent/2); 
} 

// Program to test function power 
int main() 
{ 
    // Variables Initialized
    float base = -1; 
    int exponent;

    // Used to check if the base is positive:
    float posCheck = (base*(-1));
    while (posCheck > 0) {
    // Continues asking for input till the input is valid.
        printf("Please enter a (positive float) base number:  ");
        scanf(" %f",&base);
        posCheck = base * (-1);
    }
    // Input
    printf("Please enter an integer number for the exponent:  ");
    scanf(" %d",&exponent);


    printf("Your number is %.3f", power(base, exponent)); 
    return 0; 
}