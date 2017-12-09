import { NgModule }      from '@angular/core';
import { CommonModule }  from '@angular/common';
import { FormsModule }   from '@angular/forms';
import { NgaModule }     from '../../theme/nga.module';

import { routing }    from './cursos.routing';
import { Cursos }     from './cursos.component';
import { Listar }     from './components/listar/listar.component';


@NgModule({
  declarations: [
    Cursos,
    Listar
  ],
  imports: [
    CommonModule,
    FormsModule,
    NgaModule,
    routing
  ]  
})
export class CursosModule {
}
