#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void frequency(char* words[], float frequency_table[], long long number_words, long long number_letters)
{
	for (int i = 0; i < number_words; i++)
	{
		for (long long index = 0; index < strlen(words[i]); index++)
		{
			frequency_table[words[i][index] - 97]++;
		}
	}

	for (int index = 0; index < 26; index += 1)
	{
		frequency_table[index] = (frequency_table[index] / number_letters) * 100;
	}

}
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: pb2 <inputfile>\nApplication will now stop");
		return 0;
	}

	// Variables
	_Post_ _Notnull_ char** words;
	int n = 350000;
	long long number_words = 0;
	long long number_letters = 0;
	char word[110];
	float frequency_table[26];

	// allocate the array of words
	words = (char**)malloc(sizeof(char*) * n);

	//fscanf -> read froma file
	FILE* fp = fopen(argv[1], "r"); // r - reading from a file

	//check error
	if (fp == NULL)
	{
		printf("Failed to open file %s. Application will now stop", argv[1]);
		return 0;
	}

	//Reading , create an array and find the number of words and letters
	while (!feof(fp))
	{
		fscanf(fp, "%s", word);
		words[number_words] = malloc(sizeof(char) * (strlen(word) + 1));
		if (words[number_words] != '\0')
		{
			strcpy(words[number_words], word);
			number_letters += strlen(word);
			fscanf("%c ", words[number_words]);
			number_words += 1;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		frequency_table[i] = 0;
	}

	frequency(words, frequency_table, number_words, number_letters);
	for (int i = 0; i < 26; i++)
	{
		char letter = i + 97;
		printf("%c %.2f%%\n", letter, frequency_table[i]);
	}
	return 0;
}