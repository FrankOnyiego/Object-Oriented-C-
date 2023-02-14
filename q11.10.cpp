#include <iostream>

class Account {
 public:
  Account(double balance) : balance_(balance) {}
  virtual void credit(double amount) { balance_ += amount; }
  virtual void debit(double amount) {
    if (amount > balance_) {
      std::cout << "Debit amount exceeded account balance." << std::endl;
    } else {
      balance_ -= amount;
    }
  }
  double getBalance() const { return balance_; }

 private:
  double balance_;
};

class SavingsAccount : public Account {
 public:
  SavingsAccount(double balance, double interest_rate)
      : Account(balance), interest_rate_(interest_rate) {}
  double calculateInterest() {
    return interest_rate_ * getBalance() / 100;
  }

 private:
  double interest_rate_;
};

class CheckingAccount : public Account {
 public:
  CheckingAccount(double balance, double transaction_fee)
      : Account(balance), transaction_fee_(transaction_fee) {}
  virtual void credit(double amount) {
    Account::credit(amount - transaction_fee_);
  }
  virtual void debit(double amount) {
    Account::debit(amount + transaction_fee_);
  }

 private:
  double transaction_fee_;
};

int main() {
  SavingsAccount savings(1000, 2);
  CheckingAccount checking(500, 1);

  savings.credit(100);
  savings.debit(50);
  std::cout << "Savings balance: " << savings.getBalance() << std::endl;

  checking.credit(100);
  checking.debit(50);
  std::cout << "Checking balance: " << checking.getBalance() << std::endl;

  double interest = savings.calculateInterest();
  savings.credit(interest);
  std::cout << "Savings balance after adding interest: " << savings.getBalance()
            << std::endl;

  return 0;
}

