#include "mcc_generated_files/mcc.h"
#include "main.h"



void conf_clock_hh(void){
	if (CLKH == 23){
		CLKH = 0;
	}else{
		CLKH++;
	}

	return;
}

void conf_clock_mm(void){
	if (CLKM == 59){
		CLKM = 0;
	}else{
		CLKM++;
	}

	return;
}

void conf_clock_ss(void){
	timer_flag++;
	return;
}

void conf_alarm_hh(void){
	if (ALAH == 23){
		ALAH = 0;
	}else{
		ALAH++;
	}

	return;
}

void conf_alarm_mm(void){
	if (ALAM == 59){
		ALAM = 0;
	}else{
		ALAM++;
	}

	return;
}

void conf_alarm_ss(void){
	if (ALAS == 59){
		ALAS = 0;
	}else{
		ALAS++;
	}

	return;
}

void conf_temp(void){

	if(ALAT == T_MAX){
		ALAT = T_MIN;
	}else{
		ALAT++;
    }
	return;
}


void conf_lumin(void){

	if(ALAL == L_MAX){
		ALAL = L_MIN;
	}else{
		ALAL++;
	}

	return;
}

void conf_alarm_flag(void){

	if(ALAF == 0){
		ALAF = 1;
	}else{
		ALAF = 0;
	}

	return;
}
