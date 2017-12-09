class SalasController < ApplicationController
  before_action :set_sala, only: [:show, :update, :destroy]
  wrap_parameters :expense, include: [:expense_expense_categories_attributes]

  # GET /salas
  def index
    salas = Sala.all
    @salas = []
    salas.each do |actual|
      ds = actual.disponibilidad_salas
      contador = 0
      ds.each do |d|
        if d.libre == true
          contador+=1
        end
      end
      mostrar={capacidad: actual.capacidad, nombre: actual.nombre, tipo: actual.tipo, bloques_libre: contador}
      @salas << mostrar
    end
    render json: @salas
  end

  # GET /salas/1
  def show

    actual = @sala
    ds = actual.disponibilidad_salas
    contador = 0
    ds.each do |d|
      if d.libre == true
        contador+=1
      end
    end
    @sala = {capacidad: actual.capacidad,
             nombre: actual.nombre,
             tipo: actual.tipo,
             bloques_libre: contador
    }
    render json: @sala


  end

  # POST /salas
  def create
    @sala = Sala.new(sala_params)

    if @sala.save
      dia = ''
      for i in 1..6
        for j in 1..7
          dia = dia_funcion(i)
          DisponibilidadSala.create(periodo_id: j, dia: dia, sala_id: @sala.id)
        end
      end
      render json: @sala, status: :created, location: @sala
    else
      render json: @sala.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /salas/1
  def update
    if @sala.update(sala_params)
      render json: @sala
    else
      render json: @sala.errors, status: :unprocessable_entity
    end
  end

  # DELETE /salas/1
  def destroy
    @sala.destroy
  end

  def horario_sala
    @sala = Sala.find_by_nombre(params[:nombre])
    if @sala != nil
      @disponibilidad =[]
      @sala.disponibilidad_salas.each do |actual|
        if actual.libre == true
          mostrar = {sala: actual.sala.nombre, dia: actual.dia, periodo: actual.periodo.numero, libre: actual.libre}
        else
          mostrar = {sala: actual.sala.nombre, dia: actual.dia, periodo: actual.periodo.numero,
                     asignatura: actual.asignacion.horario.curso.asignatura.nombre, seccion: actual.asignacion.horario.curso.seccion,
                     profesor: actual.asignacion.horario.curso.docente.nombres+' '+actual.asignacion.horario.curso.docente.apellidos
          }
        end
        @disponibilidad<< mostrar
      end
      render json: @disponibilidad
    else
      render :json => {:error => "Sala "+params[:nombre]+ " No encontrada"}.to_json, :status => 404
    end

  end

  def horario_dia
    @salas = DisponibilidadSala.where(dia: params[:dia])
    if @salas.size >0
      @disponibilidad =[]
      @salas.each do |actual|
        if actual.libre == true
          mostrar = {sala: actual.sala.nombre, dia: actual.dia, periodo: actual.periodo.numero, libre: actual.libre}
        else
          mostrar = {sala: actual.sala.nombre, dia: actual.dia, periodo: actual.periodo.numero,
                     asignatura: actual.asignacion.horario.curso.asignatura.nombre, seccion: actual.asignacion.horario.curso.seccion,
                     profesor: actual.asignacion.horario.curso.docente.nombres+' '+actual.asignacion.horario.curso.docente.apellidos
          }
        end
        @disponibilidad<< mostrar
      end
      render json: @disponibilidad
    else
      render :json => {:error => "No se ha encontrado Salas para el dia "+params[:dia].to_s}.to_json, :status => 404
    end
  end


  def horarioProfesor

  end

  def horarioAsignatura

  end

  def horarioPeriodo

  end

  private
  # Use callbacks to share common setup or constraints between actions.
  def set_sala
    @sala = Sala.find(params[:id])
  end

  # Only allow a trusted parameter "white list" through.
  def sala_params
    params.require(:sala).permit(:capacidad, :nombre, :sigla, :tipo)
  end


  def dia_funcion(dia_numerico)
    salida = ''
    if dia_numerico == 1
      salida = 'LUNES'
    end
    if dia_numerico == 2
      salida = 'MARTES'
    end
    if dia_numerico == 3
      salida = 'MIERCOLES'
    end
    if dia_numerico == 4
      salida = 'JUEVES'
    end
    if dia_numerico == 5
      salida = 'VIERNES'
    end
    if dia_numerico == 6
      salida = 'SABADO'
    end
    return salida
  end

end
