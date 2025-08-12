import math

def validadorInteiros():
    a = input("= ")
    while a.isdigit() == False:
        a = input(f"= ")
    return int(a)

while True:
    n = validadorInteiros()
    k = validadorInteiros()

    if n >= k:
        C = math.factorial(n) / (math.factorial(k) * math.factorial(n - k))
        break
    else:
        print("ERROR")
        continue
print(f"Combinação de ({n},{k}) = {C}")
