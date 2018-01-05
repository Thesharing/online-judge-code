/*

描述
任何一个正整数都可以用2的幂次方表示。例如：

    137=2^7+2^3+2^0

同时约定方次用括号来表示，即ab可表示为a(b)。由此可知，137可表示为：

    2(7)+2(3)+2(0)

进一步：7=2^2+2+2^0（2^1用2表示）

        3=2+2^0

所以最后137可表示为：

    2(2(2)+2+2(0))+2(2+2(0))+2(0)

又如：

    1315=2^10+2^8+2^5+2+1

所以1315最后可表示为：

    2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

输入
一个正整数n（n≤20000）。

输出
一行，符合约定的n的0，2表示（在表示中不能有空格）。

样例输入
137

样例输出
2(2(2)+2+2(0))+2(2+2(0))+2(0)

*/

#include <iostream>
#include <cmath>

using namespace std;

int max(int num){
	int i;
	for (i = 15; i >= 0; i --) {
		if (int(pow(2, i) + 0.5) <= num) {
			return i;
		}
	}
	return 0;
}

int main(void){
	char map[16][30] = {"(0)", "", "(2)", "(2+2(0))", "(2(2))", "(2(2)+2(0))", "(2(2)+2)", "(2(2)+2+2(0))",
						"(2(2+2(0)))", "(2(2+2(0))+2(0))", "(2(2+2(0))+2)", "(2(2+2(0))+2+2(0))", "(2(2+2(0))+2(2))",
						"(2(2+2(0))+2(2)+2(0))", "(2(2+2(0))+2(2)+2)","(2(2+2(0))+2(2)+2(2)+2+2(0)))"};
	int num;
	cin >> num;
	int n = max(num);
	for(int i = n; i >= 0; i--){
		int diff = num - (int)(pow(2, i) + 0.5);
		if(diff > 0){
			cout << "2" << map[i] << "+";
			num = diff;
		}
		else if(diff == 0){
			cout << "2" << map[i] << endl;
			break;
		}
	}
	return 0;
}
