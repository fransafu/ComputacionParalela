class DisponibilidadSalasController < ApplicationController
  before_action :set_disponilidad_sala, only: [:show, :update, :destroy]

  # GET /@disponibilidad_salas
  def index
    disponibilidad_salas = DisponibilidadSala.all
    @disponibilidad_salas=[]
    disponibilidad_salas.each do |actual|
      mostrar ={sala: {nombre: actual.sala.nombre, tipo: actual.sala.tipo, capacidad: actual.sala.capacidad},
                periodo: {numero: actual.periodo.numero, inicio: actual.periodo.inicio, termino: actual.periodo.termino},
                dia: actual.dia,
                libre: actual.libre
      }
      @disponibilidad_salas << mostrar
    end

    render json: @disponibilidad_salas
  end

  # GET /@disponibilidad_salas/1
  def show
    actual = @disponibilidad_sala
    @disponibilidad_sala = {dia: actual.dia,
                            libre: actual.libre,
                            sala: {nombre: actual.sala.nombre, tipo: actual.sala.tipo, capacidad: actual.sala.capacidad},
                            periodo: {numero: actual.periodo.numero, inicio: actual.periodo.inicio, termino: actual.periodo.termino}
    }
    render json: @disponibilidad_sala
  end

  # POST /@disponibilidad_salas
  def create
    @disponibilidad_sala = DisponibilidadSala.new(disponilidad_sala_params)

    if @disponibilidad_sala.save
      render json: @disponibilidad_sala, status: :created, location: @disponibilidad_sala
    else
      render json: @disponibilidad_sala.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /@disponibilidad_salas/1
  def update
    if @disponibilidad_sala.update(disponilidad_sala_params)
      render json: @disponibilidad_sala
    else
      render json: @disponibilidad_sala.errors, status: :unprocessable_entity
    end
  end

  # DELETE /@disponibilidad_salas/1
  def destroy
    @disponibilidad_sala.destroy
  end


  private
  # Use callbacks to share common setup or constraints between actions.
  def set_disponilidad_sala
    @disponibilidad_sala = DisponibilidadSala.find(params[:id])
  end

  # Only allow a trusted parameter "white list" through.
  def disponilidad_sala_params
    params.require(:disponibilidad_sala).permit(:sala_id, :dia, :periodo_id, :ocupado)
  end
end
