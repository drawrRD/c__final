#ifndef MY_PAGE_H
#define MY_PAGE_H

#include <iostream>
#include <vector>
#include <set>
#include <windows.h>
#include <time.h>
#include "account.h"
#include "post.h"
#include "chat.h"
#include "Comment.h"
#include "studyroom.h"
using namespace std;

//“我的”页面类
class My_home_page
{
public:
    My_home_page(){}
    void my_page_ui();
    void admini_page_ui();
    bool my_page_operate(int login_test);
    void my_info();
    bool info_change();
    void my_posts();

    void admini_all_account();
    void admini_all_posts();

    My_Account my_ac;

};


void My_home_page::my_page_ui()
{
    cout<<" ————————————————————————————-"<<endl;
    cout<<"| 欢迎您, "<<my_ac.user_name<<":"<<endl;
    cout<<" ————————————————————————————-"<<endl;
    cout<<"| 【1】个人资料       【2】我的贴子     【3】学了么空间   |"<<endl;
    cout<<" ————————————————————————————-"<<endl;
    cout<<"| 【4】我的课程        【5】返回         【6】退出登录    |"<<endl;
    cout<<" ————————————————————————————-"<<endl;
    cout<<"请输入你的选择:>";
}

void My_home_page::admini_page_ui()
{
    cout<<" ————————————————————————————"<<endl;
    if(my_ac.authority == "1")
        cout<<"| 欢迎您, 【*管理员】"<<my_ac.user_name<<":"<<endl;
    else if (my_ac.authority == "2")
        cout<<"| 欢迎您, 【管理员】"<<my_ac.user_name<<":"<<endl;
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 【1】用户管理       【2】帖子管理     【3】学了么空间  |"<<endl;
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 【4】课程管理        【5】返回         【6】退出登录   |"<<endl;
    cout<<" ————————————————————————————"<<endl;
    cout<<"请输入你的选择:>";
}


bool My_home_page::my_page_operate(int login_test)
{
    system("cls");
    if (login_test == 0)
    {
        cout<<"检测到您暂未登录,请前往进行登录！"<<endl;
        system("pause");
        if (my_ac.login() == false)
            return false;
        else
            login_test = 1;
    }
    if (my_ac.authority == "1" || my_ac.authority == "2")
    {
        while (1)
        {
            system("cls");
            admini_page_ui();
            char op;
            char tmp[30];
            cin>>op;
            gets(tmp);
            if (strlen(tmp) != 0)
            {
                cout<<"选择错误,请重新选择!"<<endl;
            }
            else
            {
                if (op == '1')
                {
                    admini_all_account();
                    continue;
                }
                else if (op == '2')
                {
                    admini_all_posts();
                    continue;
                }
                else if(op == '3')
                {
                    user_base my(my_ac.account, my_ac.user_name);
                    meland A(my);
                    A.mangement();
                }
                else if (op == '4')
                {
                    TeacherUI teach;
                    teach.Welcome();
                }
                else if (op == '5')
                {
                    return true;
                }
                else if (op == '6')
                {
                    return false;
                }
                else
                {
                    cout<<"选择错误,请重新选择!"<<endl;
                }
            }
            system("pause");
        }
    }
    else if (my_ac.authority == "0" || my_ac.authority == "-1")
    {
        while (1)
        {
            system("cls");
            my_page_ui();
            char op;
            char tmp[30];
            cin>>op;
            gets(tmp);
            if (strlen(tmp) != 0)
            {
                cout<<"选择错误,请重新选择!"<<endl;
            }
            else
            {
                if (op == '1')
                {
                    my_info();
                    continue;
                }
                else if (op == '2')
                {
                    my_posts();
                    continue;
                }
                else if(op == '3')
                {
                    user_base my(my_ac.account, my_ac.user_name);
                    meland A(my);
                    A.me_wel();
                }
                else if (op == '4')
                {
                    StudentUI e;
                    e.Welcome();
                }
                else if (op == '5')
                {
                    return true;
                }
                else if (op == '6')
                {
                    return false;
                }
                else
                {
                    cout<<"选择错误,请重新选择!"<<endl;
                }
            }
            system("pause");
        }
    }
}


bool cmp3(Theme_Post &a, Theme_Post &b)
{
    int n1 = stoi(a.now_pos);
    int n2 = stoi(b.now_pos);
    return n1 < n2;
}

