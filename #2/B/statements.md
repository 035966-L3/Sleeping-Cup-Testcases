## 注意

**本题需要使用文件读写（ `honey1.in` / `honey1.out` ）。**

## 题目背景

Sleeping Bear 是一只十分可爱的小熊，它越吃蜂蜜就越可爱，可是它每次去摘蜂蜜都会被蜜蜂蛰一头包。今天它又要吃蜂蜜了，但是它不想又被蜜蜂蛰一头包，所以它想请你帮助它设计一条逃生路线以规避蜜蜂的围追堵截。

## 题目描述

给定一个正整数 $k$，表示有一个 $k \times k$ 的地图，其中有字符 `B`、`X`、`R`、`L` 分别表示 Sleeping Bear 所在的位置（默认蜜蜂就在它身后），不能走的路，可以走的路以及湖的位置（只有 Sleeping Bear 跳入湖中才能不被蜜蜂蛰）。

请你帮助 Sleeping Bear 找到一条可以通往湖边的路（他每次可以向上、下、左、右移动一格），如果能够找到这种路就输出 `Yes`，如果这次还会被蛰就输出 `No`。

## 输入格式

**本题有多组测试数据。**

第一行输入一个整数 $T$，表示测试数据的数量。

对于每组测试数据：

第一行输入一个整数 $k$，表示有一个 $k \times k$ 的地图。

接下来 $k$ 行，每行输入 $k$ 个字符，表示这个地方的状态。

## 输出格式

对于每组测试数据，输出一行一个字符串 `Yes` 或 `No`，表示 Sleeping Bear 能否逃脱蜜蜂的围追堵截。

## 样例

```input1
1
5
XXRRR
XRRRR
XXXXL
XXBRR
XXRRR
```

```output1
Yes
```

```input2
2
5
XXRRR
XRRRX
XXXXL
XXBRX
XXRRR
4
RRRR
XLXX
BXLR
RRLX
```

```output2
No
Yes
```

## 样例 1 解释

字符 `G` 标出了 Sleeping Bear 一种**可能的**逃生路线：

```plain
XXRRR
XRRRR
XXXXL
XXBRG
XXGGG
```

## 数据范围

- 对于 $50\%$ 的数据，$1 \le T \le 10$，$2 \le k \le 10$。
- 对于 $100\%$ 的数据，$1 \le T \le 10$，$2 \le k \le 1000$。
- 保证地图上只有 `B`、`X`、`R`、`L`  四种字符，其中 `B` 有且仅有一个。
- **数据不对 `L` 的数量做任何保证！**
