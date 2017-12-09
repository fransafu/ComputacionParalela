import { NgModule }      from '@angular/core';
import { CommonModule }  from '@angular/common';
import { FormsModule }   from '@angular/forms';
import { NgaModule }     from '../../theme/nga.module';

import { routing }       from './facultad.routing';
import { Facultad }      from './facultad.component';
import { Listar }        from './components/listar/listar.component';

@NgModule({
  declarations: [
    Facultad,
    Listar
  ],
  imports: [
    CommonModule,
    FormsModule,
    NgaModule,
    routing
  ]  
})
export class FacultadModule {
}
