
// ENGR 385
// MPU-6050 Short Example Sketch
// This example code was provided by Arduino user JohnChi.
// The added code was created by Zack McConnell, Edy Gomez, and Kevin Gonzalez.
//
// The code is used to control the MPU-6050 device, turn on indicator LEDs, and display the
// temperature reading on 7-segment displays.

#include<Wire.h>
const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;


// This portion was used for the first part of our lab. We made LEDs light up when the x and y axis of the gyroscope changed.
/*int xled = 8;
  int yled = 9;
  int templed = 10;*/

// Pins for Display 1 will always be high. It will always display a 3.

// Variables that hold pins for Display 2.
int a2 = 17;
int b2 = 1;
int c2 = 3;
int d2 = 4;
int e2 = 5;
int f2 = 6;
int g2 = 7;

// Variables that hold pins for Display 3.
int a3 = 9;
int b3 = 10;
int c3 = 11;
int d3 = 12;
int e3 = 14;
int f3 = 15;
int g3 = 16;




void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);

  /*pinMode(xled, OUTPUT);
    pinMode(yled, OUTPUT);
    pinMode(templed, OUTPUT);*/

  // Setting Display 2 pins as outputs.

  pinMode(a2 , OUTPUT);
  pinMode(b2 , OUTPUT);
  pinMode(c2 , OUTPUT);
  pinMode(d2 , OUTPUT);
  pinMode(e2 , OUTPUT);
  pinMode(f2 , OUTPUT);
  pinMode(g2 , OUTPUT);

  // Setting Display 3 pins as outputs.

  pinMode(a3 , OUTPUT);
  pinMode(b3 , OUTPUT);
  pinMode(c3 , OUTPUT);
  pinMode(d3 , OUTPUT);
  pinMode(e3 , OUTPUT);
  pinMode(f3 , OUTPUT);
  pinMode(g3 , OUTPUT);

}
void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true); // request a total of 14 registers
  AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX = Wire.read() << 8 | Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY = Wire.read() << 8 | Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ = Wire.read() << 8 | Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  /*if(GyX < 500 && GyX > -500) {
    digitalWrite(xled, LOW);
    } else {
    digitalWrite(xled, HIGH);
    }

    if(GyY < 500 && GyY > -500) {
    digitalWrite(yled, LOW);
    } else {
    digitalWrite(yled, HIGH);
    }

    if (Tmp/340.00+36.53 >= 35) {
    digitalWrite(templed, HIGH);
    } else {
    digitalWrite(templed, LOW);

    }*/

  // Extracts the needed digit to corectly display the number on the display.
  int displayTemp = (Tmp / 340.00 + 36.53) - 30;
  int displayDecimal = ((Tmp / 340.00 + 36.53) * 10) - (Tmp / 340.00 + 36.53 + 300);

  if (displayTemp == 0) {
    displayZero();
  } else if (displayTemp == 1) {
    displayOne();
  } else if (displayTemp == 2) {
    displayTwo();
  } else if (displayTemp == 3) {
    displayThree();
  } else if (displayTemp == 4) {
    displayFour();
  } else if (displayTemp == 5) {
    displayFive();
  } else if (displayTemp == 6) {
    displaySix();
  } else if (displayTemp == 7) {
    displaySeven();
  } else if (displayTemp == 8) {
    displayEight();
  } else if (displayTemp == 9) {
    displayNine();
  }



  //Serial.print("AcX = "); Serial.print(AcX);
  //Serial.print(" | AcY = "); Serial.print(AcY);
  //Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp / 340.00 + 36.53); //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.println(GyY);
  //Serial.print(" | GyZ = "); Serial.println(GyZ);
  delay(333);
}

// These funtions display each different number on the display.
void displayOne() {
  // Display a 1.
  digitalWrite(a2, LOW);
  digitalWrite(b2, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
}

void displayTwo() {
  // Display a 2.
  digitalWrite(a2, HIGH);
  digitalWrite(b2, HIGH);
  digitalWrite(c2, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, LOW);
  digitalWrite(g2, HIGH);
}

void displayThree() {
  // Display a 1.
  digitalWrite(a2, HIGH);
  digitalWrite(b2, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, HIGH);
}

void displayFour() {
  // Display a 1.
  digitalWrite(a2, LOW);
  digitalWrite(b2, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, HIGH);
}

void displayFive() {
  // Display a 1.
  digitalWrite(a2, HIGH);
  digitalWrite(b2, LOW);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, LOW);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, HIGH);
}

void displaySix() {
  // Display a 1.
  digitalWrite(a2, HIGH);
  digitalWrite(b2, LOW);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, HIGH);
}

void displaySeven() {
  // Display a 1.
  digitalWrite(a2, HIGH);
  digitalWrite(b2, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
}

void displayEight() {
  // Display a 1.
  digitalWrite(a2, HIGH);
  digitalWrite(b2, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, HIGH);
}

void displayNine() {
  // Display a 1.
  digitalWrite(a2, HIGH);
  digitalWrite(b2, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, LOW);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, HIGH);
}

void displayZero() {
  // Display a 1.
  digitalWrite(a2, HIGH);
  digitalWrite(b2, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, LOW);
}



