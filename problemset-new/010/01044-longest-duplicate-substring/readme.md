## 1044. Longest Duplicate Substring  


题意：给出一个字符串 S，求重复子串的最大长度。  
注：重复子串允许两个串有部分重叠。  


注2：原题的描述有很大的问题，很容易错误的理解为两个重复子串必须连续。  
赛后看了其他人的代码，才知道是任意子串。  


思路：这道题显然是后缀数组的模板题，可是我不会后缀数组。  
看到是求最大值，于是我就往二分的方向思考，发现二分确实可以做这道题。  


对最大长度k 进行二分`log(n)`，然后判断这个长度 k 是否有答案`O(n)`。  
对于判断是否存在长度 k 的重复子串，最笨的方法需要`O(n^2*k)`的复杂度。  
使用`set`把子串存起来，后面只需要在`set`里判断子串是否出现过，此时需要`O(n*k*log(n))`的复杂度。  
而使用`hash`与滑动窗口的方法，则可以把`k`优化掉，从而变成`O(n*log(n))`的复杂度。  
综合复杂度就是`O(n*log(n)^2)`。  


这里的`hash`需要满足滑动窗口的性质，可以快速从左边出一个字符，右边快速进入一个字符，更新hash只需要`O(1)`的复杂度。  
这个方法的一种实现是把字符串当做`26`进制的数字（假设都是小写字母），然后计算出这个字符串对应十进制数字的值。  
由于数字可能很大，这里想固定的数字取模。  
由于在加减乘三个运算里先取模与后取模不影响结果，所以最终`hash`出的数字也相等。  


PS：对于后缀数组，如果有机会，后面我会进行专题讲解（目前专题讲解到二分查找了）。  


思考题：你能构造出一个`case`，使得`hash`冲突的吗？
即对于不同的两个字符串`S1`和`S2`，按照上面的`hash`运算后，得出的数字一样。  


## C++语言  

[tiankonguse.cpp](./tiankonguse.cpp)
