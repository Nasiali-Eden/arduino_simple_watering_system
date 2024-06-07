// Define the motor pin number
#define motor 7

// Declare variables
int soil_moisture;
float moisture_percentage;
const int Red = 8;
const int Green = 9;
int relay;

// Setup function runs once when the microcontroller starts up
void setup()
{
  // Set the motor pin as an output
  pinMode(motor, OUTPUT);
  // Set the Red and Green pins as outputs
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
}

// Main program loop
void loop()
{
  // Read the analog input from pin A0 (soil moisture sensor)
  soil_moisture = analogRead(A0);
  // Calculate the moisture percentage
  moisture_percentage = ((soil_moisture/876.00)*100);
  
  // Print the moisture percentage to the serial monitor
  Serial.print("The Percentage Moisture Value is: ");
  Serial.println(moisture_percentage);
  
  // Delay for 1 second
  delay(1000);
  
  // If the moisture percentage is greater than or equal to 70%
  if (moisture_percentage >=70)
  {
     // Set the relay value to 0
     relay = 0;
     // Set the motor speed to 0 (stop the motor)
     analogWrite(motor, relay);
     // Turn off the motor
     digitalWrite(motor, LOW);
     // Turn off the Red LED
     digitalWrite(Red, LOW);
     // Turn on the Green LED
     digitalWrite(Green, HIGH);
  }  
  // If the moisture percentage is less than 70%
  else
  {
      // Set the relay value to 40
      relay = 40;
      // Set the motor speed to 40 (start the motor)
      analogWrite(motor, relay);
      // Turn on the motor
      digitalWrite(motor, HIGH);
      // Turn on the Red LED
      digitalWrite(Red, HIGH);
      // Turn off the Green LED
      digitalWrite(Green, LOW);      
  }  
      
}


