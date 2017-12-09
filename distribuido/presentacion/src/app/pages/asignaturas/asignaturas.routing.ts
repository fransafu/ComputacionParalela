import { Routes, RouterModule }  from '@angular/router';

import { Asignaturas } from './asignaturas.component';
import { Listar } from './components/listar/listar.component';

const routes: Routes = [
{
    path: '',
    component: Asignaturas,
    children: [
      { path: 'listar', component: Listar }
    ]
  }
];

export const routing = RouterModule.forChild(routes);
