#pragma once

class Money
{
public:
    Money();
    void SetNext(Money* InNext);
    void Add(Money* InNext);
    virtual void Handle(int i);
private:
    Money* Next;
};

class OneHundredDollars : public Money
{
public:
    OneHundredDollars();
    explicit OneHundredDollars(int InAmountOfBills);
    void Handle(int i) override;
private:
    int AmountOfBills;
};

class TenDollars : public Money
{
public:
    TenDollars();
    explicit TenDollars(int InAmountOfBills);
    void Handle(int i) override;
private:
    int AmountOfBills;
};

class OneDollar : public Money
{
public:
    OneDollar();
    explicit OneDollar(int InAmountOfBills);
    void Handle(int i) override;
private:
    int AmountOfBills;
};

class ATM
{
public:
    ATM();
    ATM(int NumberOfHundredDollarBills, int NumberOfTenDollarBills, int NumberOfOneDollarBills);
    
    void GiveMoney(int AmountOfMoney);
private:
    Money SomeMoney;
};