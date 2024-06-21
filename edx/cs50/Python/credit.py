from cs50 import get_int

number = str(get_int("Number: "))


def check(x):
    product_sum = 0
    total_sum = 0
    n = len(x)

    for i in range(n):
        if i % 2 != 0:
            product = str(int(x[n-i-1]) * 2)
            for j in range(len(product)):
                product_sum += int(product[j])
        else:
            total_sum += int(x[n-i-1])

    total_sum += product_sum
    total_sum = str(total_sum)

    if total_sum[len(total_sum)-1] == '0':
        return True
    else:
        return False


if check(number):
    n = len(number)

    if n == 15 and number[0:2] in ('34', '37'):
        print("AMEX\n")
    elif n == 16 and number[0:2] in ('51', '52', '53', '54', '55'):
        print("MASTERCARD\n")
    elif n in (13, 16) and number[0] == '4':
        print("VISA\n")
    else:
        print("INVALID\n")

else:
    print("INVALID\n")

