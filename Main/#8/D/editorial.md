注意到子串的权值在其中一个端点固定时随着另一个端点向外扩展而单调递增，可以使用双指针统计答案。

将原序列反转，改为匹配子序列 $\{\texttt 2, \texttt 3, \texttt 3, \texttt 3\}$，分别维护子序列 $\{\texttt 2\}, \{\texttt 2, \texttt 3\}, \{\texttt 2, \texttt 3, \texttt 3\}, \{\texttt 2, \texttt 3, \texttt 3, \texttt 3\}$ 的出现次数即可实现双指针移动时对权值的实时计算。

最终的时间复杂度为 $O(n)$，空间复杂度为 $O(1)$，其中输入的字符串 $S$ 不计入空间复杂度。
