#ifndef CHAT_H
#define CHAT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cctype>
#include <map>
#include <ctime>
#define PII pair<string, string>
using namespace std;



class user_base
{
public:
    string num;
    string name;
    user_base(string a, string b)
    {
        num = a;
        name = b;
    }
    user_base()
    {
        num = "";
        name = "";
    }
};
class myfriend : public user_base
{
public:
    string called;
    myfriend()
    {
        num = "";
        name = "";
        called = "";
    }
    myfriend(string x, string y, string z)
    {
        num = x;
        name = y;
        called = z;
    }
    friend istream &operator>>(istream &file, myfriend &x)
    {
        file >> x.num;
        file >> x.name;
        file >> x.called;
        return file;
    }
    friend ostream &operator<<(ostream &file, myfriend &x)
    {
        file << x.num << endl;
        file << x.name << endl;
        file << x.called << endl;
        return file;
    }

    string showname()
    {
        if (called[0] != ' ')
            return called;
        else
            return name;
    }
};
class friendship
{
public:
    int number_fir;
    string me_num;
    string name;
    vector<myfriend> fri;
    friendship() : fri()
    {
        number_fir = 0;
        me_num = "";
    }
    friend istream &operator>>(istream &file, friendship &x)
    {
        file >> x.me_num;
        file >> x.name;
        file >> x.number_fir;
        // cout << x.number_fir << endl;
        x.fri.resize(x.number_fir);
        for (int i = 0; i < x.number_fir; i++)
            file >> x.fri[i];
        return file;
    }
    friend ostream &operator<<(ostream &file, friendship &x)
    {
        file << x.me_num << endl;
        file << x.name << endl;
        file << x.number_fir << endl;
        for (int i = 0; i < x.number_fir; i++)
            file << x.fri[i];
        return file;
    }
};
class friends
{
public:
    user_base my;
    int iidex;
    vector<myfriend> BFF;
    vector<pair<string, int>> Buffer;
    vector<friendship> all_friend;
    friends(user_base mm) : BFF(), Buffer(), all_friend()
    {
        int i;
        my = mm;
        friendship xx;
        ifstream file("friendship.txt");
        if (!file.is_open())
        {
            cout << "无法打开文件" << endl;
            return;
        }
        while (file >> xx)
        {
            all_friend.push_back(xx);
            Buffer.push_back({xx.me_num, all_friend.size() - 1});
            if (xx.me_num == my.num)
            {
                iidex = all_friend.size() - 1;
                for (i = 0; i < xx.number_fir; i++)
                {
                    BFF.push_back(xx.fri[i]);
                }
            }
        }
        file.close();
    }
    ~friends()
    {
        int i;
        ofstream file("friendship.txt", ios::trunc);
        if (!file.is_open())
        {
            cout << "无法打开文件" << endl;
        }
        for (i = 0; i < all_friend.size(); i++)
        {
            file << all_friend[i];
        }
        file.close();
    }
};


string makeradom();

class chatcloud
{
public:
    user_base my;
    string num;
    string name;
    int number;
    int re_num;
    vector<pair<string, string>> mem_mes;
    vector<PII> record;
    int last;

    friend istream &operator>>(istream &file, chatcloud &x);
    friend ostream &operator<<(ostream &file, chatcloud &x);
    void show_record(string);
    bool findme(string);
    void add(string x, string re);

    void ad_member(string num, string name);

    void es_member(string x);

    void sendwarning(string a, string b);

    string chat_num();
    int mem_size();
    int ti();
    chatcloud(const chatcloud &t);

    chatcloud(string xx, user_base aa);

    string cloud_name();

    chatcloud(string b, string c, string d, string e, user_base xx);

    chatcloud(user_base xx);

    void show_member();
};


istream &operator>>(istream &file, chatcloud &x);

ostream &operator<<(ostream &file, chatcloud &x);


class chats_save
{
public:
    vector<string> cloudaccout;
    vector<chatcloud> base;
    vector<pair<string, int>> now;
    vector<PII> system_use;
    user_base my;
    map<string, int> match_pair;
    map<int, int> sy_me_pair;
    map<string, string> match_friend;
    bool check(string x);
    ~chats_save();
    chats_save(user_base xx);
    void add_new_cloud(chatcloud x);
    void sendmessage(string inform, string text, string user);
    string save_newfriend(string num1, string num2, string name1, string name2);
    chatcloud &visited_cloud(int x);
    void add_record(string x, int index, string me);
};

class meland
{
public:
    meland(user_base mm) : my(mm), all(mm), FF(mm)
    {
        autho = 0;
    }
    ~meland(){};
    void me_wel();
    void chatcloud_interface();
    void connect_friend_face();
    void show_friends();
    void chattingface_friend(int);
    void print_wel();
    void chatshow(string);
    void functionbar();
    int chose_emoji();
    void show_emoji();
    void friend_face();
    void show_now();
    static bool cmp_now(pair<string, int> a, pair<string, int> b);
    void chatcloud_face();
    void chattingface_now(int);
    void chat_inputs(string, int);
    void cloud_face();
    void dele_cloud(int);
    void create_wel();
    void add_friends_inface();
    int myfinddd(string);
    void imform_mess_face();
    void imform_print();
    void check_imform(int);
    void add_friend(int);
    void refuse_op(string);
    void dele_myfir(int);
    bool judge(string);
    void print_man();
    void chatcloud_check();
    void check_prin();
    void check_record(int);
    void check_search();
    void informall();
    void mangement();
    void sendall(string);
    void sharepost(string, string);
    user_base my;
    chats_save all;
    friends FF;
    int autho;
};



#endif
