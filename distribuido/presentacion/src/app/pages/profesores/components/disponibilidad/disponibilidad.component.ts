import { Component } from '@angular/core';
import { ProfesoresServices } from '../../../../services/profesores.services';
import { PeriodoServices } from '../../../../services/periodo.services';
import { DisponibilidadDocentesServices } from '../../../../services/disponibilidadDocentes.services';

@Component({
  selector: 'disponibilidad-profesores',
  templateUrl: './disponibilidad.component.html',
  styleUrls: ['./disponibilidad.component.scss'],
  providers: [ ProfesoresServices, PeriodoServices, DisponibilidadDocentesServices ]
})

export class Disponibilidad {
	public profesores;
  public periodos;
  public disponibilidadDocentes;
  public dias: any[] = ["LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO"];
  public mostrarHorario: boolean = false;
  public profesor;
  public things: any[][];
  public horarioProfesorMatriz: any[][];
  public datosProfesor: any[] = [];
  public bloques: any[] = [];

  // Datos del profesor para validaciones
  public profeActual;
  public profeBloqueActual;
  public profeRutActual;
  public profeId;

  constructor(private _profesoresService: ProfesoresServices, 
              private _periodoService: PeriodoServices,
              private _disponibilidadDocentesService: DisponibilidadDocentesServices) {
    // Inicializar matriz
    this.things = [];

    for(var i: number = 0; i < 7; i++) {
        this.things[i] = [];
        for(var j: number = 0; j< 7; j++) {
          if ( j == 0){
            this.things[i][j] = (i + 1);
          } else {
            this.things[i][j] = "";
          }
        }
    }

    this.horarioProfesorMatriz = [];

    for(var i: number = 0; i < 7; i++) {
        this.horarioProfesorMatriz[i] = [];
        for(var j: number = 0; j< 7; j++) {
          if ( j == 0){
            this.horarioProfesorMatriz[i][j] = (i + 1);
          } else {
            this.horarioProfesorMatriz[i][j] = "";
          }
        }
    }
  }

  ngOnInit(){
    console.log("ngOnInit");
    this.cargarDatos();
  }

  cargarDatos(){
    console.log("Cargar Datos");
    this._profesoresService.getProfesores().subscribe(
      result => {
        this.profesores = result;
        // console.log(this.profesores);
        if (!this.profesores){
          console.log("Error en Query profesores server");
        }
      },
      error => {
        var errorMessage = <any>error;
        console.log(errorMessage);
      }
    );

    this._periodoService.getPeriodos().subscribe(
      result => {
        this.periodos = result;
        //console.log(this.periodos);
        if (!this.periodos){
          console.log("Error en Query periodos server");
        }
      },
      error => {
        var errorMessage = <any>error;
        console.log(errorMessage);
      }
    );

    this._disponibilidadDocentesService.getDisponibilidadDocentes().subscribe(
      result => {
        this.disponibilidadDocentes = result;
        //console.log(this.disponibilidadDocentes);
        if (!this.disponibilidadDocentes){
          console.log("Error en Query periodos server");
        }
      },
      error => {
        var errorMessage = <any>error;
        console.log(errorMessage);
      }
    );
    console.log("Termina Cargar Datos");
  }

  setMatriz(){
    console.log("Set matriz");
    for(var i: number = 0; i < 7; i++) {
      for(var j: number = 0; j< 7; j++) {
        if ( j == 0){
          this.things[i][j] = (i + 1);
        } else {
          this.things[i][j] = "";
        }
      }
    }
    console.log("Termino set matriz");
  }

  setMatrizHorarioProfesor(){
    for(var i: number = 0; i < 7; i++) {
      for(var j: number = 0; j< 7; j++) {
        if ( j == 0){
          this.horarioProfesorMatriz[i][j] = (i + 1);
        } else {
          this.horarioProfesorMatriz[i][j] = "";
        }
      }
    }
  }

  disponibilidad(nombres, apellidos, bloques_libres, rut, id){
    console.log(nombres);
    console.log(apellidos);
    console.log(bloques_libres);
    console.log(rut);
    console.log(id);
    this.setMatriz();
    for(let indexCount in this.disponibilidadDocentes) {
      console.log("indexCount: " + indexCount);
      if (this.disponibilidadDocentes[indexCount].profesor == (nombres + " " + apellidos)){
        console.log("Entre: " + String(this.disponibilidadDocentes[indexCount].profesor));
        console.log("Columna: " + String(this.dias.indexOf( this.disponibilidadDocentes[indexCount].dia) ));
        console.log("Fila: " + String(this.disponibilidadDocentes[indexCount].periodo - 1));
        console.log("Nombre profe: " + String(this.disponibilidadDocentes[indexCount].profesor));

        let columna = this.dias.indexOf( this.disponibilidadDocentes[indexCount].dia );
        let fila = this.disponibilidadDocentes[indexCount].periodo - 1;
        let str = this.disponibilidadDocentes[indexCount].profesor;

        this.datosProfesor = str;
        this.profeActual = str;
        console.log("Entrando matriz");
        this.things[columna][(fila + 1)] = str;
        console.log("Saliendo matriz");
      }      
    }

    console.log("Ingresando datos estaticos");
    this.profeActual = nombres + " " + apellidos;
    this.profeBloqueActual = bloques_libres;
    this.profeRutActual = rut;
    this.profeId = id;
    console.log("Termino cargar datos");

    // for(var i: number = 0; i < 7; i++) {
    //     for(var j: number = 0; j< 7; j++) {
    //         console.log("this.things[" + i + "][" + j + "]");
    //         console.log(this.things[i][j]);
    //     }
    // }
    this.mostrarHorario = true;
  }

