/*  File               :   PioneerWorld.h
*   Project            :   SENG1385 OOP - Assignment 6
*   Programmer         :   Kushaldeep Singh
*   First version      :   March 29, 2022
*   Description        :   This is the .h file where the definition and the code of the class PioneerWorld exists .
							The class has methods constants related to the class.*/
#include "PioneerAM.h"

#define WORLD_MAX_AM 1602
#define WORLD_MIN_AM 531
#define WORLD_NEXTCHANNEL 9
#define FAILURE -1


class PioneerWorld : public PioneerAM
{
private:
	int current_station_world;								 // Data member to hold current station value for AM band
	Freqs newFreq[SIZE];									 // Data member to hold the values of buttons.

	//bogus data members
	Freqs myNewFreq[SIZE];									 // Bogus data member to store the values of original data member to give back to user.

public:
	PioneerWorld(bool onOrOff);								 // Constructor that instantiates the object PioneerAM  inherited fromPioneerCarRadio class.
	virtual ~PioneerWorld();								 // destructor to destroy the objects of PioneerWorld

	void ShowCurrentSettings(void);							// The function is to display the menu options or the user interface to the user according to PioneerAM.

	void ScanUp(void);										//changes frequency up in increments of 9 for AM

	void ScanDown(void);									//changes frequency down in decrements of 9 for AM

	int GetWorldCurrentStation(void);						// gives the user the value of the current station of the World Current Station data member.

	bool SetWorldCurrentStation(int newStation);			// sets the world current station of the radio.

	int SelectCurrentStation(int button_num);				// Selects the value of the button passed in as param as current station.

	Freqs* GetNewFreq(void);								// Accessor to give back values of buttons to user of frequencies.

	int SetButton(int button_num);							// Sets the current station of world Radio to the button number passed in as parameter.
};





/*	Name	:   PioneerWorld()
	Purpose :   The PioneerWorld() constructor is used to instantiate the PioneerWorld object.
	Inputs	:	bool onOrOff : PioneerAM(bool)		true or false depicting radio on or off and after : PioneerAM object instantiation.
	Outputs	:	object instantiation
	Returns	:	NONE*/
PioneerWorld::PioneerWorld(bool onOrOff) : PioneerAM(onOrOff)
{
	current_station_world = WORLD_MIN_AM;				// Data member initialization with minimum value allowed of 531.
	for (int i = NOTHING; i < SIZE; ++i)
	{
		newFreq[i].AMFreq = WORLD_MIN_AM;				// Data member intialization of struct field for FM Radio.
		newFreq[i].FMFreq = NOTHING;					// Data menber initalization of struct field FM which is not being used in the class though.
	}

	// Bogus data member initailization.
	for (int i = NOTHING; i < SIZE; ++i)
	{
		myNewFreq[i].AMFreq = WORLD_MIN_AM;				// BogusData member intialization of struct field for FM Radio.
		myNewFreq[i].FMFreq = NOTHING;					// Bogus data menber initalization of struct field FM which is not being used in the class though.
	}

	SetName(kNames[ANOTHERNOTHING]);					// setting the name data memebr of AmFmradio to PioneerWorld.
	
}


/*	Name	:   ~PioneerWorld()
	Purpose :   The PioneerWorld() Destructor is used to Destroy the PioneerWorld object.
	Inputs	:	NONE
	Outputs	:	PioneerWorld is destroyed message displayed to user indicating the object is destroyed.
	Returns	:	NONE*/
PioneerWorld::~PioneerWorld()
{
	// No code required in the destructor.
}



/*	Name	:   ShowCurrentSettings()
	Purpose :   The ShowCurrentSettings() method is used to print out the values of all the data members of the object.
	Inputs	:	None
	Outputs	:	prints out the values of all the data members of the object for user if the radio is on.
	Returns	:	None*/
void PioneerWorld::ShowCurrentSettings(void)
{
	bool		on = false;
	Freqs		newFreq[SIZE] = { NOTHING };

	on = IsRadioOn();										//Check to see if the radio is on and print the user interface for the user.
	if (on)
	{
		memcpy(&newFreq, GetNewFreq(), sizeof(newFreq));
		//User Interface Menu for user to pick an option from to interact with PioneerCarRadio.
		printf("Pioneer XS440-WRLD\n");
		printf("Radio is on\n");
		printf("Volume: %d\n", GetVolume());
		printf("Current Station:%6d %s\n", (int)GetWorldCurrentStation(), GetFrequency());
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
		printf("Pioneer XS440-WRLD\n");
		printf("Radio is off\n");
	}
}



/*	Name	:   ScanUp()
	Purpose :   The ScanUp() method is used to set the data member current station value and wraps up .
	Inputs	:	NONE
	Outputs	:	Changes the current_station data member value and prints its current value if displayOutput is true.
	Returns	:	Void*/
