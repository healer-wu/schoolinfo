#pragma once
#include "function.h"
#include "PrintInfo.h"
class Address
{
private:
	string province;//省
	string city;//市
	string region;//区
public:
	Address(){}
	Address(string pro, string ci, string re) : province(pro), city(ci), region(re) {}
	Address(const Address& tmp);
	string getProvince()  { return province; }
	string getCity()  { return city; }
	string getRegion()  { return region; }
	void setProvince(string pro) { province = pro; }
	void setCity(string ci) { city = ci; }
	void setRegion(string re) { region = re; }
};
class Info: PrintInfo
{
private:
	Address address;//地址
	string phoneNumber;//电话
	string identifyNumber;//身份号
	string name;

public:
	Info();//无参构造函数
	Info(const Info& tmp);
	Info(Address address, string  phone, string num, string name);//有参构造函数
	Info(string province, string  city, string region, string phone, string num, string name);
	~Info();//析构函数
	//get系列函数
	Address getAddress();//获取地址结构体
	string getAddressStr();//获取地址字符串
	string getPhoneNumber();//获取电话号码
	string getIdentifyNumber();//获取身份号
	string getName();
	string getProvince();
	string getCity();
	string getRegion();
	//set系列函数
	bool setAddress(Address address);//设置地址结构体
	bool setAddressStr(string province, string city, string region);//设置地址字符串
	bool setPhoneNumber(string number);//设置电话号码
	bool setIdentifyNumber(string number);//设置工号
	bool setName(string name);
	bool setProvince(string pro);
	bool setCity(string city);
	bool setRegion(string re);
	void printInfo();
};

