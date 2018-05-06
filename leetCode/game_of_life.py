
# Rules:
# 1. DEATH happens: any live cell with fewer than 2 live neighbors (cause underpopulation
# 2. DEATH happens: any live cell with more than 3 live neighbors (overpopulation)
# 3. SURVIVAL happens: any live cell with 2 or 3 live neighbors survives for next generation.
# 4. RE-BIRTH happens: any dead cell with exactly 3 live neighbors become alive

# SEED : Initial pattern

# Births & Deaths happen simultaneously
# TICK: the descrete moment when birth and death happens


# Python Implementation:
def compute_gen_score(Z):
    shape = len(Z), len(Z[0]) #(rows, cols) == (y,x)
    score = [[0,]*(shape[0]) for i in range(shape[1])]
    for x in range(1, shape[1]-1):
        for y in range(1, shape[0]-1):
            score[x][y] = Z[x-1][y-1] + Z[x][y-1] + Z[x+1][y-1] + \
                            Z[x-1][y] + Z[x+1][y] + \
                            Z[x-1][y+1] + Z[x][y+1] + Z[x+1][y+1]
    
#     print(score)
    return score

#---------------
def iterate(Z):
    score = compute_gen_score(Z)
    
    for x in range(len(Z[0])-1):
        for y in range(len(Z)-1):
            if Z[x][y] == 1 and (score[x][y] < 2 or score[x][y] > 3):
                ### death
                Z[x][y] = 0
            elif Z[x][y] == 0 and score[x][y] == 3:
                ### rebirth
                Z[x][y] = 1
    return Z
    
    
    
# Numpy Implementation
def game_of_life(Z):
    Z = np.array(Z)    #converting a list-of-list into numpy array if not already done
    scores = np.zeros(Z.shape, np.int)
    scores[1:-1, 1:-1] += Z[ :-2, :-2] + Z[ :-2, 1:-1] + Z[ :-2, 2: ] + \
                            Z[1:-1, :-2] +                 Z[1:-1, 2: ] + \
                            Z[2:  , :-2] + Z[2:  , 1:-1] + Z[ 2: , 2: ]
    
    Z_flat = Z.ravel()
    scores_flat = scores.ravel()
    
    #Death
    Rule1 = np.argwhere((Z_flat == 1) & (scores_flat < 2))
    Rule2 = np.argwhere((Z_flat == 1) & (scores_flat > 3))
    #Survival
    Rule3 = np.argwhere((Z_flat == 1) & ((scores_flat == 2) | (scores_flat == 3)))
    #Birth or Re-birth
    Rule4 = np.argwhere((Z_flat == 0) & (scores_flat == 3))
    
    # Assigning states for next geneeration
    Z_flat[Rule1] = 0
    Z_flat[Rule2] = 0
    Z_flat[Rule3] = Z_flat[Rule3]
    Z_flat[Rule4] = 1
    
    Z_recovered = Z_flat.reshape(Z.shape)
    return Z_recovered
    
    
def game_of_life2(Z):
    Z = np.array(Z)
    scores = np.zeros(Z.shape, np.int)
    scores[1:-1, 1:-1] += Z[ :-2, :-2] + Z[ :-2, 1:-1] + Z[ :-2, 2: ] + \
                            Z[1:-1, :-2] +                 Z[1:-1, 2: ] + \
                            Z[2:  , :-2] + Z[2:  , 1:-1] + Z[ 2: , 2: ]
    birth = (scores == 3)[1:-1,1:-1] & (Z[1:-1,1:-1] == 0)
    survival = ((scores == 2) | (scores == 3))[1:-1,1:-1] & (Z[1:-1,1:-1] == 1)
    Z[...] = 0    # seting all elements of the upcoming generation to be zero
    Z[1:-1,1:-1][birth | survival] = 1
    return Z