class DocentesController < ApplicationController
  before_action :set_docente, only: [:show, :update, :destroy]

  # GET /docentes
  def index
    docentes = Docente.all
    @docentes = []
    docentes.each do |actual|

      disponibilidades = actual.disponibilidad_docentes
      horario=[]
      disponibilidades_docentes =[]
      disponibilidades.each do |disponibilidad|
        mostrar = {dia: disponibilidad.dia,
                   periodo: {numero: disponibilidad.periodo.numero,
                             inicio: disponibilidad.periodo.inicio,
                             termino: disponibilidad.periodo.termino
                   }
        }
        asignacion = Asignacion.find_by_disponibilidad_docente_id(disponibilidad.id)
        if asignacion!=nil
          mostrar_horario = {dia: asignacion.disponibilidad_docente.dia,
                             sala: asignacion.disponibilidad_sala.sala.nombre,
                             asignatura: {nombre: asignacion.horario.curso.asignatura.nombre,
                                          codigo: asignacion.horario.curso.asignatura.codigo},
                             seccion: asignacion.horario.curso.seccion,
                             horario: {periodo: asignacion.disponibilidad_docente.periodo.numero,
                                       inicio: asignacion.disponibilidad_docente.periodo.inicio,
                                       termino: asignacion.disponibilidad_docente.periodo.termino
                             }
          }
          horario<< mostrar_horario
          disponibilidades_docentes << mostrar

        end

      end


      mostrar = {id: actual.id,
                 nombres: actual.nombres,
                 apellidos: actual.apellidos,
                 rut: actual.rut,
                 bloques_libres: actual.bloques,
                 email: actual.email,
                 departamento: {nombre: actual.departamento.nombre,
                                facultad: {nombre: actual.departamento.facultad.nombre, sigla: actual.departamento.facultad.sigla}},
                 horario: horario,
                 disponibilidad_docentes: disponibilidades_docentes
      }
      @docentes << mostrar
    end

    render json: @docentes
  end

  # GET /docentes/1
  def show
    actual = @docente
    disponibilidades = actual.disponibilidad_docentes
    horario=[]
    disponibilidades_docentes =[]
    disponibilidades.each do |disponibilidad|
      mostrar = {dia: disponibilidad.dia,
                 periodo: {numero: disponibilidad.periodo.numero,
                           inicio: disponibilidad.periodo.inicio,
                           termino: disponibilidad.periodo.termino
                 }
      }
      disponibilidades_docentes << mostrar
      asignacion = Asignacion.find_by_disponibilidad_docente_id(disponibilidad.id)
      if asignacion!=nil
        mostrar = {dia: asignacion.disponibilidad_docente.dia,
                   sala: asignacion.disponibilidad_sala.sala.nombre,
                   asignatura: {nombre: asignacion.horario.curso.asignatura.nombre,
                                codigo: asignacion.horario.curso.asignatura.codigo},
                   seccion: asignacion.horario.curso.seccion,
                   horario: {periodo: asignacion.disponibilidad_docente.periodo.numero,
                             inicio: asignacion.disponibilidad_docente.periodo.inicio,
                             termino: asignacion.disponibilidad_docente.periodo.termino
                   }
        }
        horario<< mostrar
      end

    end
    @docente = {id: actual.id,
                nombres: actual.nombres,
                apellidos: actual.apellidos,
                rut: actual.rut,
                bloques_libres: actual.bloques,
                email: actual.email,
                departamento: {nombre: actual.departamento.nombre,
                               facultad: {nombre: actual.departamento.facultad.nombre,
                                          sigla: actual.departamento.facultad.sigla}},
                horario: horario,
                disponibilidad_docentes: disponibilidades_docentes
    }
    render json: @docente
  end

  # POST /docentes
  def create
    @docente = Docente.new(docente_params)

    if @docente.save
      render json: @docente, status: :created, location: @docente
    else
      render json: @docente.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /docentes/1
  def update
    if @docente.update(docente_params)
      render json: @docente
    else
      render json: @docente.errors, status: :unprocessable_entity
    end
  end


  private
  # Use callbacks to share common setup or constraints between actions.
  def set_docente
    @docente = Docente.find(params[:id])
  end

  # Only allow a trusted parameter "white list" through.
  def docente_params
    params.require(:docente).permit(:nombres, :apellidos, :rut, :departamento_id_id, :activo, :email)
  end
end
