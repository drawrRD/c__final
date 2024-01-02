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

//���ҵġ�ҳ����
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
    cout<<" ��������������������������������������������������������-"<<endl;
    cout<<"| ��ӭ��, "<<my_ac.user_name<<":"<<endl;
    cout<<" ��������������������������������������������������������-"<<endl;
    cout<<"| ��1����������       ��2���ҵ�����     ��3��ѧ��ô�ռ�   |"<<endl;
    cout<<" ��������������������������������������������������������-"<<endl;
    cout<<"| ��4���ҵĿγ�        ��5������         ��6���˳���¼    |"<<endl;
    cout<<" ��������������������������������������������������������-"<<endl;
    cout<<"���������ѡ��:>";
}

void My_home_page::admini_page_ui()
{
    cout<<" ��������������������������������������������������������"<<endl;
    if(my_ac.authority == "1")
        cout<<"| ��ӭ��, ��*����Ա��"<<my_ac.user_name<<":"<<endl;
    else if (my_ac.authority == "2")
        cout<<"| ��ӭ��, ������Ա��"<<my_ac.user_name<<":"<<endl;
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| ��1���û�����       ��2�����ӹ���     ��3��ѧ��ô�ռ�  |"<<endl;
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| ��4���γ̹���        ��5������         ��6���˳���¼   |"<<endl;
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"���������ѡ��:>";
}


