#define PRESSED             1
#define NOT_PRESSED         0

#define T_MIN         		0
#define T_MAX         		50
#define L_MIN         		0
#define L_MAX         		7

//need to set custom name of RB4 to SWITCH_S1 & RC5 to SWITCH_S2


//uint8_t switchEvent = 0;
uint8_t btn1State = NOT_PRESSED;
uint8_t btn2State = NOT_PRESSED;    
//SWITCH_Sx_PORT ????

uint8_t nS1presses = 0;


void checkButtonS1(void) {
    if (btn1State == NOT_PRESSED) {
        if (SWITCH_S1_PORT == LOW) {
            __delay_ms(100);
            btn1State = PRESSED;
            nS1presses++;
        }
    } else if (SWITCH_S1_PORT == HIGH) {
        btn1State = NOT_PRESSED;
        //switchEvent = 1;
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
        //switchEvent = 1;
    }
}

void conf_clock_hh(void){
	while(1){
		//blink hh
		checkButtonS1();
		checkButtonS2();
		//for each press of S2
		if(btn2State == PRESSED){
			//if hours are 23 before, turn to 0
			//else increase clock hours
		}
		//if S1 is pressed, get out of cycle
    	if(btn1State == PRESSED){
    		return;
    	}
	}
}

void conf_clock_mm(void){
	while(1){
		//blink mm
		checkButtonS1();
		checkButtonS2();
		//if S1 is pressed, get out of cycle
    	if(btn1State == PRESSED){
    		return;
    	}
		//for each press of S2
		if(btn2State == PRESSED){
			//if minutes are 59 before, turn to 0
			//else increase clock minutes
		}
		
	}
}

void conf_alarm(void){
	while(1){
		//blink C
		//blink alarm time in space for clock
		checkButtonS1();
		checkButtonS2();
		//if S1 is pressed, get out of cycle
    	if(btn1State == PRESSED){
    		return;
    	}
    	if(btn2State == PRESSED){
    		//function for editing hh
    		//function for editing mm
    		//function for editing ss
    		return;
    	}

	}



	
	
	//first press of S2 starts hh blinking
	    //subsequent S2 presses increase alarm hours - ALAH
	    //if hours are 23 before, turn to 0
	    //pressing S1 makes mm blink - don't count nS1presses (or --)
	    //subsequent S2 presses increase alarm minutes - ALAM
	    //if minutes are 59 before, turn to 0
	    //pressing S1 makes ss blink - don't count nS1presses (or --)
	    //subsequent S2 presses increase alarm seconds - ALAS
	    //if seconds are 59 before, turn to 0
	    //next press of S1 gets out of cycle  
}


void conf_temp(void){
	while(1){
		//blink T
		//blink ALAT
		checkButtonS1();
		checkButtonS2();
		//if S1 is pressed, get out of cycle
    	if(btn1State == PRESSED){
    		return;
    	}
		//for each press of S2
		if(btn2State == PRESSED){
			if(ALAT == T_MAX){
				ALAT = T_MIN;
			}else{
				ALAT++;
			}
		}
		
	}

	//blink T
   	//for each press of S2, increase ALAT
	//if ALAT is over T_MAX -> ALAT = T_MIN
	//if S1 is pressed, get out of cycle
}


void conf_lumin(void){
	while(1){
		//blink L
		//blink ALAL
		checkButtonS1();
		checkButtonS2();
		//if S1 is pressed, get out of cycle
    	if(btn1State == PRESSED){
    		return;
    	}
		//for each press of S2
		if(btn2State == PRESSED){
			if(ALAL == L_MAX){
				ALAL = L_MIN;
			}else{
				ALAL++;
			}
		}
	}

	//blink L
   	//for each press of S2, increase ALAL
	//if ALAL is over L_MAX -> ALAL = L_MIN
	//if S1 is pressed, get out of cycle 
}




//FROM NORMAL OPERATION CYCLE
//CHECK S1 & IF PRESSED
//SWITCH TO CONFIGURATION MODE

void configuration_mode(void){
	while(1){
		//case switch from number of S1 presses
		//checking S1 happens inside each operation
		switch (nS1presses) {
        	case 1:     
         		conf_clock_hh();
           		break;
        	case 2:     
           		conf_clock_mm();     
           		break;
	        case 3:     
    	       	//blink ss ????   
        	   	break;
	        case 4:     
    	       	conf_alarm();
        	   	break;
			case 5:     
    	       	conf_temp();
        	   	break;
	        case 6:     
    	       	conf_lumin();
        	   	break;
	        case 7:     
    	      	//blink A
    	      	//for each press of S2, cycle between A = 1 and A = 0 
        	   	break;
	        case 8:     
    	       	//back to NORMAL MODE -> return
        	   	nS1presses = 0;
           		return;  
    	}
	}	
}