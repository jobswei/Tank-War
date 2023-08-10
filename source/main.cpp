/*
 * @Author: 魏子喻
 * @Date: 2023-05-15 12:30:59
 * @LastEditors: 魏子喻
 * @LastEditTime: 2023-08-09 12:29:35
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
#define SUCCESS 1
#define FAIL 0
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
int play();
void game_over(int);

int main(){
    initgraph(832,666); // 初始化画布
    // 开始场景
    menu();

    init_map((int*)map,26,26);
    int res=play();
    game_over(res);
    // system("pause");
    closegraph();

    return 0;
}

void game_over(int res){
    IMAGE img;
    IMAGE img2;
    if(res==SUCCESS){
        loadimage(&img,_T("../src/success.jpg"),500,250);
        loadimage(&img2,_T("../src/success2.jpg"),400,400);
        putimage(80,50,&img);
        putimage(380,300,&img2);
    }else{
        loadimage(&img,_T("../src/failure.jpg"),500,250);
        loadimage(&img2,_T("../src/failure2.jpg"),400,400);
        putimage(80,50,&img);
        putimage(380,300,&img2);
    }
    while(true){
        int key=_getch();
        // cout<<key<<endl;
        if(key==13) break; // 摁回车退出

    }
}

void menu(){
// 显示logo
    IMAGE logo_image;
    loadimage(&logo_image,_T("../src/logo.bmp"),433,147);
    putimage(210,20,&logo_image);
    loadimage(&logo_image,_T("../src/logo_image.jpg"),433,200);
    putimage(210,450,&logo_image);
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
    loadimage(&manual_pict,_T("../src/illustrate.jpg"),300,200);

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
                solidrectangle(230,250,530,450);
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


int tank_walk(tank_s *tank, DIRECTION direction, IMAGE *img, int step=1,int tank_num=200){
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
    set_prop_map(tank->x, tank->y, tank_num);
    putimage(tank->x*32, tank->y*25,img);
    return 1;
}

int bullet_action(bullet_s *bullet, bool mine=true){
    // 通过设置mine可以对自己和地方的子弹设置不同的效果
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
    // 先不区分自己和敌方的子弹效果
    if(map[y][x]==200 || map[y1][x1]==200){
        ok=false;
        // cout<<map[y][x]<<" "<<map[y1][x1]<<endl;
        // cout<<x<<" "<<y<<endl;
        return -1;
    }
    if(map[y][x]>=100 || map[y1][x1]>=100){
        // cout<<map[y][x]<<" "<<map[y1][x1]<<endl;
        // cout<<x<<" "<<y<<endl;
        ok=false;
        int num=max(map[y][x]-100,map[y1][x1]-100);
        return num;
    }
    if(map[y][x]==4 || map[y1][x1]==4){
        ok=false;
        // cout<<map[y][x]<<" "<<map[y1][x1]<<endl;
        // cout<<x<<" "<<y<<endl;
        return -1;
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
        return -2;
    }
    // 3. 重新绘制子弹
    setfillcolor(WHITE);
    solidrectangle(bullet->pos_x, bullet->pos_y,bullet->pos_x+3, bullet->pos_y+3);
    return -2;

}

void enemy_tank_walk(tank_s *tank, DIRECTION direction, IMAGE *img,int tank_num=200){
    switch (direction)
        {
        case LEFT:
            tank->direction=LEFT;
            tank_walk(tank,tank->direction,img,1,tank_num);
            break;
        case UP:
            tank->direction=UP;
            tank_walk(tank,tank->direction,img,1,tank_num);
            break;
        case DOWN:
            tank->direction=DOWN;
            tank_walk(tank,tank->direction,img,1,tank_num);
            break;
        case RIGHT:
            tank->direction=RIGHT;
            tank_walk(tank,tank->direction,img,1,tank_num);
            break;
        }

}

/*
 * 根据目标的位置，调整地方坦克方向
*/
DIRECTION enemy_direction(tank_s *tank, int x, int y){
    int r=rand()%100;
    if (r>=50){
        if(tank->x>x) return LEFT;
        else return RIGHT;
    }else{
        if(tank->y>y) return UP;
        else return DOWN;
    }
}

