#include <LiquidCrystal.h>
#include "DHT.h"

// DHT SETUP
#define DHTPin 2
#define DHTTYPE DHT11
DHT dht(DHTPin, DHT11);

// LCD SETUP
LiquidCrystal lcd(7, 6, 12, 10, 9, 8); // LCD

const int lightSensorPin = A0;

const int redLedPin     = 11;
const int yellowLedPin  = 4; 
const int greenLedPin   = 13;
const int buzzerPin     = 5;

const int deltaUmid = 15;
const int minUmid   = 50;
const int maxUmid   = 70;

const int deltaTemp = 15;
const int minTemp   = 10;
const int maxTemp   = 15;

// Função para calcular a média móvel de um conjunto de valores
void MediaMovel(float *Array, float Valor, float &Original) {
  if(Original == -99) {
    Original = Valor;
    return;
  }

  int count = 0;
  int availableIndex = -1;
  for (int i = 0; i < 10; i++) {
    if (Array[i] != 0) {
      count += 0; 
    } else if (Array[i] == 0) {
      availableIndex = i;
      break;
    }
  }

  if(availableIndex >= 0) {
    Array[availableIndex] = Valor;
    return;
  }

  float soma = 0;
  for (int i = 0; i < 10; i++) {
    soma += Array[i];
    Array[i] = 0;
  }

  Original = soma / 10;
}

// Variáveis para armazenar as médias móveis de umidade e temperatura
float umidMed = -99;
float umidArray[10] = {};
float tempMed = -99;
float tempArray[10] = {};

// Função para ler os dados do sensor DHT22 e calcular as médias móveis
void DHTread() {
  float hu = dht.readHumidity();
  float te = dht.readTemperature();

  MediaMovel(umidArray, hu, umidMed);
  MediaMovel(tempArray, te, tempMed);
}

// Variáveis para armazenar a média móvel de luminosidade do ambiente
float abntMed = -99;
float abntArray[10] = {};

// Função para ler os dados do sensor de luz e calcular a média móvel
void AMBread() {
  const float amb = map(analogRead(lightSensorPin), 1015, 8, 0, 100);
  MediaMovel(abntArray, amb, abntMed);
}

// Função para configurar o cursor do LCD e exibir uma mensagem
void LCDset(String Str, int posX, int posY) {
  lcd.setCursor(posX, posY);
  lcd.print(Str);
}

// Array para declarar os pinos dos LEDs
const int declareLED[] = {greenLedPin, yellowLedPin, redLedPin};
int activeLED = 0;

// Função para acionar os LEDs com base no estado recebido
void LEDread(int State) {
  if(State == activeLED) {
    return;
  }
  if (activeLED != 0) {
    digitalWrite(declareLED[activeLED - 1], LOW);
  }
  digitalWrite(declareLED[State - 1], HIGH);
  activeLED = State;
}

// Função para acionar o buzzer com base no estado recebido
void BUZZERread(int State) {
  int toneset = 0;
  if(State == 2) {
    const bool recall = sin(millis() / 150) > .4;
    if(recall) {
      toneset = 1300;
    }
  } else if(State == 3) {
    const bool recall = sin(millis() / 50) > .3;
    if(recall) {
      toneset = 1500;
    } else {
      toneset = 900;
    }
  }
  if(toneset == 0) {
    noTone(buzzerPin);
  } else {
    tone(buzzerPin, toneset);
  }
}

// Função para mover uma mensagem da esquerda para a direita no LCD
void LeftToRight(int posy, char frase[]) {
  int extend = 1;

  lcd.setCursor(0, posy);
  for(int i = -strlen(frase); i < 17; i++) {
    
    if(i >= 0) {
   	
    if(i >= extend) {
      lcd.setCursor(i - extend, posy);
      lcd.print(" ");
    } else {
      lcd.setCursor(16 - (extend - i), posy);
      lcd.print(" ");
    }
    lcd.setCursor(i, posy);
    lcd.print(frase);
    }
    
    else {
      lcd.setCursor(0, posy);
      int size = strlen(frase);
      lcd.print(String(frase).substring(i * -1, size));
    }
    
    delay(120);
  };
}

