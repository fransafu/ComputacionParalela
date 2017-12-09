import { Component } from '@angular/core';
import { SalasServices } from '../../../../services/salas.services';
import { PeriodoServices } from '../../../../services/periodo.services';
import { DisponibilidadSalasServices } from '../../../../services/disponibilidadSalas.services';

@Component({
  selector: 'disponibilidad-salas',
  templateUrl: './disponibilidad.component.html',
  styleUrls: ['./disponibilidad.component.scss'],
  providers: [ SalasServices, PeriodoServices, DisponibilidadSalasServices ]
})

export class Disponibilidad {
  // Sala 
  public salas;
  public salaHorario;

  public things: any[][];
  public dias: any[] = ["LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO"];

  constructor(private _salasServices: SalasServices){
    console.log("constructor");

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
  }

  ngOnInit(){
   // console.log("ngOnInit");

    this._salasServices.getSalas().subscribe(
      result => {
        this.salas = result;
        // console.log(this.salas);
        if (!this.salas){
          console.log("Error en Query profesores server");
        }
      },
      error => {
        var errorMessage = <any>error;
        console.log(errorMessage);
      }
    );
  }

  setMatriz(){
    for(var i: number = 0; i < 7; i++) {
        for(var j: number = 0; j< 7; j++) {
          if ( j == 0){
            this.things[i][j] = (i + 1);
          } else {
            this.things[i][j] = "";
          }
        }
    }
  }

  consultarHorarioSala(sala:string, cantidadBloqueLibre:string){
    this.setMatriz();

    if (cantidadBloqueLibre == "42"){
      alert("No tiene horario asignado");
    }

    this._salasServices.getHorarioSalas(sala).subscribe(
      result => {
        this.salaHorario = result;
        // console.log(this.salaHorario);
        if (!this.salaHorario){
          console.log("Error en Query profesores server");
        }
        for(let indexCount in this.salaHorario) {
          // console.log( this.salaHorario[indexCount]);
          if ( this.salaHorario[indexCount].libre ){
            // 
          } else {
            // console.log( this.salaHorario[indexCount].dia );
            // console.log( this.salaHorario[indexCount].periodo );
            // console.log( this.salaHorario[indexCount]);
            let fila = this.dias.indexOf( this.salaHorario[indexCount].dia );
            let columna = this.salaHorario[indexCount].periodo - 1;
            let str = "Asignatura: " +  this.salaHorario[indexCount].asignatura + " - Profesor: " + this.salaHorario[indexCount].profesor + " - Seccion: " + this.salaHorario[indexCount].seccion ;

            if ( !(this.salaHorario[indexCount].dia == "SABADO" && this.salaHorario[indexCount].periodo > 4)){
                this.things[columna][(fila + 1)] = str;
              }
          }
        }
      },
      error => {
        var errorMessage = <any>error;
        console.log(errorMessage);
      }
    );
  }
}
