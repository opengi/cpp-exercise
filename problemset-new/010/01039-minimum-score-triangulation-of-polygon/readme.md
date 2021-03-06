## 1039. Minimum Score Triangulation of Polygon  

题意：给一个凸多边形，按顶点划分为一些三角形。划分的总代价为所有三角形三边乘积的和。  
求总代价最小的划分。  


思路：DP。
定义 `f(0, n)`为`0~n` 这些顶点组成的多边形的最优划分。
此时只考虑顶点`0`和顶点`n`组成的边，则`1~n-1`这些顶点可以当做三角形的第三个顶点，假设选择可顶点`k`。  
此时多边形被划分为三部分：多边形`f(0,k)`、三角形`0,k,n`、多边形`f(k,n)`。  
最优值就是所有划分中的最小值。  


## c++语言  

[tiankonguse.cpp](./tiankonguse.cpp)

## Python语言

[marvelous.py](./marvelous.py)
