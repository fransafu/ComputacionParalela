class AccesoParalelosController < ApplicationController
  before_action :set_acceso_paralelo, only: [:show, :update, :destroy]

  # GET /acceso_paralelos
  def index
    @acceso_paralelos = AccesoParalelo.all

    render json: @acceso_paralelos
  end

  # GET /acceso_paralelos/1
  def show
    render json: @acceso_paralelo
  end

  # POST /acceso_paralelos
  def create
    @acceso_paralelo = AccesoParalelo.new(acceso_paralelo_params)

    if @acceso_paralelo.save
      render json: @acceso_paralelo, status: :created, location: @acceso_paralelo
    else
      render json: @acceso_paralelo.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /acceso_paralelos/1
  def update
    if @acceso_paralelo.update(acceso_paralelo_params)
      render json: @acceso_paralelo
    else
      render json: @acceso_paralelo.errors, status: :unprocessable_entity
    end
  end

  # DELETE /acceso_paralelos/1
  def destroy
    @acceso_paralelo.destroy
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_acceso_paralelo
      @acceso_paralelo = AccesoParalelo.find(params[:id])
    end

    # Only allow a trusted parameter "white list" through.
    def acceso_paralelo_params
      params.require(:acceso_paralelo).permit(:disponible)
    end
end
