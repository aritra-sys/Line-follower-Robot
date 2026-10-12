void selectChannel(uint8_t channel) {
  digitalWrite(s0, bitRead(channel, 0));
  digitalWrite(s1, bitRead(channel, 1));
  digitalWrite(s2, bitRead(channel, 2));
  digitalWrite(s3, bitRead(channel, 3));
}

void readSensors() {
  for (uint8_t i = 0; i < sensor_number; i++) {
    long total = 0;

    selectChannel(i);
    delayMicroseconds(5);

    for (uint8_t j = 0; j < 10; j++) {
      total += analogRead(SIG);
    }

    sensors[i] = total / 10;
  }
}

void onLine(bool isBlackLower) {
  for (uint8_t i = 0; i < sensor_number; i++) {
    if (isBlackLower) {
      b[i] = sensors[i] < threshold[i];
    } else {
      b[i] = sensors[i] > threshold[i];
    }
  }
}