#CSAPP 计算机程序解释与构造

读 CSAPP 的一些笔记和习题, SP (System Program) 路线

仅作为个人学习过程中的记录.



### hints

>  OSX 用户将 common 里的 csapp.h csapp.c 链接到 /usr/local/include 就好了
>
> ```shell
> ln csapp.h /usr/local/include && ln csapp.h /usr/local/include
> ```
>
> 其他系统用户也可以这样做, 按 gcc 需要包含的路径引入
>
> 方便代码直接引入: 
>
> ```c
> #include <csapp.c>
> ```



### 目录结构

```shell
├── LICENSE
├── README.md
├── code        # 书上示例
├── common      # csapp.h, csapp.c
├── exercise    # 习题
└── notes       # 笔记
```



### TASK

- [ ] 7. 链接
- [ ] 8. 异常控制流
- [ ] 9. 虚拟存储器
- [ ] 10. 系统级 I/O
- [ ] 11. 网络编程
- [ ] 12. 并发编程



vchumming@gmail.com