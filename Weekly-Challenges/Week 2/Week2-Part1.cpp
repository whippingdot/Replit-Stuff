#include <iostream>
using namespace std;

void checkRow(string line)
{
  if (line == "BBB")
  {
    cout << "blue";
    exit(0);
  }
  else if (line == "RRR")
  {
    cout << "red";
    exit(0);
  }
}

int main()
{
  string line1;
  string line2;
  string line3;

  cin >> line1;
  cin >> line2;
  cin >> line3;

  checkRow(line1);
  checkRow(line2);
  checkRow(line3);

  for (int i = 0; i < 3; i++)
  {
    for (char c : "BR")
    {
      if (line1[i] == line2[i] && line1[i] == line3[i] && line3[i] == c)
      {
        if (c == 'B')
        {
          cout << "blue";
          exit(0);
        }
        cout << "red";
        exit(0);
      }
    }
  }
  for (char c : "BR")
  {
    if (line1[0] == line2[1] && line1[0] == line3[2] && line3[2] == c)
    {
      if (c == 'B')
      {
        cout << "blue";
        exit(0);
      }
      cout << "red";
      exit(0);
    }
    if (line1[2] == line2[1] && line1[2] == line3[0] && line3[0] == c)
    {
      if (c == 'B')
      {
        cout << "blue";
        exit(0);
      }
      cout << "red";
      exit(0);
    }
  }
  cout << "tie";
}