/*  File               :   PioneerAM.h
*   Project            :   SENG1385 OOP - Assignment 6
*   Programmer         :   Kushaldeep Singh
*   First version      :   March 29, 2022
*   Description        :   This is the .h file where the definition and the code of the class PioneerAM exists .
							The class has method prototypes and code related to the class.*/
#include "PioneerCarRadio.h"




class PioneerAM : public PioneerCarRadio
{
public:
	PioneerAM(bool onOrOff);								 // Constructor that instantiates the object PioneerAM inherited from PioneerCarRadio class.
	virtual ~PioneerAM();									// destructor to destroy the objects of PioneerAM

	void ShowCurrentSettings(void);							// The function is to display the menu options or the user interface to the user according to PioneerAM.
	void ToggleFrequency(void);								// Togglefrequency method to keep frency type for AM band in the classes PioneerAm and PioneerWorld.
};



/*	Name	:   PioneerAM()
	Purpose :   The PioneerAM() constructor is used to instantiate the PioneerAM object.
	Inputs	:	bool onOrOff : PioneerCarRadio(bool)		true or false depicting radio on or off and after : PioneerCarRadio object instantiation.
	Outputs	:	object instantiation
	Returns	:	NONE*/
PioneerAM::PioneerAM(bool onOrOff) : PioneerCarRadio(onOrOff)
{
	SetName(kNames[SUCCESS]);								// setting the name data member of AmFmradio to PioneerAM.
}



/*	Name	:   ~PioneerAM()
	Purpose :   The PioneerAM() Destructor is used to Destroy the PioneerAM object.
	Inputs	:	NONE
	Outputs	:	PioneerAM is destroyed message displayed to user indicating the object is destroyed.
	Returns	:	NONE*/
PioneerAM::~PioneerAM()
{
	// No code required in the destructor.
}



/*	Name	:   ToggleFrequency()
	Purpose :   The ToggleFrequency() method is used to toggle between stations.
	Inputs	:	None
	Outputs	:	NONE
	Returns	:	None*/
void PioneerAM::ToggleFrequency(void)
{
	//No code required as nothing needs to be done while changing band and the radio should only be displaying AM band.
}



/*	Name	:   ShowCurrentSettings()
	Purpose :   The ShowCurrentSettings() method is used to print out the values of all the data members of the object.
	Inputs	:	None
	Outputs	:	prints out the values of all the data members of the object for user if the radio is on.
	Returns	:	None*/
void PioneerAM::ShowCurrentSettings(void)
{
	bool		on = false;
	Freqs		newFreq[SIZE] = { NOTHING };

	on = IsRadioOn();										// Check to see if the radio is on and print the user interface for the user.
	if (on)
	{
		memcpy(&newFreq, GetFreq(), sizeof(newFreq));
		//User Interface Menu for user to pick an option from to interact with PioneerCarRadio.
		printf("Pioneer XS440-AM\n");
		printf("Radio is on\n");
		printf("Volume: %d\n", GetVolume());
		printf("Current Station:%6d %s\n", (int)GetCurrentStation(), GetFrequency());
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
	}
	else
	{
		// User Interface for user if radio is off.
		printf("Pioneer XS440-AM\n");
		printf("Radio is off\n");
	}
}