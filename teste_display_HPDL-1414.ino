/*
  Código de teste para o display HPDL-1414
*/

#define D0        2
#define D1        3
#define D2        4
#define D3        5
#define D4        6
#define D5        7
#define D6        8
#define DIG_SEL0  9
#define DIG_SEL1  10
#define WR        11

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(DIG_SEL0, OUTPUT);
  pinMode(DIG_SEL1, OUTPUT);
  pinMode(WR, OUTPUT);

  digitalWrite(WR, HIGH);
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(DIG_SEL1, LOW);
  digitalWrite(DIG_SEL0, LOW);
}

void loop() {
  for (int j=0; j<3; j++){
    write_display(3, j+48);
    for (int i = 32; i < 96; i++){
      write_display(j, i);
      delay(100);
    }

  }

}

int write_display(char position, char digit){
  switch (position) {
    case 0:
      digitalWrite(DIG_SEL1, LOW);
      digitalWrite(DIG_SEL0, LOW);
      break;
    case 1:
      digitalWrite(DIG_SEL1, LOW);
      digitalWrite(DIG_SEL0, HIGH);
      break;
    case 2:
      digitalWrite(DIG_SEL1, HIGH);
      digitalWrite(DIG_SEL0, LOW);
      break;
    case 3:
      digitalWrite(DIG_SEL1, HIGH);
      digitalWrite(DIG_SEL0, HIGH);
      break;
    default:
      return -1;
  }
  delayMicroseconds(1);

  if((digit >= 32) || (digit <= 95)){
      digitalWrite(WR, LOW);
      delayMicroseconds(1);

      digitalWrite(D0, ((digit >> 0) & 1) );
      digitalWrite(D1, ((digit >> 1) & 1) );
      digitalWrite(D2, ((digit >> 2) & 1) );
      digitalWrite(D3, ((digit >> 3) & 1) );
      digitalWrite(D4, ((digit >> 4) & 1) );
      digitalWrite(D5, ((digit >> 5) & 1) );
      digitalWrite(D6, ((digit >> 6) & 1) );

      delayMicroseconds(1);
      return 0;
  }
  else return -1;
}