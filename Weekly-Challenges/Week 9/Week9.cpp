#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

#define cout std::cout
#define cin std::cin
typedef std::string string;

// string multiplication(string linearEquationN, int indexes, char variable);
// string division(string linearEquationN, int indexes, char variable);
// string addition(string linearEquationN, int indexes, char variable);
// string subtraction(string linearEquationN, int indexes, char variable);

int main()
{
  string linearEquation = "";
  string linearEquation1 = "";
  string linearEquation2 = "";
  // string linearEquationSimp1 = "";
  // string linearEquationSimp2 = "";
  // string linearE1numbers = "";
  // string linearE1variables = "";
  // string linearE2numbers = "";
  // string linearE2variables = "";
  string alphabets = "abcdefghijklmnopqrstuvwxyz";

  char variable;

  bool gotVariable = false;
  bool wasEqualTo = false;
  bool notEqualToYet = true;
  bool leftSideVar = false;
  bool rightSideVar = false;
  // bool variableOne = false;

  int indexes = 0;
  int beforeIndex = indexes;
  int length1 = 0;
  int length2 = 0;
  int elementForOperation = 0;
  int operatorNoOne = 0;
  int operatorNoTwo = 0;

  cout << "NOTICE: Parentheses, powers, roots, and negative numbers will not work at this moment. I will improve this later but right now they do not work. All of the above will return errors...though some times negative numbers could work.\n\n";

  cout << "Enter the linear equation with one variable(lowercase is must): ";
  std::getline(cin, linearEquation);

  linearEquation.erase(remove(linearEquation.begin(), linearEquation.end(), ' '), linearEquation.end());

  // cout << "This was the equation you inputted: " << linearEquation << "\n";

  for (char c : linearEquation)
  {
    // TODO: Make sure there is one 'equals to' symbol in the equation
    if (c == '=')
    {
      if (wasEqualTo)
      {
        cout << "How many '=' are there??\n";
        exit(1);
      }
      wasEqualTo = true;
    }
    // TODO: Make sure there is one variable in the equation
    for (char alphabet : alphabets)
    {
      if (c == alphabet)
      {
        if (gotVariable)
        {
          if (alphabet == variable)
          {
            continue;
          }
          cout << "How many variables are there in a ONE VARIABLE linear equation (facepalm)??\n";
          exit(1);
        }
        gotVariable = true;
        // TODO: Find out what letter was used as a variable
        variable = alphabet;
        // TODO: Find out which side the variable is on
        if (wasEqualTo)
        {
          rightSideVar = true;
        }
        else
        {
          leftSideVar = true;
        }
      }
    }
    // TODO: Make sure two operands don't come right after each other
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
      if (linearEquation[indexes + 1] == '+' || linearEquation[indexes + 1] == '-' || linearEquation[indexes + 1] == '*' || linearEquation[indexes + 1] == '/')
      {
        cout << "Really? Two operands one after another? That is what you thought you could do?\n";
        exit(1);
      }
    }
    indexes++;
  }

  indexes = 0;

  if (!wasEqualTo)
  {
    cout << "You didn't input a '=', which for a linear EQUATION is necessary!\n";
    exit(1);
  }
  if (!gotVariable)
  {
    cout << "You didn't input a variable, which for a one VARIABLE linear equation is necessary!\n";
    exit(1);
  }

  // TODO: Separate the equation into two parts
  for (char c : linearEquation)
  {
    if (c == '=')
    {
      notEqualToYet = false;
      continue;
    }

    if (notEqualToYet)
    {
      linearEquation1 += c;
    }
    else
    {
      linearEquation2 += c;
    }
  }

  // cout << "Part 1: " << linearEquation1 << "\n";
  // cout << "Part 2: " << linearEquation2 << "\n";

  for (char c : linearEquation1)
  {
    length1 += 1;
    // TODO: Remember to fix this when adding negatives so that it doesn't count the negative symbol as an operator (meaning if it is inside brackets)
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
      operatorNoOne += 1;
    }
  }

  for (char c : linearEquation2)
  {
    length2 += 1;
    // TODO: Remember to fix this when adding negatives so that it doesn't count the negative symbol as an operator (meaning if it is inside brackets)
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
      operatorNoTwo += 1;
    }
  }

  length1 -= 1;
  length2 -= 1;

  // TODO: Retype this after seperating the equation into two parts so that for both parts you check this condition
  if (linearEquation1[0] == '*' || linearEquation1[0] == '/' || linearEquation1[length1] == '+' || linearEquation1[length1] == '-' || linearEquation1[length1] == '*' || linearEquation1[length1] == '/')
  {
    cout << "Do not misuse operands (meaning don't use them in the wrong place) please!\n";
    exit(1);
  }
  else if (linearEquation2[0] == '*' || linearEquation2[0] == '/' || linearEquation2[length2] == '+' || linearEquation2[length2] == '-' || linearEquation2[length2] == '*' || linearEquation2[length2] == '/')
  {
    cout << "Do not misuse operands (meaning don't use them in the wrong place) please!\n";
    exit(1);
  }

  linearEquation = linearEquation1 + "=" + linearEquation2;

  cout << "Your equation \"" << linearEquation << "\" is valid!\n";

  // while (operatorNoOne < 1)
  // {
  //   for (char c : linearEquation1)
  //   {
  //     if (c == '*')
  //     {
  //       linearEquationSimp1 += multiplication(linearEquation1, indexes, variable);
  //     }
  //     indexes++;
  //     beforeIndex = indexes;
  //   }

  //   operatorNoOne = 0;
  //   for (char c : linearEquation1)
  //   {
  //     // TODO: Remember to fix this when adding negatives so that it doesn't count the negative symbol as an operator (meaning if it is inside brackets)
  //     if (c == '+' || c == '-' || c == '*' || c == '/')
  //     {
  //       operatorNoOne += 1;
  //     }
  //   }
  // }

  // for (char c : linearEquation1)
  // {
  //   if (c == '+' || c == '-' || c == '*' || c == '/' || indexes == 0)
  //   {
  //     if (linearEquation1[indexes] == variable)
  //     {
  //       variableOne = true;
  //     }
  //     indexes++;

  //     while (linearEquation1[indexes] != '+' || linearEquation1[indexes] != '-' || linearEquation1[indexes] != '*' || linearEquation1[indexes] != '/')
  //     {
  //       cout << "reached here 1\n";
  //       if (linearEquation1[indexes] == variable)
  //       {
  //         cout << "reached here 2\n";
  //         variableOne = true;
  //       }
  //       indexes++;
  //       cout << linearEquation1[indexes] << "\n";
  //     }
  //     indexes = beforeIndex;

  //     do
  //     {
  //       cout << "reached here 3\n";
  //       if (variableOne)
  //       {
  //         cout << "reached here 4\n";
  //         linearE1variables += linearEquation1[indexes];
  //       }
  //       else
  //       {
  //         cout << "reached here 5\n";
  //         linearE1numbers += linearEquation1[indexes];
  //       }
  //       indexes++;
  //     } while (linearEquation1[indexes] != '+' || linearEquation1[indexes] != '-' || linearEquation1[indexes] != '*' || linearEquation1[indexes] != '/');
  //     indexes = beforeIndex;
  //   }
  //   indexes++;
  //   beforeIndex = indexes;
  // }

  // cout << linearE1numbers << "\n";
  // cout << linearE1variables << "\n";

  // IMPORTANT: Follow PEMDAS
}

