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

	Serial.println("MCP9808 test");

	while(! mcp.begin()){
	    Serial.println("MCP9808 not found");
	    delay(1000);
	}

	Serial.println("MCP9808 OK");
}

void loop()
{
	Serial.println("===================");
	Serial.print("Temp:"); Serial.println(mcp.getTemperature());
	Serial.println();

	delay(1000);
}