bool My_home_page::my_page_operate(int login_test)
{
    system("cls");
    if (login_test == 0)
    {
        cout<<"��⵽����δ��¼,��ǰ�����е�¼��"<<endl;
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
                cout<<"ѡ�����,������ѡ��!"<<endl;
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
                    cout<<"ѡ�����,������ѡ��!"<<endl;
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
                cout<<"ѡ�����,������ѡ��!"<<endl;
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
                    cout<<"ѡ�����,������ѡ��!"<<endl;
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
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"|��0��<=����"<<endl;
        cout<<"| ���ӹ���: "<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| ��1�������ö�     ��2��ɾ������     ��3����������"<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"���������ѡ��:>";
        char op;
        char tmp[30];
        cin>>op;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"ѡ�����,������ѡ��!"<<endl;
        }
        else
        {
            if (op == '0')
            {
                return;
            }
            else if (op == '1')
            {
                cout<<"��������Ҫ���ö���ȡ���ö������ӱ��:>";
                string new_num1;
                int flag_n = 0;
                cin>>new_num1;
                cout<<" ������������������������loading������������������������"<<endl;
                for (auto it = posts_top.begin(); it != posts_top.end(); it++)
                {
                    if (it->now_pos == new_num1)
                    {
                        flag_n = 1;
                        posts_top.erase(it);
                        cout<<"��������ȡ���ö���"<<endl;
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
                            cout<<"���������ö���"<<endl;
                            break;
                        }
                    }
                }
                if (flag_n == 0)
                    cout<<"δ��ѯ�������ӣ�������������"<<endl;
            }
            else if (op == '2')
            {
                cout<<"��������Ҫɾ�������ӱ��:>";
                string new_num;
                int flag_n = 0;
                cin>>new_num;
                cout<<" ��������������������������������������������������������"<<endl;
                for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
                {
                    if (it->now_pos == new_num)
                    {
                        flag_n = 1;
                        cout<<"��ȷ��ɾ�������� ��0��ȡ�� ��1��ɾ��"<<endl;
                        char op;
                        cin>>op;
                        if (op == '0'){break;}
                        else if (op == '1')
                        {
                            cout<<" ������������������---loading����������������������"<<endl;
                            for (auto it2 = it + 1; it2 != posts_vec.end(); it2++)
                            {
                                int num2 = stoi(it2->now_pos);
                                num2--;
                                it2->now_pos = to_string(num2);
                            }
                            posts_vec.erase(it);
                            cout<<"��������ɾ����"<<endl;
                            break;
                        }
                        else
                        {
                            cout<<"��Чѡ��"<<endl;
                            break;
                        }
                        break;
                    }
                }
                if (flag_n == 0)
                    cout<<"δ��ѯ�������ӣ�������������"<<endl;
            }
            else if (op == '3')
            {
                search_posts(my_ac);
            }
            else
            {
                cout<<"ѡ�����������ѡ��"<<endl;
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
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"|��0��<=����"<<endl;
        cout<<"| �û�����: "<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| ��1�������û���Ϣ ��2��ɾ���û���Ϣ ��3���û�Ȩ�޹���  "<<endl;
        cout<<"|       ��4�������û���Ϣ   ��5���û��������            "<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"���������ѡ��:>";
        char op;
        char tmp[30];
        cin>>op;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"ѡ�����,������ѡ��!"<<endl;
        }
        else
        {
            if (op == '0')
            {
                return;
            }
            else if ( (op == '2' || op == '3') && my_ac.authority != "1")
            {
                cout<<"�����޸�Ȩ��!"<<endl;
            }
            else if (op == '1')
            {
                string tmp_user_name, tmp_account, tmp_password;
                cout<<"| <�����û���Ϣ>"<<endl;
                cout<<" ��������������������������������������������������������"<<endl;
                cout<<"| �������˺�:>";
                cin>>tmp_account;
                cout<<" ��������������������������������������������������������"<<endl;
                cout<<"| ����������:>";
                cin>>tmp_password;
                cout<<" ��������������������������������������������������������"<<endl;
                cout<<"| �������û���:>";
                cin>>tmp_user_name;
                cout<<" ����������������������---loading������������������������"<<endl;
                Account tmp_a("0", tmp_account, tmp_password, tmp_user_name);
                account_vec.push_back(tmp_a);
                cout<<"�û�����ӡ�"<<endl;
            }
            else if (op == '2')
            {
                string tmp_account;
                cout<<"| <ɾ���û���Ϣ>"<<endl;
                cout<<" ��������������������������������������������������������"<<endl;
                cout<<"| ��������Ҫɾ���û����˺�:>";
                cin>>tmp_account;
                int isf = 0;
                for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                {
                    if (it->account == tmp_account)
                    {
                        isf = 1;
                        cout<<"���û�����Ϣ����,��ȷ�����ѡ��1��ȷ��ɾ��, ��0��ȡ��"<<endl;
                        cout<<"�û���:"<<it->account<<"�˺ţ�"<<it->user_name<<"���룺"<<it->password<<endl;
                        char op;
                        cin>>op;
                        if (op == '0'){break;}
                        else if (op == '1')
                        {
                            cout<<" ����������������������---loading������������������������"<<endl;
                            account_vec.erase(it);
                            cout<<"�û���ɾ����"<<endl;
                            break;
                        }
                        else
                        {
                            cout<<"��Чѡ��"<<endl;
                            break;
                        }
                    }
                }
                if (isf == 0)
                {
                    cout<<"δ��ѯ�����û��������������룡"<<endl;
                }
            }
            else if(op == '3')
            {
                cout<<"��ǰ�ĸ�������Ա������ʾ"<<endl;
                cout<<"����������ѡ��:��0������ ��1������� ��2��ȡ��Ȩ��"<<endl;
                cout<<" ��������������������������������������������������������"<<endl;
                for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                {
                    if (it->authority == "2")
                    {
                        cout<<"�û���:"<<it->user_name<<"   �˺ţ�"<<it->account<<endl;
                        cout<<" ��������������������������������������������������������"<<endl;
                    }
                }
                char op;
                cin>>op;
                if (op == '0'){}
                else if (op == '1')
                {
                    cout<<"��������Ҫ�������¹���Ա�˺�:>";
                    string new_ac;
                    int flag_n = 0;
                    cin>>new_ac;
                    cout<<" ����������������������--loading������������������������"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == new_ac)
                        {
                            flag_n = 1;
                            it->authority = "2";
                            cout<<"����Ա�����ɹ���"<<endl;
                            break;
                        }
                    }
                    if (flag_n == 0)
                        cout<<"δ��ѯ�����û���������������"<<endl;
                }
                else if (op == '2')
                {
                    cout<<"��������Ҫȡ��Ȩ�޵Ĺ���Ա�˺�:>";
                    string old_ac;
                    int flag_o = 0;
                    cin>>old_ac;
                    cout<<" ����������������������--loading������������������������"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == old_ac)
                        {
                            flag_o = 1;
                            it->authority = "0";
                            cout<<"����Ա�����ɹ���"<<endl;
                            break;
                        }
                    }
                    if (flag_o == 0)
                        cout<<"δ��ѯ�����û���������������"<<endl;
                }
                else
                {
                    cout<<"��Чѡ��"<<endl;

                }
            }
            else if (op == '4')
            {
                cout<<"��0������  ��1�������û������˺��Լ���"<<endl;
                cout<<" ��������������������������������������������������������"<<endl;
                cout<<" |����������ѡ��:>";
                char op;
                cin>>op;
                if (op == '0'){}
                else if (op == '1')
                {
                    string tmp_ac_n;
                    cout<<"�������û������˺��Լ���:>";
                    cin>>tmp_ac_n;
                    int flag_1 = 0;
                    cout<<" ����������������������--loading������������������������"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == tmp_ac_n || it->user_name == tmp_ac_n)
                        {
                            flag_1 = 1;
                            cout<<"���û�����Ϣ����"<<endl;
                            cout<<"�˺�: "<<(*it).account<<"  ����:"<<(*it).password<<"  �û���:"<<(*it).user_name<<"  ����:"<<(*it).name<<"  �Ա�:"<<(*it).gender<<"  ����:"<<(*it).age<<"  ѧԺ:"<<(*it).college<<"  רҵ:"<<(*it).major<<"  �༶:"<<(*it).stu_class<<"  ѧ��:"<<(*it).stu_num<<"  ��ϵ��ʽ:"<<(*it).phone<<endl;
                            break;
                        }
                    }
                    if (flag_1 == 0)
                        cout<<"δ��ѯ�����û���������������"<<endl;
                }
                else
                {
                    cout<<"��Чѡ��"<<endl;
                }
            }
            else if (op == '5')
            {
                cout<<"��ǰ�ѷ�����û�������ʾ:"<<endl;
                cout<<"����������ѡ��:��0������ ��1������� ��2���ͷ�"<<endl;
                cout<<" ��������������������������������������������������������"<<endl;
                for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                {
                    if (it->authority == "-1")
                    {
                        cout<<"�û���:"<<it->user_name<<"   �˺ţ�"<<it->account<<endl;
                        cout<<" ��������������������������������������������������������"<<endl;
                    }
                }
                char op;
                cin>>op;
                if (op == '0'){}
                else if (op == '1')
                {
                    cout<<"��������Ҫ������û��˺�:>";
                    string new_ac;
                    int flag_n = 0;
                    cin>>new_ac;
                    cout<<" ����������������������--loading������������������������"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == new_ac)
                        {
                            flag_n = 1;
                            it->authority = "-1";
                            cout<<"�����ɹ���"<<endl;
                            break;
                        }
                    }
                    if (flag_n == 0)
                        cout<<"δ��ѯ�����û���������������"<<endl;
                }
                else if (op == '2')
                {
                    cout<<"��������Ҫ�ͷŵ��û��˺�:>";
                    string old_ac;
                    int flag_o = 0;
                    cin>>old_ac;
                    cout<<" ����������������������--loading������������������������"<<endl;
                    for (auto it = account_vec.begin(); it != account_vec.end(); it++)
                    {
                        if (it->account == old_ac)
                        {
                            flag_o = 1;
                            it->authority = "0";
                            cout<<"�����ɹ���"<<endl;
                            break;
                        }
                    }
                    if (flag_o == 0)
                        cout<<"δ��ѯ�����û���������������"<<endl;
                }
                else
                {
                    cout<<"��Чѡ��"<<endl;

                }
            }
            else
            {
                cout<<"ѡ�����������ѡ��"<<endl;
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
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| ���ĸ������ϣ�"<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| �û���: "<<my_ac.user_name<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| �� ��: "<<my_ac.account<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| �� ��: "<<my_ac.password<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| �� ��*: "<<my_ac.name<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| �� ��: "<<my_ac.gender<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| �� ��: "<<my_ac.age<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| ѧ Ժ: "<<my_ac.college<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| ר ҵ*: "<<my_ac.major<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| �� ��*: "<<my_ac.stu_class<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| ѧ ��*: "<<my_ac.stu_num<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"| ��ϵ��ʽ*: "<<my_ac.phone<<endl;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"��1��������Ϣ                           ��2������"<<endl;
        cout<<"���������ѡ��:>";
        char op;
        char tmp[30];
        cin>>op;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"ѡ�����,������ѡ��!"<<endl;
        }
        else
        {
            if (op == '1')
            {
                if (info_change() == true)
                {
                    cout<<"��Ϣ�޸ĳɹ���"<<endl;
                }
            }
            else if (op == '2')
            {
                return;
            }
            else
            {
                cout<<"ѡ�����,������ѡ��!"<<endl;
            }
        }
        system("pause");
    }
}

