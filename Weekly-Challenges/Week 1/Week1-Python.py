square = int(input("Enter a number(preferably a perfect square): "))
squareRoot = 2
beforeSquareRoot = squareRoot
previousNum = 1

if square == 0 or square == 1:
  print(f"Your number inputted is {square}, and {square} is the square of itself, so your answer is {square}!")
  exit()

while True: 
  if squareRoot % 1000 == 0:
    print(".", end="")
  if squareRoot % 10000 == 0:
    print("This may take some time", end="")

  for i in range(1, squareRoot):
    squareRoot += beforeSquareRoot

  if squareRoot == square:
    squareRoot = beforeSquareRoot
    break
  elif squareRoot > square:
    squareRoot = beforeSquareRoot

    print(f"\nYour number must not be a perfect square. The square root is between {previousNum} and {squareRoot}!")
    exit()

  squareRoot = beforeSquareRoot
  previousNum = squareRoot
  # My ++ is not working unfortunately... maybe this is the wrong coding language I am thinking of, or I am just dumb :(
  squareRoot += 1
  beforeSquareRoot = squareRoot

print(f"\nThe square root of {square} is {squareRoot}!\nThanks for using our program!")
