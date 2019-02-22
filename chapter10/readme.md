# 10 - 堆（The Heap）
* **栈**内存控件
	* 在调用函数时由系统自动分配，并在函数结束后自动释放
	* 也是**局部变量**被称为**自动变量（automatic variable）**
* 仅有自动变量是不够的，有时还要“申请”一块连续的内存 — **缓冲区（buffer）**
* **缓冲区（buffer）**来自特定的内存区域 - **堆**
* **堆和栈**是分开的
* 在**堆**上，**缓冲区**独立于任何函数的**栈**。因此，它可以在多个函数中使用。例如：
	* 声明一个缓冲区储存一些文件
	* 调用**函数A**将文本文件保存到缓冲区中
	* 再调用**函数B**来统计文本中元音字母的个数
	* 最后再调用**函数C**来进行校对
	* 处理完文本文件后，就可以将缓冲区的这块内存返还给**堆**
* 常用缓冲区函数
	* `malloc()` - 得到一块内存缓冲区
	* `free()` - 释放内存缓冲区，将其返还给堆
	* `sizeof()` - 获得缓冲区的准确大小
* 示例代码1
```
#include <stdio.h>
#include <stdlib.h>	// malloc()和free()都源自stdlib

int main(int argc, const char *argv[])
{
	// 声明指针变量
	float *startOfBuffer;

	// 从对分配制定字节的内存
	startOfBuffer = malloc(1000 * sizeof(float));

	// ······使用缓冲区······

	// 释放之前被分配到的内存，使之能够被重新使用
	free(startOfBuffer);

	// 将指针变量赋为空
	startOfBuffer = NULL;

	return 0;
}
```  
![image](https://github.com/muyanbiao/Objective-C/blob/master/chapter10/Resources/the_heap1.png)

* 示例代码2
```
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float heightInMeters;
	int weightInKilos;
} Person;

float bodyMassIndex(Person *p)
{
	return p->weightInKilos / p->heightInMeters * p->heightInMeters;
}

int main(int argc, const char *argv[])
{
	// 为一个Person结构分配内存
	Person *mikey = (Person *)malloc(sizeof(Person));
	
	// 为这个Person结构的成员变量赋值
	mikey->weightInKilos = 96;
	mikey->heightInMeters = 1.7;

	// 计算并输出BMI
	float mikeyBMI = bodyMassIndex(mikey);
	printf("mikey has a BMI of %f\n", mikeyBMI);
	
	// 释放占用的内存，使之能够被重用
	free(mikey);

	// 将指针变量赋为空
	mikey = NULL;

	return 0;
}
```  
![image](https://github.com/muyanbiao/Objective-C/blob/master/chapter10/Resources/the_heap2.png)