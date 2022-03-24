本节主要讲述文件管理和文件预览以及查询的相关操作

之前介绍了一些[简单的知识](https://blog.csdn.net/qq_45618521/article/details/123716038)

为了方便后续操作，将之前的 test3 文件夹重命名为 example
# cp ( copy )
命令 cp 目录1/file1 目录2/file2 的意思是复制目录1下的 file1 文件到至目录2，并把新的复制文件命名为 file2 。我们这里先在test3 文件夹下新建一个文本文件 test1.txt ,打开终端后，输入以下命令：
```
cd 
cd linuxtutorial
gedit test1.txt
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/e860b31f63054d14a0e7380896015ba3.png)
这时候应该会弹出一个 gedit 的文本编辑界面，我没安装所以没有，gedit 是一个 linux 环境下常用的文本编辑器，可以参考别人这篇[链接](https://blog.csdn.net/qq_38916159/article/details/104212695)

![在这里插入图片描述](https://img-blog.csdnimg.cn/7a71d5d6c350461890c13cc40a045c1e.png)
我这里直接右键新建文件了，然后通过 ls 命令，我们可以看到 example 文件夹下多出了一个名为 test1.txt 的文本文件。我们这里新建一个文件夹名为 test2，然后通过 cp 命令把文件 test1.txt 复制到 test2 文件夹，并把文件名改为 test2.txt，打开终端输入如下指令：
```
mkdir test2
cp test1.txt ./test2/test2.txt
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/e5d0d14e5e8449558b3c982ee37e363f.png)
然后查看 test2 文件夹下的内容发现多了一个 test2.txt，其中的内容与文件 test1.txt 也一致
# mv( move )
命令 mv file1 file2 是用来移动（或重命名）文件的，类似 Windows 环境下的剪切。这里我们依旧拿文件 test1.txt 作为目标文件，输入如下指令：
```
cd /example
mv test1.txt test3.txt
ls
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/23d2543b8a034712be356a2b0c676520.png)
这里其实就利用了 mv 的重命名功能，这行命令的意思就是把当前目录下的 test1.txt 移动至当前目录下，并且命名为 test3.txt，所以我们可以看到当前文件目录下的文件 test1.txt 已经消失，并且出现了新的文件 test3.txt。
# rm (remove), rmdir (remove directory)
通过 rm 可以删除文件（该操作不可逆，请谨慎使用，尤其是~~删库跑路rm -rf/*~~ ），这里我们把之前的 test2.txt 文件通过以下命令删除：
```
rm /example/test2/test2.txt
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/94b23a8cd55a471ca1e6a1dfa1c270ba.png)
可以看到 test2.txt 被成功删除了。另外这里用到了上一节中介绍的 ls 指令的另一种用法，即 ls + 目标目录，这样可以把直接把目标目录下的文件内容显示出来，而不必进入该目录。另外华为云这里提示了是否确认删除，需要输入 yes 。

# 终端窗口显示的相关命令
## clear (clear screen)
运行这个命令后，我们可以清除终端窗口先前所输入的命令行以及相关结果，以便更清晰地观察接下来的命令以及命令相关的结果输出。这里可以自行试试。
## cat (concatenate)
命令 cat 可用于在屏幕上显示文件的内容,这里我们先编辑一下之前创建的 test3.txt 文件，文本内容为“hello everyone ！”，然后把内容显示在屏幕上，命令行操作如下：
```
cat test3.txt
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/2ea59a6edd884bbf8862055fe4df19c2.png)
## less
刚刚介绍的 cat 是一次显示所有内容，less 则是将文件内容一次一页地显示到屏幕上,更适合文件内容较多的场景，可以通过鼠标滚轮或者上下键翻页，如果想要退出只需要按一下键盘上的 Q 键。
```
less test3.txt
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/8128ab82f42b437e83b4fb91c4d0e7e7.png)
## head
head 命令用于显示文件内容的前几行，如果不加任何参数，默认显示前十行，输入如下指令：
```
head  test3.txt
```
如果只想显示前五行，则需要在 head 命令后添加参数“-5”，输入如下指令：
```
head -5 test3.txt
```
## tail
tail 命令的用法与 head 刚好相反，用于显示文件内容的后几行，如果不加任何参数，默认显示后十行，输入如下指令：
```
tail  test3.txt
```
如果只想显示后五行，则需要在 tail 命令后添加参数“-5”，输入如下指令：
```
tail -5 test3.txt
```
# 查询文件内容
## 使用 less 进行简单搜索
在使用 less 对文件内容进行阅读的过程中，输入“/关键词”即可对文件内容进行搜索，区分大小写，输入如下指令：
```
less test3.txt
/Sparse
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/210292b00d9d4bf888bfc169f4e3f836.png)
## grep
grep（Globally search a Regular Expression and Print）是一种强大的文本搜索工具，它能使用特定模式匹配（包括正则表达式）搜索文本。输入如下命令行，以搜索文本 test3.txt 中的“hello”为例：
```
grep Sparse test3.txt
```
grep 默认是区分大小写的，如果想无视大小写需要添加参数“-i”，输入如下指令,大家观察一下两个命令行的结果差异：
```
grep sparse test3.txt
grep -i sparse test3.txt
```

如果想要搜索一个短语，必须给要搜索的内容加上单引号（英文单引号），输入如下指令：
```
grep 'Sparse is' test3.txt
```

此外，grep 命令还有很多其他参数可选，用以修改命令行为：
- -v 用于显示没有匹配到的行；
- -n 在匹配行前面显示行号；
- -c 用于显示匹配行的总数量；
```
grep  -v Sparse  test3.txt
grep  -n Sparse  test3.txt
grep  -c Sparse  test3.txt
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/50c8435ef9424c2390e91e427aa1b29e.png)
> reference http://www.iflyros.com/courseInfo/?id=81
