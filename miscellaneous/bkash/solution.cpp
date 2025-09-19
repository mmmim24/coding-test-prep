#include <bits/stdc++.h>

using namespace std;

class Transaction
{
protected:
    double amount;
    string transactionId;
    string dateTime;

    string generateTransactionId()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(100000, 999999);
        return "TX" + to_string(dis(gen));
    }

    string getCurrentDateTime()
    {
        time_t now = time(nullptr);
        tm *localTime = localtime(&now);
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        return string(buffer);
    }

public:
    Transaction(double amt) : amount(amt), transactionId(generateTransactionId()), dateTime(getCurrentDateTime()) {}
    virtual ~Transaction() = default;
    virtual void execute(double &balance) = 0;
    virtual void display() const = 0;
    bool verifyOtp(const string &inputOtp)
    {
        string otp = "1234"; // Simulated OTP for simplicity
        return inputOtp == otp;
    }
};

class CashIn : public Transaction
{
private:
    string accountNumber;

public:
    CashIn(double amt, string receiver) : Transaction(amt), accountNumber(receiver) {}

    void execute(double &balance) override
    {
        string otp;
        cout << "Enter OTP for Cash In: ";
        cin >> otp;
        if (verifyOtp(otp))
        {
            balance += amount;
            cout << "Cash In successful!" << endl;
            display();
            cout << "Current Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid OTP! Transaction failed." << endl;
        }
    }

    void display() const override
    {
        cout << "Cash In Amount: " << amount << ", Transaction ID: " << transactionId
             << ", Date/Time: " << dateTime << endl;
    }
};

class CashOut : public Transaction
{
private:
    string agentNumber;

public:
    CashOut(double amt, string agent) : Transaction(amt), agentNumber(agent) {}

    void execute(double &balance) override
    {
        string otp;
        cout << "Enter OTP for Cash Out: ";
        cin >> otp;
        if (!verifyOtp(otp))
        {
            cout << "Invalid OTP! Transaction failed." << endl;
            return;
        }
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Cash Out successful!" << endl;
            display();
            cout << "Current Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() const override
    {
        cout << "Cash Out Amount: " << amount << ", Agent Number: " << agentNumber
             << ", Transaction ID: " << transactionId << ", Date/Time: " << dateTime << endl;
    }
};

class SendMoney : public Transaction
{
private:
    string receiverNumber;

public:
    SendMoney(double amt, string receiver) : Transaction(amt), receiverNumber(receiver) {}

    void execute(double &balance) override
    {
        string otp;
        cout << "Enter OTP for Send Money: ";
        cin >> otp;
        if (!verifyOtp(otp))
        {
            cout << "Invalid OTP! Transaction failed." << endl;
            return;
        }
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Send Money successful!" << endl;
            display();
            cout << "Current Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() const override
    {
        cout << "Send Money Amount: " << amount << ", Receiver Number: " << receiverNumber
             << ", Transaction ID: " << transactionId << ", Date/Time: " << dateTime << endl;
    }
};

class Account
{
private:
    string name;
    string phoneNumber;
    double balance; // Private to prevent direct access (Q5)

public:
    Account(string n, string pn, double initialBalance) : name(n), phoneNumber(pn), balance(initialBalance) {}

    // Q1: display for printing object properties
    string display() const
    {
        return "Name: " + name + ", Phone Number: " + phoneNumber + ", Balance: " + to_string(balance);
    }

    // Q5: Access balance only through methods
    double getBalance() const { return balance; }

    void performTransaction(Transaction *transaction)
    {
        transaction->execute(balance);
    }
};
// Explanation of bKash System Requirements

// Q1: The display method in the Account class prints all properties (name, phone number, balance).
// Q2: The SendMoney class outputs the amount, receiver number, date/time, transaction ID, and current balance after a successful transaction.
// Q3: The CashOut class mirrors the SendMoney format, including agent number instead of receiver number.
// Q4: OTP logic is simulated by requiring a hardcoded OTP ("1234") for each transaction. In a real system, OTPs would be generated and verified via an external service.
// Q5: The balance is private, accessible only via getBalance() and modified only through transaction methods (execute in derived classes).

// This implementation uses inheritance for transactions, encapsulation for balance security, and polymorphism for transaction execution, adhering to OOP principles.
int main()
{
    Account account("Hasina Akter Chowdhury", "01908774721", 10000.0);
    cout << account.display() << endl;

    double amount;
    cout << "Enter amount to Cash In: ";
    cin >> amount;
    CashIn cashIn(amount, "01908774721");
    account.performTransaction(&cashIn);

    cout << "Enter amount to Send Money: ";
    cin >> amount;
    SendMoney sendMoney(amount, "01716349899");
    account.performTransaction(&sendMoney);

    cout << "Enter amount to Cash Out: ";
    cin >> amount;
    CashOut cashOut(amount, "01755945867");
    account.performTransaction(&cashOut);

    cout << account.display() << endl;

    return 0;
}