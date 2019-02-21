# 7 - 地址与指针（Address and Pointers）
0. 内存和CPU（RAM and CPU）
	* 计算机核心部件 = ~处理器（中央处理器 - CPU）~ + ~海量的”开关“（随机存取器 - RAM）~
	* 处理器可以打开或者关闭这些开关
	* 一个开关保存一位（bit）信息。1 - 开，0 - 关
	* 8个开关保存一个字节（byte）
	* 内存是有数字编号的
	* 通常用地址（address）来指代某个特定字节的数据
	* 32位或者64位是指地址的大小  
	![image](https://github.com/muyanbiao/Objective-C/blob/master/chapter7/Resources/cpu_ram.png)

1. 获取地址（Getting addresses）
	* 变量地址 - 指内存中的某个位置，该位置的内存保存着变量的值。
	* 通过&运算符，可以得到变量的地址
	```
	#include <stdio.h>
	int main(int argc, const char *argv[])
	{
		int i = 17;
		printf("i stores its value at %p\n", &i);
		// %p - 针对内存地址的格式说明符
		// 输出：i stores its value at 0xbffff738
		printf("this function starts at %p\n", main);
		// 通过函数名能得到相应函数的地址
	}	
	```
2. 用指针保存地址（Storing addresses in pointers）
	* `float *ptr;` - 名为ptr的**变量**用于保存浮点数变量的**地址**，即ptr是指向某个浮点数变量的指针（pointer）
	```
		int main(int argc, const char *argv[])
		{
			int i = 17;
			int *addressOfI = &i;
			printf("i stores its value at %p\n", addressOfI);
			// 输出：i stores its value at 0xbffff738
		}	
	```
	* 指针存在的意义：
		1. 当遇到比正数大得多、也复杂得多的数据时，就有必要用指针来传递地址了
		2. 因为程序不一定能通过拷贝来传递数据，但一定能够直接传递或通过拷贝来传递数据的起始地址
		3. 一旦有数据的起始地址，就能很容易地存取相应数据

3. 通过地址访问数据（Getting the data at an address）
	1. 使用*运算符，可以访问保存在某个地址中的数据
		* `int *addressOfI = &i; // 声明指针` 
		* `printf("the int stored at addressOfI is %d\n", *addressOfI); // 访问保存在addressOfI地址中的int值` 
		* `*addressOfI = 89; // 在赋值表达式左边使用*运算符，将数据保存在指定的地址中` - 
		* 指针也可以称为**引用**
		* 通过指针访问某个地址中的数据 - **去引用**
	2. `addressOfI = 89; // Xcode显示警告信息：Incompatible integer to pointer conversion assigning to 'int *' from 'int'(不兼容的赋值类型转换，将int赋给int *)`
4. 不同类型的数据所占内存的大小（How many bytes?）
	1. `sizeof() // 获取某个数据类型的大小`
		```
		printf("An int is %zu bytes\n", sizeof(int));
		printf("A pointer is %zu bytes\n", sizeof(int *));
		// %zu - sizeof() 返回一个类型为size_t的数，与之对应的格式说明符就是zu%
		// 指针的长度为4个字节 - 程序在32位模式下运行
		// 指针的长度为8个字节 - 程序在64位模式下运行
		```
5. **NULL**
	1. ”空“指针 - 不指向任何地址
	2. 即：有一个能够保存地址的指针变量，但是要赋上某个值，用于明确表示该指针没有指向任何地址
	```
	float *myPointer;
	myPointer = NULL;	// 暂时将myPointer赋为NULL，程序稍后会存入某个地址指针
	...
	// myPointer指针是否为空
	if (myPointer) {
		// myPointer 不是NULL
		......处理myPointer指向的数据......
	} else {
		// myPointer 是NULL
	}
	```
	3. **Objective-C**中使用**nil**来代替**NULL**
6. 指针声明的代码规范（Stylish pointer declarations）
```
float *powerPtr;	// float指针
float *b, c; // b - float指针，c - float变量
float *b, *c; // b,c - float指针	
```
