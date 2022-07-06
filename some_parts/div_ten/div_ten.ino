const int tensao = 5;//Volts 
const double R2 = 2200;//Ohms
double R1;

long mat_resistors[8][8];
long mat_copy[8][8];
const int pin_piece[32] = {A0};

bool turn = false;

void setup() {
  upd_mat();
  last_state();  
}

void loop() {
  upd_mat();
  if(hasAMovement()){
    last_state();
    //Envia para a I.A.
  }
}

long get_resistence(int pin){
  long U2 = tensao * analogRead(pin) / 1023;
  return (long)(tensao * R2 / U2 - R2);
}
void upd_mat(){
  int cnt = 0;
  for(int i=0;i<8;i++) for(int j=0;j<8;j++) {
    mat_resistors[i][j] = get_resistence(pin_piece[cnt]);
    cnt++;
  }
}
void last_state(){for(int i=0;i<8;i++) for(int j=0;j<8;j++) mat_copy[i][j]=mat_resistors[i][j];}
bool hasAMovement(){
  for(int i=0;i<8;i++) for(int j=0;j<8;j++) {
    if(mat_copy[i][j]!=mat_resistors[i][j]){
      return true;
    }
  }
  return false;
}
