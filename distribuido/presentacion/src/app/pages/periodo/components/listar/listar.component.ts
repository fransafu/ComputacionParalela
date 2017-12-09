import { Component } from '@angular/core';
import { PeriodoServices } from '../../../../services/periodo.services';

@Component({
  selector: 'listar-component',
  templateUrl: './listar.component.html',
  styleUrls: ['./listar.component.css']
})

export class Listar {
	public periodos;
	keys: String[];

	constructor(private _periodoService: PeriodoServices){

	}

	//function hack(val) {
	//  return Array.from(val);
	//}

	ngOnInit(){
		this._periodoService.getPeriodos().subscribe(
			result => {
				this.periodos = result;
				console.log(this.periodos);
				if(!this.periodos){
					console.log("Error en Query periodos server");
				} else {
					//this.periodos = hack(periodos);
    				//this.keys = Object.keys(this.periodos);
    				console.log(this.periodos);
	  			}
			},
			error => {
				var errorMessage = <any>error;
				console.log(errorMessage);
			}
		);
	}
}