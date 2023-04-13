#include "ObjectPool.h"

TShirts::TShirts(const std::string& InFirm, int InSize) : Firm(InFirm), Size(InSize)
{}

std::string TShirts::GetFirm() const
{
    return Firm;
}

int TShirts::GetSize() const
{
    return Size;
}

Shelf::Shelf()
{
    std::string TempFirm;
    int TempSize;
    int TempNumberOfLetters;
    for(int i = 0; i < 10; ++i)
    {
        TempFirm = "";
        TempNumberOfLetters = rand() % 10 + 1;
        for(int j = 0; j < TempNumberOfLetters; ++j)
        {
            TempFirm += 'a' + rand()%26;
        }
        TempSize = 1 + rand() % 5;
        CleanTShirts.push_back(new TShirts(TempFirm, TempSize));
    }
}

TShirts* Shelf::GetTShirt()
{
    if(CleanTShirts.empty())
    {
        return nullptr;
    }
    auto TShirt = CleanTShirts.back();
    CleanTShirts.pop_back();
    DirtyTShirts.push_back(TShirt);
    return TShirt;
}

void Shelf::Clean(TShirts* SomeTShirt)
{
    auto TShirt = std::find(DirtyTShirts.begin(), DirtyTShirts.end(), SomeTShirt);
    DirtyTShirts.erase(TShirt);
    CleanTShirts.push_back(SomeTShirt);
}
