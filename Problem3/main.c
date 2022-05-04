#include <stdio.h>
#include <stdlib.h>

//
// This program takes as command line a single integer value which represents a year and then computes and displays the Easter date for that year
// The algorithm for computing the catholic Easter date is the following :
//	A = year mod 19
//	B = year mod 4
//	C = year mod 7
//	D = (19 * A + 24) mod 30
//	E = (2 * B + 4 * C + 6 * D + 5) mod 7 where mod is the remainder of the division of x to y.
// Easter day is then(22 + E + D) March.Note that this formula can give a date from April if 22 + E + D > 31; also take this case into account!
// The program will display the Easter date in the following way "The Easter day is 02 April " (use trailing zeros for the day if it is less than 10)

int main(int argc, char* argv[]) {

	int easter_year, easter_day;
	char * easter_month;
	scanf("%d", &easter_year);

	if (easter_year >= 10000 || easter_year <= 1876)
	{
		printf("Invalid input, the year should be greater or equal to 1876");
		return 0;
	}
	int A = easter_year % 19;
	int B = easter_year % 4;
	int C = easter_year % 7;
	int D = (19 * A + 24) % 30;
	int E = (2 * B + 4 * C + 6 * D + 5) % 7;

	easter_day = 22 + E + D;
	if (easter_day > 31)
	{
		easter_day = easter_day - 31;
		easter_month = "April";
	}
	else
	{
		easter_month = "March";
	}

	if (easter_day < 10)
		printf("In %d, the Easter date is %s %02d", easter_year, easter_month, easter_day);
	else
		printf("In %d, the Easter date is %s %d", easter_year, easter_month, easter_day);
	return 0; 
}

