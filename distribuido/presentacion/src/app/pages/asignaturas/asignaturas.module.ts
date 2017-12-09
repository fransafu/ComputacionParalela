import { NgModule }      from '@angular/core';
import { CommonModule }  from '@angular/common';
import { FormsModule }   from '@angular/forms';
import { NgaModule }     from '../../theme/nga.module';

import { routing }     from './asignaturas.routing';
import { Asignaturas } from './asignaturas.component';
import { Listar }      from './components/listar/listar.component';


@NgModule({
  declarations: [
    Asignaturas,
    Listar
  ],
  imports: [
    CommonModule,
    FormsModule,
    NgaModule,
    routing
  ]  
})
export class AsignaturasModule {
}
