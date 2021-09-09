#include <iostream>
using namespace std;

// remember to change the function name(s) later
void impossible()
{
  cout << "impossible";
  exit(0);
}
void checkImpossible(string answer)
{
  if (answer != "")
  {
    impossible();
  }
}

string rowWin(string line, string answer)
{
  if (line == "BBB")
  {
    checkImpossible(answer);
    return "blue";
  }
  else if (line == "RRR")
  {
    checkImpossible(answer);
    return "red";
  }
  return answer;
}

int main()
{
  // remember to change the variable names later
  string line1;
  string line2;
  string line3;
  string answer;

  int numberOB = 0;
  int numberOR = 0;

  cin >> line1 >> line2 >> line3;

  answer = rowWin(line1, answer);
  answer = rowWin(line2, answer);
  answer = rowWin(line3, answer);

  for (int i = 0; i < 3; i++)
  {
    if (line1[i] != '.' || line2[i] != '.')
    {
      if (line2[i] == '.' || line3[i] == '.')
      {
        impossible();
      }
    }
    for (char c : "BR")
    {
      if (line1[i] == line2[i] && line1[i] == line3[i] && line3[i] == c)
      {
        checkImpossible(answer);
        if (c == 'B')
        {
          answer = "blue";
        }
        else
        {
          answer = "red";
        }
      }
    }
    line1[i] == 'B' ? numberOB += 1 : numberOB;
    line1[i] == 'R' ? numberOR += 1 : numberOR;
    line2[i] == 'B' ? numberOB += 1 : numberOB;
    line2[i] == 'R' ? numberOR += 1 : numberOR;
    line3[i] == 'B' ? numberOB += 1 : numberOB;
    line3[i] == 'R' ? numberOR += 1 : numberOR;
  }

  if (numberOB != numberOR && numberOB + 1 != numberOR && numberOB - 1 != numberOR)
  {
    impossible();
  }

  for (char c : "BR")
  {
    if (line1[0] == line2[1] && line1[0] == line3[2] && line3[2] == c)
    {
      checkImpossible(answer);
      if (c == 'B')
      {
        answer = "blue";
      }
      else
      {
        answer = "red";
      }
    }
    if (line1[2] == line2[1] && line1[2] == line3[0] && line3[0] == c)
    {
      checkImpossible(answer);
      if (c == 'B')
      {
        answer = "blue";
      }
      else
      {
        answer = "red";
      }
    }
  }

  if (answer == "")
  {
    impossible();
  }
  cout << "possible\n"
       << answer;
}