## 注意

**本题需要使用文件读写（`sorrow.in` / `sorrow.out`）。**

**本题中 $\bm{S_{[l,r]}}$ 表示截取字符串 $\bm S$ 的第 $\bm{l,l+1,\ldots,r}$ 个字符所得到的子串。**

**一个字符串 $\bm S$ 被称为「23 串」，当且仅当 $\bm S$ 不包含除 $\tt 2$ 和 $\tt 3$ 以外的任何字符。**

**同一序列 $\bm{\{S_L\}}$ 的两个子序列 $\bm{\{P_n\}=[S_{i_1},S_{i_2},\ldots,S_{i_n}]\ (1\le i_1<i_2<\ldots<i_n\le L)}$ 和 $\bm{\{Q_m\}=[S_{j_1},S_{j_2},\ldots,S_{j_m}]\ (1\le j_1<j_2<\ldots<j_m\le L)}$ 本质不同，当且仅当集合 $\bm{\{i_1,i_2,\ldots,i_n\}}$ 和 $\bm{\{j_1,j_2,\ldots,j_m\}}$ 不相等。请注意，这并不意味着序列 $\bm{\{P_n\}}$ 和 $\bm{\{Q_m\}}$ 一定不相等。**

**本题中 $\bm k$ 的值超过了 64 位有符号整数（以及 64 位无符号整数）的存储范围，建议使用 C++14（或更高版本）中引入的 `__int128` 扩展数据类型进行存储。请注意，不要使用 `__int128` 类型的变量（或常量）作为参数调用 `cmath`（`math.h`）库中的函数（如绝对值函数 `abs`，算术平方根函数 `sqrt` 等），否则可能会导致编译错误。**

**你可以使用以下代码（使用时需要包含 `<cstdio>` 或 `<bits/stdc++.h>` 头文件），并用 `read()` 读入一个 `__int128` 类型的正整数，用 `readline()` 读入一行一个 23 串（该函数返回一个 `std::string` 类型的字符串，使用时需要包含 `<string>` 或 `<bits/stdc++.h>` 头文件），用 `writeline(x)` 输出一行一个 `__int128` 类型的非负整数 $\bm x$。请注意，不要将以下代码和其他输入输出方式混用：**

```cpp
inline __int128 read()
{
	__int128 x = 0;
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0')
	{
		x = x * 10 + c - '0';
		c = getchar_unlocked();
	}
	return x;
}
inline std::string readline()
{
	std::string x = "";
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0')
	{
		x += c;
		c = getchar_unlocked();
	}
	return x;
}
void write(__int128 x)
{
	if (x <= 9)
	{
		putchar_unlocked(x + '0');
		return;
	}
	write(x / 10);
	putchar_unlocked(x % 10 + '0');
}
inline void writeline(__int128 x)
{
	write(x);
	putchar_unlocked('\n');
}
```

## 题目描述

对于一个长度为 $t$ 的非空 23 串 $R$，定义其权值 $f(S)$ 为：

$$f(R)=\sum_{i_1=1}^t\sum_{i_2=1}^t\sum_{i_3=1}^t\sum_{i_4=1}^t[R_{i_1}=R_{i_2}=R_{i_3}=\texttt 3\land R_{i_4}=\texttt 2\land i_1<i_2<i_3<i_4]$$

即 $R$ 中本质不同的子序列 $\{\texttt 3,\texttt 3,\texttt 3,\texttt 2\}$ 的个数。

定义一个非空 23 串 $T$ 是「不开心的」，当且仅当 $f(T) \ge k$。

现给定一个长度为 $n$ 的 23 串 $S$，求 $S$ 中「不开心的」非空子串的数量。

## 输入格式

第一行两个正整数 $n,k\ (1 \le n \le 10^6, 1 \le k \le 10^{24})$。

第二行一个长度为 $n$ 的 23 串 $S$。

## 输出格式

一行一个非负整数表示答案。

## 样例

```input1
20 16
32323232323232323232
```

```output1
41
```

## 样例解释

「不开心的」非空子串有：

- $S_{[1,12]},S_{[1,13]},\ldots,S_{[1,20]}$（共有 $20-12+1=9$ 个）
- $S_{[2,14]},S_{[2,15]},\ldots,S_{[2,20]}$（共有 $20-14+1=7$ 个）
- $S_{[3,14]},S_{[3,15]},\ldots,S_{[3,20]}$（共有 $20-14+1=7$ 个）
- $S_{[4,16]},S_{[4,17]},\ldots,S_{[4,20]}$（共有 $20-16+1=5$ 个）
- $S_{[5,16]},S_{[5,17]},\ldots,S_{[5,20]}$（共有 $20-16+1=5$ 个）
- $S_{[6,18]},S_{[6,19]},S_{[6,20]}$（共有 $3$ 个）
- $S_{[7,18]},S_{[7,19]},S_{[7,20]}$（共有 $3$ 个）
- $S_{[8,20]}$（共有 $1$ 个）
- $S_{[9,20]}$（共有 $1$ 个）

故答案为：

$$9+7+7+5+5+3+3+1+1=41$$
