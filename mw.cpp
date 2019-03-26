#include <bits/stdc++.h>

using namespace std;

// vazio: 0;
// agente: 1;
// brisa: 2;
// cheiro: 3;
// buraco: 4;
// ouro: 5;
// wunpus: 6;

int aux = 0;
int posi,posj;

// cima,direita,baixo,esquerda;
int ganho[4] = {0,0,0,0};
// Mapa;
int mapa[4][4] = {3,0,2,4,
				  6,5,4,2,
				  3,0,2,0,
				  1,2,4,2};
int mapainicial[4][4] = {3,0,2,4,
				  		 6,5,4,2,
				  		 3,0,2,0,
				  		 0,2,4,2};
// Valor:
int valor[7] = {0,0,-1,-5,-100,1000,-1000};
// Visitou:
int visitou[4][4] = {0,0,0,0,
				 	 0,0,0,0,
				 	 0,0,0,0,
				 	 0,0,0,0};
int pos[4][4] = {0,0,0,0,
				 0,0,0,0,
				 0,0,0,0,
				 1,0,0,0};

void explicaJogo(){
	cout << "Mapa:" << endl;
	cout << "_________" << endl;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			cout << "|" << mapa[i][j];
			if(j==3)
				cout << "|";
		}
		cout << endl;
	}
	cout << "---------" << endl << endl;
	cout << "legenda:" << endl << endl;
	cout << "Vazio: 0" << endl;
	cout << "Agente: 1" << endl;
	cout << "Brisa: 2" << endl;
	cout << "Cheiro: 3" << endl;
	cout << "Buraco: 4" << endl;
	cout << "Ouro: 5" << endl;
	cout << "Wunpus: 6" << endl << endl;
}

void mostraJogo(){
	cout << "Estado atual:" << endl << endl;
	cout << "_________" << endl;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			cout << "|" << mapa[i][j];
			if(j==3)
				cout << "|";
		}
		cout << endl;
	}
	cout << "---------" << endl << endl;
}

void calculaGanho(){
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			if(pos[i][j]==1){
				posi=i;
				posj=j;
			}
		}
	}
	// Cima;
	if(posi-1>=0){
		int g = mapa[posi-1][posj];
		ganho[0] = valor[g];
	}
	else
		ganho[0] = -100;
	// Direita;
	if(posj+1<4){
		int g = mapa[posi][posj+1];
		ganho[1] = valor[g];
	}
	else
		ganho[1] = -100;
	// Baixo;
	if(posi+1<4){
		int g = mapa[posi+1][posj];
		ganho[2] = valor[g];
	}
	else
		ganho[2] = -100;
	// Esquerda;
	if(posj-1>=0){
		int g = mapa[posi][posj-1];
		ganho[3] = valor[g];
	}
	else
		ganho[3] = -100;
}

void move(int p, int i, int j){
	pos[i][j] = 0;
	mapa[i][j] = mapainicial[i][j];
	if(p==0){
		mapa[i-1][j] = 1;
		pos[i-1][j] = 1;
		posi = i-1;
		posj = j;
	}
	else if(p==1){
		mapa[i][j+1] = 1;
		pos[i][j+1] = 1;
		posi = i;
		posj = j+1;
	}
	else if(p==2){
		mapa[i+1][j] = 1;
		pos[i+1][j] = 1;
		posi = i+1;
		posj = j;
	}
	else{
		mapa[i][j-1] = 1;
		pos[i][j-1] = 1;
		posi = i;
		posj = j-1;
	}
}

void ouro(){
	cout << "Parabéns! O agente encontrou o ouro!" << endl << endl;
}

void joga(){
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			if(pos[i][j]==1){
				posi=i;
				posj=j;
			}
		}
	}
	while(posi != 1 || posj != 1){
		cout << "posi: " << posi << endl << "posj: " << posj << endl << endl;
		++aux;
		if(aux==5)
			return;
		visitou[posi][posj] = 1;
		/*/////////////////////////////////////////////
		cout << "Visitou:" << endl << endl;
		cout << "_________" << endl;
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				cout << "|" << visitou[i][j];
				if(j==3)
					cout << "|";
			}
			cout << endl;
		}
		cout << "---------" << endl << endl;
		/////////////////////////////////////////////
		cout << "posição do agente:" << endl << endl;
		cout << "_________" << endl;
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				cout << "|" << pos[i][j];
				if(j==3)
					cout << "|";
			}
			cout << endl;
		}
		cout << "---------" << endl << endl;
		/////////////////////////////////////////////*/
		calculaGanho();
		cout << "Ganho:" << endl; 
		for(int i=0;i<4;++i)
			cout << ganho[i] << ",";
		cout << endl << endl;
		int p = 0, max = -10000;

		for(int i=0;i<4;++i){
			if(ganho[i] > max && ganho[i] != -100){
				max = ganho[i];
				p = i;
			}
		}
		move(p,posi,posj);
		mostraJogo();
	}
	ouro();
}

void fimdeJogo(){
	cout << "FIM DE JOGO" << endl << endl;
	cout << "Deseja jogar novamente(pressione 1 para SIM e 0 para NÃO)?" << endl << endl;
	int jogo = 0;
	cin >> jogo;
	while(jogo > 1 || jogo < 0){
		cout << "Valor inválido, selecione de novo:" << endl << endl;
		cin >> jogo;
	}
	if(jogo == 1){
		explicaJogo();
		joga();
	}
	else
		cout << "Adeus!" << endl << endl;
}

int main(){
	explicaJogo();
	joga();
	return 0;
}