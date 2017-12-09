require 'test_helper'

class AccesoParalelosControllerTest < ActionDispatch::IntegrationTest
  setup do
    @acceso_paralelo = acceso_paralelos(:one)
  end

  test "should get index" do
    get acceso_paralelos_url, as: :json
    assert_response :success
  end

  test "should create acceso_paralelo" do
    assert_difference('AccesoParalelo.count') do
      post acceso_paralelos_url, params: { acceso_paralelo: { disponible: @acceso_paralelo.disponible } }, as: :json
    end

    assert_response 201
  end

  test "should show acceso_paralelo" do
    get acceso_paralelo_url(@acceso_paralelo), as: :json
    assert_response :success
  end

  test "should update acceso_paralelo" do
    patch acceso_paralelo_url(@acceso_paralelo), params: { acceso_paralelo: { disponible: @acceso_paralelo.disponible } }, as: :json
    assert_response 200
  end

  test "should destroy acceso_paralelo" do
    assert_difference('AccesoParalelo.count', -1) do
      delete acceso_paralelo_url(@acceso_paralelo), as: :json
    end

    assert_response 204
  end
end
