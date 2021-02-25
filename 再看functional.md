再探```#include <functional>``` 之 ```std::function```
----

[参考链接](https://www.cnblogs.com/youyoui/p/8933006.html)

### 可调用对象分类：
  * 普通函数
  * 函数指针
  * 类成员函数
  * 类静态函数
  * 类重载()函数（仿函数）
  * Lamda表达式
  * std::function包装器

### 类中成员函数和静态函数的区别：
  * 有无this指针

### 函数指针用在回调函数操作中：
  * 向一个函数的形参传入函数指针，在该函数体中调用函数指针指向的函数，即为回调操作。

### 函数包装器std::function
  * 能够包容所有具有相同参数类型的函数实体
  * 使用function包装类的成员函数时候，需要使用bind绑定this参数
