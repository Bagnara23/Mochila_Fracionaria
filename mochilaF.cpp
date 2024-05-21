#include<iostream>

using namespace std;

int main() {
    int array[2][100], n, C, i, capacidade, usado[100], maxi = -1, pesofinal = 0;
    cout << "Digite a quantidade de objetos: ";
    cin >> n;
    cout << "Digite o capacidade maxima da mochila: ";
    cin >> C;
    
    // Primeira linha da matriz é para armazenar valor segunda linha é para armazenar os pesos.
    for (i = 0; i < n; i++) {
        cin >> array[0][i] >> array[1][i];
    }
    
    for (i = 0; i < n; i++) {
        usado[i] = 0;
    }
    capacidade = C;
    // Encrementa na mochila até que esteja cheia ou proxima de seu limite.
    while (capacidade >= 0) {
        maxi = -1;
        
        //loop para encontrar o objeto de valor máximo
        for (i = 0; i < n; i++) {
            if ((usado[i] == 0) && ((maxi == -1) || (((float) array[1][i]
                    / (float) array[0][i]) > ((float) array[1][maxi]
                    / (float) array[0][maxi])))) {
                maxi = i;
            }
        }
        
        usado[maxi] = 1;

        capacidade -= array[0][maxi]; // Decrementa o peso atual
        pesofinal += array[1][maxi]; // Incrementa valor total
        
        if (capacidade >= 0) {
            cout << "\n Objeto inserido: " << maxi + 1 << " Valor: "
                    << array[0][maxi] << " Peso: " << array[1][maxi]
                    << " Espaco livre na mochila:  " << capacidade;
        } else {
            cout << "\n Objeto inserido: " << maxi + 1 << " Valor: "
                    << (array[0][maxi] + capacidade) << " Peso: "
                    << (array[1][maxi] / array[0][maxi]) * (array[0][maxi]
                            + capacidade) << " Espaco livre na mochila:  0"
                    << "\n\n O peso adicionado eh: " << capacidade + array[0][maxi];
            pesofinal -= array[1][maxi];
            pesofinal += ((array[1][maxi] / array[0][maxi]) * (array[0][maxi]
                    + capacidade));
        }
    }
    
    cout << "\n\n Peso total dos itens inseridos na mochila: " << pesofinal;
    cout << "\n";
    return 0;
}