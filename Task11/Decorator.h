#pragma once
#include <iostream>

class Pizza
{
public:
    Pizza();
    Pizza(int InPrice);
    virtual ~Pizza() = default;
    virtual double GetPrice();
    virtual std::string GetDescription() = 0;
protected:
    int Price;
};

class MargheritaPizza : public Pizza
{
public:
    MargheritaPizza();
    explicit MargheritaPizza(int InPrice);
    std::string GetDescription() override;
};

class FourSeasonsPizza : public Pizza
{
public:
    FourSeasonsPizza();
    explicit FourSeasonsPizza(int InPrice);
    std::string GetDescription() override;
};

class ToppingDecorator : public Pizza
{
public:
    ToppingDecorator(Pizza* InPizza, int InPriceOfTopping);
    double GetPrice() override;
    std::string GetDescription() override;
protected:
    Pizza* SomePizza;
    int PriceOfTopping;
};

class ExtraCheese : public ToppingDecorator
{
public:
    ExtraCheese(Pizza* InPizza, int InPriceOfTopping);
    std::string GetDescription() override;
};

class ExtraMeat : public ToppingDecorator
{
public:
    ExtraMeat(Pizza* InPizza, int InPriceOfTopping);
    std::string GetDescription() override;
};