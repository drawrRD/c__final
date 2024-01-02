#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


//账号类
class Account
{
public:
    Account()
    {
        account = "无";
        password = "无";
        user_name = "无";
        name = "无";
        gender = "无";
        age = "无";
        college = "无";
        major = "无";
        stu_class = "无";
        stu_num = "无";
        phone = "无";
        authority = "0";
    }
    Account(string _au, string _ac, string _pa, string _u, string _name = "无", string _g= "无", string _a ="无", string _c = "无", string _m = "无", string _class = "无", string _num = "无", string _phone = "无")
    {
        account = _ac;
        password = _pa;
        user_name = _u;
        name = _name;
        gender = _g;
        age = _a;
        college = _c;
        major = _m;
        stu_class = _class;
        stu_num = _num;
        phone = _phone;
        authority = _au;
    }
    Account(const Account &_a)
    {
        account = _a.account;
        password = _a.password;
        user_name = _a.user_name;
        name = _a.name;
        gender = _a.gender;
        age = _a.age;
        college = _a.college;
        major = _a.major;
        stu_class = _a.stu_class;
        stu_num = _a.stu_num;
        phone = _a.phone;
        authority = _a.authority;
    }
    string account;
    string password;
    string user_name;
    string name, gender, age, college, major, stu_class, stu_num, phone;
    string authority;
};

vector <Account> account_vec;

//我的账号：继承账号类
class My_Account : public Account
{
public:
    My_Account() : Account() {}

    bool login_account();

    bool register_account();

    bool login();

    void GetAccount(string _au, string _ac, string _pa, string _u, string _name = "无", string _g= "无", string _a ="无", string _c = "无", string _m = "无", string _class = "无", string _num = "无", string _phone = "无");

};
bool My_Account::login_account()
    {
        system("cls");
        cout<<" ——————————————————————————————"<<endl;
        cout<<"|您正在登录您的账号:"<<endl;
        cout<<" ——————————————————————————————"<<endl;
        cout<<"|账号：";
        string tmp_a;
        cin>>tmp_a;
        //cout<<endl;
        cout<<" ——————————————————————————————"<<endl;
        cout<<"|密码：";
        string tmp_p;
        cin>>tmp_p;
        //cout<<endl;
        cout<<" ——————————————————————————————"<<endl;
        for (auto it = account_vec.begin(); it != account_vec.end(); it++)
        {
            if ((*it).account == tmp_a && (*it).password == tmp_p)
            {
                cout<<"登录成功！"<<endl;
                GetAccount((*it).authority,(*it).account,(*it).password,(*it).user_name,(*it).name,(*it).gender,(*it).age,(*it).college,(*it).major,(*it).stu_class,(*it).stu_num,(*it).phone);
                system("pause");
                return true;
            }
        }
        cout<<"用户名或密码错误，请尝试重新登录"<<endl;
        return false;
    }

    bool My_Account::register_account()
    {
        while(1)
        {
            system("cls");
            cout<<" ——————————————————————————————"<<endl;
            cout<<"|您正在注册新的账号:"<<endl;
            cout<<" ——————————————————————————————"<<endl;
            cout<<"请输入账号：";
            string tmp_a;
            cin>>tmp_a;
            if (tmp_a.size() < 8 || tmp_a.size() > 16)
            {
                cout<<"账号的长度应为8~16个字符,请重新输入！"<<endl;
                Sleep(600);
                continue;
            }
            //cout<<endl;
            cout<<" ——————————————————————————————"<<endl;
            cout<<"请输入密码：";
            string tmp_p;
            cin>>tmp_p;
            if (tmp_p.size() < 8 || tmp_p.size() > 16)
            {
                cout<<"密码的长度应为8~16个字符,请重新输入！"<<endl;
                Sleep(600);
                continue;
            }
            //cout<<endl;
            cout<<" ——————————————————————————————"<<endl;
            cout<<"请确认您的密码：";
            string tmp_p2;
            cin>>tmp_p2;
            if (tmp_p2 != tmp_p)
            {
                cout<<"密码不一致，请重新输入！"<<endl;
                Sleep(600);
                continue;
            }
            //cout<<endl;
            cout<<" ———————————----loading--———————————"<<endl;
            for (auto it = account_vec.begin(); it != account_vec.end(); it++)
            {
                if ((*it).account == tmp_a)
                {
                    cout<<"用户名重复，请尝试重新进行注册！"<<endl;
                    return false;
                }
            }
            cout<<"账号注册成功！请输入您的用户名称，用于社区展示:> ";
            while (1)
            {
                string tmp_u;
                cin>>tmp_u;
                if (tmp_u.size() > 30)
                {
                    cout<<"名称不宜过长！请重新输入:> "<<endl;
                    continue;
                }
                char tmp_tmp[50];
                gets(tmp_tmp);
                Account tmp("0", tmp_a, tmp_p, tmp_u);
                GetAccount("0", tmp_a, tmp_p, tmp_u);
                account_vec.push_back(tmp);
                system("pause");
                return true;
            }
        }
    }

    bool My_Account::login()
    {
        while (1)
        {
            system("cls");
            cout<<" ————————————————————————————"<<endl;
            cout<<"|                           登 录                        |"<<endl;
            cout<<" ————————————————————————————"<<endl;
            cout<<"|                      【1】登录账号                     |"<<endl;
            cout<<" ————————————————————————————"<<endl;
            cout<<"|                      【2】注册账号                     |"<<endl;
            cout<<" ————————————————————————————"<<endl;
            cout<<"|                      【3】返   回                      |"<<endl;
            cout<<" ————————————————————————————"<<endl;
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
                    if (login_account() == true)
                    {
                        return true;
                    }
                }
                else if (op == '2')
                {
                    if (register_account() == true)
                        return true;
                }
                else if(op == '3')
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
    void My_Account::GetAccount(string _au, string _ac, string _pa, string _u, string _name, string _g, string _a, string _c, string _m, string _class, string _num, string _phone)
    {
        account = _ac;
        password = _pa;
        user_name = _u;
        name = _name;
        gender = _g;
        age = _a;
        college = _c;
        major = _m;
        stu_class = _class;
        stu_num = _num;
        phone = _phone;
        authority = _au;
    }


void Load_account()
{
    ifstream file("account_data.txt");
    if (!file.is_open())
    {
        cout<<"无法打开文件！"<<endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        vector <string> infos;
        string info;
        while (iss >> info)
        {
            infos.push_back(info);
        }
        if (infos.size() != 0)
        {
            Account tmp(infos[0], infos[1], infos[2], infos[3], infos[4], infos[5], infos[6], infos[7], infos[8], infos[9], infos[10], infos[11]);
            account_vec.push_back(tmp);
        }
    }
    file.close();
}

void Save_account()
{
    ofstream output("account_data.txt");
    if (output.is_open())
    {
        for (auto it = account_vec.begin(); it != account_vec.end(); it++)
        {
            output <<(*it).authority<<"  "<<(*it).account<<"  "<<(*it).password<<"  "<<(*it).user_name<<"  "<<(*it).name<<"  "<<(*it).gender<<"  "<<(*it).age<<"  "<<(*it).college<<"  "<<(*it).major<<"  "<<(*it).stu_class<<"  "<<(*it).stu_num<<"  "<<(*it).phone<<endl;
        }
        output.close();
    }
    else
        cout << "文件存储失败!" << endl;
}



#endif