bool My_home_page::info_change()
{
    system("cls");
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| ������Ϣά����"<<endl;
    cout<<"�������������Ϣ,��������������롾�ޡ�"<<endl;
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| �û���: "<<my_ac.user_name<<endl;
    cout<<"�������޸ĺ����Ϣ:> ";
    string tp1;
    cin>>tp1;
    if (tp1 == "��")
    {
        tp1 = my_ac.user_name;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| �� ��: "<<my_ac.account<<"(���ɸ���)"<<endl;
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| �� ��: "<<my_ac.password<<endl;
    cout<<"�������޸ĺ����Ϣ:> ";
    string tp2;
    cin>>tp2;
    if (tp2 == "��")
    {
        tp2 = my_ac.password;
    }
    else if (tp2.size() < 8 || tp2.size() > 16)
    {
        cout<<"����ĳ���ӦΪ8~16���ַ�,��Ч����!"<<endl;
        return false;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| �� ��*: "<<my_ac.name<<endl;
    cout<<"�������޸ĺ����Ϣ:> ";
    string tp3;
    cin>>tp3;
    if (tp3 == "��")
    {
        tp3 = my_ac.name;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| �� ��: "<<my_ac.gender<<endl;
    cout<<"�������޸ĺ����Ϣ(��/Ů/����):>";
    string tp4;
    cin>>tp4;
    if (tp4 == "��")
    {
        tp4 = my_ac.gender;
    }
    else if (tp4 == "��" || tp4 == "Ů" || tp4 == "����") {}
    else
    {
        cout<<"��Ч���룡"<<endl;
        return false;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| �� ��: "<<my_ac.age<<endl;
    cout<<"�������޸ĺ����Ϣ:> ";
    string tp5;
    cin>>tp5;
    if (tp5 == "��")
    {
        tp5 = my_ac.age;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| ѧ Ժ: "<<my_ac.college<<endl;
    cout<<"�������޸ĺ����Ϣ:> ";
    string tp6;
    cin>>tp6;
    if (tp6 == "��")
    {
        tp6 = my_ac.college;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| ר ҵ*: "<<my_ac.major<<endl;
    cout<<"�������޸ĺ����Ϣ:> ";
    string tp7;
    cin>>tp7;
    if (tp7 == "��")
    {
        tp7 = my_ac.major;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| �� ��*: "<<my_ac.stu_class<<endl;
    cout<<"�������޸ĺ����Ϣ:> ";
    string tp8;
    cin>>tp8;
    if (tp8 == "��")
    {
        tp8 = my_ac.stu_class;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| ѧ ��*: "<<my_ac.stu_num<<endl;
    cout<<"�������޸ĺ����Ϣ:> ";
    string tp9;
    cin>>tp9;
    if (tp9 == "��")
    {
        tp9 = my_ac.stu_num;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"| ��ϵ��ʽ*: "<<my_ac.phone<<endl;
    cout<<"�������޸ĺ����Ϣ:> ";
    string tp10;
    cin>>tp10;
    if (tp10 == "��")
    {
        tp10 = my_ac.phone;
    }
    cout<<" ��������������������������������������������������������"<<endl;
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
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"|��0��<=���� ��a��ɾ������ ��b���޸����� "<<endl;
    cout<<"|��else��������Ӧ��Ž�������"<<endl;
    cout<<"| �ҵ�����: "<<endl;
    int posts_cnt = 0;
    string num_id[200];
    for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
    {
        if (it->poster_account == my_ac.account)
        {
            posts_cnt++;
            num_id[posts_cnt] = it->now_pos;;
            cout<<" ��������������������������������������������������������"<<endl;
            cout<<"|["<<posts_cnt<<"] "<<it->type<<it->title<<endl;
            cout<<"| ������: "<<it->likes<<" "<<"�ظ���: "<<it->posts.size()<<endl;
            cout<<" ��������������������������������������������������������"<<endl;
        }
    }
    if (posts_cnt == 0)
    {
        cout<<"�㻹û�з���������Ŷ!"<<endl;
    }
    cout<<" ��������������������������������������������������������"<<endl;
    cout<<"���������ѡ��:>";
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
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"��������Ҫɾ�����������:";
        string sop;
        cin>>sop;
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"��0��ȡ��ɾ������ ��1��ȷ��ɾ��";
        cout<<"���������ѡ��:>";
        char op2;
        cin>>op2;
        if (op2 == '0')
            return;
        else if (op2 == '1')
        {
            cout<<" ��������������������---loading������������������������"<<endl;
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
                    cout<<"��������ɾ����"<<endl;
                    sc = 1;
                    break;
                }
            }
            if (sc == 0)
            {
                cout<<"δ��ѯ��������"<<endl;
                system("pause");
            }
        }
        else
        {
            cout<<"��Чѡ��"<<endl;
        }
    }
    else if (op == "b")
    {
        cout<<" ��������������������������������������������������������"<<endl;
        cout<<"��������Ҫ�޸ĵ��������:";
        string sop;
        cin>>sop;
        cout<<" ��������������������---loading������������������������"<<endl;
        int xc = 0;
        for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
        {
            if (it->now_pos == num_id[stoi(sop)] && stoi(sop) <= posts_cnt)
            {
                cout<<it->title<<endl;
                cout<<"�������޸ĺ�ı���:";
                string t_t;
                cin>>t_t;
                char ttmp[30];
                gets(ttmp);
                cout<<it->description<<endl;
                cout<<"�������޸ĺ�ĸ�Ҫ:";
                string t_d;
                cin>>t_d;
                char ttmp2[30];
                gets(ttmp2);
                it->title = t_t;
                it->description = t_d;
                cout<<"�������ѳɹ��޸ġ�"<<endl;
                xc = 1;
            }
        }
        if (xc == 0)
        {
            cout<<"δ��ѯ��������"<<endl;
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
        cout<<"ѡ�����������ѡ��"<<endl;
        system("pause");
        return;
    }
}

#endif
