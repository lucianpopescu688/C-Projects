#include <stdio.h>
#include <stdlib.h>

// Alice forgot her card’s PIN code.She remembers that her PIN code had 4 digits, all the digits were distinctand in decreasing order, and that the sum of these digits was 24. 
// This C program that prints, on different lines, all the PIN codes which fulfill these constraints. 

int main(int argc, char* argv[]) {

	for (int i = 9; i >= 3; i--)
	{
		for (int j = i - 1; j >= 2; j--)
		{
			for (int k = j - 1; k >= 1; k--)
			{
				for (int l = k - 1; l >= 0; l--)
				{
					if (i + j + k + l == 24)
					{
						int pin = 1000 * i + 100 * j + 10 * k + l;
						printf("%d", pin);
						printf("\n");
					}
				}
			}
		}

	}
}

