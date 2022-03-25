# Redirection
上一节 cat 命令的功能是将文件或标准输入组合输出到标准输出。这个命令常用来显示文件内容，或者将几个文件连接起来显示，或者从标准输入读取内容并显示，还常与重定向符号配合使用来创建文件。上一节知道了如何利用 cat 显示一个文件的内容，这一节我们来介绍一下如何利用“>”把 cat 命令的输入重定向至指定的文件，这里我们创建一个关于水果清单的文件，输入如下指令
```
cat > fruit
```
然后输入一些水果的名称，输入完成后按 ctrl + d 结束输入。然后我们再利用 cat 的显示功能查看一下 fruit 这个文件中的内容：
![在这里插入图片描述](https://img-blog.csdnimg.cn/c6a221fee8e84891935156b750deaca5.png)
# Appending to a file
利用“>>”也可以把内容重定向到 file 文件中，而且不会删除以前的内容，输入以下指令验证结果：
```
cat >> fruit
```
然后再输入一些新的水果名称，输入完成后同样使用 ctrl + d 结束输入，利用 cat 查看文件内容以验证结论：
```
cat fruit
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/ca83af986cbb4824a3dfc98fe20b75a8.png)
# Redirecting the Input
我们使用“<”来重定向一个命令的输入。sort 命令用于将文本文件内容加以排序，默认以行为单位来排序。把前面创建的文件 fruit 中的内容做一个排序并输出到屏幕，输入如下命令行：
```
sort < fruit
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/25d819d7d46a4077a7b91e2d5cad481a.png)
# 通配符“*”和“?”
通配符“ * ”可以代表任意字符，常常在查找文件的时候用到，和 Windows 环境下利用“ * ”搜索文件用法相似。输入如下指令查看所有以“tes”为开头的文件：
```
ls test*
```
通配符“ ? ”可以代表任意单个字符，也是常常在查找文件的时候用到，分别输入以下两个命令行观察“ ? ”与“ * ”的区别：
```
ls test?
ls test?.txt
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/ccee673198164a23b24b7775471ff5fc.png)
# 文件名约定
Linux环境下的文件命名要尽量避免使用一些有特殊意义的符号，如“/”，“*”，“&”，“%”等等,一般我们都采用字母数字字符来命名文件，也就是用字母、数字、下划线“_”和“.”。通常以小写字母开头，以“.”作为分割，“.”前面的信息描述文件作用或内容，“.”后面的信息用来描述该文件的格式。
## 操作
Linux 有在线手册提供有关大多数命令的信息。手册页面告诉我们特定命令可以采用哪些参数选项，以及每个参数选项如何修改命令的行为。输入 man command 以阅读特定命令的手册页：
```
man ls
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/59dc96a177ba4f2ab3f070ab8c4147a8.png)
也可以输入 whatis command 以查看简短描述，忽略有关选项等信息：
```
whatis ls
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/9524e124b9ce43248727408a1cf1e461.png)
当我们不知道某个命令的准确名称的时候可以输入 apropos keyword 命令以查找包含该关键词的所有命令的简短描述：
```
apropos copy
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/3ee10d2135144da09b834c6cf4d99069.png)
> reference http://www.iflyros.com/courseInfo/?id=81
