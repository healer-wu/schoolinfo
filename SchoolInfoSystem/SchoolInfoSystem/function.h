#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#define sleep Sleep(2000);
using namespace std;




//��������
int main();
void menu();
void entryInfo();
void searchInfo();
void deleteInfo();
void modifyInfo();
void studentList();
void teacherList();
void getHutInfo();
void printStar(int num,string s);
void printStars(int n, string s);
void setRed();
void setBlue();
void setGreen();
void setPurple();
void setYellow();
void setCyan();
void setDefault();
void setColor(int num);
void subMenuSearch();
void subMenuDel();
void subMenuModify();
void headInfo();
//����
void nameSearch();
void phoneSearch();
void idSearch();
void majorSearch();
//ɾ��
void nameSearchAndDel();
void phoneSearchAndDel();
void idSearchAndDel();
void majorSearchAndDel();
//�޸�
void nameSearchAndModify();
void phoneSearchAndModify();
void idSearchAndModify();
void majorSearchAndModify();