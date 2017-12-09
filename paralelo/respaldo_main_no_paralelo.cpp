#include <iostream>
#include <string>
#include <stdio.h>
#include <pqxx/pqxx>
#include <vector>

using namespace std;
using namespace pqxx;

vector<vector<std::string> > getQuery(string sql){

    try {
        // Crea la conexión
        connection C("dbname = logicadb user = logica password = distribuida hostaddr = 127.0.0.1 port = 56432");
        // Verifica la conexion 
        if (C.is_open()) {
            cout << "Conexion con la base de datos '" << C.dbname() << "' exitosa!" << endl;
        } else {
            cout << "No se pudo acceder a la base de datos." << endl;
        }

        work w(C); // crea un cursor (?)

        // Ejecutamos la consulta y se guarda en la variable 'r'
        result r = w.exec(sql);

        // Creamos un vector auxiliar para juntar la informacion de cada fila (junta las columnas de una fila en un solo vector)
        vector<std::string> vectorAux;

        // Creamos el vector que va a contener el otro vector, de esta forma hacemos una matriz
        // Quedaria algo como esto: matrizAux = [vectorAux, vectorAux, ..., vectorAux]
        vector<vector<std::string> > matrizAux;

        // Iteramos la consulta fila por fila
        for (result::const_iterator row = r.begin(); row != r.end(); ++row) {
            vectorAux.clear(); // limpia vector auxiliar para cargar nuevos datos sin que esten los anteriores
            for (result::tuple::const_iterator field = row->begin(); field != row->end(); ++field){ // Itera columna por columna de una sola fila
                vectorAux.push_back(field->c_str()); // llena vector
                // std::cout << field->c_str() << ' '; // Esto imprime las columnas de cada fila
            }
            // Adjunta el vector a la matriz (ver imagen de referencia)
            matrizAux.push_back(vectorAux);
        }

        cout << "Operacion finalizada" << endl;
        return matrizAux;
        C.disconnect (); // Cierra la conexion con la base de datos
    } catch (const std::exception &e) {
        // Este bloque se ejecuta si hay un error con la conexion de la base de datos
        cerr << e.what() << std::endl;
    }
}

int commitInsert(string sql){
    try {
        connection C("dbname = logicadb user = logica password = distribuida hostaddr = 127.0.0.1 port = 56432");
        // Verifica la conexion 
        if (C.is_open()) {
            cout << "Conexion con la base de datos '" << C.dbname() << "' exitosa!" << endl;
        } else {
            cout << "No se pudo acceder a la base de datos." << endl;
            return 0;
        }

        work W(C);

        W.exec( sql );
        W.commit();
        cout << "INSERT EJECUTADO CORRECTAMENTE" << endl;
        C.disconnect ();
        return 1;
    } catch (const std::exception &e) {
        cerr << e.what() << std::endl;
        return 0;
    }
}

int updateCommit(string sql){
    try {
        connection C("dbname = logicadb user = logica password = distribuida hostaddr = 127.0.0.1 port = 56432");

        // Verifica la conexion 
        if (C.is_open()) {
            cout << "Conexion con la base de datos '" << C.dbname() << "' exitosa!" << endl;
        } else {
            cout << "No se pudo acceder a la base de datos." << endl;
            return 0;
        }

        work W(C);

        W.exec( sql );
        W.commit();
        cout << "UPDATE EJECUTADO CORRECTAMENTE" << endl;
        C.disconnect ();
        return 1;
    } catch (const std::exception &e) {
        cerr << e.what() << std::endl;
        return 0;
    }
}

