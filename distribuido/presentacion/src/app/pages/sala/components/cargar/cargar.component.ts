import { Component } from '@angular/core';
import { SalasServices } from '../../../../services/salas.services';

@Component({
  selector: 'cargar-component',
  templateUrl: './cargar.component.html',
  styleUrls: ['./cargar.component.css'],
  providers: [ SalasServices ]
})

export class Cargar {
	public cargar;
	public nombreSala: string;
	public capacidadSala: string;
	public tipoSala: string;
	public cargarSala;

	constructor(private _salasService: SalasServices){
		this.nombreSala = "";
		this.capacidadSala = "";
		this.tipoSala = "";
	}

	enviarSala(){
		console.log(this.nombreSala);
		console.log(this.capacidadSala);
		console.log(this.tipoSala);

		// guardarSala
		this._salasService.guardarSala( this.nombreSala, this.capacidadSala, this.tipoSala ).subscribe(
        result => {
          this.cargarSala = result;
          	// console.log(JSON.stringify(this.cargarSala));
          	location.reload();

         	//console.log(result.status);
         	//console.log(result[0]);
        },
        error => {
          var errorMessage = <any>error;
          alert(errorMessage);
        }
      );
	}
}
