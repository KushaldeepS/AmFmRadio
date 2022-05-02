/*  File               :   PioneerCarRadio.h
*   Project            :   SENG1385 OOP - Assignment 6
*   Programmer         :   Kushaldeep Singh
*   First version      :   March 29, 2022
*   Description        :   This is the .h file where the definition of the class PioneerCarRadio exists .
							The class has method to show current setting of the radio and a fucntion to Handle the user input.*/
#include "AmFmRadio.h"
#include <conio.h>



class PioneerCarRadio : public AmFmRadio
{
public:
	PioneerCarRadio(bool onOrOff);								 // Constructor that instantiates the object PioneerCar Radio inherited from AmFmRadio class.
	virtual ~PioneerCarRadio();									 // destructor to destroy the objects of PioneerCarRadio
	
	void ShowCurrentSettings(void);								 // The function is to display the menu options or the user interface to the user.
	
	bool HandleKey(void);										 // method to handle validation and setting values of user input from the menu.
};