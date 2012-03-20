import sys

def next(array,limit):
    i=0
    while(array[i]==limit):
        array[i] = 0
        i+=1
        if(i==len(array)):
            return None
    array[i]+=1
    return array

def allWords(alphabet, length):
    letters = [0]*length
    while(letters):
        w = ""
        for i in letters:
            w += alphabet[i]
        letters = next(letters,len(alphabet)-1)
        yield w

alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9']



gLength = int(sys.argv[1])
gMaxRep = int(sys.argv[2])


for i in range(gMaxRep):    
    f = open("hex.py.log","w+"
    f.close()
    for c in allWords(alphabet,gLength):
        print(c*(i+1))
