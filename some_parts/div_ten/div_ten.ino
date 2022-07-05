const int tensao = 5;//Volts 
const double R2 = 2200;//Ohms
double R1;

double mat_resistors[8][8];
const int pin_piece[32];

void setup() {}

void loop() {
  R1 = get_resistence(A0);
}

double get_resistence(int pin){
  double U2 = tensao * analogRead(pin) / 1023;
  return tensao * R2 / U2 - R2;
}
void build_mat(){
  int cnt = 0;
  for(int i=0;i<8;i++) for(int j=0;j<8;j++) {
    mat_resistors[i][j] = get_resistence(pin_piece[cnt]);
    cnt++;
  }
}
