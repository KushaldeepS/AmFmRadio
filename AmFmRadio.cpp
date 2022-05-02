/*  File               :   AmFmRadio.cpp
*   Project            :   SENG1385 OOP - Assignment 6
*   Programmer         :   Kushaldeep Singh
*   First version      :   March 29, 2022
*   Description        :   This is the .cpp (source code) file where all of the code related to the class AmFmRadio exists.
							The code contains all the methods, accessors and mutators that are being used in the child classes as well*/

#include "AmFmRadio.h"

using namespace std;



/*	Name	:   AmFmRadio()
	Purpose :   The AmFmRadio() constructor is used to instantiate the AmFmRadio object.
	Inputs	:	bool onOrOff, Freq freq[]	true or false depicting radio on or off, Freq holds frequecies for radio cahnnels.
	Outputs	:	current_station				changes to current channel
				volume						sets the volume data member
				on							turns the radio on or off
				Freq[]						the struct array
				frequency					The value of frequency
	Returns	:	NONE*/
AmFmRadio::AmFmRadio(Freqs newFreq[], bool onOrOff)
{
	for (int i = 0; i < SIZE; ++i)
	{
		Freq[i].AMFreq = MINLIMIT_AM;
		Freq[i].FMFreq = MINLIMIT_FM;
	}
	// initializing data members of the object.
	current_station = MINLIMIT_AM;
	strcpy(frequency, "AM");
	volume = NOTHING;
	on = onOrOff;
	savedFreq.AMFreq = MINLIMIT_AM;
	savedFreq.FMFreq = MINLIMIT_FM;
	savedVol = NOTHING;
	displayOutput = false;
	// initializing bogus data member myFrequency of the object.
	strcpy(myFrequency, "");
	for (int i = 0; i < SIZE; ++i)
	{
		myFreq[i].AMFreq = NOTHING;
		myFreq[i].FMFreq = NOTHING;
	}

	name = kNames[NOTHING];								// Initialization of the data member name to keep track og the object instantiated in main.
}



/*	Name	:   AmFmRadio()
	Purpose :   The AmFmRadio() constructor is used to instantiate the AmFmRadio object.
	Inputs	:	bool onOrOff		  true or false depicting radio on or off
	Outputs	:	current_station       changes to current channel
				volume                sets the volume data member
				on                    turns the radio on or off
				Freq[]                the struct array
				frequency             The value of frequency
	Returns	:	NONE*/
AmFmRadio::AmFmRadio(bool onOrOff)
{
	for (int i = 0; i < SIZE; ++i)
	{
		Freq[i].AMFreq = MINLIMIT_AM;
		Freq[i].FMFreq = MINLIMIT_FM;
	}
	// initializing data members of the object.
	current_station = MINLIMIT_AM;
	strcpy(frequency, "AM");
	volume = NOTHING;
	on = onOrOff;
	savedFreq.AMFreq = MINLIMIT_AM;
	savedFreq.FMFreq = MINLIMIT_FM;
	savedVol = NOTHING;
	displayOutput = false;
	// initializing bogus data members of the object.
	strcpy(myFrequency, "");
	for (int i = 0; i < SIZE; ++i)
	{
		myFreq[i].AMFreq = NOTHING;
		myFreq[i].FMFreq = NOTHING;
	}
	name = kNames[NOTHING];								// Initialization of the data member name to keep track og the object instantiated in main.
}



/*	Name	:   ~AmFmRadio()
	Purpose :   The ~AmFmRadio() Destructor is used to destroy the AmFmRadio object.
	Inputs	:	NONE
	Outputs	:	prints that the object is being destroyed, if displayOutput is true.
	Returns	:	NONE*/
AmFmRadio::~AmFmRadio()
{
	if (GetDisplayOutput() == true)
	{
		printf("\nDestroying %s Radio\n", GetName().c_str());					// displaying only the name of the object destroyed after it was instantiation of its type.
	}
}



/*	Name	:   PowerToggle()
	Purpose :   The PowerToggle() method is used to set the current_station data member's value and turning the radio on.
	Input	:	None
	Outputs	:	current_station is assigned the old saved frequency.
	Returns	:	void*/
