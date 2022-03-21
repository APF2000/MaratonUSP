file = open('teste.txt', 'r')

for line in file:
    count = 0

    lastFirstChar = ''
    wasEqual = False
    #print(line)
    line = line.split(' ')
    for word in line:
        if(not wasEqual and lastFirstChar.lower() == word[0].lower()):
            count += 1
            wasEqual = True
        elif(lastFirstChar.lower() != word[0].lower()):
            wasEqual = False

        lastFirstChar = word[0]
    
    print(count)
    