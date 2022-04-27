# Linux中常用命令介绍

ctrl c： 取消命令，并且换行

ctrl u： 清空本行命令（一般直接用ctrl c了）

tab键： 可以补全命令和文件名，如果补全不了快速按两下tab键，可以显示备选选项

ls： 列出当前目录下所有文件，蓝色的是文件夹，白色的是普通文件，绿色的是可执行文件

ls后面常跟的选项有 -a（列出包括隐藏文件的所有文件） -l（列出长格式信息ls -l可缩写为ll） -h（以人性化格式输出，主要是文件大小会从字节变为KB，MB等等）

pwd: 显示当前路径

cd xxx： 进入xxx目录下， cd ..返回上层目录， cd ~返回家目录(~可省略)， cd -返回上一个目录（从哪切换来的就返回哪里）

cp xxx yyy： 将xxx文件复制成yyy，xxx和yyy可以使一个路径， 比如/dir_c/a.txt,表示dir_c文件夹下的文件a.txt（可以是绝对路径也可以是相对路径）

支持cp xxx yyy zzz ttt，把xxx yyy zzz移动到ttt路径

mv xxx yyy： 将xxx文件移动到yyy，类似cp命令，同时该命令可以实现重命名

touch xxx： 创建一个xxx文件

mkdir xxx： 创建一个xxx文件夹，加-p可以直接创建多级

cat xxx： 查看xxx文件内容

rm xxx： 删除普通文件 rm xxx -r：递归删除（用于删除文件夹） rm xxx -rf：强制递归删除，慎用

复制文本

windows/Linux下：Ctrl + insert， Mac下： command + c

粘贴文本

windows/Linux下：Shift + insert, Mac下：command + v

history： 显示历史指令，另外直接按↑键也可以逐条找之前执行的指令

