## 注意

**本题需要使用文件读写（`record.in` / `record.out`）。**

## 题目背景

[2lf](https://www.luogu.com.cn/user/824363) 为 CTFPC-4th 准备了一道测试点个数超级多的试题！

## 题目描述

这天，Sleeping Elephant 决定在评测记录上作画——画出一个绿色的 **TLE** 图案。

Sleeping Elephant 提交的题目共有 $n\times m$ 个测试点，可以看作有 $n\times m$ 个位置的网格图，从上到下分别为第 $1$ 到第 $n$ 行，从左到右分别为第 $1$ 列到第 $m$ 列。由于 Sleeping Elephant 写的不是正解，其中每个位置显示的评测状态可能是 AC（绿色）或 WA（红色）。

**T** 图案的形状如图：

|  | $\color{white}?$ |  |
| :----------: | :----------: | :----------: |
| **C** | **S** | **D** |
|  | **B** |  |

**L** 图案的形状如图：

| $\color{white}?$ |  |
| :----------: | :----------: |
| **A** |  |
| **S** | **D** |

**E** 图案的形状如图：

| $\color{white}?$ |  |
| :----------: | :----------: |
| **S** | **D** |
| **A** |  |
| **S** | **D** |
| **B** |  |
| **S** | **D** |

其中：

- **S** 代表单个绿色格子。
- **A** 代表从该位置开始向上延展的若干（$\ge 1$）个绿色格子。
- **B** 代表从该位置开始向下延展的若干（$\ge 1$）个绿色格子。
- **C** 代表从该位置开始向左延展的若干（$\ge 1$）个绿色格子。
- **D** 代表从该位置开始向右延展的若干（$\ge 1$）个绿色格子。

例如，下图包含 $10$ 个合法的 **T** 图案，$25$ 个合法的 **L** 图案和 $6$ 个合法的 **E** 图案：

| $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  |
| :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: |
|  | $\color{white}?$ |  | $\color{white}?$ |  | **S** |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |
| **S** | **S** $ $ | **S** | **S** $ $ | $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | **S** | **S** $ $ | **S** |  |
|  | **S** |  | $\color{white}?$ |  | **S** |  | $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | $\color{white}?$ |
| $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | $\color{white}?$ | **S** $ $ | **S** |  | **S** |  | $\color{white}?$ |  |
|  | **S** |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | $\color{white}?$ |
| $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | **S** | **S** $ $ | $\color{white}?$ |  |
|  | **S** |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | $\color{white}?$ |
| $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | **S** | **S** $ $ | **S** | **S** $ $ |

而下图**只**包含 $25$ 个合法的 **L** 图案，**不**包含合法的 **T** 图案和合法的 **E** 图案：

| $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  |
| :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: |
|  | $\color{white}?$ |  | $\color{white}?$ |  | **S** |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |
| $\color{white}?$ | **S** | **S** $ $ | **S** | $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | **S** | **S** $ $ | **S** |  |
|  | **S** $ $ |  | $\color{white}?$ |  | **S** |  | $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | $\color{white}?$ |
| $\color{white}?$ | **S** | $\color{white}?$ |  | $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | **S** |  | $\color{white}?$ |  |
|  | **S** $ $ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ | **S** $ $ | $\color{white}?$ |  | $\color{white}?$ |
| $\color{white}?$ | **S** | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | **S** |  | $\color{white}?$ |  |
|  | **S** $ $ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ | **S** $ $ | **S** |  | $\color{white}?$ |
| $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | $\color{white}?$ |  | **S** | **S** $ $ | **S** | **S** $ $ |

将上面两张图片上下拼接起来，我们就得到了样例。

已知 Sleeping Elephant 可以把任意多个绿色格子变为红色（可以是 $0$ 个，但不能把红色格子变成绿色），请求出他可以画出的不同的合法的 **T** 图案、合法的 **L** 图案和合法的 **E** 图案的数量。

答案对 $10^4+7$ 取模。

## 输入格式

第一行两个正整数 $n, m\ (1 \le n, m \le 1000)$。

接下来 $n$ 行，每行一个长度为 $m$ 且仅包含 $\tt G$（绿色）和 $\tt R$（红色）的字符串。

## 输出格式

一行三个非负整数，分别为 Sleeping Elephant 可以画出的不同的合法的 **T** 图案、合法的 **L** 图案和合法的 **E** 图案的数量。

答案对 $10^4+7$ 取模。

## 样例

```input1
16 12
RRRRRGRRRRRR
GGGGRGRRGGGR
RGRRRGRRGRRR
RGRRRGGRGRRR
RGRRRRRRGRRR
RGRRRRRRGGRR
RGRRRRRRGRRR
RRRRRRRRGGGG
RRRRRGRRRRRR
RGGGRGRRGGGR
RGRRRGRRGRRR
RGRRRGRRGRRR
RGRRRRRRGRRR
RGRRRRRRGRRR
RGRRRRRRGGRR
RRRRRRRRGGGG
```

```output1
10 50 6
```
