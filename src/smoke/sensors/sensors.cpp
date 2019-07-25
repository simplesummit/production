#include "sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
Sensors::Sensors() {}

//return average tempature from six sensors (one omitted because doesnt work)
float Sensors::getTempature(){ 
   FILE *filePtr;
   char therm_path[64];  /* 64 bytes buffer for building current pseudo file path */
   char readBuf[16];     /* 16 bytes buffer for reading ASCII encoded value from pseudo file */
   float temp;
   float count = 0;
   float total_temp = 0;   
   for (unsigned int curZone = 0; curZone < 8; curZone++) {
      unsigned int readBytes = 0;
      sprintf(therm_path, "/sys/devices/virtual/thermal/thermal_zone%u/temp", curZone);
      filePtr = fopen(therm_path, "r");
      if (!filePtr) {
    	printf ("Error, failed to open file\n");
    	continue;
      }
      while (readBytes < 16) {
         int curRead = fread(readBuf + readBytes, 1, 16 - readBytes, filePtr);
          if (curRead > 0)
    	     readBytes += curRead;
          else 
             break; /* nothing more to be read */
      }
      fclose (filePtr);

      if (readBytes > 0)
         *(readBuf + readBytes - 1) = 0; /* Remove last char '\n' */
	
      temp = atof(readBuf);
      temp /= 1000.f;
      //printf("%.02f\n", temp);
      if (temp < 90) {
      	total_temp += temp;
	count += 1.0f;
      }
   }
   return total_temp/count;
}
