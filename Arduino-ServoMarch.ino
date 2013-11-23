#include <Servo.h>

#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_AS2 117
#define NOTE_C3  131
#define NOTE_D3  147
#define NOTE_DS3 156

Servo myservo;

int startServoPos = 20;
int rangeServoPos = 140;
int curServoPos = startServoPos;
int servoDirection = 1;
unsigned long nextTime = 3000;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(startServoPos);
  delay(2900);

}

int setSpeed(int _note) 
{
  int x = map(_note, 73,156,25,10);
  return x;
}


void runServo(int _tone, int _dur, int _delay)
{
  nextTime += _dur;
  Serial.print("_tone: ");
  Serial.print(_tone);
  Serial.print(", millis(): ");
  Serial.print(millis());
  Serial.print("ms, nextTime: ");
  Serial.println(nextTime);
  servoDirection *= -1;
  int tonedelay = setSpeed(_tone);
  while (nextTime > millis())
  {
    if (servoDirection > 0 && (curServoPos + 1) > (startServoPos + rangeServoPos))
    {
      servoDirection = -1;
    } 
    else if (servoDirection < 0 && (curServoPos - 1) < startServoPos)
    {
      servoDirection = 1;
    }

    curServoPos = curServoPos + 1 * servoDirection;
    myservo.write(curServoPos);
    delay(tonedelay);   
  }
}

void loop() {
  runServo(NOTE_G2, 600, 600);

  runServo(NOTE_G2, 600, 600);

  runServo(NOTE_G2, 600, 600);

  runServo(NOTE_DS2, 500, 500);

  runServo(NOTE_AS2, 150, 150);

  runServo(NOTE_G2, 600, 600);

  runServo(NOTE_DS2, 500, 500);

  runServo(NOTE_AS2, 150, 150);

  runServo(NOTE_G2, 1200, 1200);

  runServo(NOTE_D3, 600, 600);

  runServo(NOTE_D3, 600, 600);

  runServo(NOTE_D3, 600, 600);

  runServo(NOTE_DS3, 500, 500);

  runServo(NOTE_C3, 150, 150);

  runServo(NOTE_FS2, 600, 600);

  runServo(NOTE_D2, 500, 500);

  runServo(NOTE_AS2, 150, 150);

  runServo(NOTE_G2, 1200, 1200);
  
  nextTime += 5500;
  delay(5000);
}

