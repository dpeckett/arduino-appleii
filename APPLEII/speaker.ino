#define SPEAKER_PIN 5

void speaker_begin() {
  pinMode(SPEAKER_PIN, OUTPUT);
  digitalWrite(SPEAKER_PIN, LOW);
}

void speaker_toggle() {
  static boolean state = false;
  state = (state)?false:true;
  digitalWrite(SPEAKER_PIN, state);
}
