from cs50 import get_string
import re

text = get_string("Text: ")

num_letters = 0
num_sentences = 0

for c in text:
    if c.isalpha():
        num_letters += 1
    if c in '.?!':
        num_sentences += 1

words = text.split()
num_words = len(words)

l = num_letters / (num_words/100)
s = num_sentences / (num_words/100)
index = round(.0588 * l - .296 * s - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
