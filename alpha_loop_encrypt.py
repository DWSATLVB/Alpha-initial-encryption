Dict_of_store = {}
each_element = []
Dict_of_store_scrap = {}
inp = []
key =[]
i = 0
j = 26
r = 0
l_case = 'abcdefghijklmnopqrstuvwxyz'  #done so that the values are added automatically
U_case = 'ABCDEFGHIJKLMNOPQRSTUVQXYZ'
encrypted = ''

for el_l in l_case:    #adding lowercase letters to Dict_of_store
    Dict_of_store[el_l] = i+1
    Dict_of_store_scrap[i+1] = el_l   

for el_U in U_case:    #adding uppercase letters to Dict_of_store
    Dict_of_store[el_U] = j+1
    Dict_of_store_scrap[j+1] = el_U


Dict_of_store[" "]= 53 

inp_main = input("Main: ").strip()
key_main = input("Key: ").strip()

for el_main1 in inp_main:
    inp.append(el_main1)

if len(inp_main)>len(key_main): #checks whether the key is the same length as the main
    for el_main2 in key_main:
        key.append(el_main2)
    while len(key)<len(inp):
        key.append(key[i % len(key)])
        i += 1

elif len(key_main)>len(inp_main):
    for el_main3 in key_main:
        key.append(el_main3)
        if len(key) == len(inp):
            break
else:
    for el_main4 in key_main:
        key.append(el_main4)

for lock,key_elem in zip(inp, key): #encrypting algorithm 
    another = Dict_of_store[lock] + Dict_of_store[key_elem]
    each_element.append(another)
    
for new_main in each_element:
    if new_main > 53:
        num = new_main - 53
        if num in Dict_of_store_scrap:  
            encrypted += Dict_of_store_scrap[num]
        else:
            encrypted += "?"  
    else:
        encrypted += Dict_of_store_scrap[new_main]


print(encrypted)

