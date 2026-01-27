由于 $\left| \dfrac{1 - \sqrt{5}}{2} \right| < 1$，当 $n \to +\infty$ 时，$\left( \dfrac{1 - \sqrt{5}}{2} \right)^n \to 0$，此时 $\dfrac{\left( \dfrac{1 + \sqrt{5}}{2} \right)^n - \left( \dfrac{1 - \sqrt{5}}{2} \right)^n}{\sqrt{5}} \to \dfrac{\left( \dfrac{1 + \sqrt{5}}{2} \right)^n}{\sqrt{5}}$，于是方程可以近似写成（显然 $R \ne \dfrac{\sqrt{5} - 1}{2}$）:

$$\begin{cases}\displaystyle\sum _{i = 1} ^{2n} \dfrac{\left( \dfrac{1 + \sqrt{5}}{2} \right)^i}{\sqrt{5}} R^{i - 1} = 0 \\ R \ne \dfrac{\sqrt{5} - 1}{2}\end{cases}$$

$$\begin{cases}\displaystyle\sum _{i = 0} ^{2n - 1} \left( \dfrac{1 + \sqrt{5}}{2} \right)^i R^i = 0 \\ R \ne \dfrac{\sqrt{5} - 1}{2}\end{cases}$$

$$\begin{cases}\dfrac{1 - \left( \dfrac{1 + \sqrt{5}}{2} R \right)^{2n}}{1 - \left( \dfrac{1 + \sqrt{5}}{2} \right) R} = 0 \\ R \ne \dfrac{\sqrt{5} - 1}{2}\end{cases}$$

$$\begin{cases}\left( \dfrac{1 + \sqrt{5}}{2} R \right)^{2n} = 1 \\ R \ne \dfrac{\sqrt{5} - 1}{2}\end{cases}$$

$$\dfrac{1 + \sqrt{5}}{2} R = -1$$

$$R = \dfrac{1 - \sqrt{5}}{2}$$

```plain
-0.6180339887
```
