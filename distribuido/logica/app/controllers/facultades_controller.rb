class FacultadesController < ApplicationController
  before_action :set_facultad, only: [:show, :update, :destroy]

  # GET /facultads
  def index
    facultades = Facultad.all
    @facultades=[]
    facultades.each do |actual|
      mostrar={sigla: actual.sigla, nombre: actual.nombre}
      @facultades<<mostrar
    end
    render json: @facultades
  end

  # GET /facultads/1
  def show
    @facultad= {sigla: @facultad.sigla, nombre: @facultad.nombre}
    render json: @facultad
  end

  # POST /facultads
  def create
    @facultad = Facultad.new(facultad_params)

    if @facultad.save
      render json: @facultad, status: :created, location: @facultad
    else
      render json: @facultad.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /facultads/1
  def update
    if @facultad.update(facultad_params)
      render json: @facultad
    else
      render json: @facultad.errors, status: :unprocessable_entity
    end
  end

  # DELETE /facultads/1
  def destroy
    @facultad.destroy
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_facultad
      @facultad = Facultad.find(params[:id])
    end

    # Only allow a trusted parameter "white list" through.
    def facultad_params
      params.require(:facultad).permit(:sigla, :nombre)
    end
end
