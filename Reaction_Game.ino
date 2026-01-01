
int BUT1 = D0;
int BUT2 = D1;
int BUT3 = D2;
int BUT4 = D3;

int LED1 = D4;
int LED2 = D5;
int LED3 = D6;
int LED4 = D7;

int wrongCount = 0;

void setup() {
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  pinMode(BUT4, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  if (wrongCount >= 3) {
    flashAll(3); 
    while (1);   
  }

  int flickers = random(1, 3); 
  int numLEDs = random(1, 4);  


  for (int f = 0; f < flickers; f++) {
    for (int i = 0; i < numLEDs; i++) {
      int led = random(1,5); 
      turnOnLED(led);
    }
    delay(300);
    allLEDsOff();
    delay(300);
  }


  bool pressed = digitalRead(BUT1)==LOW || digitalRead(BUT2)==LOW ||
                 digitalRead(BUT3)==LOW || digitalRead(BUT4)==LOW;

  if ((flickers == 1 && pressed) || (flickers == 2 && !pressed)) {
  
    delay(200);
  } else {
  
    wrongCount++;
    flashAll(wrongCount);
  }

  delay(500);
}



void turnOnLED(int led) {
  switch(led) {
    case 1: digitalWrite(LED1,HIGH); break;
    case 2: digitalWrite(LED2,HIGH); break;
    case 3: digitalWrite(LED3,HIGH); break;
    case 4: digitalWrite(LED4,HIGH); break;
  }
}

void allLEDsOff() {
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
}

void flashAll(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    digitalWrite(LED4,HIGH);
    delay(200);
    allLEDsOff();
    delay(200);
  }
}
