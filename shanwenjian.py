import os

for i in os.walk('.'):
    # print i
    p = i[0]
    print 'p:', p
    for j in range(1, len(i)):
        for k in i[j]:
            print "k", k
            if (k.endswith('.o') or k.endswith('.exe')):
                print p + '\\' + k
                os.remove(p + '\\' + k)
    
