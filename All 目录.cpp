1. std::function

  · 定义： 
    template<class R, class... Args>
    class function<R(Args...)>
    
  · 描述：
    它是对可调用实体（函数、函数指针、重载()的类、Lamda表达式)的一种类型安全的封装
  
  · 用法：
    int f(int a, int b) {return a + b;}
    function<int(int, int)> func = f;
  
2. std::optional

  · 描述：
    想要函数的返回值有多个的做法：
      ① 作为引用参数传参，函数返回值来标志运行状态
      ② tuple数据结构，例如：
        tuple<bool, string, string> f(const string& in)
        {
          if(in.size() == 0) return make_tuple(false, "", ""); 
          return make_tuple(true, "hello", "world");
        }
      ③ pair + 结构体，例如：
        struct out
        {
          string out1{""};
          string out2{""};
        };
        pair<bool, out> f(const string& in)
        {
          out o;
          if(in.size() == 0) return {false, o};
          
          o.out1 = "hello"; o.out2 = "world";
          return {true,o);
        }
        ④ std::optional
         
  · 用法：
    struct out
    {
      string out1{""};
      string out2{""};
    };
    optional<out> f(cosnt  string& in)
    {
      out o;
      if(in.size() == 0) return nullopt;
      o.out1 = "hello"; o.out2 = "world";
      return o;
    }
        
  
          
          
          
          
          
          
          
          
          
          
          
