def selectionsort(lista):
    n = len(lista)
    for i in range(n-1,0,-1):
        maximo = 0
        for j in range(1,i+1):
            if(lista[maximo] < lista[j]):
                maximo = j
        lista[maximo],lista[i] = lista[i],lista[maximo]
    return lista    

flag = True
while (flag == True):
    print("BEM - VINDO(A) DISTRIBUIDORA DE PRODUTOS")
    print("Vamos organizar os pedidos\n")
    lista = []
    x = int(input("Digite a quantidade de pedidos:"))
    numero = 0
    for t in range(0,x):
        numero = int(input(f"Digite o id do pedido: "))
        lista.append(numero)
    
    resultado = selectionsort(lista)
    print("A ordenação ficou assim: ", resultado,"\n")
    
    escolha = str(input("Deseja continuar: S ou N\n"))
    
    if(escolha == "S" or escolha == "s"):
        flag = True
    else:
        flag = False
    
