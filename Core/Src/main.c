/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "config.h"
#include "modbus_crc.h"
#include "sht3x.h"
#include "cJSON.h"
#include <math.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DS1307_I2C_ADDR 0x23
#define DS1307_TIMEOUT 300
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define BH1750_ADDRESS 0x23 << 1 // Shifted left by 1 for HAL library
#define BH1750_POWER_ON 0x01
#define BH1750_RESET 0x07
#define BH1750_CONTINUOUS_HIGH_RES_MODE 0x10

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

TIM_HandleTypeDef htim6;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart4;

/* USER CODE BEGIN PV */
char rxBuffer[50];
int previousTick = 0;
int isConnectSimcomA76xx = 0;
int isConnectMQTT = 0;
int isSleepMode = 0;
int isSendDataToServer;
int timeOutConnectA76XX = 40000;
float SignalStrength;
int isPBDONE = 0;
float airT, airH, soilT, soilMC, soilEC;
float temperature, humidity;

float SignalStrength=0;
// BatteryLevel
uint32_t adcValue=0;
float  BatteryLevel=0;
float PercentageBattery=0;
uint32_t arrayBattery[10];
uint32_t temp;
uint8_t times=10;
//int time_Period=0;
int Filter_Baterry_Values();
int MediumBattery();



char AT_RESET[] = "AT+CRESET\r\n";
char AT_CHECK_A76XX[] = "AT\r\n";
char ATE0[] = "ATE0\r\n";
char AT_CHECK_ESIM[] = "AT+CGREG?\r\n";
char AT_SIGNAL_SIM[] = "AT+CSQ\r\n";
char AT_START_MQTT[] = "AT+CMQTTSTART\r\n";
char AT_ACQUIRE_CLIENT[] = "AT+CMQTTACCQ=0,\"%s\",0\r\n";
char AT_CONNECT_MQTT[] = "AT+CMQTTCONNECT=0,\"%s:%d\",60,1,\"%s\",\"%s\"\r\n";
char AT_SET_PUBLISH_TOPIC[] = "AT+CMQTTTOPIC=0,%d\r\n";
char AT_SET_PUBLISH_PAYLOAD[] = "AT+CMQTTPAYLOAD=0,%d\r\n";
char AT_PUBLISH[] = "AT+CMQTTPUB=0,1,60\r\n";
char AT_SUBCRIBE_TOPIC[] = "%s%d\r\n";
char AT_SUBCRIBE[] = "AT+CMQTTSUB=0\r\n";
char AT_COMMAND[300];
char BUFFER_TOPPIC_MQTT[300];
char BUFFER_DATA_PAYLOAD_MQTT[300];

#if co2
	unsigned char data_co2[9] = { 0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79 };
	unsigned char data_vl53l1[3] = {0xA5,0x15,0xBA};
	uint8_t rx_co2[10];
	int carbonic;
#endif

#if rk520_01
	char rika502_01[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B};
	float soilTemperature = 0;
	float soilMoisture = 0;
	uint8_t respone_rk520_01= false;
#endif

#if rk520_02
//unsigned char rika520_02[10] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x03, 0x05, 0xCB};
unsigned char rika520_02[10] =
		{ 0x02, 0x03, 0x00, 0x00, 0x00, 0x03, 0x05, 0xF8 };
float soilTemperature_rk520_02 = 0;
float soilMoisture_rk520_02 = 0;
float EC_rk520_02 = 0;
uint8_t respone_rk520_02 = false;
#endif
#if NBL_S_TMC_7
	float soilTemperature_niubol_7=0;
	float soilMoisture_niubol_7=0;
	float soil_Conductivity_niubol_7=0;
	float soil_pH_niubol_7=0;
	float soil_Nitrogen_niubol_7=0;
	float soil_Phospho_niubol_7=0;
	float soil_Kali_niubol_7=0;
	unsigned char niubol_7[10] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x07, 0x04, 0x08};
	uint8_t respone_NBL_S_TMC_7= false;
#endif
#if rk500_02
float soilPH = 0;
//unsigned char rika500_02[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
unsigned char rika500_02[8] = { 0x05, 0x03, 0x00, 0x00, 0x00, 0x01, 0x85, 0x8E };
uint8_t respone_rk500_02 = false;
#endif
#if nbl_s_npk
//unsigned char data_nbl_s_npk[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x03, 0x05, 0xCB};
unsigned char data_nbl_s_npk[8] = { 0x03, 0x03, 0x00, 0x00, 0x00, 0x03, 0x04,
		0x29 };
