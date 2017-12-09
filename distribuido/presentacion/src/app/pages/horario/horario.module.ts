import { NgModule }      from '@angular/core';
import { CommonModule }  from '@angular/common';
import { FormsModule }   from '@angular/forms';
import { NgaModule }     from '../../theme/nga.module';

import { routing } from './horario.routing';
import { Horario } from './horario.component';
import { Listar }  from './components/listar/listar.component';

@NgModule({
  declarations: [
    Horario,
    Listar
  ],
  imports: [
    CommonModule,
    FormsModule,
    NgaModule,
    routing
  ]  
})
export class HorarioModule {
}
