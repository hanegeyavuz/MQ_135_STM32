
#include "mq135_sensor.h"
#include "math.h"


void init_mq135_sensor(mq135_t *mq135, ADC_HandleTypeDef *hadc1) {
	mq135->hadc1 = hadc1;

	// CALIBRATION
	mq135->RS_air = 0;
	mq135->R0 = 0;

	for (uint8_t i = 0; i < CALIBARAION_SAMPLE_TIMES; i++) {
		mq135->RS_air += calculate_res_mq135_sensor(read_mq135_sensor_ADC(mq135));
		HAL_Delay(100);
	}

	mq135->RS_air = mq135->RS_air / CALIBARAION_SAMPLE_TIMES;              //calculate the average value

	mq135->R0 = mq135->RS_air / RO_CLEAN_AIR_FACTOR_MQ135;                   //RS_AIR_val divided by RO_CLEAN_AIR_FACTOR yields the Ro
}

float calculate_res_mq135_sensor(uint16_t raw_adc)
{
  return (float)RL_VALUE_MQ135 * (4096 - raw_adc) / raw_adc;
}

uint16_t read_mq135_sensor_ADC(mq135_t *mq135) {

	HAL_ADC_Start(mq135->hadc1);
	HAL_ADC_PollForConversion(mq135->hadc1, HAL_MAX_DELAY);
	uint32_t adc_value = HAL_ADC_GetValue(mq135->hadc1);
	HAL_ADC_Stop(mq135->hadc1);
	return (uint16_t) adc_value;
}

void read_mq135_sensor(mq135_t *mq135) {


	mq135->rs_ro_ratio = calculate_res_mq135_sensor(read_mq135_sensor_ADC(mq135)) / mq135->R0;     //rs_ro_ratio

	mq135->gas_carbon_dioxide = (powf(10.0f,((-2.890f*(log10f(mq135->rs_ro_ratio))) + 2.055f)));   // CO2

	mq135->gas_carbon_monoxide  = (powf(10.0f,(1.457f*powf((log10f(mq135->rs_ro_ratio)), 2.0f) - 4.725f*(log10f(mq135->rs_ro_ratio)) + 2.855f)));

	mq135->gas_alchol = (powf(10.0f,((-3.181f*(log10f(mq135->rs_ro_ratio))) + 1.895f)));

	mq135->gas_ammonium = (powf(10.0f,((-2.469f*(log10f(mq135->rs_ro_ratio))) + 2.005f)));

	mq135->gas_toluene = (powf(10.0f,((-3.479f*(log10f(mq135->rs_ro_ratio))) + 1.658f)));

	mq135->gas_acetone = (powf(10.0f,(-1.004f*powf((log10f(mq135->rs_ro_ratio)), 2.0f) - 3.525f*(log10f(mq135->rs_ro_ratio)) + 1.553f)));



}
