#ifndef COMMENT_H
#define COMMENT_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <map>
using namespace std;

class CourseType
{
		// ɾ���˿γ̴���, ����״̬, ���˷�ʽ, �Ͽ���ʼ��,  �γ�����, ��ѧ������
	public:
		int id;
		string CourseTypeName = "��"; //  �γ�����
		double credits = 0;			  // ѧ��
		string TeacherName = "��";
		string ClassTime = "��";	  // �Ͽ�ʱ��
		string ClassLocation = "��";  // �Ͽεص�
		string JointClassInfo = "��"; // �ϰ���Ϣ
		string ClassCollege = "��";	  // ����ѧԺ
		string SchoolYear = "��";	  // ѧ��
		int Semester = 1;			  // ѧ��
		string Comment = "_";		  // ����
		CourseType() {}
		~CourseType() {}
		void Show();
		bool operator==(const CourseType &a);
};

class StudentUI
{
	public:
		vector<CourseType> Course;
		vector<string> Y;
		vector<string> College;
		vector<CourseType> AfterFilter;
		int option, i, j, semester;
		string SchoolYear, Semester, ClassTypeName = "", TeacherName = "", ClassCollege = "";
		CourseType *it;
		bool operator==(CourseType &A)
		{
			string a = "", b = "";
			a = it->CourseTypeName + it->TeacherName + it->ClassTime + it->ClassLocation + it->JointClassInfo + it->ClassCollege + it->SchoolYear;

			b = A.CourseTypeName + A.TeacherName + A.ClassTime + A.ClassLocation + A.JointClassInfo + A.ClassCollege + A.SchoolYear;

			if (a == b)
				return true;
			return false;
		}
		int choice;
		void Welcome();
		void Screen();
		void MakeComment();
		void Bye();
};

class TeacherUI
{
	public:
		vector<CourseType> Course;
		vector<string> Y;
		vector<string> College;
		vector<CourseType> AfterFilter;
		int option, i, j, semester, choice;
		string SchoolYear, Semester, ClassTypeName = "", TeacherName = "", ClassCollege = "";

		void Welcome();
		void Operate();
		void Add();
		void Delete();
};


#endif

