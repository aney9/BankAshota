#include <Windows.h>
#pragma execution_character_set("utf-8")
#include <iostream>
using namespace std;
class BankAccount {
private:
    int accountNumber;
    double balance;
    double ProcentStavk;

    double calcInterest() const {
        return balance * ProcentStavk * (1.0 / 12);
    }

public:

    BankAccount(int accNumber, double initialBalance, double Percent)
        : accountNumber(accNumber), balance(initialBalance), ProcentStavk(Percent) {}


    void deposit(double summ) {
        balance += summ;
    }


    void withdraw(double summ) {
        if (balance >= summ) {
            balance -= summ;
        }
        else {
            cout << "Ошыбка: Нету средства" << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    double getInterest() const {
        return calcInterest();
    }

    void setInterestRate(double newRate) {
        this->ProcentStavk = newRate;
    }

    int getAccountNumber() const {
        return this->accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.withdraw(amount);
        to.deposit(amount);
        return true;
    }
    else {
        cout << "Ошыбка: Учыс шитат" << endl;
        return false;
    }
}

int main()
{
    SetConsoleCP(65001); // устанавливаем кодировку входящего потока данных на UTF-8
    SetConsoleOutputCP(65001); // устанавливаем кодировку исходящего потока данных на UTF-8
    double balanceAcc1, balanceAcc2;
    int acc1, acc2;
    double interestRate{};
    cout << "БАНК АШОТА";
    cout << "Введы номер щета для первого акка: ";
    while (!(cin >> acc1) || acc1 <= 0) {
        cout << "Ошыбка: Введы число, которое какнибуд больше 0" << endl;
        cout << "Введы номер счета для первого акка: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "Введы нашальный баланс для первого акка: $";
    while (!(cin >> balanceAcc1) || balanceAcc1 < 0) {
        cout << "Ошыбка: Введы число, которое какнибуд больше 0" << endl;
        cout << "Введы нашальный баланс для первого акка: $";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Введы номер щета для второго акка: ";
    while (!(cin >> acc2) || acc2 <= 0 || acc2 == acc1) {
        cout << "Ошыбка: Введы число, которое какнибуд больше 0" << endl;
        cout << "Введите номер счета для второго акка: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "Введы нашальный баланс для второго акка: $";
    while (!(cin >> balanceAcc2) || balanceAcc2 < 0) {
        cout << "Введы число, которое какнибуд больше 0" << endl;
        cout << "Введы нашальный баланс для второго акка: $";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    BankAccount account1(acc1, balanceAcc1, interestRate);
    BankAccount account2(acc2, balanceAcc2, interestRate);

    cout << "Нашальный баланс в акке 1: $" << account1.getBalance() << endl;
    cout << "Нашальный баланс в акке 2: $" << account2.getBalance() << endl;

    double transferAmount;
    cout << "Введите сумму перевода: $";
    while (!(cin >> transferAmount) || transferAmount <= 0) {
        cout << "Введы число, которое какнибуд больше 0" << endl;
        cout << "Введы сумму перевода: $";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Введы процентную ставку: ";
    while (!(cin >> interestRate) || interestRate < 0) {
        cout << "Введы число, которое какнибуд больше 0" << endl;
        cout << "Введы процентную ставку: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (transfer(account1, account2, transferAmount)) {
        cout << "Перевод сдэлан" << endl;
    }

    cout << "Конечный баланс в акке 1: $" << account1.getBalance() << endl;
    cout << "Конечный баланс в акке 2: $" << account2.getBalance() << endl;

    account1.setInterestRate(interestRate);
    account2.setInterestRate(interestRate);

    cout << "Проценты на акке 1: $" << account1.getInterest() << endl;
    cout << "Проценты на акке 2: $" << account2.getInterest() << endl;

    return 0;
}


