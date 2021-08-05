//This Is A Beast Engine File Which Has The License Apache 2.0

#include "Logger.h"
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

boost::log::sources::severity_logger< boost::log::trivial::severity_level > lg;

void Logger::Init()
{
	boost::log::add_file_log(
		boost::log::keywords::file_name = "Log.log",
		boost::log::keywords::rotation_size = 10 * 1024 * 1024,
		boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
		boost::log::keywords::format = "[%TimeStamp%] : %Message%"
	);

	boost::log::add_common_attributes();
}

void Logger::LogMessage(const char* LogLevel, const char* Message)
{
	if (strcmp(LogLevel, "Trace"))
	{
		BOOST_LOG_SEV(lg, boost::log::trivial::trace) << Message;
	}
	else if (strcmp(LogLevel, "Debug"))
	{
		BOOST_LOG_SEV(lg, boost::log::trivial::debug) << Message;
	}
	else if (strcmp(LogLevel, "Info"))
	{
		BOOST_LOG_SEV(lg, boost::log::trivial::info) << Message;
	}
	else if (strcmp(LogLevel, "Warning"))
	{
		BOOST_LOG_SEV(lg, boost::log::trivial::warning) << Message;
	}
	else if (strcmp(LogLevel, "Error"))
	{
		BOOST_LOG_SEV(lg, boost::log::trivial::error) << Message;
	}
	else if (strcmp(LogLevel, "Fatal"))
	{
		BOOST_LOG_SEV(lg, boost::log::trivial::fatal) << Message;
	}
}
