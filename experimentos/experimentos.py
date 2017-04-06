import random




def randomizado():
    f = open('experimentos.txt', 'w')
    for j in range(20,620,20):
        f.write(str(j)+'\n')
        for i in range(0,j):
            value = random.randint(0,j)
            f.write(str(value)+' ')
        f.write('\n')

def todosiguales():
    f = open('iguales.txt', 'w')
    for j in range(20,620,20):
        f.write(str(j)+'\n')
        for i in range(0,j):
            value = random.randint(0,j)
            f.write(str(value)+' ')
        f.write('\n')
