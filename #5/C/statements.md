## 注意

**本题需要使用文件读写（`match.in` / `match.out`）。**

## 题目背景

CTFPC-4th 期间，[2lf](https://www.luogu.com.cn/user/824363) 总是在时不时地观察比赛排行榜，以至于他甚至能背下任意一个人的成绩。

## 题目描述

给定 $n$ 个参赛者的成绩比较结果（没有并列），请按成绩给他们排名。

> 本题的成绩比较结果将会以一张 $n$ 行 $n$ 列的表格呈现。对于第 $i$ 行第 $j$ 列的格子：
> 
> - 当 $i \le j$ 时，这一格没有内容。
> - 当 $i > j$ 时，我们用以下两个记号中的一个表示成绩比较结果：
>   - `<`：$i$ 号选手的成绩低于 $j$ 号选手。
>   - `>`：$i$ 号选手的成绩高于 $j$ 号选手。
> 
> 不难发现，表格中有且仅有第 $1$ 行是空行，且空格子全部出现在行末。

当然了，给出的成绩比较结果可能不合法，此时请输出 $n$ 个 $-1$。

## 输入格式

**本题有多组数据。**

第一行输入一个正整数 $T$，表示数据组数。

对于每组数据：

第一行一个正整数 $n$。

下面 $n-1$ 行，第 $i$ 行一个长度为 $i$ 且仅含 `<` 和 `>` 的字符串，描述了成绩比较结果表格。

请注意，表格中的空行和空格子将在输入中被省略。

## 输出格式

对于每组数据，输出一行 $n$ 个整数，按成绩从高到低的顺序依次输出 $n$ 个参赛者的编号。

给出的成绩比较结果可能不合法，此时请输出 $n$ 个 $-1$。

## 样例

```input1
2
5
>
<<
<<>
>>>>
5
>
<>
<<>
<<<>
```

```output1
5 2 1 4 3
-1 -1 -1 -1 -1
```

## 数据范围

$1 \le T \le 10^4$，$2 \le n \le 1000$，且保证单个测试点中 `<` 和 `>` 的个数之和不大于 $10^6$。
