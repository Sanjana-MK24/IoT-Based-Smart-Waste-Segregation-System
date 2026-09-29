// Smart Waste Segregation System
// Arduino UNO
// HC-SR04 + Soil Moisture Sensor + Servo Motor

const int trigPin = 8;
const int echoPin = 9;
const int soilPin = A0;
const int servoPin = 6;

long duration;
int distance;
int soil;

// Move servo to required angle
void moveServoTo(int angle)
{
  angle = constrain(angle, 0, 180);

  int pulseWidth = map(angle, 0, 180, 500, 2500);

  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);

  delay(18);
}

void setup()
{
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(servoPin, OUTPUT);

  digitalWrite(trigPin, LOW);
  digitalWrite(servoPin, LOW);

  // Start servo at center
  moveServoTo(90);

  Serial.println("================================");
  Serial.println(" Smart Waste Segregation System");
  Serial.println("================================");
  Serial.println("System Ready");
}

void loop()
{
  // -----------------------------
  // Ultrasonic Sensor
  // -----------------------------

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0)
  {
    distance = 999;
  }
  else
  {
    distance = duration * 0.034 / 2;
  }

  // -----------------------------
  // Soil Moisture Sensor
  // -----------------------------

  soil = analogRead(soilPin);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");

  Serial.print(" | Moisture: ");
  Serial.println(soil);

  // -----------------------------
  // Waste Detection
  // -----------------------------

  if (distance < 15)
  {
    Serial.println("Waste Detected!");

    delay(500);

    soil = analogRead(soilPin);

    Serial.print("Moisture Value: ");
    Serial.println(soil);

    // -----------------------------
    // Wet Waste
    // -----------------------------

    if (soil < 950)
    {
      Serial.println("WET WASTE DETECTED");
      Serial.println("Servo moving to 45 degrees");

      moveServoTo(45);

      Serial.println("Wet waste directed.");
    }

    // -----------------------------
    // Dry Waste
    // -----------------------------

    else
    {
      Serial.println("DRY WASTE DETECTED");
      Serial.println("Servo moving to 135 degrees");

      moveServoTo(135);

      Serial.println("Dry waste directed.");
    }

    // Allow waste to fall
    delay(3000);

    // Return servo to center
    Serial.println("Returning servo to center");

    moveServoTo(90);

    Serial.println("Ready for next waste.");
    Serial.println("--------------------------------");

    delay(1000);
  }

  delay(500);
}