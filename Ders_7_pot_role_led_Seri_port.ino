const int analogPin = A0;   // Analog giriş (potansiyometre/sensör)
const int ledPin = 5;       // PWM çıkışı (LED için)
const int rolePin = 7;      // Dijital çıkış (Röle kontrol)

int okunanDeger = 0;        // A0'dan okunan değer
int parlaklik = 0;          // PWM değeri (0 - 255)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(rolePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  okunanDeger = analogRead(analogPin);         // 0 - 1023
  parlaklik = map(okunanDeger, 0, 1023, 0, 255); // PWM'e ölçekleme

  // Röle kontrolü: 600 <= değer <= 700 aralığında aktif
  if (okunanDeger >= 600 && okunanDeger <= 700) 
  {
    digitalWrite(rolePin, LOW);  // Röle aç
    analogWrite(ledPin, parlaklik);              // LED parlaklığı ayarla
    delay(100);
  } 
  else 
  {
    digitalWrite(rolePin, HIGH);   // Röle kapat
    analogWrite(ledPin, parlaklik);              // LED parlaklığı ayarla
    delay(100); 
  }

  // Seri monitör üzerinden takip
  Serial.print("Analog Değer: ");
  Serial.print(okunanDeger);
  Serial.print(" | PWM: ");
  Serial.println(parlaklik);

  delay(100);
}