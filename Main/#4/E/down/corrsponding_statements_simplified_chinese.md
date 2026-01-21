## 版权声明

**本题版权归 [Long Long OJ](https://www.llong.tech/) 所有。**

## 题目描述

新定义一种位运算 $\sharp$，规定 $0\sharp0=1,0\sharp1=1,1\sharp1=1,1\sharp0=0$。

输出满足以下条件的长度为 $N$ 的 01 串的个数（$\bmod\ 998\ 244\ 353$）：

- $((((A_1\sharp A_2)\sharp A_3)\sharp\cdots)\sharp A_{N-1})\sharp A_N=1$；
- $A_1\sharp(A_2\sharp(A_3\sharp(\cdots\sharp(A_{N-1}\sharp A_N))))=1$。

## 输入格式

一行一个正整数 $N\ (1 \le N \le 10^{10^5 + 1})$。

## 输出格式

答案 $\bmod\ 998\ 244\ 353$ 的结果。

## 样例

```input1
20
```

```output1
699051
```
