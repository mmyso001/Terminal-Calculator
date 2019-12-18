/*
*Meekaeel Mysorewala
* Description: This program takes user imput from the command line and depending on if the user inputs -a -m or -x
*will add, multiply, and square the last value.  In order to parse from the command line, getopt is used.
*/


#include <stdlib.h>
#include <stdio.h>

 main (int argc, char **argv){
	extern int optind;
	extern char *optarg;
	static char usg[] = "Usage: minicalc[-a num] [-m num] [-x] value";	
	int option;
	int xf = 0; /*flags for switch statement*/
	int mf = 0;
	int af = 0;
	int mn;
 	int an;
	float value;
	float answer;
	if(argc == 1)/*checks to see if one argument was inputted*/
	{
		printf("You need at least 1 argument\n%s\n", usg);
		exit(0);
	
	}
	while((option = getopt(argc, argv, "a:m:x")) != -1)
	{
		switch(option) /*switch statement with nested if statments to check what function was inputted and if the numbers are the correct parameters*/
		{
			case 'a':
			af = 1;
			an = atoi(optarg);
			if(an < 1 || an > 500)
			{
			printf("Please enter a valid number for addition for between 1 - 500\n%s", usg);
			exit(0);
			}
			break;
			
			case 'm':
			mf = 1;
			mn = atoi(optarg);
			if(mn < 1 || mn > 10)
			{
			printf("Please enter a valid number for multiplication between 1-10\n%s", usg);
			exit(0);
			} 
			break;
			
			case 'x':
			xf = 1;
			break;
			
		}
	}
		value = atoi(argv[optind]);
	
		if(value < 1 || value > 50)
		{
			printf("Please enter a valid value between 1-50\n%s", usg);
			exit(0);
		}
		
         
		answer = value;
	
		if(xf == 1)/*completes the math from the numbers entered*/
		{
			answer = value * value;
		}
		if(mf == 1)
		{
			answer = answer * mn;
		}
		if(af == 1)
		{
			answer = answer + an;
		}
		printf("Answer: %.2f\n", answer);/*prints the final answer*/
		exit (0);
}
