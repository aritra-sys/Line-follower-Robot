void calculateError() {
  sum = 0;
  wSum = 0;
  for (uint8_t i = 0; i < sensor_number; i++) {
    wSum += (long)b[i] * weight[i];
    sum += b[i];
  }

  if (sum != 0) {
    position = (float)wSum / sum;
    error = position;
  }
}

void pid(float kp, float kd, float derivative) {
  correction = kp * error + kd * derivative;

  derivative = error - lastError;

  leftMotorSpeed = baseSpeed - correction;
  rightMotorSpeed = baseSpeed + correction;

  lastError = error;
}