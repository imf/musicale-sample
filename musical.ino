

#define SOUND_OUT 9
#define LED 13

#define WHOLE 1.0
#define HALF .5
#define QUARTER .25
#define EIGHTH .128

#define MIDDLE_C 261.626

int bpm = 80;

void setup() {                
  pinMode(LED, OUTPUT); 
  pinMode(SOUND_OUT, OUTPUT);  
}

void loop() {
  playNote(WHOLE, MIDDLE_C);
  playNote(WHOLE, 440);
  rest(WHOLE);
}

int hertzToDelay(float hertz) {
  return (int) 1000.0 / hertz * 1000.0;
}

void rest(int noteValue) {
    delay(valueToDuration(noteValue) / 100);
}

void playNote(int noteValue, float frequency) {
  emitTone(valueToDuration(noteValue), hertzToDelay(frequency));
}

int valueToDuration(int noteValue) {
  return 1000000 * 60 / bpm * noteValue;
}

void blink(int on, int off, int frequency) {
  digitalWrite(LED, HIGH);
  emitTone(on, frequency);
  digitalWrite(LED, LOW);
  delay(off);
}

void emitTone(int duration, int frequency) { // Emit 1K tone on pin SOUND_OUT
digitalWrite(LED, HIGH);
  for (int i = 0; i < duration / frequency * 10; i++) {
    digitalWrite(SOUND_OUT, HIGH);
    delayMicroseconds(frequency / 2);
    digitalWrite(SOUND_OUT, LOW);
    delayMicroseconds(frequency / 2);
  }
digitalWrite(LED, LOW);
}

