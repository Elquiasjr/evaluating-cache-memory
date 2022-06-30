function plotGrafico()
 arq = fopen('tempo.txt', 'r');
 if(arq == -1)
    printf('Erro: nao foi possivel abrir o arquivo');
    return;
 endif
tamanho = fscanf(arq, '%d', [1 1]);
indices = fscanf(arq, '%f %f %f', [3 tamanho]);
indices = indices';

fclose(arq);

x = indices(:,1); 
y = indices(:,2);
z = indices(:,3);

plot(x,y,'r',x,z,'b');
xlabel("Tamanhos");
ylabel("Tempo em milissegundos");
title("Graficos desempenho de cache");

endfunction
