import { NgModule }      from '@angular/core';
import { CommonModule }  from '@angular/common';
import { FormsModule }   from '@angular/forms';
import { NgaModule }     from '../../theme/nga.module';

import { routing }       from './periodo.routing';
import { Periodo }       from './periodo.component';
import { Listar }        from './components/listar/listar.component';

@NgModule({
  declarations: [
    Periodo,
    Listar
  ],
  imports: [
    CommonModule,
    FormsModule,
    NgaModule,
    routing
  ]  
})
export class PeriodoModule {
}
