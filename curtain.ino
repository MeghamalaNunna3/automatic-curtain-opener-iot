const int trigPin = 16;
const int echoPin = 17;
int m1 = 22;
int m2 = 23;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  Serial.begin(9600);
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
    // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance<50)
  {
   
    Serial.println("abstracle detected");
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    delay(2000);
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    delay(30000);
  }
  else
  {
    Serial.println("abstracle not detected");
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
  }
}
