
#ifndef POST_H
#define POST_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


class Post
{
public:
    Post (string _run, string _ra, string _reply, string _rt, string _likes, string _rtw)
    {
        replier_user_name = _run;
        replier_account = _ra;
        reply = _reply;
        reply_time = _rt;
        likes = _likes;
        reply_to_who = _rtw;
    }
    Post() {}
    string replier_user_name;
    string replier_account;
    string reply;
    string reply_time;
    string likes;
    string reply_to_who;
    void reply_to_theme_post(int i, Account replier_ac);
    void upvote_someone(int i);
};

class Theme_Post
{
public:
    Theme_Post(string _pun, string _pa, string _type, string _title, string _de, string _pt, string _likes, string _pos)
    {
        poster_user_name = _pun;
        poster_account = _pa;
        type = _type;
        title = _title;
        description = _de;
        post_time = _pt;
        likes = _likes;
        now_pos = _pos;
    }
    Theme_Post() {}
    ~Theme_Post(){}
    string now_pos;
    string poster_user_name;
    string poster_account;
    string type;
    string title;
    string description;
    string post_time;
    string likes;
    string flag_new;
    vector <Post> posts;
    void post_message(Account poster_ac);
};

vector <Theme_Post> posts_vec;
vector <Theme_Post> posts_top;
long long cnt = 0;

string Get_time()
{
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

    string year = to_string(localTime->tm_year + 1900);
    string month = to_string(localTime->tm_mon + 1);
    string day = to_string(localTime->tm_mday);
    string hour = to_string(localTime->tm_hour);
    string minute = to_string(localTime->tm_min);
    string second = to_string(localTime->tm_sec);
    string cur_time = year + "-" + month + "-" + day + "," + hour + ":" + minute + ":" + second;
    return cur_time;
}

void Theme_Post::post_message(Account poster_ac)
{
    while (1)
    {
        system("cls");
         cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<"|�������ӣ�"<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<"|��ѡ���������� [1]���� [2]ѧϰ [3]���� [4]��Ƹ [5]֪ͨ :>";
        char op;
        char tmp[30];
        cin>>op;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"ѡ�����,������ѡ��!"<<endl;
            Sleep(600);
            continue;
        }
        string tmp_type;;
        if (op == '1') {tmp_type = "[����]";}
        else if (op == '2') {tmp_type = "[ѧϰ]";}
        else if (op == '3') {tmp_type = "[����]";}
        else if (op == '4') {tmp_type = "[��Ƹ]";}
        else if (op == '5')
        {
            if (poster_ac.authority == "0")
            {
                cout<<"�����޷���֪ͨ��Ȩ��,����ϵ����Ա������ز���!"<<endl;
                return;
            }
            else
            {
                tmp_type = "��֪ͨ��";
            }
        }
        else {cout<<"ѡ�����,������ѡ��!"<<endl; Sleep(600); continue;}
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<"|���������ӱ��⣺";
        string tmp_title;
        cin>>tmp_title;
        char tmp123[20];
        gets(tmp123);
        if (tmp_title.size() >= 60)
        {
            cout<<"���ⲻ�˹�����"<<endl;
            Sleep(700);
            continue;
        }
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<"|���������Ӹ�Ҫ��";
        string tmp_descrip;
        cin>>tmp_descrip;
        char tmp1234[20];
        gets(tmp1234);
        cout<<" ��������������������������������������----loading-����������������������������������������--"<<endl;
        string tmp_time = Get_time();
        string tmp_likes = "0";
        string tmp_pos;
        if (posts_vec.size() == 0)
        {
            tmp_pos = "10";
        }
        else
        {
            tmp_pos = posts_vec.back().now_pos;
            int tmp_int_pos = stoi(tmp_pos) + 1;
            tmp_pos = to_string(tmp_int_pos);
        }
        Theme_Post tmp_p(poster_ac.user_name, poster_ac.password, tmp_type, tmp_title, tmp_descrip, tmp_time, tmp_likes, tmp_pos);
        posts_vec.push_back(tmp_p);
        cout<<"���ӷ����ɹ���"<<endl;
        return;
    }
}

