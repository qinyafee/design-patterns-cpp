
// https://zhuanlan.zhihu.com/p/37469260
//其他方法需要加线程锁

// Singleton 模式经常和 Factory（ AbstractFactory）模式在一起使用，
// 因为系统中工厂对象一般来说只要一个

// 《Effective C++》
// version 1.2
class Singleton {
private:
  Singleton(){}; // 私有化它的构造函数，以防止外界创建单例类的对象；
  ~Singleton(){};
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

public:
  static Singleton &getInstance() {
    // 使用函数内的 local static 对象。
    // 这样，只有当第一次访问getInstance()方法时才创建实例。
    static Singleton instance;
    return instance;
  }
};

int main() {}