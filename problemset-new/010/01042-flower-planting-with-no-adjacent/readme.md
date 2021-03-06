## 1042. Flower Planting With No Adjacent  


题意：有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。  
paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。  
你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。
四种花的编号分别是`1,2,3,4`。  


思路：考虑到这道题难度是 `easy`，那果断进行贪心了。  
贪心：从左到右依次判断当前花园可以染什么色，随机选一个即可。  
判断标准：只要和前面染色的花园不冲突即可。  



疑问：怎么证明贪心一定正确呢？  
我们的目标不是把这道题通过，而是要理解这道题为什么可以这样做。  


有`4`种颜色，每个花园的度数最多为`3`。  


突然发现这个太明显了，根本就不需要证明了。  
但是我还是尝试证明一下吧。  


假设某个花园周围都已经染色了，会不会当前花园没法选颜色呢？  
什么时候没法选？周围把所有颜色都用完了。  
那周围用了多少个颜色？最多`3`个。  
也就是永远也用不完，即永远可以找个一个颜色来染色。  


好无聊是不是？  
但就是这样一个逻辑推理，很多人理解不了。  
甚至有大牛这道题没做出来。  


## C++语言  


[tiankonguse.cpp](./tiankonguse.cpp)






