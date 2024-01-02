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
	cout << "****** �γ�����&���� ******" << endl;
	cout << "���������ʼ����" << endl;
	getch();

	// ����ѧ��
	for (i = 2023; i >= 2005; i--)
	{
		string option = to_string(i) + " - " + to_string(i + 1) + " ";
		Y.push_back(option);
	}

	ifstream f1("�α�.txt");
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
		cout << "�γ����ݶ�ʧ~-������-~  ����ϵ������Ա (�����`) " << endl;
		return;
	}

	// ���ؿ���ѧԺ`
	College.push_back("�羰԰���뽨��ѧԺ");
	College.push_back("�ִ�ũѧԺ");
	College.push_back("��ҵ�����＼��ѧԺ");
	College.push_back("��������ԴѧԺ��̼�к�ѧԺ");
	College.push_back("��ѧ����Ϲ���ѧԺ");
	College.push_back("���ù���ѧԺ");
	College.push_back("�ķ�ѧԺ�������ѧԺ��");
	College.push_back("����Ƽ�ѧԺ������ҽѧԺ");
	College.push_back("���˼����ѧԺ");
	College.push_back("�������ѧԺ");
	College.push_back("����繤��ѧԺ");
	College.push_back("����ѧԺ�����´�ҵѧԺ��");
	College.push_back("���ʽ���ѧԺ������ѧԺ��");
	College.push_back("������ѵ��");
	College.push_back("ʳƷ�뽡��ѧԺ���ִ���ʳ��ҵѧԺ��");
	College.push_back("԰�տ�ѧѧԺ");
	College.push_back("��ѧ����Ļ�ѧԺ");
	College.push_back("���ѧԺ");

	Screen();
	Bye();

}

