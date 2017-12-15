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




void setup() {
  pinMode(sprinkler_One, OUTPUT);
  pinMode(sprinkler_Two, OUTPUT);
  pinMode(sprinkler_Three, OUTPUT);

  pinMode(heater, OUTPUT);

  pinMode(E_Stop,INPUT);
  attachInterrupt(25,emergancy_Stop, LOW);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
