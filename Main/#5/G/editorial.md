让我们先约定一些记号：

- $\alpha$ 和 $\beta$ 代指要复原的两个平行平面。
- $A_1,A_2,\ldots$ 和 $B_1,B_2,\ldots$ 分别代指 $\alpha$ 和 $\beta$ 上的点。
- $l(A,B)$ 代指直线 $AB$，即通过点 $A$ 和点 $B$ 的直线。
- $C \in l$ 代表点 $C$ 在直线 $l$ 上。特别地，$C \in l(A,B)$ 代表 $A,B,C$ 三点共线。
- $C \notin l$ 代表点 $C$ 不在直线 $l$ 上。特别地，$C \notin l(A,B)$ 代表 $A,B,C$ 三点不共线。
- $C \in \gamma$ 代表点 $C$ 在平面 $\gamma$ 上。
- $l \subset \gamma$ 代表直线 $l$ 在平面 $\gamma$ 上。
- $\bm{h}$ 代指 $\alpha$ 和 $\beta$ 的法向量。
- $f(A,B,C)$ 代指 $\triangle ABC$ 的[法向量](https://baike.baidu.com/item/%E6%B3%95%E5%90%91%E9%87%8F/1161324)，其求法请参考 [Luogu P4894](https://www.luogu.com.cn/problem/P4894)。
- $s(A,B,C)$ 代指 $\triangle ABC$ 所在的平面。
- $\bm{a}\ /\!/\ \bm{b}$ 代表向量 $\bm{a}$ 和 $\bm{b}$ [共线](https://baike.baidu.com/item/%E5%B9%B3%E8%A1%8C%E5%90%91%E9%87%8F/2090261?fromtitle=%E5%85%B1%E7%BA%BF%E5%90%91%E9%87%8F&fromid=6138110)。
- $\bm{a}\,\ \bcancel{\!/\!/\!}\ \,\bm{b}$ 代表向量 $\bm{a}$ 和 $\bm{b}$ 不共线。
- $\alpha\ /\!/\ \beta, a\ /\!/\ \beta,a\ /\!/\ b$ 代表对应元素平行，其中 $a,b$ 为直线，$\alpha,\beta$ 为平面。
- $\alpha \perp \beta, a \perp \beta,a \perp b$ 代表对应元素垂直，其中 $a,b$ 为直线，$\alpha,\beta$ 为平面。
- $s(A,B,C)\ /\!/\ s(D,E,F)$ 代指 $\triangle ABC$ 和 $\triangle DEF$ 所在的平面平行，这等价于 $f(A,B,C)\ /\!/\ f(D,E,F)$。

在回到正题之前，让我们考虑三个特殊情况——

特殊情况 $1$：$n=1$，此时输出 `01` 显然正确。

> 实际上，$n=1$ 时一定有解——过点 $X$ 作平面 $\alpha \perp l$，过点 $Y$ 作平面 $\beta \perp l$，就可以得到满足要求的一组平面 $\alpha$ 和 $\beta$，其中 $X$ 和 $Y$ 是给出的两个点，$l$ 代指直线 $XY$。

特殊情况 $2$：$n=2$，此时可以直接枚举划分方案。设所划分的 $2$ 组（每组 $2$ 个）点分别是 $X_1,X_2$（$X_1 \in \alpha,X_2 \in \alpha$）和 $Y_1,Y_2$（$Y_1 \in \beta,Y_2 \in \beta$），并用 $l_1$ 代指直线 $X_1X_2$，$l_2$ 代指直线 $Y_1Y_2$。由立体几何基本事实 2（或者[此处](https://baike.baidu.com/item/%E7%AB%8B%E4%BD%93%E5%87%A0%E4%BD%95/1365715#5)的公理 1）的[推论](https://easylearn.baidu.com/edu-page/tiangong/questiondetail?id=1727646960247594674&fr=search)——直线与平面相交有且只有一个公共点，可知 $l_1 \subset \alpha,l_2 \subset \beta$。实际上，这个划分方案合法，当且仅当 $l_1$ 和 $l_2$ 平行或[异面](https://baike.baidu.com/item/%E5%BC%82%E9%9D%A2%E7%9B%B4%E7%BA%BF/10670021)。

> 当 $l_1$ 和 $l_2$ 平行时，由[立体几何基本事实推论 3](https://easylearn.baidu.com/edu-page/tiangong/questiondetail?id=1729570457280784270&fr=search)，同时满足 $l_1 \subset \gamma$ 和 $l_2 \subset \gamma$ 的平面 $\gamma$ 有且只有一个。过直线 $l_1$ 作平面 $\alpha \perp \gamma$，过直线 $l_2$ 作平面 $\alpha \perp \gamma$，就可以得到满足要求的一组平面 $\alpha$ 和 $\beta$。
>
> 当 $l_1$ 和 $l_2$ 异面时，过点 $X_2$ 作直线 $l_3\ /\!/\ l_2$，过点 $Y_2$ 作直线 $l_4\ /\!/\ l_1$，那么同时满足 $l_1 \subset \alpha$、$l_3 \subset \alpha$、$l_2 \subset \beta$、$l_4 \subset \beta$、$l_3 \subset \gamma$、$l_2 \subset \gamma$、$l_4 \subset \delta$、$l_1 \subset \delta$ 的平面 $\alpha,\beta,\gamma,\delta$ 都是唯一确定的。根据[线面平行的判定定理](https://baike.baidu.com/item/%E7%BA%BF%E9%9D%A2%E5%B9%B3%E8%A1%8C/8509225#1)和[面面平行的判定定理](https://baike.baidu.com/item/%E9%9D%A2%E9%9D%A2%E5%B9%B3%E8%A1%8C/714242#1)，由 $l_1\ /\!/\ l_4$ 可知 $l_1\ /\!/\ \beta$，由 $l_3\ /\!/\ l_2$ 可知 $l_3\ /\!/\ \beta$，从而 $\alpha\ /\!/\ \beta$——我们得到了满足要求的一组平面 $\alpha$ 和 $\beta$。
>
> 当 $l_1$ 和 $l_2$ 相交时，设 $l_1$ 和 $l_2$ 的交点是 $Z$，那么由 $Z \in l_1,Z \in l_2$ 和 $l_1 \subset \alpha,l_2 \subset \beta$，可知 $Z \in \alpha,Z \in \beta$——这与 $\alpha\ /\!/\ \beta$ 矛盾。也就是说，$l_1$ 和 $l_2$ 相交时，不存在满足要求的平面 $\alpha$ 和 $\beta$。

特殊情况 $3$：如果数据中存在 $m$ 点共线（即存在 $A_3,A_4,\ldots,A_n$ 满足 $A_i \in l(A_1,A_2)$，其中 $m \ge 3$），那么在所有合法的构造中，这 $m$ 个点一定落在同一个点。

> 让我们考虑使用反证法证明上述断言的正确性——让我们先假设上述断言是不正确的。
>
> 因为数据保证有解，所以一定存在另外一组平行但不重合的平面 $\alpha$ 和 $\beta$，使得：
>
> - 每个给定的点（包括 $A_1 \sim A_m$）都恰好落在 $\alpha$ 和 $\beta$ 中的某一个平面上。
> - $\alpha$ 和 $\beta$ 都包含了 $A_1 \sim A_m$ 中的至少一个点。
>
> 因为直线与平面相交有且只有一个公共点，结合上面的性质，可知 $\alpha$ 和 $\beta$ 都包含了 $A_1 \sim A_m$ 中的恰好一个点。
>
> 根据上述论证，结合上述断言所需要的前提条件，我们得到了以下结论：
>
> - 每个给定的点（包括 $A_1 \sim A_m$）都恰好落在 $\alpha$ 和 $\beta$ 中的某一个平面上。
> - $\alpha$ 和 $\beta$ 一共包含了 $A_1 \sim A_m$ 中的 $2$ 个点。
> - $m \ge 3$。
>
> 这 $3$ 条结论显然矛盾，因此假设不成立，上述断言一定是正确的。

接下来，我们回到正题。在下面的叙述中，我们默认 $n \ge 3$，因为 $n \le 2$ 的情况已经在上面讨论过了。

不难看出，任取 $3$ 个点（比如 $D_1,D_2,D_3$）就一定会有 $2$ 个点同时落在 $\alpha$（或 $\beta$）上，因此我们只需要尝试 $3$ 次就能确定 $2$ 个落在同一个待复原平面上的点。

不妨设 $A_1,A_2$ 均在 $\alpha$ 上，那么有：

- 由立体几何基本事实 2，如果 $P \in l(A_1,A_2)$，那么一定有 $P \in \alpha$。
- 对于满足 $A_i \notin l(A_1,A_2)$ 的 $A_i$，$f(A_1,A_2,A_i)\ /\!/\ \bm{h}$。
- 对于 $B_i$，$f(A_1,A_2,B_i)\,\ \bcancel{\!/\!/\!}\ \,\bm{h}$。

这启示我们（当 $D_i \notin l(A_1,A_2)$ 时）利用 `map` 对每个不同方向的 $f(A_1,A_2,D_i)$ 统计出现次数——一定有恰好 $n$ 个给定的点 $D_i$ 满足 $f(A_1,A_2,D_i)\,\ \bcancel{\!/\!/\!}\ \,\bm{h}$。

因此，我们只需要对每个出现次数符合要求的（可能的）$\bm{g}$，判定剩下 $n$ 个满足 $f(A_1,A_2,C_i)\,\ \bcancel{\!/\!/\!}\ \,\bm{g}$ 的点 $C_1 \sim C_n$ 是否在同一个法向量也为 $\bm{g}$ 的平面上（如果判定成功，那么这 $n$ 个点所在的平面就是平面 $\beta$）就可以了——这可以通过（先任取 $C_1 \sim C_n$ 中的 $2$ 个点——不妨设这 $2$ 个点分别是 $C_1$ 和 $C_2$，然后）对 $C_3 \sim C_n$ 检查其是否满足 $f(C_1,C_2,C_i)\ /\!/\ \bm{g}$ 和 $C_i \in l(C_1,C_2)$ 中的至少一条来实现。如果判定成功，我们直接对 $C_1 \sim C_n$ 输出 0，对另外 $n$ 个点输出 1，即可完成构造。

然而，如果数据中存在 $n-1$ 点共线（即存在 $A_3,A_4,\ldots,A_{n-1}$ 满足 $A_i \in l(A_1,A_2)$）的情况，那么我们在最坏情况下就需要判定 $n+1$ 次，上述做法的时间复杂度将退化为 $O(Tn^2 \log n + Tn^2 \log V)$（其中 $\log n$ 是 `map` 贡献的，$\log V$ 是化简法向量时使用的 `__gcd` 贡献的，且最坏情况下 $V=8 \times 10^{18}$），无法通过此题。

让我们考虑对每个 $\bm{g}$ 的判定进行优化。观察发现，我们可以另取 $2$ 个点 $E_1,E_2$（$E_1 \notin l(A_1,A_2)$，$E_2 \notin l(A_1,A_2)$），并（当 $D_i \notin l(E_1,E_2)$ 时）利用（另一个）`map` 对每个不同方向的 $f(E_1,E_2,D_i)$ 统计出现次数。对于每个 $\bm{g}$：

- 若 $f(A_1,A_2,E_1)\ /\!/\ \bm{g}$ 或 $f(A_1,A_2,E_2)\ /\!/\ \bm{g}$（注意到这样的 $\bm{g}$ 最多只有 $2$ 个，因为 $f(A_1,A_2,E_1)$ 和 $f(A_1,A_2,E_2)$ 各自只能对应一个方向的 $\bm{g}$），依然按原来的方法判断。
- 若 $f(A_1,A_2,E_1)\,\ \bcancel{\!/\!/\!}\ \,\bm{g}$ 且 $f(A_1,A_2,E_2)\,\ \bcancel{\!/\!/\!}\ \,\bm{g}$，那么 $C_1 \sim C_n$ 中一定包含了 $E_1,E_2$，我们只需要判定另外 $n-2$ 个 $C_i$ 是否满足 $f(E_1,E_2,C_i)\ /\!/\ \bm{g}$ 即可。此时我们的另一个 `map` 就派上用场了——因为对于 $A_i$ 一定有 $f(E_1,E_2,A_i)\,\ \bcancel{\!/\!/\!}\ \,\bm{g}$（否则由 $f(E_1,E_2,A_i)\ /\!/\ \bm{g}\ /\!/\ f(A_1,A_2,A_i)$ 得 $s(E_1,E_2,A_i)\ /\!/\ f(A_1,A_2,A_i)$，然而 $s(E_1,E_2,A_i)$ 和 $s(A_1,A_2,A_i)$ 有公共点 $A_i$，矛盾），所以我们只需要判定（当 $D_i \notin l(E_1,E_2)$ 时）是否有恰好 $n$ 个给定的点 $D_i$ 满足 $f(E_1,E_2,D_i)\,\ \bcancel{\!/\!/\!}\ \,\bm{g}$ 即可。

应用这一优化后，上述做法的时间复杂度将下降至 $O(Tn \log n + Tn \log V)$，可以通过本题。
