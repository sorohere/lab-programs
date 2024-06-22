def stable_match(men_preferences, women_preferences):
    free_men = list(men_preferences.keys())
    engagements = {}

    while free_men:
        man = free_men.pop(0)
        man_prefs = men_preferences[man]
        
        woman = man_prefs.pop(0)
        fiance = engagements.get(woman)

        if not fiance:
            engagements[woman] = man
        else:
            current_fiance_index = women_preferences[woman].index(fiance)
            new_fiance_index = women_preferences[woman].index(man)

            if new_fiance_index < current_fiance_index:
                engagements[woman] = man
                free_men.append(fiance)
            else:
                free_men.append(man)

    return engagements


men_prefs = {
    'm1': ['w1', 'w2', 'w3'],
    'm2': ['w2', 'w3', 'w1'],
    'm3': ['w2', 'w1', 'w3']
}

women_prefs = {
    'w1': ['m2', 'm3', 'm1'],
    'w2': ['m1', 'm2', 'm3'],
    'w3': ['m1', 'm3', 'm2']
}

stableMatches = stable_match(men_prefs, women_prefs)
print("Stable Marriages:")
for woman, man in stableMatches.items():
    print(f"{man} is engaged to {woman}")
