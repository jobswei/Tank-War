/*
 * @Author: 魏子喻
 * @Date: 2023-08-04 17:18:14
 * @LastEditors: 魏子喻
 * @LastEditTime: 2023-08-08 15:04:58
 */

enum DIRECTION{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// 坦克结构体
struct tank_s{
    int x; // 坦克在地图数组中所在的列
    int y; // 坦克在地图数组中所在的行
    DIRECTION direction; // 坦克的方向 上 下 左 右
    int live; // 坦克是否生存 1-活着 2-挂了
}; 

// 子弹结构体
struct bullet_s{
    int pos_x; // 子弹在“戏台”上的x坐标
    int pos_y;
    DIRECTION direction; // 子弹方向
    int status; // 子弹状态  子弹是否存在

};