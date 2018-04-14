
#include "Shelf.h"

// Cria as prateleiras de cada cor (RGB)
Shelf redShelf("RED");
Shelf greenShelf("GREEN");
Shelf blueShelf("BLUE");

void setup() {   

  // TODO Feito para fins de exemplo (remover)
  Serial.begin(9600);
  Serial.println(F("RED SHELF:"));
  Serial.println(redShelf.print());
  Serial.println(F("ADDING PRODUCT..."));
  redShelf.addProduct();
  Serial.println(F("RED SHELF:"));
  Serial.println(redShelf.print());
  Serial.println(F("ADDING PRODUCT..."));
  redShelf.addProduct();
  Serial.println(F("RED SHELF:"));
  Serial.println(redShelf.print());
  Serial.println(F("REMOVING PRODUCT..."));
  redShelf.removeProduct();
  Serial.println(F("RED SHELF:"));
  Serial.println(redShelf.print());

}

void loop() {
  // TODO Implementar validação do sensor RGB e chamar os métodos corretos (vide exemplo acima)
}
