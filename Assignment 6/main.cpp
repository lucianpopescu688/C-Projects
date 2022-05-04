#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArrayTest.h"
#include "FilteringCriteria.h"
#include "Offer.h"
#include "DynamicArray.h"
#include "MyOutOfBoundException.h"
#include "FilteringCriteriaAnd.h"
#include "FilteringCriteriaOr.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

void printResults(DynamicArray<Offer> arr)
{
	if (arr.getLength() == 0)
		cout << "No results found" << "\n";
	else
		cout << arr << "\n";
}

void mainMenu() 
{
	cout << "Please select your option:" << endl;
	cout << "A|a	add an offer" << endl;
	cout << "S|s	show all ofers" << endl;
	cout << "P|p	filter offers by price" << endl;
	cout << "T|t	filter offers by type" << endl;
	cout << "D|d	filter offers by departure location" << endl;
	cout << "B|b	filter offers by type and price" << endl;
	cout << "O|o	filter offers by departure location and price" << endl;
	cout << "C|c	filter offers by departure location and type " << endl;
	cout << "W|w	filter offers by two departure locations" << endl;
	cout << "G|g	get an offer by index" << endl;
	cout << "L|l	delete last plane from the list" << endl;
	cout << "R|r	delete the plane at a certain position from the list" << endl;
	cout << "M|m	display the main menu" << endl;
	cout << "Q|q	quit" << endl;
	
}

