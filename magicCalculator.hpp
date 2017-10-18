#pragma once
#include <vector>

#define INVALID_NUMBER 0

enum diagEnum
{
    BACKSLASH,
    SLASH
};

class Puzzle
{
public:
    Puzzle();
    void fillBoxWith(std::set<int> availableNumbers);
    void display() const;
    std::vector<int> box;
    bool checkBox() const;
    int foundCount;
    int triedCount;
    void setup();
    std::set<int> numbers;

private:
    bool checkRow(int idx) const;
    bool checkCol(int idx) const;
    bool checkDiag(diagEnum orientation) const;
    bool done;
};
