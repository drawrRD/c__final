#include "Comment.h"


void CourseType::Show()
{
	cout << CourseTypeName << "  ";
	cout << credits << " ";
	cout << TeacherName << "  ";
	cout << ClassTime << "  ";
	cout << ClassLocation << "  ";
	cout << JointClassInfo << "  ";
	cout << ClassCollege << " ";
	cout << SchoolYear << "  ";
	cout << Semester << "  ";
	cout << Comment << "  ";
	cout << endl;
}

bool CourseType::operator==(const CourseType &other)
{
	return (CourseTypeName == other.CourseTypeName &&
	        credits == other.credits &&
	        TeacherName == other.TeacherName &&
	        ClassTime == other.ClassTime &&
	        ClassLocation == other.ClassLocation &&
	        JointClassInfo == other.JointClassInfo &&
	        ClassCollege == other.ClassCollege &&
	        SchoolYear == other.SchoolYear &&
	        Semester == other.Semester);
}

void StudentUI ::Welcome()
{
	int i;
	cout << "****** 课程评价&讨论 ******" << endl;
	cout << "按任意键开始操作" << endl;
	getch();

	// 加载学年
	for (i = 2023; i >= 2005; i--)
	{
		string option = to_string(i) + " - " + to_string(i + 1) + " ";
		Y.push_back(option);
	}

	ifstream f1("课表.txt");
	if (f1.is_open())
	{
		CourseType C;
		while (f1 >> C.id >> C.CourseTypeName >> C.credits >> C.TeacherName >> C.ClassTime >> C.ClassLocation >> C.ClassCollege >> C.JointClassInfo >> C.SchoolYear >> C.Semester >> C.Comment)
		{
			C.Comment += "_";
			Course.push_back(C);
		}
		f1.close();
	}
	else
	{
		cout << "课程数据丢失~-呜呜呜-~  请联系工作人员 (；′⌒`) " << endl;
		return;
	}

	// 加载开课学院`
	College.push_back("风景园林与建筑学院");
	College.push_back("现代农学院");
	College.push_back("林业与生物技术学院");
	College.push_back("环境与资源学院、碳中和学院");
	College.push_back("化学与材料工程学院");
	College.push_back("经济管理学院");
	College.push_back("文法学院（外国语学院）");
	College.push_back("动物科技学院、动物医学院");
	College.push_back("马克思主义学院");
	College.push_back("艺术设计学院");
	College.push_back("光机电工程学院");
	College.push_back("集贤学院（创新创业学院）");
	College.push_back("国际教育学院（孔子学院）");
	College.push_back("体育军训部");
	College.push_back("食品与健康学院（现代粮食产业学院）");
	College.push_back("园艺科学学院");
	College.push_back("茶学与茶文化学院");
	College.push_back("村官学院");

	Screen();
	Bye();

}

