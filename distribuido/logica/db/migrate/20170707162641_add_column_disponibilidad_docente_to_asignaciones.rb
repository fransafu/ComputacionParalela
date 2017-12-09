class AddColumnDisponibilidadDocenteToAsignaciones < ActiveRecord::Migration[5.0]
  def change
    add_column :asignaciones, :disponibilidad_docente_id, :integer
    add_foreign_key :asignaciones ,:disponibilidad_docentes, column: :disponibilidad_docente_id, primary_key: :id
  end
end
