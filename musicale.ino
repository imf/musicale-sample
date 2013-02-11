

#define SOUND_OUT 9
#define LED 13

#define WHOLE 1.0
#define HALF .5
#define QUARTER .25
#define EIGHTH .128

#define MIDDLE_C 261.626
#define CIS 277
#define D 294
#define DIS 311
#define E 330
#define MIDDLE_F 349
#define FIS 370
#define G 392
#define GIS 415
#define A 440
#define AIS 466
#define B 494

int bpm = 90;

void setup() {                
  pinMode(LED, OUTPUT); 
  pinMode(SOUND_OUT, OUTPUT);  
//  Serial.begin(9600);
}

void loop() {
  playNote(WHOLE, MIDDLE_C);
  playNote(2.0, 440);
  playNote(HALF, MIDDLE_C);
  playNote(QUARTER, B);
  playNote(QUARTER, 220);
  playNote(WHOLE, 523.251);
  rest(WHOLE);
  playNote(QUARTER, MIDDLE_C);
  playNote(QUARTER, D);
  playNote(QUARTER, E);
  playNote(QUARTER, MIDDLE_F);
  playNote(QUARTER, G);
  playNote(QUARTER, A);
  playNote(QUARTER, B);
  playNote(QUARTER, MIDDLE_C * 2);
  rest(WHOLE);  
}

int hertzToDelay(float hertz) {
  return (int) 1000.0 / hertz * 1000.0;
}

void rest(int noteValue) {
    delay(valueToDuration(noteValue) / 100);
//    Serial.println("Rest.");

}

void playNote(float noteValue, float frequency) {
/*  Serial.println("playing note: ");
  Serial.print(noteValue, DEC);
  Serial.print('\t');
  Serial.print(frequency, DEC);
  Serial.print('\t');
  Serial.print(valueToDuration(noteValue), DEC);
  Serial.println(""); */
  emitTone(valueToDuration(noteValue), hertzToDelay(frequency));
}

float valueToDuration(float noteValue) { // in µSec
  return 100000 * 60 * noteValue / bpm;
}

void blink(int on, int off, int frequency) {
  digitalWrite(LED, HIGH);
  emitTone(on, frequency);
  digitalWrite(LED, LOW);
  delay(off);
}

void emitTone(float durationInMiliseconds, int frequencyInMicroseconds) { // Emit tone on pin SOUND_OUT
digitalWrite(LED, HIGH);
/*  Serial.println("Emitting tone: ");
  Serial.print(durationInMiliseconds * 10 / frequencyInMicroseconds, DEC);
  Serial.print('\t');
  Serial.print(frequencyInMicroseconds, DEC);
  Serial.println("");
*/
  for (int i = 0; i < durationInMiliseconds * 10 / frequencyInMicroseconds; i++) {
    digitalWrite(SOUND_OUT, HIGH);
    delayMicroseconds(frequencyInMicroseconds / 2);
    digitalWrite(SOUND_OUT, LOW);
    delayMicroseconds(frequencyInMicroseconds / 2);
  }
digitalWrite(LED, LOW);
}

