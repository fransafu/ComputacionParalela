class AddColumnAsignatura < ActiveRecord::Migration[5.0]
  def change
    add_column :asignaciones , :asignatura_id, :integer
    add_foreign_key :asignaciones , :asignaturas, column: :asignatura_id, primary_key: :id

  end
end
