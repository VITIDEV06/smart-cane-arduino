const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int BUZZER_PIN = 6;
const int MOTOR_PIN = 5;

long duracion;
float distancia;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Enviar pulso ultrasónico
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Recibir el eco
  duracion = pulseIn(ECHO_PIN, HIGH, 30000);

  // Convertir a centímetros
  if (duracion == 0) {
    distancia = 999;
  } else {
    distancia = duracion * 0.0343 / 2;
  }

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Más de 100 cm
  if (distancia > 100) {

    noTone(BUZZER_PIN);
    digitalWrite(MOTOR_PIN, LOW);
    delay(100);

  // Entre 50 y 100 cm
  } else if (distancia > 50) {

    tone(BUZZER_PIN, 1000);
    digitalWrite(MOTOR_PIN, HIGH);

    delay(150);

    noTone(BUZZER_PIN);
    digitalWrite(MOTOR_PIN, LOW);

    delay(500);

  // Entre 20 y 50 cm
  } else if (distancia > 20) {

    tone(BUZZER_PIN, 1500);
    digitalWrite(MOTOR_PIN, HIGH);

    delay(150);

    noTone(BUZZER_PIN);
    digitalWrite(MOTOR_PIN, LOW);

    delay(200);

  // Menos de 20 cm
  } else {

    tone(BUZZER_PIN, 2000);
    digitalWrite(MOTOR_PIN, HIGH);

    delay(100);

    noTone(BUZZER_PIN);
    digitalWrite(MOTOR_PIN, LOW);

    delay(100);
  }
}