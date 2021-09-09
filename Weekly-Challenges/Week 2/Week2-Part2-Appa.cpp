#include <iostream>
using namespace std;

void impossible()
{
  cout << "impossible";
  exit(0);
}
void endProgram(string answer)
{
  if (answer != "")
  {
    impossible();
  }
}
int main()
{
  char inputArray[3][4];

  int intArray[3][3];

  int counter1 = 0;
  int counter2 = 0;
  int z = 0;
  int p = 0;
  int q = 0;
  int r = 0;

  string answer = "";

  for (int i = 0; i < 3; i++)
  {
    cin >> inputArray[i];
    for (int x = 0; x < 3; x++)
    {
      if (inputArray[i][x] == '.')
      {
        intArray[i][x] = 0;
      }
      if (inputArray[i][x] == 'R')
      {
        intArray[i][x] = 2;
        counter1++;
      }
      if (inputArray[i][x] == 'B')
      {
        intArray[i][x] = 7;
        counter2++;
      }
    }
  }

  if (((counter1 > 5 || counter2 > 5) || (counter1 == 5 && counter2 == 5)) || (counter1 != counter2 && counter1 + 1 != counter2 && counter1 - 1 != counter2))
  {
    impossible();
  }

  for (int i = 0; i < 3; i++)
  {
    if ((intArray[2][i] == 0 && (intArray[1][i] != 0 || intArray[0][i] != 0)) || (intArray[1][i] == 0 && intArray[0][i] != 0))
    {
      impossible();
    }
  }

  q = intArray[0][0] + intArray[1][1] + intArray[2][2];
  r = intArray[0][2] + intArray[1][1] + intArray[2][0];

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      z += intArray[i][j];
      p += intArray[j][i];
    }
    if (z != p && p != q && z != q && r != z && r != p && r != q && (z == 6 || p == 6 || q == 6 || r == 6))
    {
      endProgram(answer);
      answer = "red";
    }
    if (z != p && p != q && z != q && r != z && r != p && r != q && (z == 21 || p == 21 || q == 21 || r == 21))
    {
      endProgram(answer);
      answer = "blue";
    }
    z = p = 0;
  }

  cout << "possible\n";

  if (answer == "")
  {
    cout << "tie";
  }
  else
  {
    cout << answer;
  }
}