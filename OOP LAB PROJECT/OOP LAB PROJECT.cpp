#include<iostream>
#include<string>
using namespace std;


class Account
{
protected:
	string account_title;
	int serial_number;
	int account_number;
	double balance;
public:
	void getdata()
	{
		cout << "Enter the Details:\n Name,Serial,Account number,Balance:" << endl;
		cin >> account_title;
		cin >> serial_number;
		cin >> account_number;
		cin >> balance;
	}

	virtual void credit(double amount)
	{
		balance = balance + amount;
		cout << "Credit balance: Rs. " << balance << endl;
	}
	virtual void debit(double amount)
	{
		if (balance >= amount)
		{
			balance -= amount;
			cout << " Debit balance: Rs." << balance << endl;
		}
		else
		{
			cout << "Insufficient balance in account " << endl;
		}
	}
	virtual void calculate_intrest() = 0;
	void display()
	{
		cout << "************ Account Details **********" << endl;
		cout << "Title:" << account_title << endl << "Serial number:" << serial_number << endl << "Account number:" << account_number << endl << "Balance: Rs." << balance << endl;
	}
};

class Plus :public Account
{
private:
	int intrest_rate=25;
	int intrest;
public:
	void getdata()
	{
		Account::getdata();
	}
	void calculate_intrest()
	{
		intrest = balance * intrest_rate/100;
		balance = balance + intrest;
		cout << "Intrest: Rs." << intrest << endl << "Balance with Intrest: Rs." << balance << endl;
	}
};

class Freedom :public Account
{
	
private:
	double trasaction_fee;
	int Intrest;
	
	void getdata()
		{
			Account::getdata();	
		}
		void credit(int amount)
		{
			balance = balance + amount;
			balance = balance  - trasaction_fee;
			cout << "Balance after Trasaction: Rs." << balance << endl;
		}
		void calculate_intrest()
		{
			balance = balance + Intrest;
			cout << "Balance after Intrest: Rs." << balance << endl;
		}
	
};

int main()
{
	Account* a[10];
	int n = 0, choice = 0;
	double trasaction_fee;
	int Intrest;
	do {
			cout << "Choose 1 for Plus Account and 2 for Freedom Account" << endl;
			cin >> choice;
			if (choice = 1)
			{
				a[n] = new Plus;
				a[n]->getdata();
				a[n]->display();
			}

			else if (choice = 2)
			{
				a[n] = new Freedom;
				a[n]->getdata();
				a[n]->display();
			}

			n++;
			cout << endl;
		} while (n < 1);
		cout << "Enter Trasaction and Amount of Intrest: Rs." << endl;
		cin >> Intrest >> trasaction_fee;
		a[0]->credit(1500);
		a[0]->debit(1000);
		a[0]->calculate_intrest();
	    system("pause");
	    return 0;
}