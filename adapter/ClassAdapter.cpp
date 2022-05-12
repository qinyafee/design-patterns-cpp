/*
 * C++ Design Patterns: Adapter (Class scope)
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>

/*
 * Target
 * defines specific interface that Client uses
 */
class Target {
public:
  virtual ~Target() {}

  virtual void request() = 0; // client已经设计好的接口
  // ...
};

/*
 * Adaptee
 * all requests get delegated to the Adaptee which defines
 * an existing interface that needs adapting
 */
class Adaptee {
public:
  ~Adaptee() {}

  // 第三方库的接口
  void specificRequest() { std::cout << "specific request" << std::endl; }
  // ...
};

/*
 * Adapter
 * implements the Target interface and lets the Adaptee respond
 * to request on a Target by extending both classes
 * ie adapts the interface of Adaptee to the Target interface
 */
// 通过 private 继承Adaptee 获得【实现继承】的效果，
// 而通过 public 继承 Target 获得【接口继承】的效果
// private 继承后，父类中的接口都变为 private，当然只能是实现继承了。
class Adapter : public Target, private Adaptee {
public:
  virtual void request() { specificRequest(); }
  // ...
};

// Adapter
// 模式提供了将一个类（第三方库）的接口转化为客户（购买使用者）希望的接口
int main() {
  Target *t = new Adapter();
  t->request();
  delete t;

  return 0;
}