void displayMenu()
{
	char choice;
	Offer new_offer;
	DynamicArray<Offer> arr, arr_copied;
	float filter_price;
	int type_filter , index_offer = 0;
	string Departure;
	mainMenu();
	arr.append(Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	arr.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	do
	{
		cout << "Your option is: ";
		cin >> choice;
		cout << "\n";
		
		switch (choice)
		{
			case 'A':
			case 'a':
			{
				new_offer.getdata();
				arr.append(Offer(new_offer.getID(), new_offer.getDeplocation(), new_offer.getDeslocation(), new_offer.getStartDate(), new_offer.getEndDate(), new_offer.getType(), new_offer.getPrice()));
				break;
			}

			case 'S':
			case 's':
			{
				if(arr.getLength() == 0)
					cout << "There are no airplanes / flights registered in the system." << endl;
				else
					cout << arr << "\n";
				break;
			}
			
			case 'P':
			case 'p':
			{
				cout << "Please enter the price with which the list will be filtered: ";
				cin >> filter_price;
				arr_copied = arr;
				FilterByPrice fp = FilterByPrice(filter_price);
				printResults(fp.filter(arr_copied));
				break;
			}
			
			case 'T':
			case 't':
			{
				cout << "Enter the Offer type number: 0-circuit, 1-city_break, 2-cruise, 3-all_inclusive: ";
				cin >> type_filter;
				arr_copied = arr;
				switch (type_filter)
				{
				case 0:
				{
					FilterByType ft = FilterByType(circuit);
					printResults(ft.filter(arr_copied));
					break;
				}

				case 1:
				{
					FilterByType ft = FilterByType(city_break);
					printResults(ft.filter(arr_copied));
					break;
				}

				case 2:
				{
					FilterByType ft = FilterByType(cruise);
					printResults(ft.filter(arr_copied));
					break;
				}

				case 3:
				{
					FilterByType ft = FilterByType(all_inclusive);
					printResults(ft.filter(arr_copied));
					break;
				}
				}
				break;
			}

			case 'D':
			case 'd':
			{
				cout << "Please enter the departure location with which the list will be filtered: ";
				cin >> Departure;
				arr_copied = arr;
				FilterByDeparture fd = FilterByDeparture(Departure);
				printResults(fd.filter(arr_copied));
				break;
			}
			
			case 'B':
			case 'b':
			{
				cout << "Please enter the price with which the list will be filtered: ";
				cin >> filter_price;
				
				cout << "Enter the Offer type number: 0-circuit, 1-city_break, 2-cruise, 3-all_inclusive: ";
				cin >> type_filter;
				cout << "\n";
				
				arr_copied = arr;
				FilterByPrice fp = FilterByPrice(filter_price);
				arr_copied = fp.filter(arr_copied);
				switch (type_filter)
				{
				case 0:
				{
					FilterByType ft = FilterByType(circuit);
					printResults(ft.filter(arr_copied));
					break;
				}

				case 1:
				{
					FilterByType ft = FilterByType(city_break);
					printResults(ft.filter(arr_copied));
					break;
				}

				case 2:
				{
					FilterByType ft = FilterByType(cruise);
					printResults(ft.filter(arr_copied));
					break;
				}
				
				case 3:
				{
					FilterByType ft = FilterByType(all_inclusive);
					printResults(ft.filter(arr_copied));
					break;
				}					
				}
				break;
			}
			
			case 'O':
			case 'o':
			{
				cout << "Please enter the departure location with which the list will be filtered: ";
				cin >> Departure;
				cout << "Please enter the price with which the list will be filtered: ";
				cin >> filter_price;
				arr_copied = arr;
				arr_copied = FilterByDepartureAndPrice(Departure, filter_price).filter(arr_copied);
				cout << arr_copied;
				break;
			}
			
			case 'C':
			case 'c':
			{
				cout << "Please enter the departure location with which the list will be filtered: ";
				cin >> Departure;
				cout << "Enter the Offer type number: 0-circuit, 1-city_break, 2-cruise, 3-all_inclusive: ";
				cin >> type_filter;
				cout << "\n";
				arr_copied = arr;
				switch (type_filter)
				{
				case 0:
				{
					arr_copied = FilterByDepartureAndType(Departure, circuit).filter(arr_copied);
					cout << arr_copied;
					break;
				}

				case 1:
				{
					arr_copied = FilterByDepartureAndType(Departure, city_break).filter(arr_copied);
					cout << arr_copied;
					break;
				}

				case 2:
				{
					arr_copied = FilterByDepartureAndType(Departure, cruise).filter(arr_copied);
					cout << arr_copied;
					break;
				}

				case 3:
				{
					arr_copied = FilterByDepartureAndType(Departure, all_inclusive).filter(arr_copied);
					cout << arr_copied;
					break;
				}
				}	
				break;
			}

			case 'W':
			case 'w':
			{
				string Departure1, Departure2;
				cout << "Please enter the departure location with which the list will be filtered: ";
				cin >> Departure1;
				cout << "Please enter the departure location with which the list will be filtered: ";
				cin >> Departure2;
				arr_copied = arr;
				arr_copied = FilterByDoubleDeparture(Departure1, Departure2).filter(arr_copied);
				cout << arr_copied;
				break;
			}
			
			case 'G':
			case 'g':
			{
				cout << "Please enter the index of the offer you wish to get(it can be between 0 and " << arr.getLength() - 1 << "): ";
				cin >> index_offer;
				try
				{
					cout << arr.get_at_index(index_offer);
				}
				catch (MyOutOfBoundException* exception)
				{
					cout << exception->what() << "\n";
				}
				break;
			}
			case 'L':
			case 'l':
			{
				try
				{
					arr.popBack();
				}
				catch (MyArrayIsEmpty* exception)
				{
					cout << exception->what() << "\n";
				}
				break;
			}
			
			case 'R':
			case 'r':
			{
				try
				{
					int position;
					cout << "Please enter the position of the plane you want to delete: ";
					cin >> position;
					arr.remove_at_index(position);
				}
				catch (MyOutOfBoundException* exception)
				{
					cout << exception->what() << "\n";
				}
				break;
			}
			
			case 'M':
			case 'm':
			{
				mainMenu();
				break;
			}
			
			case 'Q':
			case 'q':
			{
				cout << "Thank you for using our services! Have a nice day!" << endl;
				break;
			}
		}
	}while (choice != 'Q' && choice != 'q');
}


int main() {

	OfferTest::runAllTests();
	FilteringTest::runAllTests();
	DynamicArrayTest::runAllTests();
	displayMenu();
	_CrtDumpMemoryLeaks();
	return 0;
}