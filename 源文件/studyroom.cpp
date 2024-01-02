#include "studyroom.h"

string paper =
"  吹    _                 ___\n"
"  灭   | |_   _          : @ :\n"
"  读   | | |_| |         :   : \n"
"  书   | | | | |           * \n"
"  灯   | | | | |           *\n"
"      ***************************  一\n"
"      ***************************  身\n"
"          ****          ****       都\n"
"          ****          ****       是\n"
"          ****          ****       月\n " ;


Time::Time()
{
    hour = minute = second = 0;
    display();
}

void Time::Reset()
{
    second = 0;
    minute = 0;
    hour = 0;
}

void Time::settime()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
    }
    else if (minute == 60)
    {
        minute = 0;
        hour++;
    }
    Sleep(1000);
}

void Time::display()
{
    system("cls");
    cout << "    ";
    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout << "\t\t\t\t+ 现在是自律时间 +" << endl;
    cout << "\t\t\t\t                         [a] 开始学习     [ESC]结束学习" << endl;
    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout << "\t\t\t\t    ";
    cout << setw(2) << setfill('0') << hour << ":";
    cout << setw(2) << setfill('0') << minute << ":";
    cout << setw(2) << setfill('0') << second << endl;
    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout << paper <<endl;
    cout << "\n\t\t\t                                     +及时当勉励，岁月不待人。" << endl;
}
void Time::Menu()
{
    KeyInput();
}
void Time::KeyInput()
{
    char key;
    key = getch();
    if (key == 'a' || key == 'A')
    {
        while (1)
        {
            if (kbhit())
            {
                key = getch();
                if (key == 27)
                {
                    system("cls");
                    cout <<endl;
                    cout <<endl;
                    cout <<endl;
                    cout << "\t\t\t\t+本次共自律 ";
                    cout << setw(2) << setfill('0') << hour << ":";
                    cout << setw(2) << setfill('0') << minute << ":";
                    cout << setw(2) << setfill('0') << second << endl;
                    cout <<endl;
                    cout << "\t\t\t\t+ 乘风破浪搏沧海激流，飞鞭催马饮庆功汾酒" << endl;
                    cout << "\t\t\t\t  下次也要继续努力哦~ " << endl;
                    system("pause");
                    break;
                }
            }
            settime();
            system("cls");
            display();
        }
    }
    else if (key == 27)
    {
        system("cls");
        cout << "本次共自律 ";
        display();
        cout << "        乘风破浪搏沧海激流，飞鞭催马饮庆功汾酒" << endl;
        cout << "  下次也要继续努力哦~ " << endl;
        system("pause");
        return;
    }
    else
        KeyInput();
}

