import { Routes, RouterModule }  from '@angular/router';

import { Horario } from './horario.component';
import { Listar } from './components/listar/listar.component';

const routes: Routes = [
  {
    path: '',
    component: Horario,
    children: [
      { path: 'listar', component: Listar }
    ]
  }
];

export const routing = RouterModule.forChild(routes);
