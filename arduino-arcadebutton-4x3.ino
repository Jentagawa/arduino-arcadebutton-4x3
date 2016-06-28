byte noteON = 144;
int numbts = 13;
int bts[13];
boolean btgs[13];
int note_no[] = {27,26,25,24,15,14,13,12,3,2,1,0};
// button layout
// 13 12 11 10
// 9  8  7  6
// 5  4  3  2

// notes layout Flstudio
// 0  1  2  3
// 12 13 14 15
// 24 25 26 27

void setup() {
  Serial.begin(9600);
  for(int i=0; i<numbts; i++) bts[i] = i+2;
  for(int i=0; i<numbts; i++) btgs[i] = false;
  for(int i=0; i<numbts; i++) pinMode(bts[i], INPUT_PULLUP);
}

void loop() {
  for(int i=0; i<numbts; i++){
    if (!btgs[i]) {
      if (digitalRead(bts[i])==LOW ) {
        MIDImessage(noteON, note_no[i], 127);
        delay(2);//crude form of button debouncing
        btgs[i] = true;
      }
    }
    else {
      if (digitalRead(bts[i])==HIGH) {
        MIDImessage(noteON, note_no[i], 0);
        delay(2);//crude form of button debouncing
        btgs[i] = false;
      }
    }
  }
}

//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}

