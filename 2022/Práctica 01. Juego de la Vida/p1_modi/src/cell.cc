#include <iostream>
#include "cell.h"
#include "grid.h"

//Constructor
Cell::Cell(int i, int j): 
  state_(muerta),     //muerta = 0, viva = 1
  i_(i),
  j_(j),
  neighbor_(0) // empieza en 0, no hay vecinos
{}

// Destructor
Cell::~Cell(){}

State Cell::getState() const{
  return state_;
}

State Cell::setState(State state){
  state_ = state;
  return state_;
}

// actualizar
void Cell::updateState(){ 
  if(this->getState() == muerta) {  // si está muerta (!this->getState())
     if(neighbor_ == 3) {           // 3 celulas
        this->setState(viva);       // viva
     }
  } else {
     if(neighbor_ < 2 || neighbor_ > 3) { // caso contrario
        this->setState(muerta);           // muerta
     }
  }
}
// 1 1  (0 0) (0 1) (0 2) => (0 0) = i_ -1  | (0 2) => i_ + 1
//      (1 0) (1 1) (1 2)  
//      (2 0) (2 1) (2 2) => (2 0) = _j - 1  | (2 2) => j_ + 1

int Cell::neighbors(const Grid& grid){
  int result = 0;
  for (int i = i_ - 1; i <= i_ + 1; i++) {       
    for (int j = j_ - 1; j <= j_ + 1; j++) {
      if (!(i == i_ && j == j_) && !( i != 0 || j != grid.get_col())) {  //  i != 0 y j != al grid (para que no toque borde)
        Cell aux = grid.getCell(i, j);      // es vecina o no
        if (aux.getState() == viva){      // == 1
            result++; 
        }
      } 
    }     
  }
  neighbor_ = result;
  return neighbor_;
}

ostream& operator<<(ostream &os, const Cell& tablero){ 
  if (tablero.getState()) {
      os << "X";          // vivos
  } else {
      os << "-";
  }
  return os;
}