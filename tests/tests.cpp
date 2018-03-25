#include "../src/Puzzle.cpp"
#include <gtest/gtest.h>

TEST(PuzzleTest, solves3x3)
{
    Puzzle puzzle = Puzzle();

    std::set<int> numbers;
    for (int i = 1; i <= BOX_SIZE * BOX_SIZE; i++)
    {
        numbers.insert(i);
    }
    puzzle.fillBoxWith(numbers);

    ASSERT_GE(puzzle.foundCount, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}