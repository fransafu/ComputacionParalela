Rails.application.routes.draw do


  post 'user_token' => 'user_token#create'
  get 'acceso/:id', to: 'acceso_paralelos#show'
  resources :usuarios
  post 'disponibilidad_docentes/:disponibilidad', to: 'disponibilidad_docentes#disponibilidades'
  resources :disponibilidad_docentes do
    collection {post :create_disponibilidad_docente, via: :options}
  end
  #asignaciones

  get '/asignaciones', to: 'asignaciones#index'
  get 'asignaciones/:id', to: 'asignaciones#show'

  #asignaturas
  get 'asignaturas', to: 'asignaturas#index'
  get 'asignaturas/:id', to: 'asignaturas#show'

  #cursos
  get '/cursos', to: 'cursos#index'
  get '/cursos/:id', to: 'cursos#show'

  #departamentos
  get 'departamentos', to: 'departamentos#index'
  get 'departamentos/:id', to: 'departamentos#show'

  #disponibilidad de salas
  get 'disponibilidad/', to: 'disponibilidad_salas#index'
  get 'disponibilidad/:id', to: 'disponibilidad_salas#show'

  #docentes
  get '/docentes', to: 'docentes#index'
  get '/docentes/:id', to: 'docentes#show'

  #facultades
  get '/facultades', to: 'facultades#index'
  get '/facultades/:id', to: 'facultades#show'

  #horarios
  get '/horarios', to: 'horarios#index'
  get '/horarios/:id', to: 'horarios#show'

  #periodos
  get '/periodos', to: 'periodos#index'
  get '/periodos/:id', to: 'periodos#show'

  #salas
  resources :salas do
    collection {post :create_sala, via: :options}
  end
  get '/salas/:nombre/horarios', to: 'salas#horario_sala'
  get '/salas/:dia/dia', to: 'salas#horario_dia'


  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
