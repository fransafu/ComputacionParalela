class HorariosController < ApplicationController
  before_action :set_horario, only: [:show, :update, :destroy]

  # GET /horarios
  def index
    horarios = Horario.all
    @horarios = []
    horarios.each do |actual|
      mostrar= {dia: actual.dia,
                curso: {codigo: actual.curso.codigo,
                        asignatura: {nombre: actual.curso.asignatura.nombre, codigo: actual.curso.asignatura.codigo,
                                     departamento: {nombre: actual.curso.asignatura.departamento.nombre,
                                                    facultad: {nombre: actual.curso.asignatura.departamento.facultad.nombre, sigla: actual.curso.asignatura.departamento.facultad.sigla}}},
                        semestre: actual.curso.semestre,
                        anio: actual.curso.anio,
                        seccion: actual.curso.seccion,
                        docente: {nombres: actual.curso.docente.nombres, apellidos: actual.curso.docente.apellidos, rut: actual.curso.docente.rut,
                                  departamento: {nombre: actual.curso.docente.departamento.nombre,
                                                 facultad: {sigla: actual.curso.docente.departamento.facultad.sigla, nombre: actual.curso.docente.departamento.facultad.nombre}}},
                        horario: {numero: actual.periodo.numero, inicio: actual.periodo.inicio, termino: actual.periodo.termino}
                },
                periodo: {numero: actual.periodo.numero, inicio: actual.periodo.inicio, termino: actual.periodo.termino},
                disponible: actual.libre
      }
      @horarios << mostrar
    end
    render json: @horarios
  end

  # GET /horarios/1
  def show
    actual = @horario
    @horario = {dia: actual.dia,
                curso: {codigo: actual.curso.codigo,
                        asignatura: {nombre: actual.curso.asignatura.nombre, codigo: actual.curso.asignatura.codigo,
                                     departamento: {nombre: actual.curso.asignatura.departamento.nombre,
                                                    facultad: {nombre: actual.curso.asignatura.departamento.facultad.nombre, sigla: actual.curso.asignatura.departamento.facultad.sigla}}},
                        semestre: actual.curso.semestre,
                        anio: actual.curso.anio,
                        seccion: actual.curso.seccion,
                        docente: {nombres: actual.curso.docente.nombres, apellidos: actual.curso.docente.apellidos, rut: actual.curso.docente.rut,
                                  departamento: {nombre: actual.curso.docente.departamento.nombre,
                                                 facultad: {sigla: actual.curso.docente.departamento.facultad.sigla, nombre: actual.curso.docente.departamento.facultad.nombre}}},
                        horario: {numero: actual.periodo.numero, inicio: actual.periodo.inicio, termino: actual.periodo.termino}
                },
                periodo: {numero: actual.periodo.numero, inicio: actual.periodo.inicio, termino: actual.periodo.termino},
                disponible: actual.libre
    }
    render json: @horario
  end

  # POST /horarios
  def create
    @horario = Horario.new(horario_params)

    if @horario.save
      render json: @horario, status: :created, location: @horario
    else
      render json: @horario.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /horarios/1
  def update
    if @horario.update(horario_params)
      render json: @horario
    else
      render json: @horario.errors, status: :unprocessable_entity
    end
  end

  # DELETE /horarios/1
  def destroy
    @horario.destroy
  end

  private
  # Use callbacks to share common setup or constraints between actions.
  def set_horario
    @horario = Horario.find(params[:id])
  end

  # Only allow a trusted parameter "white list" through.
  def horario_params
    params.require(:horario).permit(:dia, :codigo_curso, :curso_asignatura, :nombre_asignatura, :periodo_id)
  end
end
