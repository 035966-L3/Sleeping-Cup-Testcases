## 圆心解法

1. 在两个维度上取圆内的点坐标的平均值为圆心。
2. 在两个维度上计算圆内的点坐标的极值，取中点为圆心。
3. 在两个维度上切片，取圆内的点密度最大的坐标为圆心。
4. 在两个维度上取到圆内所有点距离之和最小的坐标为圆心。


## 半径解法

1. 取圆内的点距圆心的最大距离为半径。
2. 计算圆内的点距圆心的平均距离，利用积分折算为半径。
3. 计算圆内的点的密度，估计圆的面积，利用圆的面积公式折算为半径。
4. 在两个维度上计算圆内的点坐标的极值，取极差为直径，然后折算为半径。

## 标准程序解法

标准程序使用了圆心解法 1 和半径解法 3。