void AmFmRadio::PowerToggle(void)
{
	if (on == false)
	{
		on = true;              //  turns the radio on.
		// assign the frequency last used as current station.
		if (strcmp(GetFrequency(), "AM") == NOTHING)
		{
			current_station = savedFreq.AMFreq;
		}
		else
		{
			current_station = savedFreq.FMFreq;
		}
		// call the function SetVolume to save the previously used volume as current volume.
		SetVolume(savedVol);
	}
	else
	{
		// if radio is being turned of save the values of current station and volume settings for later use.
		savedVol = volume;
		SetVolume(NOTHING);
		// assign the frequency currently used as saved station.
		if (strcmp(GetFrequency(), "AM") == NOTHING)
		{
			savedFreq.AMFreq = (int)current_station;
		}
		else
		{
			savedFreq.FMFreq = current_station;
		}
		on = false;									// turns the radio off.
	}
}



/*	Name	:   IsRadioOn()
	Purpose :   The IsRadioOn() method is used to give the on's value to user.
	Input	:	None
	Outputs	:	None
	Returns	:	current value of on data member of the object*/
bool AmFmRadio::IsRadioOn(void)
{
	return on;
}



/*	Name	:   SetDisplayOutput()
	Purpose :   The SetDisplayOutput() method is used to set the displayOutput data member value.
	Input	:	bool value passed in by user to be set for displayOutput.
	Outputs	:	displayOutput assigned the vslue of the parameter passed in after validation
	Returns	:	returns true if the parameter value is assigned to the data member, false otherwise*/
bool AmFmRadio::SetDisplayOutput(bool output)
{
	// check to see if the value in the data member is not same already and assigns the new value if it's different bool value.
	if (GetDisplayOutput() == false && output == true)
	{
		displayOutput = output;								// assigns the value true to the data member.
		return true;
	}
	else if (GetDisplayOutput() == true && output == false)
	{
		displayOutput = output;								//assigns the value false to the data member.
		return true;
	}
	return false;
}



/*	Name	:   GetDisplayOutput()
	Purpose :   The GetDisplayOutput() method is used to give the displayOutput value to user.
	Input	:	None
	Outputs	:	None
	Returns	:	current value of displayOutput data member of the object*/
bool AmFmRadio::GetDisplayOutput(void)
{
	return displayOutput;
}



/*	Name	:	GetVolume()
	Purpose :   The GetVolume() method is used to give the volume value to user.
	Input	:	None
	Outputs	:	None
	Returns	:	current value of volume data member of the object*/
int AmFmRadio::GetVolume(void)
{
	return volume;
}



/*	Name	:	GetFrequency()
	Purpose :   The GetFrequency() method is used to give the frequency value to user.
	Input	:	None
	Outputs	:	copied frequency values to myfrequency data member to give back to user.
	Returns	:	current value of frequency data member of the object*/
char* AmFmRadio::GetFrequency(void)
{
	//copies the frequency values to different unused data member of same data type to return to user.
	memcpy(myFrequency, frequency, sizeof(frequency));

	return myFrequency;
}



/*	Name	:	GetFreq()
	Purpose :   The GetFreq() method is used to give the struct Freqs Freqfields values to myFreq to give back to user.
	Input	:	None
	Outputs	:	myFreq[i].AMFreq = Freq[i].AMFreq
				myFreq[i].FMFreq = Freq[i].FMFreq          assigning values of Freq data member to myFreq bogus data member.
	Returns	:	current values of myFreq data member of the object*/
Freqs* AmFmRadio::GetFreq(void)
{
	//copies the struct Freqs Freq array fields values to myFreq fields values to return to user.
	for (int i = 0; i < SIZE; i++)
	{
		myFreq[i].AMFreq = Freq[i].AMFreq;
		myFreq[i].FMFreq = Freq[i].FMFreq;
	}
	return myFreq;
}



/*	Name	:	GetCurrentStation()
	Purpose :   The GetCurrentStation() method is used to give the Current_Station value to user.
	Input	:	None
	Outputs	:	None
	Returns	:	current value of Current_Station data member of the object*/
double AmFmRadio::GetCurrentStation(void)
{
	return current_station;
}



/*	Name	:   SetCurrentStation()
	Purpose :   The SetCurrentStation() method is used to set the current station of the radio.
	Inputs	:	double newStation         // hoslds the value for the new station frequency to be set as current station.
	Outputs	:	sets current station with the new values after validation.
	Returns	:	true if successfull, false for Failure*/
