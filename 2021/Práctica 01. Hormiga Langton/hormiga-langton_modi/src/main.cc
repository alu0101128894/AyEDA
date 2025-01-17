// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: main.cc

#include <iostream>
#include <cstring>

#include "../include/rule_black90.h"
#include "../include/rule_white90.h"
#include "../include/universe.h"

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cerr << "Forma de uso: ./hormiga <celdas eje y> <celdas eje x>" << std::endl;
    return 0;
  }

  Universe universe(atoi(argv[1]), atoi(argv[2]));
  Ant ant;
  ant.AddRule(new RuleBlack90); //instancias a las clases
  ant.AddRule(new RuleWhite90);
  universe.SetAnt(ant); // la paso al universo
  universe.Run();

  return 0;
}
