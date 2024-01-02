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
		// 删掉了课程代码, 开课状态, 考核方式, 上课起始周,  课程性质, 教学班名称
	public:
		int id;
		string CourseTypeName = "无"; //  课程名称
		double credits = 0;			  // 学分
		string TeacherName = "无";
		string ClassTime = "无";	  // 上课时间
		string ClassLocation = "无";  // 上课地点
		string JointClassInfo = "无"; // 合班信息
		string ClassCollege = "无";	  // 开课学院
		string SchoolYear = "无";	  // 学年
		int Semester = 1;			  // 学期
		string Comment = "_";		  // 评价
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

