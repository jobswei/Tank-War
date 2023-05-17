#include<graphics.h>
#include<string>

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

// using namespace std;
void menu();
void init_map(int* map,int line,int column);

int main(){
    initgraph(888,666); // 初始化画布
    // 开始场景
    menu();

    init_map((int*)map,26,26);

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

/* 初始化地图，可消除器为1，不可消除墙为2，老鹰(3,4),*/
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
                *(map+i*column+j+1)=4;
                *(map+(i+1)*column+j)=4;
                *(map+(i+1)*column+j+1)=4;
                break;
            default:
                break;
            }
        }
    }
}