#include "lib/SimpleFIFO.h"

#include "Product.h"
#include "Motor.h"

#define LINES_PER_SHELF 2
#define COLUMNS_PER_SHELF 3
#define SIZE_OF_FIFO 6


class Shelf {
  private:
    String color;
    boolean shelf[LINES_PER_SHELF][COLUMNS_PER_SHELF];
    SimpleFIFO<Product*, SIZE_OF_FIFO> fifo;

  public:
    Shelf(String color);
    void addProduct();
    void removeProduct();
    int getQuantityOfProducts();
    String print();
};

Shelf::Shelf(String color) {
  this->color = color;
  // Inicializando a matriz com valores false
  for(int line=0; line < LINES_PER_SHELF; line++) {
    for(int column=0; column < COLUMNS_PER_SHELF; column++) {
      this->shelf[line][column] = false;
    }
  }
}

void Shelf::addProduct() {
  for(int line=0; line < LINES_PER_SHELF; line++) {
    for(int column=0; column < COLUMNS_PER_SHELF; column++) {
      if (shelf[line][column]) {
        // Esse espaço está ocupado
      } else {
        // Esse espaço está vazio
        // Seta o espaço para ocupado
        shelf[line][column] = true;
        // Adiciona o produto na fila com a sua posição para posterior remoção
        Product *product = new Product(line, column);
        fifo.enqueue(product);
        // Procedimentos de HARDWARE
        Motor motor;
        motor.addItem(color, line, column);
        return;        
      }      
    }
  }
}

void Shelf::removeProduct() {
  Product *product = NULL;
  // Remove o produto da fila
  product = fifo.dequeue();
  // Verifica se existe algum produto na fila
  if(product != NULL) {
    // Seta como livre o espaco na prateleira
    shelf[product->getLine()][product->getColumn()] = false;
    // Procedimentos de HARDWARE
    Motor motor;
    motor.removeItem(color, product->getLine(), product->getColumn());
    //liberando o espaço em memoria
    delete product;
  }  
}

int Shelf::getQuantityOfProducts() {
  return this->fifo.count();
}

String Shelf::print() {
  String result = String("");
  for(int line=0; line < LINES_PER_SHELF; line++) {
    result += "|";
    for(int column=0; column < COLUMNS_PER_SHELF; column++) {
      result += this->shelf[line][column] ? "BUSY" : "FREE";
      result += "|";
    }
    result += "\n";
  }
  return result;  
}