int main() {

    updateCommit("UPDATE accesos_paralelos SET disponible = false");


    vector<vector<std::string> > matrizDocentes;
    matrizDocentes = getQuery("SELECT id, bloques FROM docentes ORDER BY bloques asc");

    vector<vector<std::string> > matrizDisponibilidadDocentes;
    matrizDisponibilidadDocentes = getQuery("SELECT docente_id, periodo_id, dia, id FROM disponibilidad_docentes order by docente_id, periodo_id");

    vector<vector<std::string> > matrizDisponibilidadSalas;
    matrizDisponibilidadSalas = getQuery("SELECT s.nombre as nombre_sala, \
                                                 ds.dia as dia, \
                                                 ds.periodo_id as periodo, \
                                                 ds.libre as libre, \
                                                 ds.id as disponibilidad_salas_id \
                                                 FROM disponibilidad_salas ds INNER JOIN salas s \
                                                 ON ds.sala_id = s.id");

    vector<vector<std::string> > matrizHorario;
    matrizHorario = getQuery("SELECT c.id as curso_id, \
                                    c.docente_id as docente_id, \
                                    h.libre as libre_horario \
                                    FROM cursos c INNER JOIN docentes d \
                                    ON c.docente_id = d.id INNER JOIN horarios h \
                                    ON h.curso_id = c.id \
                                    WHERE h.libre = 't'");

    vector<vector<std::string> > matrizListaDisponibilidadDocente_docente_id;
    matrizListaDisponibilidadDocente_docente_id = getQuery("select docente_id \
                                                            from disponibilidad_docentes \
                                                            group by docente_id \
                                                            order by count(periodo_id) asc");

    vector<vector<std::string> > matrizListaDocentesHorario;
    matrizListaDocentesHorario = getQuery("SELECT d.id, h.id, h.libre \
                                            FROM cursos c INNER JOIN docentes d \
                                            ON c.docente_id = d.id \
                                            INNER JOIN horarios h \
                                            ON h.curso_id = c.id \
                                            WHERE h.libre = 't' \
                                            GROUP BY d.id, h.id \
                                            ORDER BY d.id, h.id ASC");

    
    // Llena una lista con los id de los docentes con menos disponibilidad primero (asc)
    std::vector<std::string> vectorStringDocente_id;
    for (int i = 0; i < matrizListaDisponibilidadDocente_docente_id.size(); i++){ // Itera fila por fila
        for (int j = 0; j < matrizListaDisponibilidadDocente_docente_id[i].size(); j++){ // itera columna por columna
            vectorStringDocente_id.push_back(matrizListaDisponibilidadDocente_docente_id[i][j]);
        }
    }

    // 1.- Recorrer disponibilidad salas
    // 2.- Recorrer disponibilidad docentes
    // 3.- Match entre 1 y 2
    // 4.- 
    // 2.- iterar vectorStringDicente_id para recorrer los id de los docentes que tienen menor disponibilidad primero
    // 3.- iterar docentes que concidan con menor disponibilidad
    // 4.- discriminar docentes con mayor a 39 bloques
    // 5.- consultar disponibilidad de docente y consultar disponibilidad sala

    int num_bloques;
    int num_tmp;
    bool terminarHorario = false;

    for (int indice5 = 0; indice5 < matrizDisponibilidadSalas.size(); indice5++){ // Itera fila por fila
        cout << matrizDisponibilidadSalas[indice5][1] << endl; // DIA
        cout << matrizDisponibilidadSalas[indice5][2] << endl; // PERIODO
        if ( matrizDisponibilidadSalas[indice5][3] == "t" ) { // Valida que la sala este disponible en el dia y en el periodo
            cout << "Entra" << endl;
            for (int indice3 = 0; indice3 < matrizDocentes.size(); indice3++){ // Recorrer docentes con menos bloques
                for (int indice4 = 0; indice4 < matrizDisponibilidadDocentes.size(); indice4++){ // Recorre las disponibilidades del docente
                    cout << "entra 2 " << endl;
                    if ( matrizDisponibilidadDocentes[indice4][0] == matrizDocentes[indice3][0] ){
                        if ( matrizDisponibilidadDocentes[indice4][1] == matrizDisponibilidadSalas[indice5][2] && matrizDisponibilidadDocentes[indice4][2] == matrizDisponibilidadSalas[indice5][1]) {
                            for ( size_t indice = 0 ; indice < matrizListaDocentesHorario.size() ; indice++ ){
                                if ( matrizListaDocentesHorario[indice][3] == "t"){
                                    matrizDocentes[indice3][1] = to_string( num_tmp - 1 );
                                    matrizDisponibilidadSalas[indice5][3] = "f";

                                    terminarHorario = true;
                                    string query1 = "INSERT INTO asignaciones(disponibilidad_sala_id, created_at, updated_at, horario_id, disponibilidad_docente_id) VALUES (" + matrizDisponibilidadSalas[indice5][4] + ", (SELECT now()::timestamp), (SELECT now()::timestamp), " + matrizListaDocentesHorario[indice][1] + ", " + matrizDisponibilidadDocentes[indice4][3] + ")";
                                    string query2 = "UPDATE disponibilidad_salas SET libre = false WHERE disponibilidad_salas.id = " + matrizDisponibilidadSalas[indice5][4];
                                    string query3 = "UPDATE horarios SET libre = false WHERE horarios.id = " + matrizListaDocentesHorario[indice][1];
                                    string query4 = "UPDATE docentes SET updated_at = (SELECT now()::timestamp), bloques = " + to_string( num_tmp - 1 ) + " WHERE docentes.id = " + matrizDisponibilidadDocentes[indice4][0];
                                    
                                    cout << query1 << endl;
                                    commitInsert(query1);
                                    cout << query2 << endl;
                                    updateCommit(query2);
                                    cout << query3 << endl;
                                    updateCommit(query3);
                                    cout << query4 << endl;
                                    updateCommit(query4);
                                }
                                if (terminarHorario){
                                    break;
                                }
                            }

                        }
                    }
                    terminarHorario = false;
                }
            }
        }
    }

    updateCommit("UPDATE accesos_paralelos SET disponible = true");

/*
    for ( size_t indice2 = 0 ; indice2 < vectorStringDocente_id.size() ; indice2++ ){
        for ( size_t indice = 0 ; indice < matrizListaDocentesHorario.size() ; indice++ ){
            if ( vectorStringDocente_id[indice2] == matrizListaDocentesHorario[indice][0]){

                for (int indice3 = 0; indice3 < matrizDocentes.size(); indice3++){ // Itera fila por fila
                    if (matrizDocentes[indice3][0] == matrizListaDocentesHorario[indice][0]){
                        istringstream ( matrizDocentes[indice3][1] ) >> num_bloques;
                        if ( num_bloques <= 39){// Filtra que el docente no tenga mas de los bloques semanales disponibles
                            for (int indice4 = 0; indice4 < matrizDisponibilidadDocentes.size(); indice4++){
                                if ( matrizDisponibilidadDocentes[indice4][0] == matrizDocentes[indice3][0] ){ // filtra el id docente
                                    for (int indice5 = 0; indice5 < matrizDisponibilidadSalas.size(); indice5++){ // Itera fila por fila
                                        if ( matrizDisponibilidadSalas[indice5][3] == "t" ) { // Valida que la sala este disponible en el dia y en el periodo
                                            istringstream (matrizDocentes[indice3][1]) >> num_tmp;
                                            if ( matrizDisponibilidadDocentes[indice4][2] == matrizDisponibilidadSalas[indice5][1] && matrizDisponibilidadDocentes[indice4][1] == matrizDisponibilidadSalas[indice5][2] && num_tmp > 0){

                                                matrizDocentes[indice3][1] = to_string( num_tmp - 1 );
                                                matrizDisponibilidadSalas[indice5][3] = "f";

                                                terminarHorario = true;
                                                string query1 = "INSERT INTO asignaciones(disponibilidad_sala_id, created_at, updated_at, horario_id, disponibilidad_docente_id) VALUES (" + matrizDisponibilidadSalas[indice5][4] + ", (SELECT now()::timestamp), (SELECT now()::timestamp), " + matrizListaDocentesHorario[indice][1] + ", " + matrizDisponibilidadDocentes[indice4][3] + ")";
                                                string query2 = "UPDATE disponibilidad_salas SET libre = false WHERE disponibilidad_salas.id = " + matrizDisponibilidadSalas[indice5][4];
                                                string query3 = "UPDATE horarios SET libre = false WHERE horarios.id = " + matrizListaDocentesHorario[indice][1];
                                                string query4 = "UPDATE docentes SET updated_at = (SELECT now()::timestamp), bloques = " + to_string( num_tmp - 1 ) + " WHERE docentes.id = " + matrizDisponibilidadDocentes[indice4][0];

                                                // cout << query1 << endl;
                                                commitInsert(query1);
                                                // cout << query2 << endl;
                                                updateCommit(query2);
                                                // cout << query3 << endl;
                                                updateCommit(query3);
                                                // cout << query4 << endl;
                                                updateCommit(query4);

                                            }
                                        }
                                        if (terminarHorario){
                                            break;
                                        }
                                    }
                                }
                                if (terminarHorario){
                                    break;
                                }
                            }
                        }//  else {
                        //     cout << "Docente sobre pasa el numero de bloques permitidos en una semana (39)" << endl;
                        //     cout << "ID docente en matrizListaDocentesHorario: " << matrizListaDocentesHorario[indice][0] << endl;
                        //     cout << "ID docente en matrizDocentes: " << matrizDocentes[indice3][0] << endl;
                        //     cout << "ID horario en matrizListaDocentesHorario: " << matrizListaDocentesHorario[indice][1] << endl;
                        // }
                    }
                    if (terminarHorario){
                        break;
                    }
                }
                terminarHorario = false;
            }
        }
    }
*/
}
