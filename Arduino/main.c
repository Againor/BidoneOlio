const int echo = 8;
const int trig = 9;
const int pieno = 10;
const int vuoto = 20;
const int rosso = 11;
const int verde = 10;
 
void setup() {
  Serial.begin ( 9600 );
  pinMode ( echo, INPUT );
  pinMode ( trig, OUTPUT );
  pinMode ( rosso, OUTPUT);
  pinMode ( verde, OUTPUT);
}

void loop() {
  digitalWrite ( trig, LOW );
  digitalWrite ( trig, HIGH );
  delay ( 100 );
  digitalWrite ( trig, LOW );
  
  long time = pulseIn ( echo, HIGH );
  long distanza = 0.034 * time / 2;
  
  if ( distanza > 3000 ){
    Serial.println ( "Fuori Portata!" );
  } else if ( distanza > vuoto ){
    digitalWrite ( rosso, LOW );
    digitalWrite ( verde, HIGH );
    Serial.print ( distanza );
    Serial.println ( "cm   " );
  } else if ( distanza < vuoto && distanza > pieno ){
    digitalWrite ( rosso, HIGH );
    digitalWrite ( verde, HIGH );
    Serial.print ( distanza );
    Serial.println ( "cm   " );
  } else if ( distanza < pieno ){
    digitalWrite ( rosso, HIGH );
    digitalWrite ( verde, LOW );
    Serial.print ( distanza );
    Serial.println ( "cm   " );
  }
  delay(250); 
}
