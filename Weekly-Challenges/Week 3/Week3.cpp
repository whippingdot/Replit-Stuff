#include <iostream>
#include <cstdio>
#include <vector>

int addYesSayers(std::vector<int> answer, int yesSayers, int i)
{
  if (answer[i] > answer[i + 1])
  {
    ++yesSayers;
  }
  return yesSayers;
}

int main()
{
  int memberNo = 0;
  int coins = 100;
  int yesSayers = 0;

  std::vector<int> answer = std::vector<int>();
  answer.push_back(0);
  answer.push_back(0);

  puts("Please enter the amount of pirates to divide the 100 gold among:");
  std::cin >> memberNo;

  do
  {
    std::cout << "Hits this too\n";
    if (answer.size() == 2)
    {
      std::cout << "Hits this\n";
      answer[0] = coins;
      answer[1] = coins;
      answer.push_back(0);
      answer.push_back(0);
      continue;
    }

    for (int i = 100; i > 0; --i)
    {
      std::cout << "WUT hits this\n";
      answer[answer.size() - 2] = i;
      std::cout << "DEBUG 1 " << answer[answer.size() - 2] << std::endl;
      coins -= i;
      std::cout << "DEBUG 2 " << coins << std::endl;

      for (unsigned int x = 4; (answer.size() - x) >= 0; x += 2)
      {
        std::cout << x << std::endl;
        answer[answer.size() - x] = coins;
        std::cout << "DEBUG 3 " << answer.size() - x << std::endl;
        for (int y = 0; y != answer.size() - 2; y += 2)
        {
          std::cout << "O\n";
          yesSayers = addYesSayers(answer, yesSayers, y);
        }
        if ((yesSayers * 100 / ((answer.size() - 2) / 2)) > 50)
        {
          for (int y = 1; y != answer.size() + 1; y += 2)
          {
            answer[y] = answer[y - 1];
          }
          break;
        }
      }
      if ((yesSayers * 100 / ((answer.size() - 2) / 2)) > 50)
      {
        break;
      }
    }

    answer.push_back(0);
    answer.push_back(0);
    coins = 100;
    yesSayers = 0;
    // for (int i = 0; i < answer.size(); i += 2)
    // {
    //   if (answer.size() == 2) {
    //     answer[i] =
    //   }
    //   for (int x = 100; x >= 0; --x)
    //   {
    //     coins -= x;
    //     answer[i] = x;
    //   }
    // }
  } while (answer.size() <= memberNo * 2);

  puts("Here 'A' is the youngest and it gets older from there!");

  int counter = 1;
  int anotherCounter = 0;

  for (char alphabet : "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
  {
    if ((answer.size() / 2) - 1 < counter)
    {
      break;
    }
    std::cout << alphabet << ": " << answer[anotherCounter] << std::endl;
    ++counter;
    anotherCounter += 2;
  }
}