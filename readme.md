参考《王道单科2014*数据结构》，严蔚敏《数据结构（C语言版）》
代码环境：win7_64 cygwin, GCC 4.5.3
tree和graph两部分，使用了c++的引用（&）和重载

《王道》勘误:
-------------------
#Page61 
第8小题：C选项应为：top->next = x; top = x;
#Page89
第3大题：答案程序实现有问题。
#Page73
(4)出队
Q.front->next = p->next;//应改为 Q.front = p;
free(p);//删去  
因为书上的程序会导致front指针始终不动，而上段程序Q.rear = s,rear在向后移动，那么永远也不可能front==rear了
#Page132
13题 程序有问题, 已修正，见代码： /tree/exercises/ex43_13.c
#Page147
146页第6题，147页最上部分程序中的for循环有问题，代码已修正
#Page147
6题 程序有问题
#Page195
4题 第二个程序 for循环写错了！应该是：
for(p=FirstNeighbor(G, u); p>=0; p=NextNeighbor(G, u, p))
#Page284
第2大题：中间三个应从front[1]开始


#尚未解决的问题
btree.cpp 118行
bptree