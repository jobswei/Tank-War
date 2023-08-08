/*
 * @Author: 魏子喻
 * @Date: 2023-05-15 12:30:59
 * @LastEditors: 魏子喻
 * @LastEditTime: 2023-08-08 16:46:54
 */
/*
 * @Author: 魏子喻
 * @Date: 2023-05-15 12:30:59
 * @LastEditors: 魏子喻
 * @LastEditTime: 2023-08-08 11:02:27
 */
/*
 * @Author: 魏子喻
 * @Date: 2023-05-15 12:30:59
 * @LastEditors: 魏子喻
 * @LastEditTime: 2023-08-08 10:54:56
 */
#include<graphics.h>
#include<string>
#include<conio.h>
#include<Windows.h>
#include "D:/About_coding/projects/Tank War/head/objects.hpp"
#include "D:/About_coding/projects/Tank War/head/tools.hpp"
#include<iostream>

#pragma comment (lib, "Winmm") // 导入声音库

#define ENEMY_NUM 10
// 定义地图数组
int map[26][26] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
{ 2, 2, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 2, 2 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

using namespace std;
void menu();
void init_map(int* map,int line,int column);
void play();

int main(){
    initgraph(832,666); // 初始化画布
    // 开始场景
    menu();

    init_map((int*)map,26,26);
    cout<<"ok"<<endl;
    play();
    system("pause");
    return 0;
}

void menu(){
// 显示logo
    IMAGE logo_image;
    loadimage(&logo_image,_T("../src/logo.bmp"),433,147);
    putimage(210,20,&logo_image);
    // 实现导航按钮
    setlinecolor(WHITE);
    setfillcolor(BLACK);
    fillrectangle(230,200,310,240);
    settextstyle(24,0,_T("宋体")); // 设置高度宽度和字体
    outtextxy(240,210,_T("Manual")); // 输出文字
    fillrectangle(530,200,610,240);
    settextstyle(24,0,_T("宋体")); // 设置高度宽度和字体
    outtextxy(550,210,_T("Go!"));

    MOUSEMSG mouse;
    IMAGE manual_pict;
    loadimage(&manual_pict,_T("../src/illustrate.jpg"),300,300);

    while(true){
        mouse=GetMouseMsg(); // 获取鼠标
        switch (mouse.uMsg){
        case WM_MOUSEMOVE:
            if(mouse.x>230 && mouse.x<310&&  mouse.y>200 && mouse.y<240){
                putimage(230,250,&manual_pict);
            }else{
                // setlinecolor(BLACK);
                // setfillcolor(BLACK);
                // fillrectangle(230,250,530,550);
                // 绘制没有边框的矩形
                solidrectangle(230,250,530,550);
            }
            break;
        case WM_LBUTTONDOWN:
            if(mouse.x>530 && mouse.x<610&&  mouse.y>200 && mouse.y<240){
                cleardevice();
                return;
            }
            break;
        default:
            break;
        }
    }
}


/* 初始化地图，可消除墙为1，不可消除墙为2，老鹰(3,4),*/
void init_map(int *map, int line,int column){
    IMAGE img_home,img_wall_1,img_wall_2;
    loadimage(&img_home,_T("../src/home.jpg"),64,50);
    loadimage(&img_wall_1,_T("../src/wall2.jpg"),32,25);
    loadimage(&img_wall_2,_T("../src/wall1.jpg"),32,25);

    for(int i=0;i<line;i++){
        for(int j=0;j<column;j++){
            switch (*(map+i*column+j))
            {
            case 1:
                putimage(32*j,25*i,&img_wall_1);
                break;
            case 2:
                putimage(32*j,25*i,&img_wall_2);
                break;
            case 3:
                putimage(32*j,25*i,&img_home);
                // *(map+i*column+j+1)=4;
                // *(map+(i+1)*column+j)=4;
                // *(map+(i+1)*column+j+1)=4;
                set_prop_map(j,i,4);
                break;
            default:
                break;
            }
        }
    }
}


int tank_walk(tank_s *tank, DIRECTION direction, IMAGE *img, int step=1){
    int new_x=tank->x;
    int new_y=tank->y;

    if(step==1){
        if(direction==UP) new_y--;
        else if(direction==DOWN) new_y++;
        else if(direction==RIGHT) new_x++;
        else if(direction==LEFT) new_x--;
        else return 0;
    }
    // 这样写不移动也能实现转向
    setfillcolor(BLACK);
    solidrectangle(tank->x*32, tank->y*25,tank->x*32+64,tank->y*25+50);
    if(!(new_x<0 || new_y <0 || new_x+1>25 || new_y+1>25)){ // 大于25判断的是右侧和下侧
        // map[tank->y][tank->x]=0;
        // map[tank->y+1][tank->x]=0;
        // map[tank->y][tank->x+1]=0;
        // map[tank->y+1][tank->x+1]=0;
        set_prop_map(tank->x, tank->y, 0);
        if(map[new_y][new_x]==0 && map[new_y+1][new_x]==0 && map[new_y][new_x+1]==0 && map[new_y+1][new_x+1]==0) {
            tank->x=new_x;
            tank->y=new_y;
        }
    }
    // map[tank->y][tank->x]=200;
    // map[tank->y+1][tank->x]=200;
    // map[tank->y][tank->x+1]=200;
    // map[tank->y+1][tank->x+1]=200;
    set_prop_map(tank->x, tank->y, 200);
    putimage(tank->x*32, tank->y*25,img);
    return 1;
}

void bullet_action(bullet_s *bullet){

    int x,y,x1,y1; // 子弹在二位数组中的坐标
    x=bullet->pos_x /32;
    y=bullet->pos_y /25;

    // 1. 擦除上一次绘制子弹
    setfillcolor(BLACK);
    solidrectangle(bullet->pos_x, bullet->pos_y,bullet->pos_x+3, bullet->pos_y+3);
    // 2. 根据方向计算子弹在戏台上的坐标
    switch(bullet->direction){
        case UP:
            bullet->pos_y-=2;
            x1=x+1;
            y1=y;
            break;
        case DOWN:
            bullet->pos_y+=2;
            x1=x+1;
            y1=y;
            break;
        case LEFT:
            bullet->pos_x-=2;
            x1=x;
            y1=y+1;
            break;
        case RIGHT:
            bullet->pos_x+=2;
            x1=x;
            y1=y+1;
            break;
    }

    // 判断子弹位置是否合法
    bool ok=true;
    if(bullet->pos_x<0 || bullet->pos_y<0 || bullet->pos_x>832 || bullet->pos_y>666){
        // bullet->status=0;
        ok=false;
        // return ;
    }
    if(map[y][x]==4 || map[x1][y1]==4){
        ok=false;
        return ;
    }
    if(map[y][x]==2 || map[y1][x1]==2){
        ok=false;
    }
    if(map[y][x]==1){
        map[y][x]=0;
        setfillcolor(BLACK);
        solidrectangle(x*32,y*25,(x+1)*32, (y+1)*25);
        ok=false;
    }
    if(map[y1][x1]==1){
        map[y1][x1]=0;
        setfillcolor(BLACK);
        solidrectangle(x1*32,y1*25,(x1+1)*32, (y1+1)*25);
        ok=false;
    }

    if(!ok){
        bullet->status=0;
        return ;
    }
    // 3. 重新绘制子弹
    setfillcolor(WHITE);
    solidrectangle(bullet->pos_x, bullet->pos_y,bullet->pos_x+3, bullet->pos_y+3);

}

void enemy_tank_walk(tank_s *tank, DIRECTION direction, IMAGE *img){
    switch (direction)
        {
        case LEFT:
            tank->direction=LEFT;
            tank_walk(tank,tank->direction,img);
            break;
        case UP:
            tank->direction=UP;
            tank_walk(tank,tank->direction,img);
            break;
        case DOWN:
            tank->direction=DOWN;
            tank_walk(tank,tank->direction,img);
            break;
        case RIGHT:
            tank->direction=RIGHT;
            tank_walk(tank,tank->direction,img);
            break;
        }

}
/********************************
 * 实现游戏场景
**********************************/
void play(){
    tank_s my_tank;
    bullet_s my_bullet;

    tank_s enemy_tank[ENEMY_NUM];
    bullet_s enemy_bullet[ENEMY_NUM];

    IMAGE my_tank_imgs[4];
    IMAGE enemy_tank_imgs[4];

    int key;
    int times=0; // 记录程序的运行时间
    int enemy_total=0;
    // 加载我方坦克的图片
    loadimage(&my_tank_imgs[UP],_T("../src/tank_up.jpg"),64,50);
    loadimage(&my_tank_imgs[DOWN],_T("../src/tank_down.jpg"),64,50);
    loadimage(&my_tank_imgs[LEFT],_T("../src/tank_left.jpg"),64,50);
    loadimage(&my_tank_imgs[RIGHT],_T("../src/tank_right.jpg"),64,50);
    // 加载敌方坦克的图片
    loadimage(&enemy_tank_imgs[UP],_T("../src/enemy_tank_up.jpg"),64,50);
    loadimage(&enemy_tank_imgs[DOWN],_T("../src/enemy_tank_down.jpg"),64,50);
    loadimage(&enemy_tank_imgs[LEFT],_T("../src/enemy_tank_left.jpg"),64,50);
    loadimage(&enemy_tank_imgs[RIGHT],_T("../src/enemy_tank_right.jpg"),64,50);

    my_bullet.status=0; // 子弹目前是不存在的

    // 设定我方tank在地图上的出场位置
    my_tank.x=8;
    my_tank.y=24;
    my_tank.live=1;
    my_tank.direction=UP;
    set_prop_map(my_tank.x,my_tank.y, 200);
    // 设定敌方tank在地图上的出场位置
    for(int i=0;i<ENEMY_NUM;i++){
        if(i%3==0){
            enemy_tank[i].x=0;
        }else if(i%3==1){
            enemy_tank[i].x=12;
        }else{
            enemy_tank[i].x=24;
        }
        enemy_tank[i].direction=DOWN;
        enemy_tank[i].y=0;
        enemy_tank[i].live=1;
        set_prop_map(enemy_tank[i].x, enemy_tank[i].y,100+i);
        enemy_bullet[i].status=0;
    }
    // 先出来三个tank
    tank_walk(enemy_tank,DOWN,&enemy_tank_imgs[DOWN],0);
    tank_walk(enemy_tank+1,DOWN,&enemy_tank_imgs[DOWN],0);
    tank_walk(enemy_tank+2,DOWN,&enemy_tank_imgs[DOWN],0);
    enemy_total=3;

    putimage(my_tank.x*32, my_tank.y*25,&my_tank_imgs[my_tank.direction]);

    MOUSEMSG mouse;
    // cout<<"play"<<endl;
    while(true){
        if(my_tank.live==0) break;
        if(_kbhit()){
            // cout<<"key"<<endl;
            key=_getch();
            switch (key)
            {
            case 'a':
                my_tank.direction=LEFT;
                tank_walk(&my_tank,my_tank.direction,&my_tank_imgs[my_tank.direction]);
                break;
            case 'w':
                my_tank.direction=UP;
                tank_walk(&my_tank,my_tank.direction,&my_tank_imgs[my_tank.direction]);
                break;
            case 's':
                my_tank.direction=DOWN;
                tank_walk(&my_tank,my_tank.direction,&my_tank_imgs[my_tank.direction]);
                break;
            case 'd':
                my_tank.direction=RIGHT;
                tank_walk(&my_tank,my_tank.direction,&my_tank_imgs[my_tank.direction]);
                break;
            case 'j':
                if(my_bullet.status==0){
                    PlaySound(_T("../src/paoji.wav"),NULL,SND_FILENAME | SND_ASYNC);
                    my_bullet.status=1;
                    switch (my_tank.direction)
                    {
                    case UP:
                        my_bullet.pos_x=my_tank.x*32+29;
                        my_bullet.pos_y=my_tank.y*25-3;
                        break;
                    case DOWN:
                        my_bullet.pos_x=my_tank.x*32+29;
                        my_bullet.pos_y=my_tank.y*25+50;
                        break;
                    case LEFT:
                        my_bullet.pos_x=my_tank.x*32-3;
                        my_bullet.pos_y=my_tank.y*25+23;
                        break;
                    case RIGHT:
                        my_bullet.pos_x=my_tank.x*32+64;
                        my_bullet.pos_y=my_tank.y*25+23;
                        break;
                    default:
                        break;
                    }
                    my_bullet.direction=my_tank.direction;

                    
                }
                break;
            case 'p':
                break;
            default:
                cout<<key<<endl;

                break;
            }
        }

        if(times%500==0){
            for(int i=0;i<enemy_total;i++){
                if(enemy_tank[i].live==0) continue;
                enemy_tank_walk(enemy_tank+i,enemy_tank[i].direction,&enemy_tank_imgs[DOWN]);
            }
        }
        if(my_bullet.status==1){bullet_action(&my_bullet);}
        Sleep(10);
        times+=10;
    }
}

