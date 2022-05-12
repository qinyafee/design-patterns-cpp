## Strategy

Strategy defines a family of algorithms, encapsulates each one, and makes them 
interchangeable. It lets the algorithm vary independently fromclients that use it. 
The pattern has behavioral purpose and applies to the objects.

### When to use

* many related classes differ only in their behavior
* you need different variants of an algorithm
* an algorithm uses data that clients shouldn't know about

策略模式
主要思想：定义一系列的算法，把它们一个个封装起来，并且使它们可相互替换。该模式使得算法可独立于使用它的客户而变化。

为了适应不同的需求，只把需要变化的接口和方法封装起来，为以后算法预留出扩展的可能性，从而使软件系统更加灵活。
https://zhuanlan.zhihu.com/p/285228424



使用场合
当存在以下情况时使用Strategy模式：

许多相关的类仅仅是行为有异。“策略”提供了一种用多个行为中的一个行为来配置一个类的方法；
需要使用一个算法的不同变体；
算法使用客户不应该知道的数据。可使用策略模式以避免暴露复杂的、与算法相关的数据结构；
一个类定义了多种行为，并且这些行为在这个类的操作中以多个条件语句的形式出现。将相关的条件分支移入它们各自的Strategy类中以替代这些条件语句。（是不是和状态模式有点一样哦？）
https://www.cnblogs.com/ring1992/p/9593575.html