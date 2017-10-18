#include <iostream>
#include <set>
#include "magicCalculator.hpp"
#include <iomanip>

#define BOX_SIZE 3
#define MAGIC_NUMBER 15
using std::cout;
using std::endl;

int main()
{

    Puzzle puzzle = Puzzle();
    puzzle.setup();

    // Recursively
    puzzle.fillBoxWith(puzzle.numbers);
    cout << "Tried " << puzzle.triedCount << " combinations" << endl;
    cout << "Found " << puzzle.foundCount << " solutions" << endl;

    return 0;
}

void Puzzle::setup()
{
    for (int i = 1; i <= BOX_SIZE * BOX_SIZE; i++)
    {
        numbers.insert(i);
    }
}

Puzzle::Puzzle() : done(false), foundCount(0), triedCount(0)
{
    box = std::vector<int>(BOX_SIZE * BOX_SIZE);
}

void Puzzle::fillBoxWith(std::set<int> availableNumbers)
{
    if (availableNumbers.empty())
    {
        triedCount++;
        if (checkBox())
        {
            foundCount++;
            display();
            return;
        }
    }

    int occupiedCount = BOX_SIZE * BOX_SIZE - availableNumbers.size();

    for (const int number : availableNumbers)
    {
        box[occupiedCount] = number;

        std::set<int> remainingNumbers(availableNumbers);
        remainingNumbers.erase(number);

        fillBoxWith(remainingNumbers);
        if (done)
        {
            return;
        }

        box[occupiedCount] = 0;
        remainingNumbers.insert(number);
    }
}

void Puzzle::display() const
{
    std::string bar(BOX_SIZE * 2 + BOX_SIZE - 1, '_');
    cout << bar << endl;
    for (int i = 0; i < BOX_SIZE; i++)
    {
        for (int j = 0; j < BOX_SIZE; j++)
        {
            cout << std::setfill(' ') << std::setw(2) << box[i * BOX_SIZE + j] << " ";
        }
        cout << endl;
    }
}

bool Puzzle::checkBox() const
{
    bool isMagic = true;

    for (int i = 0; i < BOX_SIZE; i++)
    {
        isMagic *= checkRow(i);
        isMagic *= checkCol(i);

    }
    isMagic *= checkDiag(SLASH);
    isMagic *= checkDiag(BACKSLASH);

    return isMagic;
}

bool Puzzle::checkCol(int idx) const
{
    int sum = 0;
    for (int i = 0; i < BOX_SIZE; i++)
    {
        sum += box[idx + i * BOX_SIZE];
    }
    return sum == MAGIC_NUMBER;
}

bool Puzzle::checkRow(int idx) const
{
    int sum = 0;
    for (int i = 0; i < BOX_SIZE; i++)
    {
        sum += box[idx * BOX_SIZE + i];
    }
    return sum == MAGIC_NUMBER;
}

bool Puzzle::checkDiag(diagEnum order) const
{
    int sum = 0;
    switch (order)
    {
        case SLASH:
        //cout << "slash" << endl;
            for (int i = 0; i < BOX_SIZE; i++)
            {
                sum += box[BOX_SIZE - 1 + BOX_SIZE * i - i];
                //cout << box[BOX_SIZE - 1 + BOX_SIZE * i - i] << endl;
            }
            //cout << "slash sum: " << sum << endl;
            break;
        case BACKSLASH:
            //cout << "backslash" << endl;
            for (int i = 0; i < BOX_SIZE; i++)
            {
                sum += box[i * BOX_SIZE + i];
                //cout << box[i * BOX_SIZE + i] << endl;
            }
            //cout << "backslash sum: " << sum << endl;
            break;
        default:
            //cout << "invalid diag enum";
            exit(1);
    }

    return sum == MAGIC_NUMBER;
}
