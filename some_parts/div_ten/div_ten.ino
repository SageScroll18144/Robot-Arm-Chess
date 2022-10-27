//table
const double voltage = 5;//Volts 
const double R2 = 1000;//1k Ohms
typedef struct Piece{
  double value;
  char whichone;
}piece;

piece pieces[12];//Tabela 12 tipos de peças diferentes.

//board
long mat_resistors[8][8];
long mat_copy[8][8];
const int pin_piece[32] = {A0};

//main game
bool turn = false;

void setup() {
  Serial.begin(9600);
  build_list_of_piece();
}

void loop() {
  //Serial.println(get_resistence(A0));
  
  //Só de debug
  int a[] = {A0, A1, A2, A3};
  for(int i=0;i<sizeof(a)/sizeof(int);i++){
    Serial.print((int)get_analog_resistence(a[i]));
    Serial.print(": ");
    print_piece(a[i]);
    Serial.print(" ");
  }
  Serial.println();

  /*for(int i=0;i<12;i++) Serial.print(pieces[i].whichone);
  Serial.println();*/
}
