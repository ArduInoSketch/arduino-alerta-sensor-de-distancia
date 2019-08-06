//Link para uso da biblioteca NewPing
//https://drive.google.com/file/d/0B91L9po09u35c3EzOG9pOXBldVU/view
#include <NewPing.h>
#define trigger 6
#define echo 7
#define distance 40  //maxíma distância
NewPing sonar(trigger, echo, distance);
#define ledAlert 8
#define ledSafe 9
#define buz 10

void setup() {
  Serial.begin(115200);
  pinMode(ledAlert, OUTPUT);
  pinMode(ledSafe, OUTPUT);
  pinMode(buz, OUTPUT);
}

void loop () {
  int dist = sonar.ping_cm();
  Serial.print("DISTÂNCIA: ");
  Serial.print(dist);
  Serial.println("(cm)");

  if ((dist <= 20)  && (dist > 1)) {
    Serial.println("ALERTA!");
    digitalWrite(ledSafe, LOW);
    digitalWrite(ledAlert, HIGH);
    digitalWrite(buz, HIGH);
    delay(20);
    digitalWrite(ledAlert, LOW);
    digitalWrite(buz, LOW);
  } else {
    Serial.println("SEGURO!");
    digitalWrite(ledSafe, HIGH);
  }
}
