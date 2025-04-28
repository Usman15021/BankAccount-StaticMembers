#include <iostream>
using namespace std;

class BankAccount
{
private:
  string ownerName;
  double balance;

  /* static mean it is not tied to a specific object
  it belongs to the class itself, not individual */
  static int accountCount;
  static double totalBalance;

public: // this constructor  automatically intiallize an object when we create it.
  BankAccount(string name, double intialBalance)
  {
    ownerName = name;
    balance = intialBalance;
    accountCount++;
    totalBalance += intialBalance;
  }
  // destructor
  ~BankAccount() // this destructor automatically clen up an object is destroyed maintaing correct statistics.
  {
    accountCount--;
    totalBalance -= balance;
  }
  // Member function
  void deposit(double amount)
  {
    balance += amount;
    totalBalance += amount;
  }
  void withDraw(double amount)
  {
    if (amount <= balance)
    {
      balance -= amount;
      totalBalance -= amount;
    }
    else
    {
      cout << "Insufficient balance for " << ownerName << endl;
    }
  }
  // this const keyword promises not to change any values in the object

  void display() const
  {
    cout << "Owner: " << ownerName << ", Balance: $" << balance << endl;
  }

  /*  To allow users to see overall bank statics without touching any individual account
  we create static fuction*/
  static void showBankstats()
  {
    cout << "Bank statistics---" << endl;
    cout << "total Accounts: " << accountCount << endl;
    cout << "Total Balance: $ " << totalBalance << endl;
  }
};
/* Because static variables live outside individual objects,
we must initialize them separately:*/
// Initialize static member
int BankAccount::accountCount = 0;
double BankAccount::totalBalance = 0.0;

int main()
{
  BankAccount acc1("usman", 2000);
  BankAccount acc2("zubair", 3000);
  BankAccount acc3("imran", 4000);
  BankAccount acc4("amir", 5000);
  BankAccount acc5("nadeem", 6000);

  acc1.deposit(500);
  acc2.deposit(1000);
  acc4.withDraw(1500);

  acc1.display();
  acc2.display();
  acc3.display();
  acc4.display();
  acc5.display();
  return 0;
}