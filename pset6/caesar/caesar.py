from cs50 import get_string
import sys

# command line more than 1 or not number -> return 1
if len(sys.argv) != 2:
    print("1")

else:
    # get key
    k = int(sys.argv[1])

    # use remainder to get the key if k > 26
    k = k % 26

    # get plaintext
    p = get_string("plaintext: ")

    ciphertext = str()

    # encipher
    for i in range(len(p)):
        # if char is alphabets, then execute the key
        if p[i].isalpha():
            # for uppercase letter
            if p[i].isupper():
                r = chr((ord(p[i]) - 65 + k) % 26 + 65)
                ciphertext += r

            # for lowercase letter
            elif p[i].islower():
                s = chr((ord(p[i]) - 97 + k) % 26 + 97)
                ciphertext += s

        # for non-alphabets, just keep it
        else:
            ciphertext += p[i]

# print ciphertext
print("ciphertext:", ciphertext)