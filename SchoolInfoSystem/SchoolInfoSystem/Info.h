#pragma once
#include "function.h"
#include "PrintInfo.h"
class Address
{
private:
	string province;//ʡ
	string city;//��
	string region;//��
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
	Address address;//��ַ
	string phoneNumber;//�绰
	string identifyNumber;//��ݺ�
	string name;

public:
	Info();//�޲ι��캯��
	Info(const Info& tmp);
	Info(Address address, string  phone, string num, string name);//�вι��캯��
	Info(string province, string  city, string region, string phone, string num, string name);
	~Info();//��������
	//getϵ�к���
	Address getAddress();//��ȡ��ַ�ṹ��
	string getAddressStr();//��ȡ��ַ�ַ���
	string getPhoneNumber();//��ȡ�绰����
	string getIdentifyNumber();//��ȡ��ݺ�
	string getName();
	string getProvince();
	string getCity();
	string getRegion();
	//setϵ�к���
	bool setAddress(Address address);//���õ�ַ�ṹ��
	bool setAddressStr(string province, string city, string region);//���õ�ַ�ַ���
	bool setPhoneNumber(string number);//���õ绰����
	bool setIdentifyNumber(string number);//���ù���
	bool setName(string name);
	bool setProvince(string pro);
	bool setCity(string city);
	bool setRegion(string re);
	void printInfo();
};

