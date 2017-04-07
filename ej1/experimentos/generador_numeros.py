import random




def randomizado():
    f = open('experimentos.txt', 'w')
    j = 50;
    f.write(str(j)+'\n')
    for i in range(0,j):
        value = random.randint(0,j)
        f.write(str(value)+' ')
    f.write('\n')

def todosiguales():
    f = open('iguales.txt', 'w')
    j = 100;
    f.write(str(j)+'\n')
    for i in range(0,j):
        value = 5
        f.write(str(value)+' ')
    f.write('\n')

todosiguales()
