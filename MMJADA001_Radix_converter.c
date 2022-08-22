#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*Required defined constants*/
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Adam Mamoojee"
#define YEAR 2022

int main() 
{
    /*Ouput of required program detail*/
    char *outline = "****************************";
    printf("%s \n", outline);
    printf("%s \n" , TITLE);
    printf("%s %s \n" , "Written by:", AUTHOR);
    printf("%s %d \n" , "Date:", YEAR);
    printf("%s", outline);
    
    /*Input of required decimal number*/
    int number;
    printf("\n%s", "Enter a decimal number: ");
    scanf("%d", &number);
    
     /*Loop that executes on the condition that the decimal number is larger than zero*/
    while(number>0){
   
   printf("\n%s %d", "The decimal number you have entered is", number);
    int radix;
    
    /*Input of the Radix number required for conversion.*/
    printf("\n%s", "Enter a radix for the converter between 2 and 16: ");
    scanf("%d", &radix);
    
    /*Output of required division types and Log2 or decimal number.*/
    printf("\n%s %d", "The radix you have entered is", radix);
    printf("\nThe log2 of the number is %.2f", log2(number));
    printf("\nThe integer result of the number divided by %d is %d",radix ,(number/radix));
    printf("\nThe remainder is %d",(8%radix));
    
    /*Instantiation of function that does the conversion.*/
    Dec2RadixI(number, radix);
    
    /*Next decimal input.*/
    printf("\n%s", "Enter a decimal number: ");
    scanf("%d", &number);
    
    }
    /*Output for end of program.*/
    printf("%s", "EXIT");
    
    return 0;
}

/*Fucntion that does the Radix conversion*/

void Dec2RadixI(int decValue, int radValue){
    
    char conversion[10000];                                 /*Array to store output.*/
    conversion[0] = '0';                                    /*Needed to output 0 if decimal number is 0.*/
    char key[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B','C', 'D', 'E', 'F'}; /*Key for easy conversion*/
    int index = 0;                                          /*Tracks number of array inputs*/
    
    /*Algorithim to carry out conversion*/
    while (decValue>0){
        int keyvalue;
        keyvalue = decValue%radValue;               /*remainder needed to obtain correct conversion value*/
        conversion[index] = key[keyvalue];          /*Adding conversion. to string*/
        decValue = decValue/radValue;               /*Divinding to get to next integer*/
        index++;
        }
        
        /*Temporary array and for loops needed to reverse the string into the correct order*/
    char arrtemp[index+1];
    for (int k=0; k<index; k++){
         arrtemp[k] = conversion[index-k-1];
         
    }
    for (int k=0; k<index; k++){
         conversion[k] = arrtemp[k];
    }
    
        /*The ouput of the conversion*/
      printf("\nThe radix-%d value is %s", radValue, conversion);
      memset(conversion, 0, index);     /*Resets the Array*/        
}