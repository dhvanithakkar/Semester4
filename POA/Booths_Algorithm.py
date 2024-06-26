# Arithmetic right shift of ac+q+qi which replicates the sign bit as needed to fill bit position
# Takes ac, q, qi and returns them in the same order
def arithmetic_right_shift(ac, q, qi):
    q_last = q[-1] # removes last digit from q and saves it in qi
    qi = q_last
    q = q[:-1]

    repeated = [ac[0]] # Repeats MSB at the start
    ac = repeated + ac

    ac_last = ac[-1] # removes last digit from q and adds it to start of q 
    q = [ac_last] + q
    ac = ac[:-1]

    return ac, q, qi
# print(arithmetic_right_shift([1,0,0,0], [1, 0, 0, 0], 1))

# Adds two binary numbers a and b, both in list(int), with the same length. Ignores carry if generated.
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
# print(ones_complement([1,0,1,0,0]))

# Gives twos complement of a binary number a in list(int). 
# Returns binary number in list(int) of same length as a, using add(a, b, carry) and ones_complement(a) functions
def twos_complement(a):
    return add(ones_complement(a), [0]*len(a) , 1)

# Main function implementing booth's algorithm according to the flowchart given.  
# Uses add(a, b, carry), arithmetic_right_shift(ac, q, qi) and twos_complement(a)
def booths_algo(m, q):
    sc = len(m)
    qi = 0
    ac = [0] * sc
    m_2comp = twos_complement(m)
    action = "  Initial"
    print("n        A                       Q                   Action")
    print(n, "      ", ac, "      ", q, "      ", action)

    while sc > 0:
        if q[-1] == 0 and qi == 1:
            ac = add(ac, m)
            action = "   A = A+M"
            print(n, "      ", ac, "      ", q, "      ", action)


        elif q[-1] == 1 and qi == 0:
            ac = add(ac, m_2comp)            
            action = "   A = A-M"
            print(n, "      ", ac, "      ", q, "      ", action)


        sc -= 1
        ac, q, qi = arithmetic_right_shift(ac, q, qi)     
        action = "   Arithmetic Right Shift"
        print(n, "      ", ac, "      ", q, "      ", action)

    return ac + q

# Converts signed (first bit is signed bit) binary number in list(int) to its decimal value, in int
# Takes negative numbers into consideration
def binaryToDecimal(binary):
    is_negative = False
    if binary[0] == 1:
        binary =  twos_complement(binary)
        is_negative = True

    binary = binary[1:]
    decimal = 0
    for dig in range(len(binary)):
        decimal += binary[dig] * 2**(len(binary)-1-dig)
    
    if is_negative: 
        return -decimal
    
    return decimal
# print(binaryToDecimal([1, 0, 0, 0]))

# Converts decimal number in int to its signed (first bit is signed bit) binary value, with total max_l length (default 4) in list(int)
# Takes negative numbers into consideration
def decimalToBinary(num, max_l = 4):
    is_negative = False
    if num < 0:
        is_negative = True
        num = -num

    binary = []
    rem = 0

    while num != 0:
        rem = num % 2
        num = num // 2
        binary = [rem] + binary
    
    if max_l > len(binary):
        more_zer = max_l - len(binary)
        binary = [0] * more_zer + binary

    if is_negative:
        return twos_complement(binary)
    
    return binary

# print(decimalToBinary(-13, 5))

# bool1, bool2 = [1, 0, 0, 1], [0, 0, 1, 1]

# bool1 = list(map(lambda x: int(x), list(input("Multiplicand: "))))
# bool2 = list(map(lambda x: int(x), list(input("Multiplier: "))))
# print(num1, num2)
# n = 4

# Driver code taking the inputs and printing the output.
num1 = int(input("Multiplicand: "))
num2 = int(input("Multiplier: "))
n = int(input("Number of digits(including signed bit): "))

bool1 = decimalToBinary(num1, n)
bool2 = decimalToBinary(num2, n)

print("Boolean Multiplicand: ", bool1)
print("Boolean Multiplier: ", bool2)

print("Integer Multiplicand: ", binaryToDecimal(bool1))
print("Integer Multiplier: ", binaryToDecimal(bool2))

mul = booths_algo(bool1, bool2)

print("\nResult:")
print("Boolean: ", mul)
print("Integer: ", binaryToDecimal(mul))
