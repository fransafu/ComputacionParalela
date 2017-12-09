require 'test_helper'

class DocentesControllerTest < ActionDispatch::IntegrationTest
  setup do
    @docente = docentes(:one)
  end

  test "should get index" do
    get docentes_url, as: :json
    assert_response :success
  end

  test "should create docente" do
    assert_difference('Docente.count') do
      post docentes_url, params: { docente: { activo: @docente.activo, apellidos: @docente.apellidos, departamento_id_id: @docente.departamento_id_id, email: @docente.email, nombres: @docente.nombres, rut: @docente.rut } }, as: :json
    end

    assert_response 201
  end

  test "should show docente" do
    get docente_url(@docente), as: :json
    assert_response :success
  end

  test "should update docente" do
    patch docente_url(@docente), params: { docente: { activo: @docente.activo, apellidos: @docente.apellidos, departamento_id_id: @docente.departamento_id_id, email: @docente.email, nombres: @docente.nombres, rut: @docente.rut } }, as: :json
    assert_response 200
  end

  test "should destroy docente" do
    assert_difference('Docente.count', -1) do
      delete docente_url(@docente), as: :json
    end

    assert_response 204
  end
end
