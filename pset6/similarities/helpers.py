from nltk.tokenize import sent_tokenize


def lines(a, b):
    # split a into lines
    a_split = a.split('\n')

    # split b into lines
    b_split = b.split('\n')

    # find intersection between set a and b
    result = set(a_split).intersection(b_split)

    # convert result back into list as haha
    haha = list(result)
    return haha


def sentences(a, b):
    # split each string into sentences
    a_split = sent_tokenize(a)

    # split each string into sentences
    b_split = sent_tokenize(b)

    # find intersection between set a and b
    result = set(a_split).intersection(b_split)

    # convert result back into list as haha
    haha = list(result)
    return haha


def substrings(a, b, n):
    # create empty list to store substrings of a and b
    a_split = []
    b_split = []

    # split strings (a and b) into substring list
    for j in range(len(a) - (n - 1)):
        a_split.append(a[0 + j:n + j])

    for j in range(len(b) - (n - 1)):
        b_split.append(b[0 + j:n + j])

    # find intersection between set a and b
    result = set(a_split).intersection(b_split)

    # convert result back into list as haha
    haha = list(result)
    return haha
