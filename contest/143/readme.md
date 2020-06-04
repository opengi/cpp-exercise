## Weekly Contest 143

地址： https://leetcode.com/contest/weekly-contest-143  



## 一、  分糖果 II  


题目：[Chinese/C++] 1103. 分糖果 - 复杂度`O(人数)`  


题意： 给`n`个糖果，循环分给`m`个人，每次分的糖果个数加一个。  
问每个人得到的糖果个数。  


思路：由于规则固定，所以每个人得到的糖果也是固定的。  
我们可以按规则画出每个人得到的糖果个数。  


```
       1        2  ...        m  
     m+1      m+2  ...      m+m
    2m+1     2m+2  ...     2m+m
                   ...
(k-1)m+1 (k-1)m+2  ... (k-1)m+m
    km+1    km+2   ... km+mod
```

如上图表。可以看出来，每个人得到的糖果一次是`x, x+m, x+2m, ... x+(k-1)m`个。  
对于前`k`行，每个人得到的糖果个数是等差数列，可以计算出来。  


那怎么求出`k`呢？  
第一个方法是解方程。  
第二个方法是二分。  


求出`k`之后，就可以先求出前`k`行，每个人得到多少糖果。  
而剩余的糖果，可以在`m`人内分完，所以模拟即可。  



## 二、二叉树寻路  


题目：[Chinese/C++] 1104. `O(log n)`计算出答案  


题意：给一个二叉树，偶数层数字是反转的。  
给一个数字，求输出这个数字到根的路径。  


思路：既然偶数层的数字是反转，假设我们已经知道那一层的数字范围，根据当前层数以及第几个，就可以根据奇偶性计算出对应的值。  
如果当前层数是奇数，则正常计算，即数字范围起始值加上偏移量。  
如果当前层数是偶数，则逆序计算，即数字范围的结束地址减去偏移量。  




## 三、填充书架  



题目：[Chinese/C++] 1105. DP O(n^2) 解决书架问题  


题意： 给`n`本书，每本书有一个厚度和高度，摆在书架上。  
书架每一层最大宽度是`shelf_width`，摆不下时可以摆在下一层。
每层的高度为当前层所有书的最大高度，问书的总高度最小时多少。  


思路：经典的动态规划题。  
定义`dp[i]`为前`i`本书能够到达的最小高度。  
则对于第`i+1`本书，有若干选择。  
如自己单独一层，则状态转移为`dp[i+1] = dp[i] + h[i+1]`  
如果和前面的书放在一起，则状态转移方程式`dp[i+1] = dp[j] + max[h[j+1] ~ h[i+1])`, 其中需要满足`sum(w[i+1] ~ w[i+1]) <= shelf_width`。  
对于这两种选择，取最小值。  




## 四、解析布尔表达式  




题目：[Chinese/C++] 1106. 递归解决布尔表达式  


题意：给一个布尔表达式的规则，求表达式对应的值。  

这道题其实和上周比赛的最后一题非常类似，这是上次我的题解。  
[https://leetcode.com/problems/brace-expansion-ii/discuss/317732/ChineseC%2B%2B-1096.](https://leetcode.com/problems/brace-expansion-ii/discuss/317732/ChineseC%2B%2B-1096.)  


布尔表达式有`5`个规则。  

1. `t`为真 
2. `f`为假
3. `!(expr)` 取反  
4. `&(expr,expr,...)` 取与  
5. `|(expr,expr,...)` 取或  

我们可以增加另外一个规则，就可以形成递归闭环。  

6. `(expr,expr,...)` 获得布尔表达式集合。  

有了第`6`个万能的规则，代码实现就非常简单了。  
实际上我们并没有必要求出集合，只需要统计是否有true和是否有false即可。  
当然，实际比赛的时候，我直接计算出括号表达式里面的结果了。







