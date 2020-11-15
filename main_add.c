#define PRESSED             1
#define NOT_PRESSED         0

#define T_MIN         		0
#define T_MAX         		50
#define L_MIN         		0
#define L_MAX         		7

void checkButtonS1(void);
void checkButtonS2(void);
void conf_clock_hh(void);
void conf_clock_mm(void);
void conf_clock_ss(void);
void conf_alarm_hh(void);
void conf_alarm_mm(void);
void conf_alarm_ss(void);
void conf_temp(void);
void conf_lumin(void);
void conf_alarm_flag(void);

//need to set custom name of RB4 to SWITCH_S1 & RC5 to SWITCH_S2 - DONE IN pin_manager_add.h



uint8_t state = 0;
//State= 0 normal mode.
//state=1 , blink h
//state=2, blink m
//state=3, blink s
//state=4, blink C
//State 5,6,7 alarm time change
//state 8, blink T
//state9, blink T value
//state 10 blink L
//state 11 blink Lvalue
//state 12 Blink Alarm


uint8_t btn1State = NOT_PRESSED;
uint8_t btn2State = NOT_PRESSED;    


void checkButtonS1(void) {
    if (btn1State == NOT_PRESSED) {
        if (SWITCH_S1_PORT == LOW) {
            __delay_ms(100);
            btn1State = PRESSED;
        }
    } else if (SWITCH_S1_PORT == HIGH) {
        btn1State = NOT_PRESSED;
    }
}

void checkButtonS2(void) {
    if (btn2State == NOT_PRESSED) {
        if (SWITCH_S2_PORT == LOW) {
            __delay_ms(100);
            btn2State = PRESSED;
        }
    } else if (SWITCH_S2_PORT == HIGH) {
        btn2State = NOT_PRESSED;
    }
}


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





void main(void){
	while(1){
		//update LCD
		checkButtonS1();
		checkButtonS2();

		switch(state){
			case 0:
				//normal mode
				if(btn1State == PRESSED){
					//if s1 pressed, go to conf.mode
					state = 1;
				}
				break;
			case 1:
				
				if(btn2State == PRESSED){
					//if s2 is pressed, change hours
					conf_clock_hh();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to minutes
					state = 2;
				}
				break;
			case 2:
				if(btn2State == PRESSED){
					//if s2 is pressed, change minutes
					conf_clock_mm();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to seconds
					state = 3;
				}
				break;
			case 3:
				if(btn2State == PRESSED){
					//if s2 is pressed, change seconds
					conf_clock_ss();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to alarm changes
					state = 4;
				}
				break;
			case 4:
				if(btn2State == PRESSED){
					//if s2 is pressed, go to next state - update hours
					state = 5;
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to state 8 - blinking T
					state = 8;
				}
				break;
			case 5:
				if(btn2State == PRESSED){
					//if s2 is pressed, change alarm hours
					conf_alarm_hh();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to alarm minutes
					state = 6;
				}
				break;
			case 6:
				if(btn2State == PRESSED){
					//if s2 is pressed, change alarm minutes
					conf_alarm_mm();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to alarm seconds
					state = 7;
				}
				break;
			case 7:
				if(btn2State == PRESSED){
					//if s2 is pressed, change alarm seconds
					conf_alarm_ss();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to blinking T
					state = 8;
				}
				break;
			case 8:
				if(btn2State == PRESSED){
					//if s2 is pressed, go to next state - update T value
					state = 9;
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to state 10 - blinking L
					state = 10;
				}
				break;
			case 9:
				if(btn2State == PRESSED){
					//if s2 is pressed, change temperature
					conf_temp();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to blinking L
					state = 10;
				}
				break;
			case 10:
				if(btn2State == PRESSED){
					//if s2 is pressed, go to next state - update L value
					state = 11;
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to state 12 - blinking A
					state = 12;
				}
				break;
			case 11:
				if(btn2State == PRESSED){
					//if s2 is pressed, change luminosity
					conf_lumin();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to blinking A
					state = 12;
				}
				break;
			case 12:
				if(btn2State == PRESSED){
					//if s2 is pressed, toggle or untoggle alarms
					conf_alarm_flag();
				}else if(btn1State == PRESSED){
					//else if s1 is pressed, go to state 0 - normal mode
					state = 0;
				}
				break;
		}
	}
}