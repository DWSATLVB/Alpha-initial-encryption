Dict_of_store = {}
each_element = []
Dict_of_store_scrap = {}
inp = []
key = []
i = 0


l_case = 'abcdefghijklmnopqrstuvwxyz'
U_case = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

encrypted = ''

# Populates the two dictionaries Dict_of_store = {} and Dict_of_store_scrap = {} with lowercase letters
for idx, el_l in enumerate(l_case):
    Dict_of_store[el_l] = idx + 1
    Dict_of_store_scrap[idx + 1] = el_l

#Populates the two dictionaries Dict_of_store = {} and Dict_of_store_scrap = {} with uppercase letters
for idx, el_U in enumerate(U_case):
    Dict_of_store[el_U] = idx + 27
    Dict_of_store_scrap[idx + 27] = el_U

# Adding space character
Dict_of_store[" "] = 53
Dict_of_store_scrap[53] = " "

inp_main = input("Main: ").strip()
key_main = input("Key: ").strip()


for el_main1 in inp_main:
    inp.append(el_main1)

# Adjusting the key length to match inp length
if len(inp_main) > len(key_main):
    for el_main2 in key_main:
        key.append(el_main2)
    while len(key) < len(inp):
        key.append(key[i % len(key)])
        i += 1
elif len(key_main) > len(inp_main):
    for el_main3 in key_main:
        key.append(el_main3)
        if len(key) == len(inp):
            break
else:
    for el_main4 in key_main:
        key.append(el_main4)
        
#Algorithm starts
for lock, key_elem in zip(inp, key):
    another = Dict_of_store[lock] + Dict_of_store[key_elem]
    each_element.append(another)


for new_main in each_element:
    if new_main > 53:
        num = new_main - 53
        if num in Dict_of_store_scrap:  
            encrypted += Dict_of_store_scrap[num]
        else:
            encrypted += "?"  # Handles out of bounds 
    else:
        encrypted += Dict_of_store_scrap[new_main]

print(encrypted)
