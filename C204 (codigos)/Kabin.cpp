#include <iostream>
#include <cmath>
#include <cstring>



using namespace std;



void rabin_karp(char T[], char P[], int tamT, int tamP, int d, int q)
{



	int h; // valor utilizado para calculo de hash
	int p = 0; // padrao convertido para inteiro
	int t = 0; // texto convertido para inteiro
	int soma = 0; //soma de numero de vezes que o numero é encontrado
	int pos;//posição do que eu quero procurar
	for(int i = 0; i < tamP; i++)
	{
		p = (d * p + (P[i] - '0')) % q; // converte o padrao
		t = (d * t + (T[i] - '0')) % q; // converte o texto para o primeiro valor (t0)
	}



	h = (int)pow(d, tamP - 1) % q; // utilizado para calculo de hash



	for(int i = 0; i <= tamT - tamP; i++)
	{
		if(p == t) // Se encontrei um valor de hash valido
		{
			// Verifico se ha diferencas
			int j;
			for(j = 0; j < tamP; j++)
			{
				if(P[j] != T[i + j])
				{
					break;//mismatch
				}
			}
			if(j == tamP)
			{
				soma++;
				pos = i;
			}//encontrei
		}
		if(i < tamT - tamP) // se ainda nao cheguei no final
		{
			t = (d * ( t - (T[i] - '0') * h ) + (T[i + tamP] - '0')) % q; // atualizo o ti para ti+1
			if(t < 0) t += q;
		}
		else
		{
			if(soma > 0)
			{
				cout << "Ultima ocorrencia: " << pos << endl;
				cout << soma << " ocorrencia(s)" << endl;
			}
			else
			{
				cout << "0 ocorrencia(s)" << endl;
			}
		}
	}



}



int main()
{



	char texto[100];
	char padrao[100];
	char tamanho[100];
	char tamanhop[100];
	// cardinalidade do alfabeto usado no texto, em outras palavras, qtd de caracteres diferentes utilizados
	int d = 10;
	// número primo grande, para calcular os valores no hash
	int q = 13;
	int t = 10;
	int p = 10;
	cin >> tamanho;
	cin >> tamanhop;
	cin >> texto;
	cin >> padrao;
	rabin_karp(texto, padrao, strlen(texto), strlen(padrao), d, q);
	return 0;
}
