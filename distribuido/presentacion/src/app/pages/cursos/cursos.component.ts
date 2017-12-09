import {Component} from '@angular/core';
// import { ProfesoresServices } from '../../services/profesores.services';

@Component({
  selector: 'cursos',
  template: `<router-outlet></router-outlet>`//,
  //providers: [ProfesoresServices]
})
export class Cursos {
	public cursos;
  constructor() {
  }
  // constructor(private _profesoresService: ProfesoresServices) {

  // }

 // ngOnInit(){
  	/*this._profesoresService.getProfesores().subscribe(
  		result => {
  			this.profesores = result;

  			if (!this.profesores){
  				console.log("Error en Query profesores server");
  			}
  		},
  		error => {
  			var errorMessage = <any>error;
  			console.log(errorMessage);
  		}
  	);*/
 // }
}
