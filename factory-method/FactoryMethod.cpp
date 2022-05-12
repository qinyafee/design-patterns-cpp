/*
 * C++ Design Patterns: Factory Method
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>
#include <string>

/*
 * Product
 * products implement the same interface so that the classes can refer
 * to the interface not the concrete product
 */
class Product { //Factory 模式仅仅局限于一类，有共同基类
public:
  virtual ~Product() {}

  virtual std::string getName() = 0;
  // ...
};

/*
 * Concrete Product
 * define product to be created
 */
class ConcreteProductA : public Product {
public:
  ~ConcreteProductA() {}

  std::string getName() { return "type A"; }
  // ...
};

/*
 * Concrete Product
 * define product to be created
 */
class ConcreteProductB : public Product {
public:
  ~ConcreteProductB() {}

  std::string getName() { return "type B"; }
  // ...
};

/*
 * Creator
 * contains the implementation for all of the methods
 * to manipulate products except for the factory method
 */
class Creator {
public:
  virtual ~Creator() {}

  virtual Product *createProductA() = 0;
  virtual Product *createProductB() = 0;

  virtual void removeProduct(Product *product) = 0;

  // ...
};

/*
 * Concrete Creator
 * implements factory method that is responsible for creating
 * one or more concrete products ie. it is class that has
 * the knowledge of how to create the products
 */
class ConcreteCreator : public Creator {
public:
  ~ConcreteCreator() {}

  // 具体化类的工作延迟到ConcreteCreator子类中
  Product *createProductA() { return new ConcreteProductA(); }
  // 可以用参数化工厂方法，传入参数给一个统一的create()
  Product *createProductB() { return new ConcreteProductB(); }

  void removeProduct(Product *product) { delete product; }
  // ...
};

int main() {
  Creator *creator = new ConcreteCreator();

  Product *p1 = creator->createProductA();
  std::cout << "Product: " << p1->getName() << std::endl;
  creator->removeProduct(p1);

  Product *p2 = creator->createProductB();
  std::cout << "Product: " << p2->getName() << std::endl;
  creator->removeProduct(p2);

  delete creator;
  return 0;
}
