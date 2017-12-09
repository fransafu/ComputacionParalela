import { NgModule }      from '@angular/core';
import { CommonModule }  from '@angular/common';
import { FormsModule }   from '@angular/forms';
import { NgaModule }     from '../../theme/nga.module';

import { routing }        from './sala.routing';
import { Sala }           from './sala.component';
import { Listar }         from './components/listar/listar.component';
import { Disponibilidad } from './components/disponibilidad/disponibilidad.component';
import { Cargar }         from './components/cargar/cargar.component';

@NgModule({
  declarations: [
    Sala,
    Listar,
    Disponibilidad,
    Cargar
  ],
  imports: [
    CommonModule,
    FormsModule,
    NgaModule,
    routing
  ]  
})
export class SalaModule {
}
