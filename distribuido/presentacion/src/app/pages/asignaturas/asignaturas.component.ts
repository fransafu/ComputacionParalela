import {Component} from '@angular/core';

@Component({
  selector: 'asignaturas',
  template: `<router-outlet></router-outlet>`
})
export class Asignaturas {
	public asignaturas;
  constructor() {
  }
}
