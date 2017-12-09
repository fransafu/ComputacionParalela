/*
* Programa agrupa los datos por dias y horas
* Read and filter access.log -> rfa
*
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>


using namespace std;

int main(int argc, char *argv[]){

	// Declaracion de variables
	string rfa_usage_string = "rfa [--help] [-C <ruta>] [-semana] [-horas]";
	bool semanaValid = false;
	bool horasValid = false;
	bool rutaValid = false;
	string ruta = "";

	// Filtro de parametros
	if ( argc == 1 ) {
		cout << "Uso:" << endl;
		cout << rfa_usage_string << endl;
	} else {
		for (int i = 0; i < argc; ++i) {
			if (string(argv[i]) == "--help"){
				cout << "Uso:" << endl;
				cout << rfa_usage_string << endl;
				return 0;
			} else if (string(argv[i]) == "-semana"){
	        	semanaValid = true;
	        } else if (string(argv[i]) == "-horas") {
	        	horasValid = true;
	        }
	        if ( string(argv[i]) == "-C" ){
	        	ruta = string(argv[i + 1]);
	        	rutaValid = true;
	        }
	    }
	}

	// Validaciones
	if ( (semanaValid == true && horasValid == true) || (semanaValid == false && horasValid == false) ) {
		cout << "Ejecucion terminada." << endl;
		cout << "Debe seleccionar semana (-semana) o horas (-horas)." << endl;
		cout << "Uso:" << endl;
		cout << rfa_usage_string << endl;
		return 0;
	}
	if (!rutaValid) {
		cout << "Ejecucion terminada." << endl;
		cout << "ruta ingresada: " << ruta << endl;
		cout << "Ingresar ruta correctamente." << endl;
		cout << "Ejemplo: /home/<username>/access.log" << endl;
		cout << rfa_usage_string << endl;
		return 0;
	}

	ifstream file(ruta.c_str());

	if (file.is_open() && !(file.peek() == std::ifstream::traits_type::eof())) {
	    string str;

    	// Declarar variables
	    int contadorDomingo   = 0;
	    int contadorLunes 	  = 0;
	    int contadorMartes 	  = 0;
	    int contadorMiercoles = 0;
	    int contadorJueves    = 0;
	    int contadorViernes   = 0;
	    int contadorSabado    = 0;
    	int contarHoras[24];

	    // Init Array
	    for (int i = 0; i < 24; i++){
	    	contarHoras[ i ] = 0;
	    }

	    while (getline(file, str)){
	    	string str3 = str.substr(0, str.find("]") + 1);
	    	string strTiempo = str3.substr(str.find("["),29);
	    	string tiempoLog = strTiempo.substr(strTiempo.find("[") + 1, strTiempo.find("]") - 1);

			char *cstr = new char[tiempoLog.length() + 1];
            strcpy(cstr, tiempoLog.c_str());
			struct tm tm;
			strptime(tiempoLog.c_str(), "%d/%b/%Y:%H:%M:%S %T%z", &tm);
			time_t t = mktime(&tm);

			struct tm *timePtr;
			timePtr = localtime(&t);

			if (semanaValid) {
				switch( timePtr->tm_wday ) {
					case 0:
				   		contadorDomingo += 1;
				   		break;
				   	case 1:
				   		contadorLunes += 1;
				   		break;
				   	case 2:
				   		contadorMartes += 1;
				   		break;
				   	case 3:
				   		contadorMiercoles += 1;
				   		break;
				   	case 4:
				      	contadorJueves += 1;
				      	break;
				    case 5:
				    	contadorViernes += 1;
				      	break;
				    case 6:
				    	contadorSabado += 1;
						break;
				   	default:
				      	cout << "Error dia: " << timePtr->tm_wday << endl;
				    	break;
				}
			} else if (horasValid) {
				switch( timePtr->tm_wday ) {
					case 0:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 1:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 2:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 3:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 4:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 5:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 6:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 7:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 8:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 9:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 10:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 11:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 12:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 13:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 14:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 15:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 16:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 17:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 18:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 19:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 20:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 21:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 22:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
					case 23:
						contarHoras[ timePtr->tm_hour ] += 1;
						break;
				}
			}
	    }

	    if (semanaValid) {
	    	// Guarda semana
		    ofstream semana;
		    semana.open("semana.csv");
		    semana << "Día;Total\n";
		    semana << "Lunes;" << contadorLunes << "\n";
			semana << "Martes;" << contadorMartes << "\n";
			semana << "Miércoles;" << contadorMiercoles << "\n";
			semana << "Jueves;" << contadorJueves << "\n";
			semana << "Viernes;" << contadorViernes << "\n";
			semana << "Sábado;" << contadorSabado << "\n";
			semana << "Domingo;" << contadorDomingo << "\n";
		    semana.close();
		    cout << "Archivo semana.csv generado." << endl;
	    } else if (horasValid) {
	    	// Guarda Horas
		    ofstream horas;
		    horas.open("horas.csv");
		    horas << "Hora;Total\n";
		    for (int i = 0; i < 24; i++){
		    	horas << i << ";" << contarHoras[ i ] << "\n";
		    }
		    horas.close();
		    cout << "Archivo horas.csv generado." << endl;
	    }
	} else {
		cout << "El archivo no se pudo abrir o se encuentra vacio." << endl;
	}

	cout << "Programa terminado" << endl;

    return 0;
}
