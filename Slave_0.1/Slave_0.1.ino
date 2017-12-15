//Libraries
#include <PID_v1.h>


//---INPUTS---

//Moisture Probes
const int moisture_One = A1;
int moisture_One_Val = 0;
const int moisture_Two = A2;
int moisture_Two_Val = 0;
const int moisture_Three = A3;
int moisture_Three_Val = 0;

//Temperature Sensor
const int temp_One = A4;
int temp_One_Val = 0;
const int temp_Two = A5;
int temp_Two_Val = 0;
const int temp_Three = A6;
int temp_Three_Val = 0;

//Air Temperature Sensor
const int temp_Air = A7;
int temp_Air_Val = 0;

//Light colour sensor
const int S0 = 19;
const int S1 = 20;
const int S2 = 21;
const int S3 = 22;
const int S_Out = 23;

int red_Freq = 0;
int green_Freq = 0;
int blue_Freq = 0;

double red_Colour = 0;
double red_Setpoint = 0;
double green_Colour = 0;
double green_Setpoint = 0;
double blue_Colour = 0;
double blue_Setpoint = 0;


//---OUTPUTS---

//Sprinklers
const int sprinkler_One = 18;
int sprinkler_One_Val = 0;
const int sprinkler_Two = 24;
int sprinkler_Two_Val = 0;
const int sprinkler_Three = 15;
int sprinkler_Three_Val = 0;

//Heater
const int heater = 11;
int heater_Val = 0;

//Emergancy Stop
const int E_Stop = 10;
volatile byte emergancy = LOW;

//RGB LEDs
const int red = 12;
int red_Val = 0;
const int green = 13;
int green_Val = 0;
const int blue = 14;
int blue_Val = 0;

//---OTHER---


double Kp = 0;
double Ki = 0;
double Kd = 0;

PID red_PID(red_Colour, red_Val, red_Setpoint, Kp, Ki, Kd, DIRECT);
PID green_PID(green_Colour, green_Val, green_Setpoint, Kp, Ki, Kd, DIRECT);
PID blue_PID(blue_Colour, blue_Val, blue_Setpoint, Kp, Ki, Kd, DIRECT);


void setup() {
  //Sprinklers
  pinMode(sprinkler_One, OUTPUT);
  pinMode(sprinkler_Two, OUTPUT);
  pinMode(sprinkler_Three, OUTPUT);

  //Heater
  pinMode(heater, OUTPUT);

  //Emergancy Stop
  pinMode(E_Stop,INPUT);
  attachInterrupt(25,emergancy_Stop, LOW);

  //RGB LEDs
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  //Light colour sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  pinMode(S_Out, INPUT);
  
  digitalWrite(S0,HIGH); //sets the frequency scaling to 20%
  digitalWrite(S1,LOW);


  red_PID.SetMode(AUTOMATIC);
  green_PID.SetMode(AUTOMATIC);
  blue_PID.SetMode(AUTOMATIC);
}

void loop() {
  

}

void colour_Check(){
  digitalWrite(S2,LOW); //set sensor to read red value
  digitalWrite(S3,LOW);

  red_Freq = pulseIn(S_Out,LOW); //Read red value
  red_Colour = map(red_Freq, 0,100,255,0); // maps red sensor output to standard RGB range **Change input values to map to within appropriate range after testing**
  delay(100);
  
  digitalWrite(S2,HIGH); //set sensor to read green value
  digitalWrite(S3,HIGH);

  green_Freq = pulseIn(S_Out,LOW); //Read red value
  green_Colour = map(green_Freq, 0,100,255,0); // maps green sensor output to standard RGB range **Change input values to map to within appropriate range after testing**
  delay(100);

  digitalWrite(S2,LOW); //set sensor to read blue value
  digitalWrite(S3,HIGH);

  blue_Freq = pulseIn(S_Out,LOW);
  blue_Colour = map(blue_Freq, 0,100,255,0); // maps blue sensor output to standard RGB range **Change input values to map to within appropriate range after testing**
  delay(100);

  //PID light control

  while (red_Colour != red_Setpoint) {
    red_PID.Compute();
  }
  while (green_Colour != green_Setpoint) {
    green_PID.Compute();
  }
  while (blue_Colour != blue_Setpoint) {
    blue_PID.Compute();
  }
}

void emergancy_Stop(){
  
}