// string multiplication(string linearEquationN, int indexes, char variable)
// {
//   bool variablePresent = false;

//   string theFirstNumber = "";
//   string theSecondNumber = "";
//   string theFinalProduct = "";

//   int beforeIndex = indexes;
//   int firstInteger = 0;
//   int secondInteger = 0;
//   int theFinalProductInt = 0;
//   int length = 0;

//   for (char c : linearEquationN)
//   {
//     length++;
//   }

//   indexes--;
//   while (indexes != -1 || linearEquationN[indexes] != '+' || linearEquationN[indexes] != '-' || linearEquationN[indexes] != '*' || linearEquationN[indexes] != '/')
//   {
//     indexes--;

//     if (indexes == -1 || linearEquationN[indexes] == '*' || linearEquationN[indexes] == '/' || linearEquationN[indexes] == '+')
//     {
//       indexes++;
//       while (linearEquationN[indexes] != '*')
//       {
//         theFirstNumber += linearEquationN[indexes];
//         indexes++;

//         if (linearEquationN[indexes] == variable)
//         {
//           variablePresent = true;
//           break;
//         }
//       }
//     }
//     else if (linearEquationN[indexes] == '-')
//     {
//       while (linearEquationN[indexes] != '*')
//       {
//         theFirstNumber += linearEquationN[indexes];
//         indexes++;

