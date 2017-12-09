class AsignaturasController < ApplicationController
  before_action :set_asignatura, only: [:show, :update, :destroy]

  # GET /asignaturas
  def index
    asignaturas = Asignatura.all
    @asignaturas=[]
    asignaturas.each do |actual|
      mostrar = {nombre: actual.nombre,
                 codigo: actual.codigo,
                 departamento: {nombre: actual.departamento.nombre,
                                facultad: {nombre: actual.departamento.facultad.nombre,
                                           sigla: actual.departamento.facultad.sigla}},
                 creditos: actual.creditos,
                 horas_semanales: actual.horas_semanales
      }
      @asignaturas<< mostrar
    end

    render json: @asignaturas
  end

  # GET /asignaturas/1disponibilidad_docentes
  def show
    actual = @asignatura
    if stale?(last_modified: actual.updated_at)
      @asignatura = {nombre: actual.nombre,
                     codigo: actual.codigo,
                     departamento: {nombre: actual.departamento.nombre,
                                    facultad: {nombre: actual.departamento.facultad.nombre,
                                               sigla: actual.departamento.facultad.sigla}},
                     creditos: actual.creditos,
                     horas_semanales: actual.horas_semanales
      }
      render json: @asignatura
    end
  end

  # POST /asignaturas
  def create
    @asignatura = Asignatura.new(asignatura_params)

    if @asignatura.save
      render json: @asignatura, status: :created, location: @asignatura
    else
      render json: @asignatura.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /asignaturas/1
  def update
    if @asignatura.update(asignatura_params)
      render json: @asignatura
    else
      render json: @asignatura.errors, status: :unprocessable_entity
    end
  end

  # DELETE /asignaturas/1
  def destroy
    @asignatura.destroy
  end

  private
  # Use callbacks to share common setup or constraints between actions.
  def set_asignatura
    @asignatura = Asignatura.find(params[:id])
  end

  # Only allow a trusted parameter "white list" through.
  def asignatura_params
    params.require(:asignatura).permit(:nombre, :codigo, :departamento_id, :creditos, :horas_semanales)
  end
end
