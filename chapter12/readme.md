# 12 - 再谈消息（More Messages）
### 本章学习带参数的消息、消息的嵌套发送等知识
1. 传递实参的消息（A message with an argument）  
![image](https://github.com/muyanbiao/Objective-C/blob/master/chapter12/Resources/more_message1.png)
2. 多个实参(Multiple arguments)  
![image](https://github.com/muyanbiao/Objective-C/blob/master/chapter12/Resources/more_message2.png)  
```
#import <Foundation/Foundation.h>
int main(int argc, const char *argv[])
{
	@autoreleasepool {
		NSDate *now = [NSDate date];
		NSCalendar *cal = [NSCalendar currentCalendar];
		[cal ordinalityOfUnit:NSDayCalendarUnit
		     inUnit:NSMonthCalendarUnit
		    forDate:now];
	}
}
```  
3. 消息的嵌套发送（Nesting message sends）  
	* `double seconds = [[NSDate date] timeIntervalSince1970];`
	* 嵌套发送的消息，系统会**先执行最里面**的消息，然后按**由内至外**的顺序依次执行外层消息。
4. alloc 和 init（allock and init）
	* **唯一必须以嵌套**的形式**连续发送**的消息是alloc 和 init
	* 每个类都有一个`alloc`方法
		* 创建一个新对象，并返回一个指向该对象的**指针**
		* 通过`alloc`创建出来的对象，**必须经过初始化才能使用**
		* 如果创建出来的对象没有经过初始化，它会存在于内存里，但无法接收消息
	* 每个类都有一个`init`实例方法，它用来初始化实例
		* `NSDate *now = [[NSDate alloc] init];`
		* `[NSDate date]`中的**date**方法可以用最少的代码获取一个**NSDate**实例，我们称这种方法为**便利方法（convenience method）**
5. 向**nil**发送消息（Sending messages to nil）
	* **nil** - 值为0的指针（不指向任何对象的指针）
	* 多数面向对象的语言不允许向**nil**发送消息
	* OC可以向**nil**发送消息，什么事情都不会发生，但是要注意：
		1. 如果程序向某个对象发送了消息，却没有得到预期的结果，请检查消息接收方是否为**nil**
		2. 向**nil**发送消息，得到的返回结果没有意义
6. id
	* id类型：可以指向任意类型Objective-C对象的指针，如
		* `id delegate;`
	* 注，id声明的变量**不需要加*-星号**，id已经隐含了星号的作用
