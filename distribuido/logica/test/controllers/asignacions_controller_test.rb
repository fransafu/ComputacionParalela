require 'test_helper'

class AsignacionsControllerTest < ActionDispatch::IntegrationTest
  setup do
    @asignacion = asignacions(:one)
  end

  test "should get index" do
    get asignacions_url, as: :json
    assert_response :success
  end

  test "should create asignacion" do
    assert_difference('Asignacion.count') do
      post asignacions_url, params: { asignacion: { disponibilidad_sala_id: @asignacion.disponibilidad_sala_id, horario_id: @asignacion.horario_id } }, as: :json
    end

    assert_response 201
  end

  test "should show asignacion" do
    get asignacion_url(@asignacion), as: :json
    assert_response :success
  end

  test "should update asignacion" do
    patch asignacion_url(@asignacion), params: { asignacion: { disponibilidad_sala_id: @asignacion.disponibilidad_sala_id, horario_id: @asignacion.horario_id } }, as: :json
    assert_response 200
  end

  test "should destroy asignacion" do
    assert_difference('Asignacion.count', -1) do
      delete asignacion_url(@asignacion), as: :json
    end

    assert_response 204
  end
end
