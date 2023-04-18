#include "Decorator.h"
#include "ChainOfResponsibility.h"
#include "ObjectPool.h"

int main(int argc, char* argv[])
{
    //Object pool patterm
    srand(time(NULL));
    Shelf SomeShelf;
    auto TShirt = SomeShelf.GetTShirt();
    std::cout << TShirt->GetFirm() << " " << TShirt->GetSize() << std::endl;
    SomeShelf.Clean(TShirt);
    
    //Decorator design pattern
    Pizza* SomePizza = new MargheritaPizza();
    std::cout << SomePizza->GetDescription() << " costs $" << SomePizza->GetPrice() << std::endl;

    SomePizza = new ExtraCheese(SomePizza, 3);
    std::cout << SomePizza->GetDescription() << " costs $" << SomePizza->GetPrice() << std::endl;
    std::cout << std::endl << std::endl;

    //Chain of responsibility design pattern
    ATM SomeATM(200, 400, 700);
    SomeATM.GiveMoney(275);
    return 0;
}
