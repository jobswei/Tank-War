/*
 * @Author: 魏子喻
 * @Date: 2023-08-08 09:26:53
 * @LastEditors: 魏子喻
 * @LastEditTime: 2023-08-08 09:27:03
 */
#include <conio.h>

int main() {
    while (1) { // 无限循环
        if (_kbhit()) {
            int key = _getch(); // 获取被按下的键
            // 处理键盘按下事件，例如：
            printf("按下的键： %c\n", key);
        }
        // 其他代码
    }
    return 0;
}
