# C-Projects
College assignments and projects in C/C++.



The following four problems are more introductory to get used to the C programming language:

Problem 1 - It's a simple program that reads the user's year of birth and displays the name, age and year of birth;

Problem 2 - The program displays each 4-digit number, whose digits are distinct and in descending order, and their sum is 24;

Problem 3 - The program calculates the date on which Easter falls in that year;

Problem 4 - The program decodes a text that has been encoded with Caesar's cipher, knowing the shift by which the characters have been changed;


CeasarCipherBreaker - The program decodes a text encoded with Caesar's cipher, using only the frequency of letters in the language and the Chi-Squared distance. More information can be found at running the program using the application menu;


Assignment 2:

  Problem 1 - The program reads a list of positive/negative numbers and displays the value of the triplet with the maximum product and the elements that form the triplet;
  
  Problem 2 - The program takes a command line argument path to a file, which contains a word from a given language on each line. The program loads the words into an array, calculates the frequency of each letter in the file and displays the corresponding letter and frequency;
 
 
Assignment 3 - The program defines a structure that represents a complex number in C and various functions for:

            - getters and setters;
            
            - operations between two complex numbers;
            
            - displaying a complex number;
            
            - calculating the magnitude and phase of a complex number;
            
            - representing a complex number in polar coordinates; 
            
In the Dynamic_array.h/.cpp files is created a dynamic array of complex numbers and populated with the data stores in text file(in1.txt, in2.txt, in3.txt, in4.txt, in5.txt). Using the qsort function, the program sorts and displays the array of numbers in ascending order, based on:

  - the real part of the number;

  - the imaginary part of the number;

  - the magnitude of the number.

and the function isSorted that takes as input the array , it's size and a comparison function and returns whether the array is sorted or not.


Assignment 4

  Problem 1: The program defines a class that represent a complex number. The class contains all methods implemented in the previous assignment. In addition , class contains:
  
  - default constructor;
  
  - constructor that initializes a complex number with the real and imaginary parts;

  - overloads for the equal to and not equal to operators;

  - overload for the stream insertion operator (>>) and stream extraction (<<) operators;

  - overloads for the arithmetic operators: addition (+), subtraction (-) and multiplication(*
  
  Problem 2: BigInteger class and Fibonacci function;


Assignment 5 
- A simple  C++ application for managing travel agency offers. The main model class is the Offer class that has the following fields: an alphanumeric id, a departure location and a destination location (std::string), a price, and a start date and an end date and a type (circuit, city break, cruise, all-inclusive) and in the main function is created a dynamic array of Offers , using the DynamicArray from the previous assignments;
              
- A class hierarchy is designed to filter the existing offers based on some filtering criteria. The base class will be called FilteringCriteria and will have a single method "DynamicArray filter(DynamicArray& data)" that will return the same array as the one passed as parameter;
              
- The Filtering class has several subclasses that have modified the original method as follows: 
  
  - The class FilteringPrice has as a field member a floating point "price" and the filter function returns all those offers that have a price lower than "price";

  - The class FilteringType has as a field member an enum value "type" and the filter function returns all those offers that have the type equal to "type";

  - The class FilteringCriteriaTypeAndPrice has as field members a FilteringPrice and a FilteringType object and the filter function returns all those offers that comply with both conditions imposed by its fields;

- For each implemented class, a new class is created, which will contain the tests and a menu-based application;


Assignment 6 - has two parts and is divided as follows:
  - The first part is the previous assignment but with the following changes:
    
    - The "DynamicArray" is a generic container;
    
    - The class FilteringCriteria becomes an interface;

    - The class FilteringCriteriaTypeAndPrice becomes more generic and is renamed to FilteringCriteriaAnd and modified such that can filter by two criteria;

    - A class FilteringCriteriaDeparture is created to filter offers by the departure city;

    - A class FilteringCriteriaOr is created to combine filtering citerias using the "or" logical operator;

     - Errors are thrown in the following cases:
     
        a.	When you want to remove an element from the array, but the array is empty;
        
        b.	When you want to get the element from a position in the array, but the position is out of the bounds of the array;
        
        c.	When you want to remove the element from a position in the array, but the position is out of the bounds of the array;
        

   - The second part is the Problem 2 in which the following problems are solved and accessed with a menu-based application:
    
        a.	Given a vector of doubles, check if all the numbers are positive;
       
        b.	Given an array of integers, print the first number that is a perfect square;
        
        c.	Given a vector of strings, count the number of elements that have a length larger than a value n specified by the user;
        
        d.	Given a vector of integers, sort them by the last digit in the number;
        
        e.	Given an array of chars, sort it and then use binary search to determine if a given char is present in the array;
