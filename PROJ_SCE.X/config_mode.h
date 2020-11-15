/* 
 * File:   config_mode.h
 * Author: joaom
 *
 * Created on November 15, 2020, 4:21 PM
 */

#ifndef CONFIG_MODE_H
#define	CONFIG_MODE_H

#ifdef	__cplusplus
extern "C" {
#endif


void conf_clock_hh(void);
void conf_clock_mm(void);
void conf_clock_ss(void);
void conf_alarm_hh(void);
void conf_alarm_mm(void);
void conf_alarm_ss(void);
void conf_temp(void);
void conf_lumin(void);
void conf_alarm_flag(void);


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_MODE_H */

