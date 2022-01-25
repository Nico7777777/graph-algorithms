MAXIM_NODURI = int(500)
MAXIM_MUCHII = int( MAXIM_NODURI*(MAXIM_NODURI-1)//2 )
componenta_conexa = [int(i) for i in range(MAXIM_NODURI + 1)]
n = 0
m = 0
LISTA_MUCHII = []
MST = []

def sortare_muchii()->None:#sortarea se face duap greutatea sa, a muchiei
    global m, LISTA_MUCHII
    for i in range(m):
        j = int(i) - 1
        val = LISTA_MUCHII[i]
        while(j>=0 and val[2]<LISTA_MUCHII[j][2]):
            LISTA_MUCHII[j+1] = LISTA_MUCHII[j]
            #sau asa
            #LISTA_MUCHII[j][0], LISTA_MUCHII[j][1], LISTA_MUCHII[j][2] = LISTA_MUCHII[j+1][0], LISTA_MUCHII[j+1][1], LISTA_MUCHII[j+1][2]
            LISTA_MUCHII[j] = val
            j -= 1

def init()->None:
    global n, m, LISTA_MUCHII
    n = int(input("n= "))
    m = int(input("m= "))
    for i in range(m):
        x, y, w = map( int, input().split() )
        LISTA_MUCHII.append( [x, y, w] ) #x si y sunt nodurile in care intra muchia
                                        #iar w este greutatea muchiei
def unire_componente(minim:int, maxim:int)->None:
    global componenta_conexa
    for i in range(1, n+1):
        if componenta_conexa[i] == maxim:
            componenta_conexa[i] = minim
def print_solution()->None:
    for el in MST:
        print(el)

if __name__=="__main__":
    init()
    sortare_muchii()
    print("Lista muchiilor: ")
    for i in LISTA_MUCHII:
        print(i)
    nr_muchii_selectate = 0
    for muchie in LISTA_MUCHII:
        if nr_muchii_selectate == n-1:
            break
        if( componenta_conexa[ muchie[0] ] != componenta_conexa[ muchie[1] ] ):
            print("\nAm ales muchia " + str(muchie[0]) + "-" + str(muchie[1]) + "=" + str(muchie[2]) )
            unire_componente( componenta_conexa[ min(muchie[0], muchie[1])], max(muchie[0], muchie[1]) )
            print("Componente:", end="")
            for i in range(1, n+1):
                print( componenta_conexa[i], end=" ")
            print("-------------------------------------------")
            MST.append(muchie)
            nr_muchii_selectate += 1
    print_solution()