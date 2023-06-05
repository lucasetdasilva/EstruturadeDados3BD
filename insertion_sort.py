def insertion_sort(lista):
    n = len(lista)
    
    for i in range(1,n):
        chave = lista[i] 
        j = i - 1
        while (j >= 0 and lista[j] > chave): 
            lista[j+1] = lista[j]  
            j = j-1 
        lista[j+1] = chave 
    return lista
        
l = [90,9,0,5]
resultado = insertion_sort(l)
print(resultado)
