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


//�˺���
class Account
{
public:
    Account()
    {
        account = "��";
        password = "��";
        user_name = "��";
        name = "��";
        gender = "��";
        age = "��";
        college = "��";
        major = "��";
        stu_class = "��";
        stu_num = "��";
        phone = "��";
        authority = "0";
    }
    Account(string _au, string _ac, string _pa, string _u, string _name = "��", string _g= "��", string _a ="��", string _c = "��", string _m = "��", string _class = "��", string _num = "��", string _phone = "��")
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

//�ҵ��˺ţ��̳��˺���
class My_Account : public Account
{
public:
    My_Account() : Account() {}

    bool login_account();

    bool register_account();

    bool login();

    void GetAccount(string _au, string _ac, string _pa, string _u, string _name = "��", string _g= "��", string _a ="��", string _c = "��", string _m = "��", string _class = "��", string _num = "��", string _phone = "��");

};
bool My_Account::login_account()
    {
        system("cls");
        cout<<" ������������������������������������������������������������"<<endl;
        cout<<"|�����ڵ�¼�����˺�:"<<endl;
        cout<<" ������������������������������������������������������������"<<endl;
        cout<<"|�˺ţ�";
        string tmp_a;
        cin>>tmp_a;
        //cout<<endl;
        cout<<" ������������������������������������������������������������"<<endl;
        cout<<"|���룺";
        string tmp_p;
        cin>>tmp_p;
        //cout<<endl;
        cout<<" ������������������������������������������������������������"<<endl;
        for (auto it = account_vec.begin(); it != account_vec.end(); it++)
        {
            if ((*it).account == tmp_a && (*it).password == tmp_p)
            {
                cout<<"��¼�ɹ���"<<endl;
                GetAccount((*it).authority,(*it).account,(*it).password,(*it).user_name,(*it).name,(*it).gender,(*it).age,(*it).college,(*it).major,(*it).stu_class,(*it).stu_num,(*it).phone);
                system("pause");
                return true;
            }
        }
        cout<<"�û�������������볢�����µ�¼"<<endl;
        return false;
    }

    bool My_Account::register_account()
    {
        while(1)
        {
            system("cls");
            cout<<" ������������������������������������������������������������"<<endl;
            cout<<"|������ע���µ��˺�:"<<endl;
            cout<<" ������������������������������������������������������������"<<endl;
            cout<<"�������˺ţ�";
            string tmp_a;
            cin>>tmp_a;
            if (tmp_a.size() < 8 || tmp_a.size() > 16)
            {
                cout<<"�˺ŵĳ���ӦΪ8~16���ַ�,���������룡"<<endl;
                Sleep(600);
                continue;
            }
            //cout<<endl;
            cout<<" ������������������������������������������������������������"<<endl;
            cout<<"���������룺";
            string tmp_p;
            cin>>tmp_p;
            if (tmp_p.size() < 8 || tmp_p.size() > 16)
            {
                cout<<"����ĳ���ӦΪ8~16���ַ�,���������룡"<<endl;
                Sleep(600);
                continue;
            }
            //cout<<endl;
            cout<<" ������������������������������������������������������������"<<endl;
            cout<<"��ȷ���������룺";
            string tmp_p2;
            cin>>tmp_p2;
            if (tmp_p2 != tmp_p)
            {
                cout<<"���벻һ�£����������룡"<<endl;
                Sleep(600);
                continue;
            }
            //cout<<endl;
            cout<<" ����������������������----loading--����������������������"<<endl;
            for (auto it = account_vec.begin(); it != account_vec.end(); it++)
            {
                if ((*it).account == tmp_a)
                {
                    cout<<"�û����ظ����볢�����½���ע�ᣡ"<<endl;
                    return false;
                }
            }
            cout<<"�˺�ע��ɹ��������������û����ƣ���������չʾ:> ";
            while (1)
            {
                string tmp_u;
                cin>>tmp_u;
                if (tmp_u.size() > 30)
                {
                    cout<<"���Ʋ��˹���������������:> "<<endl;
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
            cout<<" ��������������������������������������������������������"<<endl;
            cout<<"|                           �� ¼                        |"<<endl;
            cout<<" ��������������������������������������������������������"<<endl;
            cout<<"|                      ��1����¼�˺�                     |"<<endl;
            cout<<" ��������������������������������������������������������"<<endl;
            cout<<"|                      ��2��ע���˺�                     |"<<endl;
            cout<<" ��������������������������������������������������������"<<endl;
            cout<<"|                      ��3����   ��                      |"<<endl;
            cout<<" ��������������������������������������������������������"<<endl;
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
                    cout<<"ѡ�����,������ѡ��!"<<endl;
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
        cout<<"�޷����ļ���"<<endl;
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
        cout << "�ļ��洢ʧ��!" << endl;
}



#endif
