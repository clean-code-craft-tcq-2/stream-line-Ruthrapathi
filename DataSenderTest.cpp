/*--------------------------------------------------------------------------------
---    \file       BMS_sendertest.cpp
---   \author      Ruthrapathi 
---
---     \brief     unit testing file to test streaming BMS data
------------------------------------------------------------------------------------*/
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../test/catch.hpp"
#include "BMS_Sender.h"

TEST_CASE("Test case 1 : Console output sent status") 
{
    /*Inital conditions*/	
    streamAlert_Status_s streamAlertTestStat = {NOT_SENT,FILE_ACCESS_FAILURE};
    /*func call with stub data*/
    streamAlertTestStat = sendDataToConsole(11.5, 0.7);
 
    /*Validation success*/	  
    REQUIRE(streamAlertTestStat.ConsoleSentStatus == SENT_TO_CONSOLE);

}