//         if (linearEquationN[indexes] == variable)
//         {
//           variablePresent = true;
//           break;
//         }
//       }
//     }
//   }
//   indexes = beforeIndex;

//   indexes++;
//   while (indexes != length || linearEquationN[indexes] != '+' || linearEquationN[indexes] != '-' || linearEquationN[indexes] != '*' || linearEquationN[indexes] != '/')
//   {
//     theSecondNumber += linearEquationN[indexes];
//     indexes++;

//     if (linearEquationN[indexes] == variable)
//     {
//       if (variablePresent)
//       {
//         cout << "Unfortunately since we cannot operate with powers and roots, multiplying two variables cannot work as it results in that variable squared, which is a power!\n";
//         exit(1);
//       }
//       variablePresent = true;
//       break;
//     }
//   }
//   // Just realized I haven't reset the value for `indexes` yet so note that

//   std::stringstream theFirstInteger;
//   std::stringstream theSecondInteger;

//   theFirstInteger << theFirstNumber;
//   theSecondInteger << theSecondNumber;

//   theFirstInteger >> firstInteger;
//   theSecondInteger >> secondInteger;

//   theFinalProductInt = firstInteger * secondInteger;
//   cout << "Umm final product of multiplication" << theFinalProductInt << "\n";

//   std::stringstream finalProduct;

//   finalProduct << theFinalProductInt;
//   finalProduct >> theFinalProduct;

//   if (variablePresent)
//   {
//     theFinalProduct += variable;
//   }

//   return theFinalProduct;
// }

// string division(string linearEquationN, int indexes, char variable)
// {
//   // If the first number has one variable only then you can just add the variable at the end of the string, if only the second number has a variable then you have to give an error, and if both have a variable then cancel the variable
//   bool firstNVariablePresent = false;
//   bool secondNVariablePresent = false;

//   string theFirstNumber = "";
//   string theSecondNumber = "";
//   string theFinalProduct = "";

//   int beforeIndex = indexes;
//   int firstInteger = 0;
//   int secondInteger = 0;
//   int theFinalProductInt = 0;
//   int length = 0;

//   for (char c : linearEquationN)
//   {
//     length++;
//   }

//   indexes--;
//   while (indexes != -1 || linearEquationN[indexes] != '+' || linearEquationN[indexes] != '-' || linearEquationN[indexes] != '*' || linearEquationN[indexes] != '/')
//   {
//     indexes--;

//     if (indexes == -1 || linearEquationN[indexes] == '*' || linearEquationN[indexes] == '/' || linearEquationN[indexes] == '+')
//     {
//       indexes++;
//       while (linearEquationN[indexes] != '/')
//       {
//         theFirstNumber += linearEquationN[indexes];
//         indexes++;

//         if (linearEquationN[indexes] == variable)
//         {
//           firstNVariablePresent = true;
//           break;
//         }
//       }
//     }
//     else if (linearEquationN[indexes] == '-')
//     {
//       while (linearEquationN[indexes] != '/')
//       {
//         theFirstNumber += linearEquationN[indexes];
//         indexes++;

//         if (linearEquationN[indexes] == variable)
//         {
//           firstNVariablePresent = true;
//           break;
//         }
//       }
//     }
//   }
//   indexes = beforeIndex;

//   indexes++;
//   while (indexes != length || linearEquationN[indexes] != '+' || linearEquationN[indexes] != '-' || linearEquationN[indexes] != '*' || linearEquationN[indexes] != '/')
//   {
//     theSecondNumber += linearEquationN[indexes];
//     indexes++;

//     if (linearEquationN[indexes] == variable)
//     {
//       secondNVariablePresent = true;
//       break;
//     }
//   }
//   // Just realized I haven't reset the value for `indexes` yet so note that

