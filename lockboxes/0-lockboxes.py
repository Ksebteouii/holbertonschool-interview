def canUnlockAll(boxes):
    n = len(boxes)  
    unlocked = [False] * n  
    unlocked[0] = True  
    keys = set(boxes[0])  
    keys.add(0)  # Add the key for the first box

    
    while keys:
        new_key = keys.pop() 
        if not unlocked[new_key]:
            
            unlocked[new_key] = True
           
            for key in boxes[new_key]:
                if key < n:  
                    keys.add(key)
    
   
    return all(unlocked)