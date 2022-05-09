/*--------------------------------------------------------------------------------
---    \file       BMS_Sender.c
---   \author      Ruthrapathi 
---
---     \brief     proj file to stream BMS data
------------------------------------------------------------------------------------*/
/*------ standard includes -------*/
#include <stdio.h>
#include <stdlib.h>

/*------ Project includes -------*/
#include "DataSender.h"

/*Intial states of operation*/
streamAlert_Status_s streamAlertStat = {NOT_SENT,FILE_ACCESS_FAILURE};

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    streamFileInpData
 */
/*!    \brief        read input data from file and stream continuosly
 * 
 *     \param       None
 *     \returns     streamAlert_Status_s -success/fail
 *
*//*------------------------------------------------------------------------*/
streamAlert_Status_s  streamFileInpData(char *inpFilePath)
{
  FILE *fptr;
  unsigned int dataIndex_ui;
  float tempRead ,chargerateRead;
  /*Read the input file*/
  fptr =fopen(inpFilePath,"r");

  if ( NULL != fptr) /*validating file access*/
  { 
     /*msg that file access is success*/
     streamAlertStat.FileReadStatus = FILE_ACCESS_SUCCESS; 
     printf("Data Read from file as follows\n");
     for(dataIndex_ui=0;fscanf(fptr,"%f\t%f", &tempRead,&chargerateRead) != EOF;dataIndex_ui++)
     {
       /*Req to print the data read from file in console*/
       sendDataToConsole(tempRead,chargerateRead);
     }
     /*Close the file*/
     fclose(fptr);
     
  }
  else
  {
      printf("File access error and No output in console\n"); 
      streamAlertStat.FileReadStatus = FILE_ACCESS_FAILURE; 
      streamAlertStat.ConsoleSentStatus = NOT_SENT;
  }  
 
   return streamAlertStat;;
 }  

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    sendDataToConsole
 */
/*!    \brief       send the data read from file continuosly
 * 
 *     \param        temp and chargerate
 *     \returns     streamAlert_Status_s -
 *
*//*------------------------------------------------------------------------*/
streamAlert_Status_s  sendDataToConsole(float temp ,float chargeRate)
{
   /*Prints temp and charge rate that read from file*/ 
   printf("%5.2f;%5.2f\n",temp,chargeRate);
   /*Print mgs status*/  
   streamAlertStat.ConsoleSentStatus = SENT_TO_CONSOLE;
   return streamAlertStat; 
}

/*In current project stream sent from UT file 
      if UT is disbaled then main shall be invoked (based on user choice) 
*/
#ifndef UNIT_TESTING
int  main()
{
  /*File path used for streaming*/
  char inpFilePath[50] = "Inputdata.txt";
  /* BMS data stream request from file mentioned above*/
  streamFileInpData(inpFilePath);
  return 0;
}
#endif
