import { Routes, RouterModule }  from '@angular/router';

import { Facultad } from './facultad.component';
import { Listar } from './components/listar/listar.component';

const routes: Routes = [
  {
    path: '',
    component: Facultad,
    children: [
      { path: 'listar', component: Listar }
    ]
  }
];

export const routing = RouterModule.forChild(routes);
