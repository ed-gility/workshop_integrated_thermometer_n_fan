float tempC;
int sensor_voltage;
int tempPin = 0;
int fanPin = 7;

void setup() {
  analogReference( INTERNAL );
  pinMode( fanPin, OUTPUT );
  Serial.begin( 9600 );
}

void loop() {
  sensor_voltage = analogRead(tempPin);
  tempC = sensor_voltage / 9.31;
  if ( tempC > 27.0) {
    // Ensure Fan is on (on be default for plant safety)
    digitalWrite( fanPin, LOW );  // LOW is on because we wire normally closed (plant safety)
  } else {
    // turn fan off
    digitalWrite( fanPin, HIGH );  
  }
  
  Serial.println(tempC);
  delay(1000);
}