//   std::stringstream theFirstInteger;
//   std::stringstream theSecondInteger;

//   theFirstInteger << theFirstNumber;
//   theSecondInteger << theSecondNumber;

//   theFirstInteger >> firstInteger;
//   theSecondInteger >> secondInteger;

//   theFinalProductInt = firstInteger / secondInteger;
//   cout << "Umm final product of division" << theFinalProductInt << "\n";

//   std::stringstream finalProduct;

//   finalProduct << theFinalProductInt;
//   finalProduct >> theFinalProduct;

//   if (firstNVariablePresent && !secondNVariablePresent)
//   {
//     theFinalProduct += variable;
//   }
//   else if (secondNVariablePresent && !firstNVariablePresent)
//   {
//     cout << "Well my code cannot deal with fractions so I cannot divide a non-fraction number by a fraction number - sorry!";
//     exit(1);
//   }

//   return theFinalProduct;
// }

// string addition(string linearEquationN, int indexes, char variable)
// {
//   bool firstNVariablePresent = false;
//   bool secondNVariablePresent = false;

//   string theFirstNumber = "";
//   string theSecondNumber = "";
//   string theFinalProduct = "";

//   int beforeIndex = indexes;
//   int firstInteger = 0;
//   int secondInteger = 0;
//   int theFinalProductInt = 0;
//   int length = 0;

//   for (char c : linearEquationN)
//   {
//     length++;
//   }

//   indexes--;
//   while (indexes != -1 || linearEquationN[indexes] != '+' || linearEquationN[indexes] != '-' || linearEquationN[indexes] != '*' || linearEquationN[indexes] != '/')
//   {
//     indexes--;

//     if (indexes == -1 || linearEquationN[indexes] == '*' || linearEquationN[indexes] == '/' || linearEquationN[indexes] == '+')
//     {
//       indexes++;
//       while (linearEquationN[indexes] != '+')
//       {
//         theFirstNumber += linearEquationN[indexes];
//         indexes++;

//         if (linearEquationN[indexes] == variable)
//         {
//           firstNVariablePresent = true;
//           break;
//         }
//       }
//     }
//     else if (linearEquationN[indexes] == '-')
//     {
//       while (linearEquationN[indexes] != '+')
//       {
//         theFirstNumber += linearEquationN[indexes];
//         indexes++;

//         if (linearEquationN[indexes] == variable)
//         {
//           firstNVariablePresent = true;
//           break;
//         }
//       }
//     }
//   }
//   indexes = beforeIndex;

//   indexes++;
//   while (indexes != length || linearEquationN[indexes] != '+' || linearEquationN[indexes] != '-' || linearEquationN[indexes] != '*' || linearEquationN[indexes] != '/')
//   {
//     theSecondNumber += linearEquationN[indexes];
//     indexes++;

//     if (linearEquationN[indexes] == variable)
//     {
//       secondNVariablePresent = true;
//       break;
//     }
//   }
//   // Just realized I haven't reset the value for `indexes` yet so note that

//   if (firstNVariablePresent && !secondNVariablePresent)
//   {
//     theFinalProduct = theFirstNumber + variable + "+" + theSecondNumber;
//     return theFinalProduct;
//   }
//   else if (!firstNVariablePresent && secondNVariablePresent)
//   {
//     theFinalProduct = theFirstNumber + "+" + theSecondNumber + variable;
//     return theFinalProduct;
//   }

//   std::stringstream theFirstInteger;
//   std::stringstream theSecondInteger;

//   theFirstInteger << theFirstNumber;
//   theSecondInteger << theSecondNumber;

//   theFirstInteger >> firstInteger;
//   theSecondInteger >> secondInteger;

//   theFinalProductInt = firstInteger + secondInteger;
//   cout << "Umm final product of addition" << theFinalProductInt << "\n";

//   std::stringstream finalProduct;

//   finalProduct << theFinalProductInt;
//   finalProduct >> theFinalProduct;

//   if (firstNVariablePresent && secondNVariablePresent)
//   {
//     theFinalProduct += variable;
//   }

//   return theFinalProduct;
// }

// string subtraction(string linearEquationN, int indexes, char variable)
// {
//   bool firstNVariablePresent = false;
//   bool secondNVariablePresent = false;

