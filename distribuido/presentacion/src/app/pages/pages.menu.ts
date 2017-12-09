export const PAGES_MENU = [
  {
    path: 'pages',
    children: [
      /*{
        path: 'dashboard',
        data: {
          menu: {
            title: 'general.menu.dashboard',
            icon: 'ion-android-home',
            selected: false,
            expanded: false,
            order: 0
          }
        }
      },*//*
      {
        path: 'horario',
        data: {
          menu: {
            title: 'Horario',
            icon: 'ion-calendar',
            selected: false,
            expanded: false,
            order: 100,
          }
        },
        children: [
          {
            path: 'listar',
            data: {
              menu: {
                title: 'Ver horario',
              }
            }
          }
        ]
      },*/
      {
        path: 'profesores',
        data: {
          menu: {
            title: 'Profesores',
            icon: 'ion-university',
            selected: false,
            expanded: false,
            order: 100,
          }
        },
        children: [
        /*
          {
            path: 'listar',
            data: {
              menu: {
                title: 'Lista de profesores',
              }
            }
          },
          */
          {
            path: 'disponibilidad',
            data: {
              menu: {
                title: 'Disponibilidad',
              }
            }
          }
        ]
      },
      {
        path: 'sala',
        data: {
          menu: {
            title: 'Sala',
            icon: 'ion-clipboard',
            selected: false,
            expanded: false,
            order: 100,
          }
        },
        children: [
          {
            path: 'cargar',
            data: {
              menu: {
                title: 'Cargar sala',
              }
            }
          },
          {
            path: 'disponibilidad',
            data: {
              menu: {
                title: 'Disponibilidad',
              }
            }
          }
        ]
      }//,
      /*
      {
        path: 'periodo',
        data: {
          menu: {
            title: 'Periodo',
            icon: 'ion-clipboard',
            selected: false,
            expanded: false,
            order: 100,
          }
        },
        children: [
          {
            path: 'listar',
            data: {
              menu: {
                title: 'Lista de periodos',
              }
            }
          }
        ]
      },
      {
        path: 'asignaturas',
        data: {
          menu: {
            title: 'Asignaturas',
            icon: 'ion-ios-bookmarks',
            selected: false,
            expanded: false,
            order: 100,
          }
        },
        children: [
          {
            path: 'listar',
            data: {
              menu: {
                title: 'Lista de asignaturas',
              }
            }
          }
        ]
      },
      {
        path: 'cursos',
        data: {
          menu: {
            title: 'cursos',
            //icon: 'ion-person-stalker',
            selected: false,
            expanded: false,
            order: 100,
          }
        },
        children: [
          {
            path: 'listar',
            data: {
              menu: {
                title: 'Ver cursos',
              }
            }
          }
        ]
      },
      {
        path: 'departamento',
        data: {
          menu: {
            title: 'Departamento',
            //icon: 'ion-university',
            selected: false,
            expanded: false,
            order: 100,
          }
        },
        children: [
          {
            path: 'listar',
            data: {
              menu: {
                title: 'Lista de departamentos',
              }
            }
          }
        ]
      },
      {
        path: 'facultad',
        data: {
          menu: {
            title: 'Facultad',
            //icon: 'ion-clipboard',
            selected: false,
            expanded: false,
            order: 100,
          }
        },
        children: [
          {
            path: 'listar',
            data: {
              menu: {
                title: 'Lista de facultades',
              }
            }
          }
        ]
      }*///,
      /*,
      {
        path: 'configuracion',
        data: {
          menu: {
            title: 'Configuracion',
            icon: 'ion-gear-a',
            selected: false,
            expanded: false,
            order: 100,
          }
        },
        children: [
          {
            path: 'listar',
            data: {
              menu: {
                title: 'Ver horario',
              }
            }
          }
        ]
      }*/
    ]
  }
];