void display_theme_posts(int page)
{
    for (auto it = posts_top.begin(); it != posts_top.end(); it++)
    {
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        for (auto it2 = posts_vec.begin(); it2 != posts_vec.end(); it2++)
        {
            if (it2->type == it->type && it2->title == it->title && it2->poster_account == it->poster_account)
            {
                it->now_pos = it2->now_pos;
                break;
            }
        }
        cout<<" |["<<it->now_pos<<"] ";
        cout<<"���ö���"<<it->type<<" "<<it->title<<endl;
        cout<<" |�� "<<it->description<<" ��"<<endl;
        cout<<" |�û�:"<<it->poster_user_name<<"  ������: "<<it->post_time<<"  ����: "<<it->likes<<"  �ظ�: "<<it->posts.size()<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
    }
    cnt = page * 6;
    while (cnt != posts_vec.size())
    {
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<" |["<<cnt + 10<<"] ";
        cout<<posts_vec[cnt].type<<" "<<posts_vec[cnt].title<<endl;
        cout<<" |�� "<<posts_vec[cnt].description<<" ��"<<endl;
        cout<<" |�û�:"<<posts_vec[cnt].poster_user_name<<"  ������: "<<posts_vec[cnt].post_time<<"  ����: "<<posts_vec[cnt].likes<<"  �ظ�: "<<posts_vec[cnt].posts.size()<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cnt++;
        if (cnt % 6 == 0)
            break;
    }
}

void display_reply_posts(int i)
{
    long long lou = 1;
    for (auto it = posts_vec[i].posts.begin(); it != posts_vec[i].posts.end(); it++)
    {
        cout<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        if (it->replier_account == posts_vec[i].poster_account)
            cout<<" |��"<<lou<<"¥��"<<"�������ˡ�"<<it->replier_user_name<<" :"<<endl;
        else
            cout<<" |��"<<lou<<"¥��"<<it->replier_user_name<<" :"<<endl;
        if (it->reply_to_who != posts_vec[i].poster_user_name)
            cout<<"�ظ��û�:<"<<it->reply_to_who<<">"<<endl;
        cout<<" |�� "<<it->reply<<" ��"<<endl;
        cout<<" |"<<it->reply_time<<"    "<<"��: "<<it->likes<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        lou++;
    }
}

void Post::reply_to_theme_post(int i, Account replier_ac)
{
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<"��ѡ����Ҫ�ظ���¥��(������������0��):";
        int floor;
        char tmp111[50];
        cin>>floor;
        gets(tmp111);
        if (floor < 0 || floor > posts_vec[i].posts.size())
        {
            cout<<"�ظ��û�ѡ�����,�����·�������!"<<endl;
            system("pause");
            return;
        }
        string reply_to;
        if (floor == 0)
            reply_to = posts_vec[i].poster_user_name;
        else
            reply_to = posts_vec[i].posts[floor - 1].replier_user_name;
        cout<<"�ظ�:>"<<reply_to<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<"��������Ҫ�ظ�������:";
        string text;
        char tmp123[20];
        cin>>text;
        gets(tmp123);
        cout<<" ��������������������������������������----loading������������������������������������������--"<<endl;
        string reply_time = Get_time();
        string like = "0";
        Post reply(replier_ac.user_name, replier_ac.account, text, reply_time, like, reply_to);
        posts_vec[i].posts.push_back(reply);
        cout<<"���۷��ͳɹ�!"<<endl;
        system("pause");
        return;
}

void Post::upvote_someone(int i)
{
    cout<<" ������������������������������������������������������������������������������������������--"<<endl;
    cout<<"��ѡ����Ҫ���޵�¥��(������������0��):";
    int floor;
    cin>>floor;
    if (floor < 0 || floor > posts_vec[i].posts.size())
    {
        cout<<"û�и�¥��,������ѡ��!"<<endl;
        system("pause");
        return;
    }
    string like_to;
    if (floor == 0)
    {
        like_to = posts_vec[i].poster_user_name;
        cout<<"����:>"<<like_to<<endl;
        int to_like = stoi(posts_vec[i].likes);
        to_like++;
        posts_vec[i].likes = to_string(to_like);
    }
    else
    {
        like_to = posts_vec[i].posts[floor - 1].replier_user_name;
        cout<<"����:>"<<like_to<<endl;
        int to_like = stoi(posts_vec[i].posts[floor - 1].likes);
        to_like++;
        posts_vec[i].posts[floor - 1].likes = to_string(to_like);
    }
    cout<<" ����������������������������������������--loading��������������������������������������--"<<endl;
    cout<<"���޳ɹ�!"<<endl;
    Sleep(600);
    return;
}

