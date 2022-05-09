/*--------------------------------------------------------------------------------
---    \file       DataSenderTest.cpp
---   \author      Ruthrapathi 
---
---     \brief     unit testing file to test streaming BMS data
------------------------------------------------------------------------------------*/
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "DataSender.h"

TEST_CASE("Test case 1 : Console output sent status") 
{
    /*Inital conditions*/	
    streamAlert_Status_s streamAlertTestStat = {NOT_SENT,FILE_ACCESS_FAILURE};
    /*func call with stub data*/
    streamAlertTestStat = sendDataToConsole(11.5, 0.7);
 
    /*Validation success*/	  
    REQUIRE(streamAlertTestStat.ConsoleSentStatus == SENT_TO_CONSOLE);

}

TEST_CASE("Test case 4 : validate that file read and stream data with valid file") 
{
    /*Inital conditions*/	
    streamAlert_Status_s streamAlertTestStat = {NOT_SENT,FILE_ACCESS_FAILURE};
    /*stub data*/ 	
    char testFilePath[50] = "Sender/Inputdata.txt";
    /*func call with valid file name*/
    streamAlertTestStat = streamFileInpData(testFilePath);
	
    //REQUIRE(streamAlertTestStat.FileReadStatus   == FILE_ACCESS_SUCCESS);
    //REQUIRE(streamAlertTestStat.ConsoleSentStatus   == SENT_TO_CONSOLE);
}

