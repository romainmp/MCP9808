/*
Spark Core MCP9808 Temperature Sensor Library
By: Romain MP
Licence: GPL v3
*/

#include "MCP9808.h"


MCP9808::MCP9808(uint8_t addr){
	// TODO: address value passed should be verified
	_i2cAddr = addr;
}

bool MCP9808::begin(){
	// Only join the I2C bus as master if needed
	if(! Wire.isEnabled())
		Wire.begin();

	// Cheking if we can find the sensor on the bus
	if (read16(MCP9808_REG_MANUF_ID) != 0x0054) return false;
	if (read16(MCP9808_REG_DEVICE_ID_REV) != 0x0400) return false;

	Wire.beginTransmission(_i2cAddr);
	Wire.write(MCP9808_REG_AMBIENT_TEMP); // set the pointer back to ambient temp register
	Wire.endTransmission();

	return true;
}

float MCP9808::getTemperature(){
	Wire.requestFrom((uint8_t)_i2cAddr, (uint8_t)2);
	uint8_t msb = Wire.read();
	uint8_t lsb = Wire.read();
	float temp;

	/* // Updating flag bits
	_criticalTemp = ((msb & 0x80) == 0x80);
	_upperTemp = ((msb & 0x40) == 0x40);
	_lowerTemp = ((msb & 0x20) == 0x20); */

	msb &= 0x1F; // Clear flag bits
	if ((msb & 0x10) == 0x10) // Ta < 0°C
		temp = 256.0 - (msb * 16 + lsb / 16);
	else // Ta >= 0°C
		temp = (msb * 16) + (lsb / 16);
	return temp;
}

void MCP9808::setPowerMode(uint16_t mode){
	Wire.beginTransmission(_i2cAddr);
	Wire.write(MCP9808_REG_CONFIG); // set the pointer to config register
	Wire.write(mode >> 8);
	Wire.write(mode & 0xFF);
	Wire.endTransmission();
	Wire.beginTransmission(_i2cAddr);
	Wire.write(MCP9808_REG_AMBIENT_TEMP); // set the pointer back to ambient temp register
	Wire.endTransmission();
}

void MCP9808::setResolution(uint8_t mode){
	Wire.beginTransmission(_i2cAddr);
	Wire.write(MCP9808_REG_RESOLUTION); // set the pointer to resolution register
	Wire.write(mode);
	Wire.endTransmission();
	Wire.beginTransmission(_i2cAddr);
	Wire.write(MCP9808_REG_AMBIENT_TEMP); // set the pointer back to ambient temp register
	Wire.endTransmission();
}

uint16_t MCP9808::read16(uint8_t reg) {
	uint16_t val;

	Wire.beginTransmission(_i2cAddr);
	Wire.write((uint8_t)reg);
	Wire.endTransmission();
  
	Wire.requestFrom((uint8_t)_i2cAddr, (uint8_t)2);
	val = Wire.read();
	val <<= 8;
	val |= Wire.read();  
	return val;  
}