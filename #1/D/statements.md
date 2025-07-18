现有这么一道题目：

> 在一座长度为 $T$ 的独木桥上有 $n$ 只小猪。
> 
> 现以独木桥左端为原点，向右为正方向建立数轴。
> 
> 已知 $n$ 只小猪的位置分别为 $a_1,a_2,\ldots,a_n$。
> 
> 现在，晚餐时间到了，它们要下桥吃饭。
> 
> 它们每秒同时按以下规则运动：
> 
> - 数一数它左边和右边各有多少只猪。
> - 向猪更少的那个方向移动。
> - 如果两边猪的数量相等，它不移动。
> - 处于桥两端的猪跳下独木桥。
> 
> 当然，如果桥上只剩下一只猪时，它就再也不下来了。
> 
> 求这些猪会在多少秒后全部停止移动（跳下了桥也算停止移动）。
> 
> 保证：
> 
> - $n<T$；
> - $n,T,a_i$ 均为正整数；
> - $0 < a_1 < a_2 < \ldots < a_n < T$。

以及这样一份代码：

```cpp
int solve(int T, int n, int a[])
{
	int l = 1, r = n, t = 0;
	while (l < r)
	{
		t++;
		for (int i = l; i <= r; i++)
		{
			if (i - l < r - i) a[i]--;
			if (i - l > r - i) a[i]++;
		}
		if (a[l] == 0) l++;
		if (a[r] == T) r--;
	}
	return t;
}
```

**在这份代码中，我们假设 $\bm{n,T}$ 可以无限大，数组 $\bm a$ 可以无限长，不受机器性能限制、时间限制、空间限制、`int` 范围限制等因素的影响。**

**请你分析上述代码的最坏时间复杂度，并给出证明。**

```plain
## 第一部分

上述代码的最坏时间复杂度是 $O(1)$。

## 第二部分

根据 [cq_irritater](/user/2) 第一公理，上述代码的最坏时间复杂度显然是 $O(1)$。

## 第三部分

以下是一组可能的数据：

- $n=1$。
- $T=2$。
- $a_1=1$。
```

你需要分三部分进行证明（以上是一份证明示例，它显然是错误的）：

- **第一部分：** 指出上述代码的最坏时间复杂度。
- **第二部分：** 证明上述代码的最坏时间复杂度不高于你所认为的时间复杂度。
- **第三部分：** 构造一组数据，使得上述代码的时间复杂度恰好退化为你所认为的时间复杂度。
