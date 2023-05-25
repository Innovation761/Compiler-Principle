# 基于 Makefile 的 SysY 编译器项目
本仓库是23年春夏学期编译原理大程，参考了北大的这份在线文档：https://pku-minic.github.io/online-doc/<br>
我们打算三人合作完成这次的大程，本项目的源码是以北大的项目模板为基础，通过我们自己编写源代码逐步构建一个可以编译SysY的编译器。
## 源码的使用方法
在上述文档提供的docker镜像中进行编译，成功后在build文件目录下产生可执行文件：compiler.<br>
接着在终端输入：<br>
build/compiler -koopa test.c -o test.koopa<br>
即可简单编译test.c文件，目前这个c程序写得非常简单，但后续会有所丰富。<br>