uint8_t respone_nbl_s_npk = false;
#endif

#if bh1750
uint8_t address_bh1750 = 0x10;
float data_bh1750;
uint8_t rx_bh1750[5];
float lux;
uint8_t response_bh1750 = false;
#endif
uint8_t respone_sht30 = false;

uint16_t fertN, fertP, fertK;
char testjson[300];
int testpoint = 0;
int testvar = 0;
//rs485

uint8_t hostScanOrderData[8];
uint8_t sensorResponseData[20];
uint16_t testsrlen;
int rssi = -99;

sht3x_handle_t handle = { .i2c_handle = &hi2c1, .device_address =
SHT3X_I2C_DEVICE_ADDRESS_ADDR_PIN_LOW };
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM6_Init(void);
static void MX_I2C2_Init(void);
static void MX_USART4_UART_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_ADC_Init(void);
/* USER CODE BEGIN PFP */
void turnOnA76XX();
void readSensors(void);
int32_t Read_BH1750();

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void sendData(uint8_t *data) {
	HAL_UART_Transmit(&huart4, data, 8, 2000);
}
void read_rk520_01(uint8_t *data) {
	HAL_UART_Transmit(&huart4, data, 8, 2000);
}
void read_rk520_02(uint8_t *data) {
	HAL_UART_Transmit(&huart4, data, 8, 2000);
}
void read_rk500_02(uint8_t *data) {
	HAL_UART_Transmit(&huart4, data, 8, 2000);
}
void read_niubol_7(uint8_t *data) {
	HAL_UART_Transmit(&huart4, data, 9, 2000);
}
void read_niubol_npk(uint8_t *data_npk) {
	HAL_UART_Transmit(&huart4, data_npk, 8, 2000);
}
void write_co2(uint8_t *data_co2) {
	HAL_UART_Transmit(&huart2, data_co2, 9, 1000);
}
void sendingToSimcomA76xx(char *cmd) {
	HAL_UART_Transmit(&huart1, (uint8_t*) cmd, strlen(cmd), 1000);
}
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
	if (huart->Instance == USART1) {
		HAL_UARTEx_ReceiveToIdle_IT(huart, (uint8_t*) rxBuffer, 50);
	}
	if (huart->Instance == USART4) {
#if rk520_01
						if(sensorResponseData[0]==1)
						{
							soilTemperature = (sensorResponseData[3]<<8 | sensorResponseData[4]);
							soilMoisture = (sensorResponseData[5]<<8 | sensorResponseData[6]);
							respone_rk520_01 = true;
						}
					#endif
#if rk520_02
				if (sensorResponseData[0] == 2) {
					soilTemperature_rk520_02 = (sensorResponseData[3] << 8
							| sensorResponseData[4]);
					soilMoisture_rk520_02 = (sensorResponseData[5] << 8
							| sensorResponseData[6]);
					EC_rk520_02 = (sensorResponseData[7] << 8 | sensorResponseData[8]);
					respone_rk520_02 = true;
				}
		#endif
#if NBL_S_TMC_7
						if(sensorResponseData[0]==1)
						{
							soilTemperature_niubol_7=(sensorResponseData[3]<<8 | sensorResponseData[4])*0.1;
							soilMoisture_niubol_7 = (sensorResponseData[5]<<8 | sensorResponseData[6])*0.1;
							soil_Conductivity_niubol_7=(sensorResponseData[7]<<8 | sensorResponseData[8]);
							soil_pH_niubol_7=(sensorResponseData[9]<<8 | sensorResponseData[10])*0.01;
							soil_Nitrogen_niubol_7=(sensorResponseData[11]<<8 | sensorResponseData[12]);
							soil_Phospho_niubol_7=(sensorResponseData[13]<<8 | sensorResponseData[14]);
							soil_Kali_niubol_7=(sensorResponseData[15]<<8 | sensorResponseData[16]);
							respone_NBL_S_TMC_7 = true;
						}
						//EC_rk520_02= (sensorResponseData[7]<<8 | sensorResponseData[8]);
					#endif
#if nbl_s_npk
		if (sensorResponseData[0] == 3) {
			fertN = (sensorResponseData[3] << 8 | sensorResponseData[4]);
			fertP = (sensorResponseData[5] << 8 | sensorResponseData[6]);
			fertK = (sensorResponseData[7] << 8 | sensorResponseData[8]);
			respone_nbl_s_npk = true;
		}

#endif
#if rk500_02
		if (sensorResponseData[0] == 5) {
			soilPH = (sensorResponseData[3] << 8 | sensorResponseData[4])
					/ 100.0;
			respone_rk500_02 = true;
		}
#endif
		HAL_UARTEx_ReceiveToIdle_IT(&huart4, (uint8_t*) sensorResponseData, 20);
	}
	if (huart->Instance == USART2) {
#if co2
		carbonic = (rx_co2[2] * 256 + rx_co2[3]);
		HAL_UARTEx_ReceiveToIdle_IT(&huart2, (uint8_t*) rx_co2, 8);
		#endif
	}
	//HAL_UARTEx_ReceiveToIdle_IT(huart, (uint8_t *) sensorResponseData, 9);
}

