const int tensao = 5;//Volts 
const double R2 = 2200;//Ohms
double R1;

void setup() {
  
}
void loop() {
  R1 = get_resistence(A0);
}

double get_resistence(int pin){
  double U2 = tensao * analogRead(pin) / 1023;
  return tensao * R2 / U2 - R2;
}
