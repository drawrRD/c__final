#include <iostream>
#include <vector>
#include <set>
#include <windows.h>
#include<time.h>
#include "my_page.h"

using namespace std;

//��ҳ
class Home
{
public:
    int login_test = 0;
    int page = 0;

    void home_ui()
    {
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<" |                                     ������ѧϰ����                                     |"<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<" | ��1����ҳ ��2����ѧ��ô�� ��3��������ϰ ��4�����Ϲ��� ��5���γ����� ��6���ҵ� ��7���˳�  |"<<endl;
        cout<<" ��������������������������������������������������������������������������������������������"<<endl;
        cout<<" |��8������:_________________________________________________________________________________"<<endl;
        cout<<" |��9������:_________________________________________________________________________________"<<endl;
        cout<<endl;
        cout<<" |��h������ ��n������"<<endl;
        if (posts_vec.size() != 0)
        {
            display_theme_posts(page);
        }
        int total_pages = posts_vec.size()/6 + (posts_vec.size() % 6 == 0 ? 0 : 1);
        cout<<"                    ��a��<��һҳ    "<<"�� "<<page + 1<<" ҳ/"<<"�� "<<total_pages<<" ҳ"<<"    ��һҳ>��d��"<<endl;
        cout<<"���������ѡ��:>";
    }


    void home_operate()
    {
        My_home_page mhp;
        while (1)
        {
            system("cls");
            home_ui();
            string op;
            cin>>op;
            int ok = 1;
            for (int i = 0; i < op.size(); i++)
            {
                if (op[i] < '0' || op[i] > '9')
                    ok = 0;
            }
            if (op == "1")
            {
                page = 0;
            }
            else if (op == "2")
            {
                if (login_test ==0)
                {
                    cout<<"����δ��¼����ǰ�����ҵġ����е�¼��"<<endl;
                    system("pause");
                }
                else
                {
                    user_base my(mhp.my_ac.account,mhp.my_ac.user_name);
                    meland A(my);
                    A.me_wel();
                }
            }
            else if(op == "3")
            {
                Time ti;
                ti.Menu();
            }
            else if (op == "4")
            {
                if (login_test ==0)
                {
                    cout<<"����δ��¼����ǰ�����ҵġ����е�¼��"<<endl;
                    system("pause");
                }
                else
                {
                    data_posts(mhp.my_ac);
                    //system("pause");
                }
            }
            else if (op == "5")
            {
                StudentUI e;
                e.Welcome();
            }
            else if (op == "6")
            {
                if (mhp.my_page_operate(login_test) == true)
                {
                    login_test = 1;
                }
                else
                    login_test = 0;
            }
            else if (op == "7")
            {
                cout<<"��л����ʹ�ã��ټ���"<<endl;
                return;
            }
            else if (op == "8")
            {
                if (login_test ==0)
                {
                    cout<<"����δ��¼����ǰ�����ҵġ����е�¼��"<<endl;
                    system("pause");
                }
                else
                {
                    search_posts(mhp.my_ac);
                    system("pause");
                }
            }
            else if (op == "9")
            {
                if (login_test ==0)
                {
                    cout<<"����δ��¼����ǰ�����ҵġ����е�¼��"<<endl;
                    system("pause");
                }
                else
                {
                    if (mhp.my_ac.authority == "-1")
                    {
                        cout<<"���ѱ�����Ա����������������ʱ�޷�ʹ���������ܣ�"<<endl;
                    }
                    else
                    {
                        Theme_Post tmpp;
                        tmpp.post_message(mhp.my_ac);
                    }
                    system("pause");
                }
            }
            else if (op == "a")
            {
                if (page == 0)
                {
                    cout<<"��ǰ�Ѿ��ǵ�һҳ��!"<<endl;
                    system("pause");
                }
                else
                    page--;
            }
            else if (op == "d")
            {
                if (posts_vec.size() <= (page + 1) * 6)
                {
                    cout<<"��ǰ�Ѿ������һҳ��!"<<endl;
                    system("pause");
                }
                else
                    page++;
            }
            else if (op == "n")
            {
                sort_of_newly();
            }
            else if (op == "h")
            {
                sort_of_hot();
            }
            else if (ok == 1 && op != "0" && stoi(op) <= posts_vec.size() + 9 && stoi(op) >= 10)
            {
                if (login_test == 0)
                {
                    cout<<"����δ��¼�����¼���ٲ鿴���ӣ�"<<endl;
                    system("pause");
                }
                else
                    enter_post(stoi(op), mhp.my_ac);
            }
            else
            {
                cout<<"ѡ�����,������ѡ��!"<<endl;
                system("pause");
            }

        }

    }
};










