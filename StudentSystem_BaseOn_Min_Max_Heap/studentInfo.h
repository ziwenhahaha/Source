#pragma once
#include<string>
#include<fstream>
#pragma warning(disable:4996)
using namespace std;
class student {
	public:
		char* getName();
		char* getTelephone();
		char* getStudentId();
		char* getBirthDate();
		char* getBirthPlace();
		char* getGender();
		int getGrade();

		void read();
		void write();

		void setName(char* x_name);
		void setTelephone(char* x_telephone);
		void setStudentId(char* x_studentID);
		void setBirthDate(char* x_birthDate);
		void setBirthPlace(char* x_birthPlace);
		void setGender(char* x_Gender);
		void setGrade(int x_grade);
		friend bool operator<(const student& s1, const student& s2);
		const student& operator=(const student& s1);
		const student& operator=(int s);
		friend bool operator==( student& s1,  student& s2);
	private:
		char name[100];
		char telephone[12];
		char studentID[20];
		char birthDate[20];
		char birthPlace[100];
		char gender[6];
		int grade;
};
