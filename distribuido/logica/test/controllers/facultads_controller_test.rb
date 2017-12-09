require 'test_helper'

class FacultadsControllerTest < ActionDispatch::IntegrationTest
  setup do
    @facultad = facultads(:one)
  end

  test "should get index" do
    get facultads_url, as: :json
    assert_response :success
  end

  test "should create facultad" do
    assert_difference('Facultad.count') do
      post facultads_url, params: { facultad: { nombre: @facultad.nombre, sigla: @facultad.sigla } }, as: :json
    end

    assert_response 201
  end

  test "should show facultad" do
    get facultad_url(@facultad), as: :json
    assert_response :success
  end

  test "should update facultad" do
    patch facultad_url(@facultad), params: { facultad: { nombre: @facultad.nombre, sigla: @facultad.sigla } }, as: :json
    assert_response 200
  end

  test "should destroy facultad" do
    assert_difference('Facultad.count', -1) do
      delete facultad_url(@facultad), as: :json
    end

    assert_response 204
  end
end
