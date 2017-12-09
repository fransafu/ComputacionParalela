import { Routes, RouterModule }  from '@angular/router';

import { Cursos } from './cursos.component';
import { Listar } from './components/listar/listar.component';
//import { Ckeditor } from './components/ckeditor/ckeditor.component';

const routes: Routes = [
  {
    path: '',
    component: Cursos,
    children: [
      { path: 'listar', component: Listar }
    ]
  }
];

export const routing = RouterModule.forChild(routes);
