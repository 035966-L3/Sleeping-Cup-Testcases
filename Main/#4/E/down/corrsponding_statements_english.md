## Source

**This problem is adapted from [Long Long OJ](https://www.llong.tech/). All rights reserved.**

## Problem Description

A new bitwise operation $\sharp$ is defined as follows: $0\sharp0=1$, $0\sharp1=1$, $1\sharp1=1$, $1\sharp0=0$.

Output the number of 01 strings of length $N$ (modulo $998\ 244\ 353$) that satisfy the following conditions:

- $((((A_1\sharp A_2)\sharp A_3)\sharp\cdots)\sharp A_{N-1})\sharp A_N=1$;
- $A_1\sharp(A_2\sharp(A_3\sharp(\cdots\sharp(A_{N-1}\sharp A_N))))=1$.

## Input Format

One line consisting of a positive integer $N\ (1 \le N \le 10^{10^5 + 1})$.

## Output Format

The result modulo $998\ 244\ 353$.

## Samples

```input1
20
```

```output1
699051
```
