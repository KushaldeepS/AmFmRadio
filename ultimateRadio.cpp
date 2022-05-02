/*  File               :   ultimateRadio.cpp
*   Project            :   SENG1385 OOP - Assignment 6
*   Programmer         :   Kushaldeep Singh
*   First version      :   March 29, 2022
*   Description        :   This is the .cpp file where all of the code related to the test harness or main for ultimateRadio program exists
							where all objects get instantiated to run particular type of radio and get destroyed displaying the only the message related to the type of the object.*/

#include "PioneerWorld.h"
#include <new>


//constants to handle key presses.
const char kKey[SIZE] = { 'c', 'a', 'w', 'x'};
#define QUIT 3

//prototypes
PioneerCarRadio* createRadio(string str);



int main(int argc,char* argv[])
{
	PioneerCarRadio* pRadio = NULL;
	// Exception handling to handle exceptions thrown from the createRadio function execution while instantiation of a specific object type.
	try
	{
		pRadio = createRadio(argv[SUCCESS]);
	}
	catch (exception& e)
	{
		printf ("%s Invalid input. The PioneerCarRadio object could not be instantiated, exiting program...\n", e.what());
		return FAILURE;
	}
	pRadio->HandleKey();								// Call the method HandleKey to take user input and process it until the user enters "x".
	pRadio->SetDisplayOutput(true);						// turn the print statements on for the object to display message on destruction.
	delete pRadio;
	char keyStroke =  NOTHING;
	do
	{
		keyStroke = getch();							// another valid input from user in loop to instantiate another type of radio.
		for (int i = NOTHING; i < SIZE; i++)
		{
			if (keyStroke == kKey[i] && keyStroke != kKey[QUIT])
			{
				// Exception handling to handle exceptions thrown from the createRadio function execution while instantiation of a specific object type.
				try
				{
					pRadio = createRadio(kInput[i]);
				}
				catch (exception& e)
				{
					printf("%s Invalid input. The PioneerCarRadio object could not be instantiated, exiting program...\n", e.what());
					return FAILURE;
				}
				pRadio->HandleKey();					// Displays and calls various methods and overridden method to show menu option and fucntion of the radio to user .
				pRadio->SetDisplayOutput(true);			// turn the print statements on for the object to display message on destruction.
				delete pRadio;
				break;
			}
		}
	} while (keyStroke != kKey[QUIT]);
	
	return NOTHING;
}



/*	Name	:   createRadio()
	Purpose :   The createRadio() method is used to Instantiate a new radio object.
	Inputs	:	string str			// holds the value for input type to compare value against type of radio to be instantiated.
	Outputs	:	Instantiate a particular object type.
	Returns	:	a pointer to PioneerCarRadio*/
PioneerCarRadio* createRadio(string str)
{
	if (str == kInput[NOTHING])
	{
		PioneerCarRadio* car = NULL;
		// Exception handling to handle exceptions thrown while allocating memory for instantiation of object type of PioneerCarradio.
		try
		{
			 car = new PioneerCarRadio(false);							// Instantiate an object car of PioneerCarRadio type.
		}				
		catch (bad_alloc& e)
		{
			printf("Bad allocation of memory from the new operator. Exiting program...\n");
			exit(FAILURE);
		}
		return car;														// returns a pointer to the address of the newly formed object.
	}
	else if (str == kInput[SUCCESS])
	{
		PioneerAM* am = NULL;
		// Exception handling to handle exceptions thrown while allocating memory for instantiation of object type of PioneerAM.
		try
		{
			am = new PioneerAM(false);									// Instantiate an object am of PioneerAM type.
		}
		catch (bad_alloc& e)
		{
			printf("Bad allocation of memory from the new operator. Exiting program...\n");
			exit(FAILURE);
		}																
		return am;														// return PioneerAM object masked as PioneerCarRadio.
	}
	else if (str == kInput[ANOTHERNOTHING])
	{
		PioneerWorld* world = NULL; 
		// Exception handling to handle exceptions thrown while allocating memory for instantiation of object type of PioneerWorld.
		try
		{
			world = new PioneerWorld(false);							// Instantiate an object am of PioneerWorld type.
		}
		catch (bad_alloc& e)
		{
			printf("Bad allocation of memory from the new operator. Exiting program...\n");
			exit(FAILURE);
		}
		return world;													// return PioneerWorld object masked as PioneerCarRadio.
	}
	else
	{
		throw exception("Yikes!");										// throws an exception back to main if the user input was not valid.
	}
}