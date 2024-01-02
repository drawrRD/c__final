#include <iostream>
#include <vector>
#include <set>
#include <windows.h>
#include<time.h>
#include "my_page.h"

using namespace std;

//主页
class Home
{
public:
    int login_test = 0;
    int page = 0;

    void home_ui()
    {
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<" |                                     今天你学习了吗？                                     |"<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<" | 【1】首页 【2】“学了么” 【3】在线自习 【4】资料共享 【5】课程评价 【6】我的 【7】退出  |"<<endl;
        cout<<" ——————————————————————————————————————————————"<<endl;
        cout<<" |【8】搜索:_________________________________________________________________________________"<<endl;
        cout<<" |【9】发帖:_________________________________________________________________________________"<<endl;
        cout<<endl;
        cout<<" |【h】热门 【n】最新"<<endl;
        if (posts_vec.size() != 0)
        {
            display_theme_posts(page);
        }
        int total_pages = posts_vec.size()/6 + (posts_vec.size() % 6 == 0 ? 0 : 1);
        cout<<"                    【a】<上一页    "<<"第 "<<page + 1<<" 页/"<<"共 "<<total_pages<<" 页"<<"    下一页>【d】"<<endl;
        cout<<"请输入你的选择:>";
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
                    cout<<"您暂未登录，请前往“我的”进行登录！"<<endl;
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
                    cout<<"您暂未登录，请前往“我的”进行登录！"<<endl;
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
                cout<<"感谢您的使用，再见！"<<endl;
                return;
            }
            else if (op == "8")
            {
                if (login_test ==0)
                {
                    cout<<"您暂未登录，请前往“我的”进行登录！"<<endl;
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
                    cout<<"您暂未登录，请前往“我的”进行登录！"<<endl;
                    system("pause");
                }
                else
                {
                    if (mhp.my_ac.authority == "-1")
                    {
                        cout<<"你已被管理员加入封禁名单，您暂时无法使用社区功能！"<<endl;
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
                    cout<<"当前已经是第一页了!"<<endl;
                    system("pause");
                }
                else
                    page--;
            }
            else if (op == "d")
            {
                if (posts_vec.size() <= (page + 1) * 6)
                {
                    cout<<"当前已经是最后一页了!"<<endl;
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
                    cout<<"您暂未登录，请登录后再查看帖子！"<<endl;
                    system("pause");
                }
                else
                    enter_post(stoi(op), mhp.my_ac);
            }
            else
            {
                cout<<"选择错误,请重新选择!"<<endl;
                system("pause");
            }

        }

    }
};










