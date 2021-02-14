// Temperatursensor
const int analogINtemp = A0;

//Kontakt der afgør om vinduet er åbent
const int aabentvinduekontakt = 2;

//Kontakt der afgør om vinduet er lukket.
const int lukketvinduekontakt = 4;

//Motor der åbner vinduet.
const int motoraabnervinduet = 7;

//Motor der lukker vinduet.
const int motorlukkervinduet = 12;

//Elektronisk lås, som låser vinduet når det er lukket.
const int laas = 8;

void setup() {
  // Her definerer vi PIN-typen.
  Serial.begin(9600);
  pinMode(analogINtemp, INPUT);
  pinMode(aabentvinduekontakt, INPUT);
  pinMode(lukketvinduekontakt, INPUT);
  pinMode(motoraabnervinduet, OUTPUT);
  pinMode(motorlukkervinduet, OUTPUT);
}

void loop() {

  //aflæser digital værdi fra temp sensor.
  int digtalvaluefromtemp = analogRead(analogINtemp);

  //printer digitalværdi fra temp sensor.
  //Serial.println("Digitalværdi: " + String(digtalvaluefromtemp));

  //omdanner digital værdi til spænding.
  float voltagetempsensor = digtalvaluefromtemp * (5.0 / 1023.0);

  //printer spænding fra temp sensor.
  //Serial.println("Spænding fra tempsensor: " + String(voltagetempsensor));


  //omdanner spænding til temperatur.
  int temperatur = (voltagetempsensor / 0.15) + 2.0;

  //printer temperatur fra temp sensor.
  Serial.println("Temperatur: " + String(temperatur));
  delay(2000);

  // læs værdien fra knapperne, og omskriv til forståelige værdier.
  int vindueaabent = digitalRead(aabentvinduekontakt);
  int vinduelukket = digitalRead(lukketvinduekontakt);

  //eksemplet antager at vinduet er lukket fra start.

  // Hvis temperaturen er over 25 grader, og vinduet samtidig er lukket, så åbnes vinduet.
  if (temperatur > 25 && vindueaabent == LOW) {
    digitalWrite(laas, LOW);
    delay(500);
    Serial.println("Låsen låses op");
    Serial.println("Vinduet åbner");
    digitalWrite(motorlukkervinduet, LOW);
    digitalWrite(motoraabnervinduet, HIGH);

    // Her er vinduet blevet åbnet helt op, fordi det rammer knappen ved endestationen. Knappen går HIGH.
  } else if (temperatur > 23 && vindueaabent == HIGH) {
    Serial.println("Vinduet er helt åbent");
    digitalWrite(motoraabnervinduet, LOW);
    digitalWrite(motorlukkervinduet, LOW);

    // Vinduet påbegynder lukning når det er under 23 grader, med forudsætning om at vinduet er åbent.
  } else if (temperatur < 23 && vinduelukket == LOW ) {
    Serial.println("Vinduet lukker, der er under 23 grader i huset.");
    digitalWrite(motorlukkervinduet, HIGH);
    digitalWrite(motoraabnervinduet, LOW);

    // For at sikre at vinduet lukker og låser, skal den låse hvis vinduelukket kontakt går HØJ, og temperaturen er under 25 grader.
  } else if (temperatur < 25 && vinduelukket == HIGH) {
    digitalWrite(laas, HIGH);
    Serial.println("Låsen låses");
    Serial.println("Vinduet er lukket nu.");
    digitalWrite(motorlukkervinduet, LOW);
    digitalWrite(motoraabnervinduet, LOW);

  } else {
    Serial.println("Deer sker ingennting, optimal temp i rummet, mellem 23 og 25 grader");
  }

















}
