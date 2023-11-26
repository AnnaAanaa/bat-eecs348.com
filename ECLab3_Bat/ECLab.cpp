#include <iostream>
#include <iomanip>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    void displayDetails() const {
        std::cout << "Account Details for " << getAccountType() << " (ID: " << accountNumber << "):" << std::endl;
        std::cout << "   Holder: " << accountHolder << std::endl;
        std::cout << "   Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }

    virtual std::string getAccountType() const {
        return "Generic Account";
    }

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. $" << amount << " withdrawn." << std::endl;
        } else {
            std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
        }
    }

    friend Account operator+(const Account& lhs, const Account& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

Account operator+(const Account& lhs, const Account& rhs) {
    Account result("T000", "Transfer", 0);
    result.balance = lhs.balance + rhs.balance;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account Details after transfer:" << std::endl;
    os << account.getAccountType() << " (ID: " << account.accountNumber << "):" << std::endl;
    os << "   Holder: " << account.accountHolder << std::endl;
    os << "   Balance: $" << std::fixed << std::setprecision(2) << account.balance << std::endl;
    return os;
}

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate)
        : Account(number, holder, initialBalance), interestRate(rate) {}

    std::string getAccountType() const override {
        return "Savings Account";
    }

    void deposit(double amount) override {
        balance += amount + (amount * interestRate);
    }

    void withdraw(double amount) override {
        const double minBalance = 100; // Minimum balance for savings account
        if (balance - amount >= minBalance) {
            balance -= amount;
            std::cout << "Withdrawal successful. $" << amount << " withdrawn." << std::endl;
        } else {
            std::cout << "Insufficient funds or below minimum balance. Withdrawal failed." << std::endl;
        }
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
        : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    std::string getAccountType() const override {
        return "Current Account";
    }

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            std::cout << "Withdrawal successful. $" << amount << " withdrawn." << std::endl;
        } else {
            std::cout << "Insufficient funds or exceeding overdraft limit. Withdrawal failed." << std::endl;
        }
    }
};

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    savings.displayDetails();
    current.displayDetails();

    // Transfer $300 from savings to current
    Account transferResult = savings + current;

    std::cout << transferResult;

    return 0;
}
