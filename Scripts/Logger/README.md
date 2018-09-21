### Logger

Attempting to work with the current log system is very limited and makes it difficult to track errors and gather data. This allows messages to be logged to separate file that is dated and stored within your server's profile. Once the initialization method has completed, a folder will appear named `ODZLogs` (by default) and will contain dated `.log` files.

#### Includes

Include the following line in the top `init.c` of your mission file

    #include "ODZTools/Scripts/Logger/Logger.c"

#### Initialization

    Logger.Init();

#### Usage

    Logger.Log(LogType.Debug, "This is a debug message!");
    Logger.Log(LogType.Info, "This is a info message!");
    Logger.Log(LogType.Warning, "This is a warning message!");
    Logger.Log(LogType.Error, "This is a error message!");

#### License

Feel free to use this script wherever you want for whatever you want. Just give credit where credit is due.
