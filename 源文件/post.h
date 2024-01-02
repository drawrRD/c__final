
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
         cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<"|发布帖子："<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<"|请选择帖子类型 [1]闲聊 [2]学习 [3]求助 [4]招聘 [5]通知 :>";
        char op;
        char tmp[30];
        cin>>op;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"选择错误,请重新选择!"<<endl;
            Sleep(600);
            continue;
        }
        string tmp_type;;
        if (op == '1') {tmp_type = "[闲聊]";}
        else if (op == '2') {tmp_type = "[学习]";}
        else if (op == '3') {tmp_type = "[求助]";}
        else if (op == '4') {tmp_type = "[招聘]";}
        else if (op == '5')
        {
            if (poster_ac.authority == "0")
            {
                cout<<"您暂无发布通知的权限,请联系管理员进行相关操作!"<<endl;
                return;
            }
            else
            {
                tmp_type = "【通知】";
            }
        }
        else {cout<<"选择错误,请重新选择!"<<endl; Sleep(600); continue;}
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<"|请输入帖子标题：";
        string tmp_title;
        cin>>tmp_title;
        char tmp123[20];
        gets(tmp123);
        if (tmp_title.size() >= 60)
        {
            cout<<"标题不宜过长！"<<endl;
            Sleep(700);
            continue;
        }
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<"|请输入帖子概要：";
        string tmp_descrip;
        cin>>tmp_descrip;
        char tmp1234[20];
        gets(tmp1234);
        cout<<" ———————————————————----loading-————————————————————--"<<endl;
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
        cout<<"帖子发布成功！"<<endl;
        return;
    }
}

void display_theme_posts(int page)
{
    for (auto it = posts_top.begin(); it != posts_top.end(); it++)
    {
        cout<<" —————————————————————————————————————————————--"<<endl;
        for (auto it2 = posts_vec.begin(); it2 != posts_vec.end(); it2++)
        {
            if (it2->type == it->type && it2->title == it->title && it2->poster_account == it->poster_account)
            {
                it->now_pos = it2->now_pos;
                break;
            }
        }
        cout<<" |["<<it->now_pos<<"] ";
        cout<<"【置顶】"<<it->type<<" "<<it->title<<endl;
        cout<<" |“ "<<it->description<<" ”"<<endl;
        cout<<" |用户:"<<it->poster_user_name<<"  发布于: "<<it->post_time<<"  点赞: "<<it->likes<<"  回复: "<<it->posts.size()<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
    }
    cnt = page * 6;
    while (cnt != posts_vec.size())
    {
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<" |["<<cnt + 10<<"] ";
        cout<<posts_vec[cnt].type<<" "<<posts_vec[cnt].title<<endl;
        cout<<" |“ "<<posts_vec[cnt].description<<" ”"<<endl;
        cout<<" |用户:"<<posts_vec[cnt].poster_user_name<<"  发布于: "<<posts_vec[cnt].post_time<<"  点赞: "<<posts_vec[cnt].likes<<"  回复: "<<posts_vec[cnt].posts.size()<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
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
        cout<<" —————————————————————————————————————————————--"<<endl;
        if (it->replier_account == posts_vec[i].poster_account)
            cout<<" |【"<<lou<<"楼】"<<"【发帖人】"<<it->replier_user_name<<" :"<<endl;
        else
            cout<<" |【"<<lou<<"楼】"<<it->replier_user_name<<" :"<<endl;
        if (it->reply_to_who != posts_vec[i].poster_user_name)
            cout<<"回复用户:<"<<it->reply_to_who<<">"<<endl;
        cout<<" |“ "<<it->reply<<" ”"<<endl;
        cout<<" |"<<it->reply_time<<"    "<<"赞: "<<it->likes<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
        lou++;
    }
}

void Post::reply_to_theme_post(int i, Account replier_ac)
{
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<"请选择你要回复的楼层(评论主题帖【0】):";
        int floor;
        char tmp111[50];
        cin>>floor;
        gets(tmp111);
        if (floor < 0 || floor > posts_vec[i].posts.size())
        {
            cout<<"回复用户选择错误,请重新发表评论!"<<endl;
            system("pause");
            return;
        }
        string reply_to;
        if (floor == 0)
            reply_to = posts_vec[i].poster_user_name;
        else
            reply_to = posts_vec[i].posts[floor - 1].replier_user_name;
        cout<<"回复:>"<<reply_to<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<"请输入您要回复的内容:";
        string text;
        char tmp123[20];
        cin>>text;
        gets(tmp123);
        cout<<" ———————————————————----loading—————————————————————--"<<endl;
        string reply_time = Get_time();
        string like = "0";
        Post reply(replier_ac.user_name, replier_ac.account, text, reply_time, like, reply_to);
        posts_vec[i].posts.push_back(reply);
        cout<<"评论发送成功!"<<endl;
        system("pause");
        return;
}

