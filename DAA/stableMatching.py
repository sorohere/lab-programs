#  Time Complexity: O(n^2) where n is the number of elements in the input array.

def Smatch(Mpreference, Wpreference):
    free_men = list(men_prefs.keys())
    matching = {}
    
    while free_men:
        man = free_men.pop(0)
        man_pref = Mpreference[man]
        
        woman = man_pref.pop(0)
        woman_pref = Wpreference[woman]
        curr = matching.get(woman)
        
        if not curr:
            matching[woman] = man
        else:
            if woman_pref.index(man) < woman_pref.index(curr):
                matching[woman] = man
                free_men.append(curr)
            else:
                free_men.append(man)
                
    return matching


men_prefs = {}
women_prefs = {}

num = int(input("enter no. of mens/womens: "))

print("Enter mens preference")
for i in range(num):
    ans = input(f"Enter the man {i+1} followed by his pref: ").split()
    men_prefs[ans[0]] = ans[1:]
    
print("Enter women preference")
for i in range(num):
    ans = input(f"Enter the women {i+1} followed by her pref: ").split()
    women_prefs[ans[0]] = ans[1:]

stableMatches = Smatch(men_prefs, women_prefs)

print("Stable Marriages:")
for woman, man in stableMatches.items():
    print(f"{man} - {woman}")


# men_prefs = {
#     'm1': ['w1', 'w2', 'w3'],
#     'm2': ['w2', 'w3', 'w1'],
#     'm3': ['w2', 'w1', 'w3']
# }

# women_prefs = {
#     'w1': ['m2', 'm3', 'm1'],
#     'w2': ['m1', 'm2', 'm3'],
#     'w3': ['m1', 'm3', 'm2']
# }
