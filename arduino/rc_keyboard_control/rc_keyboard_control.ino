// assign pin num
int right_pin1 = 12;
int right_pin2 = 13;
int left_pin1 = 8;
int left_pin2 = 9;
int forward_pin1 = 4;
int forward_pin2 = 5;

// duration for output
int time = 50;
// initial command
int command = 0;

void setup() {
  pinMode(right_pin1, OUTPUT);
  pinMode(right_pin2, OUTPUT);
  pinMode(left_pin1, OUTPUT);
  pinMode(left_pin2, OUTPUT);
  pinMode(forward_pin1, OUTPUT);
  pinMode(forward_pin2, OUTPUT);
 
  Serial.begin(115200);
}

void loop() {
  //receive command
  if (Serial.available() > 0){
    command = Serial.read();
  }
  else{
    reset();
  }
   send_command(command,time);
}

void right(int time){
  digitalWrite(right_pin1, LOW);
  digitalWrite(right_pin2, HIGH);
  delay(time);
}

void left(int time){
  digitalWrite(left_pin1, LOW);
  digitalWrite(left_pin2, HIGH);
  delay(time);
}

void forward(int time){
  digitalWrite(forward_pin1, LOW);
  digitalWrite(forward_pin2, LOW);
  delay(time);
}


void forward_right(int time){
  digitalWrite(forward_pin1, LOW);
  digitalWrite(forward_pin2, LOW);
  digitalWrite(right_pin1, LOW);
  digitalWrite(right_pin2, HIGH);
  delay(time);
}


void forward_left(int time){
  digitalWrite(forward_pin1, LOW);
  digitalWrite(forward_pin2, LOW);
  digitalWrite(left_pin1, LOW);
  digitalWrite(left_pin2, HIGH);
  delay(time);
}


void reset(){
  digitalWrite(forward_pin1, HIGH);
  digitalWrite(forward_pin2, LOW);
  digitalWrite(left_pin1, HIGH);
  digitalWrite(left_pin2, LOW);
  digitalWrite(right_pin1, HIGH);
  digitalWrite(right_pin2, LOW);
  
}

void send_command(int command, int time){
  switch (command){

     //reset command
     case 0: reset(); break;

     // single command
     case 1: forward(time); break;
    // case 2: reverse(time); break;
     case 2: right(time); break;
     case 3: left(time); break;

     //combination command
     case 4: forward_right(time); break;
     case 5: forward_left(time); break;
//     case 8: reverse_right(time); break;
//     case 9: reverse_left(time); break;

     default: Serial.print("Inalid Command\n");
    }
}