void enter_post(int op, Account visitor_ac)
{
    while (1)
    {
        system("cls");
        int i = op - 10;
        posts_vec[i].now_pos = to_string(op);
        cout<<"��0��<{==����   ��1��(�ޡ�����)�g����  "<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<" |����������"<<posts_vec[i].type<<" "<<posts_vec[i].title<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<" |�������ˡ�"<<posts_vec[i].poster_user_name<<" :"<<endl;
        cout<<" |�� "<<posts_vec[i].description<<" ��"<<endl;
        cout<<" |������:"<<posts_vec[i].post_time<<"   ����:"<<posts_vec[i].likes<<"   �ظ�:"<<posts_vec[i].posts.size()<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        if (posts_vec[i].posts.size() != 0)
        {
            display_reply_posts(i);
        }
        cout<<endl;
        cout<<"��2������    ��3���ظ�_________________________________"<<endl;
        cout<<"���������ѡ��:>";
        char op2;
        char tmp[50];
        cin>>op2;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"ѡ�����,������ѡ��!"<<endl;
        }
        else
        {
            if (op2 == '0')
            {
                return;
            }
            else if (visitor_ac.authority == "-1")
            {
                cout<<"���ѱ�����Ա����������������ʱ�޷�ʹ���������ܣ�"<<endl;
            }
            else if (op2 == '1')
            {
                int like = stoi(posts_vec[i].likes);
                like++;
                posts_vec[i].likes = to_string(like);
                continue;
            }
            else if (op2 == '2')
            {
                Post pp;
                pp.upvote_someone(i);
                continue;
            }
            else if(op2 == '3')
            {
                Post pp;
                pp.reply_to_theme_post(i, visitor_ac);
                continue;
            }
            else
            {
                cout<<"ѡ�����,������ѡ��!"<<endl;
            }
        }
        system("pause");
    }
}


