# 8 - 通过引用传递（Pass-By-Reference）
1. C语言`modf()`函数 - 传入double类型的数，可以得到该浮点数的整数部分和小数部分
	```
	#include <stdio.h>
	#include <math.h>

	int main(int argc, const char *argv[])
	{
		double pi = 3.14;
		double integerPart;
		double fractionPart;

		// 将integerPart的地址作为实参传入
		fractionPart = modf(pi, &integerPart);

		// 获取integerPart地址上的值
		printf("integerPart = %.0f, fractionPart = %.2f\n", integerPart, fractionPart);
	}
	```
	* `modf(pi, &integerPart);`这种传参方式称为**通过引用传递（pass-by-reference）**：调用函数时传入某个地址（也称为引用），然后由函数将数据存入该地址指向的内存
	* 对**通过引用传递**的形象比喻：
	> 假设我们负责为间谍委派任务。一天，我们通知某为间谍：想办法拿到财政部长和他的女朋友在一起的照片。我已经在公园的天石雕像下藏了一根短钢管，得到照片后，卷起来放在刚管里，我会在周二午饭后取走。用间谍的行话，称为
	> **情报传递点（dead drop）**  
	
	![image](https://github.com/muyanbiao/Objective-C/blob/master/chapter8/Resources/pass-by-reference.png)

2. 不要对`NULL`取值（Avoid dereferencing NULL）
	* 在对地址取值时，应该先检查指针是否为NULL
	```
	// 将someValue保存到ptr指针所指向的地址上之前，先判断地址是否为NULL
	if(ptr) {
		*ptr = someValue;
	}
	```
