import { Routes, RouterModule }  from '@angular/router';

import { Periodo } from './periodo.component';
import { Listar } from './components/listar/listar.component';

const routes: Routes = [
  {
    path: '',
    component: Periodo,
    children: [
      { path: 'listar', component: Listar }
    ]
  }
];

export const routing = RouterModule.forChild(routes);
