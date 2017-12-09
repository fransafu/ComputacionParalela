#include <iostream>
#include <fstream>



using namespace std;



int main() {

	
	//declarar matriz [filas][columnas]
	int matriz2 [3][6]= {{1,4,5,1,5,1},{4,5,2,4,3,1},{3,4,5,1,3,4}}; 
	ofstream horario; 
	horario.open ("horario.csv");
	horario << "horario" << endl;
	horario << "Lunes ; Martes ; Miercoles ; Jueves ; Viernes ; Sabado" <<endl;
	for (int i = 0; i<8; i++){ //filas
		for (int j=0; j<6; j++){ // columnas
			//cout << matriz2[i][j];
			if(matriz2[i][j]== 1){
				horario << "sherlos ;"<< " "; //matriz2[i][j] << endl;
			}
			else if(matriz2[i][j]== 2){
				horario << "poirot ;" << " "; // matriz2[i][j] << endl;
			}
			else if(matriz2[i][j]== 3){
				horario << "Dupin ;"<< " "; //matriz2[i][j] << endl;
			}
			else if(matriz2[i][j]== 4){
				horario << "Marple ;" << " "; //matriz2[i][j] << endl;
			}
			else if(matriz2[i][j]== 5){
				horario << "Carvalho ;" << " "; //matriz2[i][j] << endl;
			}
		}
		horario << " " << endl;
	}
	horario.close();
	cout << "archivo horario.csv generado"<< endl;

}

