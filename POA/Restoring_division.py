# Left shift of a+q which reduces the size of q by 1 when bit is shifted
# Takes a, q and returns them in the same order
def left_shift(a, q):
    q_first = q[0]
    q = q[1:]

    a.append(q_first)
    a = a[1:]

    return a, q
# print(left_shift([1,0,0,1], [1, 0, 0, 1]))

# Adds two binary numbers a and b, both in list(int), with the same length. Ignores carry if generated in the end.
# Initial carry is 0 by default but can be given as 1 if needed.
def add(a, b, carry = 0):
    ans = [0] * len(a)
    i = len(a) - 1
    while i >= 0:
        # print(i, ': c', carry,'a', a[i], 'b', b[i])
        bit = carry + a[i] + b[i]
        
        if bit == 0:
            carry, ans[i] = 0, 0
        elif bit == 1:
            carry, ans[i] = 0, 1
        elif bit == 2:
            carry, ans[i] = 1, 0
        elif bit == 3:
            carry, ans[i] = 1, 1
        
        i -= 1
    return ans
# print(add([1,1,1,0], [1, 1, 0, 1]))

# Gives ones complement of a binary number a in list(int). 
# Returns binary number in list(int) of same length as a.
def ones_complement(a):
    c = []
    for dig in a:
        if dig == 0:
            c.append(1)
        else:
            c.append(0)
    return c
# print(complement([1,0,1,0,0]))

# Gives twos complement of a binary number a in list(int). 
# Returns binary number in list(int) of same length as a, using add(a, b, carry) and ones_complement(a) functions
def twos_complement(a):
    return add(ones_complement(a), [0]*len(a) , 1)

def restoring_division(q, m):
    n = len(q) # 4
    a = [0] * (n + 1)
    old_a = a 
    m_2comp = twos_complement(m)
    action = "Initial"
    print("n        A                       Q                   Action")
    print(n, "      ", a, "      ", q, "      ", action)
    while n > 0:
        a, q = left_shift(a, q)
        action = "   Left shift"
        print(n, "      ", a, "      ", q, "      ", action)

        old_a = a
        a = add(a, m_2comp)
        action = "   A = A-M"
        print(n, "      ", a, "      ", q, "      ", action)

        if a[0] == 1:
            action = "q0=0, restore a"
            a = old_a
            q.append(0)

        else:
            action = "q0=1"
            q.append(1)

        n -= 1
        print(n, "      ", a, "      ", q, "      ", action)

        
    return q, a

# Converts unsigned binary number in list(int) to its decimal value, in int
def binaryToDecimal(binary):
    binary = binary[1:]
    decimal = 0
    for dig in range(len(binary)):
        decimal += binary[dig] * 2**(len(binary)-1-dig)
    
    return decimal
# print(binaryToDecimal([1, 0, 0, 0]))

# Converts decimal number in int to its unsigned binary value, with total max_l length (default 4) in list(int)
def decimalToBinary(num, max_l = 4):
    binary = []
    rem = 0

    while num != 0:
        rem = num % 2
        num = num // 2
        binary = [rem] + binary
    
    if max_l > len(binary):
        more_zer = max_l - len(binary)
        binary = [0] * more_zer + binary
    
    return binary

# print(decimalToBinary(-13, 5))

# bool_q, bool_m = [1, 0, 0, 1], [0, 0, 1, 1]

# bool_q = list(map(lambda x: int(x), list(input("Dividend: "))))
# bool_m = list(map(lambda x: int(x), list(input("Divisor: "))))
# n = 4

# Driver code taking the inputs and printing the output.
# Inputs must be positive integers and Number of bits for the binary conversion must be able to accomodate the dividend and divisor.
dividend = int(input("Dividend: "))
divisor = int(input("Divisor: "))
n = int(input("Maximum number of bits: "))

bool_q = decimalToBinary(dividend, n)
bool_m = decimalToBinary(divisor, n+1) # Length of divisor binary = length of dividend binary + 1

print("Boolean Dividend: ", bool_q)
print("Boolean Divisor: ", bool_m)

# print("Integer Dividend: ", binaryToDecimal(bool_q))
# print("Integer Divisor: ", binaryToDecimal(bool_m))

quo, rem = restoring_division(bool_q, bool_m)

print("\nQuotient: ")
print("Boolean: ", quo)
print("Integer: ", binaryToDecimal(quo))

print("\nRemainder: ")
print("Boolean: ", rem)
print("Integer: ", binaryToDecimal(rem))
