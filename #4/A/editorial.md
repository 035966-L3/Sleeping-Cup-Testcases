**看清总评价的计算公式**后利用 `struct` 和 `sort` 排序即可。

为了避免精度误差，建议按 $k=(2m+n)t$（将原来的公式除以 $0.03$）计算总评价，此时需要使用 `long long`。（当然了，直接使用 `double` 或 `long double` 也是一个不错的选择。）
