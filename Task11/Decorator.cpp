#include "Decorator.h"

Pizza::Pizza() : Price(7)
{}

Pizza::Pizza(int InPrice) : Price(InPrice)
{}

double Pizza::GetPrice()
{
    return Price;
}

MargheritaPizza::MargheritaPizza()
{
    Price = 10;
}

MargheritaPizza::MargheritaPizza(int InPrice)
{
    Price = InPrice;
}

std::string MargheritaPizza::GetDescription()
{
    return "Margherita pizza";
}

FourSeasonsPizza::FourSeasonsPizza()
{
    Price = 12;
}

FourSeasonsPizza::FourSeasonsPizza(int InPrice)
{
    Price = InPrice;
}

std::string FourSeasonsPizza::GetDescription()
{
    return "Four seasons pizza";
}

ToppingDecorator::ToppingDecorator(Pizza* InPizza, int InPriceOfTopping) : SomePizza(InPizza), PriceOfTopping(InPriceOfTopping)
{}

double ToppingDecorator::GetPrice()
{
    return SomePizza->GetPrice() + PriceOfTopping;
}

std::string ToppingDecorator::GetDescription()
{
    return SomePizza->GetDescription();
}

ExtraCheese::ExtraCheese(Pizza* InPizza, int InPriceOfTopping) : ToppingDecorator(InPizza, InPriceOfTopping)
{}

std::string ExtraCheese::GetDescription()
{
    return SomePizza->GetDescription() + ", with extra cheese";
}

ExtraMeat::ExtraMeat(Pizza* InPizza, int InPriceOfTopping) : ToppingDecorator(InPizza, InPriceOfTopping)
{}

std::string ExtraMeat::GetDescription()
{
    return SomePizza->GetDescription() + ", with extra meat";
}