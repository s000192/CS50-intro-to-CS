from cs50 import get_float

while True:
    # prompt user to type in the change owed
    c = get_float("Change owed: ")
    if c > 0:
        break

# convert the value into cents
c *= 100

# rounding c to integers
c = round(c)

n = 0

# deducting 25 cents from the change owed "c" until it's smaller than 25 cents
while True:
    if c < 25:
        break
    c -= 25
    n += 1

# deducting 10 cents from the change owed "c" until it's smaller than 10 cents
while True:
    if c < 10:
        break
    c -= 10
    n += 1

# deducting 5 cents from the change owed "c" until it's smaller than 5 cents
while True:
    if c < 5:
        break
    c -= 5
    n += 1


# deducting 1 cents from the change owed "c" until it's smaller than 1 cents
while True:
    if c < 1:
        break
    c -= 1
    n += 1

# print out the number of coins needed
print(n)