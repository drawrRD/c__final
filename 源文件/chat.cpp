#include "chat.h"



string ram = "1234567890qwertyuiopasdfghjklzxcvbnm";
int tim = 0;
void anykey()
{
    cout << "任意键继续...";
    cin.ignore();
    cin.get();
}
string di = "  ***      \n"
            "*      *  \n"
            "*      *       + 新同学查找界面 +\n"
            "  *** \n"
            "       **\n"
            "         **";


string makeradom()
{
    string xx;
    srand(time(NULL));
    for (int i = 0; i < 8; i++)
        xx += ram[rand() % 36];
    return xx;
}

void chatcloud::show_record(string x)
{
    int i, k;
    if (re_num < 25)
        k = 0;
    else
        k = re_num - 25;
    for (i = k; i < re_num; i++)
    {
        cout << record[i].first << endl;
        cout << record[i].second << endl;
        cout << endl;
    }
}


bool chatcloud::findme(string x)
{
    for (int i = 0; i < number; i++)
    {
        if (x == mem_mes[i].first)
            return true;
    }
    return false;
}
istream &operator>>(istream &file, chatcloud &x)
{
    file >> x.num;
    file >> x.name;
    file >> x.number;
    file.ignore();
    file >> x.re_num;
    file.ignore();
    string username, user_id;
    x.mem_mes.clear();
    for (int i = 0; i < x.number; i++)
    {
        file >> username >> user_id;
        x.mem_mes.push_back(make_pair(username, user_id));
    }
    x.record.clear();
    string sender, date;
    for (int i = 0; i < x.re_num; i++)
    {
        file >> sender >> date;
        x.record.push_back(make_pair(sender, date));
    }
    file >> x.last;
    tim = max(tim, x.last);
    file.ignore();
    return file;
}
ostream &operator<<(ostream &file, chatcloud &x)
{
    file << x.num << endl;
    file << x.name << endl;
    file << x.number << endl;
    file << x.re_num << endl;
    int i;
    for (i = 0; i < x.number; i++)
    {
        file << x.mem_mes[i].first << " " << x.mem_mes[i].second << endl;
    }
    for (i = 0; i < x.re_num; i++)
    {
        file << x.record[i].first << " " << x.record[i].second << endl;
    }
    file << x.last << endl;
    return file;
}


chats_save::chats_save(user_base mm) : base(), now(), match_pair(), match_friend()
{
    ifstream filename("chatting.txt");
    if (!filename.is_open())
    {
        cout << "无法打开文件！" << endl;
        return;
    }
    my = mm;
    chatcloud xx(mm);
    while (filename >> xx)
    {
        base.push_back(xx);
        cloudaccout.push_back(xx.chat_num());
        if (xx.findme(my.num))
        {
            if (xx.number == 1 && xx.num == "imform")
            {
                system_use.push_back({xx.record[0].first, xx.record[0].second});
                sy_me_pair.insert({system_use.size() - 1, base.size() - 1});
            }
            else
            {
                match_pair.insert(make_pair(xx.chat_num(), base.size() - 1));
                if (xx.re_num)
                    now.push_back(make_pair(xx.chat_num(), xx.ti()));
                if (xx.number == 2)
                {
                    if (xx.mem_mes[0].first == my.num)
                        match_friend.insert({xx.mem_mes[1].first, xx.chat_num()});
                    else
                        match_friend.insert({xx.mem_mes[0].first, xx.chat_num()});
                }
            }
        }
    }
    tim++;
    filename.close();
}







