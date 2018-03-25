#include <iostream>
#include <set>
#include "magicCalculator.hpp"
#include <iomanip>
#include "Puzzle.hpp"

using std::cout;
using std::endl;

int main()
{
    Puzzle puzzle = Puzzle();

    std::set<int> numbers;
    for (int i = 1; i <= BOX_SIZE * BOX_SIZE; i++)
    {
        numbers.insert(i);
    }

    puzzle.fillBoxWith(numbers);
    cout << "Tried " << puzzle.triedCount << " combinations" << endl;
    cout << "Found " << puzzle.foundCount << " solutions" << endl;

    return 0;
}
