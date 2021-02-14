const int uvlys = 1;
const int varmelegeme = 2;
const int blaeser = 3;
const int variablemodstandIN = A2;
const int temperaturIN = A0;
const int sollysIN = A1;


void setup() {
  
pinMode(uvlys, OUTPUT);
pinMode(varmelegeme, OUTPUT);
pinMode(blaeser, OUTPUT);
pinMode(variablemodstandIN, INPUT);
pinMode(temperaturIN, INPUT);
pinMode(sollysIN, INPUT);
}

void loop() {
   
 int tempD = analogRead(temperaturIN);

 float tempV = tempD*(5.0/1023);

 float tempC = (tempV/0.0010) + 2.0;

 if (tempC <= 25) {
  digitalWrite(varmelegeme, HIGH);
  
 } else if (tempC >= 30) {
   digitalWrite(varmelegeme, LOW);
   digitalWrite(blaeser, HIGH);
   
 } else if (tempC <= 27) {
   digitalWrite(blaeser, LOW);
 }


  int variablemodstand = analogRead(variablemodstandIN);
  int lyssensor = analogRead(sollysIN);


 if (variablemodstand > lyssensor) {
   digitalWrite(uvlys, HIGH);
 } else {
   digitalWrite(uvlys, LOW);
 }



 
 






}
