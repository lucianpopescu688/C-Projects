#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

template <typename S>
std::ostream& operator<<(std::ostream& os,
	const std::vector<S>& vector)
{
	// Printing all the elements
	// using <<
	for (auto element : vector) {
		os << element << " ";
	}
	return os;
}

int cinChoice()
{
	int choice;
	std::cout << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	return choice;
}

bool isPositive(int x) {
	return x > 0;
}

bool isPerfectSquare(int x) {
	int root = sqrt(x);
	return root * root == x;
}

void countNumbersPositives(std::vector<double> vect)
{
	int countPositives = std::count_if(vect.begin(), vect.end(), isPositive);
	if(countPositives == vect.size())
		std::cout << "All numbers are positive" << std::endl;
	else
		std::cout << "There are some negatives numbers in vector" << std::endl;
}

void firstIfIsPerfectSquare(std::vector<int> vect)
{
	if(isPerfectSquare(vect[0]))
		std::cout << "The first element " << vect[0] << " is a perfect square" << std::endl;
	else
		std::cout << "The first element " << vect[0] << " is not a perfect square" << std::endl;
}

void countElementsWithSpecificLengthHigher(std::vector<std::string> vect, std::vector<std::string>& result)
{
	int specificLength;
	std::cout << "The minimum length a word must have is: ";
	std::cin >> specificLength;
	std::cout << std::endl;	
	
	result.clear();
	int count = std::count_if(vect.begin(), vect.end(), [specificLength](std::string x) {return x.length() >= specificLength; });
	for(int i = 0 ; i < vect.size(); i++)
	{
		if(vect[i].length() >= specificLength)
			result.push_back(vect[i]);
	}
	if(count == 0)
		std::cout << "There are no words with length higher than " << specificLength << std::endl;
	else
		std::cout << "There are " << count << " words with length higher than " << specificLength << std::endl;
}

void sortByLastDigit(std::vector<int> vect)
{
	std::sort(vect.begin(), vect.end(), [](int x, int y) {return x % 10 < y % 10; });
	std::cout << "The vector sorted by last digit is: " << vect << std::endl;
}

void binarySearchLetters(std::vector<char> vect)
{
	sort(vect.begin(), vect.end());
	char letter;
	int middle, left = 0, right = vect.size() - 1;
	
	std::cout << "The letter you want to search is: ";
	std::cin >> letter;
	std::cout << std::endl;
	
	while(left <= right)
	{
		middle = (left + right) / 2;
		if(vect[middle] == letter)
		{
			std::cout << "The letter " << letter << " is at position " << middle << " in the sorted vector" << std::endl;
			return;
		}
		else if(vect[middle] < letter)
			left = middle + 1;
		else
			right = middle - 1;
	}
	
	std::cout << "The letter " << letter << " is not in the vector" << std::endl;
}

void Menu()
{
	std::cout << "1 - Count the number of positive numbers in a vector" << std::endl;
	std::cout << "2 - Check if the first element of a vector is a perfect square" << std::endl;
	std::cout << "3 - Count the number of elements with a specific length higher than a given length" << std::endl;
	std::cout << "4 - Sort a vector by the last digit of each element" << std::endl;
	std::cout << "5 - Binary search for a given letter in a vector" << std::endl;
	std::cout << "0 - Exit" << std::endl;
}

void displayMenu()
{
	int choice = 0;
	std::vector<double> vector_1_1{ 1, 2 , 3, 4, 5 };
	std::vector<double> vector_1_2{ 1, 2 , -3, 4, 5 };
	std::vector<int> vector_2_1{ 4, 4 , 5 };
	std::vector<int> vector_2_2{ 3, 4 , 5 };
	std::vector<std::string> result;
	std::vector<std::string> vector_3{ "Vanilla", "Mint", "Chocolate", "Strawberry", "Pistachio", "Berry" };
	std::vector<int> vector_4{ 1, 2, 3, 11, 21, 22, 32, 4 };
	std::vector<char> vector_5{ 'u', 'v', 'y', 'z', 'd', 't', 'w', 'x', 'a', 'b', 'c', 'k', 'l'};

	Menu();
	do
	{
		choice = cinChoice();
		switch (choice)
		{
		case 1:
			std::cout << "Problem 1 - Check positive numbers " << std::endl;
			std::cout << vector_1_1 << " - ";
			countNumbersPositives(vector_1_1);
			std::cout << vector_1_2 << " - ";
			countNumbersPositives(vector_1_2);
			break;

		case 2:
			std::cout << std::endl << "Problem 2 - Check if first numbers is perfect square " << std::endl;
			std::cout << vector_2_1 << " - ";
			firstIfIsPerfectSquare(vector_2_1);
			std::cout << vector_2_2 << " - ";
			firstIfIsPerfectSquare(vector_2_2);
			break;

		case 3:
			std::cout << std::endl << "Problem 3 - Count words with specific length higher " << std::endl;
			countElementsWithSpecificLengthHigher(vector_3, result);
			
			if(result.size() != 0)
				std::cout << "The result is : " << result << std::endl;
		
			std::cout << std::endl;
			std::cout << "The base vector is : " << vector_3 << std::endl;
			break;

		case 4:
			std::cout << std::endl << "Problem 4 - Sort by last digit " << std::endl;
			sortByLastDigit(vector_4);
			std::cout << "The base vector is : " << vector_4 << std::endl;
			break;
		
		case 5:
			std::cout << std::endl << "Problem 5 - Binary search for a letter " << std::endl;
			binarySearchLetters(vector_5);
			break;
		
		case 0:
			std::cout << "Thank you for using the program. The application will now stop." << std::endl;
			break;
		}
	}while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}

int main()
{
	displayMenu();
}