class PeriodosController < ApplicationController
  before_action :set_periodo, only: [:show, :update, :destroy]

  # GET /periodos
  def index
    periodos = Periodo.all
    @periodos=[]
    periodos.each do |actual|
      mostrar= {numero: actual.numero, inicio: actual.inicio, termino: actual.termino}
      @periodos << mostrar
    end

    render json: @periodos
  end

  # GET /periodos/1
  def show
    actual = @periodo
    @periodo = {numero: actual.numero, inicio: actual.inicio, termino: actual.termino}
    render json: @periodo
  end

  # POST /periodos
  def create
    @periodo = Periodo.new(periodo_params)

    if @periodo.save
      render json: @periodo, status: :created, location: @periodo
    else
      render json: @periodo.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /periodos/1
  def update
    if @periodo.update(periodo_params)
      render json: @periodo
    else
      render json: @periodo.errors, status: :unprocessable_entity
    end
  end

  # DELETE /periodos/1
  def destroy
    @periodo.destroy
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_periodo
      @periodo = Periodo.find(params[:id])
    end

    # Only allow a trusted parameter "white list" through.
    def periodo_params
      params.require(:periodo).permit(:numero, :inicio, :termino)
    end
end
