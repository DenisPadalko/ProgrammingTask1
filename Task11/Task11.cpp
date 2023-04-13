#include "Decorator.h"

int main(int argc, char* argv[])
{
    //Decorator design pattern
    Pizza* SomePizza = new MargheritaPizza();
    std::cout << SomePizza->GetDescription() << " costs $" << SomePizza->GetPrice() << std::endl;

    SomePizza = new ExtraCheese(SomePizza);
    std::cout << SomePizza->GetDescription() << " costs $" << SomePizza->GetPrice() << std::endl;

    return 0;
}
