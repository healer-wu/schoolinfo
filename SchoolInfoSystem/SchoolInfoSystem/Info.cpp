#include "Info.h"

Info::Info()
{
	this->address.setProvince("湖南省");
	this->address.setCity("株洲市");
	this->address.setRegion("天元区");
	this->phoneNumber = "13399998888";
	this->identifyNumber = "无";
}

Info::Info(const Info& tmp)
{
	address = tmp.address;
	phoneNumber = tmp.phoneNumber;
	identifyNumber = tmp.identifyNumber;
	name = tmp.name;
}

Info::Info(Address address, string  phone, string num, string name)
{
	this->address.setProvince(address.getProvince());
	this->address.setCity(address.getCity());
	this->address.setRegion(address.getRegion());
	this->phoneNumber = phone;
	this->identifyNumber = num;
	this->name = name;
}

Info::Info(string province, string  city, string region, string phone, string num, string name)
{
	this->address.setProvince(province);
	this->address.setCity(city);
	this->address.setRegion(region);
	this->phoneNumber = phone;
	this->identifyNumber = num;
	this->name = name;
}

Info::~Info()
{
	//无
}

 
Address Info::getAddress()
{
	return this->address;
}

string Info::getAddressStr()
{
	return this->address.getProvince() + this->address.getCity() + this->address.getRegion();
}

string Info::getPhoneNumber()
{
	return phoneNumber;
}

string Info::getIdentifyNumber()
{
	return identifyNumber;
}

string Info::getName()
{
	return this->name;
}

string Info::getProvince()
{
	return address.getCity();
}

string Info::getCity()
{
	return address.getCity();
}

string Info::getRegion()
{
	return address.getRegion();
}

bool Info::setAddress(  Address  address)
{
	this->address.setProvince(address.getProvince());
	this->address.setCity(address.getCity());
	this->address.setRegion(address.getRegion());
	return true;
}

bool Info::setAddressStr(  string  province,   string  city,   string  region)
{
	this->address.setProvince(province);
	this->address.setCity(province);
	this->address.setRegion(region);
	return true;
}

bool Info::setPhoneNumber(  string  number)
{
	this->phoneNumber = number;
	return true;
}

bool Info::setIdentifyNumber(  string  number)
{
	this->identifyNumber = number;
	return true;
}

bool Info::setName(  string  name)
{
	this->name = name;
	return true;
}

bool Info::setProvince(string pro)
{
	address.setProvince(pro);
	return true;
}

bool Info::setCity(string city)
{
	address.setCity(city);
	return true;
}

bool Info::setRegion(string re)
{
	address.setRegion(re);
	return true;
}

void Info::printInfo()
{
	cout << "名字 ：" << this->name << this->getAddressStr() << endl << " 电话：" << this->phoneNumber << " 身份号 ：" << this->identifyNumber  << endl;
}

Address::Address(const Address& tmp)
{
	province = tmp.province;
	city = tmp.city;
	region = tmp.region;
}
