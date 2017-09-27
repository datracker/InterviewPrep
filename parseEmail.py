'''Validating and parsing email address, this problem was found in HackerRank.
A valid email address meets the following criteria:

1. It's composed of a username, domain name, and extension assembled in this format: username@domain.extension
2. The username starts with an English alphabetical character, and any subsequent characters consist of one or more of the following: alphanumeric characters, -,., and _.
3. The domain and extension contain only English alphabetical characters.
4. The extension is 1, 2, or 3 characters in length.
Given  pairs of names and email addresses as input, print each name and email address pair having a valid email address on a new line.
'''

import re
from email.utils import *

n = int(input())
pattern = r'^[a-z][\w\-\.]+@[a-z]+\.[a-z]{1,3}$'

for _ in range(n):
    email = parseaddr(input())
    if re.search(pattern, email[1], re.I):
        print(formataddr(email))