bool AmFmRadio::SetCurrentStation(double newStation)
{
	// assign the frequency passes in as current station if valid as per radio frequencies specified in the requirements.
	if (strcmp(GetFrequency(), "AM") == NOTHING)
	{
		if (newStation <= MAXLIMIT_AM && newStation >= MINLIMIT_AM && (int)newStation % NEXTCHANNEL_AM == NOTHING)
		{
			current_station = newStation;         // assigns the objects current station the value passes in as parameter.
			return true;
		}
		return false;
	}
	else
	{
		if (newStation <= MAXLIMIT_FM && newStation >= MINLIMIT_FM)
		{
			current_station = newStation;		  // assigns the objects current station the value passes in as parameter.
			return true; 
		}
		return false;
	}
}



/*	Name	:   SetVolume()
	Purpose :   The SetVolume() method is used to set the volume of the radio.
	Inputs	:	None
	Outputs	:	sets Volume with the new values after validation and after getting the values from user for volume
	Returns	:	1 if successfull, 0 for minimum volume or 2 for maximum volume*/
int AmFmRadio::SetVolume(void)
{
	char buf[BUFF_LEN] = "";
	int temp = NOTHING;
	// get the input from the user and pass the input as parameter to check for validation and assigning the value to volume data member.
	printf("\nEnter the volume level (0 - 100). ");
	fgets(buf, sizeof buf, stdin);
	temp = atoi(buf);
	// calles the SetVolume function and passes the temp variable value which is user input for volume to assign to volume data member.

	return SetVolume(temp);
}



/*	Name	:   SetVolume()
	Purpose :   The SetVolume() method is used to set the volume of the radio.
	Inputs	:	int newVolume           Volume level requested by user
	Outputs	:	sets Volume with the new values after validation
	Returns	:	1 if successfull, 0 for minimum volume or 2 for maximum volume*/
int AmFmRadio::SetVolume(int newVolume)
{
	if (IsRadioOn() == true)
	{
		if (newVolume < NOTHING) //if user enters volume less than 0, volume = 0
		{
			volume = NOTHING;
			return NOTHING;
		}
		if (newVolume > MAXVOL) //if user enters volume greater than 100, volume = 100
		{
			volume = MAXVOL;
			return ANOTHERNOTHING;
		}
		volume = newVolume;     // if the value passes in the function is valid assign the value to volume data member.

		return SUCCESS;
	}
	else
	{
		if (GetDisplayOutput() == true)
		{
			printf("Turn the radio on to set volume.\n");
		}
		return NOTHING;
	}
}



/*	Name	:   ToggleFrequency()
	Purpose :   The ToggleFrequency() method is used to toggle between stations.
	Inputs	:	None
	Outputs	:	sets current_station with the values of saved frquencies last used after validation
	Returns	:	None*/
void AmFmRadio::ToggleFrequency(void)
{
	if (strcmp(GetFrequency(), "AM") == NOTHING)
	{
		strcpy(frequency, "FM");
		// save the current station of the user to assign again after user jumps back to this frequency.
		savedFreq.AMFreq = (int) current_station;
		current_station = savedFreq.FMFreq;
		
	}
	else
	{
		strcpy(frequency, "AM");
		// save the current station of the user to assign again after user jumps back to this frequency.
		savedFreq.FMFreq = current_station;
		current_station = savedFreq.AMFreq;
	}
}



/*	Name	:   SetButton()
	Purpose :   The SetButton() method is used to set the frequency of the station.
	Inputs	:	int button_num           Freqs array's element number
	Outputs	:	sets Freq struct fileds with the new values after validation
	Returns	:	1 if successfull, 0 otherwise*/
int AmFmRadio::SetButton(int button_num)
{
	if ((button_num >= NOTHING) && (button_num < SIZE))
	{
		// checks to see the frequency band and assigns the frequency to the button.
		if (strcmp("AM", GetFrequency()) == NOTHING)
		{
			Freq[button_num].AMFreq = (int)current_station;
		}
		else
		{
			Freq[button_num].FMFreq = current_station;
		}
		return SUCCESS;

	}

	return NOTHING;
}



/*	Name	:   SelectCurrentStation()
	Purpose :   The SelectCurrentStation() method is used to set the current_station data member.
	Inputs	:	int button_num           Freqs array's element number
	Outputs	:	sets current_station with the new values after validation
	Returns	:	1 if successfull, 0 otherwise*/
int AmFmRadio::SelectCurrentStation(int button_num)
{
	if ((button_num >= NOTHING) && (button_num < SIZE))
	{
		// checks the frequency band and changes the asked station to current station.
		if (strcmp("AM", GetFrequency()) == NOTHING)
		{
			current_station = Freq[button_num].AMFreq;
		}
		else
		{
			current_station = Freq[button_num].FMFreq;
		}

		return SUCCESS;
	}

	return NOTHING;
}



