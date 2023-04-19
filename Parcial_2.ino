const int LRD_PIN = A0; // Pin analógico utilizado para el sensor LRD
const int BOTON_PIN = 2; // Pin digital utilizado para el botón
const int LED_PIN = 6; // Pin digital utilizado para el LED
bool leerSensor = false; // Variable para indicar si se debe leer el sensor

void setup() {
  Serial.begin(9600);
  pinMode(BOTON_PIN, INPUT_PULLUP); // Se establece el pin del botón como entrada con resistencia pull-up interna
  pinMode(LED_PIN, OUTPUT); // Se establece el pin del LED como salida
}

void loop() {
  if (leerSensor) {
    int valor = analogRead(LRD_PIN);
    Serial.println(valor);
    if (valor < 100) { // Si el valor del LRD es menor a 100, se enciende el LED
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
  
  // Se lee el estado del botón y se cambia el valor de la variable leerSensor cuando se presiona el botón
  if (digitalRead(BOTON_PIN) == LOW) {
    delay(50); // Se añade un pequeño retraso para evitar lecturas erróneas debido a rebotes del botón
    leerSensor = !leerSensor;
  }
}
