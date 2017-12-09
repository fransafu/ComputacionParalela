import { Routes, RouterModule }  from '@angular/router';
import { Pages } from './pages.component';
import { ModuleWithProviders } from '@angular/core';
// noinspection TypeScriptValidateTypes

// export function loadChildren(path) { return System.import(path); };

export const routes: Routes = [
  {
    path: 'login',
    loadChildren: 'app/pages/login/login.module#LoginModule'
  },
  {
    path: 'pages',
    component: Pages,
    children: [
      { path: '', redirectTo: 'profesores', pathMatch: 'full' },
      //{ path: '*', redirectTo: 'profesores', pathMatch: 'full' },
      //{ path: 'dashboard', loadChildren: './dashboard/dashboard.module#DashboardModule' },
      { path: 'profesores', loadChildren: './profesores/profesores.module#ProfesoresModule'},
      { path: 'horario', loadChildren: './horario/horario.module#HorarioModule'},
      { path: 'cursos', loadChildren: './cursos/cursos.module#CursosModule'},
      { path: 'departamento', loadChildren: './departamento/departamento.module#DepartamentoModule'},
      { path: 'asignaturas', loadChildren: './asignaturas/asignaturas.module#AsignaturasModule'},
      { path: 'sala', loadChildren: './sala/sala.module#SalaModule'},
      { path: 'facultad', loadChildren: './facultad/facultad.module#FacultadModule'},
      { path: 'periodo', loadChildren: './periodo/periodo.module#PeriodoModule'}//,
      //{ path: 'configuracion', loadChildren: './configuracion/configuracion.module#ConfiguracionModule'},
    ]
  }
];

export const routing: ModuleWithProviders = RouterModule.forChild(routes);
