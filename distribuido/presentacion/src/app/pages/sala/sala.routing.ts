import { Routes, RouterModule }  from '@angular/router';

import { Sala } from './sala.component';
import { Listar } from './components/listar/listar.component';
import { Disponibilidad } from './components/disponibilidad/disponibilidad.component';
import { Cargar } from './components/cargar/cargar.component';

const routes: Routes = [
  {
    path: '',
    component: Sala,
    children: [
     // { path: 'listar', component: Listar },
      { path: 'disponibilidad', component: Disponibilidad },
      { path: 'cargar', component: Cargar }
    ]
  }
];

export const routing = RouterModule.forChild(routes);
