class CursosController < ApplicationController
  before_action :set_curso, only: [:show, :update, :destroy]

  # GET /cursos
  def index
    cursos = Curso.all
    @cursos=[]
    cursos.each do |actual|
      mostrar = {codigo: actual.codigo,
                 asignatura: {nombre: actual.asignatura.nombre, codigo: actual.asignatura.codigo,
                              departamento: {nombre: actual.asignatura.departamento.nombre,
                                             facultad: {nombre: actual.asignatura.departamento.facultad.nombre, sigla: actual.asignatura.departamento.facultad.sigla}}},
                 semestre: actual.semestre,
                 anio: actual.anio,
                 seccion: actual.seccion,
                 docente: {nombres: actual.docente.nombres, apellidos: actual.docente.apellidos, rut: actual.docente.rut,
                           departamento: {nombre: actual.docente.departamento.nombre,
                                          facultad: {sigla: actual.docente.departamento.facultad.sigla, nombre: actual.docente.departamento.facultad.nombre}}},

      }

      @cursos << mostrar
    end
    render json: @cursos
  end

  # GET /cursos/1
  def show
    actual = @curso
    horario = []
    actual.horarios.each do |actual|
      hora= {
          dia: actual.dia,
          periodo: actual.periodo.numero,
          inicio: actual.periodo.inicio,
          termino: actual.periodo.termino,
          libre: actual.libre
      }
      horario << hora
    end
    @curso = {codigo: actual.codigo,
              semestre: actual.semestre,
              anio: actual.anio,
              seccion: actual.seccion,
              asignatura: {nombre: actual.asignatura.nombre, codigo: actual.asignatura.codigo,
                           departamento: {nombre: actual.asignatura.departamento.nombre,
                                          facultad: {nombre: actual.asignatura.departamento.facultad.nombre, sigla: actual.asignatura.departamento.facultad.sigla}}},

              docente: {nombres: actual.docente.nombres, apellidos: actual.docente.apellidos, rut: actual.docente.rut,
                        departamento: {nombre: actual.docente.departamento.nombre,
                                       facultad: {sigla: actual.docente.departamento.facultad.sigla, nombre: actual.docente.departamento.facultad.nombre}}},
              horario: horario
    }

    render json: @curso
  end

  # POST /cursos
  def create
    @curso = Curso.new(curso_params)

    if @curso.save
      render json: @curso, status: :created, location: @curso
    else
      render json: @curso.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /cursos/1
  def update
    if @curso.update(curso_params)
      render json: @curso
    else
      render json: @curso.errors, status: :unprocessable_entity
    end
  end

  # DELETE /cursos/1
  def destroy
    @curso.destroy
  end

  private
  # Use callbacks to share common setup or constraints between actions.
  def set_curso
    @curso = Curso.find(params[:id])
  end

  # Only allow a trusted parameter "white list" through.
  def curso_params
    params.require(:curso).permit(:codigo, :asignatura_id, :semestre, :anio, :seccion, :docente_id)
  end
end