void StudentUI ::Screen()
{
	bool flag = 1;

	while (1)
	{
		system("cls");

		cout << "  查询方式  " << endl;
		cout << "    	Tips: 输入过程中可通过输入 [ -1 ]的方式退出哦 ~" << endl;

		// 打印学年的列表选项
		SchoolYear = ""; 
		cout << "* 学年" << endl;
		for (i = 0; i < Y.size(); i++)
			cout << "\t[" << setw(4) << i + 1 << " ]   " << Y[i] << endl;
		while (cin >> option)
		{
			if (option >= 1 && option <= Y.size())
			{
				SchoolYear = Y[option - 1];
				cout << "选择学年: " << SchoolYear << endl
				     << endl;
				break;
			}
			else if (option == -1)
			{
	
				flag = 0;
				break;
			}
			else
				cout << "选择错误嗷~  请重新选择 Ｏ(≧口≦)Ｏ";
		}
		if (flag == 0)
			break;

		// 学期
		cout << "* 学期" << endl;
		cout << "\t[1] 1" << endl;
		cout << "\t[2] 2" << endl;
		while (cin >> option)
		{
			if (option == 1 || option == 2)
			{
				Semester = to_string(option);
				semester = option;
				cout << "已选择学期: " << Semester << endl;
				break;
			}
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "选择错误嗷~  请重新选择 Ｏ(≧口≦)Ｏ";
		}
		if (flag == 0)
			break;
		cout << endl;

		// 课程
		cout << "是否输入 {课程名称}  [0]跳过 [1]输入课程" << endl;
		while (cin >> option)
		{
			if (option == 1)
			{
				cin >> ClassTypeName;
				break;
			}
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else if (option == 0)
				break;
			else
				cout << "不在范围哦 (⊙﹏⊙), 看下是手抖了吗" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// 开课学院
		cout << "是否输入 {开课学院}  [0]跳过 [1]选择开课学院" << endl;
		while (cin >> option)
		{
			if (option == 1)
			{
				for (i = 0; i < College.size(); i++)
					cout << "\t[ " << setw(4) << i + 1 << " ]  " << College[i] << endl;
				cin >> choice;
				ClassCollege = College[choice - 1];
				break;
			}
			else if (option == 0)
				break;
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "不在范围哦 (⊙﹏⊙), 看下是手抖了吗" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// 教师
		cout << "是否选择 {教师} [0]跳过 [1]输入老师姓名" << endl;
		while (cin >> option)
		{
			if (option == 1)
			{
				cin >> TeacherName;
				break;
			}
			else if (option == 0)
				break;
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "不在范围哦 (⊙﹏⊙), 看下是手抖了吗" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// 开始查找
		const int all_block_num = 100;
		cout << "正在查找, 喝口水休息一下再来看看吧~   （*＾-＾*）" << endl;
		for (i = 0; i < all_block_num; i++)
		{
			printf("\r[%d%%]>", i * 100 / (all_block_num - 1));
			for (j = 10; j <= i * 20 / all_block_num; j++)
			{
				cout << "▉";
				Sleep(10);
			}
		}
		cout << endl;

		AfterFilter.clear();
		for (i = 0; i < Course.size(); i++)
		{
			//if (Course[i].SchoolYear.find(SchoolYear) && Course[i].Semester == semester)
			if (Course[i].SchoolYear == SchoolYear) 
				if (Course[i].Semester == semester)
					if (ClassTypeName.empty() || Course[i].CourseTypeName.find(ClassTypeName) != -1)
						if (ClassCollege.empty() || Course[i].ClassCollege.find(ClassCollege) != -1)
							if (TeacherName.empty() || Course[i].TeacherName.find(TeacherName) != -1)
								AfterFilter.push_back(Course[i]);
		}
		MakeComment();
	}
}

void StudentUI::MakeComment()
{
	int option, whetherExit;
	char c;

	cout << "查找结果" << endl;
	cout << "	如对查询结果有疑问请在工作时间咨询韩老师: 17816139241" << endl;

	if (AfterFilter.size() == 0)
	{
		cout << "************************************************ " << endl;
		cout << "****    没有符合条件记录!    Ｏ(≧口≦)Ｏ   ****" << endl;
		cout << "************************************************ " << endl;
		cout << "				按任意键继续  " << endl;
		getch();
	}
	else
		while (1)
		{
			system("cls");
			for (i = 0; i < AfterFilter.size(); i++)
			{
				cout << setw(5) << " [ " << i + 1 << " ]   ";
				AfterFilter[i].Show();
			}
			cout << endl
			     << "*****************************" << endl;
			cout << "****---  要评价的课程  ---****           o(〃'▽'〃)o" << endl;
			cout << "    		 \tTips: 1. 可以输入[ -1 ] 返回筛选页面哦~  " << endl;
			cout << " 				2. 输入完毕后按回车提交 " << endl;
			cout << "				3. 输入完毕后不允许修改, 请同学们妥善评价" << endl;
			cout << "				4. 中途意外退出会导致评价无法保存, 记得及时提交┗|｀O′|┛ 嗷~~" << endl;
			cin >> option;
			if (option == -1)
				break;

			string Input = "";
			bool flag = true;
			if (option <= 0 || option > AfterFilter.size())
			{
				cout << "范围错误了哦~  按任意键重新选择" << endl;
				getch();
			}
			else
			{
				int temp = option - 1;
				int index = AfterFilter[temp].id;
				while (1)
				{
					c = getch();
					Input += c;
					if (c == 13)
					{
						cout << "确认要提交吗? [0]: 取消  [1]: 确定" << endl;
						cin >> whetherExit;
						if (whetherExit == 1)
						{
							flag = false;
							AfterFilter[temp].Comment += Input + "_";
							Course[index].Comment += Input + "_";

							break;
						}
					}
					if (c == '\b') // 删除键
					{
						if (Input.length() == 0)
							continue;
						Input.pop_back();
						Input.pop_back();
						//	Input.pop_back();
					}
				}
				cout << "正在保存 ing~   n(*≧▽≦*)n" << endl;
				Sleep(1000);
				ofstream FileSave("课表.txt", ios::out);
				if (FileSave.is_open())
				{
					for (i = 0; i < Course.size(); i++)
						FileSave << Course[i].id << "  " << Course[i].CourseTypeName << "  " << Course[i].credits << " " << Course[i].TeacherName << "  " << Course[i].ClassTime << "  " << Course[i].ClassLocation << "  " << Course[i].ClassCollege << " " << Course[i].JointClassInfo << "  " << Course[i].SchoolYear << "  " << Course[i].Semester << " " << Course[i].Comment << endl;
					FileSave.close();
					cout << "已成功保存" << endl;
				}
				else
					cout << "文件打开失败" << endl;
				cout << endl;
				cout << "****	按任意键继续 ╰(*°▽°*)╯ ****" << endl;
				getch();
			}
		}
}

void StudentUI::Bye()
{
	cout << endl
	     << endl
	     << " ***************************" << endl
	     << endl;
	cout << " 期待您下次使用 (*￣3￣)╭" << endl;
}

void TeacherUI::Welcome()
{
	int option;
	cout << "****** 课程评价审视 ******" << endl;
	cout << "     按任意键开始操作" << endl;
	getch();

	// 加载学年
	for (i = 2023; i >= 2005; i--)
	{
		string option = to_string(i) + " - " + to_string(i + 1) + " ";
		Y.push_back(option);
	}

	ifstream f1("课表.txt");
	if (f1.is_open())
	{
		CourseType C;
		while (f1 >> C.id >> C.CourseTypeName >> C.credits >> C.TeacherName >> C.ClassTime >> C.ClassLocation >> C.ClassCollege >> C.JointClassInfo >> C.SchoolYear >> C.Semester >> C.Comment)
		{
			Course.push_back(C);
		}
		f1.close();
	}
	else
	{
		cout << "课程数据丢失~-呜呜呜-~  请联系工作人员 (；′⌒`) " << endl;
		return;
	}

	// 加载开课学院`
	College.push_back("风景园林与建筑学院");
	College.push_back("现代农学院");
	College.push_back("林业与生物技术学院");
	College.push_back("环境与资源学院、碳中和学院");
	College.push_back("化学与材料工程学院");
	College.push_back("经济管理学院");
	College.push_back("文法学院（外国语学院）");
	College.push_back("动物科技学院、动物医学院");
	College.push_back("马克思主义学院");
	College.push_back("艺术设计学院");
	College.push_back("光机电工程学院");
	College.push_back("集贤学院（创新创业学院）");
	College.push_back("国际教育学院（孔子学院）");
	College.push_back("体育军训部");
	College.push_back("食品与健康学院（现代粮食产业学院）");
	College.push_back("园艺科学学院");
	College.push_back("茶学与茶文化学院");
	College.push_back("村官学院");

	bool flag = 1;

	while (1)
	{
		system("cls");

		cout << "  查询方式  " << endl;
		cout << "    	Tips: 输入过程中可通过输入 [ -1 ]的方式退出哦 ~" << endl;

		// 打印学年的列表选项
		cout << "* 学年" << endl;
		for (i = 0; i < Y.size(); i++)
			cout << "\t[" << setw(4) << i + 1 << " ]   " << Y[i] << endl;
		while (cin >> option)
		{
			if (option >= 1 && option <= Y.size())
			{
				SchoolYear = Y[option - 1];
				cout << "选择学年: " << SchoolYear << endl
				     << endl;
				break;
			}
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "选择错误嗷~  请重新选择 Ｏ(≧口≦)Ｏ" << endl;
		}
		if (flag == 0)
			break;

		// 学期
		cout << "* 学期" << endl;
		cout << "\t[1] 1" << endl;
		cout << "\t[2] 2" << endl;
		while (cin >> option)
		{
			if (option == 1 || option == 2)
			{
				Semester = to_string(option);
				semester = option;
				cout << "已选择学期: " << Semester << endl;
				break;
			}
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "选择错误嗷~  请重新选择 Ｏ(≧口≦)Ｏ";
		}
		if (flag == 0)
			break;
		cout << endl;

		// 课程
		cout << "是否输入 {课程名称}  [0]跳过 [1]输入课程" << endl;
		while (cin >> option)
		{
			if (option == 1)
			{
				cin >> ClassTypeName;
				break;
			}
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else if (option == 0)
				break;
			else
				cout << "不在范围哦 (⊙﹏⊙), 看下是手抖了吗" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// 开课学院
		cout << "是否输入 {开课学院}  [0]跳过 [1]选择开课学院" << endl;
		while (cin >> option)
		{
			if (option == 1)
			{
				for (i = 0; i < College.size(); i++)
					cout << "\t[ " << setw(4) << i + 1 << " ]  " << College[i] << endl;
				cin >> choice;
				ClassCollege = College[choice - 1];
				break;
			}
			else if (option == 0)
				break;
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "不在范围哦 (⊙﹏⊙), 看下是手抖了吗" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// 教师
		cout << "是否选择 {教师} [0]跳过 [1]输入老师姓名" << endl;
		while (cin >> option)
		{
			if (option == 1)
			{
				cin >> TeacherName;
				break;
			}
			else if (option == 0)
				break;
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "不在范围哦 (⊙﹏⊙), 看下是手抖了吗" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// 开始查找
		const int all_block_num = 100;
		cout << "正在查找, 喝口水休息一下再来看看吧~   （*＾-＾*）" << endl;
		for (i = 0; i < all_block_num; i++)
		{
			printf("\r[%d%%]>", i * 100 / (all_block_num - 1));
			for (j = 10; j <= i * 20 / all_block_num; j++)
			{
				cout << "▉";
				Sleep(10);
			}
		}
		cout << endl;

		AfterFilter.clear();
		for (i = 0; i < Course.size(); i++)
		{
			if (Course[i].SchoolYear.find(SchoolYear) && Course[i].Semester == semester)
				if (ClassTypeName.empty() || Course[i].CourseTypeName.find(ClassTypeName) != -1)
					if (ClassCollege.empty() || Course[i].ClassCollege.find(ClassCollege) != -1)
						if (TeacherName.empty() || Course[i].TeacherName.find(TeacherName) != -1)
							AfterFilter.push_back(Course[i]);
		}
		Operate();
	}
	cout << endl
	     << endl
	     << " ***************************" << endl
	     << endl;
	cout << " 期待您下次使用 (*￣3￣)╭" << endl;
}
void TeacherUI ::Add()
{
	int option;
	CourseType C;

	cout << "请输入增加课程的信息  (^^*)" << endl;
	cout << "[0] 确认		" << endl;
	cout << "[1] 课程名称	";
	cout << "[2] 学分    	";
	cout << "[3] 教师名称 	" << endl;
	cout << "[4] 上课时间   ";
	cout << "[5] 上课地点  	";
	cout << "[6] 合班信息	" << endl;
	cout << "[7] 开课学院   ";
	cout << "[8] 学年  	";
	cout << "[9] 学期 		" << endl;

	while (1)
	{
		cin >> option;
		if (option == 0)
			break;
		switch (option)
		{
			case 1:
				cin >> C.CourseTypeName;
				break;
			case 2:
				cin >> C.credits;
				break;
			case 3:
				cin >> C.TeacherName;
				break;
			case 4:
				cin >> C.ClassTime;
				break;
			case 5:
				cin >> C.ClassLocation;
				break;
			case 6:
				cin >> C.JointClassInfo;
				break;
			case 7:
				cin >> C.ClassCollege;
				break;
			case 8:
				cin >> C.SchoolYear;
				break;
			case 9:
				cin >> C.Semester;
				break;
			default:
				cout << "不在范围哦~ 重新选择吧  （○｀ 3′○）" << endl;
				break;
		}
		C.id = Course.size() + 1;
	}
	AfterFilter.push_back(C);
	Course.push_back(C);

	// 存储文件
	ofstream SaveFile("课表.txt", ios::out);
	cout << "正在保存 ing~   n(*≧▽≦*)n" << endl;
	Sleep(1000);
	ofstream FileSave("课表.txt", ios::out);
	if (FileSave.is_open())
	{
		for (i = 0; i < Course.size(); i++)
			FileSave << Course[i].id << "  " << Course[i].CourseTypeName << "  " << Course[i].credits << " " << Course[i].TeacherName << "  " << Course[i].ClassTime << "  " << Course[i].ClassLocation << "  " << Course[i].ClassCollege << " " << Course[i].JointClassInfo << "  " << Course[i].SchoolYear << "  " << Course[i].Semester << " " << Course[i].Comment << endl;
		FileSave.close();
		cout << "已成功保存" << endl;
	}
	else
		cout << "文件打开失败" << endl;
	cout << endl;
	cout << "****	按任意键继续 ╰(*°▽°*)╯ ****" << endl;
	getch();
}

void TeacherUI ::Delete()
{
	int option2;
	cout << "要删除的课程是" << endl;
	cout << "		输入 [-1] 可以返回哦~    ()" << endl;
	while (cin >> option2)
	{
		if (option2 >= 1 && option2 <= AfterFilter.size())
		{

			for (auto it = Course.begin(); it != Course.end();)
			{
				if (it->id == AfterFilter[option2 - 1].id)
				{
					it = Course.erase(it);
					break;
				}
				else
					it++;
			}
			AfterFilter.erase(AfterFilter.begin() + option2 - 1);

			// 存储文件
			ofstream SaveFile("课表.txt");
			cout << "正在保存 ing~   n(*≧▽≦*)n" << endl;
			Sleep(1000);
			ofstream FileSave("课表.txt", ios::out);
			if (FileSave.is_open())
			{
				for (i = 0; i < Course.size(); i++)
					FileSave << Course[i].id << "  " << Course[i].CourseTypeName << "  " << Course[i].credits << " " << Course[i].TeacherName << "  " << Course[i].ClassTime << "  " << Course[i].ClassLocation << "  " << Course[i].ClassCollege << " " << Course[i].JointClassInfo << "  " << Course[i].SchoolYear << "  " << Course[i].Semester << " " << Course[i].Comment << endl;
				FileSave.close();
				cout << "已成功保存" << endl;
			}
			else
				cout << "文件打开失败" << endl;
			break;
		}
		else if (option2 == -1)
			break;
		else
		{
			cout << "范围错误了哦~  重新选择" << endl;
		}
		cout << endl;
	}
}

void TeacherUI ::Operate()
{
	int option1;
	while (1)
	{
		system("cls");
		cout << "*****  查找结果  *****" << endl;
		for (i = 0; i < AfterFilter.size(); i++)
		{
			cout << setw(5) << " [ " << i + 1 << " ]   ";
			AfterFilter[i].Show();
		}

		cout << endl
		     << "您想进行 [0]返回 [1]新增一门课 [2]剔除一门课" << endl;
		cin >> option1;
		if (option1 == 0)
			break;
		else if (option1 == 1)
			Add();
		else if (option1 == 2)
			Delete();
		else
		{
			cout << "选择错误嗷~  按任意键重新选择 Ｏ(≧口≦)Ｏ" << endl;
			getch();
			system("cls");
		}
	}
}
