<!--
 * @Date: 2022-01-08 22:51:18
 * @LastEditors: Vscode
 * @LastEditTime: 2022-01-08 22:55:28
 * @Author: Keeyu
 * @Github: https://github.com/keeYuc
-->

这套模型本人已经实现了大幅盈利 有缘作者得之，当然大部分情况没有较高的技术分析和图形抽象水平是看不懂的，有较高水平的也不需要看我的，全当玩玩
* main.go 为主目录通过cgo拓展给tdx官方差价调用（plug-in）
  * 使用runBuild.sh 构建windows平台下动态库
* just-cpp为直接使用cpp实现算法
* single 为更加纯粹的插件选股（因为上述两种只能传递三个参数）