void turnOnA76XX(void) {
	HAL_GPIO_WritePin(ENABLE_A76XX_GPIO_Port, ENABLE_A76XX_Pin, RESET);
	HAL_Delay(3000);
	HAL_GPIO_WritePin(ENABLE_A76XX_GPIO_Port, ENABLE_A76XX_Pin, SET);
	HAL_Delay(3000);
	HAL_GPIO_WritePin(ENABLE_A76XX_GPIO_Port, ENABLE_A76XX_Pin, RESET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(ENABLE_A76XX_GPIO_Port, ENABLE_A76XX_Pin, SET);
	HAL_Delay(1000);
}

int connectSimcomA76xx() {
	//HAL_TIM_Base_Stop_IT(&htim6);
	previousTick = HAL_GetTick();
	while ((isConnectSimcomA76xx == 0)
			&& (previousTick + timeOutConnectA76XX) > HAL_GetTick()) {
//	while(isConnectSimcomA76xx == 0){

		if (strstr((char*) rxBuffer, "PB DONE")) {
			HAL_Delay(1000);
			isPBDONE = 1;
		}
//		if (strstr((char*) rxBuffer, "PDN ACT 1")) {
//			HAL_Delay(5000);
//			isPBDONE = 1;
//		}
		if (isPBDONE == 1) {
			sendingToSimcomA76xx(ATE0);
			HAL_Delay(200);
			sendingToSimcomA76xx(AT_SIGNAL_SIM);
			HAL_Delay(1000);
			uint8_t SignalStrength1;
			SignalStrength = (rxBuffer[8] - 48) * 10 + (rxBuffer[9] - 48)
					+ (rxBuffer[11] - 48) * 0.1 + (rxBuffer[12] - 48) * 0.01;
			SignalStrength1 = (rxBuffer[8] - 48) * 10 + (rxBuffer[9] - 48);
			if(SignalStrength1>=31)
			{
				rssi=-51;
			}else rssi = SignalStrength1 * 2 - 113;
			isConnectSimcomA76xx = 1;
			HAL_Delay(1000);
		}
	}
	if (isConnectSimcomA76xx == 0) {
		NVIC_SystemReset();
	}
	return isConnectSimcomA76xx;
}
#if bh1750
int32_t Read_BH1750() {
	HAL_StatusTypeDef result;
	result = HAL_I2C_Master_Transmit(&hi2c2, DS1307_I2C_ADDR << 1,
			&address_bh1750, 1, 300);
	if (result == HAL_OK) {
		response_bh1750 = true;
	}
	HAL_Delay(200);
	HAL_I2C_Master_Receive(&hi2c2, DS1307_I2C_ADDR << 1, rx_bh1750, 2, 300);
	data_bh1750 = ((rx_bh1750[0] << 8) | rx_bh1750[1]) / 1.2;
	HAL_Delay(200);
	return data_bh1750;
}
#endif

void BH1750_Init(void) {
	uint8_t cmd = BH1750_POWER_ON;
	HAL_I2C_Master_Transmit(&hi2c2, BH1750_ADDRESS, &cmd, 1, HAL_MAX_DELAY);
	cmd = BH1750_RESET;
	HAL_I2C_Master_Transmit(&hi2c2, BH1750_ADDRESS, &cmd, 1, HAL_MAX_DELAY);
	cmd = BH1750_CONTINUOUS_HIGH_RES_MODE;
	HAL_I2C_Master_Transmit(&hi2c2, BH1750_ADDRESS, &cmd, 1, HAL_MAX_DELAY);
}
uint16_t BH1750_ReadLight(void) {
	uint8_t buf[2];
	HAL_I2C_Master_Receive(&hi2c2, BH1750_ADDRESS, buf, 2, HAL_MAX_DELAY);
	uint16_t lux = (buf[0] << 8) | buf[1];
	return lux / 1.2; // Convert to lux
}

void readSensors(void) {
	//rs485
	//lux = Read_BH1750();
	for (int i = 1; i <= 2; i++) {
#if sht30
		sht3x_read_temperature_and_humidity(&handle, &temperature, &humidity);
		//printf("Initial temperature: %.2fC, humidity: %.2f%%RH\n\r", temperature, humidity);
		// Enable heater for two seconds.
		sht3x_set_header_enable(&handle, true);
		HAL_Delay(1000);
		sht3x_set_header_enable(&handle, false);
		// Read temperature and humidity again.
		respone_sht30 = sht3x_read_temperature_and_humidity(&handle,
				&temperature, &humidity);
		HAL_Delay(1000);
#endif
#if bh1750
		lux = Read_BH1750();
		HAL_Delay(1000);
#endif
#if rk520_01
				read_rk520_01(rika502_01);
				HAL_Delay(1000);
				#endif
#if rk520_02
				read_rk520_02(rika520_02);
				HAL_Delay(1000);
		#endif
#if rk500_02
		read_rk500_02(rika500_02);
		HAL_Delay(1000);
#endif
#if NBL_S_TMC_7
				read_niubol_7(niubol_7);
				HAL_Delay(1000);
				#endif
#if nbl_s_npk
		read_niubol_npk(data_nbl_s_npk);
		HAL_Delay(1000);
#endif
#if co2
				write_co2(data_co2);
				HAL_Delay(1000);
		#endif
	}
	//HAL_GPIO_WritePin(LED_STATUS_GPIO_Port, LED_STATUS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ENABLE_SENSOR_GPIO_Port, ENABLE_SENSOR_Pin, GPIO_PIN_RESET);
}

int connectMQTT(void) {
	//readSensors();
	sendingToSimcomA76xx(ATE0);
	HAL_Delay(200);
	sendingToSimcomA76xx(AT_START_MQTT);
	HAL_Delay(500);
	sprintf(AT_COMMAND, AT_ACQUIRE_CLIENT, MQTT_CLIENT_ID);
	sendingToSimcomA76xx(AT_COMMAND);
	HAL_Delay(500);
	sprintf(AT_COMMAND, AT_CONNECT_MQTT, MQTT_HOST, MQTT_PORT, MQTT_USER,
	MQTT_PASS);
	sendingToSimcomA76xx(AT_COMMAND);
	HAL_Delay(700);
	// Start Sensor
	sprintf(BUFFER_TOPPIC_MQTT, "%s/sn/%s", FARM, MQTT_CLIENT_ID);
	sprintf(AT_COMMAND, AT_SET_PUBLISH_TOPIC, (int) strlen(BUFFER_TOPPIC_MQTT));
	sendingToSimcomA76xx(AT_COMMAND);
	HAL_Delay(500);
	sendingToSimcomA76xx(BUFFER_TOPPIC_MQTT);
	HAL_Delay(500);
	// test json
	sprintf(BUFFER_TOPPIC_MQTT, "%s/sn/%s", FARM, MQTT_CLIENT_ID);
	sprintf(AT_COMMAND, AT_SET_PUBLISH_TOPIC, (int) strlen(BUFFER_TOPPIC_MQTT));
	sendingToSimcomA76xx(AT_COMMAND);
	HAL_Delay(500);
	sendingToSimcomA76xx(BUFFER_TOPPIC_MQTT);
	HAL_Delay(500);
	sprintf(AT_COMMAND, AT_SET_PUBLISH_PAYLOAD, (int) strlen(testjson));
	sendingToSimcomA76xx(AT_COMMAND);
	HAL_Delay(500);
	sendingToSimcomA76xx(testjson);
	HAL_Delay(500);
	sendingToSimcomA76xx(AT_PUBLISH);
	HAL_Delay(500);

	isConnectMQTT = 1;
	return isConnectMQTT;
}

int Sleep_Stm32_A7672S() {
	//Sleep Simcom A7672S

	HAL_GPIO_WritePin(ENABLE_A76XX_GPIO_Port, ENABLE_A76XX_Pin, GPIO_PIN_RESET);
	HAL_Delay(5000);
	//sendingToSimcomA76xx("AT+CPOF");
	HAL_GPIO_WritePin(ENABLE_A76XX_GPIO_Port, ENABLE_A76XX_Pin, GPIO_PIN_SET);
	HAL_Delay(6000);
	//CLose sensor
	HAL_GPIO_WritePin(LED_STATUS_GPIO_Port, LED_STATUS_Pin, GPIO_PIN_RESET);
	HAL_TIM_Base_Start_IT(&htim6);
	HAL_SuspendTick();
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFE);
	HAL_ResumeTick();
	NVIC_SystemReset();
	isSleepMode = 1;

	return isSleepMode;
}
int Filter_Baterry_Values(){
	for(int i=0;i<times;i++)
	{
		HAL_ADC_Start(&hadc);
		HAL_ADC_PollForConversion(&hadc,HAL_MAX_DELAY);
		HAL_Delay(100);
		arrayBattery[i]=HAL_ADC_GetValue(&hadc);
	}
	adcValue=MediumBattery();
	BatteryLevel=((adcValue/4095.0)*3.3);
	PercentageBattery=((BatteryLevel-2.5)/0.5)*100;
	if(PercentageBattery>100)
	{
		PercentageBattery=100;
	}
	HAL_ADC_Stop(&hadc);
	return PercentageBattery ;
}
int MediumBattery(){
	for(int i=0; i<times-1; i++)
	{
		for(int j=i+1;j<times;j++)
		{
			if(arrayBattery[i]>arrayBattery[j])
			{

			  temp=arrayBattery[i];

			  arrayBattery[i]=arrayBattery[j];

			  arrayBattery[j]=temp;

			}
		}
	}
	return arrayBattery[times/2];
}
void exampleFunction(void) {
	// Các biến cần được ghép vào JSON
//    const char *name = "John Doe";
//    int age = 30;
//    double score = 85.5;
//    const char *hobbies[] = {"reading", "swimming", "coding"};
//    int hobbies_count = sizeof(hobbies) / sizeof(hobbies[0]);
	// Tạo một đối tượng JSON
	cJSON *json = cJSON_CreateObject();
	// Thêm các giá trị vào đối tượng JSON
#if sht30
	if (respone_sht30 == true) {
		airT = (temperature * 100) / 100;
		airH = (humidity * 100) / 100;
		cJSON_AddNumberToObject(json, "airT", airT);
		cJSON_AddNumberToObject(json, "airRH", airH);
	}
#endif
#if rk520_01
	    if(respone_rk520_01==true)
	    {
			soilT = soilTemperature*0.1;
			soilMC = soilMoisture*0.1;
		    cJSON_AddNumberToObject(json, "soilT", soilT);
		    cJSON_AddNumberToObject(json, "soilMC", soilMC);
		    respone_rk520_01 = false;
	    }

	#endif
#if rk520_02
	if (respone_rk520_02 == true) {
		soilMC = soilMoisture_rk520_02 * 0.1;
		soilT = soilTemperature_rk520_02 * 0.1;
		soilEC = EC_rk520_02;
		cJSON_AddNumberToObject(json, "soilT", soilT);
		cJSON_AddNumberToObject(json, "soilMC", soilMC);
		cJSON_AddNumberToObject(json, "soilEC", soilEC);
		respone_rk520_02 = false;
	}

#endif
#if rk500_02
	if (respone_rk500_02 == true) {
		cJSON_AddNumberToObject(json, "soilPH", soilPH);
		respone_rk500_02 = false;
	}

#endif
#if nbl_s_npk
	if (respone_nbl_s_npk == true) {
		cJSON_AddNumberToObject(json, "fertN", fertN);
		cJSON_AddNumberToObject(json, "fertP", fertP);
		cJSON_AddNumberToObject(json, "fertK", fertK);
		respone_nbl_s_npk = false;
	}

#endif
#if NBL_S_TMC_7
	if (respone_NBL_S_TMC_7 == true) {
	    cJSON_AddNumberToObject(json, "soilT", soilTemperature_niubol_7);
	    cJSON_AddNumberToObject(json, "soilMC", soilMoisture_niubol_7);
		cJSON_AddNumberToObject(json, "soilEC", soil_Conductivity_niubol_7);
		cJSON_AddNumberToObject(json, "soilPH", soil_pH_niubol_7);
		cJSON_AddNumberToObject(json, "fertN", soil_Nitrogen_niubol_7);
		cJSON_AddNumberToObject(json, "fertP", soil_Phospho_niubol_7);
		cJSON_AddNumberToObject(json, "fertK", soil_Kali_niubol_7);
		respone_NBL_S_TMC_7 = false;
	}

#endif
#if bh1750
	if (response_bh1750) {
		cJSON_AddNumberToObject(json, "Light", lux);
	}
#endif
#if co2
	cJSON_AddNumberToObject(json, "Carbonic", carbonic);
#endif
	cJSON_AddNumberToObject(json, "_gsm_signal_strength", rssi);
	cJSON_AddNumberToObject(json, "_battery_level", PercentageBattery);
	// Tạo một mảng JSON cho các sở thích
//    cJSON *json_hobbies = cJSON_CreateArray();
//    for (int i = 0; i < hobbies_count; i++) {
//        cJSON_AddItemToArray(json_hobbies, cJSON_CreateString(hobbies[i]));
//    }
//    cJSON_AddItemToObject(json, "hobbies", json_hobbies);

	// Chuyển đổi đối tượng JSON thành chuỗi
	char *json_string = cJSON_Print(json);
	if (json_string == NULL) {
		printf("Lỗi tạo chuỗi JSON\n");
		cJSON_Delete(json);
		return;
	}

	// In chuỗi JSON
	printf("%s\n", json_string);
	sprintf(testjson, "%s", json_string);

	// Giải phóng bộ nhớ
	free(json_string);
	cJSON_Delete(json);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  MX_TIM6_Init();
  MX_I2C2_Init();
  MX_USART4_UART_Init();
  MX_USART2_UART_Init();
  MX_ADC_Init();
  /* USER CODE BEGIN 2 */

	HAL_UARTEx_ReceiveToIdle_IT(&huart1, (uint8_t*) rxBuffer, 50);
	HAL_UARTEx_ReceiveToIdle_IT(&huart4, (uint8_t*) sensorResponseData, 20);
#if co2
		HAL_UARTEx_ReceiveToIdle_IT(&huart2, (uint8_t*) rx_co2, 8);
	#endif

	HAL_GPIO_WritePin(ENABLE_SENSOR_GPIO_Port, ENABLE_SENSOR_Pin, SET);
	turnOnA76XX();
	BH1750_Init();
#if sht30
	if (!sht3x_init(&handle)) {
		printf("SHT3x access failed.\n\r");
	}
#endif

	//HAL_TIM_Base_Start_IT(&htim6);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
		if (!isConnectSimcomA76xx) {
			isConnectSimcomA76xx = connectSimcomA76xx();
		}
		readSensors();
		Filter_Baterry_Values();
		exampleFunction();
		if (!isConnectMQTT) {
			isConnectMQTT = connectMQTT();
		}
		if (!isSleepMode) {
			isSleepMode = Sleep_Stm32_A7672S();
		}

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV16;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART2
                              |RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC_Init(void)
{

  /* USER CODE BEGIN ADC_Init 0 */

  /* USER CODE END ADC_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC_Init 1 */

  /* USER CODE END ADC_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc.Instance = ADC1;
  hadc.Init.OversamplingMode = DISABLE;
  hadc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ContinuousConvMode = ENABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerFrequencyMode = ENABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */

  /* USER CODE END ADC_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00000000;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x00000000;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 59999;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = TIME_PERIOD;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART4_UART_Init(void)
{

  /* USER CODE BEGIN USART4_Init 0 */

  /* USER CODE END USART4_Init 0 */

  /* USER CODE BEGIN USART4_Init 1 */

  /* USER CODE END USART4_Init 1 */
  huart4.Instance = USART4;
  huart4.Init.BaudRate = 9600;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  huart4.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart4.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART4_Init 2 */

  /* USER CODE END USART4_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_STATUS_Pin|ENABLE_SENSOR_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ENABLE_A76XX_GPIO_Port, ENABLE_A76XX_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_STATUS_Pin ENABLE_SENSOR_Pin */
  GPIO_InitStruct.Pin = LED_STATUS_Pin|ENABLE_SENSOR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : ENABLE_A76XX_Pin */
  GPIO_InitStruct.Pin = ENABLE_A76XX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ENABLE_A76XX_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
