#include "Decorator.h"

std::string MargheritaPizza::GetDescription()
{
    return "Margherita pizza";
}

double MargheritaPizza::GetPrice()
{
    return 10.0;
}

std::string FourSeasonsPizza::GetDescription()
{
    return "Four seasons pizza";
}

double FourSeasonsPizza::GetPrice()
{
    return 12.0;
}

ToppingDecorator::ToppingDecorator(Pizza* InPizza) : SomePizza(InPizza)
{}

double ToppingDecorator::GetPrice()
{
    return SomePizza->GetPrice();
}

std::string ToppingDecorator::GetDescription()
{
    return SomePizza->GetDescription();
}

ExtraCheese::ExtraCheese(Pizza* InPizza) : ToppingDecorator(InPizza)
{}

double ExtraCheese::GetPrice()
{
    return SomePizza->GetPrice() + 3.0;
}

std::string ExtraCheese::GetDescription()
{
    return SomePizza->GetDescription() + ", with extra cheese";
}

ExtraMeat::ExtraMeat(Pizza* InPizza) : ToppingDecorator(InPizza)
{}

double ExtraMeat::GetPrice()
{
    return SomePizza->GetPrice() + 4.0;
}

std::string ExtraMeat::GetDescription()
{
    return SomePizza->GetDescription() + ", with extra meat";
}