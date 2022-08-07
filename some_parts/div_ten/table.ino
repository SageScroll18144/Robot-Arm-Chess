double get_resistence(int pin){
  double U2 = voltage * analogRead(pin) / 1023;
  return ((voltage * R2 / U2) - R2);
}
double get_analog_resistence(int pin){
  return analogRead(pin);
}
void build_list_of_piece(){
  piece n;

  //*LEITURA ANALOGICA DOS RESISTORES
  n.value = 833;//220.0
  n.whichone = 't';
  pieces[0] = n;

  n.value = 780;//330.0
  n.whichone = 'c';
  pieces[1] = n;

  n.value = 690;//470.0
  n.whichone = 'b';
  pieces[2] = n;

  n.value = 109;//8200.0
  n.whichone = 'k';
  pieces[3] = n;

  n.value = 512;//1000.0
  n.whichone = 'q';
  pieces[4] = n;

  n.value = 314;//2200.0
  n.whichone = 'p';
  pieces[5] = n;

  n.value = 235;//3300.0
  n.whichone = 'T';
  pieces[6] = n;

  n.value = 43;//22000.0
  n.whichone = 'C';
  pieces[7] = n;

  n.value = 607;//680.0
  n.whichone = 'B';
  pieces[8] = n;

  n.value = 92;//10000.0
  n.whichone = 'K';
  pieces[9] = n;

  n.value = 77;//12000.0
  n.whichone = 'Q';
  pieces[10] = n;

  n.value = 20;//47000.0
  n.whichone = 'P';
  pieces[11] = n;
}
char which_piece(double res_value){
  for(int i=0;i<12;i++){
    double x = pieces[i].value;
    if(res_value>=0.95*x && res_value<=1.05*x){
      return pieces[i].whichone;
    }
  }
  return 'x';
}
void print_piece(int pin){
  Serial.print(which_piece(get_analog_resistence(pin)));
}