void My_home_page::admini_all_posts()
{
    while (1)
    {
        system("cls");
        cout<<" ————————————————————————————"<<endl;
        cout<<"|【0】<=返回"<<endl;
        cout<<"| 帖子管理: "<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 【1】帖子置顶     【2】删除帖子     【3】帖子搜索"<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"请输入你的选择:>";
        char op;
        char tmp[30];
        cin>>op;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"选择错误,请重新选择!"<<endl;
        }
        else
        {
            if (op == '0')
            {
                return;
            }
            else if (op == '1')
            {
                cout<<"请输入你要新置顶或取消置顶的帖子编号:>";
                string new_num1;
                int flag_n = 0;
                cin>>new_num1;
                cout<<" ————————————loading————————————"<<endl;
                for (auto it = posts_top.begin(); it != posts_top.end(); it++)
                {
                    if (it->now_pos == new_num1)
                    {
                        flag_n = 1;
                        posts_top.erase(it);
                        cout<<"该帖子已取消置顶。"<<endl;
                        break;
                    }
                }
                if (flag_n == 0)
                {
                    for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
                    {
                        if (it->now_pos == new_num1)
                        {
                            flag_n = 1;
                            posts_top.push_back(*it);
                            //sort(posts_vec.begin(), posts_vec.end(), cmp3);
                            cout<<"该帖子已置顶。"<<endl;
                            break;
                        }
                    }
                }
                if (flag_n == 0)
                    cout<<"未查询到该帖子，请检查您的输入"<<endl;
            }
            else if (op == '2')
            {
                cout<<"请输入你要删除的帖子编号:>";
                string new_num;
                int flag_n = 0;
                cin>>new_num;
                cout<<" ————————————————————————————"<<endl;
                for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
                {
                    if (it->now_pos == new_num)
                    {
                        flag_n = 1;
                        cout<<"请确认删除该帖子 【0】取消 【1】删除"<<endl;
                        char op;
                        cin>>op;
                        if (op == '0'){break;}
                        else if (op == '1')
                        {
                            cout<<" —————————---loading———————————"<<endl;
                            for (auto it2 = it + 1; it2 != posts_vec.end(); it2++)
                            {
                                int num2 = stoi(it2->now_pos);
                                num2--;
                                it2->now_pos = to_string(num2);
                            }
                            posts_vec.erase(it);
                            cout<<"该帖子已删除。"<<endl;
                            break;
                        }
                        else
                        {
                            cout<<"无效选择"<<endl;
                            break;
                        }
                        break;
                    }
                }
                if (flag_n == 0)
                    cout<<"未查询到该帖子，请检查您的输入"<<endl;
            }
            else if (op == '3')
            {
                search_posts(my_ac);
            }
            else
            {
                cout<<"选择错误，请重新选择！"<<endl;
            }
        }
        system("pause");
    }
}