  getEstadoBloque(cordenada){
    let dato = cordenada.split("-");
    let columna = +dato[0];
    let fila = +dato[1] - 1;

    // console.log("Columna: " + columna);
    // console.log("Fila: " + (fila + 1));

    if ( this.things[columna][(fila + 1)] == ""){
      this.things[columna][(fila + 1)] = this.profeActual;
    } else {
      this.things[columna][(fila + 1)] = "";
    }
  }

  mostrarHorarioDocente(rut){
    //console.log("Mostrar horario");
    //console.log("Rut profesor: " + rut);
    this.setMatrizHorarioProfesor();

    for (var i: number = 0; i < this.profesores.length; i++){
      if ( this.profesores[i].rut == rut ) {
        if (this.profesores[i].horario.length > 0){
          for (var j: number = 0; j < this.profesores[i].horario.length; j++){
            console.log("Imprimiendo por profe");

            console.log(this.profesores[i].horario[j].dia);
            console.log(this.profesores[i].horario[j].sala);
            console.log(this.profesores[i].horario[j].seccion);
            console.log(this.profesores[i].horario[j].horario.periodo);

            let columna = this.dias.indexOf( this.profesores[i].horario[j].dia );
            let fila = this.profesores[i].horario[j].horario.periodo - 1;
            console.log("columna: " + columna);
            console.log("fila: " + fila);

            this.horarioProfesorMatriz[columna][(fila + 1)] = "Asignatura: " + this.profesores[i].horario[j].asignatura.nombre + " - Seccion: " + this.profesores[i].horario[j].seccion + " - Sala: " + this.profesores[i].horario[j].sala ;
          }
        } else {
          alert("EL profesor seleccionado no tiene horario");
        }
      }
    }

    // for(var i: number = 0; i < 7; i++) {
    //     for(var j: number = 0; j< 7; j++) {
    //         console.log("this.horarioProfesorMatriz[" + i + "][" + j + "]");
    //         console.log(this.horarioProfesorMatriz[i][j]);
    //     }
    // }
    this.mostrarHorario = false;
  }

  ejecutar(){
    this._disponibilidadDocentesService.getEjecutar().subscribe(
        result => {
          alert(result);
        },
        error => {
          var errorMessage = <any>error;
          alert(errorMessage);
        }
      );
  }

  generarObjDisponibilidad(){
    // console.log("Bloques libres: " + this.profeBloqueActual);
    // console.log("Rut: " + this.profeRutActual);
    // console.log("Id: " + this.profeId);
    let dataSend = '';
    let validarComa = false;
    dataSend += '{';
    dataSend += '"docente_id" : "' + this.profeId + '",';
    dataSend += '"rut" : "' + this.profeRutActual + '",';
    dataSend += '"disponibilidad": ['
    for(var i: number = 0; i < 7; i++) {
        for(var j: number = 0; j< 7; j++) {
            if ( this.things[i][j] != "" && ( String(this.things[i][j]).split(" ") ).length > 2 ){
              // console.log("this.things[" + i + "][" + j + "]");
              if (validarComa){
                dataSend += ',';
                validarComa = false;
              }
              dataSend += '{'
              dataSend += '"dia" : "' + this.dias[(j - 1)] + '",';
              dataSend += '"periodo" : "' + (i + 1) + '"';
              dataSend += '}'
              // console.log("Dia: " + this.dias[j]);
              // console.log("periodo: " + (i + 1) );
              // console.log(this.things[i][j]);
              validarComa = true;

            }
        }
    }
    dataSend += ']}';
    // console.log( dataSend );
    let jsonSend = JSON.parse(dataSend);
    // console.log(jsonSend[0]);
    // console.log( JSON.stringify( jsonSend ) );

    if ( (jsonSend.disponibilidad).length < this.profeBloqueActual ){
      alert("La disponibilidad no puede ser menor a la cantidad de bloques asignados.");
    } else {
      alert("Guardar disponibilidad");

      this._disponibilidadDocentesService.postActualizarDisponibilidad( JSON.stringify( jsonSend ) ).subscribe(
        result => {
          this.disponibilidadDocentes = result;
          alert(result);

          location.reload();

          // this.cargarDatos();
        },
        error => {
          var errorMessage = <any>error;
          alert(errorMessage);
        }
      );
    }
  }
}
