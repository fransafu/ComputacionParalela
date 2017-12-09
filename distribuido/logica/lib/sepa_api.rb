class SepaApi
  URL='https://sepa.utem.cl/rest/api/v1'
  AUTH = {username: 'EH9550bn6q', password: '290bf40f3a27671b71ccf2f454533607'} #rubilar


  def guardarDocentes()
    salida =[]
    uri = '/academia/docentes'
    respuesta = HTTParty.get(URI.encode(URL+uri), basic_auth: AUTH)
    case respuesta.response.code.to_i
      when 200
        respuesta.each do |docente|
          if Docente.find_by_rut(docente['rut'])==nil
            salida << guardarDocente(docente['rut'])
          end
        end
      when 403
        salida ='Privilegios insuficientes para acceder a la información'
      when 404
        salida ='Docentes no encontrados'
      when 500
        salida = 'Error interno del api Sepa'
    end
  end


  def guardarDocente(rut)
    salida = nil
    uri = '/academia/docentes/'
    if rut!= nil
      respuesta = HTTParty.get(URI.encode(URL+uri+rut.to_s), basic_auth: AUTH)
      case respuesta.response.code.to_i
        when 200
          salida = Docente.new
          salida.nombres = respuesta['nombres']
          salida.apellidos = respuesta['apellidos']
          salida.rut = respuesta['rut']
          departamento = respuesta['departamento']['nombre']
          facultad = Facultad.find_by_nombre(respuesta['departamento']['facultad']['nombre'])
          if facultad==nil
            persistirFacultad(respuesta['departamento']['facultad'])
            facultad = Facultad.find_by_nombre(respuesta['departamento']['facultad']['nombre'])
          end
          if Departamento.find_by_nombre(departamento) == nil
            persistirDepartamento(departamento, facultad.id)
          end
          salida.departamento_id= (Departamento.find_by_nombre(departamento)).id
          if salida.save
            salida = 'Se persistio docente con id: '+salida.id.to_s
          else
            salida = salida.errors
          end
        when 403
          salida='Privilegios insuficientes para acceder a la información'
        when 404
          salida ='Docentes no encontrados'
        when 500
          salida = 'Error interno del api Sepa'
      end
    end
    return salida
  end


  def getAsignaturasInformatica()
    salida = nil
      uri = '/docencia/asignaturas'
    respuesta = HTTParty.get(URI.encode(URL+uri), basic_auth: AUTH)
    case respuesta.response.code.to_i
      when 200
        respuesta.each do |asignatura|
          if asignatura['codigo'].include? "INF"
            getCursos(asignatura['codigo'])
          end
        end
      when 403
        salida='Privilegios insuficientes para acceder a la información'
      when 404
        salida ='Docentes no encontrados'
      when 500
        salida = 'Error interno del api Sepa'
    end
  end


  def getCursos(codigo)
    salida = nil
    uri ='/docencia/asignaturas/'+codigo+'/cursos'
      respuesta = HTTParty.get(URI.encode(URL+uri), basic_auth: AUTH)
    case respuesta.response.code.to_i
      when 200
        today = Time.now
        respuesta.each do |curso|
          if curso['asignatura']['codigo'].include? "INF"
            if curso['anio']== 2017 && curso['semestre'] == 1
              if Facultad.find_by_sigla(curso['asignatura']['departamento']['facultad']['sigla']) == nil
                Facultad.create(nombre: curso['asignatura']['departamento']['facultad']['nombre'], sigla: curso['asignatura']['departamento']['facultad']['sigla'])
              end
              if Departamento.find_by_nombre(curso['asignatura']['departamento']['nombre'])==nil
                Departamento.create(nombre: curso['asignatura']['departamento']['nombre'], facultad_id: (Facultad.find_by_sigla(curso['asignatura']['departamento']['facultad']['sigla'])).id)
              end
              if Docente.find_by_rut(curso['docente']['rut']) == nil
                if Facultad.find_by_sigla(curso['docente']['departamento']['facultad']['sigla']) == nil
                  Facultad.create(nombre: curso['docente']['departamento']['facultad']['nombre'], sigla: curso['docente']['departamento']['facultad']['sigla'])
                end
                if Departamento.find_by_nombre(curso['docente']['departamento']['nombre'])==nil
                  Departamento.create(nombre: curso['docente']['departamento']['nombre'], facultad_id: (Facultad.find_by_sigla(curso['docente']['departamento']['facultad']['sigla'])).id)
                end
                Docente.create(nombres: curso['docente']['nombres'], apellidos: curso['docente']['apellidos'], rut: curso['docente']['rut'], departamento_id: (Departamento.find_by_nombre(curso['docente']['departamento']['nombre'])).id, email: curso['docente']['email'])
              end
              if Asignatura.find_by_codigo(curso['asignatura']['codigo']) == nil
                if Departamento.find_by_nombre(curso['asignatura']['departamento']['nombre'])==nil
                  Departamento.create(nombre: curso['asignatura']['departamento']['nombre'], facultad_id: (Facultad.find_by_sigla(curso['docente']['departamento']['facultad']['sigla'])).id)
                end
                Asignatura.create(nombre: curso['asignatura']['nombre'],
                                  codigo: curso['asignatura']['codigo'],
                                  departamento_id: (Departamento.find_by_nombre(curso['asignatura']['departamento']['nombre'])).id,
                                  creditos: curso['asignatura']['creditos'],
                                  horas_semanales: curso['asignatura']['horasSemanales'])
              end
              Curso.create(codigo: curso['codigo'],
                           asignatura_id: (Asignatura.find_by_codigo(curso['asignatura']['codigo'])).id,
                           semestre: curso['semestre'],
                           anio: curso['anio'],
                           seccion: curso['seccion'],
                           docente_id: (Docente.find_by_rut(curso['docente']['rut'])).id)
              guardarHoario(curso['codigo'])
            end
          end
        end
      when 403
        salida='Privilegios insuficientes para acceder a la información'
      when 404
        salida ='Docentes no encontrados'
      when 500
        salida = 'Error interno del api Sepa'
    end
  end


  def persistirDepartamento(nombre, facultad)
    departamento = Departamento.find_by_nombre(nombre)
    if departamento == nil
      Departamento.create(nombre: nombre, facultad_id: facultad)
    end
  end


  def guardarPeriodos()
    salida =''
    uri = '/planificacion/periodos'
    respuesta = HTTParty.get(URI.encode(URL+uri), basic_auth: AUTH)
    case respuesta.response.code.to_i
      when 200
        respuesta.each do |periodo|
          if Periodo.find_by_numero(periodo['numero'])==nil
            Periodo.create(numero: periodo['numero'], inicio: periodo['inicio'], termino: periodo['termino'])
          else
            periodo = Periodo.find_by_numero(periodo['numero'])
            periodo.save(numero: periodo['numero'], inicio: periodo['inicio'], termino: periodo['termino'])
          end
        end
      when 403
        salida ='Privilegios insuficientes para acceder a la información'
      when 404
        salida ='Periodo no encontrados'
      when 500
        salida = 'Error interno del api Sepa'
    end
  end

  def persistirFacultad(facultad)
    if Facultad.find_by_nombre(facultad['nombre']) == nil
      Facultad.create(nombre: facultad['nombre'], sigla: facultad['sigla'])
    end
  end

  def guardarHoario(codigo)
    salida=''
    uri = '/planificacion/cursos/'+codigo.to_s+'/horarios'
    respuesta = HTTParty.get(URI.encode(URL+uri), basic_auth: AUTH)
    case respuesta.response.code.to_i
      when 200
        respuesta.each do |horario|
          Horario.create(dia: horario['dia'], curso_id: (Curso.find_by_codigo(horario['codigoCurso'])).id, periodo_id: (Periodo.find_by_numero(horario['periodo'])).id)
        end
      when 403
        salida ='Privilegios insuficientes para acceder a la información'
      when 404
        salida ='Periodo no encontrados'
      when 500
        salida = 'Error interno del api Sepa'
    end
    return salida
  end

end
