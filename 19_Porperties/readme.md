# 17 - 属性
* 属性的声明
	* `@property(nonatomic, readonly) double circumferenceOfEarth;`
* **属性特性（property attributes）**
	* **atomic(原子性) vs. nonatomic(非原子性)** - 和多线程运行有关
		* 系统默认**atomic**，所有所有的属性都要显性设置为nonatomic
	* 存取属性
		* **readonly（只读属性），readwrite（读写属性）**，默认是**readwrite**
	* 生命周期类型（lifetime specifier）
		* **unsafe_retained、assign、strong、weak、copy** ，这些特性决定了存方法将如何处理与其相关的内存管理问题
		* **assign**：存方法会将传入的值直接赋给实例变量，如下所示：
			```
			@property(assign) int averageScore;
			// 上面的属性声明相当于实现了下面的存方法
			- (void)setAvergaeScore:(int)d
			{
				_averageScore = d;
			}
			```
			* `assign`特性用来保存非对象类型的实例变量。
			* 非对象类型的实例变量**默认**使用assign特性，**不需要显示添加**
		* **strong**：要求保留传入的对象，并放弃原有对象（如果原有对象不再有其他拥有方，就会被释放）。凡是**指向对象**的实例变量，通常都应该使用strong特性。
		* **weak**：要求不保留传入的对象。如果该对象被释放，那么响应的实例变量会被自动赋为nil。
			* 这是为了避免**悬空指针**。
			* **悬空指针**指向的是不存在的对象。
			* 向**悬空指针**发送消息会导致程序崩溃。
			* 相应的**存方法**会**将传入的对象直接赋给实例变量**。
		* **unsafe_unretained**：和`weak`特性类似，要求不保留传入的对象。然后，如果该对象被释放，相应的实例变量不会被自动赋值为nil
		* **copy**：拷贝传入的对象，并将新对象赋给实例变量。
			* 声明NSString或NSArray对象的属性时，都需要设置copy属性。
			```
			@property(copy) NSString *lastName;
			//以上的存方法等同于以下代码
			- （void）setLastName:(NSString *)d {
				lastName = [d copy];
			}
			```