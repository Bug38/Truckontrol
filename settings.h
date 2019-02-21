/*********************************************************/
/* File that groups all settings specific for that setup */
/*********************************************************/
#ifndef __TRUCKONTROL_SETTINGS_H__
#define __TRUCKONTROL_SETTINGS_H__

// iBus channels (settings from RC controller)
#define ch_R_UpDown         0
#define ch_L_UpDown         1
#define ch_R_LeftRight      2
#define ch_L_LeftRight      3
#define ch_VRA              4
#define ch_VRB              5
#define ch_SWA              6
#define ch_SWB              7
#define ch_SWC              8
#define ch_SWD              9

#define MIN_CHANNEL_VALUE   1000
#define MED_CHANNEL_VALUE   1500
#define MAX_CHANNEL_VALUE   2000

// Tractor channels
#define ch_motor            ch_L_UpDown
#define ch_gearbox          ch_SWC
// #define ch_direction        ch_SWD
#define ch_servo            ch_R_LeftRight
#define ch_lights           ch_SWA

// Tractor wiring
#define p_motor             5
#define p_servo             6
#define p_lights            7
#define p_reverseLights     8

// I2C
#define i2cMasterAddress    1
#define pin_rescanDevices   2 // Interruption on that pin

#endif //__TRUCKONTROL_SETTINGS_H__
