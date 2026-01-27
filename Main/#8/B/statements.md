## 注意

**本题需要使用文件读写（`laser.in` / `laser.out`）。**

**本题的标准程序没有用到随机数生成器。**

**本题的 IO 量很大，因此请注意 IO 效率。**

**你可以使用以下代码（使用时需要包含 `<cstdio>` 或 `<bits/stdc++.h>` 头文件），并用 `read()` 读入一个正整数，用 `write_solution(x)` 输出一行一个正整数 $\bm x$，用 `write_no_solution()` 输出一行一个整数 $\bm{-1}$：**

```cpp
inline int read()
{
	int x = 0;
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0')
	{
		x = x * 10 + c - '0';
		c = getchar_unlocked();
	}
	return x;
}
void write(int x)
{
	if (x <= 9)
	{
		putchar_unlocked(x + '0');
		return;
	}
	write(x / 10);
	putchar_unlocked(x % 10 + '0');
}
inline void write_solution(int x)
{
	write(x);
	putchar_unlocked('\n');
}
inline void write_no_solution()
{
	putchar_unlocked('-');
	putchar_unlocked('1');
	putchar_unlocked('\n');
}
```

## 题目背景

X 国最近在和 Y 国战斗。

X 国刚刚部署了一种激光武器，这种激光武器可以朝前后左右四个方向发射可以秒杀、无法防御的激光。

X 国的将领对这种武器十分重视，因为这种武器只能使用一次。

经过调查，他发现 Y 国的营地可以被激光破坏，并且可以被穿透。

现在 X 国的将领想要知道，是否有 Y 国的营地没有被破坏。

X 国的将领会向你进行多次询问，每次给出武器的坐标，询问是否有 Y 国的营地没有被破坏。

如果有，请告诉他任意一个没有被破坏的营地的编号。

## 题目描述

给定二维平面上的 $n$ 个基准点 $(x_1, y_1), (x_2, y_2), \ldots, (x_n, y_n)$ 和 $q$ 个询问点 $(a_1, b_1), (a_2, b_2), \ldots, (a_q, b_q)$，请对每个询问点找出一个基准点，使得该基准点与给定的询问点：

- 该基准点与给定的询问点不重合。
- 该基准点与给定的询问点之间连成的线段不平行于坐标轴：既不平行于 $x$ 轴，也不平行于 $y$ 轴。

## 输入格式

第一行两个正整数 $n,q\ (1 \le n, q \le 10^6)$。

接下来 $n$ 行，每行两个正整数 $x_i, y_i\ (1 \le x_i,y_i \le 10^9)$。

接下来 $q$ 行，每行两个正整数 $a_i, b_i\ (1 \le a_i,b_i \le 10^9)$。

## 输出格式

对于每一个询问，输出一行一个整数，表示找到的基准点 $(x_i, y_i)$ 的编号 $i$。

**答案可能有多个，输出一个即可。**

**特别地，如果无解，则输出 $\bm{-1}$。**

## 样例

```input1
2 3
1 3
3 3
1 2
2 2
3 3
```

```output1
2
1
-1
```

```input2
2 3
1 3
3 3
1 2
2 2
3 3
```

```output2
2
2
-1
```
