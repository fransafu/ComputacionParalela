import { Component } from '@angular/core';

@Component({
  selector: 'listar-component',
  templateUrl: './listar.component.html',
  styleUrls: ['./listar.component.css']
})

export class Listar {

	public periodos: any[] = [1, 2, 3, 4, 5, 6, 7, 8, 9];
	public dias: any[] = ["Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"]; 
	public marca: boolean = true;
	public clicked: boolean = false;

	public bloques: any[] = [[false, false, false, false, false, false], 
							   [false, false, false, false, false, false], 
							   [false, false, false, false, false, false], 
							   [false, false, false, false, false, false], 
							   [false, false, false, false, false, false], 
							   [false, false, false, false, false, false], 
							   [false, false, false, false, false, false], 
							   [false, false, false, false, false, false], 
							   [false, false, false, false, false, false],
							   [false, false, false, false, false, false]];
  
  	constructor() {
  	};

  	ngOnInit(){}

  	getEstadoBloque(cordenada){
  		console.log(cordenada);
  		let dato = cordenada.split("-");
  		let fila = +dato[0];
  		let columna = +dato[1];


  		console.log("columna: " + (columna - 1));
  		console.log("fila: " + (fila - 1));

  		console.log("bloques["+(columna - 1)+"]["+(fila - 1)+"]: "+this.bloques[columna][fila]);

  		return this.bloques[(columna - 1)][(fila - 1)];
  	}

  	changeEstadoBloque(cordenada){
  		console.log(cordenada);
  		let dato = cordenada.split("-");
  		let fila = +dato[0];
  		let columna = +dato[1];

  		console.log("columna: " + (columna - 1));
  		console.log("fila: " + (fila - 1));

  		console.log("bloques["+(columna - 1)+"]["+(fila - 1)+"]: "+this.bloques[columna][fila]);

  		if (!this.bloques[(columna - 1)][(fila - 1)]){
  			this.bloques[(columna - 1)][(fila - 1)] = true;
  		} else {
  			this.bloques[(columna - 1)][(fila - 1)] = false;
  		}
  	}

  	changeColor(){
  		if (this.clicked){
  			this.clicked = false;
  		} else {
  			this.clicked = true;
  		}
  	}
}
