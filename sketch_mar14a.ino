const int LED_PIN = 12;  // LED가 연결된 핀 번호
bool led_state = true;   // LED의 초기 상태는 켜짐으로 설정

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 스페이스바가 눌리면 LED를 끄거나 켭니다.
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == ' ') {
      led_state = !led_state;
      digitalWrite(LED_PIN, led_state);
      Serial.println(led_state ? "LED ON" : "LED OFF");
    }
  }
}