void search_posts(Account visitor_ac)
{
    while (1)
    {
        system("cls");
        int ok = 0;
        cout<<"��0��<{==����  ��1�����ؼ��ʼ���  ��2�������ڼ���  ��3�������ͼ���"<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<" |����������ѡ��:>";
        char op;
        //char tmp[30];
        //gets(tmp);
        cin>>op;
        if (op == '0')
        {
            return;
        }
        else if (op == '1')
        {
            cout<<" ������������������������������������������������������������������������������������������--"<<endl;
            cout<<" |������ؼ���:>";
            string keyword;
            cin>>keyword;
            ok = 0;
            for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
            {
                if (it->title.find(keyword) != it->title.npos)
                {
                    ok = 1;
                    cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                    cout<<" |["<<it->now_pos<<"] ";
                    cout<<it->type<<" "<<it->title<<endl;
                    cout<<" |�� "<<it->description<<" ��"<<endl;
                    cout<<" |�û�:"<<it->poster_user_name<<"  ������: "<<it->post_time<<"  ����: "<<it->likes<<"  �ظ�: "<<it->posts.size()<<endl;
                    cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                }
            }
            if (ok == 0)
            {
                cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                cout<<"δ��ѯ���롰"<<keyword<<"���йص�����,����С�ؼ��������������Χ��"<<endl;
            }
        }
        else if (op == '2')
        {
            time_t currentTime = time(nullptr);
            tm* localTime = localtime(&currentTime);
            cout<<" ������������������������������������������������������������������������������������������--"<<endl;
            cout<<" |����������(��-��-��):>"<<endl;
            cout<<" ������������������������������������������������������������������������������������������--"<<endl;
            cout<<" |��:>";
            string year;
            cin>>year;
            int bj = 1;
            for (int i = 0; i < year.size(); i++)
            {
                if (year[i] < '0' || year[i] > '9')
                    bj = 0;
            }
            if (bj == 0)
            {
                cout<<"�Ƿ����룡"<<endl;
                Sleep(600);
                continue;
            }
            cout<<" ������������������������������������������������������������������������������������������--"<<endl;
            cout<<" |��:>";
            string month;
            cin>>month;
            bj = 1;
            for (int i = 0; i < month.size(); i++)
            {
                if (year[i] < '0' || year[i] > '9')
                    bj = 0;
            }
            if (bj == 0)
            {
                cout<<"�Ƿ����룡"<<endl;
                Sleep(600);
                continue;
            }
            cout<<" ������������������������������������������������������������������������������������������--"<<endl;
            cout<<" |��:>";
            string day;
            cin>>day;
            bj = 1;
            for (int i = 0; i < day.size(); i++)
            {
                if (day[i] < '0' || day[i] > '9')
                    bj = 0;
            }
            if (bj == 0)
            {
                cout<<"�Ƿ����룡"<<endl;
                Sleep(600);
                continue;
            }
            string date = year + "-" + month + "-" + day;
            ok = 0;
            for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
            {
                if (it->post_time.find(date) != it->post_time.npos)
                {
                    ok = 1;
                    cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                    cout<<" |["<<it->now_pos<<"] ";
                    cout<<it->type<<" "<<it->title<<endl;
                    cout<<" |�� "<<it->description<<" ��"<<endl;
                    cout<<" |�û�:"<<it->poster_user_name<<"  ������: "<<it->post_time<<"  ����: "<<it->likes<<"  �ظ�: "<<it->posts.size()<<endl;
                    cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                }
            }
            if (ok == 0)
            {
                cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                cout<<"δ��ѯ����"<<date<<"�������йص����ݡ�"<<endl;
            }
        }
        else if (op == '3')
        {
            cout<<" |��ѡ��������������� [1]���� [2]ѧϰ [3]���� [4]��Ƹ [5]֪ͨ :>";
            char op;
            char tmp[30];
            cin>>op;
            string tmp_type;;
            if (op == '1') {tmp_type = "[����]";}
            else if (op == '2') {tmp_type = "[ѧϰ]";}
            else if (op == '3') {tmp_type = "[����]";}
            else if (op == '4') {tmp_type = "[��Ƹ]";}
            else if (op == '5') {tmp_type = "��֪ͨ��";}
            else
            {
                cout<<"��Чѡ��"<<endl;
                system("pause");
                continue;
            }
            ok = 0;
            for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
            {
                if (it->type == tmp_type)
                {
                    ok = 1;
                    cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                    cout<<" |["<<it->now_pos<<"] ";
                    cout<<it->type<<" "<<it->title<<endl;
                    cout<<" |�� "<<it->description<<" ��"<<endl;
                    cout<<" |�û�:"<<it->poster_user_name<<"  ������: "<<it->post_time<<"  ����: "<<it->likes<<"  �ظ�: "<<it->posts.size()<<endl;
                    cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                }
            }
            if (ok == 0)
            {
                cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                cout<<"δ��ѯ����"<<tmp_type<<"�����͵����ӡ�"<<endl;
            }
        }
        if (ok == 1)
        {
            cout<<" ������������������������������������������������������������������������������������������--"<<endl;
            cout<<"�������Ӧ����Ž�������(����[0]����):>";
            string xh;
            cin>>xh;
            int iok = 1;
            for (int i = 0; i < xh.size(); i++)
            {
                if (xh[i] < '0' || xh[i] > '9')
                    iok = 0;
            }
            if (xh == "0")
            {
                continue;
            }
            else if (iok == 1 && stoi(xh) >= 10 && stoi(xh) <= posts_vec.size() + 9)
            {
                enter_post(stoi(xh), visitor_ac);
                return;
            }
            else
            {
                cout<<"ѡ�����������ѡ��"<<endl;
                system("pause");
                continue;
            }
        }
        system("pause");
    }

}


