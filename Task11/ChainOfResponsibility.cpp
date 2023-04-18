#include "ChainOfResponsibility.h"
#include <iostream>

ATM::ATM()
{
    OneHundredDollars* HundredDollarBills = new OneHundredDollars();
    TenDollars* TenDollarsBills = new TenDollars();
    OneDollar* OneDollarBills = new OneDollar();
    SomeMoney.Add(HundredDollarBills);
    SomeMoney.Add(TenDollarsBills);
    SomeMoney.Add(OneDollarBills);
}

ATM::ATM(int NumberOfHundredDollarBills, int NumberOfTenDollarBills, int NumberOfOneDollarBills)
{
    OneHundredDollars* HundredDollarBills = new OneHundredDollars(NumberOfHundredDollarBills);
    TenDollars* TenDollarsBills = new TenDollars(NumberOfTenDollarBills);
    OneDollar* OneDollarBills = new OneDollar(NumberOfOneDollarBills);
    SomeMoney.Add(HundredDollarBills);
    SomeMoney.Add(TenDollarsBills);
    SomeMoney.Add(OneDollarBills);
}

void ATM::GiveMoney(int AmountOfMoney)
{
    SomeMoney.Handle(AmountOfMoney);
}

Money::Money()
{
    Next = 0;
}

void Money::SetNext(Money* InNext)
{
    Next = InNext;
}

void Money::Add(Money* InNext)
{
    if(Next)
    {
        Next->Add(InNext);
    }
    else
    {
        Next = InNext;
    }
}

void Money::Handle(int i)
{
    Next->Handle(i);
}

OneHundredDollars::OneHundredDollars() : AmountOfBills(100)
{}

OneHundredDollars::OneHundredDollars(int InAmountOfBills) : AmountOfBills(InAmountOfBills)
{}

void OneHundredDollars::Handle(int i)
{
    int NumberOfBills = i / 100;
    i = i % 100;
    if((NumberOfBills > 0) && (NumberOfBills <= AmountOfBills))
    {
        AmountOfBills -= NumberOfBills;
        std::cout << NumberOfBills << " one hundred dollars bills were dispensed" << std::endl;
    }
    else if((NumberOfBills > 0) && (NumberOfBills > AmountOfBills))
    {
        std::cout << AmountOfBills << " one hundred dollars bills were dispensed" << std::endl;
        NumberOfBills -= AmountOfBills;
        AmountOfBills = 0;
        i = i + (NumberOfBills * 100);
    }
    if(i > 0)
    {
        Money::Handle(i);
    }
}

TenDollars::TenDollars() : AmountOfBills(100)
{}

TenDollars::TenDollars(int InAmountOfBills) : AmountOfBills(InAmountOfBills)
{}

void TenDollars::Handle(int i)
{
    int NumberOfBills = i / 10;
    i = i % 10;
    if((NumberOfBills > 0) && (NumberOfBills <= AmountOfBills))
    {
        AmountOfBills -= NumberOfBills;
        std::cout << NumberOfBills << " ten dollars bills were dispensed" << std::endl;
    }
    else if((NumberOfBills > 0) && (NumberOfBills > AmountOfBills))
    {
        std::cout << AmountOfBills << " ten dollars bills were dispensed" << std::endl;
        NumberOfBills -= AmountOfBills;
        AmountOfBills = 0;
        i = i + (NumberOfBills * 10);
    }
    if(i > 0)
    {
        Money::Handle(i);
    }
}

OneDollar::OneDollar() : AmountOfBills(100)
{}

OneDollar::OneDollar(int InAmountOfBills) : AmountOfBills(InAmountOfBills)
{}

void OneDollar::Handle(int i)
{
    if(AmountOfBills >= i)
    {
        std::cout << i << " one dollars bills were dispensed" << std::endl;
    }
    else
    {
        std::cout << "There isn't enough money in ATM" << std::endl;
    }
}