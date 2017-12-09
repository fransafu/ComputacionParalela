require 'test_helper'

class DisponibilidadDocentesControllerTest < ActionDispatch::IntegrationTest
  setup do
    @disponibilidad_docente = disponibilidad_docentes(:one)
  end

  test "should get index" do
    get disponibilidad_docentes_url, as: :json
    assert_response :success
  end

  test "should create disponibilidad_docente" do
    assert_difference('DisponibilidadDocente.count') do
      post disponibilidad_docentes_url, params: { disponibilidad_docente: { dia: @disponibilidad_docente.dia, docente_id: @disponibilidad_docente.docente_id, periodo_id: @disponibilidad_docente.periodo_id } }, as: :json
    end

    assert_response 201
  end

  test "should show disponibilidad_docente" do
    get disponibilidad_docente_url(@disponibilidad_docente), as: :json
    assert_response :success
  end

  test "should update disponibilidad_docente" do
    patch disponibilidad_docente_url(@disponibilidad_docente), params: { disponibilidad_docente: { dia: @disponibilidad_docente.dia, docente_id: @disponibilidad_docente.docente_id, periodo_id: @disponibilidad_docente.periodo_id } }, as: :json
    assert_response 200
  end

  test "should destroy disponibilidad_docente" do
    assert_difference('DisponibilidadDocente.count', -1) do
      delete disponibilidad_docente_url(@disponibilidad_docente), as: :json
    end

    assert_response 204
  end
end
