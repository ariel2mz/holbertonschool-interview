#!/usr/bin/python3
def canUnlockAll(boxes):
    llavero = [0]
    abiertas = []
    abierto = 1
    yaabierta = 0

    while abierto == 1:

        for x in range(0,len(boxes)):

            abierto = 0
            for y in abiertas:
                if x == y:
                    yaabierta = 1

            if yaabierta == 0:
                for prueba in llavero:
                    if yaabierta == 0:
                        if prueba == x:
                            for interior in boxes[x]:
                                llavero.append(interior)
                            abiertas.append(x)
                            abierto = 1
                            yaabierta = 1
            yaabierta = 0

    if len(abiertas) == len(boxes):
        return True
    else: 
        return False
    
    