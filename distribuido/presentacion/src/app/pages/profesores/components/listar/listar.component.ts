import { Component } from '@angular/core';
import { ProfesoresServices } from '../../../../services/profesores.services';
import { Disponibilidad } from '../disponibilidad/disponibilidad.component';

@Component({
  selector: 'listar-component',
  templateUrl: './listar.component.html',
  styleUrls: ['./listar.component.scss']
})

export class Listar {
	public profesores;
  /* Muestra de objeto profesor desde base de datos:

  apellidos:"Castillo Valdes"
bloques_libres:6
departamento: Object
  facultad:Object
    nombre:"Facultad de Ingeniería"
    sigla:"FACING"
nombre:"Informática y Computación"
email:"10471648@sincorreo.cl"
nombres:"Mauro Alex"
rut:"10.471.648-2"
*/
  constructor(private _profesoresService: ProfesoresServices) {
  }

  ngOnInit(){
  	this._profesoresService.getProfesores().subscribe(
  		result => {
  			this.profesores = result;
  			console.log(this.profesores);
  			if (!this.profesores){
  				console.log("Error en Query profesores server");
  			}
  		},
  		error => {
  			var errorMessage = <any>error;
  			console.log(errorMessage);
  		}
  	);
  }

  disponibilidad(rut){
    console.log("Disponibilidad profe rut: " + rut);
    // this._disponibilidad.saludar();
  }
}