void data_posts(Account my_ac)
{
    while (1)
    {
        system("cls");
        cout<<"���Ϲ���"<<endl;
        int flagz = 0;
        for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
        {

            if(it->type == "[����]")
            {
                flagz = 1;
                cout<<" ������������������������������������������������������������������������������������������--"<<endl;
                cout<<" |["<<it->now_pos<<"] ";
                cout<<it->type<<" "<<it->title<<endl;
                cout<<" |�� "<<it->description<<" ��"<<endl;
                cout<<" |�û�:"<<it->poster_user_name<<"  ������: "<<it->post_time<<"  ����: "<<it->likes<<"  �ظ�: "<<it->posts.size()<<endl;
                cout<<" ������������������������������������������������������������������������������������������--"<<endl;
            }
        }
        if (flagz == 0)
        {
            cout<<"�����û��������ϣ�"<<endl;
            cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        }
        cout<<"��0��<=���� ��1���������� ��else��ѡ����Ӧ����Ž�������"<<endl;
        cout<<" ������������������������������������������������������������������������������������������--"<<endl;
        cout<<" |����������ѡ��:>";
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
        else if (op == "1")
        {
            cout<<" ������������������������������������������������������������������������������������������������������������������������"<<endl;
            cout<<"|�������ӣ��������ϣ�"<<endl;
            cout<<" ������������������������������������������������������������������������������������������������������������������������"<<endl;
            cout<<"|��������:> [����]"<<endl;
            string tmp_type = "[����]";
            cout<<" ������������������������������������������������������������������������������������������������������������������������"<<endl;
            cout<<"|���������ӱ��⣺";
            string tmp_title;
            cin>>tmp_title;
            char tmp123[20];
            gets(tmp123);
            if (tmp_title.size() >= 60)
            {
                cout<<"���ⲻ�˹�����"<<endl;
                Sleep(700);
                continue;
            }
            cout<<" ������������������������������������������������������������������������������������������������������������������������"<<endl;
            cout<<"|������Ҫ�������������(�Ͻ�����Υ��Υ��Ȳ����к���Ϣ,����Υ��,����Ա�����˺Ž��з������!):";
            string tmp_descrip;
            cin>>tmp_descrip;
            char tmp1234[20];
            gets(tmp1234);
            cout<<" ������������������������������������������������������loading������������������������������������������������������"<<endl;
            string tmp_time = Get_time();
            string tmp_likes = "0";
            string tmp_pos;
            if (posts_vec.size() == 0)
            {
                tmp_pos = "10";
            }
            else
            {
                tmp_pos = posts_vec.back().now_pos;
                int tmp_int_pos = stoi(tmp_pos) + 1;
                tmp_pos = to_string(tmp_int_pos);
            }
            Theme_Post tmp_p(my_ac.user_name, my_ac.password, tmp_type, tmp_title, tmp_descrip, tmp_time, tmp_likes, tmp_pos);
            posts_vec.push_back(tmp_p);
            cout<<"���ӷ����ɹ���"<<endl;
        }
        else if (flagz != 0 && ok == 1 && op != "0" && stoi(op) <= posts_vec.size() + 9 && stoi(op) >= 10)
        {
            enter_post(stoi(op), my_ac);
            return;
        }
        else
        {
            cout<<"ѡ�����������ѡ��"<<endl;
            //system("pause");
            return;
        }
        system("pause");
    }

}





vector<int> extract_date(const string& dateTimeStr)
{
    vector<int> dateTime;

    stringstream ss(dateTimeStr);
    string datePart, timePart;
    char delimiter;

    getline(ss, datePart, ',');
    stringstream ssDate(datePart);
    string token;
    while (getline(ssDate, token, '-'))
    {
        dateTime.push_back(stoi(token));
    }

    getline(ss, timePart);
    stringstream ssTime(timePart);
    while (getline(ssTime, token, ':'))
    {
        dateTime.push_back(stoi(token));
    }

    return dateTime;
}


bool cmp1(Theme_Post &a, Theme_Post &b)
{

    vector<int> dateTime1 = extract_date(a.post_time);
    vector<int> dateTime2 = extract_date(b.post_time);

    int year1 = dateTime1[0];
    int month1 = dateTime1[1];
    int day1 = dateTime1[2];
    int hour1 = dateTime1[3];
    int mi1 = dateTime1[4];
    int sec1 = dateTime1[5];

    int year2 = dateTime2[0];
    int month2 = dateTime2[1];
    int day2 = dateTime2[2];
    int hour2 = dateTime2[3];
    int mi2 = dateTime2[4];
    int sec2 = dateTime2[5];
    if (year1 == year2)
    {
        if (month1 == month2)
        {
            if (day1 == day2)
            {
                if (hour1 == hour2)
                {
                    if (mi1 == mi2)
                    {
                        return sec1 > sec2;
                    }
                    return mi1 > mi2;
                }
                return hour1 > hour2;
            }
            return day1 > day2;
        }
        return month1 > month2;
    }
    return year1 > year2;
}

