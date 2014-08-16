/*
Spark Core MCP9808 Temperature Sensor Library
By: Romain MP
Licence: GPL v3
*/

#include "MCP9808/MCP9808.h"

MCP9808 mcp = MCP9808();

void setup()
{
	Serial.begin(9600);
    
    delay(5000);
    
	Serial.println("MCP9808 test");

	while(! mcp.begin()){
	    Serial.println("MCP9808 not found");
	    delay(500);
	}
	
	mcp.setResolution(MCP9808_SLOWEST);

	Serial.println("MCP9808 OK");
}

void loop()
{
	Serial.print("Temp:"); Serial.println(mcp.getTemperature(), 4);
	delay(250);
}