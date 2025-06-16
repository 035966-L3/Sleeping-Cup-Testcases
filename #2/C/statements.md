## 注意

**本题需要使用文件读写（`honey2.in` / `honey2.out`）。**

## 题目背景

Sleeping Bear 是一只十分可爱的小熊，它越吃蜂蜜就越可爱，可是它每次去摘蜂蜜都会被蜜蜂蛰一头包。今天它又要吃蜂蜜了，但是它不想又被蜜蜂蛰一头包，所以它想请你帮助它设计一条逃生路线以躲避蜜蜂的围追堵截。

## 题目描述

给定一个正整数 $k$，表示有一个 $k \times k$ 的地图，其中有字符 `B`、`X`、`R`、`L` 分别表示 Sleeping Bear 所在的位置（默认蜜蜂就在它身后），不能走的路，可以走的路以及湖的位置（只有 Sleeping Bear 跳入湖中才能不被蜜蜂蛰）。

已知：

- **`B` 的位置按照 `R` 的位置处理。**
- Sleeping Bear 可能在任何一个 `R` 的位置。
- Sleeping Bear 在开始逃生时可以面向**任何方向**（上、下、左、右）。
- Sleeping Bear 每次可以执行以下操作之一：
  - 沿着所面向的方向，向前走一格。
  - 左转（逆时针转向）$90^\circ$，然后向前走一格。
  - **也就是说，Sleeping Bear 每次只能直行或左转，不能掉头或右转。**
- 如果 Sleeping Bear 能够从某个 `R` 的位置走到任意一个 `L` 的位置，则这个 `R` 的位置是安全的。

请帮 Sleeping Bear 判断一下，哪些位置是安全的。

## 输入格式

**本题有多组测试数据。**

第一行输入一个整数 $T$，表示测试数据的数量。

对于每组测试数据：

第一行输入一个整数 $k$，表示有一个 $k \times k$ 的地图。

接下来 $k$ 行，每行输入 $k$ 个字符，表示这个地方的状态。

## 输出格式

对于每组测试数据，输出 $k$ 行，每行 $k$ 个字符：

- 如果某个 `R` 的位置是安全的，则将它替换成 `L` 输出。
- 如果某个 `R` 的位置不是安全的，则将它替换成 `X` 输出。
- **`B` 的位置按照 `R` 的位置处理。**
- 所有的 `L` 和 `X` 原样输出。

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
XXXXL
XXXXL
XXXXL
XXLLL
XXLLL
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
XXXXX
XXXXX
XXXXL
XXXXX
XXXXX
XLLL
XLXX
LXLL
LLLX
```

## 样例 1 解释

举个例子，`B` 位置是安全的，因为该位置存在逃生路线。

当 Sleeping Bear 的初始方向**向右**时，字符 `G` 标出了它**唯一的**逃生路线：

```plain
XXRRR
XRRRR
XXXXL
XXBGG
XXRRR
```

当 Sleeping Bear 的初始方向**向左**时，字符 `G` 标出了它一种**可能的**逃生路线：

```plain
XXRRR
XRRRR
XXXXL
XXBRG
XXGGG
```

实际上，它也可以在右下角的四个格子内绕任意多圈。

当 Sleeping Bear 的初始方向**向下**时，上面两种逃生路线都是可能的。

当 Sleeping Bear 的初始方向**向上**时，它将无法逃生。

## 数据范围

- 对于 $50\%$ 的数据，$1 \le T \le 10$，$2 \le k \le 10$。
- 对于 $100\%$ 的数据，$1 \le T \le 10$，$2 \le k \le 1000$。
- 保证地图上只有 `B`、`X`、`R`、`L`  四种字符，其中 `B` 有且仅有一个。
- **数据不对 `L` 的数量做任何保证！**