bool cmp2(Theme_Post &a, Theme_Post &b)
{
    double hota = stod(a.likes)* 0.35 + (double)a.posts.size() * 0.65;
    double hotaa = 0;
    if (a.posts.size() != 0)
    {
        for (auto it = a.posts.begin(); it != a.posts.end(); it++)
        {
            hotaa += stod(it->likes);
        }
    }
    double hotb = stod(b.likes)* 0.35 + (double)b.posts.size() * 0.65;
    double hotbb = 0;
    if (b.posts.size() != 0)
    {
        for (auto it = b.posts.begin(); it != b.posts.end(); it++)
        {
            hotbb += stod(it->likes);
        }
    }
    hota = hota * 0.7 + hotaa * 0.3;
    hotb = hotb * 0.7 + hotbb * 0.3;
    return hota > hotb;
}

void sort_of_newly()
{
    sort(posts_vec.begin(), posts_vec.end(), cmp1);
    int position = 10;
    for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
    {
        it->now_pos = to_string(position);
        position++;
    }
}

void sort_of_hot()
{
    sort(posts_vec.begin(), posts_vec.end(), cmp2);
    int position = 10;
    for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
    {
        it->now_pos = to_string(position);
        position++;
    }
}



void Load_post()
{
    ifstream file("posts_data.txt");
    if (!file.is_open())
    {
        cout<<"�޷����ļ���"<<endl;
        return;
    }
    string line;
    int cnt = 0 , cnt2 = 0;
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
            if (infos[0] == "�ö�")
            {
                cnt = stoi(infos[1]);
                continue;
            }
            Theme_Post tmp(infos[0], infos[1], infos[2],infos[3],infos[4],infos[5],infos[6], infos[7]);
            for (int i = 8; i < infos.size(); i += 6)
            {
                Post tmp2(infos[i], infos[i + 1], infos[i + 2], infos[i + 3], infos[i + 4], infos[i + 5]);
                tmp.posts.push_back(tmp2);
            }
            if (cnt2 < cnt)
            {
                posts_top.push_back(tmp);
                cnt2++;
            }
            else
                posts_vec.push_back(tmp);
        }
    }
    file.close();
}

void Save_post()
{
    ofstream output("posts_data.txt");
    if (output.is_open())
    {
        if (posts_top.size() != 0)
        {
            output << "�ö�  "<<posts_top.size()<<endl;
            for (auto it = posts_top.begin(); it != posts_top.end(); it++)
            {
                output <<(*it).poster_user_name<<" "<<(*it).poster_account<<" "<<(*it).type<<" "<<(*it).title<<" "<<(*it).description<<" "<<(*it).post_time<<" "<<(*it).likes<<" "<<(*it).now_pos<<" ";
                for (int i = 0; i < (*it).posts.size(); i++)
                {
                    string tmp1 = (*it).posts[i].replier_user_name;
                    string tmp2 = (*it).posts[i].replier_account;
                    string tmp3 = (*it).posts[i].reply;
                    string tmp4 = (*it).posts[i].reply_time;
                    string tmp5 = (*it).posts[i].likes;
                    string tmp6 = (*it).posts[i].reply_to_who;
                    output <<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<" "<<tmp5<<" "<<tmp6<<" ";
                }
                output<<endl;
            }
        }
        for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
        {
            output <<(*it).poster_user_name<<" "<<(*it).poster_account<<" "<<(*it).type<<" "<<(*it).title<<" "<<(*it).description<<" "<<(*it).post_time<<" "<<(*it).likes<<" "<<(*it).now_pos<<" ";
            for (int i = 0; i < (*it).posts.size(); i++)
            {
                string tmp1 = (*it).posts[i].replier_user_name;
                string tmp2 = (*it).posts[i].replier_account;
                string tmp3 = (*it).posts[i].reply;
                string tmp4 = (*it).posts[i].reply_time;
                string tmp5 = (*it).posts[i].likes;
                string tmp6 = (*it).posts[i].reply_to_who;
                output <<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<" "<<tmp5<<" "<<tmp6<<" ";
            }
            output<<endl;
        }
        output.close();
    }
    else
        cout << "�ļ��洢ʧ��!" << endl;
}

#endif
