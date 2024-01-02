#include "studyroom.h"

string paper =
"  ��    _                 ___\n"
"  ��   | |_   _          : @ :\n"
"  ��   | | |_| |         :   : \n"
"  ��   | | | | |           * \n"
"  ��   | | | | |           *\n"
"      ***************************  һ\n"
"      ***************************  ��\n"
"          ****          ****       ��\n"
"          ****          ****       ��\n"
"          ****          ****       ��\n " ;


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
    cout << "\t\t\t\t+ ����������ʱ�� +" << endl;
    cout << "\t\t\t\t                         [a] ��ʼѧϰ     [ESC]����ѧϰ" << endl;
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
    cout << "\n\t\t\t                                     +��ʱ�����������²����ˡ�" << endl;
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
                    cout << "\t\t\t\t+���ι����� ";
                    cout << setw(2) << setfill('0') << hour << ":";
                    cout << setw(2) << setfill('0') << minute << ":";
                    cout << setw(2) << setfill('0') << second << endl;
                    cout <<endl;
                    cout << "\t\t\t\t+ �˷����˲��׺��������ɱ޴������칦�ھ�" << endl;
                    cout << "\t\t\t\t  �´�ҲҪ����Ŭ��Ŷ~ " << endl;
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
        cout << "���ι����� ";
        display();
        cout << "        �˷����˲��׺��������ɱ޴������칦�ھ�" << endl;
        cout << "  �´�ҲҪ����Ŭ��Ŷ~ " << endl;
        system("pause");
        return;
    }
    else
        KeyInput();
}

