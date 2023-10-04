int p1 = 12;
int p2 = 2;
int p3 = 3;
int p4 = 4;
int p5 = 8;
int p6 = 9;
int p7 = 10;
int p8 = 11;
int leftp = 5;
int rightp = 6;
int modep = 7;
int d1 = 0;
int d2 = 0;
int d3 = 0;
int d4 = 0;
int d5 = 0;
int d6 = 0;
int d7 = 0;
int d8 = 0;
int left = 0;
int right = 0;
void write(int p, int data)
{
  digitalWrite(p, data);
}

void leftAns() // to shift bits from left to right
{  
  d8 = d7;
  d7 = d6;
  d6 = d5;
  d5 = d4;
  d4 = d3;
  d3 = d2;
  d2 = d1;
  d1 = left;

  write(p1, d1);
  write(p2, d2);
  write(p3, d3);
  write(p4, d4);
  write(p5, d5);
  write(p6, d6);
  write(p7, d7);
  write(p8, d8);
  delay(1000);
  left = !digitalRead(leftp);

}

void rightAns() // to shift bits from right to left
{
  d1 = d2;
  d2 = d3;
  d3 = d4;
  d4 = d5;
  d5 = d6;
  d6 = d7;
  d7 = d8;
  d8 = right;

  write(p1, d1);
  write(p2, d2);
  write(p3, d3);
  write(p4, d4);
  write(p5, d5);
  write(p6, d6);
  write(p7, d7);
  write(p8, d8);
  delay(1000);
  right = !digitalRead(rightp);
}

void setup() {
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p5, OUTPUT);
  pinMode(p6, OUTPUT);
  pinMode(p7, OUTPUT);
  pinMode(p8, OUTPUT);
  pinMode(leftp, INPUT_PULLUP); 
  pinMode(rightp, INPUT_PULLUP);
  pinMode(modep, INPUT_PULLUP);
}

void loop() {
  int m = digitalRead(modep);
  if(m == 0)
  {
    leftAns();
  }
  else
  {
    rightAns();
  }
}
