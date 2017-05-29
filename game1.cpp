#include<iostream>
#include<conio.h>//  包含字符输入

using namespace std;

void print(void);//函数声明
void up(void);
void down(void);
void left(void);
void right(void);
void move(void);

int map[10][20]=
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
        {1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1},
        {1,1,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1},
        {1,0,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,1},
        {1,0,0,1,1,1,0,0,0,0,1,1,1,0,1,1,0,0,0,1},
        {1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1},
        {1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1},
        {1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,3,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

bool victory=false;

int a=1,b=1;

int a1=0,b1=0;

//主函数
int main()
{
    print();

    char ch;

    while(!victory)
    {
        ch=getch();

        switch(ch)
        {
        case 'w':up();move();system("cls");print();break;
        case 's':down();move();system("cls");print();break;
        case 'a':left();move();system("cls");print();break;
        case 'd':right();move();system("cls");print();break;
        }
    }

    if(victory)
    {
        cout<<"大赢家，呼啦啦！！！"<<endl;
    }

    cout<<endl;

    return 0;
}

//打印迷宫地图
void print()
{
    int i,j;

    for(i=0;i<10;i++)
    {
        for(j=0;j<20;j++)
        {
            if(map[i][j]==1)
            {
                cout<<"#";
            }
            else if(map[i][j]==0)
            {
                cout<<" ";
            }
            else if(map[i][j]==2)
            {
                cout<<'\014';
            }
            else
                cout<<'\006';
        }
        cout<<endl;
    }
}
//控制各点的移动
//控制向上走
void up()
{
    if(1!=map[a-1][b])
    {
        a1=a;
        b1=b;
        a=a-1;
    }
}
//控制向下走
void down()
{
    if(1!=map[a+1][b])
    {
        a1=a;
        b1=b;
        a=a+1;
    }
}
//控制向左走
void left()
{
    if(1!=map[a][b-1])
    {
        a1=a;
        b1=b;
        b=b-1;
    }
}
//控制向右走
void right()
{
    if(1!=map[a][b+1])
    {
        a1=a;
        b1=b;
        b=b+1;
    }
}
//将点的移动的坐标表示出来
void move()
{
    if(map[a][b]==3)
    {
        victory=true;
    }

    map[a][b]=2;
    map[a1][b1]=0;
}
