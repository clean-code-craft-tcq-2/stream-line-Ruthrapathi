/*--------------------------------------------------------------------------------
---    \file       DataSender.h
---   \author      Ruthrapathi 
---
---     \brief     header file to stream BMS data
------------------------------------------------------------------------------------*/

/*Unit testing defintion macro needs to be enabled for testing  */
#define UNIT_TESTING 
/*enums used for Unit testing*/
typedef enum {
 SENT_TO_CONSOLE,
 NOT_SENT
}ConsoleSentStatus_t;

typedef enum {
 FILE_ACCESS_SUCCESS,
 FILE_ACCESS_FAILURE
}FileReadStatus_t;

typedef struct {
		ConsoleSentStatus_t ConsoleSentStatus;
		FileReadStatus_t FileReadStatus;
}streamAlert_Status_s;

/*Function to read and stream file data*/
streamAlert_Status_s streamFileInpData(char *inpFilePath);
/*Function to send ouput to console*/
streamAlert_Status_s sendDataToConsole(float temp ,float chargeRate);
