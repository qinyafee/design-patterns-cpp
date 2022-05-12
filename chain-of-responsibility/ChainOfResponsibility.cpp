/*
 * C++ Design Patterns: Chain of Responsibility
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */
#include <iostream>

/*
 * Handler
 * defines an interface for handling requests and
 * optionally implements the successor link
 */
class Handler {
public:
  virtual ~Handler() {}

  virtual void setHandler(Handler *s) { successor = s; }

  // 当一个请求到来时， ConcreteHandler 会先检查看自己有没有
  // 匹配的处理程序，如果有就自己处理，否则传递给它的后继。
  virtual void handleRequest() {
    // 这里示例程序中为了简化，ConcreteHandler，只是简单的检查看自己有没有后继，
    // 有的话将请求传递给后继进行处理，没有的话就自己处理。
    if (successor != 0) {
      successor->handleRequest();
    }
  }
  // ...

private:
  Handler *successor;
};

/*
 * Concrete Handlers
 * handle requests they are responsible for
 */
class ConcreteHandler1 : public Handler {
public:
  ~ConcreteHandler1() {}

  bool canHandle() {
    // ...
    return false;
  }

  virtual void handleRequest() {
    if (canHandle()) {
      std::cout << "Handled by Concrete Handler 1" << std::endl;
    } else {
      std::cout << "Cannot be handled by Handler 1" << std::endl;
      Handler::handleRequest();
    }
    // ...
  }
  // ...
};

class ConcreteHandler2 : public Handler {
public:
  ~ConcreteHandler2() {}

  bool canHandle() {
    // ...
    return true;
  }

  virtual void handleRequest() {
    if (canHandle()) {
      std::cout << "Handled by Handler 2" << std::endl;
    } else {
      std::cout << "Cannot be handled by Handler 2" << std::endl;
      Handler::handleRequest();
    }
    // ...
  }

  // ...
};

int main() {
  ConcreteHandler1 handler1;
  ConcreteHandler2 handler2;

  handler1.setHandler(&handler2);
  handler1.handleRequest();

  return 0;
}
