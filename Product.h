class Product {
  private:
    int line;
    int column;

  public:
    Product();
    Product(int line, int column);
    int getLine();
    void setLine(int line);
    int getColumn();
    void setColumn(int column);
} product;

Product::Product() {}

Product::Product(int line, int column) {
  this->line = line;
  this->column = column;
}

int Product::getLine() {
  return line;
}

void Product::setLine(int line) {
  this->line = line;
}

int Product::getColumn() {
  return column;
}

void Product::setColumn(int column) {
  this->column = column;
}
