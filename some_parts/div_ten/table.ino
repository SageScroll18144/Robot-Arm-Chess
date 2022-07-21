double get_resistence(int pin){
  double U2 = voltage * analogRead(pin) / 1023;
  if(U2==0.0) return 0.0;
  return ((voltage * R2 / U2) - R2);
}
void build_list_of_piece(){
  piece n;
  
  n.value = 220.0;
  n.whichone = 't';
  pieces[0] = n;

  n.value = 330.0;
  n.whichone = 'c';
  pieces[1] = n;

  n.value = 470.0;
  n.whichone = 'b';
  pieces[2] = n;

  n.value = 8200.0;
  n.whichone = 'k';
  pieces[3] = n;

  n.value = 1000.0;
  n.whichone = 'q';
  pieces[4] = n;

  n.value = 2200.0;
  n.whichone = 'p';
  pieces[5] = n;

  n.value = 3300.0;
  n.whichone = 'T';
  pieces[6] = n;

  n.value = 22000.0;
  n.whichone = 'C';
  pieces[7] = n;

  n.value = 680.0;
  n.whichone = 'B';
  pieces[8] = n;

  n.value = 10000.0;
  n.whichone = 'K';
  pieces[9] = n;

  n.value = 12000.0;
  n.whichone = 'Q';
  pieces[10] = n;

  n.value = 47000.0;
  n.whichone = 'P';
  pieces[11] = n;
}
char which_piece(double res_value){
  if(res_value == 0.0) return 'x';
  for(int i=0;i<12;i++){
    double x = pieces[i].value;
    if(res_value>=0.85*x && res_value<=1.15*x){
      return pieces[i].whichone;
    }
  }
}
void print_piece(int pin){
  Serial.print(which_piece(get_resistence(pin)));
}
