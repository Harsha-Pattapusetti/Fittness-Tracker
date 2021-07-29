#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;
int squatCount, jjCount, puCount, suCount, exercise;

int checkExercise()
 {
  X = CircuitPlayground.motionX(); // Store Coordinates
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  if ((abs(Y) < 5) && (Z < -6) && (X < -10) && (X > -15)) // Look for squat threshold coordinates
    {
      squatCount += 1; // Increment squat count and print out
      Serial.print("Squat: ");
      Serial.println(squatCount);
      delay(300); // Make sure exercise isn't counted multiple times
      return 0;
    }
  else if((Y > 0) && (X < -15)) // Look for jumping jack threshold coordinates
    {
      jjCount += 1; // Increment jumping jack count and print out
      Serial.print("Jumping Jack: ");
      Serial.println(jjCount);
      delay(600); // Make sure exercise isn't counted multiple times
      return 1;
    }
   else if((Z < -11) && (X > 3) && (Y < -1)) // Look for push-up threshold coordinates
    {
      puCount += 1; // Increment push-up count and print out
      Serial.print("Push-up: ");
      Serial.println(puCount);
      delay(600); // Make sure exercise isn't counted multiple times
      return 2;
    }
   else if((Z > 7) && (Y < 0) && (X > -1)) // Look for sit-up threshold coordinates
    {
      suCount += 1; // Increment sit-up count and print out
      Serial.print("Sit-up: ");
      Serial.println(suCount);
      delay(500); // Make sure exercise isn't counted multiple times
      return 3;
    }
   else { // Don't do anything if no exercises are detected
    return 4;
   }
 }

 void updateNeopixel(int exerciseType, int count)
  {
    if((count >= 0) && (count <= 7)) // Changing color from Red to yellow when exercise count is low
     {
      CircuitPlayground.setPixelColor(exerciseType, 255, int(36*count), 0);
     }
    else if ((count > 8) && (count <= 14)) // Changing color from yellow to green when exercise count is nearing 15
     {
      CircuitPlayground.setPixelColor(exerciseType, 255 - 36*count, 255, 0);
     }
    else // Change color to solid green when exercise count has reached 15
     {
      CircuitPlayground.setPixelColor(exerciseType, 0, 255,   0);
     }
  }

void resetCount() // Reset LED colors and all exercise counts
 {
  CircuitPlayground.clearPixels();
  squatCount = 0;
  jjCount = 0;
  puCount = 0;
  suCount = 0;
 }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Initialize serial monitor, clear LED colors, and exercise count.
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  squatCount = 0;
  jjCount = 0;
  puCount = 0;
  suCount = 0;
}

void loop() {
  // put your main code here, to run repeatedly:  
  if (CircuitPlayground.leftButton()) // Reset LEDs and exercise count if button is pressed
    {
      resetCount();
    }
  exercise = checkExercise(); // Store exercise measurement
  if(exercise == 0) // Update Squat LED if squat exercise is detected
    {
      updateNeopixel(0, squatCount);
    }
   else if(exercise == 1) // Update jumping jack LED if jumping jack is detected
    {
      updateNeopixel(1, jjCount);
    }
   else if(exercise == 2) // Update push-up LED if push-up is detected
    {
      updateNeopixel(2, puCount); 
    }
   else if(exercise == 3) // Update sit-up LED if sit-up is detected
    {
      updateNeopixel(3, suCount);
    }
   else{ // Don't do anything if none of the above are detected
   }
   
   exercise = 4; // No exercise detected
   
  delay(200);
}
