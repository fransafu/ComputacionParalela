class AddForeigToDisponibilidadSala < ActiveRecord::Migration[5.0]
  def change
    add_foreign_key :disponibilidad_salas , :periodos, column: :periodo_id, primary_key: :id
    add_foreign_key :disponibilidad_salas , :salas, column: :sala_id, primary_key: :id
    change_column_default :disponibilidad_salas , :ocupado, true
  end
end
