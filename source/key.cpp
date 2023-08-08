/*
 * @Author: 魏子喻
 * @Date: 2023-08-08 09:32:24
 * @LastEditors: 魏子喻
 * @LastEditTime: 2023-08-08 09:32:29
 */
#include <conio.h>
#include <iostream>

int main() {
    while (1) {
        if (_kbhit()) {
            int key = _getch();
            std::cout << "Key pressed: " << char(key) << std::endl;
        }
        // Other code here
    }
    return 0;
}
