/*********************************************************/
/* File that groups all settings specific for each setup */
/*********************************************************/
#ifndef __TRUCKONTROL_SETTINGS_H__
#define __TRUCKONTROL_SETTINGS_H__


// iBus
#define ch_motor          1
#define ch_servo          2
#define ch_aux_leftUp     3
#define ch_aux_leftTurn   4
#define ch_aux_knob1      5
#define ch_aux_knob2      6
#define ch_aux_tristate1  7
#define ch_aux_tristate2  8
#define ch_aux_bistate1   9
#define ch_aux_bistate2  10

#define ch_lights 7

// I2C
#define i2cMasterAddress 1
#define pin_reloadDevices 2 // Interruption on that pin

// Tractor
#define p_motor 5
#define p_servo 6
#define p_lights 7


#endif //__TRUCKONTROL_SETTINGS_H__