vector<string> bad = {"装逼", "草泥马", "特么的", "撕逼", "玛拉戈壁", "爆菊", "JB", "呆逼", "本屌", "齐B短裙", "法克鱿", "丢你老母", "达菲鸡", "装13", "逼格", "蛋疼", "傻逼", "绿茶婊", "你妈的", "表砸", "屌爆了", "买了个婊", "已撸", "吉跋猫", "妈蛋", "逗比", "我靠", "碧莲", "碧池", "然并卵", "日了狗", "屁民", "吃翔", "XX狗", "淫家", "你妹", "浮尸国", "滚粗"};
bool meland::judge(string x)
{
    for (auto i = bad.begin(); i != bad.end(); i++)
    {
        if (x.find(*i) != -1)
            return false;
    }
    return true;
}
void meland::dele_myfir(int room_index)
{
    string x, y, nn, other;
    x = all.base[room_index].mem_mes[0].first;
    y = all.base[room_index].mem_mes[1].first;
    nn = all.base[room_index].num;
    if (x == my.num)
        other = y;
    else
        other = x;
    all.cloudaccout.erase(remove(all.cloudaccout.begin(), all.cloudaccout.end(), nn), all.cloudaccout.end());
    all.base.erase(all.base.begin() + room_index);
    all.match_pair.erase(nn);
    all.match_friend.erase(other);
    for (auto i = FF.BFF.begin(); i != FF.BFF.end(); i++)
    {
        if ((*i).num == other)
        {
            i = FF.BFF.erase(i);
            break;
        }
    }
    int kk = myfinddd(other);
    for (auto i = FF.all_friend[kk].fri.begin(); i != FF.all_friend[kk].fri.end(); i++)
    {
        if ((*i).num == my.num)
        {
            i = FF.all_friend[kk].fri.erase(i);
            break;
        }
    }
    FF.all_friend[kk].number_fir--;
    for (auto i = FF.all_friend[FF.iidex].fri.begin(); i != FF.all_friend[FF.iidex].fri.end(); i++)
    {
        if ((*i).num == other)
        {
            i = FF.all_friend[FF.iidex].fri.erase(i);
            break;
        }
    }
    FF.all_friend[FF.iidex].number_fir--;
    for (auto i = all.now.begin(); i != all.now.end(); i++)
    {
        if ((*i).first == nn)
        {
            i = all.now.erase(i);
            break;
        }
    }
    cout << "删除成功" << endl;
    anykey();
}
string emo[30] = {"", "【不屑】(￣_,￣)", "【擦眼泪】(ノへ￣)", "【亲】（づ￣3￣）づ╭～", "【汗】Σ(°△°|||)︴", "【笨】(～￣(OO)￣)ブ", "【拍桌】o(*≧▽≦)ツ┏━┓", "【啵啵】(*￣3)(ε￣*)", "【喂】(#`O′)", "【愣住】(°ー°〃)", "【怨念】o(一︿一+)o", "【崩溃】o(≧口≦)o", "【太可怕了】ヽ(*。>Д<)o゜", "【伤心】(；′⌒`)", "【拜拜】ヾ(￣▽￣)Bye~Bye~"};
void meland::show_emoji()
{
    cout << "————————————————————————————————————————————————————" << endl;
    cout << "                  + 表情包库 +                        " << endl;
    cout << "   学了么~ 学了么~ 学了么~ 学了么~ 学了么~ 学了么~    " << endl;
    cout << "____________________________________________________" << endl;
    cout << endl;
    for (int i = 1; i <= 14; i++)
    {
        cout << "+ [" << i << "] ";
        cout << emo[i] << endl;
        cout << endl;
    }
    cout << "____________________________________________________" << endl;
    cout << "   学了么~ 学了么~ 学了么~ 学了么~ 学了么~ 学了么~    " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "请输入你要选择的表情：ヾ(￣▽￣) 直接返回请按【0】" << endl;
}
int meland::chose_emoji()
{
    int x;
    system("cls");
    show_emoji();
    while (cin >> x)
    {
        if (x >= 0 && x <= 14)
            break;
        else
            cout << "没有这个选项哦~ 请再次输入吧 <(￣︶￣)↗[GO!]" << endl;
        Sleep(500);
        system("cls");
        show_emoji();
    }
    return x;
}
void meland::create_wel()
{
    system("cls");
    cout << "~请选择您的好友一起创建聊天云吧~" << endl;
    cout << "————————————————————————————————————————————" << endl;
    show_friends();
    cout << endl;
    cout << endl;
    cout << "已选择：";
    cout << "+ 请一个个选择，不要着急哦~ (选择完毕后请按【*】)" << endl;
}
void meland::cloud_face()
{
    chatcloud chuang(my);
    system("cls");
    create_wel();
    string xx;
    int x;
    chuang.num = makeradom();
    while (cin >> xx)
    {
        if (xx == "*")
            break;
        x = xx[0] - '0';
        if (xx.size() != 1)
        {
            cout << "+ 输入多个字符 请重新输入" << endl;
        }
        else if (xx.size() == 1 && (x <= 0 || x > FF.BFF.size()))
        {
            cout << "上面没有这个好友哦" << endl;
        }
        else if (xx.size() == 1 && (x > 0 && x <= FF.BFF.size()))
        {
            chuang.ad_member(FF.BFF[x - 1].num, FF.BFF[x - 1].showname());
            cout << "添加成功!" << endl;
        }
        system("cls");
        cout << "~请选择您的好友一起创建聊天云吧~ (不能只选择一个好友哦！)" << endl;
        cout << "————————————————————————————————————————————" << endl;
        show_friends();
        cout << endl;
        cout << endl;
        cout << "已选择：";
        chuang.show_member();
        cout << endl;
        cout << endl;
        cout << "+ 请一个个选择，不要着急哦~ (选择完毕后请按【*】)" << endl;
    }
    if (chuang.number == 1 || chuang.number == 0)
    {
        system("cls");
        cout << "~请选择您的好友一起创建聊天云吧~ (不能只选择一个好友哦！)" << endl;
        cout << "————————————————————————————————————————————" << endl;
        show_friends();
        cout << endl;
        cout << endl;
        cout << "已选择：";
        chuang.show_member();
        cout << "————————————————————————————————————————————" << endl;
        cout << "！！！不能只选择一个好友 创建失败啦" << endl;
        Sleep(1000);
        return;
    }
    cout << endl;
    cout << endl;
    cout << "+ 聊天云成员:  ";
    chuang.show_member();
    cout << endl;
    cout << "————————————————————————————————————————————" << endl;
    cout << "选择成功!" << endl;
    cout << "给你们的聊天云起个名字吧 (注意不要重复哦,不然你自己也分不清是哪个啦)" << endl;
    cin >> chuang.name;
    chuang.last = tim++;
    chuang.ad_member(my.num, my.name);
    all.add_new_cloud(chuang);
    cout << "创建聊天云成功！  <(￣︶￣)↗[GO!] 一起来聊天吧" << endl;
    Sleep(1000);
}
bool meland::cmp_now(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
void meland::show_now()
{
    int i, ii;
    if (all.now.size() == 0)
        return;
    sort(all.now.begin(), all.now.end(), cmp_now);
    for (i = 0; i < all.now.size(); i++)
    {
        ii = all.match_pair[all.now[i].first];
        if (all.base[ii].name != all.base[ii].num)
            cout << "+ [" << i + 1 << "]  <" << all.base[ii].cloud_name() << ">*" << endl;
        else
            cout << "+ [" << i + 1 << "]  <" << all.base[ii].cloud_name() << ">" << endl;
    }
}
void meland::chattingface_now(int x)
{
    int index = all.match_pair[all.now[x - 1].first];
    chat_inputs(all.base[index].cloud_name(), index);
}
void meland::chatcloud_face()
{
    system("cls");
    cout << "—————————————————————最近聊天云—————————————————————" << endl;
    cout << endl;
    show_now();
    cout << endl;
    cout << "————————————————————————————————————————————————————" << endl;
    cout << "+  加*为多人聊天云 如想创建新的多人聊天云 请再按【*】  +" << endl;
    cout << endl;
    cout << "请选择您的聊天云:(按下回车以确认, 按【0】返回)" << endl;
}
void meland::chatcloud_interface()
{
    string xx;
    int x;
    chatcloud_face();
    while (cin >> xx)
    {
        x = xx[0] - '0';
        if (x <= all.now.size() && x > 0)
        {
            chattingface_now(x);
        }
        else if (x == 0)
            break;
        else if (xx == "*")
        {
            cloud_face();
        }
        else
        {
            cout << "输入错误 请再次输入！" << endl;
            Sleep(500);
        }
        chatcloud_face();
    }
}
void meland::friend_face()
{
    system("cls");
    cout << "———————————————————————— " << my.name << " 同学的好友 ——————————————————————————" << endl;
    cout << endl;
    show_friends();
    cout << endl;
    cout << "请选择按序号输入您要聊天的好友：(按下回车以确认, 按【0】返回)" << endl;
}
void meland::connect_friend_face()
{
    string xx;
    int x;
    friend_face();
    while (cin >> xx)
    {
        x = xx[0] - '0';
        if (x <= FF.BFF.size() && x > 0)
        {
            chattingface_friend(x);
        }
        else if (x == 0)
        {
            break;
        }
        else
        {
            cout << "输入错误 请再次输入！" << endl;
            Sleep(500);
        }
        friend_face();
    }
}
void meland::show_friends()
{
    int i;
    for (i = 0; i < FF.BFF.size(); i++)
    {
        cout << "+ [" << i + 1 << "] ";
        cout << FF.BFF[i].showname() << endl;
    }
}
void meland::functionbar()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "+  如想不再接收当前聊天云发出的消息 请按【$$】   +" << endl;
    cout << "——————————————————————————————————————————————————————————————————————————————" << endl;
    cout << "+  [%] 表情包    [*] 返回    [^^] 拍一拍你的同学 说'太卷了'   +" << endl;
    cout << "+  [~] 消息记录  [+] 成员信息" << endl;
    cout << "——————————————————————————————————————————————————————————————————————————————" << endl;
    cout << endl;
}
void meland::dele_cloud(int x)
{
    cout << endl;
    cout << endl;
    cout << "\t";
    cout << "+++   +++   +++   +++   +++   +++   +++   ++++  +++  +++" << endl;
    cout << "\t";
    cout << "||  qwq 请确定您清除该聊天云 如清除您将不再收到该消息    ||" << endl;
    cout << "\t";
    cout << "+++   +++   +++   +++   +++   +++   +++   ++++  +++  +++" << endl;
    cout << endl;
    cout << "\t";
    cout << "【YES】以确定, 任意键以取消" << endl;
    string tex;
    cin >> tex;
    if (tex == "YES")
    {
        for (auto i = all.now.begin(); i != all.now.end(); i++)
        {
            if ((*i).first == all.visited_cloud(x).num)
            {
                i = all.now.erase(i);
                break;
            }
        }
        all.base[x].es_member(my.num);
        cout << "清除聊天云成功！" << endl;
    }
}
void meland::chat_inputs(string title, int room_index)
{
    system("cls");
    chatshow(title);
    all.visited_cloud(room_index).show_record(my.name); // 输出前20条
    cout << endl;
    functionbar();
    cout << endl;
    cout << "╰(*°▽°*)╯|...please enter:(输出的所有空格都将被忽视)";
    string tex;
    while (cin >> tex)
    {
        tex.erase(remove(tex.begin(), tex.end(), ' '), tex.end());
        if (tex == "*")
            break;
        else if (tex == "%")
        {
            int x = chose_emoji();
            string tt = emo[x];
            tt.erase(remove(tt.begin(), tt.end(), ' '), tt.end());
            if (x != 0)
                all.add_record(emo[x], room_index, my.name);
        }
        else if (tex == "^^")
        {
            all.add_record("~~~~~~~~~~拍一拍'" + title + "'说~'太太太卷了'", room_index, my.name);
        }
        else if (tex == "$$")
        {
            if (all.base[room_index].name != all.base[room_index].num)
            {
                dele_cloud(room_index);
                Sleep(1000);
                break;
            }
            else
            {
                cout << endl;
                cout << "这不是多人聊天云哦，你是否想删除好友？ 【YES】是 【NO】否 【任意键】返回" << endl;
                string op;
                cin >> op;
                if (op == "YES")
                {
                    dele_myfir(room_index);
                    return;
                }
                else if (op == "NO")
                {
                    anykey();
                }
            }
        }
        else if (tex == "+")
        {
            cout << endl;
            if (all.base[room_index].chat_num() == all.base[room_index].name)
            {
                if (all.base[room_index].mem_mes[0].first == my.num)
                {
                    cout << "<" << all.base[room_index].mem_mes[1].second << ">";
                }
                else
                {
                    cout << "<" << all.base[room_index].mem_mes[0].second << ">";
                }
            }
            else
                cout << "<" << all.base[room_index].name << ">";
            cout << " 好友信息" << endl;
            cout << "————————————————————" << endl;

            for (int i = 0; i < all.base[room_index].mem_mes.size(); i++)
            {
                cout << all.base[room_index].mem_mes[i].first << "   " << all.base[room_index].mem_mes[i].second << endl;
            }
            anykey();
        }
        else if (tex == "~")
        {
            cout << endl;
            if (all.base[room_index].chat_num() == all.base[room_index].name)
            {
                if (all.base[room_index].mem_mes[0].first == my.num)
                {
                    cout << "<" << all.base[room_index].mem_mes[1].second << ">";
                }
                else
                {
                    cout << "<" << all.base[room_index].mem_mes[0].second << ">";
                }
            }
            else
                cout << "<" << all.base[room_index].name << ">";
            cout << " 好友信息" << endl;
            cout << "————————————————————" << endl;

            for (int i = 0; i < all.base[room_index].record.size(); i++)
            {
                cout << all.base[room_index].record[i].first << "   " << all.base[room_index].record[i].second << endl;
            }
            anykey();
        }
        else
        {
            if (judge(tex))
                all.add_record(tex, room_index, my.name);
            else
            {
                cout << "你输入的字符不符合规定奥~ 请输入文明用语" << endl;
                anykey();
            }
        }
        system("cls");
        chatshow(title);
        all.visited_cloud(room_index).show_record(my.name);
        cout << endl;
        functionbar();
        cout << endl;
        cout << "╰(*°▽°*)╯|...please enter:(输出的所有空格都将被忽视)";
    }
}
void meland::chatshow(string x)
{
    cout << "" << endl;
    cout << "\t\t+ " << setw(x.size()) << x << " +" << endl;
    cout << "—————————————————————————————————————————————————" << endl;
}
void meland::chattingface_friend(int x)
{
    int room_index;
    auto it = all.match_friend.find(FF.BFF[x - 1].num);
    if (it != all.match_friend.end())
    {
        room_index = all.match_pair[it->second];
    }
    else
    {
        string xx = all.save_newfriend(my.num, FF.BFF[x - 1].num, my.name, FF.BFF[x - 1].showname());
        room_index = all.match_pair[xx];
    }
    chat_inputs(FF.BFF[x - 1].showname() + " 同学", room_index);
}
bool cmp_fn(pair<string, int> a, pair<string, int> b)
{
    return a.first < b.first;
}
int meland::myfinddd(string x)
{
    sort(FF.Buffer.begin(), FF.Buffer.end(), cmp_fn);
    int left = 0, right = FF.Buffer.size() - 1, mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (FF.Buffer[mid].first == x)
        {
            return FF.Buffer[mid].second;
        }
        else if (FF.Buffer[mid].first < x)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return -1;
}
void meland::add_friends_inface()
{
    string tex;
    system("cls");
    cout << di << endl;
    cout << endl;
    cout << endl;
    cout << "+ 请输入你想要查找的用户ID   o(*≧▽≦)ツ" << endl;
    cin >> tex;
    for (auto i = FF.BFF.begin(); i != FF.BFF.end(); i++)
    {
        if ((*i).num == tex)
        {
            cout << "你已将该同学添加至好友列表，不用再重复添加了~" << endl;
            Sleep(1600);
            return;
        }
    }
    int kk = myfinddd(tex);
    int all_block_num = 20;
    for (int i = 0; i < all_block_num; i++)
    {
        printf("\r[%d%%]>", i * 100 / (all_block_num - 1));
        for (int j = 1; j <= i * 8 / all_block_num; j++)
        {
            cout << "*";
            Sleep(10);
        }
    }
    cout << " 查找完毕" << endl;
    if (kk >= 0)
    {
        cout << "已找到该同学 (≧▽≦)" << endl;
        cout << endl;
        cout << "+ 用户ID: " << tex << endl;
        cout << "+ 用户昵称：" << FF.all_friend[kk].name << endl;
        string tt;
        cout << "+ 请输入你的好友验证内容:" << endl;
        cin >> tt;
        all.sendmessage(my.num, my.name + ":" + tt, tex);
        cout << "已发送好友申请消息  <(￣︶￣)↗[GO!]" << endl;
    }
    else
        cout << "+ 未找到该同学，请检查输入是否有误" << endl;
    Sleep(1600);
}
void meland::print_wel()
{
    system("cls");
    cout << "欢迎你，" << my.name << endl;
    cout << endl;
    cout << "————————————————————————我的学了么————————————————————————" << endl;
    cout << endl;
    cout << "[1] 最近聊天云      [2] 我的好友    [3] 添加好友" << endl;
    cout << "[4] 通知收件箱      [0] 退出  " << endl;
    cout << endl;
    cout << "请选择您要进行的操作:(按下回车以确认)" << endl;
}
void meland::imform_print()
{
    system("cls");
    printf("╔══════════════════════════════════╗\n");
    printf("║            通知收件箱            ║\n");
    printf("╚══════════════════════════════════╝\n");
    cout << endl;
    int index = 0;
    for (auto i = all.system_use.begin(); i != all.system_use.end(); i++)
    {
        index++;
        if ((*i).first == "管理员kiki")
        {
            cout << "+ [" << index << "] 系统通知 " << (*i).second << endl;
            cout << endl;
        }
        else
        {
            cout << "+ [" << index << "] 来自ID号为 " << (*i).first << " 的好友申请：" << (*i).second << endl;
            cout << endl;
        }
    }
    cout << "——————————————————————————————————————" << endl;
    cout << "请输入您要进行查看的通知编号(按【0】返回)" << endl;
}
void meland::refuse_op(string x)
{
    all.sendmessage("管理员kiki", my.name + ":不好意思,我已拒绝你的邀请", x); //
}
void meland::add_friend(int kk) // 该好友的all——friend 下标//各个函数初始化
{
    string xx;
    string yy = FF.all_friend[kk].me_num;
    auto it = all.match_friend.find(yy);
    if (it != all.match_friend.end() && all.match_friend.size() > 0)
    {
        cout << "请勿重复添加好友" << endl;
        anykey();
        return;
    }
    cout << endl;
    cout << "请输入该好友的备注名" << endl;
    cin >> xx;
    xx.erase(remove(xx.begin(), xx.end(), ' '), xx.end());
    myfriend A(my.num, my.name, my.name), B(yy, FF.all_friend[kk].name, xx);
    FF.all_friend[kk].number_fir++;
    FF.all_friend[kk].fri.push_back(A);
    FF.BFF.push_back(B);
    FF.all_friend[FF.iidex].number_fir++;
    FF.all_friend[FF.iidex].fri.push_back(B);
    cout << "添加成功!快去和小同学聊天吧" << endl;
    string nn = all.save_newfriend(my.num, yy, my.name, xx);
    int room_index = all.match_pair[nn];
    all.add_record("一起开始聊天吧~", room_index, my.name);
    anykey();
}
void meland::check_imform(int x)
{
    system("cls");
    if (all.system_use[x - 1].first == "管理员kiki")
    {
        printf("╔══════════════════════════════════╗\n");
        printf("║            系统通知              ║\n");
        printf("╚══════════════════════════════════╝\n");
        cout << endl;
        cout << "++ " << all.system_use[x - 1].second << endl;
        anykey();
        all.base.erase(all.base.begin() + all.sy_me_pair[x - 1]);
        all.system_use.erase(all.system_use.begin() + x - 1);
    }
    else
    {
        printf("╔══════════════════════════════════╗\n");
        printf("║            验证消息              ║\n");
        printf("╚══════════════════════════════════╝\n");
        cout << endl;
        cout << "来自用户ID为 " << all.system_use[x - 1].first << " :" << endl;
        cout << all.system_use[x - 1].second << endl;
        string op, opp;
        cout << endl;
        cout << "是否选择加该同学为好友呢？ 【YES】是  【NO】拒绝 【其他任意键】 返回" << endl;
        cin >> op;
        if (op == "YES")
        {
            cout << "确定加入吗？ 【Y】以确认 任意键返回" << endl;
            cin >> opp;
            if (opp == "Y")
            {
                int xx = myfinddd(all.system_use[x - 1].first); // 系统用的
                all.base.begin() + all.sy_me_pair[x - 1] = all.base.erase(all.base.begin() + all.sy_me_pair[x - 1]);
                all.system_use.begin() + x - 1 = all.system_use.erase(all.system_use.begin() + x - 1);
                add_friend(xx);
            }
        }
        else if (op == "NO")
        {
            cout << "确定拒绝吗？ 【Y】以确认 任意键返回" << endl;
            cin >> opp;
            if (opp == "Y")
            {
                refuse_op(all.system_use[x - 1].first);
                all.base.erase(all.base.begin() + all.sy_me_pair[x - 1]);
                all.system_use.erase(all.system_use.begin() + x - 1);
            }
        }
    }
}
void meland::imform_mess_face()
{
    imform_print();
    string xx;
    int x;
    while (cin >> xx)
    {
        x = xx[0] - '0';
        if (xx == "0")
            break;
        if (x > 0 && x <= all.system_use.size())
        {
            check_imform(x);
        }
        else
        {
            cout << "输入错误，请再次输入" << endl;
            system("puase");
        }
        imform_print();
    }
}
void meland::me_wel()
{
    int x;
    print_wel();
    while (cin >> x)
    {
        switch (x)
        {
        case 1:
            chatcloud_interface();
            break;
        case 2:
            connect_friend_face();
            break;
        case 3:
            add_friends_inface();
            break;
        case 4:
            imform_mess_face();
            break;
        case 0:
            return;
            break;
        default:
            cout << "输入错误请再次输入" << endl;
            break;
        }
        system("cls");
        print_wel();
    }
}
void meland::check_prin()
{
    system("cls");
    for (int i = 0; i < all.base.size(); i++)
    {

        cout << "+ [" << i + 1 << "]  <" << all.base[i].num << ">" << endl;
    }
    cout << "请输入你想要查看的聊天云记录 (输入0退出)" << endl;
}
void meland::check_record(int x)
{
    system("cls");
    for (auto i = 0; i < all.base[x].record.size(); i++)
    {
        cout << "+ [" << i + 1 << "]  <" << all.base[x].record[i].second << ">" << endl;
    }
    cout << "请选择你要删除的记录(输入0退出)" << endl;
    string xx;
    int k;
    while (cin >> xx)
    {
        k = xx[0] - '0';
        if (k <= all.base[x].record.size() && k > 0)
        {
            all.base[x].record.erase(all.base[x].record.begin() + k - 1);
            all.base[x].re_num--;
        }
        else if (k == 0)
            break;
        else
        {
            cout << "输入错误 请再次输入！" << endl;
            Sleep(500);
        }
        cout << "请再次选择：" << endl;
    }
}
void meland::chatcloud_check()
{
    string xx;
    int x;
    check_prin();
    while (cin >> xx)
    {
        x = xx[0] - '0';
        if (x <= all.base.size() && x > 0)
        {
            check_record(x - 1);
        }
        else if (x == 0)
            break;
        else
        {
            cout << "输入错误 请再次输入！" << endl;
            Sleep(500);
        }
        check_prin();
    }
}
void meland::print_man()
{
    system("cls");
    cout << "欢迎你，" << my.name << endl;
    cout << endl;
    cout << "————————————————————————学了么操作端————————————————————————" << endl;
    cout << endl;
    cout << "[1] 聊天云记录     [2] 通知发布   [3] 聊天云搜索" << endl;
    cout << "[0] 退出  " << endl;
    cout << endl;
    cout << "请选择您要进行的操作:(按下回车以确认)" << endl;
}
void meland::check_search()
{
    system("cls");
    cout << "请输入你要查看的聊天云账户" << endl;
    string xx;
    int i;
    cin >> xx;
    for (i = 0; i != all.base.size(); i++)
    {
        if (all.base[i].num == xx)
        {
            check_record(i);
            break;
        }
    }
    if (i == all.base.size())
        cout << "未找到该聊天云" << endl;
    anykey();
    system("cls");
}

