import {Component} from '@angular/core';
//import { SalasServices } from '../../services/salas.services';

@Component({
  selector: 'sala',
  template: `<router-outlet></router-outlet>`
})
export class Sala {
  public salas;
  constructor(/*private _salasService: SalasServices*/) {

  }
}
