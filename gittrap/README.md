# 踩坑记录
## 配置用户名和邮箱
```
git config --global user.name "xxx"
git config --global user.email "xxx"
```
## 检查用户名和邮箱
```
git config user.name
git config user.email
```

## 初始化本地仓库
```
git init
```

## 添加项目目录下所有文件至本地仓库
```
git add .
```

## 加入注释提交
```
git commit -m '本次提交的说明'
```

## 将本地仓库与远程仓库相连接
```
git remote add origin xxx
```
xxx为仓库链接

## 强制将远程仓库文件更新至指定远程仓库中
```
git pull --rebase origin master
```

## 将本地仓库中的文件推送至指定的远程仓库中
```
git push -u origin master
```
## 设置多个远程仓库地址
```
git push -u origin master

git push -u ${remote_name} ${branch_name}
```

## 同步 Gitee 和 GitHub 的代码仓库
https://blog.gitee.com/2021/07/15/repo-mirror/
