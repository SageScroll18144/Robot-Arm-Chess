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
  int a[] = {A0, A1, A2};
  for(int i=0;i<sizeof(a)/sizeof(int);i++){
    print_piece(a[i]);
  }
  Serial.println();
}
