import { Routes, RouterModule }  from '@angular/router';

import { Departamento } from './departamento.component';
import { Listar } from './components/listar/listar.component';

const routes: Routes = [
  {
    path: '',
    component: Departamento,
    children: [
      { path: 'listar', component: Listar }
    ]
  }
];

export const routing = RouterModule.forChild(routes);
