class DisponibilidadDocentesController < ApplicationController
  before_action :set_disponibilidad_docente, only: [:show, :update, :destroy]

  # GET /disponibilidad_docentes
  def index
    disponibilidad_docentes = DisponibilidadDocente.all
    @disponibilidad_docentes=[]
    disponibilidad_docentes.each do |actual|
      mostrar = {profesor: actual.docente.nombres+' '+actual.docente.apellidos,
                 dia: actual.dia,
                 periodo: actual.periodo.numero
      }
      @disponibilidad_docentes << mostrar
    end
    render json: @disponibilidad_docentes
  end

  # GET /disponibilidad_docentes/1
  def show
    actual = @disponibilidad_docente
    @disponibilidad_docente = {profesor: actual.docente.nombres+' '+actual.docente.apellidos,
                               dia: actual.dia,
                               periodo: actual.periodo.numero
    }

    render json: @disponibilidad_docente
  end



  # POST /disponibilidad_docentes
  def create

    debugger

    docente_json = params.slice(:docente_id, :rut, :disponibilidad).to_json
    docente_id = (Docente.find_by_rut(docente_json['rut'])).id
    docente = Docente.find(docente_id)
    if docente.bloques < docente_json['disponibilidad'].size
      docente.disponibilidad_docentes.each do |eliminar|
        eliminar.destroy
      end
      docente_json['disponibilidad'].each do |actual|
        periodo_id = (Periodo.find_by_numero(actual['periodo'].to_i)).id
        dia = actual['dia']
        DisponibilidadDocente.create(docente_id: docente_id, periodo_id: periodo_id, dia: dia)
      end
      render json: {status: 200,message: "Guardados con exito las nuevas disponibilidades"}.to_json
    else
      render json: {
          error: "La disponibilidad ingresada es menor a la cantidad de bloques que debe impartir",
          status: 404
      }
    end
  end

  # PATCH/PUT /disponibilidad_docentes/1
  def update
    if @disponibilidad_docente.update(disponibilidad_docente_params)
      render json: @disponibilidad_docente
    else
      render json: @disponibilidad_docente.errors, status: :unprocessable_entity
    end
  end

  # DELETE /disponibilidad_docentes/1
  def destroy
    @disponibilidad_docente.destroy
  end

  private
  # Use callbacks to share common setup or constraints between actions.
  def set_disponibilidad_docente
    @disponibilidad_docente = DisponibilidadDocente.find(params[:id])
  end

  # Only allow a trusted parameter "white list" through.
  def disponibilidad_docente_params
    params.require(:disponibilidad_docente).permit(:docente_id, :periodo_id, :dia)
  end
end
