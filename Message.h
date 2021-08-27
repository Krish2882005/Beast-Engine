#pragma once
#include <vector>
#include "Colour.h"

struct MessageFormat
{
	const char* Message = "";
	Colour MessageColour = { 255, 255, 255, 255 };
	bool StayOnTop = false;
};

class Message
{
public:
	void Load();
	void Init();

	bool Log(const char* message);
	bool Log(const char* message, Colour MessageColour);
	bool Log(const char* message, bool StayOnTop);
	bool Log(const char* message, Colour MessageColour, bool StayOnTop);
	bool Log(int message);
	bool Log(int message, Colour MessageColour);
	bool Log(int message, bool StayOnTop);
	bool Log(int message, Colour MessageColour, bool StayOnTop);
	bool Log(float message);
	bool Log(float message, Colour MessageColour);
	bool Log(float message, bool StayOnTop);
	bool Log(float message, Colour MessageColour, bool StayOnTop);
	bool Log(double message);
	bool Log(double message, Colour MessageColour);
	bool Log(double message, bool StayOnTop);
	bool Log(double message, Colour MessageColour, bool StayOnTop);
	bool Log(long double message);
	bool Log(long double message, Colour MessageColour);
	bool Log(long double message, bool StayOnTop);
	bool Log(long double message, Colour MessageColour, bool StayOnTop);
	bool Log(unsigned long long message);
	bool Log(unsigned long long message, Colour MessageColour);
	bool Log(unsigned long long message, bool StayOnTop);
	bool Log(unsigned long long message, Colour MessageColour, bool StayOnTop);
	bool Log(long long message);
	bool Log(long long message, Colour MessageColour);
	bool Log(long long message, bool StayOnTop);
	bool Log(long long message, Colour MessageColour, bool StayOnTop);
	bool Log(unsigned long message);
	bool Log(unsigned long message, Colour MessageColour);
	bool Log(unsigned long message, bool StayOnTop);
	bool Log(unsigned long message, Colour MessageColour, bool StayOnTop);
	bool Log(long message);
	bool Log(long message, Colour MessageColour);
	bool Log(long message, bool StayOnTop);
	bool Log(long message, Colour MessageColour, bool StayOnTop);
	bool Log(unsigned int message);
	bool Log(unsigned int message, Colour MessageColour);
	bool Log(unsigned int message, bool StayOnTop);
	bool Log(unsigned int message, Colour MessageColour, bool StayOnTop);

	bool LogWarning(const char* message);

	bool LogError(const char* message);
	void ChangeMaxMessageSize(int maxmessages);
	void Clean();
private:
	int MaxMessages = 1000;
	int TotalMessages = 0;
	std::vector<MessageFormat> Messages;
	std::vector<const char*> WarningMessages;
	std::vector<const char*> ErrorMessages;
};
