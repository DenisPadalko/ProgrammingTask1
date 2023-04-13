#pragma once
#include <iostream>

class Pizza
{
public:
    virtual ~Pizza() = default;
    virtual double GetPrice() = 0;
    virtual std::string GetDescription() = 0;
};

class MargheritaPizza : public Pizza
{
public:
    double GetPrice() override;
    std::string GetDescription() override;
};

class FourSeasonsPizza : public Pizza
{
public:
    double GetPrice() override;
    std::string GetDescription() override;
};

class ToppingDecorator : public Pizza
{
public:
    ToppingDecorator(Pizza* InPizza);
    double GetPrice() override;
    std::string GetDescription() override;
protected:
    Pizza* SomePizza;
};

class ExtraCheese : public ToppingDecorator
{
public:
    ExtraCheese(Pizza* InPizza);
    double GetPrice() override;
    std::string GetDescription() override;
};

class ExtraMeat : public ToppingDecorator
{
public:
    ExtraMeat(Pizza* InPizza);
    double GetPrice() override;
    std::string GetDescription() override;
};