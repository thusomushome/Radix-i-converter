#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Name"
#define YEAR 2022


char str[30]="";
void*Dec2RadixI(int decValue ,int radValue){
    char num [17]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','\0'};
    char ch [17]="";
    int decimal = decValue;
    int index =0;
    int rad = radValue;
    int i = 1;
    int Rem = 0;   // rem - remainder

    while (i>0)
    {
        i = (decimal/rad); // evaluate decimal/radix

        Rem = ceil(((decimal/(float)rad)-i)*rad);// calculate remainder of decValue by radValue multiply by (i- decimal/radix divider)
        sprintf(ch,"%c",num[Rem]);// Convert the element from an array to string
        strcat(str,ch);
        decimal = i;// assign new i to the decimal variable

        index++;
    }
    strrev(str);
    return str;
}

int main (void)
{
    printf("*****************************\n");
    printf("%s\n",TITLE);// print the title of the code
    printf("Written by:%s\n",AUTHOR);// print the Author of the code
    printf("Date:%d\n",YEAR);// print the DATE of the code
    printf("*****************************\n");

    int deci =0; // create a variable for positive integer number
    int radix =0; // create a variable for radix number

do // create a do while loop that will operate while decimal number is greater than 0 and radix greater than zero
{
    printf("Enter a decimal number: ");// this will prompt external user to insert a positive integer number
    scanf("%d",&deci);

    if (deci>=0){
            printf("The number you have entered is %d\n",deci);}//print the integer number if it is greater or equal to 1
    else
{
    printf("EXIT");// if the number is less than zero print EXIT and break
    break;
}

    printf("Enter a radix for the converter between 2 and 16: ");// this will prompt the user to enter a radix value between 2 and 16
    scanf("%d",&radix);

    if (radix>=0){
            printf("The radix you have entered is %d\n",radix);}//print the radix value entered by user if it is greater or equal to zero
    else
{
    printf("EXIT");// print EXIT if the radix value entered is less than zero and break
    break;
}

    double log2 = (log(deci)/log(2)); // create a log equation between decimal number
    printf("The log2 of the number is %1.2f\n",log2);// print the log2 number with 2 decimal points

    int integerdivider = deci/radix; //it will create a variable that will be a divider between decimal number and radix
    printf("The integer result of the number divided by %d is %d\n",radix,integerdivider);//print the results of the integerdivider equation

    int remainder = deci%radix; // create a remainder of decimal number by the radix
    printf("The remainder is %d\n",remainder); // print the remainder of the variable


    printf("The radix-%d value is %s\n",radix,Dec2RadixI(deci,radix)); // print the convers
    strcpy(str,"");

    return 0;

}while (deci >=0 || radix >=0);
}
