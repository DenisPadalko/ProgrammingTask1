#pragma once
#include <iostream>
#include <vector>

class TShirts
{
public:
    TShirts(const std::string& InFirm, int InSize);
    std::string GetFirm() const;
    int GetSize() const;
private:
    std::string Firm;
    int Size;
};

class Shelf
{
public:
    Shelf();

    TShirts* GetTShirt();
    void Clean(TShirts* SomeTShirt);
private:
    std::vector<TShirts*> CleanTShirts;
    std::vector<TShirts*> DirtyTShirts;
};
