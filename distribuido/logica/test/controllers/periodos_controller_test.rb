require 'test_helper'

class PeriodosControllerTest < ActionDispatch::IntegrationTest
  setup do
    @periodo = periodos(:one)
  end

  test "should get index" do
    get periodos_url, as: :json
    assert_response :success
  end

  test "should create periodo" do
    assert_difference('Periodo.count') do
      post periodos_url, params: { periodo: { inicio: @periodo.inicio, numero: @periodo.numero, termino: @periodo.termino } }, as: :json
    end

    assert_response 201
  end

  test "should show periodo" do
    get periodo_url(@periodo), as: :json
    assert_response :success
  end

  test "should update periodo" do
    patch periodo_url(@periodo), params: { periodo: { inicio: @periodo.inicio, numero: @periodo.numero, termino: @periodo.termino } }, as: :json
    assert_response 200
  end

  test "should destroy periodo" do
    assert_difference('Periodo.count', -1) do
      delete periodo_url(@periodo), as: :json
    end

    assert_response 204
  end
end
