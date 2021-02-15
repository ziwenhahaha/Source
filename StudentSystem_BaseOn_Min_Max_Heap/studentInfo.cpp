#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<cstring>
#include "studentInfo.h"
#pragma warning(disable:4996)
using namespace std;

	char* student::getName() {
		return name;
	}
	char* student::getTelephone() {
		return telephone;
	}
	char* student::getStudentId() {
		return studentID;
	}
	char* student::getBirthDate() {
		return birthDate;
	}
	char* student::getBirthPlace() {
		return birthPlace;
	}
	char* student::getGender() {
		return gender;
	}
	int student::getGrade() {
		return grade;
	}

	void student::setName(char* x_name) {
		strcpy(name, x_name);
	}
	void student::setTelephone(char* x_telephone) {
		strcpy(telephone, x_telephone);
		//telephone = x_telephone;
	}
	void student::setStudentId(char* x_studentID) {
		strcpy(studentID, x_studentID);
		//studentID = x_studentID;
	}
	void student::setBirthDate(char* x_birthDate) {
		strcpy(birthDate, x_birthDate);
	}
	void student::setBirthPlace(char* x_birthPlace) {
		strcpy(birthPlace, x_birthPlace);
	}
	void student::setGender(char* x_Gender) {
		strcpy(gender, x_Gender);
	}
	void student::setGrade(int x_grade) {
		grade = x_grade;
	}

const student& student::operator=(const student& s) {
	if (this != &s) {
		strcpy(this->birthDate, s.birthDate);
		strcpy(this->birthPlace, s.birthPlace);
		strcpy(this->gender, s.gender);
		//strcpy(this->grade, s.birthDate);
		strcpy(this->name, s.name);
		strcpy(this->studentID, s.studentID);
		strcpy(this->telephone, s.telephone);
		this->grade = s.grade;
	}
	return *this;
}

const student& student::operator=(const int s) {
	this->grade = s;
	return *this;
}

bool operator<(const student& s1, const student& s2) {
	return s1.grade < s2.grade;
}
using namespace std;
bool operator==( student& s1,  student& s2) {
	char cc[100];
	char dd[100];
	return strcmp(s1.getName(),s2.getName())==0 && s1.getGrade()==s2.getGrade();

}

void student::read() 
{
	char name[100];
	char telephone[12];
	char studentID[20];
	char birthDate[20];
	char birthPlace[100];
	char gender[6];
	int grade;
	//cout << "input real part and imaginary part of complex number:";
	std::cin >> name >> telephone >> studentID >> birthDate >> birthPlace >> gender >> grade;
	this->setName(name);
	this->setTelephone(telephone);
	this->setStudentId(studentID);
	this->setBirthDate(birthDate);
	this->setBirthPlace(birthPlace);
	this->setGender(gender);
	this->setGrade(grade);
}
void student::write() {
	std::cout << getName() << " "
		<< getTelephone() << " "
		<< getStudentId() << " "
		<< getBirthDate() << " "
		<< getBirthPlace() << " "
		<< getGender() << " "
		<< getGrade() << std::endl;
}