#include<NewPing.h>
#include<LowPower.h>

#define echo  8;
#define trig  9;
#define pieno 200;
#define vuoto 2
#define rosso 11;
#define verde 10;

NewPing sonar(trig, echo, pieno);
void setup() {
  Serial.begin(9600);
}

void loop() {
    int distanza = sonar.ping() / US_ROUNDTRIP_CM;
    if ( distanza > 3000 ){
        Serial.println ( "Fuori Portata!" );
    } else if ( distanza > vuoto ){
        digitalWrite(rosso, LOW);
        digitalWrite(verde, HIGH);
    } else if ( distanza < vuoto && distanza > pieno ){
        digitalWrite(rosso, HIGH);
        digitalWrite(verde, HIGH);
    } else if ( distanza < pieno ){
        digitalWrite(rosso, HIGH);
        digitalWrite(verde, LOW);
    }
    Serial.println(distanza + " cm");
    //1h = 3600s / 8s = 450
    //TODO Trovare un modo migliore di far diminuire la corrente nello sleep
    for(int i; i < 450; i++){
        LowPower.powerDown(SLEEP_8S, ADC_CONTROL_OFF, BOD_OFF);
    }
}
