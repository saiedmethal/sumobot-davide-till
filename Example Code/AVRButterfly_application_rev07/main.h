//Revisions number
#define SWHIGH  0
#define SWLOW   7

// main.h

void Initialization(void);
unsigned char StateMachine(char state, unsigned char stimuli);
char BootFunc(char input);
char PowerSaveFunc(char input);
char AutoPower(char input);
void Delay(unsigned int millisec);
char Revision(char input);
void OSCCAL_calibration(void);

#define BOOL    char

#define FALSE   0
#define TRUE    (!FALSE)
#define NULL    0

#define AUTO    3

// Macro definitions
#define sbi(port,bit)  (port |= (1<<bit))   //set bit in port
#define cbi(port,bit)  (port &= ~(1<<bit))  //clear bit in port

// Menu state machine states
#define ST_AVRBF                        10
#define ST_AVRBF_REV                    11
#define ST_TIME                         20
#define ST_TIME_CLOCK                   21
#define ST_TIME_CLOCK_FUNC              22
#define ST_TIME_CLOCK_ADJUST            23
#define ST_TIME_CLOCK_ADJUST_FUNC       24
#define ST_TIME_CLOCKFORMAT_ADJUST      25
#define ST_TIME_CLOCKFORMAT_ADJUST_FUNC 36
#define ST_TIME_DATE                    27
#define ST_TIME_DATE_FUNC               28
#define ST_TIME_DATE_ADJUST             29
#define ST_TIME_DATE_ADJUST_FUNC        30
#define ST_TIME_DATEFORMAT_ADJUST       31
#define ST_TIME_DATEFORMAT_ADJUST_FUNC  32
#define ST_MUSIC                        40
#define ST_SOUND_MUSIC                  41
#define ST_MUSIC_SELECT                 42
#define ST_MUSIC_PLAY                   43
#define ST_VCARD                        50
#define ST_VCARD_FUNC                   51
#define ST_VCARD_NAME                   52
#define ST_VCARD_ENTER_NAME             53
#define ST_VCARD_ENTER_NAME_FUNC        54
#define ST_VCARD_DOWNLOAD_NAME          55
#define ST_VCARD_DOWNLOAD_NAME_FUNC     56
#define ST_TEMPERATURE                  60
#define ST_TEMPERATURE_FUNC             61
#define ST_VOLTAGE                      70
#define ST_VOLTAGE_FUNC                 71
#define ST_LIGHT                        80
#define ST_LIGHT_FUNC                   81
#define ST_OPTIONS                      90
#define ST_OPTIONS_DISPLAY              91
#define ST_OPTIONS_DISPLAY_CONTRAST     92
#define ST_OPTIONS_DISPLAY_CONTRAST_FUNC 93
#define ST_OPTIONS_BOOT                 94
#define ST_OPTIONS_BOOT_FUNC            95
#define ST_OPTIONS_POWER_SAVE           96
#define ST_OPTIONS_POWER_SAVE_FUNC      97
#define ST_OPTIONS_AUTO_POWER_SAVE      98
#define ST_OPTIONS_AUTO_POWER_SAVE_FUNC 99


//Button definitions

#define KEY_NULL    0
#define KEY_ENTER   1
#define KEY_NEXT    2
#define KEY_PREV    3
#define KEY_PLUS    4
#define KEY_MINUS   5
