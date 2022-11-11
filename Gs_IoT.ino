#define ledg1 13
#define ledr1 2
#define ledg2 4
#define ledr2 3
#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 10, A0, A1, A2, A3);

int vaga = 1;
int vaga1 = 1;
int vagas = vaga + vaga1;
int trigger = 5;
int echo = 6;
int trigger1 = 8;
int echo1 = 9;
float distancia;
float distancia1;

void setup() {
  Serial.begin(9600);
  pinMode(ledg1, OUTPUT);
  pinMode(ledr1, OUTPUT);
  pinMode(ledg2, OUTPUT);
  pinMode(ledr2, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(trigger1, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(echo1, INPUT);
  lcd.begin(16, 2);

}

void loop()
{  lcd.clear();

  
  	distancia = valorDistancia(trigger,echo);
  	distancia1 = valorDistancia(trigger1,echo1);

   	Serial.print(distancia);
  	Serial.println(" m");
   	Serial.print(distancia1);
  	Serial.println(" m");
  	delay(100);
 
 	lcd.setCursor(0, 0);
  	lcd.print("VAGAS LIVRES " );
  	lcd.setCursor(0, 1);
  	lcd.print("VAGAS OCUPADAS");
 
 	if(distancia > 2.00 && distancia1 >2.00){
  		digitalWrite(ledg1, HIGH);
      	digitalWrite(ledr1, LOW);
      	digitalWrite(ledg2, HIGH);
      	digitalWrite(ledr2, LOW);
      	lcd.setCursor(15, 0);
      	lcd.print(2);
      	lcd.setCursor(15, 1);
      	lcd.print(0);
    }else if(distancia > 2.00){
      	digitalWrite(ledg1, HIGH);
      	digitalWrite(ledr1, LOW);
      	digitalWrite(ledg2, LOW);
      	digitalWrite(ledr2, HIGH);
      	lcd.setCursor(15, 0);
      	lcd.print(1);
      	lcd.setCursor(15, 1);
      	lcd.print(1);
    }else if(distancia1 >2.00){
      	digitalWrite(ledg1, LOW);
      	digitalWrite(ledr1, HIGH);
      	digitalWrite(ledg2, HIGH);
      	digitalWrite(ledr2, LOW);
      	lcd.setCursor(15, 0);
      	lcd.print(1);
      	lcd.setCursor(15, 1);
      	lcd.print(1);
    }else{
		digitalWrite(ledg1, LOW);
      	digitalWrite(ledr1, HIGH);
      	digitalWrite(ledg2, LOW);
      	digitalWrite(ledr2, HIGH);
      	lcd.setCursor(15, 0);
      	lcd.print(0);
      	lcd.setCursor(15, 1);
      	lcd.print(2);
    }
 
  
  delay(5000);
  
  }

float valorDistancia(int trigger,int echo)
{  
  digitalWrite(trigger, HIGH); 
  digitalWrite(trigger, LOW);
  return  0.0001715 * pulseIn(echo, HIGH);

}