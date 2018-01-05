# Yogurt Factory

### 描述
The cows have purchased a yogurt factory that makes world-famous Yucky Yogurt. Over the next N (1 <= N <= 10,000) weeks, the price of milk and labor will fluctuate weekly such that it will cost the company C_i (1 <= C_i <= 5,000) cents to produce one unit of yogurt in week i. Yucky's factory, being well-designed, can produce arbitrarily many units of yogurt each week.

Yucky Yogurt owns a warehouse that can store unused yogurt at a constant fee of S (1 <= S <= 100) cents per unit of yogurt per week. Fortuitously, yogurt does not spoil. Yucky Yogurt's warehouse is enormous, so it can hold arbitrarily many units of yogurt.

Yucky wants to find a way to make weekly deliveries of Y_i (0 <= Y_i <= 10,000) units of yogurt to its clientele (Y_i is the delivery quantity in week i). Help Yucky minimize its costs over the entire N-week period. Yogurt produced in week i, as well as any yogurt already in storage, can be used to meet Yucky's demand for that week.

### 输入
* Line 1: Two space-separated integers, N and S.

* Lines 2..N+1: Line i+1 contains two space-separated integers: C_i and Y_i.

### 输出
* Line 1: Line 1 contains a single integer: the minimum total cost to satisfy the yogurt schedule. Note that the total might be too large for a 32-bit integer.

### 样例输入
```
4 5
88 200
89 400
97 300
91 500
```

### 样例输出
```
126900
```

### 提示
OUTPUT DETAILS:
In week 1, produce 200 units of yogurt and deliver all of it. In week 2, produce 700 units: deliver 400 units while storing 300 units. In week 3, deliver the 300 units that were stored. In week 4, produce and deliver 500 units.

### 代码

```cpp
#include <iostream>

using namespace std;

int main(void)
{
    int n, s;
    cin >> n >> s;
    int c, y;
    int min_price = 6000;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c >> y;
        if (c < (min_price + s)) {
            min_price = c;
            sum += (long long)c * (long long)y;
        }
        else {
            min_price = min_price + s;
            sum += (long long)min_price * (long long)y;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
```