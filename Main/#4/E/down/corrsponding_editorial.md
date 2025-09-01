爆搜可得答案序列：

$$1,3,5,11,21,43,85,171,341,683,\ldots$$

瞪眼可得公式：

$$A_n=\begin{cases}1,&n=1\\2A_{n-1}-1,&n=2k+1\\2A_{n-1}+1,&n=2k\end{cases}(k \in \mathbb{Z})$$

化简可得：

$$A_n=\begin{cases}\dfrac{4^{k+1}-1}{3},&n=2k+1\\\\\dfrac{4^{k+1}+2}{6},&n=2k\end{cases}(k \in \mathbb{Z})$$

实际上这就是 [OEIS A001045](https://oeis.org/A001045)：

$$A_n=\begin{cases}2n-1,&n\le 2\\A_{n-1}+2A_{n-2},&n\ge 3\end{cases}$$
