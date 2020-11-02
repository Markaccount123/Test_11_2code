#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//c语言预处理章
//翻译环境和执行环境
//翻译环境--1.预编译 2.编译 3.汇编阶段
//预编译就是文本操作 把头文件里的链接整过来，包括在预处理阶段把注释行变为空格代替  把test.c---test.i文件
//编译就是把c语言代码翻译成汇编代码   test.i--test.s 转换成了汇编语言
//汇编就是test.s--转换为test.o文件   把汇编语言转换为二进制代码  这一阶段会形成符号表---Add  0x200  即放符号也放地址
//在执行环境下 会形成test.o---test.exe文件                                    符号表下只会放置有效的地址
//链接 -- 1.合并段表  2.符号表的合并和符号表的重定位

//这里可能第一次没有听懂，但是不要灰心，在下面仔细的查找资料 好好的慢慢感受这些
//这里有一本书叫《程序员的自我修养》  可以好好看一下


//预定义符号
//int main()
//{
//	printf("%s\n", __FILE__);  //文件的路径
//	printf("%d\n", __LINE__);  //打印行号
//	printf("%s\n", __DATE__);  //打印日期
//	printf("%s\n", __TIME__); // 打印时间
//	printf("%s\n", __FUNCTION__); // 函数名
//  printf("%d\n", __STDC__);  //这里你会发现VS编译器并不满足这个c语言标准库  在这里他会报错，但是在gcc编译器下可以很好的运行起来
//	return 0;
//}


//为什么我在这里运行完以后我并不知道在哪里去找到我所开辟的这个log.txt文档 
//int main()
//{
//	int arr[10] = { 0 };
//	FILE* pf = fopen("log.txt", "w");
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		arr[i] = i;
//		fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);  //以格式化的形式往文件中打印
//	}
//	fclose(pf);
//	pf = NULL;
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#define  #include 这些都是预处理指令
//#define 可以定义标识符 和 宏

//#define 在定义标识符的时候是否需要在结尾添加";" ???
//答案是尽量不要在后面添加";"
//#define MAX 100
////#define STR "hehe"
//int mian()
//{
//	int max = MAX;
//	printf("%d\n", max);
//	//printf("%s\n", STR);
//	return 0;
//}

//#define SQUARE(X) X*X
//int main()
//{
//	/*int ret = SQUARE(5);
//	printf("ret = %d\n", ret);*/
//
//	int ret = SQUARE(5 + 1);
//	printf("ret = %d\n", ret);    //宏是替换的  不是传参的   5+1*5+1  根据乘法运算就是 11  这里的改变方法就是在宏定义哪里给X带上()
//	//所以告诉我们在这里定义宏的时候不要吝啬(),因为很有可能会出错  因为他只是替换 对于一些运算他就改变了原本的意思
//	return 0;  //  这里的意思是相当于把5替换SQUARE(X)里的X ， 然后在转换成5*5
//}
//
//#define DOUBLE(X) ((X)+(X))
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(a);
//	printf("%d\n", ret);
//	return 0;
//}

//避免在使用宏时由于参数中的操作符或链接操作符之间不可预料的相互作用
//在程序中扩展#define定义符号和宏时，需要设计几个步骤