# 4 - 格式化字符串
* 格式化字符串demo
```
void congratulateStudent(char *student, char *course, int numDays) {
	printf("%s has done as much %s programming as I could fit into %d days.\n", student, course, numDays);
}
// %s - 字符串
// %d - 整数。d 代表十进制数（decimal）
// \n - 转义字符（escape sequence）,转义字符已\开始，它告诉编译器跟在它之后的字符不具有原本的意义
// 例如：\"，就是输出双引号
```