void meland::informall()
{
    system("cls");
    string tex;
    cout << "请输入你要发送的消息:(0返回)";
    cin >> tex;
    if (tex == "0")
        return;
    tex.erase(remove(tex.begin(), tex.end(), ' '), tex.end());
    sendall(tex);
    cout << "发送成功" << endl;
    anykey();
}
void meland::sendall(string tex)
{
    string member;
    for (auto i = 0; i < FF.all_friend.size(); i++)
    {
        member = FF.all_friend[i].me_num;
        all.sendmessage("管理员kiki", tex, member);
    }
}
void meland::mangement()
{
    int x;
    print_man();
    while (cin >> x)
    {
        switch (x)
        {
        case 1:
            chatcloud_check();
            break;
        case 2:
            informall();
            break;
        case 3:
            check_search();
            break;
        case 0:
            return;
            break;
        default:
            cout << "输入错误请再次输入" << endl;
            break;
        }
        system("cls");
        print_man();
    }
}





void chatcloud::add(string x, string re)
    {
        re_num++;
        record.push_back({x, re});
        last = tim++;
    }
    void chatcloud::ad_member(string num, string name)
    {
        mem_mes.push_back({num, name});
        record.push_back({name, "大家好啊~"});
        re_num++;
        number++;
    }
    void chatcloud::es_member(string x)
    {
        number--;
        for (auto i = mem_mes.begin(); i != mem_mes.end(); i++)
        {
            if (x == (*i).first)
            {
                i = mem_mes.erase(i);
                record.push_back({"用户" + x, "我已离开聊天云了，拜拜"});
                break;
            }
        }
    }
    void chatcloud::sendwarning(string a, string b)
    {
        record.push_back({a, b});
        re_num++;
    }
    string chatcloud::chat_num() { return num; }
    int chatcloud::mem_size() { return number; }
    int chatcloud::ti() { return last; }
    chatcloud::chatcloud(const chatcloud &t) : mem_mes(), record()
    {
        my = t.my;
        num = t.num;
        name = t.name;
        number = t.number;
        re_num = t.re_num;
        int i;
        for (i = 0; i < number; i++)
        {
            mem_mes.push_back(t.mem_mes[i]);
        }
        for (i = 0; i < re_num; i++)
            record.push_back(t.record[i]);
        last = t.last;
    }
    chatcloud::chatcloud(string xx, user_base aa) : mem_mes(), record()
    {
        my = aa;
        num = "imform";
        name = num;
        number = 1;
        re_num = 0;
        last = 0;
        mem_mes.push_back({xx, xx});
    }
    string chatcloud::cloud_name()
    {
        if (name == num)
        {
            if (my.name == mem_mes[0].second)
                return mem_mes[1].second;
            else
                return mem_mes[0].second;
        }
        else
            return name;
    }
    chatcloud::chatcloud(string b, string c, string d, string e, user_base xx) : mem_mes(), record()
    {
        my = xx;
        num = "";
        number = 2;
        re_num = 0;
        name = "";
        mem_mes.push_back({b, c});
        mem_mes.push_back({d, e});
        last = tim++;
    }
    chatcloud::chatcloud(user_base xx) : mem_mes(), record()
    {
        my = xx;
        num = "";
        number = 0;
        name = "";
        re_num = 0;
        last = 0;
    }
    void chatcloud::show_member()
    {
        int i;
        for (i = 0; i < number; i++)
            cout << mem_mes[i].second << " ";
    }





    bool chats_save::check(string x)
    {
        for (auto i = cloudaccout.begin(); i != cloudaccout.end(); i++)
        {
            if (*i == x)
                return false;
        }
        return true;
    }
    chats_save::~chats_save()
    {
        ofstream file("chatting.txt", ios::trunc);
        if (!file.is_open())
        {
            cout << "无法打开文件！" << endl;
            return;
        }

        for (int i = 0; i < base.size(); i++)
        {
            file << base[i];
        }
        file.close();
    }
    chats_save::chats_save(user_base xx);
    void chats_save::add_new_cloud(chatcloud x)
    {
        base.push_back(x);
        now.push_back({x.num, x.last});
        cloudaccout.push_back(x.num);
        match_pair.insert({x.num, base.size() - 1});
    }
    void chats_save::sendmessage(string inform, string text, string user)
    {
        text.erase(remove(text.begin(), text.end(), ' '), text.end());
        chatcloud x(user, my);
        x.add(inform, text);
        base.push_back(x);
    }
    string chats_save::save_newfriend(string num1, string num2, string name1, string name2)
    {
        chatcloud x(num1, name1, num2, name2, my);
        string xx = makeradom();
        while (!check(xx))
        {
            xx = makeradom();
        }
        x.num = xx;
        x.name = xx;
        cloudaccout.push_back(xx);
        string ff = (num1 == my.num) ? num2 : num1;
        base.push_back(x);
        match_pair.insert(make_pair(x.chat_num(), base.size() - 1));
        match_friend.insert(make_pair(ff, x.chat_num()));
        now.push_back(make_pair(x.chat_num(), x.ti()));
        return x.chat_num();
    }
    chatcloud &chats_save::visited_cloud(int x)
    {
        return base[x];
    }
    void chats_save::add_record(string x, int index, string me)
    {
        base[index].add(me, x);
        string xx = base[index].num;
        for (int i = 0; i < now.size(); i++)
        {
            if (now[i].first == xx)
            {
                now[i].second = tim - 1;
                break;
            }
        }
    }
