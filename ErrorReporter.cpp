#include "ErrorReporter.h"
#include "Logger.h"

Logger* logger = new Logger();

void ErrorReporter::Init()
{
	logger->Init();
}

void ErrorReporter::LogMessage(const char* LogLevel, const char* Message)
{
	logger->LogMessage(LogLevel, Message);
}

void ErrorReporter::Clean()
{
	delete logger;
}