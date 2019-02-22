# 17 - 属性
* 属性的声明
	* `@property(nonatomic, readonly) double circumferenceOfEarth;`
* **属性特性（property attributes）**
	* **atomic(原子性) vs. nonatomic(非原子性)** - 和多线程运行有关
		* 系统默认**atomic**，所有所有的属性都要显性设置为nonatomic
	* **readonly（只读属性），readwrite（读写属性）**
		* 默认是**readwrite**
	* 内存相关特性
		* `assign, copy, strong, weak`
			* **copy(可拷贝)**，声明NSString或NSArray对象的属性时，都需要设置copy属性。