void PioneerWorld::ScanUp(void)
{
	if (strcmp("AM", GetFrequency()) == NOTHING)
	{
		//if current_station is 1602, the current_station becomes 531
		// the next channel for AM change jumps the value by 9.
		if (GetWorldCurrentStation() == WORLD_MAX_AM)
		{
			SetWorldCurrentStation(WORLD_MIN_AM);			
		}
		else
		{
			SetWorldCurrentStation(GetWorldCurrentStation() + WORLD_NEXTCHANNEL);
		}
	}
	if (GetDisplayOutput() == true)
	{
		printf("\nCurrent station: %d %s\n",(int)GetWorldCurrentStation(), GetFrequency());         // only prints displayOutput is true.
	}
}



/*	Name	:	ScanDown()
	Purpose :	The ScanDown() method is used to set the data member current station value and wraps up .
	Inputs	:	NONE
	Outputs	:	Changes the current_station data member value and prints its current value if displayOutput is true.
	Returns	:	Void*/
void PioneerWorld::ScanDown(void)
{
	if (strcmp("AM", GetFrequency()) == NOTHING)
	{
		//if current_station is 531, the current_station becomes 1602
		// the next channel for AM change jumps the value by 9.
		if (GetWorldCurrentStation() == WORLD_MIN_AM)
		{
			SetWorldCurrentStation(WORLD_MAX_AM);
		}
		else
		{
			SetWorldCurrentStation(GetWorldCurrentStation() - WORLD_NEXTCHANNEL);
		}
	}
	
	if (GetDisplayOutput() == true)
	{
		printf("\nCurrent station: %d %s\n", (int)GetWorldCurrentStation(), GetFrequency());      // only prints if displayOutput is true.
	}
}



/*	Name	:   SetWorldCurrentStation()
	Purpose :   The SetWorldCurrentStation() method is used to set the current station of the radio.
	Inputs	:	int newStation         // holds the value for the new station frequency to be set as world current station.
	Outputs	:	sets current station world data member with the new values after validation.
	Returns	:	true if successfull, false for Failure*/
bool PioneerWorld::SetWorldCurrentStation(int newStation)
{
	// assign the frequency passes in as current station if valid as per radio frequencies specified in the requirements.
	if (strcmp(GetFrequency(), "AM") == NOTHING)
	{
		if (newStation <= WORLD_MAX_AM && newStation >= WORLD_MIN_AM)
		{
			current_station_world = newStation;         // assigns the objects current station the value passed in as parameter.
			return true;
		}
		
	}
	return false;
}



/*	Name	:   GetWorldCurrentStation()
	Purpose :   The GetWorldCurrentStation() method is used to set the current station for world of the radio.
	Inputs	:	NONE
	Outputs	:	gives value of current station world data member with the new values after validation.
	Returns	:	value of the current_station_world data member*/
int PioneerWorld::GetWorldCurrentStation(void)
{
	return current_station_world;
}



/*	Name	:   SelectCurrentStation()
	Purpose :   The SelectCurrentStation() method is used to set the current_station data member.
	Inputs	:	int button_num           Freqs array's element number
	Outputs	:	sets current_station with the new values after validation
	Returns	:	1 if successfull, 0 otherwise*/
int PioneerWorld::SelectCurrentStation(int button_num)
{
	if ((button_num >= NOTHING) && (button_num < SIZE))
	{
		// checks the frequency band and changes the asked station to current station.
		if (strcmp("AM", GetFrequency()) == NOTHING)
		{
			Freqs world_Freq[SIZE] = { NOTHING };
			memcpy(&world_Freq, GetNewFreq(), sizeof(world_Freq));
			current_station_world = world_Freq[button_num].AMFreq;
		}

		return SUCCESS;
	}

	return NOTHING;
}



/*	Name	:   SetButton()
	Purpose :   The SetButton() method is used to set the frequency of the station.
	Inputs	:	int button_num           Freqs array's element number
	Outputs	:	sets Freq struct fields with the new values after validation
	Returns	:	1 if successfull, 0 otherwise*/
int PioneerWorld::SetButton(int button_num)
{
	if ((button_num >= NOTHING) && (button_num < SIZE))
	{
		// checks to see the frequency band and assigns the frequency to the button.
		if (strcmp("AM", GetFrequency()) == NOTHING)
		{	
			newFreq[button_num].AMFreq = current_station_world;
		}

		return SUCCESS;
	}

	return NOTHING;
}



/*	Name	:	GetNewFreq()
	Purpose :   The GetNewFreq() method is used to give the struct Freqs newFreq fields values to myNewFreq to give back to user.
	Input	:	None
	Outputs	:	myNewFreq[i].AMFreq = newFreq[i].AMFreq;
				myNewFreq[i].FMFreq = newFreq[i].FMFreq;          assigning values of newFreq data member to myNewFreq bogus data member.
	Returns	:	current values of myNewFreq data member of the object*/
Freqs* PioneerWorld::GetNewFreq(void)
{
	//copies the struct Freqs newFreq array fields values to myNewFreq fields values to return to user.
	for (int i = 0; i < SIZE; ++i)
	{
		myNewFreq[i].AMFreq = newFreq[i].AMFreq;
		myNewFreq[i].FMFreq = newFreq[i].FMFreq;
	}
	return myNewFreq;
}