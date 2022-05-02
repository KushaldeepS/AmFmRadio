/*  File               :   AmFmRadio.h
*   Project            :   SENG1385 OOP - Assignment 6
*   Programmer         :   Kushaldeep Singh
*   First version      :   March 29, 2022
*   Description        :   This is the .h file where the definition of the class AmFmRadio exists including a struct Freqs and constants.
							The class has data memebrs to support the functioning of the radio to turn radio on or off, to change channels of radio and
							frequency band as well, to show current setting of the radio, to change and save the buttons and their frequencies.*/
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#pragma warning (disable : 4996)



// constant values to handle magic numbers
#ifndef _CARRADIO_H
#define _CARRADIO_H

#define MAXLIMIT_AM 1700
#define MINLIMIT_AM 530
#define MAXLIMIT_FM 107.9
#define MINLIMIT_FM 87.9
#define NEXTCHANNEL_AM 10
#define NEXTCHANNEL_FM 0.2
#define SIZE 5
#define FREQ_LEN 3
#define NOTHING 0
#define SUCCESS 1
#define ANOTHERNOTHING 2
#define BUFF_LEN 20
#define MAXVOL 100


const string kNames[SIZE] = { "Pioneer XS440", "Pioneer XS440-AM", "Pioneer XS440-WRLD" };		// constant string array to store name data member values.
const string kInput[SIZE] = { "-car", "-am", "-world" };										// constant string array to validate name data member values.

//struct to store frequencies for both AM and FM band
typedef struct Freqs
{
	int    AMFreq;		// able to store frequency for AM band
	double FMFreq;		// able to store frequency for FM band
}Freqs;

class AmFmRadio
{
private:
	Freqs	Freq[SIZE];				//Struct array to store frequencies for buttons.
	double	current_station;		//current station frequency value
	char	frequency[FREQ_LEN];	//frequency band name
	int		volume;					//volume level
	bool	on;						//store bool value to turn radio on or off
	Freqs	savedFreq;              //saves last used frequency for later use.
	int		savedVol;				//saves last used volume level
	bool	displayOutput;			//saves bool to make program to show outputs for user.

	string name;					// Name to store the name of the radio being destroyed even in child classes.

	// unused data members in the code except copying char *.
	char myFrequency[FREQ_LEN];		//bogus data member to use and store frequencies for buttons when needs to return address of the memory.
	Freqs myFreq[SIZE];				//bogus data member to use and store frequency band name when needs to return address of the memory.

public:
	//sets the each button to the lowest frequency, sets the current station, sets the
	//frequency to AM, sets the volume to 0 and sets on to false
	// constructor to instantiate object by passing value for button presets and turns the radio on.
	AmFmRadio(Freqs Freq[], bool onOrOff);

	//constructor to instantiate object by passing bool value to turns the radio on if not passed in the default value is set as false of radio on data member.
	AmFmRadio(bool onOrOff = false);

	//Destructor for destroying any objects at the end of the program that were instantiated at the beginning of the program.
	virtual ~AmFmRadio();

	//sets on to true
	void PowerToggle(void);

	//returns a true if the radio is currently powered on, and false if the radio is in
	//the off position
	bool IsRadioOn(void);

	//toggles frequency between AM and FM and sets current station
	virtual void ToggleFrequency(void);

	//sets button with current station by being passed a button number
	virtual int SetButton(int button_num);

	//sets current station by being passed a button number
	virtual int SelectCurrentStation(int button_num);

	//sets volume
	int SetVolume(void);

	// sets volume by passing volume
	int SetVolume(int volume);

	//shows volume, button settings, current station, AM or FM
	virtual void ShowCurrentSettings(void);

	//changes frequency up in increments of .2 for FM, 10 for AM
	virtual void ScanUp(void);

	//changes frequency down in decrements of .2 for FM, 10 for AM
	virtual void ScanDown(void);

	//gets the bool for printing output for user.
	bool GetDisplayOutput(void);

	//gets the current station values for user.
	double GetCurrentStation(void);

	//gets the volume values for user.
	int GetVolume(void);

	// gets the frequency calue for user.
	char* GetFrequency(void);

	//gets the radio presets for user.
	Freqs* GetFreq(void);

	//Sets the data member displayOutput to enable or disable print statments
	bool SetDisplayOutput(bool);

	// sets the current station of the radio.
	bool SetCurrentStation(double newStation);

	// sets the value of the name data member after validation.
	bool SetName(string input);

	// Gives the value of the name data member to user.
	string GetName(void);
};
#endif