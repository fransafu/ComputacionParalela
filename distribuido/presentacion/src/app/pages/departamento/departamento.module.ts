import { NgModule }      from '@angular/core';
import { CommonModule }  from '@angular/common';
import { FormsModule }   from '@angular/forms';
import { NgaModule }     from '../../theme/nga.module';

import { routing }       from './departamento.routing';
import { Departamento }  from './departamento.component';
import { Listar }        from './components/listar/listar.component';

@NgModule({
  declarations: [
    Departamento,
    Listar
  ],
  imports: [
    CommonModule,
    FormsModule,
    NgaModule,
    routing
  ]  
})
export class DepartamentoModule {
}
