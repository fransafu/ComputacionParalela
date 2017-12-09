import {Component} from '@angular/core';
import { PeriodoServices } from '../../services/periodo.services';

@Component({
  selector: 'periodo',
  template: `<router-outlet></router-outlet>`,
  providers: [PeriodoServices]
})
export class Periodo {
	public periodos;
  	keys: String[];

	constructor(private _periodoService: PeriodoServices) {

  	}

  	ngOnInit(){
  		
  		this._periodoService.getPeriodos().subscribe(
	  		result => {
	  			this.periodos = result;

	  			if (!this.periodos){
	  				console.log("Error en Query periodos server");
	  			} else {
    				this.keys = Object.keys(this.periodos);
	  			}
	  		},
	  		error => {
	  			var errorMessage = <any>error;
	  			console.log(errorMessage);
	  		}
	  	);
  	}
}

//{"numero":9,"inicio":"20:40:00","termino":"22:10:00"}
