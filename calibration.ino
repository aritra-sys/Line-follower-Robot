void resetCalibration() {
  for (uint8_t i = 0; i < sensor_number; i++) {
    sensorMin[i] = 1023;
    sensorMax[i] = 0;
  }
}

void updateCalibration() {
  readSensors();
  for (uint8_t i = 0; i < sensor_number; i++) {
    if (sensors[i] < sensorMin[i]) {
      sensorMin[i] = sensors[i];
    }
    if (sensors[i] > sensorMax[i]) {
      sensorMax[i] = sensors[i];
    }
  }
}

void calculateThreshold() {
  for (uint8_t i = 0; i < sensor_number; i++) {
    threshold[i] = (sensorMin[i] + sensorMax[i]) / 2;
  }
}

void calibrate() {
  resetCalibration();

  unsigned long startTime = millis();

  while (millis() - startTime < calibration_time) {
    motor(-calibration_speed, calibration_speed);
    updateCalibration();
  }

  stopMotor();
  calculateThreshold();
}
