/*
 * @Author: 魏子喻
 * @Date: 2023-08-04 17:18:14
 * @LastEditors: 魏子喻
 * @LastEditTime: 2023-08-04 17:39:58
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