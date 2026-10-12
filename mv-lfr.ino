//Global variables
//Motor pins
const uint8_t ain1;  // Left motor backward
const uint8_t ain2;  // Left motor forward
const uint8_t pwma;  // Left motor PWM
const uint8_t bin1;  // Right motor backward
const uint8_t bin2;  // Right motor forward
const uint8_t pwmb;  // Right motor PWM
int leftMotorSpeed, RightMotorSpeed;

//Sensor pins - Multiplexor
const uint8_t s0;
const uint8_t s1;
const uint8_t s2;
const uint8_t s3;
const uint8_t SIG;  // MUX Signal pin

const uint8_t sensor_number = 14;
long sum, wSum;

uint16_t sensors[sensor_number];  //Sensor values
uint8_t b[sensor_number];
uint16_t sensorMin[sensor_number];
uint16_t sensorMax[sensor_number];
uint16_t threshold[sensor_number];
const int16_t weight[sensor_number] = { -6500, -5500, -4500, -3500, -2500, -1500, -500, 500, 1500, 2500, 3500, 4500, 5500, 6500 };

float position, error, previousError, correction,derivative;
float kp = 1, ki = 1, kd = 1;


bool isBlackLower = true;
int calibration_time = 5000;
int calibration_speed = 90;
int startTime;

void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(SIG, INPUT);

  pinMode(pwma, OUTPUT);
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(bin1, OUTPUT);
  pinMode(bin2, OUTPUT);
  pinMode(pwmb, OUTPUT);
}

void loop() {

}