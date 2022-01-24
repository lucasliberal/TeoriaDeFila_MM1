#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float n_ClientesNoSistema(float p, int n){
    float pn = (1-p)*pow(p,n);
    return pn;
}

float n_maisClientesNoSistema(float p, int n){
    float pn = pow(p, n);
    return pn;
}

float n0_ClientesNaFila(float p){
    float pn = 1 - pow(p, 2);
    return pn;
}

float nMedio_ClientesNoSistema(float mi, float lambda){
    float En = lambda/(mi-lambda);
    return En;
}

float nMedio_ClientesNaFila(float lambda, float mi){
    float Enq = pow(lambda,2)/(mi*(mi-lambda));
    return Enq;
}

float nMedio_ClientesEmServico(float p){
    float Ens=p;
    return Ens;
}

float tempoMedio_RespostaDoSistema(float mi, float p){
    float Er = 1/(mi*(1-p));
    return Er;
}

float tempoMedio_EsperaNaFila(float p, float mi){
    float Ew = p/(mi*(1-p));
    return Ew;
}

float tempoMedio_ClientesEmServico(float mi){
    float Es=1/mi;
    return mi;
}

void menu(float lambda, float mi, float p){
    printf("\n======================= MENU =========================\n");
    printf("| 1 - Prob. de ter n Clientes no Sistema          Pn |\n");
    printf("| 2 - Prob. de n ou mais Clientes no Sistema  P(>=n) |\n");
    printf("| 3 - Prob. de ter 0 Clientes na Fila        P(nq=0) |\n");
    printf("| 4 - Numero medio de Clientes no Sistema       E[n] |\n");
    printf("| 5 - Numero medio de Clientes na Fila         E[nq] |\n");
    printf("| 6 - Numero medio de Clientes em Servico      E[ns] |\n");
    printf("| 7 - Tempo medio de resposta do Sistema        E[r] |\n");
    printf("| 8 - Tempo medio de espera na Fila             E[w] |\n");
    printf("| 9 - Tempo medio de Clientes em Servico        E[s] |\n");
    printf("======================================================\n");
    printf("\n   lambda=%.2f    ||    mi=%.2f    ||    p=%.2f\n", lambda, mi, p);
}

float index_menu(int index, float lambda, float mi, float p){
    if (index == 1){
        int n;
        printf("Digite o valor de n: "); scanf("%d", &n);
        printf("%.2f", n_ClientesNoSistema(p, n));
        return 0;
    }
    if (index == 2){
        int n;
        printf("Digite o valor de n: "); scanf("%d", &n);
        printf("%.2f", n_maisClientesNoSistema(p, n));
        return 0;
    }
    if (index == 3){
        printf("%.2f", n0_ClientesNaFila(p));
        return 0;
    }
    if (index == 4){
        printf("%.2f", nMedio_ClientesNoSistema(mi, lambda));
        return 0;
    }
    if (index == 5){
        printf("%.2f", nMedio_ClientesNaFila(lambda, mi));
        return 0;
    }
    if (index == 6){
        printf("%.2f", nMedio_ClientesEmServico(p));
        return 0;
    }
    if (index == 7){
        printf("%.4f", tempoMedio_RespostaDoSistema(mi, p));
        return 0;
    }
    if (index == 8){
        printf("%.4f", tempoMedio_EsperaNaFila(p, mi));
        return 0;
    }
    if (index == 9){
        printf("%.4f", tempoMedio_ClientesEmServico(mi));
        return 0;
    }
    if (index == 0){
        return 2;
    }
}

int main(){
    system("color 0a");
    int index;
    int resp, resp2;
    float mi, lambda, p;

    do{
        system("cls");
        printf("Digite o valor de lambda: "); scanf("%f", &lambda);
        printf("Digite o valor de mi: "); scanf("%f", &mi);
        p = lambda / mi; printf("p = %.2f\n", p);

        do{
            system("cls");
            menu(lambda, mi, p);
            printf("\n=> Opcao: "); scanf("%d", &index); printf("\n");
            index_menu(index, lambda, mi, p);
            printf("\n\n\nDigite 1 para CONTINUAR ou 0 para SAIR: ");
            scanf("%d", &resp);
        } while(resp == 1);
        system("cls");
        printf("Digite 1 para ALTERAR VALORES ou 0 para FECHAR PROGRAMA: "); scanf("%d", &resp2);
    }while(resp2 == 1);

    return 0;
}
