// Created by Jonathan 'Pwn' Rainier 2018. All rights reserved.
// https://github.com/Pwnoz0r/ODZTools

#include "ODZTools/Scripts/Logger/Enums/LogType.c"

class Logger
{
	static string BasePath = "";
	static int LogYear = 0;
	static int LogMonth = 0;
	static int LogDay = 0;

	static void Init()
	{
		BasePath = "$profile:ODZLogs";
		MakeDirectory(BasePath);

		Log(LogType.Info, "--- Started Logging ---");

		Print("--- Initialized ODZTools/Logger ---");
	}

	static void Log(LogType type, string message)
	{
		string prefix = "";
		switch(type)
		{
			case LogType.Debug:
				prefix = "DEBUG";
				break;
			case LogType.Info:
				prefix = "INFO";
				break;
			case LogType.Warning:
				prefix = "WARNING";
				break;
			case LogType.Error:
				prefix = "ERROR";
				break;
		}

		string dateTime = GetDateTime();
		string messageFormat = string.Format("%1 [%2]: %3", dateTime, prefix, message);
		string logPath = string.Format("%1/%2%3%4.log", BasePath, LogYear, LogMonth, LogDay);

		FileHandle file = OpenFile(logPath, FileMode.APPEND);
		FPrintln(file, messageFormat);
		CloseFile(file);
	}

	static string GetDateTime()
	{
		int hour = 0;
		int minute = 0;
		int second = 0;

		GetHourMinuteSecond(hour, minute, second);
		GetYearMonthDay(LogYear, LogMonth, LogDay);

		return string.Format("%1/%2/%3 @ %4:%5:%6", LogYear, LogMonth, LogDay, hour, minute, second);
	}
}
