class AddForeignToDisponibiliadDocentes < ActiveRecord::Migration[5.0]
  def change
    add_foreign_key :disponibilidad_docentes , :docentes, column: :docente_id, primary_key: :id
    add_foreign_key :disponibilidad_docentes , :periodos, column: :periodo_id, primary_key: :id

  end
end
