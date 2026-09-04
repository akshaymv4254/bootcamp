int soilSensor = A0;

int BlueLED = 8;
int blueLED = 9;

int dryThreshold = 600;

void setup() {
  Serial.begin(9600);

  pinMode(BlueLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {

  int soilValue = analogRead(soilSensor);

  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  if (soilValue > dryThreshold) {

    // Soil is dry
    digitalWrite(blueLED, HIGH);
    digitalWrite(BlueLED, LOW);

    Serial.println("SOIL IS DRY");
  }
  else {

    // Soil is wet
    digitalWrite(blueLED, LOW);
    digitalWrite(BlueLED, HIGH);

    Serial.println("SOIL IS WET");
  }

  delay(1000);
}