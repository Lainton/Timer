Timer介绍
<<<<<<< HEAD
________
timer是一个倒计时软件
===================
=======
--------
>>>>>>> 77427005853e9dfc348cff527618d5065555dabf
提供命令行参数设置的方式

提供交互式设置方式

提供显示剩余时间的模式（calculate）

使用
<<<<<<< HEAD
___
1.编译软件
=========
=======
---
*__windows__
```javascript
g++ timer.cpp -o timer.exe
```
*__mac__(timer.a为mac编译过的程序，可以直接使用)
```javascript
g++ timer.cpp -o timer.a
```

2.运行
<<<<<<< HEAD
======
=======
=====

>>>>>>> 77427005853e9dfc348cff527618d5065555dabf
*剩余时间__剩余时间__模式（calculate 模式）
```javascript
//倒计时1小时1分钟1秒
./timer.a -c -H 1 -M 1 -S 1
```
![TIMER](https://github.com/Lainton/Timer/blob/master/images/calculate.png)
<<<<<<< HEAD
=======

>>>>>>> 77427005853e9dfc348cff527618d5065555dabf
*不显示__剩余时间__模式（sleep 模式）
```javascript
//倒计时1小时1分钟1秒
./timer.a -s -H 1 -M 1 -S 1
```
![TIMER](https://github.com/Lainton/Timer/blob/master/images/sleep.png)



<<<<<<< HEAD

快速上手
_______
=======
快速上手
------
>>>>>>> 77427005853e9dfc348cff527618d5065555dabf
```javascript
  //compile
  g++ timer.cpp -o timer.a
  //run 
  ./timer.a -c -H 1 -M 1 -S 1
```
