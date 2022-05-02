/*  File               :   PioneerCarRadio.cpp
*   Project            :   SENG1385 OOP - Assignment 6
*   Programmer         :   Kushaldeep Singh
*   First version      :   March 29, 2022
*   Description        :   This is the .cpp file where all the code related to PioneerCarRadio exists.
							The class has method prototypes to show current setting of the radio and to Handle the user input.*/
#include "PioneerCarRadio.h"



/*	Name	:   PioneerCarRadio()
	Purpose :   The PioneerCarRadio() constructor is used to instantiate the PioneerCarRadio object.
	Inputs	:	bool onOrOff : AmFmRadio(bool)		true or false depicting radio on or off and after : AmFmRadio object instantiation.
	Outputs	:	object instantiation						
	Returns	:	NONE*/
PioneerCarRadio::PioneerCarRadio(bool onOrOff) : AmFmRadio(onOrOff)
{
	SetName(kNames[NOTHING]);								// setting the name data member of AmFmradio to PioneerCarRadio.
}



/*	Name	:   ~PioneerCarRadio()
	Purpose :   The PioneerCarRadio() Destructor is used to Destroy the PioneerCarRadio object.
	Inputs	:	NONE
	Outputs	:	PioneerCarRadio is destroyed message displayed to user indicating the object is destroyed.
	Returns	:	NONE*/
PioneerCarRadio::~PioneerCarRadio()
{
	// No code required in the destructor.
}



/*	Name	:   ShowCurrentSettings()
	Purpose :   The ShowCurrentSettings() method is used to print out the values of all the data members of the object.
	Inputs	:	None
	Outputs	:	prints out the values of all the data members of the object for user if the radio is on.
	Returns	:	None*/
void PioneerCarRadio::ShowCurrentSettings(void)
{
	bool		on = false;
	Freqs		newFreq[SIZE] = { NOTHING };

	on = IsRadioOn();										// Check to see if the radio is on and print the user interface for the user.
	if (on)
	{
		memcpy(&newFreq, GetFreq(), sizeof(newFreq));
		//User Interface Menu for user to pick an option from to interact with PioneerCarRadio.
		printf("Pioneer XS440\n");
		printf("Radio is on\n");
		printf("Volume: %d\n", GetVolume());
		if (strcmp(GetFrequency(), "AM") == NOTHING)
		{
			printf("Current Station:%6d %s\n",(int) GetCurrentStation(), GetFrequency());
		}
		else
		{
			printf("Current Station:%6.1f %s\n", GetCurrentStation(), GetFrequency());
		}
		printf("AM Buttons:\n");
		for (int i = NOTHING; i < SIZE; ++i)
		{
			//prints the values of all the AM buttons.
			if (i == SIZE - SUCCESS)
			{
				printf("%d:%6d\n", i + SUCCESS, newFreq[i].AMFreq);
				break;
			}
			printf("%d:%6d, ", i + SUCCESS, newFreq[i].AMFreq);

		}
		printf("FM Buttons:\n");
		// The following lines of code prints out the button values stored in the data members for FM buttons.
		for (int j = NOTHING; j < SIZE; ++j)
		{
			if (j == SIZE - SUCCESS)
			{
				printf("%d:%6.1f\n", j + SUCCESS, newFreq[j].FMFreq);
				break;
			}
			//prints the values of all the FM buttons.
			printf("%d:%6.1f, ", j + SUCCESS, newFreq[j].FMFreq);
		}
	}
	else
	{
		// User Interface for user if radio is off.
		printf("Pioneer XS440\n");
		printf("Radio is off\n");
	}
}


/*	Name	:   HandleKey()
	Purpose :   The HandleKey() method is used to handle the user input and to call the pertinent fucntion to process the user input.
	Inputs	:	None
	Outputs	:	prints out the values of all the data members of the object for user.
	Returns	:	None*/
bool PioneerCarRadio::HandleKey(void)
{
	//initializations of variables
	int			button_num = NOTHING;									
	char		shiftButtons[SIZE] = { '!', '@', '#', '$', '%' };		// Char array to find and process the shift+buttons to set that button with the current value.
	char		buf[BUFF_LEN] = { NOTHING };
	char		key = NOTHING;
	bool		on = false;
	
	do
	{
		ShowCurrentSettings();											// call to the fucntion ShowCurrentSettings to display User interfface to user to choose from.

		on = IsRadioOn();												// Check to see if radio is on or off and pass the bool value to on.
		key = getch();													// getting the user input from keyboard.
		if (on)															// checks to see if radio is on and only execute the following line sof code if radio is on.
		{
			for (int i = NOTHING; i < SIZE; i++)
			{
				if (shiftButtons[i] == key)
				{
					SetButton(i);										// Sets the current station frequency to the selected button number.
					break;
				}
			}
			button_num = atoi(&key);
			if ((button_num > NOTHING) && (button_num <= SIZE))
			{
				SelectCurrentStation(button_num - SUCCESS);				// sets the button number's frequency to the current station
			}
		}
		//Following lines of code interprets the user input for the menu and calls various methods pertinent to the request.
		switch (key)
		{
		case 'o':
			PowerToggle();									// turns radio on or off
			break;
		case '+':
			if (on)
			{
				SetVolume(GetVolume() + SUCCESS);				// sets volume to the valid requested input and increase the volume by 1.	
			}
			break;
		case '_':
			if (on)
			{
				SetVolume(GetVolume() - SUCCESS);				// sets volume to the valid requested input and decrease the volume by 1
			}				
			break;
		case '=':
			if (on)
			{
				ScanUp();										// changes the frequency one step up.
			}
			break;
		case '-':
			if (on)
			{
				ScanDown();										//Changes frequency to one step down.
			}
			break;
		case 'b':
			if (on)
			{
				ToggleFrequency();								// sets volume to the valid requested input
			}
			break;
		case 'x':
			break;												//quits the program.

		}
		system("CLS");											// Clears the screen

	} while (key != 'x');										// loop until the user enters 'x'

	return on;
}