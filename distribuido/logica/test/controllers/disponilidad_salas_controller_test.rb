require 'test_helper'

class DisponilidadSalasControllerTest < ActionDispatch::IntegrationTest
  setup do
    @disponibilidad_sala = disponilidad_salas(:one)
  end

  test "should get index" do
    get disponilidad_salas_url, as: :json
    assert_response :success
  end

  test "should create @disponibilidad_sala" do
    assert_difference('DisponibilidadSala.count') do
      post disponilidad_salas_url, params: {disponibilidad_sala: {dia: @disponibilidad_sala.dia, ocupado: @disponibilidad_sala.ocupado, periodo_id: @disponibilidad_sala.periodo_id, sala_id: @disponibilidad_sala.sala_id } }, as: :json
    end

    assert_response 201
  end

  test "should show @disponibilidad_sala" do
    get disponilidad_sala_url(@disponibilidad_sala), as: :json
    assert_response :success
  end

  test "should update @disponibilidad_sala" do
    patch disponilidad_sala_url(@disponibilidad_sala), params: {disponibilidad_sala: {dia: @disponibilidad_sala.dia, ocupado: @disponibilidad_sala.ocupado, periodo_id: @disponibilidad_sala.periodo_id, sala_id: @disponibilidad_sala.sala_id } }, as: :json
    assert_response 200
  end

  test "should destroy @disponibilidad_sala" do
    assert_difference('DisponibilidadSala.count', -1) do
      delete disponilidad_sala_url(@disponibilidad_sala), as: :json
    end

    assert_response 204
  end
end