void bullet_init(tank_s my_tank, bullet_s *my_bullet){
    if(my_bullet->status==1) return ;
    my_bullet->status=1;
    switch (my_tank.direction)
    {
    case UP:
        my_bullet->pos_x=my_tank.x*32+29;
        my_bullet->pos_y=my_tank.y*25-3;
        break;
    case DOWN:
        my_bullet->pos_x=my_tank.x*32+29;
        my_bullet->pos_y=my_tank.y*25+50;
        break;
    case LEFT:
        my_bullet->pos_x=my_tank.x*32-3;
        my_bullet->pos_y=my_tank.y*25+23;
        break;
    case RIGHT:
        my_bullet->pos_x=my_tank.x*32+64;
        my_bullet->pos_y=my_tank.y*25+23;
        break;
    default:
        break;
    }
    my_bullet->direction=my_tank.direction;
}
/********************************
 * 实现游戏场景
**********************************/
int play(){
    int result=SUCCESS;

    tank_s my_tank;
    bullet_s my_bullet;

    tank_s enemy_tank[ENEMY_NUM];
    bullet_s enemy_bullet[ENEMY_NUM];

    IMAGE my_tank_imgs[4];
    IMAGE enemy_tank_imgs[4];

    int key;
    int times=0; // 记录程序的运行时间
    int enemy_total=0;
    srand(time(NULL));

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
    // loadimage(&enemy_tank_imgs[UP],_T("../src/jiege.jpg"),64,50);
    // loadimage(&enemy_tank_imgs[DOWN],_T("../src/jiege.jpg"),64,50);
    // loadimage(&enemy_tank_imgs[LEFT],_T("../src/jiege.jpg"),64,50);
    // loadimage(&enemy_tank_imgs[RIGHT],_T("../src/jiege.jpg"),64,50);

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
    tank_walk(enemy_tank,DOWN,&enemy_tank_imgs[DOWN],0,100);
    tank_walk(enemy_tank+1,DOWN,&enemy_tank_imgs[DOWN],0,101);
    tank_walk(enemy_tank+2,DOWN,&enemy_tank_imgs[DOWN],0,102);
    enemy_total=3;

    putimage(my_tank.x*32, my_tank.y*25,&my_tank_imgs[my_tank.direction]);

    MOUSEMSG mouse;
    bool loop=true;
    // cout<<"play"<<endl;
    while(loop){
        if(my_tank.live==0) break;
        if(_kbhit()){
            // cout<<"key"<<endl;
            key=_getch();
            switch (key)
            {
            case 'a':
                my_tank.direction=LEFT;
                tank_walk(&my_tank,my_tank.direction,&my_tank_imgs[my_tank.direction],1,200);
                break;
            case 'w':
                my_tank.direction=UP;
                tank_walk(&my_tank,my_tank.direction,&my_tank_imgs[my_tank.direction],1,200);
                break;
            case 's':
                my_tank.direction=DOWN;
                tank_walk(&my_tank,my_tank.direction,&my_tank_imgs[my_tank.direction],1,200);
                break;
            case 'd':
                my_tank.direction=RIGHT;
                tank_walk(&my_tank,my_tank.direction,&my_tank_imgs[my_tank.direction],1,200);
                break;
            case 'j':
                if(my_bullet.status==0){
                    PlaySound(_T("../src/paoji.wav"),NULL,SND_FILENAME | SND_ASYNC);
                    bullet_init(my_tank,&my_bullet);
                }
                break;
            case 'p':
                break;
            default:
                cout<<key<<endl;
                break;
            }
            // for(int i=0;i<26;i++){
            //     for(int j=0;j<26;j++){
            //         cout<<map[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
        }
        
        if(times%3000==0 && times!=0&&enemy_total<=ENEMY_NUM){ // 每隔5s出来一个enemy
            enemy_total++;
            tank_walk(enemy_tank+enemy_total-1,DOWN,&enemy_tank_imgs[DOWN],0,enemy_total);

        }
        
        if(times%1000==0 && times!=0){ // 每隔2000ms，地方tank转一下
            DIRECTION target_dir;
            for(int i=0;i<enemy_total;i++){
                if(i%2==0){// 攻击我方老巢
                    target_dir=enemy_direction(enemy_tank+i, 13, 25);
                }else{ // 攻击我方坦克
                    target_dir=enemy_direction(enemy_tank+i, my_tank.x, my_tank.y);
                }
                enemy_tank[i].direction=target_dir;
            }
        }
        if(times%500==0 && times!=0){ // 每隔500ms前进一下
            for(int i=0;i<enemy_total;i++){
                if(enemy_tank[i].live==0) continue;
                enemy_tank_walk(enemy_tank+i,enemy_tank[i].direction,&enemy_tank_imgs[enemy_tank[i].direction],100+i);
            }
        }
        // 必须先移动再发射子弹，否则会被自己的子弹打死
        if(times%200==0){ // 敌方每个500s发一次子弹 
            for(int i=0;i<enemy_total;i++){
                if(enemy_tank[i].live==1 && enemy_bullet[i].status==0){
                    bullet_init(enemy_tank[i], enemy_bullet+i);
                }
            }
        }
        // 子弹移动
        if(my_bullet.status==1){
            int num=bullet_action(&my_bullet);
            if(num==-1) {
                result=false;
                loop=false;} // 跳出循环，游戏结束
            if(num>=0 && num<enemy_total) 
                {
                    my_bullet.status=0;
                    enemy_tank[num].live=0;
                    set_prop_map(enemy_tank[num].x,enemy_tank[num].y,0);
                    setfillcolor(BLACK);
                    solidrectangle(enemy_tank[num].x*32, enemy_tank[num].y*25,enemy_tank[num].x*32+64, enemy_tank[num].y*25+50);
                }
        }
        for(int i=0;i<enemy_total;i++){
            if(enemy_bullet[i].status==1){
                int num=bullet_action(enemy_bullet+i);
                // cout<<num<<endl;
                // if(num==-1)cout<<num<<endl;
                if(num==-1) {
                    result=false;
                    loop=false;} // 跳出循环，游戏结束
                    // if(num>=0 && num<enemy_total) 
                // {   
                //     enemy_tank[num].live=0;
                //     setfillcolor(BLACK);
                //     solidrectangle(enemy_tank[num].x*32, enemy_tank[num].y*25,enemy_tank[num].x*32+64, enemy_tank[num].y*25+50);
                // }
            }
        }
        int enemy_live=0;
        for(int i=0;i<enemy_total;i++){
            enemy_live+=enemy_tank[i].live;
        }
        if(enemy_live==0) loop=false; // 赢了
        Sleep(10);
        times+=10;
    }
    return result;
}

