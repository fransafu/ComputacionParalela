class ChangeAsignaciones < ActiveRecord::Migration[5.0]
  def change
    remove_column :asignaciones, :disponibilidad_docente_id
    add_column :asignaciones , :horario_id, :integer
    add_foreign_key :asignaciones , :horarios, column: :horario_id, primary_key: :id
  end
end
