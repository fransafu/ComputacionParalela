import { NgModule }      from '@angular/core';
import { CommonModule }  from '@angular/common';
import { FormsModule }   from '@angular/forms';
import { NgaModule }     from '../../theme/nga.module';

import { routing }    from './profesores.routing';
import { Profesores } from './profesores.component';
import { Listar }     from './components/listar/listar.component';
import { Disponibilidad }     from './components/disponibilidad/disponibilidad.component';


@NgModule({
  declarations: [
    Profesores,
    Listar,
    Disponibilidad
  ],
  imports: [
    CommonModule,
    FormsModule,
    NgaModule,
    routing
  ]  
})
export class ProfesoresModule {
}
