/*A basic 6 channel transmitter using the nRF24L01 module.*/
/* Like, share and subscribe, ELECTRONOOBS */
/* http://www.youtube/c/electronoobs */

/* First we include the libraries. Download it from 
   my webpage if you donw have the NRF24 library */

#include <SPI.h>            
#include <Wire.h>
#include <EEPROM.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//OLED setup

#define XPOS 0
#define YPOS 1
#define DELTAY 2
#if (SSD1306_LCDHEIGHT != 64)
#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/*Create a unique pipe out. The receiver has to 
  wear the same unique code*/
  
const uint64_t pipeOut = 0xE8E8F0F0E1LL; //IMPORTANT: The same as in the receiver!!!

// The sizeof this struct should not exceed 32 bytes
// This gives us up to 32 8 bits channals
struct MyData {
  byte throttle;
  byte yaw;
  byte pitch;
  byte roll;
  byte AUX1;
  byte AUX2;
};

MyData data;



//Inputs outputs
int toggle_1 = 3; 
int toggle_2 = 2;
int throttle_in = A0;
int yaw_in = A1;
int pitch_in = A2;
int roll_in = A3;
int mode_in = 4;


//Variables
int throttle_fine = 0;
int yaw_fine = 0;
int pitch_fine = 0;
int roll_fine = 0;

int throttle_to_send = 0;
int yaw_to_send = 0;
int pitch_to_send = 0;
int roll_to_send = 0; 

bool throttle_inverted = false; 
bool yaw_inverted = true; 
bool pitch_inverted = true; 
bool roll_inverted = false; 

bool yaw_decrease = false;
bool throttle_decrease = false;
bool pitch_decrease = false;
bool roll_decrease = false;

bool yaw_increase = false;
bool throttle_increase = false;
bool pitch_increase = false;
bool roll_increase = false;

bool mode = true;

void resetData() 
{
  //This are the start values of each channal
  // Throttle is 0 in order to stop the motors
  //127 is the middle value of the 10ADC.
    
  data.throttle = 127;
  data.yaw = 127;
  data.pitch = 127;
  data.roll = 127;
  data.AUX1 = 0;
  data.AUX2 = 0;
}

void setup()
{
  if( EEPROM.read(1) != 55)
  {
    EEPROM.write(2, 127);
    EEPROM.write(3, 127);
    EEPROM.write(4, 127);
    EEPROM.write(5, 127); 
    EEPROM.write(6, 0);
    EEPROM.write(7, 1);
    EEPROM.write(8, 1);
    EEPROM.write(9, 0);    
    EEPROM.write(1, 55);
  }

  throttle_fine = EEPROM.read(2);
  yaw_fine = EEPROM.read(3);
  pitch_fine = EEPROM.read(4);
  roll_fine = EEPROM.read(5);
  throttle_inverted = EEPROM.read(6);
  yaw_inverted = EEPROM.read(7);
  pitch_inverted = EEPROM.read(8);
  roll_inverted = EEPROM.read(9);

  delay(2000);
  

}

/**************************************************/




int map_normal(int val, int lower, int middle, int upper, bool reverse)
{
  val = constrain(val, lower, upper);
  if ( val < middle )
    val = map(val, lower, middle, 0, 128);
  else
    val = map(val, middle, upper, 128, 255);
  return ( reverse ? 255 - val : val );
}





// Returns a corrected value for a joystick position that takes into account
// the values of the outer extents and the middle of the joystick range.
int map_exponential(int val, bool reverse)
{
  val = constrain(val, 0, 1023);
  float cube = ((pow((val - 512),3)/520200) + 258.012) / 2; 
  return ( reverse ? 255 - cube : cube );
}










void loop()
{

  //Mode select  
  if(!mode)
  {
  throttle_to_send = map_normal(analogRead(throttle_in), 0, 512, 1023, throttle_inverted);
  yaw_to_send = map_normal(analogRead(yaw_in), 0, 512, 1023,           yaw_inverted);
  pitch_to_send = map_normal(analogRead(pitch_in), 0, 512, 1023,       pitch_inverted);
  roll_to_send = map_normal(analogRead(roll_in), 0, 512, 1023,         roll_inverted);  
  }
  
  if(mode)
  {
  throttle_to_send = map_exponential(analogRead(throttle_in), throttle_inverted);
  yaw_to_send = map_exponential(analogRead(yaw_in),           yaw_inverted);
  pitch_to_send = map_exponential(analogRead(pitch_in),       pitch_inverted);
  roll_to_send = map_exponential(analogRead(roll_in),         roll_inverted);  
  }

  


  throttle_to_send = throttle_to_send  + throttle_fine - 127;
  yaw_to_send = yaw_to_send  + yaw_fine - 127;
  pitch_to_send = pitch_to_send  + pitch_fine - 127;
  roll_to_send = roll_to_send  + roll_fine - 127;  
  
  
  data.throttle = constrain(throttle_to_send,0,255);
  data.yaw      = constrain(yaw_to_send,0,255);
  data.pitch    = constrain(pitch_to_send,0,255);
  data.roll     = constrain(roll_to_send,0,255);
  data.AUX1     = digitalRead(toggle_1);
  data.AUX2     = digitalRead(toggle_2);



  
}
