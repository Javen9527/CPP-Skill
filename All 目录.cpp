1. std::function

  · 定义： 
    template<class R, class... Args>
    class function<R(Args...)>
    
  · 描述：
    它是对可调用实体（函数、函数指针、重载()的类、Lamda表达式)的一种类型安全的封装
  
  · 用法：
    int f(int a, int b) {return a + b;}
    function<int(int, int)> func = f;
  
2. 
