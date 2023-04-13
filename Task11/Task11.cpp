#include "Decorator.h"
#include "ChainOfResponsibility.h"

int main(int argc, char* argv[])
{
    //Decorator design pattern
    Pizza* SomePizza = new MargheritaPizza();
    std::cout << SomePizza->GetDescription() << " costs $" << SomePizza->GetPrice() << std::endl;

    SomePizza = new ExtraCheese(SomePizza);
    std::cout << SomePizza->GetDescription() << " costs $" << SomePizza->GetPrice() << std::endl;
    std::cout << std::endl << std::endl;

    //Chain of responsibility design pattern
    ATM SomeATM(200, 400, 700);
    SomeATM.GiveMoney(275);
    return 0;
}
