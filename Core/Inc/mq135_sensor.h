
#ifndef INC_MQ135_SENSOR_H_
#define INC_MQ135_SENSOR_H_

#include "stm32f4xx_hal.h"

/************************MQ135sensor************************************/
/************************Hardware Related Macros************************************/
#define         MQ135PIN                       (5)     //define which analog input channel you are going to use
#define         RL_VALUE_MQ135                 (1)     //define the load resistance on the board, in kilo ohms
#define         RO_CLEAN_AIR_FACTOR_MQ135      (3.59)  //RO_CLEAR_AIR_FACTOR=(Sensor resistance in clean air)/RO,
                                                       //which is derived from the chart in datasheet

/***********************Software Related Macros************************************/
#define         CALIBARAION_SAMPLE_TIMES     (50)    //define how many samples you are going to take in the calibration phase
#define         CALIBRATION_SAMPLE_INTERVAL  (500)   //define the time interal(in milisecond) between each samples in the
                                                     //cablibration phase
#define         READ_SAMPLE_INTERVAL         (50)    //define how many samples you are going to take in normal operation
#define         READ_SAMPLE_TIMES            (5)     //define the time interal(in milisecond) between each samples in
                                                     //normal operation

/**********************Application Related Macros**********************************/
#define         GAS_CARBON_DIOXIDE           (9)
#define         GAS_CARBON_MONOXIDE          (3)
#define         GAS_ALCOHOL                  (4)
#define         GAS_AMMONIUM                 (10)
#define         GAS_TOLUENE                  (11)
#define         GAS_ACETONE                  (12)
//#define         accuracy                     (0)   //for linearcurves

typedef struct {
	ADC_HandleTypeDef *hadc1;

	float RS_air;

	float R0;

	float rs_ro_ratio;

	float gas_carbon_monoxide;
	float gas_carbon_dioxide;
	float gas_alchol;
	float gas_ammonium;
	float gas_toluene;
	float gas_acetone;
}mq135_t;


void init_mq135_sensor(mq135_t *mq135, ADC_HandleTypeDef *hadc1);

float calculate_res_mq135_sensor(uint16_t raw_adc);

uint16_t read_mq135_sensor_ADC(mq135_t *mq135);

void read_mq135_sensor(mq135_t *mq135);

#endif /* INC_MQ135_SENSOR_H_ */
