## 注意

**请严格按照提交方式进行操作。**

## 题目描述

现有一份答案文件和一份输出文件，请将两者进行全文比对，并返回相关信息。

## 提交方式

请使用以下模板。请在 (2) 处完善函数 `check` 的代码，使其能够按照题目要求返回相关信息。如有需要（虽然 std 没有这个需要），可以在 (1) 出定义变量，函数等。**除此之外，你不应该改动模板中的任何代码。** 完成代码后，请使用 C++ 进行提交。

在 `check` 函数中：

- `answer`：答案文件，只含有 ASCII 可见字符，半角空格和换行符（`\n`），长度不大于 $10^6$。
- `output`：输出文件，只含有 ASCII 可见字符，半角空格和换行符（`\n`），长度不大于 $10^6$。
- 返回值应参照下列 $6$ 个模板，结合比对结果给出：
  - `Accepted.`（完全一致）
  - `Wrong Answer: Missing Line on Line %d.`（文末缺行，输出文件没有那一行）
  - `Wrong Answer: Missing Character on Line %d, Column %d.`（行末缺字符）
  - `Wrong Answer: Extra Line on Line %d.`（文末多行，答案文件没有那一行）
  - `Wrong Answer: Extra Character on Line %d, Column %d.`（行末多字符）
  - `Wrong Answer: Wrong Answer on Line %d, Column %d.`（字符不一致）

**此外，下发文件（样例）中的 `.ans` 文件和 `.out` 文件中包含某些重要信息（例如，当你比对出多处错误时，应按照第一处错误给出返回值），请在开始编写代码前仔细阅读。**

```cpp
#include <bits/stdc++.h>
using namespace std;
// (1)
string check(string answer, string output)
{
    if (answer == output) return "Accepted.";
    // (2)
}
int main()
{
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    string ansa, out;
    stringstream s0, s1, s2;
    bool sepa = false;
    char c = getchar();
    while (c != EOF)
    {
        s0 << (int) c << endl;
        if (c == 127) sepa = true;
        else if (sepa) s2 << '*';
        else s1 << '*';
        c = getchar();
    }
    s1 >> ansa;
    s2 >> out;
    int tmp = 0, cnt = 0;
    sepa = false;
    while (s0 >> tmp)
    {
        if (tmp == 127)
        {
            sepa = true;
            cnt = 0;
        }
        else
        {
            if (sepa) out[cnt] = tmp;
            else ansa[cnt] = tmp;
            cnt++;
        }
    }
    cout << check(ansa, out);
    return 0;
}
```

## 样例

**请在「下发文件」处获取样例。**

共有 $17$ 个。其中 `.in` 为实际输入文件，`.ans` 为答案文件，`.out` 为输出文件，`.chk` 为你应该输出的结果。

**在本地测试样例时，你应该将 `.in` 文件作为输入文件，并将输出结果与 `.chk` 文件进行比对。`.ans` 文件和 `.out` 文件在测试时可以删去。**