void StudentUI ::Screen()
{
	bool flag = 1;

	while (1)
	{
		system("cls");

		cout << "  ��ѯ��ʽ  " << endl;
		cout << "    	Tips: ��������п�ͨ������ [ -1 ]�ķ�ʽ�˳�Ŷ ~" << endl;

		// ��ӡѧ����б�ѡ��
		SchoolYear = ""; 
		cout << "* ѧ��" << endl;
		for (i = 0; i < Y.size(); i++)
			cout << "\t[" << setw(4) << i + 1 << " ]   " << Y[i] << endl;
		while (cin >> option)
		{
			if (option >= 1 && option <= Y.size())
			{
				SchoolYear = Y[option - 1];
				cout << "ѡ��ѧ��: " << SchoolYear << endl
				     << endl;
				break;
			}
			else if (option == -1)
			{
	
				flag = 0;
				break;
			}
			else
				cout << "ѡ������~  ������ѡ�� ��(�R�ڨQ)��";
		}
		if (flag == 0)
			break;

		// ѧ��
		cout << "* ѧ��" << endl;
		cout << "\t[1] 1" << endl;
		cout << "\t[2] 2" << endl;
		while (cin >> option)
		{
			if (option == 1 || option == 2)
			{
				Semester = to_string(option);
				semester = option;
				cout << "��ѡ��ѧ��: " << Semester << endl;
				break;
			}
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "ѡ������~  ������ѡ�� ��(�R�ڨQ)��";
		}
		if (flag == 0)
			break;
		cout << endl;

		// �γ�
		cout << "�Ƿ����� {�γ�����}  [0]���� [1]����γ�" << endl;
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
				cout << "���ڷ�ΧŶ (�ѩn��), �������ֶ�����" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// ����ѧԺ
		cout << "�Ƿ����� {����ѧԺ}  [0]���� [1]ѡ�񿪿�ѧԺ" << endl;
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
				cout << "���ڷ�ΧŶ (�ѩn��), �������ֶ�����" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// ��ʦ
		cout << "�Ƿ�ѡ�� {��ʦ} [0]���� [1]������ʦ����" << endl;
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
				cout << "���ڷ�ΧŶ (�ѩn��), �������ֶ�����" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// ��ʼ����
		const int all_block_num = 100;
		cout << "���ڲ���, �ȿ�ˮ��Ϣһ������������~   ��*��-��*��" << endl;
		for (i = 0; i < all_block_num; i++)
		{
			printf("\r[%d%%]>", i * 100 / (all_block_num - 1));
			for (j = 10; j <= i * 20 / all_block_num; j++)
			{
				cout << "��";
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

	cout << "���ҽ��" << endl;
	cout << "	��Բ�ѯ������������ڹ���ʱ����ѯ����ʦ: 17816139241" << endl;

	if (AfterFilter.size() == 0)
	{
		cout << "************************************************ " << endl;
		cout << "****    û�з���������¼!    ��(�R�ڨQ)��   ****" << endl;
		cout << "************************************************ " << endl;
		cout << "				�����������  " << endl;
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
			cout << "****---  Ҫ���۵Ŀγ�  ---****           o(��'��'��)o" << endl;
			cout << "    		 \tTips: 1. ��������[ -1 ] ����ɸѡҳ��Ŷ~  " << endl;
			cout << " 				2. ������Ϻ󰴻س��ύ " << endl;
			cout << "				3. ������Ϻ������޸�, ��ͬѧ����������" << endl;
			cout << "				4. ��;�����˳��ᵼ�������޷�����, �ǵü�ʱ�ύ��|��O��|�� �~~" << endl;
			cin >> option;
			if (option == -1)
				break;

			string Input = "";
			bool flag = true;
			if (option <= 0 || option > AfterFilter.size())
			{
				cout << "��Χ������Ŷ~  �����������ѡ��" << endl;
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
						cout << "ȷ��Ҫ�ύ��? [0]: ȡ��  [1]: ȷ��" << endl;
						cin >> whetherExit;
						if (whetherExit == 1)
						{
							flag = false;
							AfterFilter[temp].Comment += Input + "_";
							Course[index].Comment += Input + "_";

							break;
						}
					}
					if (c == '\b') // ɾ����
					{
						if (Input.length() == 0)
							continue;
						Input.pop_back();
						Input.pop_back();
						//	Input.pop_back();
					}
				}
				cout << "���ڱ��� ing~   n(*�R���Q*)n" << endl;
				Sleep(1000);
				ofstream FileSave("�α�.txt", ios::out);
				if (FileSave.is_open())
				{
					for (i = 0; i < Course.size(); i++)
						FileSave << Course[i].id << "  " << Course[i].CourseTypeName << "  " << Course[i].credits << " " << Course[i].TeacherName << "  " << Course[i].ClassTime << "  " << Course[i].ClassLocation << "  " << Course[i].ClassCollege << " " << Course[i].JointClassInfo << "  " << Course[i].SchoolYear << "  " << Course[i].Semester << " " << Course[i].Comment << endl;
					FileSave.close();
					cout << "�ѳɹ�����" << endl;
				}
				else
					cout << "�ļ���ʧ��" << endl;
				cout << endl;
				cout << "****	����������� �t(*�㨌��*)�s ****" << endl;
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
	cout << " �ڴ����´�ʹ�� (*��3��)�q" << endl;
}

void TeacherUI::Welcome()
{
	int option;
	cout << "****** �γ��������� ******" << endl;
	cout << "     ���������ʼ����" << endl;
	getch();

	// ����ѧ��
	for (i = 2023; i >= 2005; i--)
	{
		string option = to_string(i) + " - " + to_string(i + 1) + " ";
		Y.push_back(option);
	}

	ifstream f1("�α�.txt");
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
		cout << "�γ����ݶ�ʧ~-������-~  ����ϵ������Ա (�����`) " << endl;
		return;
	}

	// ���ؿ���ѧԺ`
	College.push_back("�羰԰���뽨��ѧԺ");
	College.push_back("�ִ�ũѧԺ");
	College.push_back("��ҵ�����＼��ѧԺ");
	College.push_back("��������ԴѧԺ��̼�к�ѧԺ");
	College.push_back("��ѧ����Ϲ���ѧԺ");
	College.push_back("���ù���ѧԺ");
	College.push_back("�ķ�ѧԺ�������ѧԺ��");
	College.push_back("����Ƽ�ѧԺ������ҽѧԺ");
	College.push_back("���˼����ѧԺ");
	College.push_back("�������ѧԺ");
	College.push_back("����繤��ѧԺ");
	College.push_back("����ѧԺ�����´�ҵѧԺ��");
	College.push_back("���ʽ���ѧԺ������ѧԺ��");
	College.push_back("������ѵ��");
	College.push_back("ʳƷ�뽡��ѧԺ���ִ���ʳ��ҵѧԺ��");
	College.push_back("԰�տ�ѧѧԺ");
	College.push_back("��ѧ����Ļ�ѧԺ");
	College.push_back("���ѧԺ");

	bool flag = 1;

	while (1)
	{
		system("cls");

		cout << "  ��ѯ��ʽ  " << endl;
		cout << "    	Tips: ��������п�ͨ������ [ -1 ]�ķ�ʽ�˳�Ŷ ~" << endl;

		// ��ӡѧ����б�ѡ��
		cout << "* ѧ��" << endl;
		for (i = 0; i < Y.size(); i++)
			cout << "\t[" << setw(4) << i + 1 << " ]   " << Y[i] << endl;
		while (cin >> option)
		{
			if (option >= 1 && option <= Y.size())
			{
				SchoolYear = Y[option - 1];
				cout << "ѡ��ѧ��: " << SchoolYear << endl
				     << endl;
				break;
			}
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "ѡ������~  ������ѡ�� ��(�R�ڨQ)��" << endl;
		}
		if (flag == 0)
			break;

		// ѧ��
		cout << "* ѧ��" << endl;
		cout << "\t[1] 1" << endl;
		cout << "\t[2] 2" << endl;
		while (cin >> option)
		{
			if (option == 1 || option == 2)
			{
				Semester = to_string(option);
				semester = option;
				cout << "��ѡ��ѧ��: " << Semester << endl;
				break;
			}
			else if (option == -1)
			{
				flag = 0;
				break;
			}
			else
				cout << "ѡ������~  ������ѡ�� ��(�R�ڨQ)��";
		}
		if (flag == 0)
			break;
		cout << endl;

		// �γ�
		cout << "�Ƿ����� {�γ�����}  [0]���� [1]����γ�" << endl;
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
				cout << "���ڷ�ΧŶ (�ѩn��), �������ֶ�����" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// ����ѧԺ
		cout << "�Ƿ����� {����ѧԺ}  [0]���� [1]ѡ�񿪿�ѧԺ" << endl;
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
				cout << "���ڷ�ΧŶ (�ѩn��), �������ֶ�����" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// ��ʦ
		cout << "�Ƿ�ѡ�� {��ʦ} [0]���� [1]������ʦ����" << endl;
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
				cout << "���ڷ�ΧŶ (�ѩn��), �������ֶ�����" << endl;
		}
		if (flag == 0)
			break;
		cout << endl;

		// ��ʼ����
		const int all_block_num = 100;
		cout << "���ڲ���, �ȿ�ˮ��Ϣһ������������~   ��*��-��*��" << endl;
		for (i = 0; i < all_block_num; i++)
		{
			printf("\r[%d%%]>", i * 100 / (all_block_num - 1));
			for (j = 10; j <= i * 20 / all_block_num; j++)
			{
				cout << "��";
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
	cout << " �ڴ����´�ʹ�� (*��3��)�q" << endl;
}
void TeacherUI ::Add()
{
	int option;
	CourseType C;

	cout << "���������ӿγ̵���Ϣ  (^^*)" << endl;
	cout << "[0] ȷ��		" << endl;
	cout << "[1] �γ�����	";
	cout << "[2] ѧ��    	";
	cout << "[3] ��ʦ���� 	" << endl;
	cout << "[4] �Ͽ�ʱ��   ";
	cout << "[5] �Ͽεص�  	";
	cout << "[6] �ϰ���Ϣ	" << endl;
	cout << "[7] ����ѧԺ   ";
	cout << "[8] ѧ��  	";
	cout << "[9] ѧ�� 		" << endl;

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
				cout << "���ڷ�ΧŶ~ ����ѡ���  ����� 3���" << endl;
				break;
		}
		C.id = Course.size() + 1;
	}
	AfterFilter.push_back(C);
	Course.push_back(C);

	// �洢�ļ�
	ofstream SaveFile("�α�.txt", ios::out);
	cout << "���ڱ��� ing~   n(*�R���Q*)n" << endl;
	Sleep(1000);
	ofstream FileSave("�α�.txt", ios::out);
	if (FileSave.is_open())
	{
		for (i = 0; i < Course.size(); i++)
			FileSave << Course[i].id << "  " << Course[i].CourseTypeName << "  " << Course[i].credits << " " << Course[i].TeacherName << "  " << Course[i].ClassTime << "  " << Course[i].ClassLocation << "  " << Course[i].ClassCollege << " " << Course[i].JointClassInfo << "  " << Course[i].SchoolYear << "  " << Course[i].Semester << " " << Course[i].Comment << endl;
		FileSave.close();
		cout << "�ѳɹ�����" << endl;
	}
	else
		cout << "�ļ���ʧ��" << endl;
	cout << endl;
	cout << "****	����������� �t(*�㨌��*)�s ****" << endl;
	getch();
}

void TeacherUI ::Delete()
{
	int option2;
	cout << "Ҫɾ���Ŀγ���" << endl;
	cout << "		���� [-1] ���Է���Ŷ~    ()" << endl;
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

			// �洢�ļ�
			ofstream SaveFile("�α�.txt");
			cout << "���ڱ��� ing~   n(*�R���Q*)n" << endl;
			Sleep(1000);
			ofstream FileSave("�α�.txt", ios::out);
			if (FileSave.is_open())
			{
				for (i = 0; i < Course.size(); i++)
					FileSave << Course[i].id << "  " << Course[i].CourseTypeName << "  " << Course[i].credits << " " << Course[i].TeacherName << "  " << Course[i].ClassTime << "  " << Course[i].ClassLocation << "  " << Course[i].ClassCollege << " " << Course[i].JointClassInfo << "  " << Course[i].SchoolYear << "  " << Course[i].Semester << " " << Course[i].Comment << endl;
				FileSave.close();
				cout << "�ѳɹ�����" << endl;
			}
			else
				cout << "�ļ���ʧ��" << endl;
			break;
		}
		else if (option2 == -1)
			break;
		else
		{
			cout << "��Χ������Ŷ~  ����ѡ��" << endl;
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
		cout << "*****  ���ҽ��  *****" << endl;
		for (i = 0; i < AfterFilter.size(); i++)
		{
			cout << setw(5) << " [ " << i + 1 << " ]   ";
			AfterFilter[i].Show();
		}

		cout << endl
		     << "������� [0]���� [1]����һ�ſ� [2]�޳�һ�ſ�" << endl;
		cin >> option1;
		if (option1 == 0)
			break;
		else if (option1 == 1)
			Add();
		else if (option1 == 2)
			Delete();
		else
		{
			cout << "ѡ������~  �����������ѡ�� ��(�R�ڨQ)��" << endl;
			getch();
			system("cls");
		}
	}
}
