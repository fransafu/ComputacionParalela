class AddForeignToHoraris < ActiveRecord::Migration[5.0]
  def change
    add_foreign_key :horarios, :periodos, column: :periodo_id, primary_key: :id
  end
end
