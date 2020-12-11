#include <iostream>
#include <string>
using namespace std;

class ICustomer
{
public:
	virtual void Discount(string data) = 0;
};

class PrivilegedCustomer : public ICustomer
{
public:
	void Discount(string data)
	{
		cout << data << "40% " << endl;
	}
};

class OrdinaryCustomer : public ICustomer
{
public:
	void Discount(string data)
	{
		cout << data << "10% " << endl;
	}
};

class ISeason
{
public:
	virtual void Percentage(string data) = 0;
};

class Spring : public ISeason
{
public:
	void Percentage(string data)
	{
		cout << data << "12% " << endl;
	}
};

class Winter : public ISeason
{
public:
	void Percentage(string data)
	{
		cout << data << "15% " << endl;
	}
};

class IEvent
{
public:
	virtual void Gift(string data) = 0;
};

class Christmas : public IEvent
{
public:
	void Gift(string data)
	{
		cout << data << "50% " << endl;
	}
};

class Easter : public IEvent
{
public:
	void Gift(string data)
	{
		cout << data << "30% " << endl;
	}
};


class AbstractFactory
{
public:
	virtual ICustomer* getDiscount(string type) = 0;
	virtual ISeason* getPercentage(string type) = 0;
	virtual IEvent* getGift(string type) = 0;
};

class DeviceAbstractFactory : public AbstractFactory
{
public:
	ICustomer* getDiscount(string type)
	{
		if (type == "PrivilegedCustomer")
		{
			return new PrivilegedCustomer;
		}
		else if (type == "OrdinaryCustomer")
		{
			return new OrdinaryCustomer;
		}
	}

public:
	ISeason* getPercentage(string type)
	{
		if (type == "Spring")
		{
			return new Spring;
		}
		else if (type == "Winter")
		{
			return new Winter;
		}
	}

public:
	IEvent* getGift(string type)
	{
		if (type == "Christmas")
		{
			return new Christmas;
		}
		else if (type == "Easter")
		{
			return new Easter;
		}
	}

};

// Main Usage
int main()
{
	AbstractFactory* abstractFactory = new DeviceAbstractFactory;
	ICustomer* customer;
	customer = abstractFactory->getDiscount("PrivilegedCustomer");
	customer->Discount("Your Discount Is: ");

	ISeason* season;
	season = abstractFactory->getPercentage("Spring");
	season->Percentage("Your Percentage Is: ");

	IEvent* event;
	event = abstractFactory->getGift("Christmas");
	event->Gift("Your Gift Is: ");


}
