#ifndef _LOGMANAGER_H
#define _LOGMANAGER_H

#pragma once

#include <string>
#include <fstream>

namespace DRE
{
	enum LogMessageType
	{
		INFO = 0,
		WARNING,
		TRACE,
		ERROR,
		FATAL_ERROR
	};

	class LogManager
	{
	public:
		static void Initialize() {
			std::ofstream output;
			output.open("DumbRockEngineLog.txt");
			output.close();
		}

		static void LogMessage(LogMessageType messageType, const std::string& message, const char* filename, const int& line) {
			std::ofstream output;
			output.open("DumbRockEngineLog.txt", std::ios::app | std::ios::app);

			switch (messageType) {
			case LogMessageType::INFO:
				output << "INFO: " << message << " - from: " << filename << " at line: " << line << std::endl;
				break;
			case LogMessageType::WARNING:
				output << "WARNING: " << message << " - from: " << filename << " at line: " << line << std::endl;
				break;
			case LogMessageType::TRACE:
				output << "TRACE: " << message << " - from: " << filename << " at line: " << line << std::endl;
				break;
			case LogMessageType::ERROR:
				output << "ERROR: " << message << " - from: " << filename << " at line: " << line << std::endl;
				break;
			case LogMessageType::FATAL_ERROR:
				output << "FATAL ERROR: " << message << " - from: " << filename << " at line: " << line << std::endl;
				break;
			}

			output.close();
		}
	};
}

#endif