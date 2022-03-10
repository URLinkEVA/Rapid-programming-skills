# 简介
- gcc是一个用于linux系统下编程的编译器。
- gcc原名为 GNU C compile(语言编译器)，因为它原本只能处理 C语言。
- gcc 很快地扩展，变得可处理 C++，之后也变得可处理 Pascal、Object-C、Java以及其他语言。
# 格式
- gcc指令的一般格式为：
	- gcc   [选项]   要编译的文件   [选项]    [目标文件] 
- 其中目标文件可以缺省，缺省情况，生成的可执行文件名为a.out

# 使用gcc编译一个简单的C程序
```c
//example hello.c
#include<stdio.h>
int main(){
    printf("hello world\n");
    return -1;
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/1f58a399e51a4e4c9704de3b8791f6ca.png)
- 使用vi编写一个简单的hello world程序， 并使用gcc编译，缺省情况下编译成功后，会生成可执行文件a.out
- 我们可以通过gcc的-o选项指定生成的可执行文件名
- 以上两条命令，实际隐含了四个步骤。

# gcc编译流程
使用gcc编译程序的时候 ，实际包含了四个步骤：
## 预处理（Pre-processing）
读取C语言源文件，对以“#”开头的语句进行处理
## 编译（Compilation）
对预处理之后输出的文件进行词法分析，试图找出所有不符合语法规则的部份，打印错误或警告。若没有任何语法问题，则将其翻译为功能等价的汇编代码
## 汇编（Assembly）
把汇编代码翻译成目标机器代码（二进制文件）
## 链接（Linking）
将一个文件中引用的符号（函数、外部变量等）与该符号在另文件中的定义和实现连接起来，从而使有关的目标文件连成一个整体，最终生成可以被操作系统执行的可执行文件

# 写一个简单的测试程序
写一个简单的程序gcc-test.c便于我们接下来探讨用，写完之后仔细阅读该代码，了解代码功能，并判断是否有问题:

```c
#include<stdio.h>

#define VER1
#define MAX 20
#define MIN 10

int main(int argc, char ** argv){
    #ifdef VER1
        printf("min = %d\n", MIN)
    #else
        printf("max = %d\n", MAX)
    #endif
        printf("limit = %d\n", LIMIT)

        return 0;
}
```
## gcc编译流程 – 第一步：预处理
- 在该阶段，gcc将对以“#“起始的语句进行处理：
	- 将头文件展开	:  将头文件的内容展开至C文件
	- 做宏的替换	:  将源文件中出现的宏做宏值替换。
	- 条件编译的判断 : 根据条件编译选项，加载指定代码
(注：该阶段会删除注释代码)

- 可以通过gcc的选项-E来单独执行预处理，而不处理其它三个步骤，并生成gcc-test.i的文件：
![在这里插入图片描述](https://img-blog.csdnimg.cn/e1c031ce51df499f9dd08dc444091d6a.png)