void My_home_page::admini_all_account()
{
    while (1)
    {
        system("cls");
        cout<<" ————————————————————————————"<<endl;
        cout<<"|【0】<=返回"<<endl;
        cout<<"| 用户管理: "<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 【1】增加用户信息 【2】删除用户信息 【3】用户权限管理  "<<endl;
        cout<<"|       【4】搜索用户信息   【5】用户封禁管理            "<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"请输入你的选择:>";
        char op;
        char tmp[30];
        cin>>op;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"选择错误,请重新选择!"<<endl;
        }
        else
        {
            if (op == '0')
            {
                return;
            }
            else if ( (op == '2' || op == '3') && my_ac.authority != "1")
            {
                cout<<"您暂无该权限!"<<endl;
            }
            else if (op == '1')
            {
                string tmp_user_name, tmp_account, tmp_password;
                cout<<"| <增加用户信息>"<<endl;
                cout<<" ————————————————————————————"<<endl;
                cout<<"| 请输入账号:>";
                cin>>tmp_account;
                cout<<" ————————————————————————————"<<endl;
                cout<<"| 请输入密码:>";
                cin>>tmp_password;
                cout<<" ————————————————————————————"<<endl;
                cout<<"| 请输入用户名:>";
                cin>>tmp_user_name;
                cout<<" ———————————---loading————————————"<<endl;
                Account tmp_a("0", tmp_account, tmp_password, tmp_user_name);
                account_vec.push_back(tmp_a);
                cout<<"用户已添加。"<<endl;
            }
            else if (op == '2')
            {
                string tmp_account;
                cout<<"| <删除用户信息>"<<endl;
                cout<<" ————————————————————————————"<<endl;
                cout<<"| 请输入需要删除用户的账号:>";
                cin>>tmp_account;
                int isf = 0;
                for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                {
                    if (it->account == tmp_account)
                    {
                        isf = 1;
                        cout<<"该用户的信息如下,请确认你的选择【1】确认删除, 【0】取消"<<endl;
                        cout<<"用户名:"<<it->account<<"账号："<<it->user_name<<"密码："<<it->password<<endl;
                        char op;
                        cin>>op;
                        if (op == '0'){break;}
                        else if (op == '1')
                        {
                            cout<<" ———————————---loading————————————"<<endl;
                            account_vec.erase(it);
                            cout<<"用户已删除。"<<endl;
                            break;
                        }
                        else
                        {
                            cout<<"无效选择"<<endl;
                            break;
                        }
                    }
                }
                if (isf == 0)
                {
                    cout<<"未查询到该用户，请检查您的输入！"<<endl;
                }
            }
            else if(op == '3')
            {
                cout<<"当前的辅助管理员如下所示"<<endl;
                cout<<"请输入您的选择:【0】返回 【1】新添加 【2】取消权限"<<endl;
                cout<<" ————————————————————————————"<<endl;
                for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                {
                    if (it->authority == "2")
                    {
                        cout<<"用户名:"<<it->user_name<<"   账号："<<it->account<<endl;
                        cout<<" ————————————————————————————"<<endl;
                    }
                }
                char op;
                cin>>op;
                if (op == '0'){}
                else if (op == '1')
                {
                    cout<<"请输入你要任命的新管理员账号:>";
                    string new_ac;
                    int flag_n = 0;
                    cin>>new_ac;
                    cout<<" ———————————--loading————————————"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == new_ac)
                        {
                            flag_n = 1;
                            it->authority = "2";
                            cout<<"管理员任命成功！"<<endl;
                            break;
                        }
                    }
                    if (flag_n == 0)
                        cout<<"未查询到该用户，请检查您的输入"<<endl;
                }
                else if (op == '2')
                {
                    cout<<"请输入你要取消权限的管理员账号:>";
                    string old_ac;
                    int flag_o = 0;
                    cin>>old_ac;
                    cout<<" ———————————--loading————————————"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == old_ac)
                        {
                            flag_o = 1;
                            it->authority = "0";
                            cout<<"管理员任命成功！"<<endl;
                            break;
                        }
                    }
                    if (flag_o == 0)
                        cout<<"未查询到该用户，请检查您的输入"<<endl;
                }
                else
                {
                    cout<<"无效选择"<<endl;

                }
            }
            else if (op == '4')
            {
                cout<<"【0】返回  【1】输入用户名或账号以检索"<<endl;
                cout<<" ————————————————————————————"<<endl;
                cout<<" |请输入您的选择:>";
                char op;
                cin>>op;
                if (op == '0'){}
                else if (op == '1')
                {
                    string tmp_ac_n;
                    cout<<"请输入用户名或账号以检索:>";
                    cin>>tmp_ac_n;
                    int flag_1 = 0;
                    cout<<" ———————————--loading————————————"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == tmp_ac_n || it->user_name == tmp_ac_n)
                        {
                            flag_1 = 1;
                            cout<<"该用户的信息如下"<<endl;
                            cout<<"账号: "<<(*it).account<<"  密码:"<<(*it).password<<"  用户名:"<<(*it).user_name<<"  姓名:"<<(*it).name<<"  性别:"<<(*it).gender<<"  年龄:"<<(*it).age<<"  学院:"<<(*it).college<<"  专业:"<<(*it).major<<"  班级:"<<(*it).stu_class<<"  学号:"<<(*it).stu_num<<"  联系方式:"<<(*it).phone<<endl;
                            break;
                        }
                    }
                    if (flag_1 == 0)
                        cout<<"未查询到该用户，请检查您的输入"<<endl;
                }
                else
                {
                    cout<<"无效选择"<<endl;
                }
            }
            else if (op == '5')
            {
                cout<<"当前已封禁的用户如下所示:"<<endl;
                cout<<"请输入您的选择:【0】返回 【1】新添加 【2】释放"<<endl;
                cout<<" ————————————————————————————"<<endl;
                for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                {
                    if (it->authority == "-1")
                    {
                        cout<<"用户名:"<<it->user_name<<"   账号："<<it->account<<endl;
                        cout<<" ————————————————————————————"<<endl;
                    }
                }
                char op;
                cin>>op;
                if (op == '0'){}
                else if (op == '1')
                {
                    cout<<"请输入你要封禁的用户账号:>";
                    string new_ac;
                    int flag_n = 0;
                    cin>>new_ac;
                    cout<<" ———————————--loading————————————"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == new_ac)
                        {
                            flag_n = 1;
                            it->authority = "-1";
                            cout<<"操作成功！"<<endl;
                            break;
                        }
                    }
                    if (flag_n == 0)
                        cout<<"未查询到该用户，请检查您的输入"<<endl;
                }
                else if (op == '2')
                {
                    cout<<"请输入你要释放的用户账号:>";
                    string old_ac;
                    int flag_o = 0;
                    cin>>old_ac;
                    cout<<" ———————————--loading————————————"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == old_ac)
                        {
                            flag_o = 1;
                            it->authority = "0";
                            cout<<"操作成功！"<<endl;
                            break;
                        }
                    }
                    if (flag_o == 0)
                        cout<<"未查询到该用户，请检查您的输入"<<endl;
                }
                else
                {
                    cout<<"无效选择"<<endl;

                }
            }
            else
            {
                cout<<"选择错误，请重新选择！"<<endl;
            }
        }
        system("pause");
    }
}



