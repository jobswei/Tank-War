#include<graphics.h>
#include<string>

// using namespace std;

int main(){
    initgraph(888,666); // ��ʼ������
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
    mouse=GetMouseMsg(); // ��ȡ���
    IMAGE manual_pict;
    loadimage(&manual_pict,_T("../src/illustrate.jpg"),300,300);
    while(true){
        mouse=GetMouseMsg();
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
                
            }
        default:
            break;
        }
    }

    system("pause");
    return 0;
}