#include <iostream>

int main()
{
  int square = 0;
  int squareRoot = 2;
  int beforeSquareRoot = squareRoot;
  int previousNum = 1;

  std::cout << "Enter a number(preferably a perfect square): ";
  std::cin >> square;

  if (square == 0 || square == 1)
  {
    std::cout << "Your number inputted is " << square << " , and " << square << " is the square of itself, so your answer is " << square << "!\n";
    abort();
  }

  while (true)
  {
    if (squareRoot % 1000 == 0)
    {
      std::cout << ".";
    }
    if (squareRoot % 10000 == 0)
    {
      std::cout << "This may take some time";
    }

    for (int i = 1; i < beforeSquareRoot; i++)
    {
      squareRoot += beforeSquareRoot;
    }

    if (squareRoot == square)
    {
      squareRoot = beforeSquareRoot;
      break;
    }
    else if (squareRoot > square)
    {
      squareRoot = beforeSquareRoot;

      std::cout << "\nYour number must not be a perfect square. The square root is between " << previousNum << " and " << squareRoot << "!";
      abort();
    }

    squareRoot = beforeSquareRoot;
    previousNum = squareRoot;
    squareRoot += 1;
    beforeSquareRoot = squareRoot;
  }
  std::cout << "\nThe square root of " << square << " is " << squareRoot << "!\nThanks for using our program!\n";
}
