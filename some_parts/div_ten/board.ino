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
