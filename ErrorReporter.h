#pragma once

class ErrorReporter
{
	public:
		static void Init();
		static void LogMessage(const char* LogLevel, const char* Message);
		static void Clean();
	private:

};

