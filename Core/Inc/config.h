/*
 * config.h
 *
 *  Created on: Dec 4, 2023
 *      Author: ThuanPhat
 */
#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#include "main.h"
// Codename of the farm, where we deploy this node to.
#ifndef FARM
#define FARM "gateway-agriconnect"
#endif
// Serial number. Must be lower case.
#ifndef SERIAL_NUMBER
#define SERIAL_NUMBER "eb000332"
#endif
#define time_sleep 180 //seconds (s)
/** MQTT
 * Global broker: mqtt.agriconnect.vn
 */
#define MQTT_HOST "tcp://mqtt.agriconnect.vn"           		// MQTT broker
#define MQTT_USER "mqttnode"                          // User - connect to MQTT broker
#define MQTT_PASS "congamo"                        		// Password - connect to MQTT broker
//#define MQTT_USER "node"                          // User - connect to MQTT broker
//#define MQTT_PASS "654321"                        		// Password - connect to MQTT broker
#define MQTT_CLIENT_ID  SERIAL_NUMBER
#define MQTT_PORT 1883
// ADRESS FLASH
#define true 1
#define false 0

#define rk520_01 false
#define rk520_02 false
#define rk500_02 false
#define bh1750 true
#define sht30 true
#define NBL_S_TMC_7 true
#define nbl_s_npk false
#define co2 false
#define enable_sleep_mode false

#define time_Period ((1000000*time_sleep)/60000)-1;

#endif /* INC_CONFIG_H_ */