//   string theFirstNumber = "";
//   string theSecondNumber = "";
//   string theFinalProduct = "";

//   int beforeIndex = indexes;
//   int firstInteger = 0;
//   int secondInteger = 0;
//   int theFinalProductInt = 0;
//   int length = 0;

//   for (char c : linearEquationN)
//   {
//     length++;
//   }

//   indexes--;
//   while (indexes != -1 || linearEquationN[indexes] != '+' || linearEquationN[indexes] != '-' || linearEquationN[indexes] != '*' || linearEquationN[indexes] != '/')
//   {
//     indexes--;

//     if (indexes == -1 || linearEquationN[indexes] == '*' || linearEquationN[indexes] == '/' || linearEquationN[indexes] == '+')
//     {
//       indexes++;
//       while (linearEquationN[indexes] != '-')
//       {
//         theFirstNumber += linearEquationN[indexes];
//         indexes++;

//         if (linearEquationN[indexes] == variable)
//         {
//           firstNVariablePresent = true;
//           break;
//         }
//       }
//     }
//     else if (linearEquationN[indexes] == '-')
//     {
//       theFirstNumber += "-";
//       indexes++;
//       while (linearEquationN[indexes] != '-')
//       {
//         theFirstNumber += linearEquationN[indexes];
//         indexes++;

//         if (linearEquationN[indexes] == variable)
//         {
//           firstNVariablePresent = true;
//           break;
//         }
//       }
//     }
//   }
//   indexes = beforeIndex;

//   indexes++;
//   while (indexes != length || linearEquationN[indexes] != '+' || linearEquationN[indexes] != '-' || linearEquationN[indexes] != '*' || linearEquationN[indexes] != '/')
//   {
//     theSecondNumber += linearEquationN[indexes];
//     indexes++;

//     if (linearEquationN[indexes] == variable)
//     {
//       secondNVariablePresent = true;
//       break;
//     }
//   }
//   // Just realized I haven't reset the value for `indexes` yet so note that

//   if (firstNVariablePresent && !secondNVariablePresent)
//   {
//     theFinalProduct = theFirstNumber + variable + "-" + theSecondNumber;
//     return theFinalProduct;
//   }
//   else if (!firstNVariablePresent && secondNVariablePresent)
//   {
//     theFinalProduct = theFirstNumber + "-" + theSecondNumber + variable;
//     return theFinalProduct;
//   }

//   std::stringstream theFirstInteger;
//   std::stringstream theSecondInteger;

//   theFirstInteger << theFirstNumber;
//   theSecondInteger << theSecondNumber;

//   theFirstInteger >> firstInteger;
//   theSecondInteger >> secondInteger;

//   theFinalProductInt = firstInteger - secondInteger;
//   cout << "Umm final product of subtraction" << theFinalProductInt << "\n";

//   std::stringstream finalProduct;

//   finalProduct << theFinalProductInt;
//   finalProduct >> theFinalProduct;

//   if (firstNVariablePresent && secondNVariablePresent)
//   {
//     theFinalProduct += variable;
//   }

//   return theFinalProduct;
// }

// PROBLEM: Fix the problem that occurs when there is only a variable, and no coefficient
// IDEA: Add a 1 before a variable without a coefficient. Also when adding or subtracting coefficient numbers only do the operation on the coefficient and then add the variable at the end.

// PROBLEM: Two variables cannot come adjacent to each other so it will cause problems when multiplying a negative number and a positive or two negatives or when dividing negatives from positives or the opposite or when dividing negatives by negatives. Probably ask users to use brackets as to not make the program confused and when noticing a bracket, remove it and allow it if the conditions meet.

// MONDAY & TUESDAY & WEDNESDAY
// TODO: Simplify both sides of the equation
// TODO: - Create multiplication function
// TODO: - Create division function
// TODO: - Create addition function
// TODO: - Create subtraction function

// TODO: Concatenate both sides of the equation
// TODO: Move normal values to other side and change their symbols
// TODO: Simplify the other side
// TODO: Repeat the last two steps over and over until there is only the variable on one side

// THURSDAY
// TODO: Print out the value of the variable
// TODO: Maybe make a graph with the value I get