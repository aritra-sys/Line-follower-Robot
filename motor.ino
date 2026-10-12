void motor(int16_t lmspeed, int16_t rmspeed) {
  lmspeed = constrain(lmspeed, -255, 255);
  rmspeed = constrain(rmspeed, -255, 255);

  digitalWrite(ain1, 0 <= lmspeed);
  digitalWrite(ain2, 0 > lmspeed);
  analogWrite(pwma, abs(lmspeed));

  digitalWrite(bin1, 0 <= rmspeed);
  digitalWrite(bin2, 0 > rmspeed);
  analogWrite(pwmb, abs(rmspeed));
}

void stopMotor(){
  motor(0,0);
}
