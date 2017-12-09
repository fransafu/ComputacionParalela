class EditarAsignacionesYDocentes < ActiveRecord::Migration[5.0]
  def change
    remove_column :asignaciones, :horario_id
    add_column :asignaciones, :disponibilidad_docente_id, :integer
    add_foreign_key :asignaciones , :disponibilidad_docentes, column: :disponibilidad_docente_id, primary_key: :id
    add_column :docentes , :bloques, :integer

  end
end
