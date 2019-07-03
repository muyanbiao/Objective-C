# 11 - 对象（Objects）
1. 对象（Objects）
	* 对象和结构类似
	* 和结构一样，一个对象可以保存多个相关的数据
	* 结构中称这些数据为**成员（member）**
	* 对象中称这些数据为**实例变量（instance variable，也简称”ivars“）**
	* 对象和结构的不同：对象还可以包含一组函数，并且这些函数可以使用对象所保存的数据。这类函数称为**方法（methods）**
2. 类（Classes）
	* **类(class)** 负责描述某个特定类型的对象，包括实例变量和方法
	* 类可以描述两种对象：
		1. 抽象概念：如数据、字符串或指令集
		2. 实际存在的事物：如人、地点或储蓄账户
	* 一个类**定义了**一种对象
	* 同时也可以用来**创建**这种对象
	* 类是对象的**原型**
	* 又是生产对象的**工厂**  
	![image](https://github.com/muyanbiao/Objective-C/blob/master/chapter11/Resources/objects1.png)
3. 创建并使用对象（Creating and using your first object）
```
#import <Foundation/Foundation.h>
// #import指令 - 让编译器先检查之前是否已经导入过这个文件，或是已经包含到目标文件夹中了
// #include指令 - 告诉编译器做呆板的复制粘贴，将包含的内容粘贴到目标文件中
int main(int argc, const char *argv[])
{
	@autoreleasepool {
		NSDate *now = [NSDate date];	// 新建now指针 - 保存了NSDate实例在内存中的地址
		NSLog(@"This NSDate object lives at %p", now);	//输出NSDate实例在内存中的地址
	}
}
```
4. 方法和消息（Methods and messages）
	* OC中，如需执行方法里的代码，首先需要发送一条消息给包含这个方法的对象或类
	* `NSDate *now = [NSDate date];`
5. 消息发送（Message sends）  
![image](https://github.com/muyanbiao/Objective-C/blob/master/chapter11/Resources/objects2.png)
	* date方法执行后，NSDate类会在堆上给NSDate实例声明一部分内存，将NSDate实例初始化为当前的日期/时间，然后返回新对象的地址
`NSLog(@"The date is %@", now); // %@格式说明符会输出相应对象的”描述信息“`
6. 详解消息（Another message）
```
	double seconds = [now timeIntervalSince1970];	// 向now指针指向的NSDate实例发送消息timeIntervalSince1970
	NSLog(@"It has been %f seconds since the start of 1970.", seconds);
// OS X 和 iOS系统都是基于Unix开发的，1970是“Unix时代”的开始
```
7. 类方法与实例方法（Class methods vs. instance methods）
	* `NSDate *now = [NSDate date];`	// `date`是**类方法（Class methods）**。类方法会创建类的实例，并初始化实例变量
	* `double seconds = [now timeIntervalSince1970];`	// `timeIntervalSince1970`是**实例方法（instance methods）**。实例方法会提供实例的实例变量的信息，或对实例的实例变量进行操作。  
	![image](https://github.com/muyanbiao/Objective-C/blob/master/chapter11/Resources/objects3.png)
8. Objective-C语言命名习惯
	* **指向实例的变量**使用“驼峰拼写法（camel case）”来命名。以小写字母开头，接下来每个单词首字母使用大写，如`now、 weightLifter、 myCurrentLocation`。
	* **方法**的命名也是用驼峰拼写法，如`date、bodyMassIndex、timeIntervalSince1970`。
	* **类**的名称以大写字母开头，接下来的单词继续使用驼峰拼写法：`NSDate、Person、CLLocation、NSMutableArray`
		* 类要加前缀，可以避免相似的类名造成的混乱
		* 通过前缀可以知道类属于哪个框架
			* Foundation框架的类使用**NS**前缀，如`NSDate、NSLog`，**NS**是`NEXTSTEP`的缩写，Foundation框架就是基于这个平台构建出来的。
	* 很多苹果公司创建的类型和常量的命名也是前缀大写的驼峰拼写法。如：`NSInteger`并不是类，它只是一个整型类型。`NSOKButton`只是一个等于1的常量
