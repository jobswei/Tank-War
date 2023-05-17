#include<graphics.h>
#include<string>

// �����ͼ����
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
    initgraph(888,666); // ��ʼ������
    // ��ʼ����
    menu();

    init_map((int*)map,26,26);

    system("pause");
    return 0;
}

void menu(){
// ��ʾlogo
    IMAGE logo_image;
    loadimage(&logo_image,_T("../src/logo.bmp"),433,147);
    putimage(210,20,&logo_image);
    // ʵ�ֵ�����ť
    setlinecolor(WHITE);
    setfillcolor(BLACK);
    fillrectangle(230,200,310,240);
    settextstyle(24,0,_T("����")); // ���ø߶ȿ�Ⱥ�����
    outtextxy(240,210,_T("Manual")); // �������
    fillrectangle(530,200,610,240);
    settextstyle(24,0,_T("����")); // ���ø߶ȿ�Ⱥ�����
    outtextxy(550,210,_T("Go!"));

    MOUSEMSG mouse;
    IMAGE manual_pict;
    loadimage(&manual_pict,_T("../src/illustrate.jpg"),300,300);

    while(true){
        mouse=GetMouseMsg(); // ��ȡ���
        switch (mouse.uMsg){
        case WM_MOUSEMOVE:
            if(mouse.x>230 && mouse.x<310&&  mouse.y>200 && mouse.y<240){
                putimage(230,250,&manual_pict);
            }else{
                // setlinecolor(BLACK);
                // setfillcolor(BLACK);
                // fillrectangle(230,250,530,550);
                // ����û�б߿�ľ���
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

/* ��ʼ����ͼ����������Ϊ1����������ǽΪ2����ӥ(3,4),*/
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