void Post::upvote_someone(int i)
{
    cout<<" —————————————————————————————————————————————--"<<endl;
    cout<<"请选择你要点赞的楼层(点赞主题帖【0】):";
    int floor;
    cin>>floor;
    if (floor < 0 || floor > posts_vec[i].posts.size())
    {
        cout<<"没有该楼层,请重新选择!"<<endl;
        system("pause");
        return;
    }
    string like_to;
    if (floor == 0)
    {
        like_to = posts_vec[i].poster_user_name;
        cout<<"点赞:>"<<like_to<<endl;
        int to_like = stoi(posts_vec[i].likes);
        to_like++;
        posts_vec[i].likes = to_string(to_like);
    }
    else
    {
        like_to = posts_vec[i].posts[floor - 1].replier_user_name;
        cout<<"点赞:>"<<like_to<<endl;
        int to_like = stoi(posts_vec[i].posts[floor - 1].likes);
        to_like++;
        posts_vec[i].posts[floor - 1].likes = to_string(to_like);
    }
    cout<<" ————————————————————--loading———————————————————--"<<endl;
    cout<<"点赞成功!"<<endl;
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
        cout<<"【0】<{==返回   【1】(＾——＾)ゞ点赞  "<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<" |【主题帖】"<<posts_vec[i].type<<" "<<posts_vec[i].title<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<" |【发帖人】"<<posts_vec[i].poster_user_name<<" :"<<endl;
        cout<<" |“ "<<posts_vec[i].description<<" ”"<<endl;
        cout<<" |发布于:"<<posts_vec[i].post_time<<"   点赞:"<<posts_vec[i].likes<<"   回复:"<<posts_vec[i].posts.size()<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
        if (posts_vec[i].posts.size() != 0)
        {
            display_reply_posts(i);
        }
        cout<<endl;
        cout<<"【2】点赞    【3】回复_________________________________"<<endl;
        cout<<"请输入你的选择:>";
        char op2;
        char tmp[50];
        cin>>op2;
        gets(tmp);
        if (strlen(tmp) != 0)
        {
            cout<<"选择错误,请重新选择!"<<endl;
        }
        else
        {
            if (op2 == '0')
            {
                return;
            }
            else if (visitor_ac.authority == "-1")
            {
                cout<<"你已被管理员加入封禁名单，您暂时无法使用社区功能！"<<endl;
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
                cout<<"选择错误,请重新选择!"<<endl;
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
        cout<<"【0】<{==返回  【1】按关键词检索  【2】按日期检索  【3】按类型检索"<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<" |请输入您的选择:>";
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
            cout<<" —————————————————————————————————————————————--"<<endl;
            cout<<" |请输入关键词:>";
            string keyword;
            cin>>keyword;
            ok = 0;
            for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
            {
                if (it->title.find(keyword) != it->title.npos)
                {
                    ok = 1;
                    cout<<" —————————————————————————————————————————————--"<<endl;
                    cout<<" |["<<it->now_pos<<"] ";
                    cout<<it->type<<" "<<it->title<<endl;
                    cout<<" |“ "<<it->description<<" ”"<<endl;
                    cout<<" |用户:"<<it->poster_user_name<<"  发布于: "<<it->post_time<<"  点赞: "<<it->likes<<"  回复: "<<it->posts.size()<<endl;
                    cout<<" —————————————————————————————————————————————--"<<endl;
                }
            }
            if (ok == 0)
            {
                cout<<" —————————————————————————————————————————————--"<<endl;
                cout<<"未查询到与“"<<keyword<<"”有关的内容,请缩小关键词以扩大检索范围。"<<endl;
            }
        }
        else if (op == '2')
        {
            time_t currentTime = time(nullptr);
            tm* localTime = localtime(&currentTime);
            cout<<" —————————————————————————————————————————————--"<<endl;
            cout<<" |请输入日期(年-月-日):>"<<endl;
            cout<<" —————————————————————————————————————————————--"<<endl;
            cout<<" |年:>";
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
                cout<<"非法输入！"<<endl;
                Sleep(600);
                continue;
            }
            cout<<" —————————————————————————————————————————————--"<<endl;
            cout<<" |月:>";
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
                cout<<"非法输入！"<<endl;
                Sleep(600);
                continue;
            }
            cout<<" —————————————————————————————————————————————--"<<endl;
            cout<<" |日:>";
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
                cout<<"非法输入！"<<endl;
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
                    cout<<" —————————————————————————————————————————————--"<<endl;
                    cout<<" |["<<it->now_pos<<"] ";
                    cout<<it->type<<" "<<it->title<<endl;
                    cout<<" |“ "<<it->description<<" ”"<<endl;
                    cout<<" |用户:"<<it->poster_user_name<<"  发布于: "<<it->post_time<<"  点赞: "<<it->likes<<"  回复: "<<it->posts.size()<<endl;
                    cout<<" —————————————————————————————————————————————--"<<endl;
                }
            }
            if (ok == 0)
            {
                cout<<" —————————————————————————————————————————————--"<<endl;
                cout<<"未查询到“"<<date<<"”当天有关的内容。"<<endl;
            }
        }
        else if (op == '3')
        {
            cout<<" |请选择检索的帖子类型 [1]闲聊 [2]学习 [3]求助 [4]招聘 [5]通知 :>";
            char op;
            char tmp[30];
            cin>>op;
            string tmp_type;;
            if (op == '1') {tmp_type = "[闲聊]";}
            else if (op == '2') {tmp_type = "[学习]";}
            else if (op == '3') {tmp_type = "[求助]";}
            else if (op == '4') {tmp_type = "[招聘]";}
            else if (op == '5') {tmp_type = "【通知】";}
            else
            {
                cout<<"无效选择！"<<endl;
                system("pause");
                continue;
            }
            ok = 0;
            for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
            {
                if (it->type == tmp_type)
                {
                    ok = 1;
                    cout<<" —————————————————————————————————————————————--"<<endl;
                    cout<<" |["<<it->now_pos<<"] ";
                    cout<<it->type<<" "<<it->title<<endl;
                    cout<<" |“ "<<it->description<<" ”"<<endl;
                    cout<<" |用户:"<<it->poster_user_name<<"  发布于: "<<it->post_time<<"  点赞: "<<it->likes<<"  回复: "<<it->posts.size()<<endl;
                    cout<<" —————————————————————————————————————————————--"<<endl;
                }
            }
            if (ok == 0)
            {
                cout<<" —————————————————————————————————————————————--"<<endl;
                cout<<"未查询到“"<<tmp_type<<"”类型的帖子。"<<endl;
            }
        }
        if (ok == 1)
        {
            cout<<" —————————————————————————————————————————————--"<<endl;
            cout<<"请输入对应的序号进入帖子(输入[0]返回):>";
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
                cout<<"选择错误，请重新选择！"<<endl;
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
        cout<<"资料共享："<<endl;
        int flagz = 0;
        for (auto it = posts_vec.begin(); it != posts_vec.end(); it++)
        {

            if(it->type == "[资料]")
            {
                flagz = 1;
                cout<<" —————————————————————————————————————————————--"<<endl;
                cout<<" |["<<it->now_pos<<"] ";
                cout<<it->type<<" "<<it->title<<endl;
                cout<<" |“ "<<it->description<<" ”"<<endl;
                cout<<" |用户:"<<it->poster_user_name<<"  发布于: "<<it->post_time<<"  点赞: "<<it->likes<<"  回复: "<<it->posts.size()<<endl;
                cout<<" —————————————————————————————————————————————--"<<endl;
            }
        }
        if (flagz == 0)
        {
            cout<<"暂无用户分享资料！"<<endl;
            cout<<" —————————————————————————————————————————————--"<<endl;
        }
        cout<<"【0】<=返回 【1】共享资料 【else】选择相应的序号进入帖子"<<endl;
        cout<<" —————————————————————————————————————————————--"<<endl;
        cout<<" |请输入您的选择:>";
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
            cout<<" ————————————————————————————————————————————————————————————"<<endl;
            cout<<"|发布帖子，共享资料："<<endl;
            cout<<" ————————————————————————————————————————————————————————————"<<endl;
            cout<<"|帖子类型:> [资料]"<<endl;
            string tmp_type = "[资料]";
            cout<<" ————————————————————————————————————————————————————————————"<<endl;
            cout<<"|请输入帖子标题：";
            string tmp_title;
            cin>>tmp_title;
            char tmp123[20];
            gets(tmp123);
            if (tmp_title.size() >= 60)
            {
                cout<<"标题不宜过长！"<<endl;
                Sleep(700);
                continue;
            }
            cout<<" ————————————————————————————————————————————————————————————"<<endl;
            cout<<"|请输入要分享的资料链接(严禁传播违法违规等不良有害信息,如有违规,管理员将对账号进行封禁处理!):";
            string tmp_descrip;
            cin>>tmp_descrip;
            char tmp1234[20];
            gets(tmp1234);
            cout<<" ———————————————————————————loading———————————————————————————"<<endl;
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
            cout<<"帖子发布成功！"<<endl;
        }
        else if (flagz != 0 && ok == 1 && op != "0" && stoi(op) <= posts_vec.size() + 9 && stoi(op) >= 10)
        {
            enter_post(stoi(op), my_ac);
            return;
        }
        else
        {
            cout<<"选择错误，请重新选择！"<<endl;
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
        cout<<"无法打开文件！"<<endl;
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
            if (infos[0] == "置顶")
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
            output << "置顶  "<<posts_top.size()<<endl;
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
        cout << "文件存储失败!" << endl;
}

#endif