/*	Name	:   ShowCurrentSettings()
	Purpose :   The ShowCurrentSettings() method is used to print out the values of all the data members of the object.
	Inputs	:	None
	Outputs	:	prints out the values of all the data members of the object for user.
	Returns	:	None*/
void AmFmRadio::ShowCurrentSettings(void)
{
	// checks to see if radio is on then prints out the respective following statement.
	if (IsRadioOn() == true)
	{
		printf("\n\nRadio is on. \n");
	}
	else
	{
		printf("\n\nRadio is off. \n");
	}
	//the following lines of code is printing out all the data members values for user of the object.
	printf("\nFrequency: %s\n", frequency);
	printf("Volume: %d\n", volume);
	printf("Current Station: %.1f %s\n", current_station, frequency);
	printf("AM Button Settings: ");
	for (int i = 0; i < SIZE; ++i)
	{
		//prints the values of all the AM buttons.
		printf("%d) %6d ", i + 1, Freq[i].AMFreq);
	}

	printf("\nFM Button Settings: ");
	for (int j = 0; j < SIZE; ++j)
	{
		//prints the values of all the FM buttons.
		printf("%d) %6.1f ", j + 1, Freq[j].FMFreq);
	}
}



/*	Name	:   ScanUp()
	Purpose :   The ScanUp() method is used to set the data member current station value and wraps up .
	Inputs	:	NONE
	Outputs	:	Changes the current_station data member value and prints its current value if displayOutput is true.
	Returns	:	Void*/
void AmFmRadio::ScanUp(void)
{
	if (strcmp("AM", GetFrequency()) == NOTHING)
	{
		//if current_station is 1700, the current_station becomes 530
		// the next channel for AM change jumps the value by 10.
		if (current_station == MAXLIMIT_AM)
		{
			current_station = MINLIMIT_AM;
		}
		else
		{
			current_station = current_station + NEXTCHANNEL_AM;
		}
	}
	else
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. 
		if (current_station == MAXLIMIT_FM)
		{
			current_station = MINLIMIT_FM;
		}
		else
		{
			current_station = current_station + NEXTCHANNEL_FM;
		}
	}
	if (GetDisplayOutput() == true)
	{
		printf("\nCurrent station: %f %s\n", current_station, frequency);         // only prints displayOutput is true.
	}
}



/*	Name	:	ScanDown()
	Purpose :	The ScanDown() method is used to set the data member current station value and wraps up .
	Inputs	:	NONE
	Outputs	:	Changes the current_station data member value and prints its current value if displayOutput is true.
	Returns	:	Void*/
void AmFmRadio::ScanDown(void)
{
	if (strcmp("AM", GetFrequency()) == NOTHING)
	{
		//if current_station is 530, the current_station becomes 1700
		// the next channel for AM change jumps the value by 10.
		if (current_station == MINLIMIT_AM)
		{
			current_station = MAXLIMIT_AM;
		}
		else
		{
			current_station = current_station - NEXTCHANNEL_AM;                
		}
	}
	else
	{
		//if the current_station is 87.9, the current_station becomes 107.9
		//Note: car radios jump .2 for the FM.
		if (current_station == MINLIMIT_FM)
		{
			current_station = MAXLIMIT_FM;
		}
		else
		{
			current_station = current_station - NEXTCHANNEL_FM;
		}
	}
	if (GetDisplayOutput() == true)
	{
		printf("\nCurrent station: %f %s\n", current_station, frequency);      // only prints if displayOutput is true.
	}
}


/*	Name	:   SetName()
	Purpose :   The SetName() set the value of the name data member.
	Inputs	:	string input          to set the current value of data memeber to parameter value.
	Outputs	:	sets the value of the name data memebr to valid value from the string array names[].
	Returns	:	true if successful false otherwise*/
bool AmFmRadio::SetName(string input)
{
	for (int i = NOTHING; i < SIZE; i++)
	{
		if (kNames[i] == input)
		{
			name = kNames[i];						// assigns tthe value of the found object name to the name data member.
			return true;
		}
	}
	return false;
}



/*	Name	:	GetName()
	Purpose :   The GetName() method is used to give the name data member value to user.
	Input	:	None
	Outputs	:	gives the name data member value to user
	Returns	:	current value of name data member of the object*/
string AmFmRadio::GetName(void)
{
	return name;
}