void My_home_page::my_info()
{
    while (1)
    {
        system("cls");
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 您的个人资料："<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 用户名: "<<my_ac.user_name<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 账 号: "<<my_ac.account<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 密 码: "<<my_ac.password<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 姓 名*: "<<my_ac.name<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 性 别: "<<my_ac.gender<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 年 龄: "<<my_ac.age<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 学 院: "<<my_ac.college<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 专 业*: "<<my_ac.major<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 班 级*: "<<my_ac.stu_class<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 学 号*: "<<my_ac.stu_num<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"| 联系方式*: "<<my_ac.phone<<endl;
        cout<<" ————————————————————————————"<<endl;
        cout<<"【1】完善信息                           【2】返回"<<endl;
        cout<<"请输入你的选择:>";
        char op;
        char tmp[30];
        cin>>op;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"选择错误,请重新选择!"<<endl;
        }
        else
        {
            if (op == '1')
            {
                if (info_change() == true)
                {
                    cout<<"信息修改成功！"<<endl;
                }
            }
            else if (op == '2')
            {
                return;
            }
            else
            {
                cout<<"选择错误,请重新选择!"<<endl;
            }
        }
        system("pause");
    }
}

bool My_home_page::info_change()
{
    system("cls");
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 个人信息维护："<<endl;
    cout<<"若不更改相关信息,请在输入框中输入【无】"<<endl;
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 用户名: "<<my_ac.user_name<<endl;
    cout<<"请输入修改后的信息:> ";
    string tp1;
    cin>>tp1;
    if (tp1 == "无")
    {
        tp1 = my_ac.user_name;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 账 号: "<<my_ac.account<<"(不可更改)"<<endl;
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 密 码: "<<my_ac.password<<endl;
    cout<<"请输入修改后的信息:> ";
    string tp2;
    cin>>tp2;
    if (tp2 == "无")
    {
        tp2 = my_ac.password;
    }
    else if (tp2.size() < 8 || tp2.size() > 16)
    {
        cout<<"密码的长度应为8~16个字符,无效输入!"<<endl;
        return false;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 姓 名*: "<<my_ac.name<<endl;
    cout<<"请输入修改后的信息:> ";
    string tp3;
    cin>>tp3;
    if (tp3 == "无")
    {
        tp3 = my_ac.name;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 性 别: "<<my_ac.gender<<endl;
    cout<<"请输入修改后的信息(男/女/保密):>";
    string tp4;
    cin>>tp4;
    if (tp4 == "无")
    {
        tp4 = my_ac.gender;
    }
    else if (tp4 == "男" || tp4 == "女" || tp4 == "保密") {}
    else
    {
        cout<<"无效输入！"<<endl;
        return false;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 年 龄: "<<my_ac.age<<endl;
    cout<<"请输入修改后的信息:> ";
    string tp5;
    cin>>tp5;
    if (tp5 == "无")
    {
        tp5 = my_ac.age;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 学 院: "<<my_ac.college<<endl;
    cout<<"请输入修改后的信息:> ";
    string tp6;
    cin>>tp6;
    if (tp6 == "无")
    {
        tp6 = my_ac.college;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 专 业*: "<<my_ac.major<<endl;
    cout<<"请输入修改后的信息:> ";
    string tp7;
    cin>>tp7;
    if (tp7 == "无")
    {
        tp7 = my_ac.major;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 班 级*: "<<my_ac.stu_class<<endl;
    cout<<"请输入修改后的信息:> ";
    string tp8;
    cin>>tp8;
    if (tp8 == "无")
    {
        tp8 = my_ac.stu_class;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 学 号*: "<<my_ac.stu_num<<endl;
    cout<<"请输入修改后的信息:> ";
    string tp9;
    cin>>tp9;
    if (tp9 == "无")
    {
        tp9 = my_ac.stu_num;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"| 联系方式*: "<<my_ac.phone<<endl;
    cout<<"请输入修改后的信息:> ";
    string tp10;
    cin>>tp10;
    if (tp10 == "无")
    {
        tp10 = my_ac.phone;
    }
    cout<<" ————————————————————————————"<<endl;
    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
    {
        if ((*it).account == my_ac.account)
        {
            Account tmp((*it).authority, (*it).account, tp2, tp1, tp3, tp4, tp5, tp6, tp7, tp8, tp9, tp10);
            my_ac.GetAccount((*it).authority, (*it).account, tp2, tp1, tp3, tp4, tp5, tp6, tp7, tp8, tp9, tp10);
            account_vec.erase(it);
            account_vec.push_back(tmp);
            return true;
        }
    }
    return false;
}


void My_home_page::my_posts()
{
    system("cls");
    cout<<" ————————————————————————————"<<endl;
    cout<<"|【0】<=返回 【a】删除帖子 【b】修改帖子 "<<endl;
    cout<<"|【else】输入相应序号进入帖子"<<endl;
    cout<<"| 我的帖子: "<<endl;
    int posts_cnt = 0;
    string num_id[200];
    for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
    {
        if (it->poster_account == my_ac.account)
        {
            posts_cnt++;
            num_id[posts_cnt] = it->now_pos;;
            cout<<" ————————————————————————————"<<endl;
            cout<<"|["<<posts_cnt<<"] "<<it->type<<it->title<<endl;
            cout<<"| 点赞数: "<<it->likes<<" "<<"回复数: "<<it->posts.size()<<endl;
            cout<<" ————————————————————————————"<<endl;
        }
    }
    if (posts_cnt == 0)
    {
        cout<<"你还没有发布过帖子哦!"<<endl;
    }
    cout<<" ————————————————————————————"<<endl;
    cout<<"请输入你的选择:>";
    string op;
    cin>>op;
    int ok = 1;
    for (int i = 0; i < op.size(); i++)
    {
        if (op[i] < '0' || op[i] > '9')
            ok = 0;
    }
    if (op == "0")
    {
        return;
    }
    else if (op == "a")
    {
        cout<<" ————————————————————————————"<<endl;
        cout<<"请输入您要删除的帖子序号:";
        string sop;
        cin>>sop;
        cout<<" ————————————————————————————"<<endl;
        cout<<"【0】取消删除操作 【1】确认删除";
        cout<<"请输入你的选择:>";
        char op2;
        cin>>op2;
        if (op2 == '0')
            return;
        else if (op2 == '1')
        {
            cout<<" ——————————---loading————————————"<<endl;
            int sc = 0;
            for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
            {
                if (it->now_pos == num_id[stoi(sop)] && stoi(sop) <= posts_cnt)
                {
                    for (auto it2 = it + 1; it2 != posts_vec.end(); it2++)
                    {
                        int num2 = stoi(it2->now_pos);
                        num2--;
                        it2->now_pos = to_string(num2);
                    }
                    posts_vec.erase(it);
                    cout<<"该帖子已删除。"<<endl;
                    sc = 1;
                    break;
                }
            }
            if (sc == 0)
            {
                cout<<"未查询到该帖子"<<endl;
                system("pause");
            }
        }
        else
        {
            cout<<"无效选择"<<endl;
        }
    }
    else if (op == "b")
    {
        cout<<" ————————————————————————————"<<endl;
        cout<<"请输入您要修改的帖子序号:";
        string sop;
        cin>>sop;
        cout<<" ——————————---loading————————————"<<endl;
        int xc = 0;
        for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
        {
            if (it->now_pos == num_id[stoi(sop)] && stoi(sop) <= posts_cnt)
            {
                cout<<it->title<<endl;
                cout<<"请输入修改后的标题:";
                string t_t;
                cin>>t_t;
                char ttmp[30];
                gets(ttmp);
                cout<<it->description<<endl;
                cout<<"请输入修改后的概要:";
                string t_d;
                cin>>t_d;
                char ttmp2[30];
                gets(ttmp2);
                it->title = t_t;
                it->description = t_d;
                cout<<"该帖子已成功修改。"<<endl;
                xc = 1;
            }
        }
        if (xc == 0)
        {
            cout<<"未查询到该帖子"<<endl;
            system("pause");
        }
    }
    else if (ok == 1 && stoi(op) <= posts_cnt && stoi(op) > 0)
    {
        enter_post(stoi(num_id[stoi(op)]), my_ac);
        return;
    }
    else
    {
        cout<<"选择错误，请重新选择！"<<endl;
        system("pause");
        return;
    }
}

#endif
