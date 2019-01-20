from cs50 import get_int

while True:
    # prompt the user to input the height of bricks
    n = get_int("Height: ")
    if n >= 0 and n <= 23:
        break

# starting for loop counting the heights
for i in range(n):
    for j in range(n - i - 1):
        print(" ", end='')
    for k in range(i + 2):
        print("#", end='')
    print()
