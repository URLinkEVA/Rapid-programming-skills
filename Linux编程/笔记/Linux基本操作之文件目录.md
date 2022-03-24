本节主要讲述文件目录相关操作
# ls ( list )
![在这里插入图片描述](https://img-blog.csdnimg.cn/ba37b1f2bbbb465baa7fa1ddfef0a6f6.png)
登录进去 cd 到总目录下，终端输入
```
ls
```
可以查看当前文件夹所拥有的内容
![在这里插入图片描述](https://img-blog.csdnimg.cn/8c8392f4a98c4f389994025b575eb6bd.png)
事实上 ls 命令并不会把当前目录下所有的内容都显示出来，比如有些文件是以点 (.) 开头的，那么这些文件就是隐藏文件，隐藏文件经常用来存储比较重要的软件或者程序的配置信息，只有特别熟悉当前的工作环境以及这些文件的作用的时候才会去修改他们，所以通常被以这种方式隐藏，避免被误删或者误修改。

如果想要列出文件目录下包含隐藏的所有的文件，需要输入以下指令：
```
ls -a
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/598eb1e434384ec7bda9d9f73c06afa5.png)
可以看到很多隐藏文件被列举出来，这行命令中的 -a 其实是命令 list 的一个可选参数，a 也就是 all 的意思，后面我们会接触到更多类型的命令参数，这些参数都会对命令行为产生影响。

# mkdir ( making directories )
在 Windows 环境下我们新建一个文件夹一般是 右击桌面-> 新建文件夹 即可。在Linux环境下我们通常还可以采用命令行的方式，这里我们在当前目录下新建一个名为 test3 的文件夹，需要输入以下指令：
```
mkdir test3
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/707e338ec46849e8b9b25ee00aef7d20.png)
#  cd ( Change directory )
命令 cd directory 的意思是改变当前的工作目录至目标目录，也就是我们常说的打开并进入一个指定的文件夹。这里我们输入如下指令打开我们刚刚创建的文件夹 test3
![在这里插入图片描述](https://img-blog.csdnimg.cn/05b4774a1b13406da2d6a861f10ba6b1.png)
可以发现我们当前所处的文件目录已经切换至 test3 ,在当前文件夹下输入 ls -a 指令,查看当前文件夹下的内容：
```
ls -a
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/abdc5141cc3140f0ae17873af36a99de.png)
这里我们可以看到当前的文件目录下有两个特殊的文件目录叫（.）和（..）,（.）其实就是指的当前目录，我们通过 cd 命令打开（.），可以发现当前的工作目录没有发生任何改变：
![在这里插入图片描述](https://img-blog.csdnimg.cn/d7fad7e1f50d421290b9af7aec0857f2.png)
（..）是指的当前目录的上一级目录，我们通过 cd 命令打开（ .. ），可以发现我们又回到了一开始的目录（注：在Unix风格的操作系统里通常用波浪号“~”来表示当前用户的主目录也就是home目录）：
![在这里插入图片描述](https://img-blog.csdnimg.cn/6d0f9fcd2dbb4b3eb8a6c0c6df5d9981.png)
如果直接输入 cd 命令，不加任何的目录名参数，那么不管当前处于任何一个文件目录，都会回到最开始的目录。
![在这里插入图片描述](https://img-blog.csdnimg.cn/98f50e5672b1413f9780fccc265d0a43.png)

# pwd （ print working directory ）
命令 pwd 的主要作用是打印当前的目录在整个文件系统中的绝对路径，输入如下指令：
```
pwd
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/1df63f137bf94f45887d43071dfb74ef.png)
> reference http://www.iflyros.com/courseInfo/?id=81
