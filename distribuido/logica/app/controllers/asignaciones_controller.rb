class AsignacionesController < ApplicationController
  before_action :set_asignacion, only: [:show, :update, :destroy]

  # GET /asignacions
  def index
    asignaciones = Asignacion.all
    @asignaciones=[]

    asignaciones.each do |actual|
      asignacion={dia: actual.disponibilidad_docente.dia,
                  periodo: {numero: actual.disponibilidad_docente.periodo.numero,
                            inicio: actual.disponibilidad_docente.periodo.inicio,
                            termino: actual.disponibilidad_docente.periodo.termino},
                  docente: {nombres: actual.disponibilidad_docente.docente.nombres,
                            apellidos: actual.disponibilidad_docente.docente.apellidos,
                            rut: actual.disponibilidad_docente.docente.rut},
                  curso:{ asignatura: actual.horario.curso.asignatura.nombre,
                          codigo: actual.horario.curso.asignatura.codigo,
                            seccion: actual.horario.curso.seccion}}
      @asignaciones<< asignacion
    end
    render json: @asignaciones
  end

  # GET /asignacions/1
  def show
    actual = @asignacion
    @asignacion = {dia: actual.disponibilidad_docente.dia,
                   periodo: {numero: actual.disponibilidad_docente.periodo.numero,
                             inicio: actual.disponibilidad_docente.periodo.inicio,
                             termino: actual.disponibilidad_docente.periodo.termino},
                   docente: {nombres: actual.disponibilidad_docente.docente.nombres,
                             apellidos: actual.disponibilidad_docente.docente.apellidos,
                             rut: actual.disponibilidad_docente.docente.rut},
                   curso:{ asignatura: actual.horario.curso.asignatura.nombre,
                           codigo: actual.horario.curso.asignatura.codigo,
                           seccion: actual.horario.curso.seccion}}
    render json: @asignacion
  end

  # POST /asignacions
  def create
    @asignacion = Asignacion.new(asignacion_params)

    if @asignacion.save
      render json: @asignacion, status: :created, location: @asignacion
    else
      render json: @asignacion.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /asignacions/1
  def update
    if @asignacion.update(asignacion_params)
      render json: @asignacion
    else
      render json: @asignacion.errors, status: :unprocessable_entity
    end
  end

  # DELETE /asignacions/1
  def destroy
    @asignacion.destroy
  end

  private
  # Use callbacks to share common setup or constraints between actions.
  def set_asignacion
    @asignacion = Asignacion.find(params[:id])
  end

  # Only allow a trusted parameter "white list" through.
  def asignacion_params
    params.require(:asignacion).permit(:disponibilidad_sala_id, :horario_id)
  end
end
