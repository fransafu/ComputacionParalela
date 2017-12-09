import { Routes, RouterModule }  from '@angular/router';

import { Profesores } from './profesores.component';
import { Listar } from './components/listar/listar.component';
import { Disponibilidad } from './components/disponibilidad/disponibilidad.component';

const routes: Routes = [
  {
    path: '',
    component: Profesores,
    children: [
      { path: 'listar', component: Listar },
      { path: 'disponibilidad', component: Disponibilidad }
    ]
  }
];

export const routing = RouterModule.forChild(routes);
