#include <vector>
#include <set>

#define BOX_SIZE 3
#define MAGIC_NUMBER 15

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

private:
    bool checkRowOk(int idx) const;
    bool checkCol(int idx) const;
    bool checkDiag(diagEnum orientation) const;
};