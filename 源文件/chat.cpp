#include "chat.h"



string ram = "1234567890qwertyuiopasdfghjklzxcvbnm";
int tim = 0;
void anykey()
{
    cout << "���������...";
    cin.ignore();
    cin.get();
}
string di = "  ***      \n"
            "*      *  \n"
            "*      *       + ��ͬѧ���ҽ��� +\n"
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
        cout << "�޷����ļ���" << endl;
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







vector<string> bad = {"װ��", "������", "��ô��", "˺��", "�������", "����", "JB", "����", "����", "��B��ȹ", "������", "������ĸ", "��Ƽ�", "װ13", "�Ƹ�", "����", "ɵ��", "�̲��", "�����", "����", "�ű���", "���˸��", "��ߣ", "����è", "�走", "����", "�ҿ�", "����", "�̳�", "Ȼ����", "���˹�", "ƨ��", "����", "XX��", "����", "����", "��ʬ��", "����"};
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
    cout << "ɾ���ɹ�" << endl;
    anykey();
}
string emo[30] = {"", "����м��(��_,��)", "�������᡿(�Τأ�)", "���ס����ţ�3�����Ũq��", "��������(�����|||)��", "������(����(OO)��)��", "��������o(*�R���Q)�ĩ�����", "���࣡�(*��3)(�ţ�*)", "��ι��(#`O��)", "���ס��(��`�㡨)", "��Թ�o(һ��һ+)o", "��������o(�R�ڨQ)o", "��̫�����ˡ��c(*��>��<)o�b", "�����ġ�(�����`)", "���ݰݡ��d(������)Bye~Bye~"};
void meland::show_emoji()
{
    cout << "��������������������������������������������������������������������������������������������������������" << endl;
    cout << "                  + ������� +                        " << endl;
    cout << "   ѧ��ô~ ѧ��ô~ ѧ��ô~ ѧ��ô~ ѧ��ô~ ѧ��ô~    " << endl;
    cout << "____________________________________________________" << endl;
    cout << endl;
    for (int i = 1; i <= 14; i++)
    {
        cout << "+ [" << i << "] ";
        cout << emo[i] << endl;
        cout << endl;
    }
    cout << "____________________________________________________" << endl;
    cout << "   ѧ��ô~ ѧ��ô~ ѧ��ô~ ѧ��ô~ ѧ��ô~ ѧ��ô~    " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "��������Ҫѡ��ı��飺�d(������) ֱ�ӷ����밴��0��" << endl;
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
            cout << "û�����ѡ��Ŷ~ ���ٴ������ <(�����)�J[GO!]" << endl;
        Sleep(500);
        system("cls");
        show_emoji();
    }
    return x;
}
void meland::create_wel()
{
    system("cls");
    cout << "~��ѡ�����ĺ���һ�𴴽������ư�~" << endl;
    cout << "����������������������������������������������������������������������������������������" << endl;
    show_friends();
    cout << endl;
    cout << endl;
    cout << "��ѡ��";
    cout << "+ ��һ����ѡ�񣬲�Ҫ�ż�Ŷ~ (ѡ����Ϻ��밴��*��)" << endl;
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
            cout << "+ �������ַ� ����������" << endl;
        }
        else if (xx.size() == 1 && (x <= 0 || x > FF.BFF.size()))
        {
            cout << "����û���������Ŷ" << endl;
        }
        else if (xx.size() == 1 && (x > 0 && x <= FF.BFF.size()))
        {
            chuang.ad_member(FF.BFF[x - 1].num, FF.BFF[x - 1].showname());
            cout << "��ӳɹ�!" << endl;
        }
        system("cls");
        cout << "~��ѡ�����ĺ���һ�𴴽������ư�~ (����ֻѡ��һ������Ŷ��)" << endl;
        cout << "����������������������������������������������������������������������������������������" << endl;
        show_friends();
        cout << endl;
        cout << endl;
        cout << "��ѡ��";
        chuang.show_member();
        cout << endl;
        cout << endl;
        cout << "+ ��һ����ѡ�񣬲�Ҫ�ż�Ŷ~ (ѡ����Ϻ��밴��*��)" << endl;
    }
    if (chuang.number == 1 || chuang.number == 0)
    {
        system("cls");
        cout << "~��ѡ�����ĺ���һ�𴴽������ư�~ (����ֻѡ��һ������Ŷ��)" << endl;
        cout << "����������������������������������������������������������������������������������������" << endl;
        show_friends();
        cout << endl;
        cout << endl;
        cout << "��ѡ��";
        chuang.show_member();
        cout << "����������������������������������������������������������������������������������������" << endl;
        cout << "����������ֻѡ��һ������ ����ʧ����" << endl;
        Sleep(1000);
        return;
    }
    cout << endl;
    cout << endl;
    cout << "+ �����Ƴ�Ա:  ";
    chuang.show_member();
    cout << endl;
    cout << "����������������������������������������������������������������������������������������" << endl;
    cout << "ѡ��ɹ�!" << endl;
    cout << "�����ǵ�������������ְ� (ע�ⲻҪ�ظ�Ŷ,��Ȼ���Լ�Ҳ�ֲ������ĸ���)" << endl;
    cin >> chuang.name;
    chuang.last = tim++;
    chuang.ad_member(my.num, my.name);
    all.add_new_cloud(chuang);
    cout << "���������Ƴɹ���  <(�����)�J[GO!] һ���������" << endl;
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
    cout << "��������������������������������������������������ơ�����������������������������������������" << endl;
    cout << endl;
    show_now();
    cout << endl;
    cout << "��������������������������������������������������������������������������������������������������������" << endl;
    cout << "+  ��*Ϊ���������� ���봴���µĶ��������� ���ٰ���*��  +" << endl;
    cout << endl;
    cout << "��ѡ������������:(���»س���ȷ��, ����0������)" << endl;
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
            cout << "������� ���ٴ����룡" << endl;
            Sleep(500);
        }
        chatcloud_face();
    }
}
void meland::friend_face()
{
    system("cls");
    cout << "������������������������������������������������ " << my.name << " ͬѧ�ĺ��� ����������������������������������������������������" << endl;
    cout << endl;
    show_friends();
    cout << endl;
    cout << "��ѡ�����������Ҫ����ĺ��ѣ�(���»س���ȷ��, ����0������)" << endl;
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
            cout << "������� ���ٴ����룡" << endl;
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
    cout << "+  ���벻�ٽ��յ�ǰ�����Ʒ�������Ϣ �밴��$$��   +" << endl;
    cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "+  [%] �����    [*] ����    [^^] ��һ�����ͬѧ ˵'̫����'   +" << endl;
    cout << "+  [~] ��Ϣ��¼  [+] ��Ա��Ϣ" << endl;
    cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << endl;
}
void meland::dele_cloud(int x)
{
    cout << endl;
    cout << endl;
    cout << "\t";
    cout << "+++   +++   +++   +++   +++   +++   +++   ++++  +++  +++" << endl;
    cout << "\t";
    cout << "||  qwq ��ȷ��������������� ��������������յ�����Ϣ    ||" << endl;
    cout << "\t";
    cout << "+++   +++   +++   +++   +++   +++   +++   ++++  +++  +++" << endl;
    cout << endl;
    cout << "\t";
    cout << "��YES����ȷ��, �������ȡ��" << endl;
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
        cout << "��������Ƴɹ���" << endl;
    }
}
void meland::chat_inputs(string title, int room_index)
{
    system("cls");
    chatshow(title);
    all.visited_cloud(room_index).show_record(my.name); // ���ǰ20��
    cout << endl;
    functionbar();
    cout << endl;
    cout << "�t(*�㨌��*)�s|...please enter:(��������пո񶼽�������)";
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
            all.add_record("~~~~~~~~~~��һ��'" + title + "'˵~'̫̫̫����'", room_index, my.name);
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
                cout << "�ⲻ�Ƕ���������Ŷ�����Ƿ���ɾ�����ѣ� ��YES���� ��NO���� �������������" << endl;
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
            cout << " ������Ϣ" << endl;
            cout << "����������������������������������������" << endl;

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
            cout << " ������Ϣ" << endl;
            cout << "����������������������������������������" << endl;

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
                cout << "��������ַ������Ϲ涨��~ ��������������" << endl;
                anykey();
            }
        }
        system("cls");
        chatshow(title);
        all.visited_cloud(room_index).show_record(my.name);
        cout << endl;
        functionbar();
        cout << endl;
        cout << "�t(*�㨌��*)�s|...please enter:(��������пո񶼽�������)";
    }
}
void meland::chatshow(string x)
{
    cout << "" << endl;
    cout << "\t\t+ " << setw(x.size()) << x << " +" << endl;
    cout << "��������������������������������������������������������������������������������������������������" << endl;
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
    chat_inputs(FF.BFF[x - 1].showname() + " ͬѧ", room_index);
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
    cout << "+ ����������Ҫ���ҵ��û�ID   o(*�R���Q)��" << endl;
    cin >> tex;
    for (auto i = FF.BFF.begin(); i != FF.BFF.end(); i++)
    {
        if ((*i).num == tex)
        {
            cout << "���ѽ���ͬѧ����������б��������ظ������~" << endl;
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
    cout << " �������" << endl;
    if (kk >= 0)
    {
        cout << "���ҵ���ͬѧ (�R���Q)" << endl;
        cout << endl;
        cout << "+ �û�ID: " << tex << endl;
        cout << "+ �û��ǳƣ�" << FF.all_friend[kk].name << endl;
        string tt;
        cout << "+ ��������ĺ�����֤����:" << endl;
        cin >> tt;
        all.sendmessage(my.num, my.name + ":" + tt, tex);
        cout << "�ѷ��ͺ���������Ϣ  <(�����)�J[GO!]" << endl;
    }
    else
        cout << "+ δ�ҵ���ͬѧ�����������Ƿ�����" << endl;
    Sleep(1600);
}
void meland::print_wel()
{
    system("cls");
    cout << "��ӭ�㣬" << my.name << endl;
    cout << endl;
    cout << "�������������������������������������������������ҵ�ѧ��ô������������������������������������������������" << endl;
    cout << endl;
    cout << "[1] ���������      [2] �ҵĺ���    [3] ��Ӻ���" << endl;
    cout << "[4] ֪ͨ�ռ���      [0] �˳�  " << endl;
    cout << endl;
    cout << "��ѡ����Ҫ���еĲ���:(���»س���ȷ��)" << endl;
}
void meland::imform_print()
{
    system("cls");
    printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("�U            ֪ͨ�ռ���            �U\n");
    printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
    cout << endl;
    int index = 0;
    for (auto i = all.system_use.begin(); i != all.system_use.end(); i++)
    {
        index++;
        if ((*i).first == "����Աkiki")
        {
            cout << "+ [" << index << "] ϵͳ֪ͨ " << (*i).second << endl;
            cout << endl;
        }
        else
        {
            cout << "+ [" << index << "] ����ID��Ϊ " << (*i).first << " �ĺ������룺" << (*i).second << endl;
            cout << endl;
        }
    }
    cout << "����������������������������������������������������������������������������" << endl;
    cout << "��������Ҫ���в鿴��֪ͨ���(����0������)" << endl;
}
void meland::refuse_op(string x)
{
    all.sendmessage("����Աkiki", my.name + ":������˼,���Ѿܾ��������", x); //
}
void meland::add_friend(int kk) // �ú��ѵ�all����friend �±�//����������ʼ��
{
    string xx;
    string yy = FF.all_friend[kk].me_num;
    auto it = all.match_friend.find(yy);
    if (it != all.match_friend.end() && all.match_friend.size() > 0)
    {
        cout << "�����ظ���Ӻ���" << endl;
        anykey();
        return;
    }
    cout << endl;
    cout << "������ú��ѵı�ע��" << endl;
    cin >> xx;
    xx.erase(remove(xx.begin(), xx.end(), ' '), xx.end());
    myfriend A(my.num, my.name, my.name), B(yy, FF.all_friend[kk].name, xx);
    FF.all_friend[kk].number_fir++;
    FF.all_friend[kk].fri.push_back(A);
    FF.BFF.push_back(B);
    FF.all_friend[FF.iidex].number_fir++;
    FF.all_friend[FF.iidex].fri.push_back(B);
    cout << "��ӳɹ�!��ȥ��Сͬѧ�����" << endl;
    string nn = all.save_newfriend(my.num, yy, my.name, xx);
    int room_index = all.match_pair[nn];
    all.add_record("һ��ʼ�����~", room_index, my.name);
    anykey();
}
void meland::check_imform(int x)
{
    system("cls");
    if (all.system_use[x - 1].first == "����Աkiki")
    {
        printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
        printf("�U            ϵͳ֪ͨ              �U\n");
        printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
        cout << endl;
        cout << "++ " << all.system_use[x - 1].second << endl;
        anykey();
        all.base.erase(all.base.begin() + all.sy_me_pair[x - 1]);
        all.system_use.erase(all.system_use.begin() + x - 1);
    }
    else
    {
        printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
        printf("�U            ��֤��Ϣ              �U\n");
        printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
        cout << endl;
        cout << "�����û�IDΪ " << all.system_use[x - 1].first << " :" << endl;
        cout << all.system_use[x - 1].second << endl;
        string op, opp;
        cout << endl;
        cout << "�Ƿ�ѡ��Ӹ�ͬѧΪ�����أ� ��YES����  ��NO���ܾ� ������������� ����" << endl;
        cin >> op;
        if (op == "YES")
        {
            cout << "ȷ�������� ��Y����ȷ�� ���������" << endl;
            cin >> opp;
            if (opp == "Y")
            {
                int xx = myfinddd(all.system_use[x - 1].first); // ϵͳ�õ�
                all.base.begin() + all.sy_me_pair[x - 1] = all.base.erase(all.base.begin() + all.sy_me_pair[x - 1]);
                all.system_use.begin() + x - 1 = all.system_use.erase(all.system_use.begin() + x - 1);
                add_friend(xx);
            }
        }
        else if (op == "NO")
        {
            cout << "ȷ���ܾ��� ��Y����ȷ�� ���������" << endl;
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
            cout << "����������ٴ�����" << endl;
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
            cout << "����������ٴ�����" << endl;
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
    cout << "����������Ҫ�鿴�������Ƽ�¼ (����0�˳�)" << endl;
}
void meland::check_record(int x)
{
    system("cls");
    for (auto i = 0; i < all.base[x].record.size(); i++)
    {
        cout << "+ [" << i + 1 << "]  <" << all.base[x].record[i].second << ">" << endl;
    }
    cout << "��ѡ����Ҫɾ���ļ�¼(����0�˳�)" << endl;
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
            cout << "������� ���ٴ����룡" << endl;
            Sleep(500);
        }
        cout << "���ٴ�ѡ��" << endl;
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
            cout << "������� ���ٴ����룡" << endl;
            Sleep(500);
        }
        check_prin();
    }
}
void meland::print_man()
{
    system("cls");
    cout << "��ӭ�㣬" << my.name << endl;
    cout << endl;
    cout << "������������������������������������������������ѧ��ô�����ˡ�����������������������������������������������" << endl;
    cout << endl;
    cout << "[1] �����Ƽ�¼     [2] ֪ͨ����   [3] ����������" << endl;
    cout << "[0] �˳�  " << endl;
    cout << endl;
    cout << "��ѡ����Ҫ���еĲ���:(���»س���ȷ��)" << endl;
}
void meland::check_search()
{
    system("cls");
    cout << "��������Ҫ�鿴���������˻�" << endl;
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
        cout << "δ�ҵ���������" << endl;
    anykey();
    system("cls");
}

void meland::informall()
{
    system("cls");
    string tex;
    cout << "��������Ҫ���͵���Ϣ:(0����)";
    cin >> tex;
    if (tex == "0")
        return;
    tex.erase(remove(tex.begin(), tex.end(), ' '), tex.end());
    sendall(tex);
    cout << "���ͳɹ�" << endl;
    anykey();
}
void meland::sendall(string tex)
{
    string member;
    for (auto i = 0; i < FF.all_friend.size(); i++)
    {
        member = FF.all_friend[i].me_num;
        all.sendmessage("����Աkiki", tex, member);
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
            cout << "����������ٴ�����" << endl;
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
        record.push_back({name, "��Һð�~"});
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
                record.push_back({"�û�" + x, "�����뿪�������ˣ��ݰ�"});
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
            cout << "�޷����ļ���" << endl;
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