// Configurações iniciais do sistema
void setup() {
  Serial.begin(115200);

  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  noTone(buzzerPin);

  lcd.begin(16, 2);
  dht.begin();

  // Início da apresentação no LCD
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("- Bit Wise -");
  LeftToRight(1, "Building your Future");
  lcd.clear();
}

// Variáveis para controlar o ciclo de atualização
const int maxCycles = 3;
const char cycles[] = {'T', 'U', 'A'};
int arrayCycle = 0;
unsigned long lastCycle = 0;

// Loop principal do sistema
void loop() {
  DHTread();
  AMBread();

  int umidStatus = 1;
  int tempStatus = 1;
  int abntStatus = 1;

  // Verifica o estado da umidade
  const char *umidReplicate = "ADEQUADA";
  if(umidMed <= (minUmid - deltaUmid) || umidMed >= (maxUmid + deltaUmid)) {
    umidReplicate = (umidMed <= minUmid - deltaUmid) ? "MUITO BAIXA" : "MUITO ALTA";
    umidStatus = 3;
  } else if(umidMed <= (minUmid) || umidMed >= (maxUmid)) {
    umidReplicate = (umidMed <= minUmid) ? "BAIXA" : "ALTA";
    umidStatus = 2;
  }

  // Verifica o estado da temperatura
  const char *tempReplicate = "ADEQUADA";
  if(tempMed <= (minTemp - deltaTemp) || tempMed >= (maxTemp + deltaTemp)) {
    tempReplicate = (tempMed <= minTemp - deltaTemp) ? "MUITO BAIXA" : "MUITO ALTA";
    tempStatus = 3;
  } else if(tempMed <= (minTemp) || tempMed >= (maxTemp)) {
    tempReplicate = (tempMed <= minTemp) ? "BAIXA" : "ALTA";
    tempStatus = 2;
  }

  // Verifica o estado do ambiente
  if(abntMed > 60) {
    abntStatus = 3;
  } else if(abntMed > 30) {
    abntStatus = 2;
  }

  // Atualiza o ciclo de exibição no LCD
  if (millis() - lastCycle > 2500) {
    lastCycle = millis();

    char curr = cycles[arrayCycle];
    lcd.clear();
    if(curr == 'T') {
      LCDset("TEMP. ", 0, 0);
      lcd.print(tempReplicate);
      LCDset("Temperatura: ", 0, 1);
      lcd.print(String(round(tempMed)) + 'c');
    } else if(curr == 'U') {
      LCDset("UMID. ", 0, 0);
      lcd.print(umidReplicate);
      LCDset("Umidade: ", 0, 1);
      lcd.print(String(round(umidMed)) + '%');
    } else if(curr == 'A') {
      LCDset("ABNT. ", 0, 0);
      if(abntStatus == 1) {
        lcd.print("ADEQUADO");
      } else if(abntStatus == 2) {
        lcd.print("CLARO");
      } else if(abntStatus == 3) {
        lcd.print("MUITO CLARO");
      }
      LCDset("Ambiente: ", 0, 1);
      lcd.print(String(round(abntMed)) + '%');
    }

    arrayCycle++;
    if (arrayCycle >= sizeof(cycles)) {
      arrayCycle = 0;
    }
  }

  // Exibe as informações no monitor serial
  Serial.print("Temp: " + String(tempMed) + "°c | Umid: " + String(umidMed) + "% | Abnt: " + String(abntMed) + "%");
  Serial.println("");
  const int visual = max(max(umidStatus, tempStatus), abntStatus);

  // Atualiza os LEDs e o buzzer com base no estado das condições
  LEDread(visual);
  BUZZERread(visual);

  delay(150);
}