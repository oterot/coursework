while True:
    height = input("Height: ")
    if not height.isdigit():
        print("Enter an integer between 0 and 8 inclusive.")
        continue
    height = int(height)
    if height > 0 and height < 9 and height:
        break
    else:
        print("Enter an integer between 0 and 8 inclusive.")

for i in range(height):
    spaces = height - i - 1
    blocks = i + 1
    left = (" " * spaces) + ("#" * blocks)
    right = ("#" * blocks)
    print(left + "  " + right)