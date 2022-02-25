#include <iostream> 

#include <fstream>
#include <string>
#include <unistd.h>

char knight = 'N'; 
char wall=' ';
char path='.';
char visited = '#';
int solutions[5][5]; 
//std::string board[7][7];
// int solutionsRow = 0; 
// int solutionsCol = 0; 
int sequence = 1; 


int load_board(std::string filename, std::string *board){
    //reads the board line by line 
    // i represents num of lines 
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,board[i])){
    i++;
  }
  return i;
}


void print_board(std::string board[],int lines){
  std::cout << "[0;0H\n";
  for(int i = 0; i < lines; i++){
    std::cout << board[i] << "\n";
  }
}


void solve(std::string board[], int lines, int row, int col, bool &solved){
  if (sequence > 25){
    solved = true;
    return;
  }
  if (board[row][col]==wall ||
      board[row][col]==knight || board[row][col]==visited) {

    return;
  }

  board[row][col]=knight;
  usleep(80000);
  print_board(board,lines);

    sequence++; 
  // solutions[solutionsRow][solutionsCol] = 5*(row-2) + col-1; 
//   if(row > 6 || row < -1 || col > 6 || col < -1) {
    solutions[row-2][col-2] = sequence;
 // }
 // sequence++; 
  // int temp = 5*(row-2) + col-1;
  // std::cout << temp << std::endl; 

  // std::cout <<  solutions[solutionsRow][solutionsCol] << std::endl; 
    
  

  //1st way 
  if (!solved) solve(board,lines,row-2,col+1,solved);
 
  //2nd 
  if (!solved) solve(board,lines,row-1,col+2,solved);
 
  //3rd
  if (!solved) solve(board,lines,row+1,col+2,solved);
  
  //4th
  if (!solved) solve(board,lines,row+2,col+1,solved);
 
  //5th 
  if (!solved) solve(board,lines,row+2,col-1,solved);
 
  //6th
  if (!solved) solve(board,lines,row+1,col-2,solved);
  
  //7th
  if (!solved) solve(board,lines,row-1,col-2,solved);

  //8th
  if (!solved) solve(board,lines,row-2,col-1,solved);



int main() {
  std::string board[9];
  int lines;  
  lines = load_board("board.dat", board);

  std::cout << "[2J;\n";
  print_board(board,lines);
  bool solved = false;
  solve(board,lines,3,3,solved);
  print_board(board,lines);
  

  for (int i = 0; i < 5; i++) { 
      for (int j = 0; j < 5; j++) { 
          std::cout << solutions[i][j] << ":";
      }
      std::cout << std::endl; 
  }

  std::cout << "Done!\n";
}




